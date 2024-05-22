// RtpRenderer.cpp : Implementation of CRtpRenderer

#include "stdafx.h"
#include ".\rtprenderer.h"
#include <WinCrypt.h>

// CRtpRenderer
CRtpRenderer::CRtpRenderer()
{
	m_bSendRRs = FALSE;
	// voller Sdes nur alle n Intervalle, sonst nur Cname
	m_bLeightweightSdes = TRUE;

	// 4Byte fixed
	m_pBufferSdesHeader = NULL;
	m_pBufferSdesFull = NULL;
	m_cbBufferSdesFull = 0;
	m_pBufferSdesLeightweight = NULL;
	m_cbBufferSdesLeightweight = 0;
	// 1 Minute
	m_SdesFullIntervalMilliseconds = 1000 * 60;
	m_TimeLastSdesFull = 0; //(UINT)(~1);

	m_pSdesItems = NULL;
	m_uNextSeqNum = 0;

	m_payloadType = 0x22; //34 == H.263; 126; // 7E, dynamic Video
}

HRESULT CRtpRenderer::FinalConstruct()
{
	HRESULT hr = S_OK;

	if (!InitializeCriticalSectionAndSpinCount(&m_critSectSdesBufferLock, 0x80000400))
	{
		return E_FAIL;
	}

	hr = SetIsListener(FALSE);
	VALHR(hr);

	HCRYPTPROV hCryptProv = NULL;
	BOOL bRetVal = CryptAcquireContext(&hCryptProv, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT);
	bRetVal = CryptGenRandom(hCryptProv, sizeof(USHORT), (BYTE*)&m_uNextSeqNum);
	// local ssrc
	bRetVal = CryptGenRandom(hCryptProv, sizeof(UINT), (BYTE*)&m_ssrc);
	bRetVal = CryptReleaseContext(hCryptProv, NULL);
	hCryptProv = NULL;

	hr = this->CRtpSocketBase::Initialize();

	hr = InitializeRtpHeader();

	return hr;
}

void CRtpRenderer::FinalRelease() 
{
	DeleteCriticalSection(&m_critSectSdesBufferLock);

	if (m_pBufferSdesLeightweight == m_pBufferSdesFull)
	{
		m_pBufferSdesLeightweight = NULL;
	}
	else
	{
		SAFE_FREE(m_pBufferSdesLeightweight);
	}

	SAFE_FREE(m_pBufferSdesFull);
}


STDMETHODIMP CRtpRenderer::InitializeRtpHeader()
{
	ZeroMemory(&m_bufferRtpHeader, RTP_CONSTANTS_RTP_FIXED_HEADER_SIZE);

	m_bufferRtpHeader[3] = 128; // v=2, 0, 0, 0
	BufferUtil_PutNetworkByteOrderUint(m_bufferRtpHeader, 8, m_ssrc);

	return S_OK;
}

STDMETHODIMP CRtpRenderer::InitializeRtcpReportGeneration()
{
	CheckPointer(m_pSdesItems, E_UNEXPECTED);

	HRESULT hr = S_OK;
	BYTE cbPad = 0;
	hr = RtcpSdesUtil_CreateSdesPacketWithHeader(&m_pBufferSdesFull, &m_cbBufferSdesFull, &cbPad, m_pSdesItems, FALSE);
	CheckPointerJIF(m_pBufferSdesFull, E_OUTOFMEMORY);

	if (m_bLeightweightSdes)
	{
		hr = RtcpSdesUtil_CreateSdesPacketWithHeader(&m_pBufferSdesLeightweight, &m_cbBufferSdesLeightweight, &cbPad, m_pSdesItems, TRUE);
		CheckPointerJIF(m_pBufferSdesLeightweight, E_OUTOFMEMORY);
	}
	else
	{
		m_pBufferSdesLeightweight = m_pBufferSdesFull;
	}

	return hr;

cleanup:
	SAFE_FREE(m_pBufferSdesFull);		
	SAFE_FREE(m_pBufferSdesLeightweight);		

	return hr;
}

// the size of the packet has to be updated in the counter
STDMETHODIMP CRtpRenderer::RtcpTimerCallback(VOID)
{
	ATLTRACE2("CRtpRenderer::RtcpTimerCallback \r\n");
	HRESULT hr = S_OK;

	UINT lActiveSources = 0;
	if (m_bSendRRs)
	{
		lActiveSources = (UINT)m_pPerfCounterNumberOfActiveSources->get_RawValue() - 1;
	}
	
	BYTE* pSRWithRRNboBuffer = NULL;
	UINT cbOffset = RTP_CONSTANTS_RTCP_HEADER_SIZE;
	UINT cbBufferLength = 0;
	hr = RtcpSenderReportUtil_AllocateSRAndRRsWithHeader(&pSRWithRRNboBuffer, &cbBufferLength, lActiveSources, m_ssrc);

	LONGLONG lNtpTimeStamp = RtcpSenderReportUtil_GenerateNtpTimestamp();
	UINT rtpTimestamp = 0;
	UINT cPacketsSent = m_pPerfCounterRtpPacketsSent->get_RawValueUint();
	UINT cbSent = m_pPerfCounterRtpOctetsSent->get_RawValueUint();
	
	hr = RtcpSenderReportUtil_WriteSR(pSRWithRRNboBuffer, &cbOffset, cbBufferLength, lNtpTimeStamp, rtpTimestamp, cPacketsSent, cbSent);
	ASSERT(SUCCEEDED(hr));

	if (lActiveSources > 0)
	{
		CAutoLock lock(&m_critSectRtpSessionMembersMapSynchronization);
		POSITION position = m_mapRtpSessionMembers.GetStartPosition();

		UINT currentSsrc;
		CRtpSessionMember *pCurrentSessionMember = NULL;
		do 
		{
			m_mapRtpSessionMembers.GetNextAssoc(position, currentSsrc, pCurrentSessionMember);
			if (!position) break;

			if (pCurrentSessionMember && pCurrentSessionMember->m_bIsSource)
			{
				hr = pCurrentSessionMember->CreateRR(pSRWithRRNboBuffer, &cbOffset, cbBufferLength);
				ASSERT(SUCCEEDED(hr));
			}
		} while(--lActiveSources > 0);
	}

	BYTE* pBuffers[2];
	UINT pcbBufferLengths[2];
	pBuffers[0] = pSRWithRRNboBuffer;
	pcbBufferLengths[0] = cbBufferLength;

	UINT currentTime = timeGetTime();
	UINT cbSdes = 0;

	CAutoLock lockSdes(&m_critSectSdesBufferLock);

	if ((m_TimeLastSdesFull > currentTime) || ((currentTime - m_TimeLastSdesFull) > m_SdesFullIntervalMilliseconds))
	{
		m_TimeLastSdesFull = currentTime;
		pBuffers[1] = m_pBufferSdesFull;
		pcbBufferLengths[1] = m_cbBufferSdesFull;
		cbSdes = m_cbBufferSdesFull;
	}
	else
	{
		pBuffers[1] = m_pBufferSdesLeightweight;
		pcbBufferLengths[1] = m_cbBufferSdesLeightweight;
		cbSdes = m_cbBufferSdesLeightweight;
	}

	m_pPerfCounterTimestampLastRtcpReportSent->put_RawValue(lNtpTimeStamp);
	m_pPerfCounterRtcpPacketsSent->Increment();
	m_pPerfCounterRtcpOctetsSent->IncrementBy(
		RTP_CONSTANTS_RTCP_PACKET_NETWORK_OVERHEAD_UDP_OVER_IP 
		+ RTP_CONSTANTS_RTCP_HEADER_SIZE 
		+ cbOffset 
		+ cbSdes);

	hr = SendRtcpDataRaw(pBuffers, pcbBufferLengths,2);
	ASSERT(SUCCEEDED(hr));

	// Free Buffer
	SAFE_FREE(pSRWithRRNboBuffer);

	return hr;
}

STDMETHODIMP CRtpRenderer::SendRtpPacket(BYTE* pBuffer, UINT cbBuffer, BOOL bMarker, UINT timestamp)
{
	CheckPointer(pBuffer, E_POINTER);
	CheckPointer(cbBuffer, E_INVALIDARG);
	CheckPointer(timestamp, E_INVALIDARG);

	BufferUtil_PutNetworkByteOrderUshort(m_bufferRtpHeader, 2, m_uNextSeqNum++);
	BufferUtil_PutNetworkByteOrderUint(m_bufferRtpHeader, 4, timestamp);
	m_bufferRtpHeader[1] &= 127;
	if (bMarker) m_bufferRtpHeader[1] += 128;

	WSABUF pwsabuf[2];
	pwsabuf[0].buf = (CHAR*)m_bufferRtpHeader;
	pwsabuf[0].len = RTP_CONSTANTS_RTP_FIXED_HEADER_SIZE;

	pwsabuf[0].buf = (CHAR*)pBuffer;
	pwsabuf[0].len = cbBuffer;

	DWORD dwBytesSent = 0;
	DWORD dwFlags = 0;
	INT wsaRetVal = WSASendTo(m_scktRtpSocket, pwsabuf, 2, &dwBytesSent, dwFlags, (sockaddr*)&(m_pRtpAddresses->remoteAddress), sizeof(sockaddr_in), NULL, NULL);
	INT wsaLastError = 0;
	if (wsaRetVal != 0)
	{
		wsaLastError = WSAGetLastError();
	}

	m_pPerfCounterRtpPacketsSent->Increment();
	m_pPerfCounterRtpOctetsSent->IncrementBy(cbBuffer);
	
	return (wsaRetVal == 0 ? S_OK : E_FAIL);
}

STDMETHODIMP CRtpRenderer::SetPayloadType(BYTE payloadType)
{
	if (payloadType != m_payloadType)
	{
		// set payload type and write to header
		m_payloadType = payloadType;
		m_bufferRtpHeader[1] &= 128;
		m_bufferRtpHeader[1] += m_payloadType;
	
		return S_OK;
	}

	return S_FALSE;
}

STDMETHODIMP CRtpRenderer::Start(void)
{
	if (m_bListenState) return S_FALSE;
	CheckPointer(m_pSdesItems, E_UNEXPECTED);
	CheckPointer(m_pPerfCounterRtcpPacketsSent, E_UNEXPECTED);
	CheckPointer(m_pPerfCounterRtcpOctetsSent, E_UNEXPECTED);

	m_TimeLastSdesFull = timeGetTime();
	m_pBufferSdesFull;
	m_cbBufferSdesFull;
	
	m_pPerfCounterRtcpPacketsSent->Increment();
	m_pPerfCounterRtcpOctetsSent->IncrementBy(
		RTP_CONSTANTS_RTCP_PACKET_NETWORK_OVERHEAD_UDP_OVER_IP 
		+ m_cbBufferSdesFull);

	HRESULT hr = SendRtcpDataRaw(&m_pBufferSdesFull, &m_cbBufferSdesFull, 1);
	VALHR(hr);
	
	return StartListen();
}

STDMETHODIMP CRtpRenderer::Stop(void)
{
	/*return */HRESULT hr = this->CRtpSocketBase::StopListen();
	VALHR(hr);

	hr = this->SendBye();
	VALHR(hr);

	return hr;
}

STDMETHODIMP CRtpRenderer::Configure(
									 BYTE* pSocketAddressesByte, UINT cbSocketAddresses,
									 BYTE* pSdesItems, UINT cbSdesItems)
{
	CheckPointer(pSocketAddressesByte, E_POINTER);
	CheckPointer(pSdesItems, E_POINTER);

	if (cbSocketAddresses != sizeof(SocketAddresses) && cbSocketAddresses != sizeof(SocketAddressesIPMcast)) return E_INVALIDARG;
	if (cbSdesItems != sizeof(SdesItems)) return E_INVALIDARG;

	HRESULT hr = S_OK;

	SocketAddresses *pSocketAddresses = (SocketAddresses*)pSocketAddressesByte;

	m_pSdesItems = (SdesItems*)SAFE_ALLOC(cbSdesItems);
	CheckPointer(m_pSdesItems, E_OUTOFMEMORY);
	CopyMemory(m_pSdesItems, pSdesItems, cbSdesItems);

	// SSRC setzen
	m_pSdesItems->ssrc = m_ssrc;

	hr = this->CreateSockets(pSocketAddresses);
	VALHR(hr);

	hr = InitializeRtcpReportGeneration();
	VALHR(hr);

	hr = this->CRtpSocketBase::InitializePerformanceCounter();
	VALHR(hr);

	hr = InitializePerformanceCounterForRtpRenderer();
	VALHR(hr);

	return S_OK;
}

STDMETHODIMP CRtpRenderer::InitializePerformanceCounterForRtpRenderer(void)
{
	CheckPointer(m_pPerfCounterFactory, E_UNEXPECTED);

	HRESULT hr =m_pPerfCounterFactory->GetCountersForRtpRenderer(
		&m_pPerfCounterRtpPacketsSent,
		&m_pPerfCounterRtpOctetsSent
		);

	VALHR(hr);

	m_pPerfCounterNumberOfActiveSources->Increment();

	return hr;
}

//////////////////////////////////////////////////////////////////////////
// ???
STDMETHODIMP CRtpRenderer::SendRtpPayloadData(
	BOOL bMarker, UINT timestamp,
	BYTE* pProperlyPacketizedData, UINT cbProperlyPacketizedData)
{
	BYTE rtpHeader[RTP_CONSTANTS_RTP_FIXED_HEADER_SIZE];
	UINT cbOffset = 0;
	HRESULT hr = RtpPacketUtil_WriteRtpHeader(rtpHeader, &cbOffset, RTP_CONSTANTS_RTP_FIXED_HEADER_SIZE, bMarker, m_payloadType, m_uNextSeqNum++, timestamp, m_ssrc);
	VALHR(hr);
	ASSERT(cbOffset == RTP_CONSTANTS_RTP_FIXED_HEADER_SIZE);

	WSABUF wsabuf[2];
	wsabuf[0].buf = (CHAR*)rtpHeader;// Header;
	wsabuf[0].len = RTP_CONSTANTS_RTP_FIXED_HEADER_SIZE;
	// Payload
	wsabuf[1].buf = (CHAR*)pProperlyPacketizedData;
	wsabuf[1].len = cbProperlyPacketizedData;

	DWORD dwBytesSentIfSync = 0;
	DWORD dwFlags = 0;
	// For overlapped sockets (created using WSASocket with flag WSA_FLAG_OVERLAPPED) 
	// sending information uses overlapped I/O, 
	// unless both lpOverlapped and lpCompletionRoutine are NULL. 
	// In that case, the socket is treated as a nonoverlapped socket
	//INT wsaRetVal = WSASend(m_scktRtpSocket, wsabuf, 2, &dwBytesSentIfSync, dwFlags, NULL, NULL);
	INT wsaRetVal = WSASendTo(m_scktRtpSocket, wsabuf, 2, &dwBytesSentIfSync, dwFlags, (sockaddr*)&(m_pRtpAddresses->remoteAddress), sizeof(sockaddr_in), NULL, NULL);

	hr = m_pPerfCounterRtpOctetsSent->IncrementBy(cbProperlyPacketizedData);
	VALHR(hr);
	hr = m_pPerfCounterRtpPacketsSent->Increment();
	VALHR(hr);

	ASSERT(wsaRetVal == 0);

	return wsaRetVal == 0 ? S_OK : E_FAIL;
}

STDMETHODIMP CRtpRenderer::SetNetworkParameter(
	LPWSTR szRemoteAddress, USHORT uRemotePort, LPWSTR szLocalInterface, USHORT uLocalPort, 
	INT ttl,
	LPWSTR szCname)
{
	CheckPointer(szCname, E_POINTER);

	HRESULT hr = S_OK;

	USES_CONVERSION;

	SocketAddresses *pSocketAddresses = NULL;
	hr = RtpConfigurationHelper_CreateConfiguration(
		W2T(szRemoteAddress), 
		uRemotePort, 
		W2T(szLocalInterface), 
		uLocalPort,
		ttl, 
		&pSocketAddresses);

	VALHR(hr);
	CheckPointer(pSocketAddresses, E_FAIL);

	SdesItems *pItems = NULL;
	hr = RtpConfigurationHelper_CreateSdesItems(W2T(szCname), 0, 0, 0, 0, 0, 0, &pItems);

	return this->Configure((BYTE*)pSocketAddresses, pSocketAddresses->cbSize, (BYTE*)pItems, sizeof(SdesItems));
}

STDMETHODIMP CRtpRenderer::SetRtpBandwidth(UINT uSessionBandwidth, BOOL bEnforce)
{
	return this->CRtpSocketBase::SetRtpBandwidth(uSessionBandwidth, bEnforce);
}

STDMETHODIMP CRtpRenderer::SetRtcpParameter(LPWSTR szName, LPWSTR szEMail, LPWSTR szPhone, LPWSTR szLoc, LPWSTR szTool, LPWSTR szNote)
{
	USES_CONVERSION;

	HRESULT hr = S_OK;

	if (!m_pSdesItems)
	{
		ASSERT(m_pSdesItems != NULL);

		SdesItems *pItems = NULL;
		hr = RtpConfigurationHelper_CreateSdesItems(DEFAULT_CNAME_T, W2T(szName), W2T(szEMail), W2T(szPhone), W2T(szLoc), W2T(szTool), W2T(szNote), &pItems);
		VALHR(hr);
	}
	else
	{
		if (szName && wcslen(szName) > 0) strncpy(m_pSdesItems->name, W2A(szName), RTP_COSTANTS_RTCP_SDES_ITEM_VALUE_MAXLENGTH);
		if (szName && wcslen(szEMail) > 0) strncpy(m_pSdesItems->email, W2A(szEMail), RTP_COSTANTS_RTCP_SDES_ITEM_VALUE_MAXLENGTH);
		if (szName && wcslen(szPhone) > 0) strncpy(m_pSdesItems->phone, W2A(szPhone), RTP_COSTANTS_RTCP_SDES_ITEM_VALUE_MAXLENGTH);
		if (szName && wcslen(szLoc) > 0) strncpy(m_pSdesItems->loc, W2A(szLoc), RTP_COSTANTS_RTCP_SDES_ITEM_VALUE_MAXLENGTH);
		if (szName && wcslen(szTool) > 0) strncpy(m_pSdesItems->tool, W2A(szTool), RTP_COSTANTS_RTCP_SDES_ITEM_VALUE_MAXLENGTH);
		if (szName && wcslen(szNote) > 0) strncpy(m_pSdesItems->note, W2A(szNote), RTP_COSTANTS_RTCP_SDES_ITEM_VALUE_MAXLENGTH);
	}

	CAutoLock lockSdes(&m_critSectSdesBufferLock);

	// reprepare the buffer
	SAFE_FREE(m_pBufferSdesFull);
	m_cbBufferSdesFull = 0;
	BYTE cbPad = 0;
	hr = RtcpSdesUtil_CreateSdesPacketWithHeader(&m_pBufferSdesFull, &m_cbBufferSdesFull, &cbPad, m_pSdesItems, FALSE);
	
	if (!m_bLeightweightSdes)
	{
		m_pBufferSdesLeightweight = m_pBufferSdesFull;
	}
	
	return hr;
}

STDMETHODIMP CRtpRenderer::ReserveNetworkAddressAndCreateSockets(
	LPWSTR szRemoteAddress, LPWSTR szLocalInterface, 
	USHORT uMinLocalPort, USHORT uMaxLocalPort, INT ttl, LPWSTR cname)// UINT uszLocalInterfaceMaxLen, USHORT* puRemotePort, INT addressFamilySpecification)
{
	HRESULT hr = InternalReserveNetworkAddressAndCreateSockets(
		szRemoteAddress, 
		szLocalInterface, 
		uMinLocalPort, uMaxLocalPort, ttl);
	ATLTRACE2("InternalReserveNetworkAddress Returns 0x%x \r\n", hr);
	VALHR(hr);

	if (m_pSdesItems == NULL)
	{
		m_pSdesItems = (SdesItems*)SAFE_ALLOC(sizeof(SdesItems));
		CheckPointer(m_pSdesItems, E_OUTOFMEMORY);

		if (cname)
		{
			USES_CONVERSION;
			strncpy(m_pSdesItems->cname, W2A(cname), 254);
		}
		else
		{
			strncpy(m_pSdesItems->cname, "Kite.RtpRenderer.Cname\0", 254);
		}
	}

	hr = InitializeRtcpReportGeneration();
	VALHR(hr);

	hr = this->CRtpSocketBase::InitializePerformanceCounter();
	VALHR(hr);

	hr = InitializePerformanceCounterForRtpRenderer();
	VALHR(hr);

	return S_OK;
}

STDMETHODIMP CRtpRenderer::ReserveNetworkAddress(
	LPWSTR szRemoteAddress, LPWSTR szLocalInterface,
	USHORT uMinLocalPort, USHORT uMaxLocalPort, LPWSTR szLocalInterfaceOut, INT cchLocalAddress, USHORT *puLocalPortBase)
{
	HRESULT hr = InternalReserveNetworkAddress(
		szRemoteAddress, 
		szLocalInterface, 
		uMinLocalPort, uMaxLocalPort, szLocalInterfaceOut, cchLocalAddress, puLocalPortBase);

	ATLTRACE2("InternalReserveNetworkAddress Returns 0x%x \r\n", hr);
	VALHR(hr);

	return S_OK;
}

STDMETHODIMP CRtpRenderer::GetNetworkParameter(
							   LPWSTR szRemoteAddress, INT cchRemoteAddress, USHORT *puRemotePort, 
							   LPWSTR szLocalInterface, INT cchLocalAddress, USHORT *puLocalPortBase, INT* pTtl)
{
	return InternalGetNetworkParameter(
		szRemoteAddress, cchRemoteAddress, puRemotePort, 
		szLocalInterface, cchLocalAddress, puLocalPortBase, pTtl);
}

STDMETHODIMP CRtpRenderer::GetSenderStatistics(UINT *pcPacketsSent, UINT *pcOctetsSent, UINT *pMillisecs)
{
	CheckPointer(pcPacketsSent, E_POINTER);
	CheckPointer(pcOctetsSent, E_POINTER);
	CheckPointer(pMillisecs, E_POINTER);

	CheckPointer(m_pPerfCounterRtpPacketsSent, E_UNEXPECTED);
	CheckPointer(m_pPerfCounterRtpOctetsSent, E_UNEXPECTED);

	(*pcPacketsSent) = m_pPerfCounterRtpPacketsSent->get_RawValueUint();
	(*pcOctetsSent) = m_pPerfCounterRtpOctetsSent->get_RawValueUint();
	(*pMillisecs) = 0; 

	return S_OK;
}

STDMETHODIMP CRtpRenderer::GetStatisticsForReceiver(UINT ssrcRRSource, BYTE *pFractionLost, UINT *pcCumulativeNumberOfPacketsLost, UINT *pInterarrivalJitter)
{
	CheckPointer(pFractionLost, E_POINTER);
	CheckPointer(pcCumulativeNumberOfPacketsLost, E_POINTER);
	CheckPointer(pInterarrivalJitter, E_POINTER);
	CheckPointer(ssrcRRSource, E_INVALIDARG);

	// TODO Lock the Map

	CRtpSessionMember* pMember = NULL;
	if (m_mapRtpSessionMembers.Lookup(ssrcRRSource))
	{
		if (!pMember)
		{
			m_mapRtpSessionMembers.RemoveKey(ssrcRRSource);
			return S_FALSE;
		}
		else
		{
			(*pFractionLost) = 0;
			(*pcCumulativeNumberOfPacketsLost) = 0;
			(*pInterarrivalJitter) = 0;
			return S_OK;
		}
	}

	return S_FALSE;	
}

STDMETHODIMP CRtpRenderer::GetPerformanceCounterPrefix(UINT ssrc, LPWSTR szPerfCounterPrefix, INT cchPerfCounterPrefix)
{
	return E_NOTIMPL;
}


STDMETHODIMP CRtpRenderer::get_LocalSsrc(UINT* pVal)
{
	CheckPointer(pVal, E_POINTER);
	(*pVal) = m_ssrc;
	return S_OK;
}

// Nur zum Testen
STDMETHODIMP CRtpRenderer::put_LocalSsrc(UINT newVal)
{
	CheckPointer(newVal, E_INVALIDARG);
	m_ssrc = newVal;
	return S_OK;
}
