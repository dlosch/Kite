#include "StdAfx.h"
#include "Rtpuuids.h"
#include "RtpRendererFilter.h"

#include <atlbase.h>

#include <dxerr9.h>
#pragma comment(lib, "dxerr9")

#ifndef AF_INET
#	define AF_INET	2
#	define AF_INET6 23
#endif

#define PAYLOAD_PACKTIZER 1

CRtpRendererFilter::CRtpRendererFilter(LPUNKNOWN pUnk, HRESULT *phr)
: CBaseRenderer(CLSID_RtpRenderer, // CLSID for this renderer
			  _T("Kite.Rtp.Atl.Filter.Renderer"),         // Debug ONLY description
			  pUnk,       // Aggregated owner object
			  phr)       // General OLE return code
		  , m_szRemoteAddress(NULL)
		, m_uRemotePort(0)
		, m_szLocalAddress(NULL)
		, m_uLocalPort(0)
		, m_ttl(AF_INET)

		//m_szCname[255];
		, m_uTimePerAduNanos(1000 * 10000 / 10)
		, m_uTimestampIncrementPerAdu(90000 / 10)
		, m_uRtpSessionBandwidth(128000)
		, m_payloadType(0x22) // H.263
		, m_bIsFirstSample(TRUE)
		, m_lFirstSampleStartTime(0)

		, m_pRtpPayloadPacketizer(NULL)
		, m_pRtpSenderStats(NULL)
{
	ZeroMemory(m_szCname, sizeof(WCHAR) * 255);
	HRESULT hr = S_OK;
}

CRtpRendererFilter::~CRtpRendererFilter(void)
{
	ASSERT(m_pRtpRendererControl);
	if (m_pRtpRendererControl)
	m_pRtpRendererControl->Stop();

	SAFE_RELEASE(m_pRtpPayloadPacketizer);
}

CUnknown * WINAPI CRtpRendererFilter::CreateInstance(LPUNKNOWN pUnk, HRESULT *phr)
{
	CRtpRendererFilter* pInstance = new CRtpRendererFilter(pUnk, phr);

	if (pInstance == NULL)
	{
		(*phr) = E_OUTOFMEMORY;
		return NULL;
	}

	return pInstance;
}

STDMETHODIMP CRtpRendererFilter::NonDelegatingQueryInterface(REFIID riid, void **ppVoid)
{
	if (IsEqualGUID(riid, IID_IRtpRendererFilterConfiguration))
	{
		return GetInterface((IRtpRendererFilterConfiguration*)this, ppVoid);
	}

	//if (IsEqualGUID(riid, IID_IRtpRendererFilter))
	//{
	//	return GetInterface((IRtpRendererFilter*)this, ppVoid);
	//}

	return CBaseRenderer::NonDelegatingQueryInterface(riid, ppVoid);
}

STDMETHODIMP_(ULONG) CRtpRendererFilter::NonDelegatingRelease(void)
{
	return CBaseRenderer::NonDelegatingRelease();
}

//////////////////////////////////////////////////////////////////////////
HRESULT CRtpRendererFilter::CheckMediaType(const CMediaType *pMediaType)
{
	CheckPointer(pMediaType, E_POINTER);

	// MediaType: has to be "PPRP" - Subtype or any payload type that has 0001 as Data2

	if (IsEqualGUID(pMediaType->majortype, MEDIATYPE_Video))
	{
		// My own Generic Rtp-Payload type (includes header)
		if (IsEqualGUID(MEDIASUBTYPE_PPRP, pMediaType->subtype))
		{
			return S_OK;
		}

		// Indicates RTP Capability on my types
		else if (pMediaType->subtype.Data2) //(pMediaType->subtype.Data2 == 0x0001)
		{
			return S_OK;
		}

		else if (m_pRtpPayloadPacketizer)
		{
			UINT cTypes = 0;
			HRESULT hr = m_pRtpPayloadPacketizer->get_GuidCount(&cTypes);

			if (SUCCEEDED(hr))
			{
				MyRegPinTypes *pMyRegPinTypes = new MyRegPinTypes[cTypes];

				__try
				{
					hr = m_pRtpPayloadPacketizer->GetGuids(pMyRegPinTypes);
					if (SUCCEEDED(hr))
					{
						for (INT currentMediaType = 0; currentMediaType < cTypes; currentMediaType++)
						{
							if (IsEqualGUID(pMyRegPinTypes[currentMediaType].clsMinorType, pMediaType->subtype))
							{
								return S_OK;
							}
						}
					}
				}
				__finally
				{
					delete [] pMyRegPinTypes;
				}
			}
		}
	}
	else if (IsEqualGUID(pMediaType->majortype, MEDIATYPE_Audio))
	{
		// My own Generic Rtp-Payload type (includes header)
		if (IsEqualGUID(MEDIASUBTYPE_PPRP, pMediaType->subtype))
		{
			return S_OK;
		}

		// Indicates RTP Capability on my types
		else if (pMediaType->subtype.Data2 == 0x0001)
		{
			return S_OK;
		}
		else
		{
			return S_OK;
		}

	}

	return S_FALSE;
}

HRESULT CRtpRendererFilter::DoRenderSample(IMediaSample *pMediaSample)
{
	if (m_pRtpRenderer == NULL) 
	{
		ATLTRACE2("!!!!!!!!!!!!!!!!!!!!!!!\r\n!!!!! Im RtpRendererFilter ist kein RtpRenderer gesetzt \r\n\r\n");
		return S_OK;
	}

	CheckPointer(pMediaSample, E_POINTER);
	CheckPointer(m_pRtpRenderer, E_UNEXPECTED);
	
	HRESULT hr = S_OK;

	LONGLONG lMediaTimeStart = 0, lMediaTimeEnd = 0;
	hr = pMediaSample->GetMediaTime(&lMediaTimeStart, &lMediaTimeEnd);
	
	// VFW_E_MEDIA_TIME_NOT_SET
	if (hr == VFW_E_MEDIA_TIME_NOT_SET)
	{
		LONGLONG lEndTime = 0;
		if (m_bIsFirstSample)
		{
			hr = pMediaSample->GetTime(&m_lFirstSampleStartTime, &lEndTime);
			lMediaTimeStart = 0;
			m_bIsFirstSample = FALSE;
		}
		else
		{
			LONGLONG lStart = 0;
			hr = pMediaSample->GetTime(&lStart, &lEndTime);
			lMediaTimeStart = ((lStart - m_lFirstSampleStartTime) / m_uTimePerAduNanos) * m_uTimestampIncrementPerAdu;
		}
	}

	BYTE* pDataBuffer = NULL;
	hr = pMediaSample->GetPointer(&pDataBuffer);

	LONG lActualDataLength = pMediaSample->GetActualDataLength();

	BOOL bMarker = (pMediaSample->IsSyncPoint() == S_OK);

#if PAYLOAD_PACKTIZER
	if (m_pRtpPayloadPacketizer)
	{
		BYTE** ppBuffers = NULL;
		UINT *pcbBuffers = NULL;
		UINT cBuffers = 0;

		hr = m_pRtpPayloadPacketizer->Packetize(pDataBuffer, lActualDataLength, &ppBuffers, &pcbBuffers, &cBuffers);

		if (FAILED(hr))
		{
			ASSERT(0);
		}
		else
		{
			if (hr == S_FALSE)
			{
				hr = m_pRtpRenderer->SendRtpPayloadData(bMarker, (UINT)(lMediaTimeStart & 0xFFFFFFFF), pDataBuffer, (UINT)lActualDataLength);
			}
			else
			{
				for (UINT currentBuffer = 0; currentBuffer < cBuffers; currentBuffer++)
				{
					hr = m_pRtpRenderer->SendRtpPayloadData(
						(currentBuffer + 1 == cBuffers), 
						(UINT)(lMediaTimeStart & 0xFFFFFFFF), 
						ppBuffers[currentBuffer],
						pcbBuffers[currentBuffer]);

					SAFE_FREE(ppBuffers[currentBuffer]);
				}

				SAFE_FREE(ppBuffers);
				SAFE_FREE(pcbBuffers);
			}
		}
	}
	else
#endif
	// Alles unter panamaischer Billigflagge verschiffen
	hr = m_pRtpRenderer->SendRtpPayloadData(bMarker, (UINT)(lMediaTimeStart & 0xFFFFFFFF), pDataBuffer, (UINT)lActualDataLength);

	// sich freuen ;-)))
	return hr;
}

//////////////////////////////////////////////////////////////////////////
HRESULT CRtpRendererFilter::ShouldDrawSampleNow(
							IMediaSample *pMediaSample,
							REFERENCE_TIME *pStartTime,
							REFERENCE_TIME *pEndTime
							)
{
	// always render immediately, or, how one guy would say:
	// I ain't no Ansel Adams - I am not waiting for the light!
	return S_OK;
}

HRESULT CRtpRendererFilter::OnStartStreaming(void)
{
	HRESULT hr = S_OK;

	if (m_pRtpRenderer == NULL) 
	{
		MessageBox(NULL, _T("Im RtpRendererFilter ist kein RtpRenderer gesetzt"), NULL, MB_OK);
		return S_OK;
	}


	ASSERT(m_pRtpRendererControl);
	CheckPointer(m_pRtpRendererControl, E_UNEXPECTED);
	hr = m_pRtpRendererControl->Start();

	return hr;
}

HRESULT CRtpRendererFilter::OnStopStreaming(void)
{
	return S_OK;
}

HRESULT CRtpRendererFilter::SetMediaType(
					 const CMediaType *pMediaType)
{
	CheckPointer(pMediaType, E_POINTER);

	LONG lSubType = pMediaType->subtype.Data1;
	switch(lSubType) 
	{
	case FOURCC_H263:
	case FOURCC_h263:
		m_payloadType = 0x22;
		break;
	case FOURCC_H26P:
	case FOURCC_h26p:
	case FOURCC_PPRP:
	default:
		{
			DXTRACE_MSG("FOURCC_PPRP - need to set Payload Type\r\n");
		}
	}

	return S_OK;
}

STDMETHODIMP CRtpRendererFilter::SetNetworkParameter(
							   LPWSTR szRemoteAddress, 
							   USHORT uRemotePort, 
							   LPWSTR szLocalInterface, 
							   USHORT uLocalPort,
							   INT ttl, 
							   LPWSTR szCname)
{
	CheckPointer(szRemoteAddress, E_POINTER);
	CheckPointer(uRemotePort, E_INVALIDARG);
	CheckPointer(szCname, E_POINTER);

	if (wcslen(szRemoteAddress) > 255) return E_INVALIDARG;
	if (szLocalInterface && wcslen(szLocalInterface) > 255) return E_INVALIDARG;
	if (szCname && wcslen(szCname) > 255) return E_INVALIDARG;

	if (m_szRemoteAddress) SAFE_FREE(m_szRemoteAddress);
	m_szRemoteAddress = (LPWSTR)SAFE_ALLOC(sizeof(WCHAR) * (wcslen(szRemoteAddress) + 1));
	wcscpy(m_szRemoteAddress, szRemoteAddress);

	if (szLocalInterface)
	{
		if (m_szLocalAddress) SAFE_FREE(m_szLocalAddress);
		m_szLocalAddress = (LPWSTR)SAFE_ALLOC(sizeof(WCHAR) * (wcslen(szRemoteAddress) + 1));
		wcscpy(m_szLocalAddress, szLocalInterface);
	}

	if(szCname) wcsncpy(m_szCname, szCname, 255);

	m_uRemotePort = uRemotePort;
	m_uLocalPort = uLocalPort;
	m_ttl = ttl;

	return m_pRtpRendererConfiguration->SetNetworkParameter(szRemoteAddress, uRemotePort, szLocalInterface, uLocalPort, ttl, szCname);
}

STDMETHODIMP CRtpRendererFilter::SetRtpParameter(BYTE payloadType)
{
	if (payloadType & (1 << 7)) return E_INVALIDARG;
	m_payloadType = payloadType;

	HRESULT hr = m_pRtpRendererConfiguration->SetPayloadType(m_payloadType);

	return hr;
}

STDMETHODIMP CRtpRendererFilter::SetRtcpParameter(BSTR lpcwstrName, BSTR lpcwstrEMail, BSTR lpcwstrPhone, BSTR lpcwstrLoc, BSTR lpcwstrTool, BSTR lpcwstrNote )
{
	// SdesItems
	m_rtcpName = CComBSTR(lpcwstrName);
	m_rtcpEMail = CComBSTR(lpcwstrEMail);
	m_rtcpPhone = CComBSTR(lpcwstrPhone);
	m_rtcpLoc = CComBSTR(lpcwstrLoc);
	m_rtcpTool = CComBSTR(lpcwstrTool);
	m_rtcpNote = CComBSTR(lpcwstrName);
	
	HRESULT hr = m_pRtpRendererConfiguration->SetRtcpParameter(
		m_rtcpName,
		m_rtcpEMail,
		m_rtcpPhone,
		m_rtcpLoc,
		m_rtcpTool,
		m_rtcpNote);

	return hr;
	// return m_pRtpRenderer->SetRtcpParameter(lpcwstrName, lpcwstrEMail, lpcwstrPhone, lpcwstrLoc, lpcwstrTool, lpcwstrNote);
}

STDMETHODIMP CRtpRendererFilter::SetRtpBandwidth(UINT uSessionBandwidth, BOOL bEnforce)
{
	m_uRtpSessionBandwidth = uSessionBandwidth;

	return S_OK;
}

STDMETHODIMP CRtpRendererFilter::SetProtocolMediaParameter(
									 // nanos per Frame duration
									 UINT uTimePerAduNanos, 
									 UINT uRtpTimestampIncrementPerFrame)
{
	if (uTimePerAduNanos <= 0 || uTimePerAduNanos > 10000000) return E_INVALIDARG; // min  1 fps
	if (uRtpTimestampIncrementPerFrame <= 0 || uRtpTimestampIncrementPerFrame > 90000) return E_INVALIDARG;
	
	m_uTimePerAduNanos = uTimePerAduNanos;
	m_uTimestampIncrementPerAdu = uRtpTimestampIncrementPerFrame;

	return S_OK;
}


STDMETHODIMP CRtpRendererFilter::SetRtpPayloadPacketizer(
								   IRtpPayloadPacketizer *pPacketizer)
{
	CheckPointer(pPacketizer, E_POINTER);
	
	SAFE_RELEASE(m_pRtpPayloadPacketizer);
	m_pRtpPayloadPacketizer = pPacketizer;
	m_pRtpPayloadPacketizer->AddRef();

	return S_OK;
}

STDMETHODIMP CRtpRendererFilter::ReserveNetworkAddress(/*[in]*/ LPWSTR szRemoteAddress, /*[in,out]*/ LPWSTR szLocalAddress, USHORT uMinLocalPort, USHORT uMaxLocalPort, LPWSTR szLocalAddressOut, INT cchLocal, USHORT *puLocal)
{
	return m_pRtpRendererConfiguration->ReserveNetworkAddress(szRemoteAddress, szLocalAddress, uMinLocalPort, uMaxLocalPort, szLocalAddressOut, cchLocal, puLocal);
}

STDMETHODIMP CRtpRendererFilter::GetNetworkParameter(
							   LPWSTR szRemoteAddress, INT cchRemoteAddress, USHORT *puRemotePort, 
							   LPWSTR szLocalInterface, INT cchLocalAddress, USHORT *puLocalPortBase, INT* pTtl)
{
	return m_pRtpRendererConfigurationOut->GetNetworkParameter(
		szRemoteAddress, cchRemoteAddress, puRemotePort, 
		szLocalInterface, cchLocalAddress, puLocalPortBase, pTtl);
}

STDMETHODIMP CRtpRendererFilter::GetSenderStatistics(UINT *pcPacketsSent, UINT *pcOctetsSent, UINT *pMillisecs)
{
	// return m_pRtpRendererStatistics->;
	return E_NOTIMPL;
}

STDMETHODIMP CRtpRendererFilter::GetStatisticsForReceiver(UINT ssrcRRSource, BYTE *pFractionLost, UINT *pcCumulativeNumberOfPacketsLost, UINT *pInterarrivalJitter)
{
	return E_NOTIMPL;	
}

STDMETHODIMP CRtpRendererFilter::GetPerformanceCounterPrefix(UINT ssrc, LPWSTR szPerfCounterPrefix, INT cchPerfCounterPrefix)
{
	return E_NOTIMPL;
}


STDMETHODIMP CRtpRendererFilter::SetRtpRenderer(IRtpRenderer *pRenderer)
{
	return AssignRtpRendererInstance(pRenderer);
}

STDMETHODIMP CRtpRendererFilter::AssignRtpRendererInstance(IRtpRenderer *pRenderer)
{
	CheckPointer(pRenderer, E_POINTER);
	m_pRtpRenderer = NULL;
	m_pRtpRendererConfiguration = NULL;
	m_pRtpRendererConfigurationOut = NULL;
	m_pRtpRendererControl = NULL;
	//m_pRtpSenderStats = NULL;

	HRESULT hr = S_OK;
	m_pRtpRenderer = pRenderer;
	
	hr = m_pRtpRenderer->QueryInterface(__uuidof(IRtpRendererConfiguration), (void**)&m_pRtpRendererConfiguration);
	VALHR(hr);
	
	hr = m_pRtpRenderer->QueryInterface(__uuidof(IRtpRendererConfigurationOut), (void**)&m_pRtpRendererConfigurationOut);
	VALHR(hr);
	
	hr = m_pRtpRenderer->QueryInterface(__uuidof(IRtpRendererControl), (void**)&m_pRtpRendererControl);
	VALHR(hr);

	return S_OK;
}