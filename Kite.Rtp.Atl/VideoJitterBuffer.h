#pragma once

#include <atlcoll.h>
#include <MMSystem.h>

#include "IJitterBuffer.h"

#include "VideoJitterBufferItems.h"

class CVideoJitterBuffer
	: public IJitterBuffer
{
	CRITICAL_SECTION m_critSectMapFramesSynchronization;
	CRITICAL_SECTION m_critSectObjectLock;

	CVideoJitterBufferItemTimestamp *m_pTop;

	UINT m_uLowWaterMark;

	BOOL m_bMuted;

	UINT m_tFirstSampleAfterBufferingStarted;
	UINT m_tsFirstSampleRtpTimestampOffset;
	UINT m_uTimestampIncrementPerSecond;

	UINT m_tBufferDuration;

	UINT m_tsNewestTimestampQueued;
	
	UINT m_uTimePerFrameNanos;

	void StartBuffering();
public:
	CVideoJitterBuffer(void);
	~CVideoJitterBuffer(void);

	STDMETHOD(SetBufferParameter)(
		UINT uBufferDurationMilliseconds,
		UINT uTimestampIncrementPerSecond,
		UINT uTimePerFrameNanos);

	STDMETHOD(SetLatency)(UINT millisecs);
	STDMETHOD(GetLatency)(UINT *pMillisecs);
	STDMETHOD(SetMuted)(INT bMuted);
	STDMETHOD(GetMuted)(INT* pbMuted);

	STDMETHOD(EnqueuePacket)(RtpParsedPacket *pPacket);
	HRESULT DequeueDeliveryUnit(RtpParsedPacket ***pppPackets, UINT *pcPackets);

	STDMETHODIMP TimeoutDeliveryUnitsEarlierThan(UINT timestamp);
	STDMETHODIMP ClearBuffer();
	VOID DebugPrint();

	STDMETHODIMP DequeuePackets(RtpParsedPacket ***pppRtpParsedPackets, UINT *pcPackets);
	STDMETHODIMP ExpireOlderThanOrEqual(UINT uTimestamp);
	void RemoveEarlier(UINT uTimeStamp);
	void Remove(CVideoJitterBufferItemTimestamp* pItem);
	UINT Count();
};
