#include "StdAfx.h"
#include ".\audiojitterbuffer.h"

//////////////////////////////////////////////////////////////////////////
AudioJitterBufferItem::AudioJitterBufferItem(RtpParsedPacket *pPacket)
{
	m_pPacket = pPacket;
	m_pLeft = NULL;
	m_pRight = NULL;
}

AudioJitterBufferItem::~AudioJitterBufferItem()
{
	SAFE_FREE(m_pPacket);
}

RtpParsedPacket* AudioJitterBufferItem::GetAndRemovePacket()
{
	RtpParsedPacket *pPacket = m_pPacket;
	m_pPacket = NULL;
	return pPacket;
}

//////////////////////////////////////////////////////////////////////////

CAudioJitterBuffer::CAudioJitterBuffer(void)
{
	m_pTop = NULL;

	m_bMuted = FALSE;

	m_tFirstSampleAfterBufferingStarted = 0;
	m_tsFirstSampleRtpTimestampOffset = 0;
	
	m_uTimestampIncrementPerSecond = 8000;
	m_uTimePerFrameNanos = (3 * 30 * 10000); // 3 Samples a 30 Millisecs - iLBC Low
	//////////////////////////////////////////////////////////////////////////

	// Dauer des Puffers, millis
	m_tBufferDuration = 500;
}

CAudioJitterBuffer::~CAudioJitterBuffer(void)
{
	Clear();
}

void CAudioJitterBuffer::StartBuffering()
{
	m_tsFirstSampleRtpTimestampOffset = 0;
	m_tFirstSampleAfterBufferingStarted = 0;
}

// remove the first item from the list and return it
RtpParsedPacket* CAudioJitterBuffer::Dequeue()
{
	if (m_pTop)
	{
		RtpParsedPacket* pPacket = m_pTop->GetAndRemovePacket();
		if (m_pTop->m_pRight)
		{
			AudioJitterBufferItem* pOldFirst = m_pTop;
			m_pTop->m_pRight->m_pLeft = NULL;
			m_pTop = m_pTop->m_pRight;
			SAFE_DELETE(pOldFirst);
		}
		else
		{
			SAFE_DELETE(m_pTop);
		}

		return pPacket;
	}

	return NULL;
}

// Insert Item to the list an possibly update the reference to the first item
BOOL CAudioJitterBuffer::Insert(RtpParsedPacket* pItem)
{
	if (pItem == NULL) return FALSE;

	if (m_tFirstSampleAfterBufferingStarted == 0)
	{
		// start the Buffer duration when first packet is received
		m_tFirstSampleAfterBufferingStarted = timeGetTime();
		m_tsFirstSampleRtpTimestampOffset = pItem->timestamp;
	}

	if (m_pTop)
	{
		if (m_pTop->m_pPacket->timestamp == pItem->timestamp)
		{
			SAFE_FREE(pItem);
			return FALSE;
		}
		if (m_pTop->m_pPacket->timestamp > pItem->timestamp)
		{
			// Insert Head
			AudioJitterBufferItem *pNew = new AudioJitterBufferItem(pItem);
			pNew->m_pLeft = NULL;
			pNew->m_pRight = m_pTop;
			m_pTop->m_pLeft = pNew;
			m_pTop = pNew;
			return TRUE;
		}

		AudioJitterBufferItem *pCurrent = m_pTop;
		
		do
		{
			if (!pCurrent->m_pRight)
			{
				AudioJitterBufferItem *pNew = new AudioJitterBufferItem(pItem);
				pNew->m_pLeft = pCurrent;
				pCurrent->m_pRight = pNew;
				return TRUE;
			}
			else if (pCurrent->m_pRight->m_pPacket->timestamp > pItem->timestamp)
			{
				// Insert 
				AudioJitterBufferItem *pNew = new AudioJitterBufferItem(pItem);
				pNew->m_pRight = pCurrent->m_pRight;
				pNew->m_pRight->m_pLeft = pNew;
				pNew->m_pLeft = pCurrent;
				pCurrent->m_pRight = pNew;
				
				return TRUE;
			}
			else if (pCurrent->m_pRight->m_pPacket->timestamp == pItem->timestamp)
			{
				SAFE_FREE(pItem);
				return FALSE;
			}
		}
		while (pCurrent = pCurrent->m_pRight);

		ASSERT(0);
		return FALSE;
	}
	else
	{
		m_pTop = new AudioJitterBufferItem(pItem);
		return TRUE;
	}
}

// Remove only pItem from the list, update references
void CAudioJitterBuffer::Remove(AudioJitterBufferItem *pItem)
{
	if (!pItem) return;

	if (m_pTop)
	{
		AudioJitterBufferItem* pCurrent = m_pTop;

		do 
		{
			if (pCurrent == pItem)	
			{
				// delete it
				if (pCurrent->m_pLeft)
				{
					// may be NULL
					pCurrent->m_pLeft->m_pRight = pCurrent->m_pRight;
				}
				else 
				{
					m_pTop = pCurrent->m_pRight;
				}

				if (pCurrent->m_pRight)
				{
					pCurrent->m_pRight->m_pLeft = pCurrent->m_pLeft;
				}

				pCurrent->m_pLeft = NULL;
				pCurrent->m_pRight = NULL;
				SAFE_DELETE(pCurrent);
				return;
			}
		} while(pCurrent = pCurrent->m_pRight);
	}
}

// Removes all items carrying a ts earlier or equal than iTimeStamp and updates references
void CAudioJitterBuffer::RemoveEarlierOrEqual(UINT uTimeStamp)
{
#ifdef DEBUG
	INT cRemoved = 0;
	if (m_pTop)
	{
		do 
		{
			if (m_pTop->m_pPacket->timestamp <= uTimeStamp)
			{
				cRemoved++;
				Remove(m_pTop);
			}
			else
			{
				break;
			}
		}
		while (m_pTop);
	}
	ATLTRACE2("%s Time: %u REMOVED %d Packets \r\n", __FUNCTION__, timeGetTime(), cRemoved);
#else
	if (m_pTop)
	{
		do 
		{
			if (m_pTop->m_pPacket->timestamp <= uTimeStamp)
			{
				Remove(m_pTop);
			}
			else
			{
				return;
			}
		}
		while (m_pTop);
	}
#endif
}

// Removes all items carrying a ts earlier or equal than iTimeStamp and updates references
void CAudioJitterBuffer::RemoveEarlier(UINT uTimeStamp)
{
#ifdef DEBUG
	INT cRemoved = 0;
	if (m_pTop)
	{
		do 
		{
			if (m_pTop->m_pPacket->timestamp < uTimeStamp)
			{
				cRemoved++;
				Remove(m_pTop);
			}
			else
			{
				break;
			}
		}
		while (m_pTop);
	}
	ATLTRACE2("%s Time: %u REMOVED %d Packets \r\n", __FUNCTION__, timeGetTime(), cRemoved);
#else
	if (m_pTop)
	{
		do 
		{
			if (m_pTop->m_pPacket->timestamp < uTimeStamp)
			{
				Remove(m_pTop);
			}
			else
			{
				return;
			}
		}
		while (m_pTop);
	}
#endif
}

// Remove all items
void CAudioJitterBuffer::Clear()
{
	RtpParsedPacket* pCurrentItem = Dequeue();

	while (pCurrentItem)
	{
		SAFE_FREE(pCurrentItem);
		
		pCurrentItem = Dequeue();
	}
}

UINT CAudioJitterBuffer::Count()
{
	AudioJitterBufferItem* pCurrent = m_pTop;
	UINT cItems = 0;
	while (pCurrent)
	{
		cItems++;
		pCurrent = pCurrent->m_pRight;
	}

	return cItems;
}

#ifdef DEBUG
void CAudioJitterBuffer::DebugPrint()
{
	AudioJitterBufferItem *pCurrent = m_pTop;

	ATLTRACE2("CAudioJitterBuffer::DebugPrint: Count is %d \r\n", Count());
	while(pCurrent)
	{
		// Print Current Item;
		ATLTRACE2("\t this-Ptr: 0x%x \r\n", pCurrent);
		ATLTRACE2("\t Packet:   0x%x \r\n", pCurrent->m_pPacket);
		ATLTRACE2("\t Left:     0x%x \r\n", pCurrent->m_pLeft);
		ATLTRACE2("\t Right:    0x%x \r\n", pCurrent->m_pRight);
		if (pCurrent->m_pPacket)
		{
			ATLTRACE2("\t TimeStamp 0x%x (%d) \r\n", pCurrent->m_pPacket->timestamp, pCurrent->m_pPacket->timestamp);
			ATLTRACE2("\t SeqNum    0x%x (%d) \r\n", pCurrent->m_pPacket->seqNum, pCurrent->m_pPacket->seqNum);
			ATLTRACE2("\t Marker    %d \r\n", pCurrent->m_pPacket->marker);
			ATLTRACE2("\t cbData    %d \r\n", pCurrent->m_pPacket->cbData);
			ATLTRACE2("\r\n", pCurrent->m_pPacket->cbData);
		}

		pCurrent = pCurrent->m_pRight;
	}
	ATLTRACE2("=================================================== \r\n");
}
#else
/*__forceinline */void CAudioJitterBuffer::DebugPrint() { __noop; }
#endif

STDMETHODIMP CAudioJitterBuffer::EnqueuePacket(RtpParsedPacket *pPacket)
{
	if (m_bMuted) 
	{
		SAFE_FREE(pPacket);
		return S_FALSE;
	}
	else
	{
		return (Insert(pPacket) ? S_OK : S_FALSE);
	}
}

STDMETHODIMP CAudioJitterBuffer::DequeuePackets(RtpParsedPacket ***pppRtpParsedPackets, UINT *pcPackets)
{
	CheckPointer(pppRtpParsedPackets, E_POINTER);
	CheckPointer(pcPackets, E_POINTER);

	UINT uDiff = timeGetTime() - m_tFirstSampleAfterBufferingStarted;

	if (uDiff < m_tBufferDuration)
	{
		return S_FALSE;
	}

	// RTP Zielzeitstempel ausrechen
	uDiff -= m_tBufferDuration;
	UINT uTargetRtpTimestamp = (((uDiff * m_uTimestampIncrementPerSecond) / 1000) + m_tsFirstSampleRtpTimestampOffset);

	RemoveEarlier(uTargetRtpTimestamp);

	if (m_pTop)
	{
		(*pppRtpParsedPackets) = (RtpParsedPacket**)SAFE_ALLOC(sizeof(RtpParsedPacket*));
		CheckPointer(*pppRtpParsedPackets, E_OUTOFMEMORY);
		(*pppRtpParsedPackets)[0] = Dequeue();
		(*pcPackets) = (*pppRtpParsedPackets)[0] ? 1 : 0;

		return S_OK;
	}
	else
	{
		*pppRtpParsedPackets = NULL;
		*pcPackets = 0;
		return S_FALSE;
	}
}

STDMETHODIMP CAudioJitterBuffer::ExpireOlderThanOrEqual(UINT uTimestamp)
{
	RemoveEarlierOrEqual(uTimestamp);
	return S_OK;
}

STDMETHODIMP CAudioJitterBuffer::ClearBuffer(void)
{
	Clear();
	return S_OK;
}

STDMETHODIMP CAudioJitterBuffer::SetBufferParameter(
								UINT uBufferDurationMilliseconds,
								UINT uTimestampIncrementPerSecond,
								UINT uTimePerFrameNanos)
{
	ATLTRACE2("CAudioJitterBuffer::SetBufferParameter Duration %ud %ud / Rtp %ud %ud / Adu %ud %ud \r\n", 
		m_tBufferDuration, uBufferDurationMilliseconds, m_uTimestampIncrementPerSecond, uTimestampIncrementPerSecond, m_uTimePerFrameNanos, uTimePerFrameNanos);
	
	m_tBufferDuration = uBufferDurationMilliseconds;
	m_uTimestampIncrementPerSecond = uTimestampIncrementPerSecond;
	m_uTimePerFrameNanos = uTimePerFrameNanos;

	return S_OK;
}

STDMETHODIMP CAudioJitterBuffer::SetLatency(UINT millisecs)
{
	if ((millisecs < 0) && (millisecs > 10000)) return E_INVALIDARG;
	m_tBufferDuration =  millisecs;
	return S_OK;
}

STDMETHODIMP CAudioJitterBuffer::GetLatency(UINT *pMillisecs)
{
	CheckPointer(pMillisecs, E_POINTER);
	(*pMillisecs) = m_tBufferDuration;
	return S_OK;
}

STDMETHODIMP CAudioJitterBuffer::SetMuted(INT bMuted)
{
	if (m_bMuted == bMuted) return S_FALSE;

	m_bMuted = bMuted;
	if (bMuted)
	{
		ClearBuffer();
	}

	return S_OK;
}

STDMETHODIMP CAudioJitterBuffer::GetMuted(INT* pbMuted)
{
	CheckPointer(pbMuted, E_POINTER);
	(*pbMuted) = m_bMuted;
	return S_OK;
}
