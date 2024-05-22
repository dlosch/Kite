// Test.h : Declaration of the CTest

#pragma once
#include "resource.h"       // main symbols

#include "RtpListenerEventCallbacks.h"
#include "IRtpPayloadPacketizer.h"
// CTest
#define FILTER_EXPORTS	1
#if FILTER_EXPORTS
#include "FilterInterfaces.h"
#endif
#include "RtpRenderer.h"
//struct AM_MEDIA_TYPE;
//class IRtpBufferedListener;
[
	coclass,
	threading("both"),
	aggregatable("never"),
	vi_progid("KiteRtpAtl.Test"),
	progid("KiteRtpAtl.Test.1"),
	version(1.0),
	uuid("07136823-BDF2-4A41-B965-CCE9E450F41F"),
	helpstring("Test Class")
	// visible in Typelib
	, hidden
	, noncreatable
	, default(IRtpBufferedListenerEventConsumer)
]
class ATL_NO_VTABLE CTest : 
	// Interfaces aro only exporteed to the typelib if referenced somewhere (method, cocolass)
	public IRtpBufferedListenerFilterEventConsumerEx,
	public IRtpBufferedListenerFilterEventConsumer,
	public IRtpBufferedListenerEventConsumer
	, public IRtpPayloadPacketizer


	, public IRtpBufferedListenerFilter_Export
	, public IRtpListenerOutputPin_Export
	//, public IRtpRendererFilterEx_Export
	, public IRtpBufferedListenerFilterSingleOutputPin_Export,
	public IRtpRendererFilterConfiguration_Export

{
public:
	CTest()
	{
	}


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease() 
	{
	}

public:
	STDMETHODIMP ActiveSourceAdded(UINT ssrc) { return E_NOTIMPL; } 
	STDMETHODIMP ActiveSourceRemoved(UINT ssrc) { return E_NOTIMPL; } 
	STDMETHODIMP SdesInformationForSource(UINT ssrc, const SdesItems *pSdesItems) { return E_NOTIMPL; } 

	// PayloadPacketizer
	STDMETHODIMP get_MaxBufferSize(UINT *pcbMtu) { return E_NOTIMPL; } 
	STDMETHODIMP put_MaxBufferSize(UINT cbMtu) { return E_NOTIMPL; } 
	STDMETHODIMP get_GuidCount(UINT *pcGuids) {return E_NOTIMPL;}
	STDMETHODIMP GetGuids(MyRegPinTypes* pRegPinTypes) {return E_NOTIMPL;}

	STDMETHODIMP Packetize(
		BYTE* pBuffer, UINT cbBuffer, BYTE*** ppBuffer, 
		UINT **ppcbBuffers, UINT *pcBuffers) { return E_NOTIMPL; } 
		STDMETHODIMP Depacketize(BYTE** pBuffers, UINT *pcbBuffers, UINT *pSeqNums, UINT cBuffers, 
			BYTE* pBuffer, UINT *pcbBuffer, UINT *pcbSkipped) { return E_NOTIMPL; } 

			// IRtpRendererFilter Methods
public:
	STDMETHOD(SetNetworkParameter)(LPWSTR  szRemoteAddress, USHORT  uRemotePort, LPWSTR  szLocalInterface, USHORT  uLocalPort, INT  ttl, LPWSTR  szCname)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}
	STDMETHOD(SetRtpParameter)(BYTE  payloadType)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}
	STDMETHOD(SetRtpBandwidth)(UINT  uSessionBandwidth, BOOL  bEnforce)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}
	STDMETHOD(SetRtcpParameter)(BSTR  lpcwstrName, BSTR  lpcwstrEMail, BSTR  lpcwstrPhone, BSTR  lpcwstrLoc, BSTR  lpcwstrTool, BSTR  lpcwstrNote)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}
	STDMETHOD(SetProtocolMediaParameter)(UINT  uTimePerAduNanos, UINT  uRtpTimestampIncrementPerFrame)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}
	STDMETHOD(SetRtpPayloadPacketizer)(IRtpPayloadPacketizer * pPacketizer)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}
	STDMETHOD(ReserveNetworkAddress)(LPWSTR  szRemoteAddress, LPWSTR  szLocalAddress, USHORT  uMinLocalPort, USHORT  uMaxLocalPort, LPWSTR  szLocalOut, INT  cchLocal, USHORT * puLocal)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}
	STDMETHOD(GetNetworkParameter)(LPWSTR  szRemoteAddress, INT  cchRemoteAddress, USHORT * puRemotePort, LPWSTR  szLocalInterface, INT  cchLocalAddress, USHORT * puLocalPortBase, INT * pTtl)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}

	// IRtpBufferedListenerFilter Methods
public:
	STDMETHOD(SetNetworkParamete)(LPWSTR  szRemoteAddress, USHORT  uRemotePort, LPWSTR  szLocalInterface, USHORT  uLocalInterface, INT  ttl)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}
	STDMETHOD(SetMediaParameterDefaults)(BOOL  bAduSpansMultiplePackets, BYTE  payloadType, UINT  uRtpTimeStampIncrementPerSecond, UINT  uExpectedTimePerAduNanoseconds)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}
	STDMETHOD(SetOutputMediaType)(AM_MEDIA_TYPE * pMediaType)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}
	STDMETHOD(SetJitterBufferParameter)(UINT  ssrc, UINT  uLatency)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}
	STDMETHOD(SelectActiveSourceForOutputPin)(UINT  index, UINT  ssrc)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}
	STDMETHOD(AddOutputPin)(INT * pIndex)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}
	STDMETHOD(AddOutputPinForActiveSource)(UINT  ssrc, INT * pIndex)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}
	STDMETHOD(RemoveOutputPin)(UINT  index)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}
	STDMETHOD(RegisterEventHandler)(IRtpBufferedListenerFilterEventConsumer * pEventConsumer)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}
	STDMETHOD(RegisterEventHandlerEx)(IRtpBufferedListenerFilterEventConsumerEx * pEventConsumerEx)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}
	STDMETHOD(GetSubscribedSourcesCount)(INT * pcSubscribed)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}
	STDMETHOD(GetSubscribedSources)(INT ** pSubscribedSources, INT * pcSubscribedSources)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}
	STDMETHOD(GetActiveSourcesCount)(INT * pcActive)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}
	STDMETHOD(GetActiveSources)(INT ** pActiveSources, INT * pcActiveSources)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}
	STDMETHOD(SetAutoSubscribeActiveSources)(BOOL  bValue)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}
	STDMETHOD(GetAutoSubscribeActiveSources)(BOOL * pbValue)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}
	STDMETHOD(GetActiveSourcesSafeArray)(SAFEARRAY ** ppSafeArray)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}
	STDMETHOD(SetJitterBufferLatency)(UINT  ssrc, UINT  uLatency)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}
	STDMETHOD(GetJitterBufferLatency)(UINT  ssrc, UINT * puLatency)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}
	STDMETHOD(GetRtcpAttributes)(UINT  ssrc, SdesItems * pSdesItems)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}
	STDMETHOD(SetMuted)(UINT  ssrc, INT  bMuted)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}
	STDMETHOD(GetMuted)(UINT  ssrc, INT * pbIsMuted)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}
	STDMETHOD(SetPinCount)(INT  pinCount)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}
	STDMETHOD(GetPinCount)(INT * pPinCount)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}
	STDMETHOD(GetPinIndexForSource)(UINT  ssrc, INT * pIndex)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}

	// IRtpListenerOutputPin Methods
public:
	STDMETHOD(GetBufferPrefix)(INT * pcbPrefix)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}

	// IRtpRendererFilterEx Methods
public:
	STDMETHOD(GetPerformanceCounterPrefix)(LPBSTR  bstrPerfCounterPrefix)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}
	// Duplicate Method : HRESULT GetActiveSourcesCount(INT *)
	// Duplicate Method : HRESULT GetActiveSources(INT **, INT *)

	// IRtpBufferedListenerFilterSingleOutputPin Methods
public:
	STDMETHOD(Configure)(UINT  ssrc, IRtpBufferedListener * pRtpBufferedListener, IPlayoutBuffer * pPlayoutBuffer, IRtpPayloadPacketizer * pPacketizer, LPGUID  lpGuidMajorType, LPGUID  lpGuidMinorType)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}
	STDMETHOD(SetJitterBufferParameter)(UINT  uLatency)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}
	STDMETHOD(GetSubscribedSsrc)(UINT * pSsrc)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}

	// IRtpRendererFilterConfiguration_Export Methods
public:
	STDMETHOD(SetRtpRenderer)(IRtpRenderer * pRenderer)
	{
		// Add your function implementation here.
		return E_NOTIMPL;
	}
};

