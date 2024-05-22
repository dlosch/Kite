#pragma once

#include "IJitterBuffer.h"

class CAudioJitterBuffer
	: public IJitterBuffer
{
	AudioJitterBufferItem* m_pTop;

	BOOL m_bMuted;

	UINT m_tFirstSampleAfterBufferingStarted;
	UINT m_tsFirstSampleRtpTimestampOffset;

	UINT m_uTimestampIncrementPerSecond;
	UINT m_uTimePerFrameNanos;
	//////////////////////////////////////////////////////////////////////////

	UINT m_tBufferDuration;
	/*__forceinline*/ void StartBuffering();

public:
	CAudioJitterBuffer(void);
	~CAudioJitterBuffer(void);

	// remove the first item from the list and return it
	RtpParsedPacket* Dequeue();
	
	// Insert Item to the list an possibly update the reference to the first item
	BOOL Insert(RtpParsedPacket* pItem);

	// Remove only pItem from the list, update references
	void Remove(AudioJitterBufferItem *pItem);

	// Removes all items carrying a ts earlier or equal than iTimeStamp and updates references
	void RemoveEarlierOrEqual(UINT uTimeStamp);

	// Removes all items carrying a ts earlier or equal than iTimeStamp and updates references
	void RemoveEarlier(UINT uTimeStamp);

	// Remove all items
	void Clear();

	// Count items (TODO iterate rather than recurse)
	UINT Count();

	void DebugPrint();

	// IJitterBuffer
	STDMETHODIMP EnqueuePacket(RtpParsedPacket *pPacket);
	STDMETHODIMP DequeuePackets(RtpParsedPacket ***pppRtpParsedPackets, UINT *pcPackets);
	STDMETHODIMP ExpireOlderThanOrEqual(UINT uTimestamp);
	STDMETHODIMP ClearBuffer(void);

	STDMETHODIMP SetBufferParameter(
		UINT uBufferDurationMilliseconds,
		UINT uTimestampIncrementPerSecond,
		UINT uTimePerFrameNanos);

	STDMETHOD(SetLatency)(UINT millisecs);
	STDMETHOD(GetLatency)(UINT *pMillisecs);
	STDMETHOD(SetMuted)(INT bMuted);
	STDMETHOD(GetMuted)(INT* pbMuted);
};
