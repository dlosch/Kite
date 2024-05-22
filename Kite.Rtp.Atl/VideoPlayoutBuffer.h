// VideoPlayoutBuffer.h : Declaration of the CVideoPlayoutBuffer

#pragma once
#include "resource.h"       // main symbols

#include "VideoJitterBufferItems.h"

// CVideoPlayoutBuffer
[
	coclass,
	threading("both"),
	aggregatable("never"),
	vi_progid("KiteRtpAtl.VideoPlayoutBuffer"),
	progid("KiteRtpAtl.VideoPlayoutBuffer.1"),
	version(1.0),
	uuid("E493FD51-97B1-4126-829E-24F63A7FD50D"),
	helpstring("VideoPlayoutBuffer Class")
]
class ATL_NO_VTABLE CVideoPlayoutBuffer : 
	public IPlayoutBuffer
	, public IDisposable
{
	BOOL m_bDisposed;
	CRITICAL_SECTION m_critSectObjectLock;
	CRITICAL_SECTION m_critSectMapFramesSynchronization;

	BYTE m_payloadType;

	CRITICAL_SECTION m_critSectManualResetEvent;
	BOOL m_bIsEventSignalled;
	HANDLE m_hManualResetEvent;

	void UpdateEventState();

public:
	CVideoPlayoutBuffer();
	DECLARE_PROTECT_FINAL_CONSTRUCT()
	HRESULT FinalConstruct();
	void FinalRelease();

	STDMETHOD(get_Disposed)(BOOL* pVal);
	STDMETHOD(Dispose)(void);

	CVideoJitterBufferItemTimestamp *m_pTop;

	UINT m_uLowWaterMark;

	BOOL m_bMuted;

	UINT m_tFirstSampleAfterBufferingStarted;
	UINT m_tsFirstSampleRtpTimestampOffset;
	UINT m_uTimestampIncrementPerSecond;

	UINT m_tBufferDuration;

	UINT m_tsNewestTimestampQueued;

	UINT m_uTimePerFrameNanos;

	UINT CountSeqNums(CVideoJitterBufferItemTimestamp *pTimestamp);
	STDMETHOD(InsertPacketToTsItem)(RtpParsedPacket *pPacket, CVideoJitterBufferItemTimestamp *pTimestamp);
	STDMETHOD(Insert)(RtpParsedPacket *pPacket);
	void StartBuffering();

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
	void RemoveTop(); //CVideoJitterBufferItemTimestamp* pItem);
	UINT Count();

	STDMETHOD(put_PayloadType)(BYTE payloadType);
	STDMETHOD(get_PayloadType)(BYTE *pPayloadType);

	STDMETHOD(get_DueTime)(UINT* pDueTimeMilliseconds);
	STDMETHOD(get_EventHandle)(LONG_PTR** pEventHandle);

	STDMETHOD(get_BufferDurationMilliseconds)(UINT* pVal);
	STDMETHOD(put_BufferDurationMilliseconds)(UINT newVal);

	STDMETHOD(get_RtpTimestampIncrementPerSecond)(UINT* pVal);
	STDMETHOD(put_RtpTimestampIncrementPerSecond)(UINT newVal);

	STDMETHOD(get_TimePerSampleNanos)(UINT* pVal);
	STDMETHOD(put_TimePerSampleNanos)(UINT newVal);
};

