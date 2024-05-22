#include "StdAfx.h"
#include ".\videojitterbuffer.h"

CVideoJitterBuffer::CVideoJitterBuffer(void)
{
	BOOL bRetVal = InitializeCriticalSectionAndSpinCount(&m_critSectMapFramesSynchronization, 0x80000400);
	bRetVal = InitializeCriticalSectionAndSpinCount(&m_critSectObjectLock, 0x80000400);

	m_pTop = NULL; 

	m_bMuted = FALSE;

	m_tBufferDuration = 500;
	m_uTimePerFrameNanos = ((1000 * 10000) / 10);
	m_uTimestampIncrementPerSecond = 90000;

	m_tsFirstSampleRtpTimestampOffset = 0;
	m_uLowWaterMark = 0;

	m_tFirstSampleAfterBufferingStarted = 0;
	m_tsFirstSampleRtpTimestampOffset = 0;
	m_uTimestampIncrementPerSecond = 90000; // fixe3d for video
}

CVideoJitterBuffer::~CVideoJitterBuffer(void)
{
	ClearBuffer();

	DeleteCriticalSection(&m_critSectMapFramesSynchronization);
	DeleteCriticalSection(&m_critSectObjectLock);
}

void CVideoJitterBuffer::StartBuffering()
{
	CAutoLock lock(&m_critSectObjectLock);
	m_tsFirstSampleRtpTimestampOffset = 0;
	m_tFirstSampleAfterBufferingStarted = 0;
}

STDMETHODIMP CVideoJitterBuffer::SetBufferParameter(
							  UINT uBufferDurationMilliseconds,
							  UINT uTimestampIncrementPerSecond,
							  UINT uTimePerFrameNanos)
{
	CAutoLock lock(&m_critSectObjectLock);

	m_tBufferDuration = uBufferDurationMilliseconds;
	m_uTimestampIncrementPerSecond = uTimestampIncrementPerSecond;
	m_uTimePerFrameNanos = uTimePerFrameNanos;
	return S_OK;
}

STDMETHODIMP CVideoJitterBuffer::SetLatency(UINT millisecs)
{
	if ((millisecs < 0) && (millisecs > 10000)) return E_INVALIDARG;
	m_tBufferDuration =  millisecs;
	return S_OK;
}

STDMETHODIMP CVideoJitterBuffer::GetLatency(UINT *pMillisecs)
{
	CheckPointer(pMillisecs, E_POINTER);
	(*pMillisecs) = m_tBufferDuration;
	return S_OK;
}

STDMETHODIMP CVideoJitterBuffer::SetMuted(INT bMuted)
{
	if (m_bMuted == bMuted) return S_FALSE;

	m_bMuted = bMuted;
	if (bMuted)
	{
		ClearBuffer();
	}

	return S_OK;
}

STDMETHODIMP CVideoJitterBuffer::GetMuted(INT* pbMuted)
{
	CheckPointer(pbMuted, E_POINTER);
	(*pbMuted) = m_bMuted;
	return S_OK;
}

STDMETHODIMP CVideoJitterBuffer::EnqueuePacket(RtpParsedPacket *pPacket)
{
	CheckPointer(pPacket, E_POINTER);

	if (m_bMuted) 
	{
		SAFE_FREE(pPacket);
		return S_FALSE;
	}

	CAutoLock lock(&m_critSectObjectLock);
	CAutoLock lockMap(&m_critSectMapFramesSynchronization);

	if (!m_tFirstSampleAfterBufferingStarted)
	{
		m_tFirstSampleAfterBufferingStarted = timeGetTime();
		m_tsFirstSampleRtpTimestampOffset = pPacket->timestamp;
	}

	if (m_pTop)
	{
		CVideoJitterBufferItemTimestamp *pItemAtTimestamp = NULL;
		if (NULL != (pItemAtTimestamp = m_pTop->Find(pPacket->timestamp)))
		{
			pItemAtTimestamp->InsertPacketToFrame(pPacket);
		}
		else
		{
			CVideoJitterBufferItem *pItem = new CVideoJitterBufferItem(pPacket);
			pItemAtTimestamp = new CVideoJitterBufferItemTimestamp(pItem);
			m_pTop = m_pTop->Insert(pItemAtTimestamp);
			ASSERT(m_pTop);
		}
	}
	else
	{
		CVideoJitterBufferItem *pItem = new CVideoJitterBufferItem(pPacket);
		m_pTop = new CVideoJitterBufferItemTimestamp(pItem);
		ASSERT(m_pTop);
	}

	return S_OK;
}

HRESULT CVideoJitterBuffer::DequeueDeliveryUnit(RtpParsedPacket ***pppPackets, UINT *pcPackets)
{
	CheckPointer(pppPackets, E_POINTER);
	CheckPointer(pcPackets, E_POINTER);

	CAutoLock lock(&m_critSectObjectLock);
	CAutoLock lockMap(&m_critSectMapFramesSynchronization);

	UINT uDiff = timeGetTime() - m_tFirstSampleAfterBufferingStarted; 
	if (uDiff < m_tBufferDuration)
	{
		ATLTRACE2("CVideoJitterBuffer::DequeueDeliveryUnit Puffer noch nicht gef�llt \r\n");
		return S_FALSE;
	}

	uDiff -= m_tBufferDuration;
	UINT uTargetRtpTimestamp = (((uDiff * m_uTimestampIncrementPerSecond) / 1000) + m_tsFirstSampleRtpTimestampOffset);

	RemoveEarlier(uTargetRtpTimestamp);
	(*pcPackets) = 0;
	(*pppPackets) = NULL;
	CheckPointer(m_pTop, S_FALSE);

	(*pcPackets) = m_pTop->GetItemCount();

	if (*pcPackets == 0)
	{
		(*pppPackets) = NULL;
		return S_FALSE;
	}

	(*pppPackets) = (RtpParsedPacket**)SAFE_ALLOC((*pcPackets) * sizeof(RtpParsedPacket*));
	CheckPointer(*pppPackets, E_OUTOFMEMORY);

	UINT uPacketIterator = 0;
	CVideoJitterBufferItem* pCurrentItem = NULL;
	for (; uPacketIterator < *pcPackets; uPacketIterator++)
	{
		pCurrentItem = m_pTop->DequeuePacket();
		if (pCurrentItem != NULL)
		{
			(*pppPackets)[uPacketIterator] = pCurrentItem->GetAndRemovePacket();
			SAFE_DELETE(pCurrentItem);
		}
		else
		{
			ASSERT(0);
			(*pppPackets)[uPacketIterator] = NULL;
		}
	}
	
	CVideoJitterBufferItemTimestamp *pTimestamp = m_pTop->m_pNext;
	m_pTop->Remove(m_pTop);
	delete m_pTop;
	m_pTop = pTimestamp;

	return S_OK;
}

UINT CVideoJitterBuffer::Count()
{
	if (!m_pTop) return 0;

	CAutoLock lock(&m_critSectObjectLock);
	CAutoLock lockMap(&m_critSectMapFramesSynchronization);

	UINT cTimestampItems = 0;
	CVideoJitterBufferItemTimestamp *pItem = m_pTop;
	do 
	{
		cTimestampItems++;
	}
	while(NULL != (pItem = pItem->m_pNext));

	return cTimestampItems;
}

void CVideoJitterBuffer::RemoveEarlier(UINT uTimeStamp)
{
	CAutoLock lock(&m_critSectObjectLock);
	CAutoLock lockMap(&m_critSectMapFramesSynchronization);
#ifdef DEBUG
	INT cRemoved = 0;
	while (m_pTop && m_pTop->m_pFrame && m_pTop->m_pFrame->m_pRtpParsedPacket)
	{
		if (m_pTop->m_pFrame->m_pRtpParsedPacket->timestamp < uTimeStamp)
		{
			cRemoved++;
			Remove(m_pTop);
		}
		else
		{
			break;
		}
	}

	ATLTRACE2("%s (Time) %u REMOVED %d \r\n", __FUNCTION__, timeGetTime(), cRemoved);
#else
	while (m_pTop && m_pTop->m_pFrame && m_pTop->m_pFrame->m_pRtpParsedPacket)
	{
		if (m_pTop->m_pFrame->m_pRtpParsedPacket->timestamp < uTimeStamp)
		{
			Remove(m_pTop);
		}
		else
		{
			return;
		}
	}
#endif

}

void CVideoJitterBuffer::Remove(CVideoJitterBufferItemTimestamp* pItem)
{
	CVideoJitterBufferItemTimestamp *pTemp = m_pTop->m_pNext;
	SAFE_DELETE(m_pTop);
	m_pTop = pTemp;
}
//////////////////////////////////////////////////////////////////////////

STDMETHODIMP CVideoJitterBuffer::TimeoutDeliveryUnitsEarlierThan(UINT timestamp)
{
	CAutoLock lock(&m_critSectObjectLock);
	CAutoLock lockMap(&m_critSectMapFramesSynchronization);

	CheckPointer(m_pTop, S_FALSE);
	
	m_pTop = m_pTop->Find(timestamp);
	m_pTop->DeletePrevious();

	DebugPrint();

	return S_OK;
}

STDMETHODIMP CVideoJitterBuffer::ClearBuffer()
{
	CAutoLock lock(&m_critSectObjectLock);
	CAutoLock lockMap(&m_critSectMapFramesSynchronization);

	CheckPointer(m_pTop, S_FALSE);

	if (m_pTop)
		delete m_pTop->Last();

	m_pTop = NULL;

	return S_OK;
}

VOID CVideoJitterBuffer::DebugPrint()
{
	CAutoLock lock(&m_critSectObjectLock);
	CAutoLock lockMap(&m_critSectMapFramesSynchronization);

	ATLTRACE2("Ich bin ein VideoJitterBuffer: \r\n");
	if (m_pTop) m_pTop->DebugPrint();
}

STDMETHODIMP CVideoJitterBuffer::DequeuePackets(RtpParsedPacket ***pppRtpParsedPackets, UINT *pcPackets)
{
	return DequeueDeliveryUnit(pppRtpParsedPackets, pcPackets);
}

STDMETHODIMP CVideoJitterBuffer::ExpireOlderThanOrEqual(UINT uTimestamp)
{
	return TimeoutDeliveryUnitsEarlierThan(uTimestamp + 1);
}
