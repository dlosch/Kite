#ifndef VIDEOJITTERBUFFERITEMS_H
#define VIDEOJITTERBUFFERITEMS_H

// Same Timestamp: doppelt			 verlinkte Liste
class CVideoJitterBufferItem
{
public:
	CVideoJitterBufferItem *m_pPrev;
	CVideoJitterBufferItem *m_pNext;
	RtpParsedPacket *m_pRtpParsedPacket;

	CVideoJitterBufferItem(RtpParsedPacket *pPacket)
	{
		m_pNext = NULL;
		m_pPrev = NULL;
		m_pRtpParsedPacket = pPacket;
	}

	~CVideoJitterBufferItem()
	{
		SAFE_FREE(m_pRtpParsedPacket);
	}

	RtpParsedPacket* GetAndRemovePacket()
	{
		RtpParsedPacket* pTemp = m_pRtpParsedPacket;
		m_pRtpParsedPacket = NULL;
		return pTemp;
	}

	CVideoJitterBufferItem* Find(UINT seqNum)
	{
		if (seqNum == m_pRtpParsedPacket->seqNum)
		{
			return this;
		}
		else if (seqNum > m_pRtpParsedPacket->seqNum)
		{
			return (m_pNext ? m_pNext->Find(seqNum) : NULL);
		}
		else return NULL;
	}
	VOID Remove(CVideoJitterBufferItem *pItem)
	{
		if (this != pItem)
		{
			if (m_pRtpParsedPacket->seqNum > pItem->m_pRtpParsedPacket->seqNum)
			{
			}
			else
			{
				/*this->m_pNext = */ m_pNext->Remove(pItem);
			}
		}
		else
		{
			if (m_pNext)
			{
				// TODO dies ist dirty
				m_pNext->m_pPrev = this->m_pPrev;
			}

			if (m_pPrev)
			{
				m_pPrev->m_pNext = m_pNext;
			}
		}
	}

	CVideoJitterBufferItem* Insert(CVideoJitterBufferItem *pItem)
	{
		if (!pItem) return this;

		if (pItem->m_pRtpParsedPacket->seqNum < m_pRtpParsedPacket->seqNum)
		{
			pItem->m_pPrev = this->m_pPrev;
			pItem->m_pNext = this;
			this->m_pPrev = pItem;

			return pItem;
		}
		else
		{
			if (pItem->m_pRtpParsedPacket->seqNum == this->m_pRtpParsedPacket->seqNum)
			{
				delete pItem;
				return this;
			}
			else // if (pItem->m_pRtpParsedPacket->seqNum > this->m_pRtpParsedPacket->seqNum)
			{
				if (m_pNext)
				{
					m_pNext = m_pNext->Insert(pItem);
				}
				else
				{
					m_pNext = pItem;
					pItem->m_pPrev = this;
				}

				return this;
			}
		}
	}

	VOID DebugPrint()
	{
		ATLTRACE2("\t\tIch bin CVideoJitterBufferItem, mein Timestamp ist %d, meine SeqNum ist %d  m_pPrev 0x%x m_pNext 0x%x  und hier kommt mein n�chster: \r\n", m_pRtpParsedPacket->timestamp, m_pRtpParsedPacket->seqNum, m_pPrev, m_pNext);
		if (m_pNext) m_pNext->DebugPrint();
	}
};

class CVideoJitterBufferItemTimestamp
{
public:
	CVideoJitterBufferItemTimestamp *m_pPrev;
	CVideoJitterBufferItemTimestamp *m_pNext;

	CVideoJitterBufferItem *m_pFrame;

	CVideoJitterBufferItemTimestamp(CVideoJitterBufferItem *pFrame)
	{
		m_pNext = NULL;
		m_pPrev = NULL;
		m_pFrame = pFrame;
	}

	CVideoJitterBufferItemTimestamp(RtpParsedPacket *pPacket)
	{
		m_pNext = NULL;
		m_pPrev = NULL;
		// TODO get from Allocator (preallocated)
		m_pFrame = new CVideoJitterBufferItem(pPacket);
	}

	~CVideoJitterBufferItemTimestamp()
	{
		if (m_pFrame)
			ClearItems();

	}

	CVideoJitterBufferItemTimestamp* Find(UINT timestamp)
	{
		ASSERT(m_pFrame->m_pRtpParsedPacket);

		if (timestamp == m_pFrame->m_pRtpParsedPacket->timestamp)
		{
			return this;
		}
		else if (timestamp > m_pFrame->m_pRtpParsedPacket->timestamp)
		{
			return (m_pNext ? m_pNext->Find(timestamp) : NULL);
		}

		// k�nnte passieren
		ASSERT(0);
		return NULL;
	}

	VOID Remove(CVideoJitterBufferItemTimestamp *pItem)
	{
		if (this != pItem)
		{
			ASSERT(m_pFrame->m_pRtpParsedPacket);

			if (m_pFrame->m_pRtpParsedPacket->timestamp > pItem->m_pFrame->m_pRtpParsedPacket->timestamp)
			{
				// Failure - element existiert nicht
				ASSERT(0);

				//return this;
			}
			else
			{
				if (m_pNext)
				{
					/*this->m_pNext = */ m_pNext->Remove(pItem);
				}
			}
		}
		else
		{
			if (m_pNext)
			{
				m_pNext->m_pPrev = this->m_pPrev;
			}

			if (m_pPrev)
			{
				m_pPrev->m_pNext = m_pNext;
			}

			m_pNext = NULL;
			m_pPrev = NULL;
		}
	}

	CVideoJitterBufferItemTimestamp* Insert(CVideoJitterBufferItemTimestamp *pItem)
	{
		// should throw
		if (!pItem) return this;
		ASSERT(pItem->m_pFrame);

		if (pItem->m_pFrame->m_pRtpParsedPacket->timestamp < m_pFrame->m_pRtpParsedPacket->timestamp)
		{
			pItem->m_pPrev = this->m_pPrev;
			pItem->m_pNext = this;
			this->m_pPrev = pItem;

			return pItem;
		}
		else
		{
			if (pItem->m_pFrame->m_pRtpParsedPacket->timestamp == this->m_pFrame->m_pRtpParsedPacket->timestamp)
			{
				ASSERT(0);
				return this;
			}
			else // if (pItem->m_pFrame->m_pRtpParsedPacket->timestamp > this->m_pFrame->m_pRtpParsedPacket->timestamp)
			{
				if (m_pNext)
				{
					m_pNext = m_pNext->Insert(pItem);
				}
				else
				{
					m_pNext = pItem;
					pItem->m_pPrev = this;
				}
				return this;
			}
		}
	}

	VOID InsertPacketToFrame(RtpParsedPacket *pPacket)
	{
		// TODO get From Allocator
		if (m_pFrame)
		{
			m_pFrame = m_pFrame->Insert(new CVideoJitterBufferItem(pPacket));
		}
		else
		{
			m_pFrame = new CVideoJitterBufferItem(pPacket);
		}
	}

	VOID ClearItems()
	{
		if (m_pFrame)
		{
			ASSERT(m_pFrame->m_pPrev == NULL);
			CVideoJitterBufferItem* pItemTemp = NULL;
			while (m_pFrame)
			{
				pItemTemp = m_pFrame->m_pNext;
				m_pFrame->Remove(m_pFrame);
				delete m_pFrame;
				m_pFrame = pItemTemp;
			}
		}
	}

	VOID DeletePrevious()
	{
		if (m_pPrev)
		{
			m_pPrev->DeletePrevious();
			m_pPrev->ClearItems();
			delete m_pPrev;
			m_pPrev = NULL;
		}
	}

	CVideoJitterBufferItem* DequeuePacket()
	{
		if (m_pFrame)
		{
			CVideoJitterBufferItem* pTemp = m_pFrame;
			m_pFrame = m_pFrame->m_pNext;
			if (m_pFrame) m_pFrame->m_pPrev = NULL;
			pTemp->m_pNext = NULL;
			pTemp->m_pPrev = NULL;

			return pTemp;
		}

		return NULL;
	}

	CVideoJitterBufferItemTimestamp* FindFirstWithSameOrNewerTs(UINT timestamp)
	{
		ASSERT(m_pFrame->m_pRtpParsedPacket);

		if (timestamp <= m_pFrame->m_pRtpParsedPacket->timestamp)
		{
			return this;
		}
		else // if (timestamp > m_pFrame->m_pRtpParsedPacket->timestamp)
		{
			return (m_pNext ? m_pNext->FindFirstWithSameOrNewerTs(timestamp) : this);
		}
	}

	UINT GetItemCount()
	{
		ASSERT(m_pFrame);

		CVideoJitterBufferItem *pItem = m_pFrame;
		UINT cItems = 0;
		do {
			cItems++;
			pItem = pItem->m_pNext;
		} while(pItem);

		return cItems;
	}

	CVideoJitterBufferItemTimestamp* Last()
	{
		return (m_pNext ? m_pNext->Last() : this);
	}

	VOID DebugPrint()
	{
		ATLTRACE2("Ich bin ein CVideoJitterBufferItemTimestamp, mein TimeStamp ist %d \r\n", m_pFrame->m_pRtpParsedPacket->timestamp);

		this->m_pFrame->DebugPrint();

		if (this->m_pNext) this->m_pNext->DebugPrint();

	}
};


#endif