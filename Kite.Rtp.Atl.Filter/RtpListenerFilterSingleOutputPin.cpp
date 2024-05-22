#include "StdAfx.h"
#include ".\rtplistenerfiltersingleoutputpin.h"

#define DEBUG_VIDEO	1
#define DEBUG_AUDIO	0

#include <dxerr9.h>
#pragma comment(lib, "dxerr9")

#include <crtdbg.h>

#include "RtpBufferedSourceStream.h"

CRtpListenerFilterSingleOutputPin::CRtpListenerFilterSingleOutputPin(LPUNKNOWN pUnk, HRESULT *phr)
	: CBaseFilter(
			  _T("Kite.Rtp.Atl.Filter.Listener.SinglePin"),
			  pUnk,
			  &m_critSectFilterLock ,
			  CLSID_RtpBufferedListenerFilter
			  )
			  , m_pOutputStream(NULL)
			  , m_pOutputMediaType(NULL)
			  , m_pRtpPlayoutBuffer(NULL)
{
	m_pOutputStream = new CRtpBufferedListenerSinglePinOutputStream(this, phr, L"Where Do You want to go today, dirtbag?");
	if (!m_pOutputStream)
	{
		(*phr) = E_OUTOFMEMORY;
	}
}

CRtpListenerFilterSingleOutputPin::~CRtpListenerFilterSingleOutputPin(void)
{
	SAFE_DELETE(m_pOutputStream);
}

CUnknown * WINAPI CRtpListenerFilterSingleOutputPin::CreateInstance(LPUNKNOWN pUnk, HRESULT *phr)
{
	CRtpListenerFilterSingleOutputPin* pInstance = new CRtpListenerFilterSingleOutputPin(pUnk, phr);

	if (pInstance == NULL)
	{
		(*phr) = E_OUTOFMEMORY;
		return NULL;
	}

	return pInstance;
}

STDMETHODIMP CRtpListenerFilterSingleOutputPin::NonDelegatingQueryInterface(REFIID riid, void **ppVoid)
{
	//if (IsEqualGUID(riid, IID_IRtpBufferedListenerFilter))
	//{
	//	return GetInterface((IRtpBufferedListenerFilter*)this, ppVoid);
	//}
	if (IsEqualGUID(riid, IID_IRtpBufferedListenerFilterSingleOutputPin))
	{
		return GetInterface((IRtpBufferedListenerFilterSingleOutputPin*)this, ppVoid);
	}
	
	return CBaseFilter::NonDelegatingQueryInterface(riid, ppVoid);
}

STDMETHODIMP_(ULONG) CRtpListenerFilterSingleOutputPin::NonDelegatingRelease(void)
{
	return CBaseFilter::NonDelegatingRelease();
}

//
// GetPin
//
// Return a non-addref'd pointer to pin n
// needed by CBaseFilter
CBasePin *CRtpListenerFilterSingleOutputPin::GetPin(int n) 
{
	CAutoLock lock(&m_critSectFilterLock);

	// n must be in the range 0..m_uPinCount-1
	// if m_uPinCount>n  && n>=0 it follows that m_uPinCount>0
	// which is what used to be checked (i.e. checking that we have a pin)
	if (n == 0)
	{
		return m_pOutputStream;
	}

	return NULL;
}

//
// GetPinCount
//
// Returns the number of pins this filter has
int CRtpListenerFilterSingleOutputPin::GetPinCount(void) 
{
	// CAutoLock lock(&m_critSectFilterLock); // sehr sinnvoll ;-)
	return 1;
}

STDMETHODIMP CRtpListenerFilterSingleOutputPin::GetState(
	DWORD dwMilliSecsTimeout,
	FILTER_STATE *pState)
{
	CheckPointer(pState, E_POINTER);
	(*pState) = m_State;

	// if (m_State == State_Stopped)
	_RPT2(_CRT_WARN, "CurrentState: %d / Paused? %d \r\n", m_State, (m_State == State_Paused));

	// If a filter cannot deliver data for some reason, 
	// it returns VFW_S_CANT_CUE. 
	// Live capture filters return this value while paused, 
	// because they do not deliver data in the paused state.

	return ((m_State == State_Paused) ? VFW_S_CANT_CUE : S_OK);
}

STDMETHODIMP_(ULONG) CRtpListenerFilterSingleOutputPin::GetMiscFlags(void)
{
	return AM_FILTER_MISC_FLAGS_IS_SOURCE;
}

//////////////////////////////////////////////////////////////////////////

STDMETHODIMP CRtpListenerFilterSingleOutputPin::Configure(
	UINT ssrc, 
	IRtpBufferedListener *pRtpBufferedListener,
	IPlayoutBuffer *pPlayoutBuffer,
	IRtpPayloadPacketizer *pPacketizer,
	LPGUID lpGuidMajorType,
	LPGUID lpGuidMinorType)
{
	CheckPointer(pPlayoutBuffer, E_POINTER);
	// ssrc is reserved in all parts of the lib and may not be used
	CheckPointer(ssrc, E_INVALIDARG);

	if (!pPacketizer)
	{
		CheckPointer(pPlayoutBuffer, E_POINTER);
		CheckPointer(pPlayoutBuffer, E_POINTER);
	}

	// Cleanup if needed
	//m_pRtpListener = NULL;
	//m_pRtpBufferedListener = NULL;
	m_pRtpPayloadPacketizer = NULL;
	SAFE_RELEASE(m_pRtpPlayoutBuffer);
	SAFE_DELETE(m_pOutputMediaType); // Calls FreeMediaType
	m_ssrcOfSelectedSource = 0;

	HRESULT hr = S_OK;
	// HRESULT hr = pRtpBufferedListener->QueryInterface(__uuidof(IRtpListener), (void**)&m_pRtpListener);

	//hr = AssignRtpBufferedListener(pRtpBufferedListener);
	//VALHR(hr);

	//m_pRtpBufferedListener = pRtpBufferedListener; // Calls Addref
	m_pRtpPayloadPacketizer = pPacketizer;
	m_pRtpPlayoutBuffer = pPlayoutBuffer;
	m_pRtpPlayoutBuffer->AddRef();

	m_ssrcOfSelectedSource = ssrc;

	////m_pOutputMediaType = new CMediaType(lpGuidMajorType);
	////m_pOutputMediaType->SetSubtype(lpGuidMinorType);

	return S_OK;
}

STDMETHODIMP CRtpListenerFilterSingleOutputPin::SetOutputMediaType(AM_MEDIA_TYPE *pMediaType)
{
	CheckPointer(pMediaType, E_POINTER);
	SAFE_DELETE(m_pOutputMediaType);

	HRESULT hr = S_OK;
	m_pOutputMediaType = new CMediaType((*pMediaType), &hr);

	return hr;
}

STDMETHODIMP CRtpListenerFilterSingleOutputPin::SetJitterBufferParameter(UINT uLatency)
{
	CheckPointer(m_pRtpPlayoutBuffer, E_UNEXPECTED);
	return m_pRtpPlayoutBuffer->SetLatency(uLatency);
}

// SSRC of zero indeicates taht this thing is not subscribed
STDMETHODIMP CRtpListenerFilterSingleOutputPin::GetSubscribedSsrc(UINT *pSsrc)
{
	CheckPointer(pSsrc, E_POINTER);
	(*pSsrc) = m_ssrcOfSelectedSource;
	return S_OK;
}

STDMETHODIMP CRtpListenerFilterSingleOutputPin::AssignRtpBufferedListener(IRtpBufferedListener *pRtpBufferedListener)
{
	CheckPointer(pRtpBufferedListener, E_POINTER);

	HRESULT hr = S_OK;
	m_pRtpBufferedListener = pRtpBufferedListener;

	hr = m_pRtpBufferedListener->QueryInterface(__uuidof(IRtpListener), (void**)&m_pRtpListener);
	VALHR(hr);
	hr = m_pRtpBufferedListener->QueryInterface(__uuidof(IRtpListenerConfiguration), (void**)&m_pRtpListenerConfiguration);
	VALHR(hr);
	hr = m_pRtpBufferedListener->QueryInterface(__uuidof(IRtpListenerConfigurationOut), (void**)&m_pRtpListenerConfigurationOut);
	VALHR(hr);
	hr = m_pRtpBufferedListener->QueryInterface(__uuidof(IRtpListenerControl), (void**)&m_pRtpListenerControl);
	VALHR(hr);
	hr = m_pRtpBufferedListener->QueryInterface(__uuidof(IRtpListenerCallbackRegistration), (void**)&m_pRtpListenerCallbackRegistration);
	VALHR(hr);
	hr = m_pRtpBufferedListener->QueryInterface(__uuidof(IRtpBufferedListenerData), (void**)&m_pRtpListenerData);
	VALHR(hr);
	
	return hr;
}