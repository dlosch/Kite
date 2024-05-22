#ifndef IPLAYOUTBUFFER_H
#define IPLAYOUTBUFFER_H

#pragma once

#ifndef E_DISPOSED
#	define E_DISPOSED	MAKE_HRESULT(1, FACILITY_ITF, 0xFF00) 
#endif
#define CheckDisposed if(m_bDisposed) { return E_DISPOSED; }

struct AudioJitterBufferItem 
{
	AudioJitterBufferItem(RtpParsedPacket *pPacket);
	~AudioJitterBufferItem();

	RtpParsedPacket* GetAndRemovePacket();

	RtpParsedPacket* m_pPacket;
	AudioJitterBufferItem* m_pLeft;
	AudioJitterBufferItem* m_pRight;
};


// IPlayoutBuffer
[
	object,
	uuid("53F0C4D4-9926-4F1E-B0FF-47EAF6AA1F5A"),
	helpstring("IVideoPlayoutBuffer Interface"),
	pointer_default(unique)
]
__interface IPlayoutBuffer : IUnknown
{
	HRESULT EnqueuePacket(RtpParsedPacket *pPacket);
	HRESULT DequeuePackets(RtpParsedPacket ***pppRtpParsedPackets, UINT *pcPackets);
	HRESULT ExpireOlderThanOrEqual(UINT uTimestamp);
	HRESULT ClearBuffer();

	HRESULT SetBufferParameter(
		UINT uBufferDurationMilliseconds,
		UINT uTimestampIncrementPerSecond,
		UINT uTimePerFrameNanos);

	HRESULT SetLatency(UINT uLatency);

	HRESULT GetLatency(UINT *puLatency);

	HRESULT SetMuted(BOOL bMuted);

	HRESULT GetMuted(BOOL *pbMuted);

	[propget, helpstring("property PayloadType")] HRESULT PayloadType([out, retval] BYTE* pVal);
	[propput, helpstring("property PayloadType")] HRESULT PayloadType([in] BYTE newVal);

	[propget] HRESULT DueTime([out, retval] UINT* pDueTimeMilliseconds);
	[propget] HRESULT EventHandle([out, retval] LONG_PTR** pEventHandle);

	[propget] HRESULT BufferDurationMilliseconds([out, retval] UINT* pVal);
	[propput] HRESULT BufferDurationMilliseconds([in] UINT newVal);

	[propget] HRESULT RtpTimestampIncrementPerSecond([out, retval] UINT* pVal);
	[propput] HRESULT RtpTimestampIncrementPerSecond([in] UINT newVal);

	[propget] HRESULT TimePerSampleNanos([out, retval] UINT* pVal);
	[propput] HRESULT TimePerSampleNanos([in] UINT newVal);

};

// IVideoPlayoutBuffer
[
	object,
	uuid("53F0C4D5-9926-4F1E-B0FF-47EAF6AA1F5A"),
	helpstring("IVideoPlayoutBuffer Interface"),
	pointer_default(unique)
]
__interface IDisposable : IUnknown
{
	[propget, helpstring("property Disposed")] HRESULT Disposed([out, retval] BOOL* pVal);
	[helpstring("method Dispose")] HRESULT Dispose(void);
};

#endif
