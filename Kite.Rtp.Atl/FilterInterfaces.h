#include "IRtpPayloadPacketizer.h"

#include "RtpBufferedListener.h"
// #include <strmif.h>

[export]
typedef struct _AMMediaType
    {
    GUID majortype;
    GUID subtype;
    BOOL bFixedSizeSamples;
    BOOL bTemporalCompression;
    ULONG lSampleSize;
    GUID formattype;
    IUnknown *pUnk;
    ULONG cbFormat;
    /* [size_is] */ BYTE *pbFormat;
    } 	AM_MEDIA_TYPE;



[
	object,
	uuid("D32EA7FB-59D2-4a6b-ACCF-E70A323004A3"),
	pointer_default(unique)
]
__interface IRtpListenerOutputPin_Export : IUnknown 
{
	HRESULT GetBufferPrefix(INT *pcbPrefix);
};

[
	object,
	uuid("D32EA7F5-59D2-4a6b-ACCF-E70A323004A3"),
	pointer_default(unique)
]
__interface IRtpBufferedListenerFilter_Export : IUnknown
{
	HRESULT SetNetworkParameter(
		LPWSTR szRemoteAddress, 
		USHORT uRemotePort, 
		LPWSTR szLocalInterface, 
		USHORT uLocalInterface,
		INT ttl);

	HRESULT SetMediaParameterDefaults(
		[in] BOOL bAduSpansMultiplePackets,
		BYTE payloadType,
		UINT uRtpTimeStampIncrementPerSecond,
		UINT uExpectedTimePerAduNanoseconds);

	HRESULT SetOutputMediaType( AM_MEDIA_TYPE *pMediaType);

	HRESULT SetRtpBandwidth( UINT uSessionBandwidth, BOOL bEnforce);

	HRESULT SetJitterBufferParameter(UINT ssrc, UINT uLatency);

	HRESULT SelectActiveSourceForOutputPin( UINT index, UINT ssrc) ;
	HRESULT AddOutputPin( /*out*/ INT *pIndex) ;
	HRESULT AddOutputPinForActiveSource( UINT ssrc, INT *pIndex) ;
	HRESULT RemoveOutputPin( UINT index) ;

	HRESULT RegisterEventHandler( IRtpBufferedListenerFilterEventConsumer *pEventConsumer) ;
	HRESULT RegisterEventHandlerEx( IRtpBufferedListenerFilterEventConsumerEx *pEventConsumerEx) ;

	HRESULT GetSubscribedSourcesCount(INT *pcSubscribed);
	HRESULT GetSubscribedSources(INT** pSubscribedSources, INT* pcSubscribedSources);
	HRESULT GetActiveSourcesCount(INT *pcActive);
	HRESULT GetActiveSources(INT** pActiveSources, INT* pcActiveSources);

	HRESULT SetAutoSubscribeActiveSources(BOOL bValue);
	HRESULT GetAutoSubscribeActiveSources(BOOL *pbValue);

	// 0809
	HRESULT SetRtpPayloadPacketizer(
		IRtpPayloadPacketizer *pPacketizer);

	HRESULT ReserveNetworkAddress(
		/*[in]*/ LPWSTR szRemoteAddress, 
		/*[in,out]*/ LPWSTR szLocalAddress,
		USHORT uLocalMinPort,
		USHORT uLocalMaxPort,
		LPWSTR szLocalOut, INT cchLocal, USHORT *puLocal);


	HRESULT GetNetworkParameter(
		LPWSTR szRemoteAddress, INT cchRemoteAddress, USHORT *puRemotePort, 
		LPWSTR szLocalInterface, INT cchLocalAddress, USHORT *puLocalPortBase, INT* pTtl);

	// 13092003
	HRESULT SetJitterBufferLatency(UINT ssrc, UINT uLatency);
	HRESULT GetJitterBufferLatency(UINT ssrc, UINT* puLatency);

	HRESULT GetRtcpAttributes(UINT ssrc, SdesItems *pSdesItems);
	HRESULT SetMuted(UINT ssrc, INT bMuted);
	HRESULT GetMuted(UINT ssrc, INT *pbIsMuted);

	// diese nur auf dem Filter implementieren
	HRESULT SetPinCount(INT pinCount);
	HRESULT GetPinCount(INT *pPinCount);
	HRESULT GetPinIndexForSource(UINT ssrc, INT *pIndex);
};

[
	object,
	uuid("D32EA7E5-59D2-4A6B-ACCF-E70A323004A3"),
	pointer_default(unique)
]
__interface IRtpBufferedListenerFilterSingleOutputPin_Export : IUnknown
{
	STDMETHOD(Configure)(THIS_ 
		UINT ssrc, 
		IRtpBufferedListener *pRtpBufferedListener,
		IPlayoutBuffer *pPlayoutBuffer,
		IRtpPayloadPacketizer *pPacketizer,
		LPGUID lpGuidMajorType,
		LPGUID lpGuidMinorType);

	STDMETHOD(SetOutputMediaType)(THIS_ AM_MEDIA_TYPE *pMediaType);

	STDMETHOD(SetJitterBufferParameter)(UINT uLatency);
	STDMETHOD(GetSubscribedSsrc)(THIS_ UINT *pSsrc);
};
