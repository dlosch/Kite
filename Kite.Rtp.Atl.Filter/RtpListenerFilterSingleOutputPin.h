#pragma once

#include "Rtpuuids.h"
#include <MMSystem.h>
#include "IRtpListenerFilter.h"
// TODO standardmäßig baue ich erstmal einen SourceStream, 
// die Applikation kann dann über die Events die SSRCs umschalten

//#include "RtpBufferedOutputStream.h"
#include "RtpBufferedListenerSinglePinOutputStream.h"

#if !EXTERNAL_INTERFACES
DECLARE_INTERFACE_(IRtpBufferedListenerFilterSingleOutputPin, IUnknown) 
{
	STDMETHOD(Configure)(THIS_ 
		UINT ssrc, 
		IRtpBufferedListener *pRtpBufferedListener,
		IPlayoutBuffer *pPlayoutBuffer,
		IRtpPayloadPacketizer *pPacketizer,
		LPGUID lpGuidMajorType,
		LPGUID lpGuidMinorType);

	//STDMETHOD(SetRtpListener)(THIS_ IRtpBufferedListener *pRtpBufferedListener);
	//STDMETHOD(SetRtpPayloadPacketizer)(THIS_ IRtpPayloadPacketizer *pPacketizer);
	STDMETHOD(SetOutputMediaType)(THIS_ AM_MEDIA_TYPE *pMediaType);
	//STDMETHOD(SetMediaParameter)(
	//	BOOL bAduSpansMultiplePackets,
	//	BYTE payloadType,
	//	UINT uRtpTimeStampIncrementPerSecond,
	//	UINT uExpectedTimePerAduNanoseconds);
	
	STDMETHOD(SetJitterBufferParameter)(UINT uLatency);
	STDMETHOD(GetSubscribedSsrc)(THIS_ UINT *pSsrc);
};
#endif

class CRtpListenerFilterSingleOutputPin
	: public CBaseFilter
	, public IAMFilterMiscFlags
	, public IRtpBufferedListenerFilterSingleOutputPin
{
public:
	friend class CRtpBufferedOutputStream;

	CCritSec m_critSectFilterLock ;   //  filter lock

	CRtpBufferedListenerSinglePinOutputStream *m_pOutputStream;

	QzCComPtr<IRtpListener> m_pRtpListener;
	QzCComPtr<IRtpBufferedListener> m_pRtpBufferedListener;
	QzCComPtr<IRtpListenerConfiguration> m_pRtpListenerConfiguration;
	QzCComPtr<IRtpListenerConfigurationOut> m_pRtpListenerConfigurationOut;
	QzCComPtr<IRtpListenerControl> m_pRtpListenerControl;
	QzCComPtr<IRtpListenerCallbackRegistration> m_pRtpListenerCallbackRegistration;
	QzCComPtr<IRtpBufferedListenerData> m_pRtpListenerData;
	STDMETHOD(AssignRtpBufferedListener)(IRtpBufferedListener *pRtpBufferedListener);

	QzCComPtr<IRtpPayloadPacketizer> m_pRtpPayloadPacketizer;
	IPlayoutBuffer *m_pRtpPlayoutBuffer;

	UINT m_ssrcOfSelectedSource;
	CMediaType *m_pOutputMediaType;

	CRtpListenerFilterSingleOutputPin(LPUNKNOWN pUnk, HRESULT *phr);
	~CRtpListenerFilterSingleOutputPin(void);

	//////////////////////////////////////////////////////////////////////////
	// COM Stuff
	static CUnknown * WINAPI CreateInstance(LPUNKNOWN pUnk, HRESULT *phr);
	STDMETHODIMP NonDelegatingQueryInterface(REFIID, void **);
	STDMETHODIMP_(ULONG) NonDelegatingRelease(void);
	DECLARE_IUNKNOWN;

	CBasePin* GetPin(int n);
	int GetPinCount(void);

	// live sources
	STDMETHOD(GetState)(
		DWORD dwMilliSecsTimeout,
		FILTER_STATE *State
		);

	// CBasePin
	//STDMETHOD(Run)(REFERENCE_TIME tStart);
	//STDMETHOD(Pause)(void);

	// IAMFilterMiscFlags
	STDMETHOD_(ULONG, GetMiscFlags)(void); 

	//////////////////////////////////////////////////////////////////////////
	STDMETHOD(Configure)(THIS_ 
		UINT ssrc, 
		IRtpBufferedListener *pRtpBufferedListener,
		IPlayoutBuffer *pPlayoutBuffer,
		IRtpPayloadPacketizer *pPacketizer,
		LPGUID lpGuidMajorType,
		LPGUID lpGuidMinorType);

	STDMETHOD(SetOutputMediaType)(AM_MEDIA_TYPE *pMediaType);

	STDMETHOD(SetJitterBufferParameter)(UINT uLatency);

	STDMETHOD(GetSubscribedSsrc)(THIS_ UINT *pSsrc);
};
