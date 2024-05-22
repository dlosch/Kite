// VideoPlayoutBuffer.cpp : Implementation of CVideoPlayoutBuffer

#include "stdafx.h"
#include "VideoPlayoutBuffer.h"
#include ".\videoplayoutbuffer.h"

// CVideoPlayoutBuffer
CVideoPlayoutBuffer::CVideoPlayoutBuffer()
{
}

HRESULT CVideoPlayoutBuffer::FinalConstruct()
{
	m_hManualResetEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	m_bIsEventSignalled = FALSE;
	if (m_hManualResetEvent == NULL) return S_FALSE;

	BOOL bRetVal = InitializeCriticalSectionAndSpinCount(&m_critSectMapFramesSynchronization, 0x80000400);
	bRetVal = InitializeCriticalSectionAndSpinCount(&m_critSectObjectLock, 0x80000400);
	bRetVal = InitializeCriticalSectionAndSpinCount(&m_critSectManualResetEvent, 0x80000400);

	m_payloadType = 0; // Wildcard

	m_bDisposed = FALSE;

	m_pTop = NULL; 

	m_bMuted = FALSE;

	m_tBufferDuration = 500;
	m_uTimePerFrameNanos = ((1000 * 10000) / 10);
	m_uTimestampIncrementPerSecond = 90000;

	m_tsFirstSampleRtpTimestampOffset = 0;

	m_uLowWaterMark = 5;

	m_tFirstSampleAfterBufferingStarted = 0;
	m_tsFirstSampleRtpTimestampOffset = 0;
	m_uTimestampIncrementPerSecond = 90000; // fixe3d for video

	return S_OK;
}

__forceinline  void CVideoPlayoutBuffer::UpdateEventState()
{
	INT cItems = Count();
	if (cItems < m_uLowWaterMark)
	{
		CAutoLock lock(&m_critSectManualResetEvent);

		if (m_bIsEventSignalled)
		{
			ResetEvent(m_hManualResetEvent);
			m_bIsEventSignalled = FALSE;
		}
	}
	else if (!m_bIsEventSignalled)
	{
		CAutoLock lock(&m_critSectManualResetEvent);
		SetEvent(m_hManualResetEvent);
		m_bIsEventSignalled = TRUE;

	}
}

void CVideoPlayoutBuffer::FinalRelease() 
{
	ClearBuffer();

	DeleteCriticalSection(&m_critSectMapFramesSynchronization);
	DeleteCriticalSection(&m_critSectObjectLock);

	CloseHandle(m_hManualResetEvent);
}

STDMETHODIMP CVideoPlayoutBuffer::get_Disposed(BOOL* pVal)
{
	CheckPointer(pVal, E_POINTER);
	(*pVal) = m_bDisposed;
	return S_OK;
}

STDMETHODIMP CVideoPlayoutBuffer::Dispose(void)
{
	CAutoLock lock(&m_critSectObjectLock);

	m_bDisposed = TRUE;

	// Stop and deallocate all resources
	ClearBuffer();

	return S_OK;
}

STDMETHODIMP CVideoPlayoutBuffer::put_PayloadType(BYTE payloadType)
{
	CheckDisposed;
	if (payloadType > 127) return E_INVALIDARG;
	m_payloadType = payloadType;
	return S_OK;
}

STDMETHODIMP CVideoPlayoutBuffer::get_PayloadType(BYTE *pPayloadType)
{
	CheckDisposed;
	CheckPointer(pPayloadType, E_POINTER);
	(*pPayloadType) = m_payloadType;
	return S_OK;
}

void CVideoPlayoutBuffer::StartBuffering()
{
	CAutoLock lock(&m_critSectObjectLock);
	m_tsFirstSampleRtpTimestampOffset = 0;
	m_tFirstSampleAfterBufferingStarted = 0;
}

STDMETHODIMP CVideoPlayoutBuffer::SetBufferParameter(
	UINT uBufferDurationMilliseconds,
	UINT uTimestampIncrementPerSecond,
	UINT uTimePerFrameNanos)
{
	CAutoLock lock(&m_critSectObjectLock);
	CheckDisposed;

	// Setze die Parameter
	m_tBufferDuration = uBufferDurationMilliseconds;
	m_uTimestampIncrementPerSecond = uTimestampIncrementPerSecond;
	m_uTimePerFrameNanos = uTimePerFrameNanos;

	return S_OK;
}

STDMETHODIMP CVideoPlayoutBuffer::SetLatency(UINT millisecs)
{
	CheckDisposed;

	if ((millisecs < 0) && (millisecs > 10000)) return E_INVALIDARG;
	m_tBufferDuration =  millisecs;
	return S_OK;
}

STDMETHODIMP CVideoPlayoutBuffer::GetLatency(UINT *pMillisecs)
{
	CheckDisposed;

	CheckPointer(pMillisecs, E_POINTER);
	(*pMillisecs) = m_tBufferDuration;
	return S_OK;
}

STDMETHODIMP CVideoPlayoutBuffer::SetMuted(INT bMuted)
{
	CheckDisposed;

	if (m_bMuted == bMuted) return S_FALSE;

	m_bMuted = bMuted;
	if (bMuted)
	{
		ClearBuffer();
	}

	return S_OK;
}

STDMETHODIMP CVideoPlayoutBuffer::GetMuted(INT* pbMuted)
{
	CheckDisposed;

	CheckPointer(pbMuted, E_POINTER);
	(*pbMuted) = m_bMuted;
	return S_OK;
}

STDMETHODIMP CVideoPlayoutBuffer::InsertPacketToTsItem(RtpParsedPacket *pPacket, CVideoJitterBufferItemTimestamp *pTimestamp)
{
	CheckPointer(pPacket, E_POINTER);
	CheckPointer(pTimestamp, E_POINTER);

	ASSERT(pTimestamp->m_pFrame);
	ASSERT(pTimestamp->m_pFrame->m_pRtpParsedPacket);
	ASSERT(pPacket->timestamp == pTimestamp->m_pFrame->m_pRtpParsedPacket->timestamp);
	
	CheckPointer(pTimestamp->m_pFrame, E_POINTER);
	CheckPointer(pTimestamp->m_pFrame->m_pRtpParsedPacket, E_POINTER);

	CVideoJitterBufferItem *pSeqNum = pTimestamp->m_pFrame;

	do 
	{
		ASSERT(pSeqNum->m_pRtpParsedPacket);

		if (pPacket->seqNum < pSeqNum->m_pRtpParsedPacket->seqNum) // (Paket ist kleiner Element)
		{
			// Insert left new
			CVideoJitterBufferItem *pSeqNumNew = new CVideoJitterBufferItem(pPacket);
			pSeqNumNew->m_pPrev = pSeqNum->m_pPrev;
			
			if (pSeqNumNew->m_pPrev) pSeqNumNew->m_pPrev->m_pNext = pSeqNumNew;
			else pTimestamp->m_pFrame = pSeqNumNew;

			pSeqNumNew->m_pNext = pSeqNum;
			pSeqNum->m_pPrev = pSeqNumNew;

			return S_OK;
		}
		else if (pPacket->seqNum == pSeqNum->m_pRtpParsedPacket->seqNum) // (Paket gleich Element)
		{
			// Drop, da duplikat
			SAFE_FREE(pPacket);
			return S_FALSE;
		}
		else if (pPacket->seqNum > pSeqNum->m_pRtpParsedPacket->seqNum) // (Packet ist gr��er element)
		{
			if (pSeqNum->m_pNext == NULL) //(rechts existiert nicht)
			{
				// rechts new
				CVideoJitterBufferItem *pSeqNumNewRight = new CVideoJitterBufferItem(pPacket);
				pSeqNumNewRight->m_pPrev = pSeqNum;
				pSeqNumNewRight->m_pNext = NULL;
				pSeqNum->m_pNext = pSeqNumNewRight;

				return S_OK;
			}
		}			
	} 
	while(NULL != (pSeqNum = pSeqNum->m_pNext));

	ASSERT(0);
	return E_FAIL;
}

STDMETHODIMP CVideoPlayoutBuffer::Insert(RtpParsedPacket *pPacket)
{
	CheckPointer(pPacket, E_POINTER);
	CAutoLock lockMap(&m_critSectMapFramesSynchronization);

	if (m_tFirstSampleAfterBufferingStarted == 0)
	{
		m_tFirstSampleAfterBufferingStarted = timeGetTime();
		m_tsFirstSampleRtpTimestampOffset = pPacket->timestamp;
	}

	if (m_pTop)
	{
		ASSERT(m_pTop->m_pFrame);
		ASSERT(m_pTop->m_pFrame->m_pRtpParsedPacket);

		if (pPacket->timestamp < m_pTop->m_pFrame->m_pRtpParsedPacket->timestamp)
		{
			CVideoJitterBufferItemTimestamp *pTimestampNew = new CVideoJitterBufferItemTimestamp(pPacket);
			pTimestampNew->m_pPrev = NULL;
			pTimestampNew->m_pNext = m_pTop;
			pTimestampNew->m_pNext->m_pPrev = pTimestampNew;
			m_pTop = pTimestampNew;

			UpdateEventState();

			return S_OK;
		}
		else
		{
			CVideoJitterBufferItemTimestamp *pTimestamp = m_pTop;

			do 
			{
				ASSERT(pTimestamp->m_pFrame);
				ASSERT(pTimestamp->m_pFrame->m_pRtpParsedPacket);

				if (pPacket->timestamp < pTimestamp->m_pFrame->m_pRtpParsedPacket->timestamp) // (Paket ist kleiner Element)
				{
					// Insert left new
					CVideoJitterBufferItemTimestamp *pTimestampNew = new CVideoJitterBufferItemTimestamp(pPacket);
					pTimestampNew->m_pPrev = pTimestamp->m_pPrev;
					if (pTimestampNew->m_pPrev) pTimestampNew->m_pPrev->m_pNext = pTimestampNew;

					pTimestampNew->m_pNext = pTimestamp;
					pTimestamp->m_pPrev = pTimestampNew;

					UpdateEventState();

					return S_OK;
				}
				else if (pPacket->timestamp == pTimestamp->m_pFrame->m_pRtpParsedPacket->timestamp) // (Paket gleich Element)
				{
					// Insert here
					return InsertPacketToTsItem(pPacket, pTimestamp);
				}
				//else if (pPacket->timestamp > pTimestamp->m_pFrame->m_pRtpParsedPacket->timestamp) // (Packet ist gr��er element)
				{
					if (pTimestamp->m_pNext == NULL) //(rechts existiert)
					{
						// rechts new
						CVideoJitterBufferItemTimestamp *pTimestampNewRight = new CVideoJitterBufferItemTimestamp(pPacket);
						pTimestampNewRight->m_pPrev = pTimestamp;
						pTimestampNewRight->m_pNext = NULL;
						pTimestamp->m_pNext = pTimestampNewRight;

						UpdateEventState();
						return S_OK;
					}
					//else 
					//{
					//	continue;
					//}
				}
			}
			while(NULL != (pTimestamp = pTimestamp->m_pNext));

			ASSERT(0);
			return E_FAIL;
		}
	}
	else 
	{
		m_pTop = new CVideoJitterBufferItemTimestamp(pPacket);
	
		return S_OK;
	}
}

//HRESULT 
STDMETHODIMP CVideoPlayoutBuffer::EnqueuePacket(RtpParsedPacket *pPacket)
{
	CheckDisposed;

	// TRACECALL;
	CheckPointer(pPacket, E_POINTER);

	if (m_bMuted) 
	{
		SAFE_FREE(pPacket);
		return S_FALSE;
	}

	if (m_payloadType)
	{
		if (m_payloadType != ((BYTE)(pPacket->payloadType & 0xFF)))
		{
			LOG("PayloadType Mismatch - dropping the packet");
			SAFE_FREE(pPacket);
			return S_PROPERTY_CHANGED;
		}
	}
	return Insert(pPacket);

	return S_OK;
}

UINT CVideoPlayoutBuffer::CountSeqNums(CVideoJitterBufferItemTimestamp *pTimestamp)
{
	if (!pTimestamp) return -1;

	ASSERT(pTimestamp->m_pFrame);
	ASSERT(pTimestamp->m_pFrame->m_pRtpParsedPacket);

	UINT cFrames = 1;
	CVideoJitterBufferItem* pItem = pTimestamp->m_pFrame;
	while (NULL != (pItem = pItem->m_pNext))
	{
		cFrames++;
	}

	return cFrames;
}

HRESULT CVideoPlayoutBuffer::DequeueDeliveryUnit(RtpParsedPacket ***pppPackets, UINT *pcPackets)
{
	CheckDisposed;
	CheckPointer(pppPackets, E_POINTER);
	CheckPointer(pcPackets, E_POINTER);

	ATLTRACE2("\r\n CVideoPlayoutBuffer::DequeueDeliveryUnit %d \r\n", Count());

	CAutoLock lock(&m_critSectObjectLock);
	CAutoLock lockMap(&m_critSectMapFramesSynchronization);

	UINT uDiff = timeGetTime() - m_tFirstSampleAfterBufferingStarted; 
	if (uDiff < m_tBufferDuration)
	{
		ATLTRACE2("CVideoPlayoutBuffer::DequeueDeliveryUnit Puffer noch nicht gef�llt \r\n");
		return S_FALSE;
	}

	uDiff -= m_tBufferDuration;
	UINT uTargetRtpTimestamp = (((uDiff * m_uTimestampIncrementPerSecond) / 1000) + m_tsFirstSampleRtpTimestampOffset);

	(*pcPackets) = 0;
	(*pppPackets) = NULL;
	CheckPointer(m_pTop, S_FALSE);

	(*pcPackets) = CountSeqNums(m_pTop);//  m_pTop->GetItemCount();

	if (*pcPackets <= 0)
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
	if (pTimestamp)
		pTimestamp->m_pPrev = NULL;
	m_pTop->m_pNext = NULL;

	delete m_pTop;
	m_pTop = pTimestamp;

	return S_OK;
}

UINT CVideoPlayoutBuffer::Count()
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

// Removes all items carrying a ts earlier or equal than iTimeStamp and updates references
void CVideoPlayoutBuffer::RemoveEarlier(UINT uTimeStamp)
{
	CAutoLock lock(&m_critSectObjectLock);
	CAutoLock lockMap(&m_critSectMapFramesSynchronization);

	if (Count() < 3) return;

#ifdef DEBUG
	INT cRemoved = 0;
	while (m_pTop && m_pTop->m_pFrame && m_pTop->m_pFrame->m_pRtpParsedPacket)
	{
		if (m_pTop->m_pFrame->m_pRtpParsedPacket->timestamp < uTimeStamp)
		{
			cRemoved++;
			RemoveTop();
		}
		else
		{
			break;
		}
	}

	ATLTRACE2("%s (Time) %u REMOVED %d Count is %d \r\n", __FUNCTION__, timeGetTime(), cRemoved, Count());
#else
	while (m_pTop && m_pTop->m_pFrame && m_pTop->m_pFrame->m_pRtpParsedPacket)
	{
		if (m_pTop->m_pFrame->m_pRtpParsedPacket->timestamp < uTimeStamp)
		{
			RemoveTop();
		}
		else
		{
			return;
		}
	}
#endif

}

void CVideoPlayoutBuffer::RemoveTop() //CVideoJitterBufferItemTimestamp* pItem)
{
	CVideoJitterBufferItemTimestamp *pTemp = m_pTop->m_pNext;
	SAFE_DELETE(m_pTop);
	m_pTop = pTemp;
}
//////////////////////////////////////////////////////////////////////////

STDMETHODIMP CVideoPlayoutBuffer::TimeoutDeliveryUnitsEarlierThan(UINT timestamp)
{
	CheckDisposed;

	CAutoLock lock(&m_critSectObjectLock);
	CAutoLock lockMap(&m_critSectMapFramesSynchronization);

	CheckPointer(m_pTop, S_FALSE);

	m_pTop = m_pTop->Find(timestamp);
	m_pTop->DeletePrevious();

	DebugPrint();

	return S_OK;
}

STDMETHODIMP CVideoPlayoutBuffer::ClearBuffer()
{
	CAutoLock lock(&m_critSectObjectLock);
	CAutoLock lockMap(&m_critSectMapFramesSynchronization);

	CheckPointer(m_pTop, S_FALSE);

	if (m_pTop)
		delete m_pTop->Last();

	m_pTop = NULL;

	return S_OK;
}

VOID CVideoPlayoutBuffer::DebugPrint()
{
	CAutoLock lock(&m_critSectObjectLock);
	CAutoLock lockMap(&m_critSectMapFramesSynchronization);

	ATLTRACE2("Ich bin ein VideoJitterBuffer: \r\n");
	if (m_pTop) m_pTop->DebugPrint();
}

// IJitterBuffer
STDMETHODIMP CVideoPlayoutBuffer::DequeuePackets(RtpParsedPacket ***pppRtpParsedPackets, UINT *pcPackets)
{
	return DequeueDeliveryUnit(pppRtpParsedPackets, pcPackets);
}

STDMETHODIMP CVideoPlayoutBuffer::ExpireOlderThanOrEqual(UINT uTimestamp)
{
	return TimeoutDeliveryUnitsEarlierThan(uTimestamp + 1);
}


STDMETHODIMP CVideoPlayoutBuffer::get_DueTime(UINT* pDueTimeMilliseconds)
{
	CheckPointer(pDueTimeMilliseconds, E_POINTER);
	(*pDueTimeMilliseconds) = (m_uTimePerFrameNanos / 10000);
	return S_OK;
}

STDMETHODIMP CVideoPlayoutBuffer::get_EventHandle(LONG_PTR** pEventHandle)
{
	CheckPointer(pEventHandle, E_POINTER);
	*pEventHandle = (LONG_PTR*)m_hManualResetEvent;
	return S_OK;
}


STDMETHODIMP CVideoPlayoutBuffer::get_BufferDurationMilliseconds(UINT* pVal)
{
	CheckPointer(pVal, E_POINTER);
	*pVal = m_tBufferDuration;
	return S_OK;
}

STDMETHODIMP CVideoPlayoutBuffer::put_BufferDurationMilliseconds(UINT newVal)
{
	if (newVal == 0 || newVal > 10000) return E_UNEXPECTED;
	CAutoLock lock(&m_critSectObjectLock);
	m_tBufferDuration = newVal;
	return S_OK;
}

STDMETHODIMP CVideoPlayoutBuffer::get_RtpTimestampIncrementPerSecond(UINT* pVal)
{
	CheckPointer(pVal, E_POINTER);
	*pVal = m_uTimestampIncrementPerSecond;
	return S_OK;
}

STDMETHODIMP CVideoPlayoutBuffer::put_RtpTimestampIncrementPerSecond(UINT newVal)
{
	CAutoLock lock(&m_critSectObjectLock);
	m_uTimestampIncrementPerSecond = newVal;
	return S_OK;
}

STDMETHODIMP CVideoPlayoutBuffer::get_TimePerSampleNanos(UINT* pVal)
{
	CheckPointer(pVal, E_POINTER);
	*pVal = m_uTimePerFrameNanos;
	return S_OK;
}

STDMETHODIMP CVideoPlayoutBuffer::put_TimePerSampleNanos(UINT newVal)
{
	if (newVal < 100000) return E_UNEXPECTED;
	CAutoLock lock(&m_critSectObjectLock);
	m_uTimePerFrameNanos = newVal;
	return S_OK;
}
