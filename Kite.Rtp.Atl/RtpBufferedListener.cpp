#include "stdafx.h"
#include "RtpBufferedListener.h"
#include "RtpMediaTypeHelper.h"

#include ".\audiojitterbuffer.h"
#include ".\rtpbufferedlistener.h"

#define DEFAULT_NANOS_PER_FRAME	(1000 * 10000 / 10) // ~15 fps

CRtpBufferedListener::CRtpBufferedListener()
	: m_uTimestampIncrementPerSecond(90000)
	, m_uTimePerFrameNanos(DEFAULT_NANOS_PER_FRAME)
	, m_uExpectedTimePerAduNanoseconds(DEFAULT_NANOS_PER_FRAME)
	, m_uBufferDurationMilliseconds(3000)
	, m_bAduSpansMultiplePackets(TRUE)
	, m_payloadType(0x22)
{
}

HRESULT CRtpBufferedListener::FinalConstruct()
{
	HRESULT hr = this->CRtpListenerBase::FinalConstruct();
	VALHR(hr);

 	BOOL bRetVal = m_mapJitterBuffersForSources.InitHashTable(3);
	ASSERT(bRetVal);

	if (!bRetVal) return E_FAIL;


	bRetVal = InitializeCriticalSectionAndSpinCount(&m_critSectMapJitterBufferForSourcesSynchronization, 0x80000400);
	ASSERT(bRetVal);


	return bRetVal ? S_OK : E_FAIL;
}
void CRtpBufferedListener::FinalRelease()
{
	this->CRtpListenerBase::FinalRelease();

	DeleteCriticalSection(&m_critSectRtpSessionMembersMapSynchronization);
}

STDMETHODIMP CRtpBufferedListener::Configure(BYTE* pSocketAddresses, UINT cbSocketAddresses/*, BYTE* pSdesItems, UINT cbSdesItems*/)
{
	return this->CRtpListenerBase::Configure(pSocketAddresses, cbSocketAddresses);
}

STDMETHODIMP CRtpBufferedListener::Start(void)
{
	SetParameterOnJitterBuffer();

	return this->CRtpListenerBase::Start();
}

STDMETHODIMP CRtpBufferedListener::Stop(void)
{
	return this->CRtpListenerBase::Stop();
}

STDMETHODIMP CRtpBufferedListener::SetNetworkParameter(LPWSTR szRemoteAddress, USHORT uRemotePort, LPWSTR szLocalInterface, USHORT uLocalPort, INT ttl)
{
	return this->CRtpListenerBase::SetNetworkParameter(szRemoteAddress, uRemotePort, szLocalInterface, uLocalPort, ttl);
}

STDMETHODIMP CRtpBufferedListener::RegisterCallback(IRtpListenerEventConsumer *pEventConsumer)
{
	return this->CRtpListenerBase::RegisterCallback(pEventConsumer);
}

STDMETHODIMP CRtpBufferedListener::GetDeliveryUnit(UINT ssrc, RtpParsedPacket*** pppDeliveryUnit, UINT *pcPackets)
{
	CheckPointer(pppDeliveryUnit, E_POINTER);
	CheckPointer(pcPackets, E_POINTER);

	CAutoLock lock(&m_critSectMapJitterBufferForSourcesSynchronization);

	IPlayoutBuffer *m_pVideoJitterBuffer;
	if (m_mapJitterBuffersForSources.Lookup(ssrc, m_pVideoJitterBuffer) && m_pVideoJitterBuffer)
	{
		return m_pVideoJitterBuffer->DequeuePackets(pppDeliveryUnit, pcPackets);
	}

	// Not subscribed
	return E_FAIL;
}

STDMETHODIMP CRtpBufferedListener::HandleParsedRtpPacket(RtpParsedPacket *pPacket)
{
	CheckPointer(pPacket, E_POINTER);

	DebugHelpers_DebugPrintRtpParsedPacket(pPacket);

	CAutoLock lock(&m_critSectMapJitterBufferForSourcesSynchronization);

	HRESULT hr = S_OK;

	IPlayoutBuffer *m_pVideoJitterBuffer;
	if (m_mapJitterBuffersForSources.Lookup(pPacket->ssrc, m_pVideoJitterBuffer) && m_pVideoJitterBuffer)
	{
		UINT ssrc = pPacket->ssrc;
		hr = m_pVideoJitterBuffer->EnqueuePacket(pPacket);

		ASSERT(SUCCEEDED(hr));
		if (SUCCEEDED(hr))
		{
			//S_FALSE == Packet wasn't enqueued, dropped for example
			//S_PROPERTY_CHANGED == The payload type changed
			if (hr == S_OK)
			{
				return hr;
			}
			else if (hr == S_FALSE)
			{
				return hr;
			}
			else if (hr == S_PROPERTY_CHANGED)
			{
				RaiseActiveRtpSourceChangedEvent(ssrc, RTP_SESSION_MEMBER_EVENT_TYPE_PAYLOADTYPE_CHANGED);
				return S_FALSE;
			}
		}
		
		return hr;
	}
	else
	{
		{
			SAFE_FREE(pPacket);
		}
	}

	// Not subscribed
	return E_FAIL;
}

STDMETHODIMP CRtpBufferedListener::SubscribeSsrc(UINT ssrc)
{
	CAutoLock lock(&m_critSectMapJitterBufferForSourcesSynchronization);	

	IPlayoutBuffer *pBuffer;
	if (m_mapJitterBuffersForSources.Lookup(ssrc, pBuffer))
	{
		if (pBuffer)
		{
			// Already subscribed
			return S_FALSE;
		}
		else
		{
			m_mapJitterBuffersForSources.RemoveKey(ssrc);
		}
	}
	
	HRESULT hr = S_OK;

	if (m_pPlayoutBufferClassFactory != NULL)
	{
		m_pPlayoutBufferClassFactory->CreateInstance(NULL, __uuidof(IPlayoutBuffer), (void**)&pBuffer);
	}
	else
	{
		if (m_bAduSpansMultiplePackets)
		{
			if (m_pPlayoutBufferClassFactory)
			{
				m_pPlayoutBufferClassFactory->CreateInstance(NULL, __uuidof(IPlayoutBuffer), (void**)&pBuffer);
			}
			else
			{
				ASSERT(m_pPlayoutBufferClassFactory);
				hr = CoCreateInstance(__uuidof(CVideoPlayoutBuffer), NULL, CLSCTX_INPROC, __uuidof(IPlayoutBuffer), (void**)&pBuffer);
			}
		}
		else
		{
			if (m_pPlayoutBufferClassFactory)
			{
				m_pPlayoutBufferClassFactory->CreateInstance(NULL, __uuidof(IPlayoutBuffer), (void**)&pBuffer);
			}
			else
			{
				ASSERT(m_pPlayoutBufferClassFactory);
				hr = CoCreateInstance(__uuidof(CAudioPlayoutBuffer), NULL, CLSCTX_INPROC, __uuidof(IPlayoutBuffer), (void**)&pBuffer);
			}
		}
	}
	if (FAILED(hr))
	{
		ASSERT(pBuffer);
		return hr;
	}
	
	pBuffer->SetBufferParameter(m_uBufferDurationMilliseconds, m_uTimestampIncrementPerSecond, m_uTimePerFrameNanos);

	m_mapJitterBuffersForSources.SetAt(ssrc, pBuffer);

	return S_OK;
}

STDMETHODIMP CRtpBufferedListener::SubscribeSsrcAndGetPointer(UINT ssrc, IPlayoutBuffer** ppPlayoutBuffer)
{
	return SubscribeSsrcAndGetPointerEx(ssrc, NULL, m_payloadType, m_uTimestampIncrementPerSecond, m_uExpectedTimePerAduNanoseconds, ppPlayoutBuffer);
}

STDMETHODIMP CRtpBufferedListener::SubscribeSsrcAndGetPointerEx(UINT ssrc, 
																LPGUID pGuidJitterBuffer,
																BYTE payloadType,
																UINT uRtpTimeStampIncrementPerSecond,
																UINT uExpectedTimePerAduNanoseconds,
																
																IPlayoutBuffer** ppPlayoutBuffer)
{
	CheckPointer(ppPlayoutBuffer, E_POINTER);
	CAutoLock lock(&m_critSectMapJitterBufferForSourcesSynchronization);	

	if (m_mapJitterBuffersForSources.Lookup(ssrc, (*ppPlayoutBuffer)))
	{
		if (*ppPlayoutBuffer)
		{
			SAFE_RELEASE((*ppPlayoutBuffer));
		}
		else
		{
			m_mapJitterBuffersForSources.RemoveKey(ssrc);
		}
	}


	if (pGuidJitterBuffer != NULL)
	{
		CoCreateInstance(*pGuidJitterBuffer, NULL, CLSCTX_INPROC, __uuidof(IPlayoutBuffer), (void**)ppPlayoutBuffer);
	}
	else if (m_pPlayoutBufferClassFactory)
	{
		m_pPlayoutBufferClassFactory->CreateInstance(NULL, __uuidof(IPlayoutBuffer), (void**)ppPlayoutBuffer);
	}
	else
	{
		ASSERT(0);
		if (m_bAduSpansMultiplePackets)
		{
			CoCreateInstance(__uuidof(CVideoPlayoutBuffer), NULL, CLSCTX_INPROC, __uuidof(IPlayoutBuffer), (void**)ppPlayoutBuffer);
			// ...
		}
		else
		{
			CoCreateInstance(__uuidof(CAudioPlayoutBuffer), NULL, CLSCTX_INPROC, __uuidof(IPlayoutBuffer), (void**)ppPlayoutBuffer);
		}
	}

	HRESULT hr = S_OK;

	if (FAILED(hr))
	{
		ASSERT(hr == S_OK && *ppPlayoutBuffer);
		return hr;
	}

	(*ppPlayoutBuffer)->SetBufferParameter(m_uBufferDurationMilliseconds, m_uTimestampIncrementPerSecond, m_uTimePerFrameNanos);

	m_mapJitterBuffersForSources.SetAt(ssrc, (*ppPlayoutBuffer));

	(*ppPlayoutBuffer)->AddRef();

	return S_OK;
}

STDMETHODIMP CRtpBufferedListener::UnsubscribeSsrc(UINT ssrc)
{
	CAutoLock lock(&m_critSectMapJitterBufferForSourcesSynchronization);	

	IPlayoutBuffer *pBuffer;
	if (m_mapJitterBuffersForSources.Lookup(ssrc, pBuffer))
	{
		if (!pBuffer)
		{
			m_mapJitterBuffersForSources.RemoveKey(ssrc);
		}
		else
		{
			SAFE_DISPOSE_AND_RELEASE(pBuffer);
			ASSERT(m_mapJitterBuffersForSources.RemoveKey(ssrc));
		}
	}

	return S_OK;
}
// Virtual
STDMETHODIMP CRtpBufferedListener::InternalHandleSourceRemoved(UINT ssrc)
{
	return UnsubscribeSsrc(ssrc);
}

STDMETHODIMP CRtpBufferedListener::CreateClassFactory(BOOL bVideo)
{
	if (m_pPlayoutBufferClassFactory)
	{
		return S_FALSE;

		m_pPlayoutBufferClassFactory->LockServer(FALSE);
		m_pPlayoutBufferClassFactory = NULL;
	}

	HRESULT hr = S_OK;
	if (bVideo)
	{
		hr = CoGetClassObject(__uuidof(CVideoPlayoutBuffer), CLSCTX_INPROC_SERVER, NULL, IID_IClassFactory, (void**)&m_pPlayoutBufferClassFactory);
	}
	else
	{
		hr = CoGetClassObject(__uuidof(CAudioPlayoutBuffer), CLSCTX_INPROC_SERVER, NULL, IID_IClassFactory, (void**)&m_pPlayoutBufferClassFactory);
	}

	ASSERT(SUCCEEDED(hr));
	ASSERT(m_pPlayoutBufferClassFactory);

	if (SUCCEEDED(hr))
	{
		m_pPlayoutBufferClassFactory->LockServer(TRUE);
	}

	return hr;
}

STDMETHODIMP CRtpBufferedListener::SetMediaParameterDefaults(
		BOOL bAduSpansMultiplePackets,
		BYTE payloadType,
		UINT uRtpTimeStampIncrementPerSecond,
		UINT uExpectedTimePerAduNanoseconds,
		BOOL bUpdateExistingBuffers)
{
	if (payloadType > 127) return E_INVALIDARG;

	if (m_bAduSpansMultiplePackets != bAduSpansMultiplePackets) 
	{
		HRESULT hr = S_OK;
		hr = CreateClassFactory(bAduSpansMultiplePackets);
		ASSERT(SUCCEEDED(hr));
	}

	m_bAduSpansMultiplePackets = bAduSpansMultiplePackets;
	m_uTimestampIncrementPerSecond = uRtpTimeStampIncrementPerSecond;
	m_payloadType = payloadType;
	m_uExpectedTimePerAduNanoseconds = uExpectedTimePerAduNanoseconds;

	if (bUpdateExistingBuffers)
	{
		CAutoLock lock(&m_critSectMapJitterBufferForSourcesSynchronization);

		POSITION position = m_mapJitterBuffersForSources.GetStartPosition();

		UINT ssrc;
		IPlayoutBuffer* pBuffer = NULL;
		while (position) 
		{
			m_mapJitterBuffersForSources.GetNextAssoc(position, ssrc, pBuffer);

			if (pBuffer == NULL)
			{
				ASSERT(0);
			}
			else
			{
				pBuffer->SetBufferParameter(m_uBufferDurationMilliseconds, m_uTimestampIncrementPerSecond, m_uTimePerFrameNanos);
			}
		}
	}
	return S_OK;
}

STDMETHODIMP CRtpBufferedListener::SetRtpBandwidth(UINT uSessionBandwidthKilobitPerSecond, BOOL bEnforce)
{
	return this->CRtpSocketBase::SetRtpBandwidth(uSessionBandwidthKilobitPerSecond, bEnforce);
}

STDMETHODIMP CRtpBufferedListener::GetSubscribedSourcesCount(INT *pcSubscribed)
{
	CAutoLock lock(&m_critSectMapJitterBufferForSourcesSynchronization);

	// Call this method to retrieve the number of elements in the map.
	(*pcSubscribed) = m_mapJitterBuffersForSources.GetCount();

	return S_OK;
}

STDMETHODIMP CRtpBufferedListener::GetSubscribedSources(INT** ppSubscribedSources, INT* pcSubscribedSources)
{
	CheckPointer(ppSubscribedSources, E_POINTER);

	CAutoLock lockMap(&m_critSectMapJitterBufferForSourcesSynchronization);
	CAutoLock lock(&m_critSectRtpSessionMembersMapSynchronization);

	INT cItems = m_mapJitterBuffersForSources.GetCount();
	if (cItems == 0)
	{
		(*ppSubscribedSources) = NULL;
		(*pcSubscribedSources) = 0;
		return S_FALSE;
	}

	(*pcSubscribedSources) = cItems;
	(*ppSubscribedSources) = (INT*)SAFE_ALLOC((*pcSubscribedSources) * sizeof(INT));
	CheckPointer(*ppSubscribedSources, E_OUTOFMEMORY);

	POSITION pos = m_mapJitterBuffersForSources.GetStartPosition();
	IPlayoutBuffer *pPlayoutBuffer = NULL;
	CRtpSessionMember *pMember = NULL;
	UINT ssrcKey = 0;
	for (int subscribed = 0; (subscribed < cItems) && (pos != NULL); subscribed++)
	{
		m_mapJitterBuffersForSources.GetNextAssoc(pos, ssrcKey, pPlayoutBuffer);

		if (S_OK == CheckIsPlayoutBufferDisposed(pPlayoutBuffer))
		{
			ASSERT(0);
			(*ppSubscribedSources)[subscribed] = 0;
			continue;
		}

		if (m_mapRtpSessionMembers.Lookup(ssrcKey, pMember))
		{
			ASSERT(pMember);
			ASSERT(ssrcKey == pMember->m_ssrc);
			ASSERT(pMember->m_bIsSource);

			(*ppSubscribedSources)[subscribed] = ssrcKey;
		}
		else
		{
			ASSERT(0);
		}		
	}

	return S_OK;
}

STDMETHODIMP CRtpBufferedListener::GetActiveSourcesCount(INT *pcActive)
{
	CheckPointer(pcActive, E_POINTER);

	CAutoLock lock(&m_critSectRtpSessionMembersMapSynchronization);

	if (m_mapRtpSessionMembers.GetCount() == 0)
	{
		(*pcActive) = 0;
		return S_OK;
	}

	POSITION pos = m_mapRtpSessionMembers.GetStartPosition();
	CRtpSessionMember *pMember = NULL;
	while(pMember = m_mapRtpSessionMembers.GetNextValue(pos) /*&& pos*/)
	{
		if (pMember->m_bIsSource)
			(*pcActive)++; 

		if (!pos) break;
	}
	
	return S_OK;
}

STDMETHODIMP CRtpBufferedListener::GetActiveSources(INT** ppActiveSources, INT* pcActiveSources)
{
	CheckPointer(ppActiveSources, E_POINTER);
	CheckPointer(pcActiveSources, E_POINTER);

	CAutoLock lock(&m_critSectRtpSessionMembersMapSynchronization);

	INT cItems = m_mapRtpSessionMembers.GetCount();
	if (cItems == 0)
	{
		(*ppActiveSources) = NULL;
		(*pcActiveSources) = 0;
		return S_FALSE;
	}

	// langsam
	HRESULT hr = GetActiveSourcesCount(pcActiveSources);
	VALHR(hr);

	(*ppActiveSources) = (INT*)SAFE_ALLOC((*pcActiveSources) * sizeof(INT));
	CheckPointer(*ppActiveSources, E_OUTOFMEMORY);

	POSITION pos = m_mapRtpSessionMembers.GetStartPosition();
	CRtpSessionMember *pMember = NULL;
	UINT ssrcKey;
	for (int active = 0; active < cItems; active++)
	{
		m_mapRtpSessionMembers.GetAt(pos, ssrcKey, pMember);
		ASSERT(pMember);
		ASSERT(ssrcKey == pMember->m_ssrc);
		if (pMember->m_bIsSource)
		{
			// TODO knallt - ist eine Map
			(*ppActiveSources)[active] = ssrcKey;
		}
	}

	return S_OK;
}

STDMETHODIMP CRtpBufferedListener::GetActiveSourcesSafeArray(/*[out, satype(VT_U4)]*/ SAFEARRAY** ppActiveSources)
{
	CheckPointer(ppActiveSources, E_POINTER);

	INT cActiveSources = 0;
	GetActiveSourcesCount(&cActiveSources);
	SAFEARRAYBOUND sfarrybndSafeArrayBound [] = { cActiveSources, 0 };

	(*ppActiveSources) = SafeArrayCreate(VT_UI4, 1, sfarrybndSafeArrayBound);

	UINT *puActiveSources;

	SafeArrayAccessData((*ppActiveSources), (void**)&puActiveSources);

	POSITION pos = m_mapRtpSessionMembers.GetStartPosition();
	CRtpSessionMember *pMember = NULL;
	UINT ssrcKey;
	for (int active = 0; active < cActiveSources; active++)
	{
		m_mapRtpSessionMembers.GetAt(pos, ssrcKey, pMember);
		ASSERT(pMember);
		ASSERT(ssrcKey == pMember->m_ssrc);
		if (pMember->m_bIsSource)
		{
			puActiveSources[active] = ssrcKey;
			
		}
	}

	SafeArrayUnaccessData(*ppActiveSources);

	return S_OK;
}

STDMETHODIMP CRtpBufferedListener::GetLatency(UINT* pLatency)
{
	CheckPointer(pLatency, E_POINTER);

	(*pLatency) = (m_uBufferDurationMilliseconds * 10000);
	return S_OK;
}

STDMETHODIMP CRtpBufferedListener::SetLatency(UINT uLatency)
{
	CAutoLock lock(&m_critSectObjectLock);

	UINT uTemp = (m_uBufferDurationMilliseconds / 10000);

	if (uTemp > 500 && uTemp < 5000)
	{
		m_uBufferDurationMilliseconds = uTemp;
		return S_OK;
	}
	
	return E_INVALIDARG;
}

STDMETHODIMP CRtpBufferedListener::SetParameterOnJitterBuffer()
{
	CAutoLock lock(&m_critSectMapJitterBufferForSourcesSynchronization);

	POSITION pos = m_mapJitterBuffersForSources.GetStartPosition();

	IPlayoutBuffer *pJitterBuffer = NULL;
	
	while (pos && ((pJitterBuffer = m_mapJitterBuffersForSources.GetNextValue(pos)) != NULL))
	{
		ASSERT(SUCCEEDED(pJitterBuffer->SetBufferParameter(m_uBufferDurationMilliseconds, m_uTimestampIncrementPerSecond, m_uTimePerFrameNanos)));
	}

	return S_OK;
}

STDMETHODIMP CRtpBufferedListener::ReserveNetworkAddressAndCreateSockets(LPWSTR szRemoteAddress, LPWSTR szLocalInterface, USHORT uMinLocalPort, USHORT uMaxLocalPort, INT ttl)
{
	HRESULT hr = S_OK;
	hr = InternalReserveNetworkAddressAndCreateSockets(
		szRemoteAddress, 
		szLocalInterface, 
		uMinLocalPort, uMaxLocalPort, ttl);

	if (FAILED(hr))
	{
		return hr;
	}

	ASSERT(m_pRtpAddresses);
	ASSERT(m_pRtcpAddresses);

	hr = this->CRtpSocketBase::InitializePerformanceCounter();
	VALHR(hr);

	return hr;
}

STDMETHODIMP CRtpBufferedListener::ReserveNetworkAddress(LPWSTR szRemoteAddress, LPWSTR szLocalInterface, USHORT uMinLocalPort, USHORT uMaxLocalPort, LPWSTR szLocalInterfaceOut, INT cchLocalAddress, USHORT *puLocalPortBase)
{
	HRESULT hr = S_OK;
	hr = InternalReserveNetworkAddress(
		szRemoteAddress, 
		szLocalInterface, 
		uMinLocalPort, uMaxLocalPort, szLocalInterfaceOut, cchLocalAddress, puLocalPortBase);

	return hr;
}

STDMETHODIMP CRtpBufferedListener::GetNetworkParameter(
							   LPWSTR szRemoteAddress, INT cchRemoteAddress, USHORT *puRemotePort, 
							   LPWSTR szLocalInterface, INT cchLocalAddress, USHORT *puLocalPortBase, INT* pTtl)
{
	return InternalGetNetworkParameter(
		szRemoteAddress, cchRemoteAddress, puRemotePort, 
		szLocalInterface, cchLocalAddress, puLocalPortBase, pTtl);
}

// 13092003
STDMETHODIMP CRtpBufferedListener::SetJitterBufferLatency(UINT ssrc, UINT uLatency)
{
	IPlayoutBuffer *pJitterBuffer = NULL;

	CAutoLock lock(&m_critSectMapJitterBufferForSourcesSynchronization);

	if (m_mapJitterBuffersForSources.Lookup(ssrc, pJitterBuffer) == TRUE)
	{
		if (pJitterBuffer == NULL)
		{
			m_mapJitterBuffersForSources.RemoveKey(ssrc);
		}
		else
		{
			return pJitterBuffer->SetLatency(uLatency);
		}
	}

	return E_INVALIDARG;
}

STDMETHODIMP CRtpBufferedListener::GetJitterBufferLatency(UINT ssrc, UINT* puLatency)
{
	IPlayoutBuffer *pJitterBuffer = NULL;

	CAutoLock lock(&m_critSectMapJitterBufferForSourcesSynchronization);

	if (m_mapJitterBuffersForSources.Lookup(ssrc, pJitterBuffer) == TRUE)
	{
		if (pJitterBuffer == NULL)
		{
			m_mapJitterBuffersForSources.RemoveKey(ssrc);
		}
		else
		{
			return pJitterBuffer->GetLatency(puLatency);
		}
	}

	return E_INVALIDARG;
}

STDMETHODIMP CRtpBufferedListener::GetRtcpAttributes(UINT ssrc, SdesItems *pSdesItems)
{
	CAutoLock lock(&m_critSectRtpSessionMembersMapSynchronization);

	CRtpSessionMember* pMember = NULL;

	if (m_mapRtpSessionMembers.Lookup(ssrc, pMember))
	{
		if (!pMember)
		{
			m_mapRtpSessionMembers.RemoveKey(ssrc);
			return E_INVALIDARG;
		}
		else
		{
			return pMember->GetSdesItems(pSdesItems);
		}
	}
	else
	{
		return E_INVALIDARG;
	}
}

STDMETHODIMP CRtpBufferedListener::SetMuted(UINT ssrc, BOOL bMuted)
{
	IPlayoutBuffer *pJitterBuffer = NULL;

	CAutoLock lock(&m_critSectMapJitterBufferForSourcesSynchronization);

	if (m_mapJitterBuffersForSources.Lookup(ssrc, pJitterBuffer) == TRUE)
	{
		if (pJitterBuffer == NULL)
		{
			m_mapJitterBuffersForSources.RemoveKey(ssrc);
		}
		else
		{
			return pJitterBuffer->SetMuted(bMuted);
		}
	}

	return E_INVALIDARG;
}

STDMETHODIMP CRtpBufferedListener::GetMuted(UINT ssrc, BOOL *pbIsMuted)
{
	IPlayoutBuffer *pJitterBuffer = NULL;

	CAutoLock lock(&m_critSectMapJitterBufferForSourcesSynchronization);

	if (m_mapJitterBuffersForSources.Lookup(ssrc, pJitterBuffer) == TRUE)
	{
		if (pJitterBuffer == NULL)
		{
			m_mapJitterBuffersForSources.RemoveKey(ssrc);
		}
		else
		{
			return pJitterBuffer->GetMuted(pbIsMuted);
		}
	}

	return E_INVALIDARG;
}

STDMETHODIMP CRtpBufferedListener::GetSessionMemberInfo(UINT ssrc, RtpSessionMemberInfo *pSessionMemberInfo, BOOL bIncludeSdesItems)
{
	return this->CRtpSocketBase::InternalGetSessionMemberInfo(ssrc, pSessionMemberInfo, bIncludeSdesItems);
}

STDMETHODIMP CRtpBufferedListener::SetPlayoutBufferGuid(LPGUID pPlayoutBufferGuid)
{
	CheckPointer(pPlayoutBufferGuid, E_POINTER);

	m_pPlayoutBufferClassFactory = NULL;

	HRESULT hr = CoGetClassObject(*pPlayoutBufferGuid, CLSCTX_INPROC, NULL, IID_IClassFactory, (void**)&m_pPlayoutBufferClassFactory);

	if (SUCCEEDED(hr))
	{
		m_pPlayoutBufferClassFactory->LockServer(TRUE);
	}
	
	return hr;
}

STDMETHODIMP CRtpBufferedListener::RaiseActiveRtpSourceAddedEvent(UINT ssrc)
{
	__raise ActiveSourceAdded(ssrc);
	return S_OK;
}

STDMETHODIMP CRtpBufferedListener::RaiseActiveRtpSourceDeletedEvent(UINT ssrc)
{
	__raise ActiveSourceRemoved(ssrc);
	return S_OK;
}

STDMETHODIMP CRtpBufferedListener::RaiseActiveRtpSourceChangedEvent(UINT ssrc, RTP_SESSION_MEMBER_EVENT_TYPE eventType)
{
	__raise ActiveSourceChanged(ssrc, eventType);
	return S_OK;
}

STDMETHODIMP CRtpBufferedListener::get_LocalSsrc(UINT* pVal)
{
	CheckPointer(pVal, E_POINTER);
	(*pVal) = m_ssrc;
	return S_OK;
}

STDMETHODIMP CRtpBufferedListener::put_LocalSsrc(UINT newVal)
{
	CheckPointer(newVal, E_INVALIDARG);
	m_ssrc = newVal;
	return S_OK;
}
