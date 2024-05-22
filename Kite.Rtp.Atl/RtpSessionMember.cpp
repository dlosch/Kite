#include "StdAfx.h"
#include "rtpsessionmember.h"

extern UINT Kite::Rtp::s_inactivityTimeoutMilliseconds;

CRtpSessionMember::CRtpSessionMember(UINT ssrc, BOOL bIsSource, IPerformanceCounterFactory *pFactory)
{
	// CheckPointer(pFactory, E_POINTER);
	m_ssrc = ssrc;
	m_bIsSource = bIsSource;
	m_lastUpdateMillisecs = timeGetTime();
	m_pPerfCounterFactory = pFactory;
	m_uSeqNumCycleCount = 0;
	m_uHighestReceivedSeqNum = 0;

	m_pSdesItems = NULL;
	
	m_payloadType = 0;

	m_bRtpPacketsReceived = FALSE;
	/*
	 *	Infos aus SR:
		- Ntp Timestamp (64)
		- Rtp Ts (32)
		- Senders Packet Count
		- Senders Octet Count

		Infos f�r RR:
		- Number Of Packets Lost (|Packets received - Senders Packet Count|)
		- Sequence Number Received
		- Interarrival Jitter ()
			Wird bei jedem empfangenen Rtp Packet geupdated (Packet timestamp)
		- last SR Timestamp 
			The middle 32 bits out of 64 in the NTP timestamp (as explained
			in Section 4) received as part of the most recent RTCP sender
			report (SR) packet from source SSRC_n.  If no SR has been
			received yet, the field is set to zero.

		- The delay, expressed in units of 1/65536 seconds, between
		receiving the last SR packet from source SSRC_n and sending this
		reception report block.  If no SR packet has been received yet
		from SSRC_n, the DLSR field is set to zero.

	 */
	if (bIsSource)
	{
		SetIsActiveSource();
	}
}

CRtpSessionMember::~CRtpSessionMember()
{
	ATLTRACE2("%s, File %s, Line %d \r\n", __FUNCTION__, __FILE__, __LINE__);
	SAFE_FREE(m_pSdesItems);
}

HRESULT CRtpSessionMember::SetIsActiveSource(void)
{
	CheckPointer(m_pPerfCounterFactory, E_UNEXPECTED);

	if (m_pPerfCounterNtpTimestampReceivedInLastSenderReport
		&& m_pPerfCounterRtpTimestampReceivedInLastSenderReport
		&& m_pPerfCounterSendersRtpPacketCount
		&& m_pPerfCounterSendersRtpOctetCount
		&& m_pPerfCounterRtpPacketsReceivedFromSource
		&& m_pPerfCounterExtendedHighestSequenceNumberReceived
		&& m_pPerfCounterInterarrivalJitter
		&& m_pPerfCounterTimestampLastSRReceived
		&& m_pPerfCounterLastSRReceivedAbsoluteTimeMilliseconds)
	{
		return S_FALSE;
	}
	else
	{
		HRESULT hr = m_pPerfCounterFactory->GetCountersForRtpSessionMember(m_ssrc, 
			// Information received from SRs
			&m_pPerfCounterNtpTimestampReceivedInLastSenderReport,
			&m_pPerfCounterRtpTimestampReceivedInLastSenderReport,
			&m_pPerfCounterSendersRtpPacketCount,
			&m_pPerfCounterSendersRtpOctetCount,

			// Information  for Sending RRs
			&m_pPerfCounterRtpPacketsReceivedFromSource,
			&m_pPerfCounterExtendedHighestSequenceNumberReceived,
			&m_pPerfCounterInterarrivalJitter,
			// middle 32 of ntp ts
			&m_pPerfCounterTimestampLastSRReceived,

			// TODO RENAMED
			&m_pPerfCounterLastSRReceivedAbsoluteTimeMilliseconds

			);

		VALHR(hr);

		return hr;
	}

	return S_FALSE;
}

BOOL CRtpSessionMember::GetIsTimedOut(UINT currentTime)
{
	if (currentTime < m_lastUpdateMillisecs) 
	{
		m_lastUpdateMillisecs = currentTime;
		return FALSE;
	}

	return (currentTime - m_lastUpdateMillisecs > Kite::Rtp::s_inactivityTimeoutMilliseconds);
}

HRESULT CRtpSessionMember::CreateRR(BYTE* pBuffer, UINT *pcbOffset, UINT cbBufferLength)
{
	// Calculate Delay since Last SR
	UINT uDelay = 0;
	UINT uLastSRReceived = m_pPerfCounterTimestampLastSRReceived->get_RawValueUint();
	if (uLastSRReceived != 0)
	{
		UINT tNow = timeGetTime();
		UINT tReceiveLastSR = m_pPerfCounterLastSRReceivedAbsoluteTimeMilliseconds->get_RawValueUint();

		uDelay = (UINT)(tNow - tReceiveLastSR / 1000 * 65535); 
	}

	return RtcpReceiverReportUtil_WriteRR(pBuffer, pcbOffset, cbBufferLength, 
					m_ssrc, 
					m_pPerfCounterSendersRtpPacketCount->get_RawValueUint(), m_pPerfCounterRtpPacketsReceivedFromSource->get_RawValueUint(),
					m_pPerfCounterExtendedHighestSequenceNumberReceived->get_RawValueUint(),
					// RFC 1889, 13.8
					(m_pPerfCounterInterarrivalJitter->get_RawValueUint() >> 4),
					m_pPerfCounterTimestampLastSRReceived->get_RawValueUint(),
					uDelay
				);
}

//////////////////////////////////////////////////////////////////////////

STDMETHODIMP CRtpSessionMember::KeepAlive(void)
{
	m_lastUpdateMillisecs = timeGetTime();
	return S_OK;
}

HRESULT CRtpSessionMember::Update(RtpParsedPacket *pPacket)
{
	CheckPointer(pPacket, E_POINTER);
	if (pPacket->ssrc != m_ssrc)
	{
		ASSERT(0);
		return E_INVALIDARG;
	}

	m_lastUpdateMillisecs = timeGetTime();
	{
		if (!m_bIsSource) SetIsActiveSource();
	}

	HRESULT hr = S_OK;
	if (m_payloadType != pPacket->payloadType)
	{
		m_payloadType = pPacket->payloadType;
		hr = S_FALSE;
	}

	m_pPerfCounterRtpPacketsReceivedFromSource->Increment();
	BOOL bSeqNumOverflow = (((m_uHighestReceivedSeqNum & 0xC000) == 0xC000) && ((pPacket->seqNum & 0xC000) == 0));
	
	if (bSeqNumOverflow)
	{
		m_uSeqNumCycleCount++;
	}

	if (m_uHighestReceivedSeqNum < pPacket->seqNum || bSeqNumOverflow)
	{
		m_uHighestReceivedSeqNum++;
		
		LONGLONG lExtendedHighestSeqNum = (m_uSeqNumCycleCount << 16 | m_uHighestReceivedSeqNum);
		m_pPerfCounterExtendedHighestSequenceNumberReceived->put_RawValue(lExtendedHighestSeqNum);
	}

	LONG tArrival = timeGetTime() * RTP_CONSTANTS_VIDEO_TIMESTAMP_INCREMENT_PER_MILLISECOND;
	LONG tTransit = abs(tArrival - pPacket->timestamp);
	LONG d = abs(tTransit - m_tTransitPrevious);
	m_tTransitPrevious = tTransit;

	INT jitter = m_pPerfCounterInterarrivalJitter->get_RawValueInt();
	jitter += d - ((jitter + 8) >> 4);
	
	hr = m_pPerfCounterInterarrivalJitter->put_RawValueInt(jitter);
	VALHR(hr);

	return hr;
}
HRESULT CRtpSessionMember::Update(RtcpSenderReport *pPacket)
{
	CheckPointer(pPacket, E_POINTER);
	if (pPacket->ssrc != m_ssrc)
	{
		ASSERT(0);
		return E_INVALIDARG;
	}

	m_lastUpdateMillisecs = timeGetTime();

	if (!m_bIsSource) SetIsActiveSource();

	HRESULT hr = S_OK;
	hr = m_pPerfCounterNtpTimestampReceivedInLastSenderReport->put_RawValue(pPacket->ntpTimeStampMsw << 16 | pPacket->ntpTimeStampLsw);
	VALHR(hr);
	hr = m_pPerfCounterRtpTimestampReceivedInLastSenderReport->put_RawValueUint(pPacket->rtpTimeStamp);
	VALHR(hr);

	hr = m_pPerfCounterSendersRtpPacketCount->put_RawValueUint(pPacket->sendersPacketCount);
	VALHR(hr);
	hr = m_pPerfCounterSendersRtpOctetCount->put_RawValueUint(pPacket->sendersOctetCount);
	VALHR(hr);

	hr = m_pPerfCounterTimestampLastSRReceived->put_RawValueUint((pPacket->ntpTimeStampMsw << 8) | (pPacket->ntpTimeStampLsw >> 8) );
	VALHR(hr);

	hr = m_pPerfCounterLastSRReceivedAbsoluteTimeMilliseconds->put_RawValue(m_lastUpdateMillisecs);
	VALHR(hr);

	return S_OK;
}
HRESULT CRtpSessionMember::Update(RtcpReceiverReport *pPacket)
{
	CheckPointer(pPacket, E_POINTER);

	m_lastUpdateMillisecs = timeGetTime();
	BYTE fraction = (BYTE)(pPacket->cumulativeNumberOfPacketsLostWithFractionLost >> 24);
	pPacket->cumulativeNumberOfPacketsLostWithFractionLost &= 0xFFFFFF;
	ATLTRACE2(
		"Receiver Report received: for SSRC %d Fraction Lost %d (0x%x) CumulativePktsLost %d, InterArrivalJitter %d (0x%x)", 
		pPacket->ssrc,
		fraction, fraction,
		pPacket->cumulativeNumberOfPacketsLostWithFractionLost,
		pPacket->interArrivalJitter, pPacket->interArrivalJitter);

	return S_OK;
}
HRESULT CRtpSessionMember::Update(RtcpBye *pPacket)
{
	CheckPointer(pPacket, E_POINTER);
	if (pPacket->ssrc != m_ssrc)
	{
		ASSERT(0);
		return E_INVALIDARG;
	}

	m_lastUpdateMillisecs = timeGetTime();

	return S_OK;
}

HRESULT CRtpSessionMember::Update(SdesItems *pItems)
{
	CheckPointer(pItems, E_POINTER);
	// Copy Memeory

	if (!m_bIsSource) SetIsActiveSource();

	ASSERT(m_ssrc == pItems->ssrc);

	HRESULT hr = S_OK;
	if (m_pSdesItems)
	{
		if (memcmp(m_pSdesItems, pItems, sizeof(SdesItems)))
		{
			if (_tcsclen(m_pSdesItems->cname) == 0 &&  0 < _tcslen(pItems->cname) && _tcscmp(pItems->cname, m_pSdesItems->cname))
			{	
				// Notify Application about changed Sdes
				hr = S_FALSE;
				_tcsncpy(m_pSdesItems->cname, pItems->cname, RTP_COSTANTS_RTCP_SDES_ITEM_VALUE_MAXLENGTH - 1);
			}

			if (_tcsclen(m_pSdesItems->email) == 0 && 0 < _tcslen(pItems->email) && _tcscmp(pItems->email, m_pSdesItems->email))
			{	
				// Notify Application about changed Sdes
				hr = S_FALSE;
				_tcsncpy(m_pSdesItems->email, pItems->email, RTP_COSTANTS_RTCP_SDES_ITEM_VALUE_MAXLENGTH - 1);
			}

			if (_tcsclen(m_pSdesItems->loc) == 0 && 0 < _tcslen(pItems->loc) && _tcscmp(pItems->loc, m_pSdesItems->loc))
			{	
				// Notify Application about changed Sdes
				hr = S_FALSE;
				_tcsncpy(m_pSdesItems->loc, pItems->loc, RTP_COSTANTS_RTCP_SDES_ITEM_VALUE_MAXLENGTH - 1);
			}

			if (_tcsclen(m_pSdesItems->name) == 0 && 0 < _tcslen(pItems->name) && _tcscmp(pItems->name, m_pSdesItems->name))
			{	
				// Notify Application about changed Sdes
				hr = S_FALSE;
				_tcsncpy(m_pSdesItems->name, pItems->name, RTP_COSTANTS_RTCP_SDES_ITEM_VALUE_MAXLENGTH - 1);
			}

			if (_tcsclen(m_pSdesItems->note) == 0 && 0 < _tcslen(pItems->note) && _tcscmp(pItems->note, m_pSdesItems->note))
			{	
				// Notify Application about changed Sdes
				hr = S_FALSE;
				_tcsncpy(m_pSdesItems->note, pItems->note, RTP_COSTANTS_RTCP_SDES_ITEM_VALUE_MAXLENGTH - 1);
			}

			if (_tcsclen(m_pSdesItems->phone) == 0 && 0 < _tcslen(pItems->phone) && _tcscmp(pItems->phone, m_pSdesItems->phone))
			{	
				// Notify Application about changed Sdes
				hr = S_FALSE;
				_tcsncpy(m_pSdesItems->phone, pItems->phone, RTP_COSTANTS_RTCP_SDES_ITEM_VALUE_MAXLENGTH - 1);
			}

			if (_tcsclen(m_pSdesItems->tool) == 0 && 0 < _tcslen(pItems->tool) && _tcscmp(pItems->tool, m_pSdesItems->tool))
			{	
				// Notify Application about changed Sdes
				hr = S_FALSE;
				_tcsncpy(m_pSdesItems->tool, pItems->tool, RTP_COSTANTS_RTCP_SDES_ITEM_VALUE_MAXLENGTH - 1);
			}
		}
	}
	else
	{
		hr = S_FALSE;
		m_pSdesItems = (SdesItems*)SAFE_ALLOC(sizeof(SdesItems));
		CheckPointer(m_pSdesItems, E_OUTOFMEMORY);
		CopyMemory(m_pSdesItems, pItems, sizeof(SdesItems));
	}

	return hr;
}

HRESULT CRtpSessionMember::GetSdesItems(SdesItems *pItems)
{
	CheckPointer(pItems, E_POINTER);

	if (m_pSdesItems)
	{
		CopyMemory(pItems, m_pSdesItems, sizeof(SdesItems));
		return S_OK;
	}
	else
	{
		ZeroMemory(pItems, sizeof(SdesItems));
		return S_FALSE;
	}
}

HRESULT CRtpSessionMember::GetSourceInfo(RtpSessionMemberInfo *pInfo, BOOL bIncludeSdes)
{
	CheckPointer(pInfo, E_POINTER);

	HRESULT hr = S_OK;

	pInfo->ssrc = m_ssrc;
	pInfo->payloadType = m_payloadType;

	pInfo->delaySinceLastPacketMillis = timeGetTime() - m_lastUpdateMillisecs;

	pInfo->interarrivalJitter = 0;
	pInfo->octetsLost = 0;
	pInfo->packetsLost = 0;
	if (bIncludeSdes && pInfo->pSdesItems)
		CopyMemory(pInfo->pSdesItems, m_pSdesItems, sizeof(SdesItems));

	return hr;
}