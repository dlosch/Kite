#include "StdAfx.h"

#ifdef RTPLISTENERFILTER

#include "RtpListenerFilter.h"

#define DEBUG_VIDEO	1
#define DEBUG_AUDIO	0

#include <dxerr9.h>
#pragma comment(lib, "dxerr9")

#include <crtdbg.h>

#include "RtpBufferedSourceStream.h"

CRtpBufferedListenerFilter::CRtpBufferedListenerFilter(LPUNKNOWN pUnk, HRESULT *phr)

	: CBaseFilter(
				_T("Kite.Rtp.Atl.Filter.Listener"),
				pUnk,
				&m_critSectFilterLock ,
				CLSID_RtpBufferedListenerFilter
				)

		, m_paBufferedStreams(NULL)
		, m_pRtpListener(NULL)
		, m_pRtpBufferedListener(NULL)

		, m_state(RTPLISTENERFILTERSTATE_UNINITIALIZED)
		, m_uTimePerFrame(1000 * 10000 / 10) // ~15 fps
		, m_uRtpBitrate(128000)

		, m_pEventConsumer(NULL)
		, m_pEventConsumerEx(NULL)

		, m_uPinCount(0)
		, m_bAutoSubscribeActiveSources(FALSE)

		, m_pOutputMediaType(NULL)

		, m_pRtpPayloadPacketizer(NULL)
		, m_bDisposing(FALSE)
{
	HRESULT hr = S_OK;
	
	hr = CoCreateInstance(__uuidof(CRtpBufferedListener), NULL, CLSCTX_INPROC, __uuidof(IRtpListener), (void**)&m_pRtpListener);
	ASSERT(SUCCEEDED(hr));
	ASSERT(m_pRtpListener);

	if (FAILED(hr))
		*phr = hr;


	if (m_pRtpListener)
	{
		m_pRtpListener->QueryInterface(__uuidof(IRtpBufferedListener), (void**)&m_pRtpBufferedListener);
		ASSERT(m_pRtpBufferedListener);

		hr = m_pRtpListener->RegisterCallback((IRtpListenerEventConsumer*)this);
		if (FAILED(hr))
			*phr = hr;

	}
#if SOURCESTREAM
	// Create One default Pin
	// CRtpBufferedSourceStream(CRtpBufferedListenerFilter *pParentFilter, LPWSTR szPinName, HRESULT *phr);
	CRtpBufferedSourceStream *pRtpSourceStreamDefaultOutputPin = new CRtpBufferedSourceStream(this, L"Default Output Pin", phr);
	if (!pRtpSourceStreamDefaultOutputPin)
	{
		*phr = E_OUTOFMEMORY;
	}
#endif

}

CRtpBufferedListenerFilter::~CRtpBufferedListenerFilter(void)
{
	SAFE_RELEASE(m_pRtpPayloadPacketizer);

	while (m_uPinCount > 0) 
	{
		// deleting the pins causes them to be removed from the array...
		delete m_paBufferedStreams[--m_uPinCount];
	}

	SAFE_DELETE_ARRAY(m_paBufferedStreams);
	ASSERT(m_paBufferedStreams == NULL);
}

CUnknown * WINAPI CRtpBufferedListenerFilter::CreateInstance(LPUNKNOWN pUnk, HRESULT *phr)
{
	CRtpBufferedListenerFilter* pInstance = new CRtpBufferedListenerFilter(pUnk, phr);

	if (pInstance == NULL)
	{
		(*phr) = E_OUTOFMEMORY;
		return NULL;
	}

	return pInstance;
}

STDMETHODIMP CRtpBufferedListenerFilter::NonDelegatingQueryInterface(REFIID riid, void **ppVoid)
{
	if (IsEqualGUID(riid, IID_IRtpBufferedListenerFilter))
	{
		return GetInterface((IRtpBufferedListenerFilter*)this, ppVoid);
	}

	return CBaseFilter::NonDelegatingQueryInterface(riid, ppVoid);
}

STDMETHODIMP_(ULONG) CRtpBufferedListenerFilter::NonDelegatingRelease(void)
{
	ULONG uRefCount = CBaseFilter::NonDelegatingRelease();
	if (!m_bDisposing && uRefCount == 1)
	{
		m_bDisposing = TRUE;
		SAFE_RELEASE(m_pRtpBufferedListener);
		SAFE_RELEASE(m_pRtpListener);

		return 0;
	}

	return uRefCount;
}

// IRtpListenerEventConsumer
STDMETHODIMP CRtpBufferedListenerFilter::ActiveSourceAdded(UINT ssrc)
{
	// TODO doch nur im Debug, oder?
	DXTRACE_MSG("CRtpBufferedListenerFilter::ActiveSourceAdded");

	if (m_bAutoSubscribeActiveSources)
	{
		UINT uPinIterator = 0;
		BOOL bSubscribed = FALSE;
		for (; uPinIterator < m_uPinCount; uPinIterator++)
		{
			bSubscribed = FALSE;
			if (m_paBufferedStreams[uPinIterator] && SUCCEEDED(m_paBufferedStreams[uPinIterator]->IsSubscribed(&bSubscribed)) && !bSubscribed)
			{
				ASSERT(SUCCEEDED(m_paBufferedStreams[uPinIterator]->SelectSsrc(ssrc)));
				return S_OK;
			}
		}

		// TODO raise event for consumer

		return S_FALSE;
	}

	return S_FALSE;
}

STDMETHODIMP CRtpBufferedListenerFilter::ActiveSourceRemoved(UINT ssrc)
{
	DXTRACE_MSG("CRtpBufferedListenerFilter::ActiveSourceRemoved");
	return NOERROR;
}

STDMETHODIMP CRtpBufferedListenerFilter::ActiveSourceChanged(UINT ssrc, INT type)
{
	ASSERT(0);
	DXTRACE_MSG("CRtpBufferedListenerFilter::ActiveSourceChanged");
	return NOERROR;
}

STDMETHODIMP CRtpBufferedListenerFilter::SelectActiveSourceForOutputPin(UINT index, UINT ssrc)
{
	//m_pRtpListener->
	return E_NOTIMPL;
}

STDMETHODIMP CRtpBufferedListenerFilter::AddOutputPin(INT *pIndex)
{
	_RPT0(_CRT_WARN, "CRtpBufferedListenerFilter::AddOutputPin \r\n");

	HRESULT hr = S_OK;
	CRtpBufferedOutputStream* pOutputPin = new CRtpBufferedOutputStream(this, &hr, L"CRtpBufferedListenerFilter::AddOutputPin");
	CheckPointer(pOutputPin, E_OUTOFMEMORY);
	ASSERT(SUCCEEDED(hr));
	_RPT0(_CRT_WARN, "Created Pin, has Added itself to m_paStreams \r\n");
	_RPT1(_CRT_WARN, "m_uPinCount : %d \r\n", m_uPinCount);

	(*pIndex) = FindPinNumber(pOutputPin);
	_RPT1(_CRT_WARN, "FindPinNumber via Object-Ptr 0x%x \r\n", *pIndex);
	
	return hr;
}

STDMETHODIMP CRtpBufferedListenerFilter::AddOutputPinForActiveSource(UINT ssrc, INT *pIndex)
{
	TRACECALL;
	
	HRESULT hr = S_OK;
	CRtpBufferedOutputStream* pOutputPin = new CRtpBufferedOutputStream(this, &hr, L"CRtpBufferedListenerFilter::AddOutputPin");
	CheckPointer(pOutputPin, E_OUTOFMEMORY);
	ASSERT(SUCCEEDED(hr));
	VALHR(hr);

	(*pIndex) = FindPinNumber(pOutputPin);
	ASSERT(*pIndex > 0); // soweit ich weiss, 1 indiziert

	hr = pOutputPin->SelectSsrc(ssrc);
	
	return hr;
}


STDMETHODIMP CRtpBufferedListenerFilter::RemoveOutputPin(UINT index)
{
	TRACECALL;
	
	return this->RemoveOutputPin(index);
}

STDMETHODIMP CRtpBufferedListenerFilter::RegisterEventHandler(IRtpBufferedListenerFilterEventConsumer *pEventConsumer)
{
	CheckPointer(pEventConsumer, E_POINTER);
	CheckPointer(!m_pEventConsumer, E_UNEXPECTED);

	m_pEventConsumer = pEventConsumer;

	return S_OK;
}

STDMETHODIMP CRtpBufferedListenerFilter::RegisterEventHandlerEx(IRtpBufferedListenerFilterEventConsumerEx *pEventConsumerEx)
{
	TRACECALL;

	CheckPointer(pEventConsumerEx, E_POINTER);
	CheckPointer(!m_pEventConsumerEx, E_UNEXPECTED);

	m_pEventConsumerEx = pEventConsumerEx;

	return S_OK;
}

//////////////////////////////////////////////////////////////////////////
//
//  Add a new pin
//
HRESULT CRtpBufferedListenerFilter::AddPin(CRtpBufferedOutputStream *pPin)
{
	CAutoLock lock(&m_critSectFilterLock);

	/*  Allocate space for this pin and the old ones */
	CRtpBufferedOutputStream **paStreams = new CRtpBufferedOutputStream *[m_uPinCount + 1];
	if (paStreams == NULL) 
	{
		return E_OUTOFMEMORY;
	}
	if (m_paBufferedStreams != NULL) 
	{
		CopyMemory((PVOID)paStreams, (PVOID)m_paBufferedStreams,m_uPinCount * sizeof(m_paBufferedStreams[0]));
		paStreams[m_uPinCount] = pPin;
		delete [] m_paBufferedStreams;
	}
	m_paBufferedStreams = paStreams;
	m_paBufferedStreams[m_uPinCount] = pPin;
	m_uPinCount++;
	return S_OK;
}

//
//  Remove a pin - pStream is NOT deleted
//
HRESULT CRtpBufferedListenerFilter::RemovePin(CRtpBufferedOutputStream *pPin)
{
	CAutoLock lock(&m_critSectFilterLock);

	UINT i;
	for (i = 0; i < m_uPinCount; i++) 
	{
		if (m_paBufferedStreams[i] == pPin) 
		{
			if (m_uPinCount == 1) 
			{
				delete [] m_paBufferedStreams;
				m_paBufferedStreams = NULL;
			} 
			else 
			{
				/*  no need to reallocate */
				while (++i < m_uPinCount)
					m_paBufferedStreams[i - 1] = m_paBufferedStreams[i];
			}
			m_uPinCount--;
			return S_OK;
		}
	}
	return S_FALSE;
}

//
// FindPinNumber
//
// return the number of the pin with this IPin* or -1 if none
int CRtpBufferedListenerFilter::FindPinNumber(IPin *iPin) 
{
	UINT i;
	for (i=0; i<m_uPinCount; ++i)
	{
		if ((IPin *)(m_paBufferedStreams[i])==iPin) 
		{
			return i;
		}
	}
	return -1;
}

//
// GetPin
//
// Return a non-addref'd pointer to pin n
// needed by CBaseFilter
CBasePin *CRtpBufferedListenerFilter::GetPin(int n) 
{
	CAutoLock lock(&m_critSectFilterLock);

	// n must be in the range 0..m_uPinCount-1
	// if m_uPinCount>n  && n>=0 it follows that m_uPinCount>0
	// which is what used to be checked (i.e. checking that we have a pin)
#pragma warning(disable: 4018) // signed/unsigned mismatch
	if ((n >= 0) && (n < m_uPinCount)) 
	{
		ASSERT(m_paBufferedStreams[n]);
		return m_paBufferedStreams[n];
	}
#pragma warning(default: 4018)
	return NULL;
}

//
// FindPin
//
// Set *ppPin to the IPin* that has the id Id.
// or to NULL if the Id cannot be matched.
STDMETHODIMP CRtpBufferedListenerFilter::FindPin(LPCWSTR Id, IPin **ppPin)
{
	CheckPointer(ppPin,E_POINTER);
	ValidateReadWritePtr(ppPin,sizeof(IPin *));
	// The -1 undoes the +1 in QueryId and ensures that totally invalid
	// strings (for which WstrToInt delivers 0) give a deliver a NULL pin.
	int i = WstrToInt(Id) -1;
	*ppPin = GetPin(i);
	if (*ppPin!=NULL){
		(*ppPin)->AddRef();
		return NOERROR;
	} else {
		return VFW_E_NOT_FOUND;
	}
}

//
// GetPinCount
//
// Returns the number of pins this filter has
int CRtpBufferedListenerFilter::GetPinCount(void) {

	CAutoLock lock(&m_critSectFilterLock);
	return m_uPinCount;
}

STDMETHODIMP CRtpBufferedListenerFilter::GetState(
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

//////////////////////////////////////////////////////////////////////////

// IRTpBufferedListenerFilter
STDMETHODIMP CRtpBufferedListenerFilter::SetNetworkParameter(
							   LPWSTR szRemoteAddress, 
							   USHORT uRemotePort, 
							   LPWSTR szLocalInterface, 
							   USHORT uLocalPort,
							   INT ttl)
{
	CheckPointer(m_pRtpListener, E_POINTER);

	HRESULT hr = m_pRtpListener->SetNetworkParameter(szRemoteAddress, uRemotePort, szLocalInterface, uLocalPort, ttl);
	ASSERT(SUCCEEDED(hr));

	if (SUCCEEDED(hr))
	{
		m_state = RTPLISTENERFILTERSTATE_NETWORK_CONFIGURED;
	}

	return hr;
}

STDMETHODIMP CRtpBufferedListenerFilter::SetMediaParameterDefaults(
		BOOL bAduSpansMultiplePackets,
		BYTE payloadType,
		UINT uRtpTimeStampIncrementPerSecond,
		UINT uExpectedTimePerAduNanoseconds)
{
	CheckPointer(m_pRtpListener, E_UNEXPECTED);

	m_uTimePerFrame = uExpectedTimePerAduNanoseconds;

	return m_pRtpListener->SetMediaParameterDefaults(
		bAduSpansMultiplePackets,
		payloadType,
		uRtpTimeStampIncrementPerSecond,
		uExpectedTimePerAduNanoseconds, TRUE);
}


STDMETHODIMP CRtpBufferedListenerFilter::SetOutputMediaType(AM_MEDIA_TYPE *pMediaType)
{
	CheckPointer(pMediaType, E_POINTER);
	SAFE_DELETE(m_pOutputMediaType);

	HRESULT hr = S_OK;
	m_pOutputMediaType = new CMediaType((*pMediaType), &hr);

	return hr;
}


STDMETHODIMP CRtpBufferedListenerFilter::SetRtpBandwidth(UINT uSessionBandwidth, BOOL bEnforce)
{
	CheckPointer(m_pRtpListener, E_UNEXPECTED);

	m_uRtpBitrate = uSessionBandwidth;

	HRESULT hr = m_pRtpListener->SetRtpBandwidth(uSessionBandwidth, bEnforce);
	VALHR(hr);

	return hr;
}

STDMETHODIMP CRtpBufferedListenerFilter::SetJitterBufferParameter(UINT ssrc, UINT uLatency)
{
	return m_pRtpBufferedListener->SetJitterBufferLatency(ssrc, uLatency);
}

STDMETHODIMP CRtpBufferedListenerFilter::GetSubscribedSourcesCount(INT *pcSubscribed)
{
	TRACECALL;
	CheckPointer(m_pRtpBufferedListener, E_UNEXPECTED);
	CheckPointer(pcSubscribed, E_POINTER);

	return m_pRtpBufferedListener->GetSubscribedSourcesCount(pcSubscribed);
}
STDMETHODIMP CRtpBufferedListenerFilter::GetSubscribedSources(INT** ppSubscribedSources, INT* pcSubscribedSources)
{
	TRACECALL;
	
	CheckPointer(m_pRtpBufferedListener, E_UNEXPECTED);
	CheckPointer(ppSubscribedSources, E_POINTER);
	CheckPointer(pcSubscribedSources, E_POINTER);

	return m_pRtpBufferedListener->GetSubscribedSources(ppSubscribedSources, pcSubscribedSources);
}
STDMETHODIMP CRtpBufferedListenerFilter::GetActiveSourcesCount(INT *pcActive)
{
	CheckPointer(m_pRtpBufferedListener, E_UNEXPECTED);
	CheckPointer(pcActive, E_POINTER);

	return m_pRtpBufferedListener->GetActiveSourcesCount(pcActive);
}
STDMETHODIMP CRtpBufferedListenerFilter::GetActiveSources(INT** pActiveSources, INT* pcActiveSources)
{
	CheckPointer(m_pRtpBufferedListener, E_UNEXPECTED);
	CheckPointer(pActiveSources, E_POINTER);
	CheckPointer(pcActiveSources, E_POINTER);

	return m_pRtpBufferedListener->GetActiveSources(pActiveSources, pcActiveSources);
}

STDMETHODIMP CRtpBufferedListenerFilter::GetActiveSourcesSafeArray(SAFEARRAY** ppSafeArray)
{
	return m_pRtpBufferedListener->GetActiveSourcesSafeArray(ppSafeArray);
}

STDMETHODIMP CRtpBufferedListenerFilter::Run(REFERENCE_TIME tStart)
{
	// Am ende der Run Methode setzt der Filter den Status aus State_Running
	HRESULT hr = this->CBaseFilter::Run(tStart);

	hr = m_pRtpListener->Start();
	VALHR(hr);

	return hr;
}

STDMETHODIMP CRtpBufferedListenerFilter::Pause(void)
{
	HRESULT hr = this->CBaseFilter::Pause();
	
	return hr;
}

STDMETHODIMP_(ULONG) CRtpBufferedListenerFilter::GetMiscFlags(void)
{
	return AM_FILTER_MISC_FLAGS_IS_SOURCE;
}

STDMETHODIMP CRtpBufferedListenerFilter::SetAutoSubscribeActiveSources(BOOL bValue)
{
	m_bAutoSubscribeActiveSources = bValue;
	return S_OK;
}

STDMETHODIMP CRtpBufferedListenerFilter::GetAutoSubscribeActiveSources(BOOL *pbValue)
{
	CheckPointer(pbValue, E_POINTER);
	*pbValue = m_bAutoSubscribeActiveSources;
	return S_OK;
}


STDMETHODIMP CRtpBufferedListenerFilter::SetRtpPayloadPacketizer(
	IRtpPayloadPacketizer *pPacketizer)
{
	CheckPointer(pPacketizer, E_POINTER);

	if (m_State != State_Stopped)
	{
		// geht nur im Stopped state
		return E_UNEXPECTED;
	}

	SAFE_RELEASE(m_pRtpPayloadPacketizer);
	m_pRtpPayloadPacketizer = pPacketizer;
	m_pRtpPayloadPacketizer->AddRef();

	return S_OK;
}

STDMETHODIMP CRtpBufferedListenerFilter::ReserveNetworkAddress(/*[in]*/ LPWSTR szRemoteAddress, /*[in,out]*/ LPWSTR szLocalAddress, USHORT uMinLocalPort, USHORT uMaxLocalPort, LPWSTR szLocalOut, INT cchLocal, USHORT *puLocalPort)
{
	return m_pRtpListener->ReserveNetworkAddress(szRemoteAddress, szLocalAddress, uMinLocalPort, uMaxLocalPort, szLocalOut, cchLocal, puLocalPort);
}

STDMETHODIMP CRtpBufferedListenerFilter::GetNetworkParameter(LPWSTR szRemoteAddress, INT cchRemoteAddress, USHORT *puRemotePort, LPWSTR szLocalInterface, INT cchLocalAddress, USHORT *puLocalPortBase, INT* pTtl)
{
	return m_pRtpListener->GetNetworkParameter(szRemoteAddress, cchRemoteAddress, puRemotePort, szLocalInterface, cchLocalAddress, puLocalPortBase, pTtl);
}

STDMETHODIMP CRtpBufferedListenerFilter::SetJitterBufferLatency(UINT ssrc, UINT uLatency)
{
	return m_pRtpBufferedListener->SetJitterBufferLatency(ssrc, uLatency);
}

STDMETHODIMP CRtpBufferedListenerFilter::GetJitterBufferLatency(UINT ssrc, UINT* puLatency)
{
	return m_pRtpBufferedListener->GetJitterBufferLatency(ssrc, puLatency);
}

STDMETHODIMP CRtpBufferedListenerFilter::GetRtcpAttributes(UINT ssrc, SdesItems *pSdesItems)
{
	return m_pRtpBufferedListener->GetRtcpAttributes(ssrc, pSdesItems);
}

STDMETHODIMP CRtpBufferedListenerFilter::SetMuted(UINT ssrc, INT bMuted)
{
	return m_pRtpBufferedListener->SetMuted(ssrc, bMuted);
}

STDMETHODIMP CRtpBufferedListenerFilter::GetMuted(UINT ssrc, INT *pbIsMuted)
{
	return m_pRtpBufferedListener->GetMuted(ssrc, pbIsMuted);
}

STDMETHODIMP CRtpBufferedListenerFilter::SetPinCount(INT pinCount)
{
	CAutoLock lock(&m_critSectFilterLock);

	if (pinCount <= m_uPinCount)
	{
		return S_FALSE;
	}
	HRESULT hr = S_OK;
	CRtpBufferedOutputStream *pStream = NULL;
	for (UINT pin = m_uPinCount; pin < pinCount; pin++)
	{
		pStream = new CRtpBufferedOutputStream(this, &hr, L"Pin");
		CheckPointer(pStream, E_OUTOFMEMORY);
		if (FAILED(hr)) return hr;
	}

	return S_OK;
}

STDMETHODIMP CRtpBufferedListenerFilter::GetPinCount(INT *pPinCount)
{
	CheckPointer(pPinCount, E_POINTER);
	(*pPinCount) = m_uPinCount;
	return S_OK;
}

STDMETHODIMP CRtpBufferedListenerFilter::GetPinIndexForSource(UINT ssrc, INT *pIndex)
{
	CheckPointer(pIndex, E_POINTER);

	CAutoLock lock(&m_critSectFilterLock);

	HRESULT hr = S_OK;
	
	UINT tempSsrc = 0;
	for (UINT pin = 0; pin < m_uPinCount; pin++)
	{
		hr = m_paBufferedStreams[pin]->GetSsrc(&tempSsrc);
		if (S_OK == hr && tempSsrc == ssrc)
		{
			(*pIndex) = pin;
			return S_OK;
		}
	}
	return E_FAIL;
}
#endif
