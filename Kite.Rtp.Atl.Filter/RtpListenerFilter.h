#pragma once

#include "Rtpuuids.h"
#include <MMSystem.h>
#include "IRtpListenerFilter.h"
// TODO standardm��ig baue ich erstmal einen SourceStream, 
// die Applikation kann dann �ber die Events die SSRCs umschalten

#include "RtpBufferedOutputStream.h"

#include "RtpBufferedSourceStreamHeader.h"

//////////////////////////////////////////////////////////////////////////

// In the constructor, create one or more output pins derived from CSourceStream. 
// The pins automatically add themselves to the filter in their constructor methods, 
// and remove themselves in their destructor methods. 

// Pin hinzuf�gern via CSource:::AddPin, entfrenen via ::::RemovePin
class CRtpBufferedListenerFilter 
	//: public CSource
	: public CBaseFilter
	

	//////////////////////////////////////////////////////////////////////////
	, public IRtpListenerEventConsumer
	, public IRtpBufferedListenerFilter
	// Dshow
	, public IAMFilterMiscFlags
{
public:

#ifdef SOURCESTREAM
	friend class CRtpBufferedSourceStream;
#endif
	friend class CRtpBufferedOutputStream;

	enum RTPLISTENERFILTERSTATE
	{
		RTPLISTENERFILTERSTATE_UNINITIALIZED,
		RTPLISTENERFILTERSTATE_NETWORK_CONFIGURED,
		RTPLISTENERFILTERSTATE_MEDIA_CONFIGURED,
		RTPLISTENERFILTERSTATE_RUNNING
	};

	CCritSec m_critSectFilterLock ;   //  filter lock

	// Holzhammer - d�mmer kann man sich nichts anstellen
	BOOL m_bDisposing;

	// Die 

	RTPLISTENERFILTERSTATE m_state;
	IRtpListener* m_pRtpListener;
	IRtpBufferedListener* m_pRtpBufferedListener;

	IRtpPayloadPacketizer *m_pRtpPayloadPacketizer;

	// Event Handling for Application
	IRtpBufferedListenerFilterEventConsumer* m_pEventConsumer;
	IRtpBufferedListenerFilterEventConsumerEx* m_pEventConsumerEx;

	UINT m_uPinCount;
	UINT m_uTimePerFrame;
	UINT m_uRtpBitrate;

	//GUID m_guidMajorType;
	//GUID m_guidSubType;
	CMediaType *m_pOutputMediaType;

	// TODO durch TimePerFrame(Nanos) ersetzen
	//UINT m_uFramesPerSecondCalculated;

	CRtpBufferedListenerFilter(LPUNKNOWN pUnk, HRESULT *phr);
	~CRtpBufferedListenerFilter(void);

	//////////////////////////////////////////////////////////////////////////
	// COM Stuff
	static CUnknown * WINAPI CreateInstance(LPUNKNOWN pUnk, HRESULT *phr);
	STDMETHODIMP NonDelegatingQueryInterface(REFIID, void **);
	STDMETHODIMP_(ULONG) NonDelegatingRelease(void);
	DECLARE_IUNKNOWN;

	// Methods stolen from CSource (defined for CSourceStreams)
	//
	//  Add a new pin
	//
	HRESULT AddPin(CRtpBufferedOutputStream *pPin);
	//
	//  Remove a pin - pStream is NOT deleted
	//
	HRESULT RemovePin(CRtpBufferedOutputStream *pStream);
	CRtpBufferedOutputStream** m_paBufferedStreams;
	INT FindPinNumber(IPin *iPin);
	CBasePin* GetPin(int n);
	int GetPinCount(void);

	// LIve Sources
	STDMETHOD(GetState)(
		DWORD dwMilliSecsTimeout,
		FILTER_STATE *State
		);

	//////////////////////////////////////////////////////////////////////////
	// IRtpListenerEventConsumer
	STDMETHOD(ActiveSourceAdded)(UINT ssrc);
	STDMETHOD(ActiveSourceRemoved)(UINT ssrc);
	STDMETHOD(ActiveSourceChanged)(UINT ssrc, INT type);

	// IRtpBufferedListenerFilter
	STDMETHOD(SetNetworkParameter)(
		LPWSTR szRemoteAddress, 
		USHORT uRemotePort, 
		LPWSTR szLocalInterface, 
		USHORT uLocalPort,
		INT ttl);

	STDMETHOD(GetNetworkParameter)(
		LPWSTR szRemoteAddress, INT cchRemoteAddress, USHORT *puRemotePort, 
		LPWSTR szLocalInterface, INT cchLocalAddress, USHORT *puLocalPortBase, INT* pTtl);

	//STDMETHOD(SetProtocolMediaParameter)(
	//	// mediaType FourCC (Requires Mapping FourCC-->Filter)
	//	UINT uMediaFourCC, 
	//	// nanos per Frame duration
	//	UINT uTimePerFrame, 
	//	UINT uTimestampIncrementPerFrame);
	STDMETHOD(SetMediaParameterDefaults)(
		BOOL bAduSpansMultiplePackets,
		BYTE payloadType,
		UINT uRtpTimeStampIncrementPerSecond,
		UINT uExpectedTimePerAduNanoseconds);

	//STDMETHOD(SetMediaTypeGuids)(GUID major, GUID sub);
	STDMETHOD(SetOutputMediaType)(AM_MEDIA_TYPE *pMediaType);

	STDMETHOD(SetRtpBandwidth)(UINT uSessionBandwidth, BOOL bEnforce);
	STDMETHOD(SetJitterBufferParameter)(UINT ssrc, UINT uLatency);

	STDMETHOD(SelectActiveSourceForOutputPin)(UINT index, UINT ssrc);
	STDMETHOD(AddOutputPin)(/*out*/ INT *pIndex);
	STDMETHOD(AddOutputPinForActiveSource)(UINT ssrc, INT *pIndex);
	STDMETHOD(RemoveOutputPin)(UINT index);

	STDMETHOD(RegisterEventHandler)(IRtpBufferedListenerFilterEventConsumer *pEventConsumer);
	STDMETHOD(RegisterEventHandlerEx)(IRtpBufferedListenerFilterEventConsumerEx *pEventConsumerEx);

	// 
	//STDMETHOD(Configure)(UINT fps);

	// IRtpBufferedListener durchschleifen
	STDMETHOD(GetSubscribedSourcesCount)(INT *pcSubscribed);
	STDMETHOD(GetSubscribedSources)(INT** pSubscribedSources, INT* pcSubscribedSources);
	STDMETHOD(GetActiveSourcesCount)(INT *pcActive);
	STDMETHOD(GetActiveSources)(INT** pActiveSources, INT* pcActiveSources);
	STDMETHOD(GetActiveSourcesSafeArray)(SAFEARRAY** ppSafeArray);

	// 0809
	STDMETHOD(SetRtpPayloadPacketizer)(IRtpPayloadPacketizer *pPacketizer);

	STDMETHOD(ReserveNetworkAddress)(
		/*[in]*/ LPWSTR szRemoteAddress, 
		/*[in,out]*/ LPWSTR szLocalAddress,
		USHORT uLocalMinPort,
		USHORT uLocalMaxPort,
		LPWSTR szLocalOut, INT cchLocal, USHORT *puLocal);

	BOOL m_bAutoSubscribeActiveSources;
	STDMETHOD(SetAutoSubscribeActiveSources)(BOOL bValue);
	STDMETHOD(GetAutoSubscribeActiveSources)(BOOL *pbValue);

	// CBasePin
	STDMETHOD(Run)(REFERENCE_TIME tStart);
	STDMETHOD(Pause)(void);

	STDMETHOD(FindPin)(LPCWSTR Id, IPin **ppPin);

	// IAMFilterMiscFlags
	STDMETHOD_(ULONG, GetMiscFlags)(void); 

	// 13092003
	STDMETHOD(SetJitterBufferLatency)(UINT ssrc, UINT uLatency);
	STDMETHOD(GetJitterBufferLatency)(UINT ssrc, UINT* puLatency);

	STDMETHOD(GetRtcpAttributes)(UINT ssrc, SdesItems *pSdesItems);
	STDMETHOD(SetMuted)(UINT ssrc, INT bMuted);
	STDMETHOD(GetMuted)(UINT ssrc, INT *pbIsMuted);

	// diese nur auf dem Filter implementieren
	STDMETHOD(SetPinCount)(INT pinCount);
	STDMETHOD(GetPinCount)(INT *pPinCount);
	STDMETHOD(GetPinIndexForSource)(UINT ssrc, INT *pIndex);
};
