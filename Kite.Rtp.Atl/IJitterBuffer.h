#ifndef IJITTERBUFFER_H
#define IJITTERBUFFER_H

interface IJitterBuffer
{
	STDMETHOD(EnqueuePacket)(RtpParsedPacket *pPacket) PURE;
	STDMETHOD(DequeuePackets)(RtpParsedPacket ***pppRtpParsedPackets, UINT *pcPackets) PURE;
	STDMETHOD(ExpireOlderThanOrEqual)(UINT uTimestamp) PURE;
	STDMETHOD(ClearBuffer)() PURE;

	STDMETHOD(SetBufferParameter)(
		UINT uBufferDurationMilliseconds,
		UINT uTimestampIncrementPerSecond,
		UINT uTimePerFrameNanos) PURE;

	STDMETHOD(SetLatency)
		(UINT uLatency) PURE;

	STDMETHOD(GetLatency)
		(UINT *puLatency) PURE;

	STDMETHOD(SetMuted)
		(BOOL bMuted) PURE;

	STDMETHOD(GetMuted)
		(BOOL *pbMuted) PURE;
};

#endif