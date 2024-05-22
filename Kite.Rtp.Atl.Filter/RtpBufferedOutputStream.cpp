#include "stdafx.h"

#ifdef RTPLISTENERFILTER


#include "RtpListenerFilter.h"
#include "RtpBufferedOutputStream.h"

#include <dxerr9.h>

#define PAYLOAD_PACKTIZER 1
#define BUFFER_SIZE	4096

#define BUFFER_COUNT	100
#define BUFFER_SIZE_CONCATENATED	102400
#define TEMP_BUFFER_SIZE	(4096 * 16)	// 65k

CRtpBufferedOutputStream::CRtpBufferedOutputStream(CRtpBufferedListenerFilter *pParentFilter, HRESULT *phr, LPCWSTR pName)
: CBaseOutputPin(_T("Kite.Rtp.Atl.Filter.BufferedListener.TimedOutputPin"),
				 pParentFilter,
				 &m_critSect,
				 phr,
				 pName)
				 , m_cbBufferPrefix(0)
				 , m_pRtpBufferedListenerFilter(NULL)
				 , m_dwTimerId(0)
				 , m_uTimerResolution(0)
				 , m_uTimerDelay(0)

				 , m_dwDeliveryMode(RTP_BUFFERED_LISTENER_DELIVERYMODE_DELIVERYUNITS_CONCATENATED|RTP_BUFFERED_LISTENER_DELIVERYMODE_REFIXED_BY_PAYLOADHEADER)
				 //, m_uRtpPayloadHeaderSize(RTP_PAYLOAD_HEADER_H263_MODE_A)
				 , m_ssrcOfSelectedSource(0)

				 , m_uStreamOffset(0)
				 , m_uMaxStreamOffset(0)

				 , m_pExpectedMediaType(NULL)
{
	// TODO !!! entweder hier und im Codec ReceiveMultiple m_pInputPin->ReceiveMultiple();
	// oder den RTP Payload Header als Prefix vor den Buffer???
	if ((pParentFilter == NULL) || (pParentFilter->m_pRtpListener == NULL) || (pParentFilter->m_pRtpBufferedListener == NULL))
	{
		(*phr) = E_INVALIDARG;
		return;
	}

	m_pRtpBufferedListenerFilter = pParentFilter;
	m_pRtpListener = m_pRtpBufferedListenerFilter->m_pRtpListener;
	m_pRtpBufferedListener = m_pRtpBufferedListenerFilter->m_pRtpBufferedListener;

	MMRESULT mmres = TIMERR_NOERROR;
	m_uTimerResolution = 0;

	TIMECAPS timeCaps;
	if (TIMERR_NOERROR != timeGetDevCaps(&timeCaps, sizeof(TIMECAPS)))
	{
		(*phr) = E_FAIL;
	}
	m_uTimerResolution = timeCaps.wPeriodMin;
	mmres = timeBeginPeriod(m_uTimerResolution);	

	if (mmres == TIMERR_NOCANDO)
	{
		(*phr) = E_FAIL;
	}

	// add ourselves to the outpins of the filter
	(*phr) = pParentFilter->AddPin(this);
	_RPT2(_CRT_WARN, "ctor of CRtpBufferedOutputStream has added the newly created intsance to the parent filters Coll, PinCount is now: %d, HR was: 0x%x\r\n", pParentFilter->m_uPinCount, *phr);
}

CRtpBufferedOutputStream::~CRtpBufferedOutputStream()
{
	MMRESULT mmres;
	if (m_dwTimerId)
	{
		mmres = timeKillEvent(m_dwTimerId);		
		m_dwTimerId = 0;
		ASSERT(mmres == MMSYSERR_NOERROR);

		if (!MyTimeKillSynchronousFlagAvailable()) Sleep(m_uTimerDelay + 10);
	}

	mmres = timeEndPeriod(m_uTimerResolution);
	m_uTimerResolution = 0;
	ASSERT(mmres == MMSYSERR_NOERROR);
}

STDMETHODIMP CRtpBufferedOutputStream::GetBufferPrefix(INT *pcbPrefix)
{
	CheckPointer(pcbPrefix, E_POINTER);
	// Sequence number is prepended
	(*pcbPrefix) = 4;
	return S_OK;
}

// Must override
HRESULT CRtpBufferedOutputStream::DecideBufferSize(
	IMemAllocator *pMemAllocator,
	ALLOCATOR_PROPERTIES *pAllocatorProperties
	)
{
	CheckPointer(pMemAllocator, E_POINTER);
	CheckPointer(pAllocatorProperties, E_POINTER);

	ALLOCATOR_PROPERTIES actual;
	ZeroMemory(&actual, sizeof(ALLOCATOR_PROPERTIES));

#define _27082003	1
#if !_27082003
	pAllocatorProperties->cbAlign = 1;
	pAllocatorProperties->cBuffers = ((m_dwDeliveryMode & RTP_BUFFERED_LISTENER_DELIVERYMODE_DELIVERYUNITS_MULTIPLE_SAMPLES) ? BUFFER_COUNT : 1); 
	pAllocatorProperties->cbPrefix = 0;// ((m_dwDeliveryMode & RTP_BUFFERED_LISTENER_DELIVERYMODE_REFIXED_BY_PAYLOADHEADER) ? m_uRtpPayloadHeaderSize : 0);
	pAllocatorProperties->cbBuffer = ((m_dwDeliveryMode & RTP_BUFFERED_LISTENER_DELIVERYMODE_DELIVERYUNITS_CONCATENATED) ? BUFFER_SIZE_CONCATENATED : BUFFER_SIZE);
#else
	pAllocatorProperties->cbAlign = 1;
	//pAllocatorProperties->cBuffers = 50; // ((m_dwDeliveryMode & RTP_BUFFERED_LISTENER_DELIVERYMODE_DELIVERYUNITS_MULTIPLE_SAMPLES) ? BUFFER_COUNT : 1); 
	pAllocatorProperties->cBuffers = BUFFER_COUNT;
	pAllocatorProperties->cbPrefix = 4; //sequence  ((m_dwDeliveryMode & RTP_BUFFERED_LISTENER_DELIVERYMODE_REFIXED_BY_PAYLOADHEADER) ? m_uRtpPayloadHeaderSize : 0);
	pAllocatorProperties->cbBuffer = 4096; // sollte passen((m_dwDeliveryMode & RTP_BUFFERED_LISTENER_DELIVERYMODE_DELIVERYUNITS_CONCATENATED) ? BUFFER_SIZE_CONCATENATED : BUFFER_SIZE);
#endif

	HRESULT hr = pMemAllocator->SetProperties(pAllocatorProperties, &actual);

	if (SUCCEEDED(hr))
	{
		if (	
			(actual.cbAlign <= pAllocatorProperties->cbAlign)
			&& (actual.cbBuffer >= pAllocatorProperties->cbBuffer)
			&& (actual.cbPrefix >= pAllocatorProperties->cbPrefix)
			&& (actual.cBuffers >= pAllocatorProperties->cBuffers)
			)
		{
			m_cbBufferPrefix = actual.cbPrefix;
			return S_OK;
		}

		return E_FAIL;
	}

	return hr;
}

HRESULT CRtpBufferedOutputStream::CheckMediaType(
	const CMediaType *pMediaType
	)
{
	CheckPointer(pMediaType, E_POINTER);

	if (IsEqualGUID(pMediaType->majortype, MEDIATYPE_Audio))
	{
		m_dwDeliveryMode &= RTP_BUFFERED_LISTENER_DELIVERYMODE_DELIVERYUNITS_MULTIPLE_SAMPLES;
		return S_OK;
	}

	if (IsEqualGUID(pMediaType->majortype, MEDIATYPE_Video))
	{
		// Erase right bit
		m_dwDeliveryMode &= 0xFF00;

		if (
			(IsEqualGUID(pMediaType->subtype, MEDIATYPE_H263))
			|| (IsEqualGUID(pMediaType->subtype, MEDIATYPE_h263))
			)
		{
			m_dwDeliveryMode &= RTP_BUFFERED_LISTENER_DELIVERYMODE_DELIVERYUNITS_CONCATENATED;
			//m_uRtpPayloadHeaderSize = RTP_PAYLOAD_HEADER_H263_MODE_A;

			return S_OK;
		}
		else if
			(
			(IsEqualGUID(pMediaType->subtype, MEDIATYPE_H26P))
			|| (IsEqualGUID(pMediaType->subtype, MEDIATYPE_h26p))
			)
		{
			m_dwDeliveryMode &= RTP_BUFFERED_LISTENER_DELIVERYMODE_DELIVERYUNITS_CONCATENATED;
			//m_uRtpPayloadHeaderSize = RTP_PAYLOAD_HEADER_H26P;

			return S_OK;
		}
		else if
			(
			(IsEqualGUID(pMediaType->subtype, MEDIATYPE_H263_RTP))
			|| (IsEqualGUID(pMediaType->subtype, MEDIATYPE_h263_rtp))
			)
		{
			m_dwDeliveryMode &= RTP_BUFFERED_LISTENER_DELIVERYMODE_DELIVERYUNITS_MULTIPLE_SAMPLES;
			//m_uRtpPayloadHeaderSize = RTP_PAYLOAD_HEADER_H263_MODE_A;

			return S_OK;
		}
		else if (
			(IsEqualGUID(pMediaType->subtype, MEDIATYPE_H26P_RTP))
			|| (IsEqualGUID(pMediaType->subtype, MEDIATYPE_h26p_rtp))
			)
		{
			m_dwDeliveryMode &= RTP_BUFFERED_LISTENER_DELIVERYMODE_DELIVERYUNITS_MULTIPLE_SAMPLES;
			//m_uRtpPayloadHeaderSize = RTP_PAYLOAD_HEADER_H26P;

			return S_OK;
		}

// #define PAYLOAD_PACKTIZER 1
#if PAYLOAD_PACKTIZER
		else if (m_pRtpBufferedListenerFilter && m_pRtpBufferedListenerFilter->m_pRtpPayloadPacketizer)
		{
			// Die Guid muss explizit im Filter gesetzt werden
			// Guids 

		}
#endif
	}

	return VFW_E_TYPE_NOT_ACCEPTED;
}

HRESULT CRtpBufferedOutputStream::GetMediaType(
	int iPosition,
	CMediaType *pMediaType
	)
{
	if (iPosition < 0) return E_INVALIDARG;

	CheckPointer(pMediaType, E_POINTER);

	if (m_pRtpBufferedListenerFilter->m_pOutputMediaType)
	{
		if (iPosition > 0) return VFW_S_NO_MORE_ITEMS;

		CopyMediaType(pMediaType, m_pRtpBufferedListenerFilter->m_pOutputMediaType);

		return S_OK;
	}
	else
	{
		BOOL bOk_But_Should_Not_Happen = FALSE;
		ASSERT(bOk_But_Should_Not_Happen);
		if (m_pExpectedMediaType)
		{
			pMediaType = m_pExpectedMediaType;
			return S_OK;
		}

		if (iPosition < 0) return E_INVALIDARG;
		if (iPosition > 4) return VFW_S_NO_MORE_ITEMS;


		INT width[] =
		{
			352,
			176,
			128,
			704,
			1408
		};

		INT height[] =
		{
			288,
			144,
			96,
			576,
			1152
		};

		return FillMediaTypeStruct(
			pMediaType, 
			MEDIATYPE_Video,
			MEDIATYPE_H263_RTP, // TODO h�ngt vom konfigurierten Format ab
			FORMAT_VideoInfo,
			MEDIATYPE_H263_RTP.Data1,
			width[iPosition % 5], 
			height[iPosition % 5], 
			m_pRtpBufferedListenerFilter->m_uRtpBitrate,
			m_pRtpBufferedListenerFilter->m_uTimePerFrame);
	}
	return S_OK;
}

HRESULT CRtpBufferedOutputStream::SetMediaType(
	const CMediaType *pMediaType
	)
{
	CheckPointer(pMediaType, E_POINTER);

	return S_OK;
}

HRESULT CRtpBufferedOutputStream::Active(void)
{
	DXTRACE_MSG("CRtpBufferedOutputStream::Active \r\n");

	HRESULT hr = S_OK;


	if (m_pFilter->IsActive())
	{
		return S_FALSE;
	}

	if (!IsConnected())
	{
		return S_OK;
	}

	hr = CBaseOutputPin::Active();
	if (FAILED(hr)) 
	{
		return hr;
	}

	return S_OK;
}

HRESULT CRtpBufferedOutputStream::Inactive(void)
{

	HRESULT hr;

	// do nothing if not connected - its ok not to connect to
	// all pins of a source filter
	if (!IsConnected()) 
	{
		return NOERROR;
	}

	// !!! need to do this before trying to stop the thread, because
	// we may be stuck waiting for our own allocator!!!

	hr = CBaseOutputPin::Inactive();  // call this first to Decommit the allocator
	if (FAILED(hr)) 
	{
		return hr;
	}

	if (m_dwTimerId)
	{
		MMRESULT mmres = timeKillEvent(m_dwTimerId);
		m_dwTimerId = 0;
	}

	return S_OK;
}

HRESULT CRtpBufferedOutputStream::Run(REFERENCE_TIME tStart)
{
	HRESULT hr = S_OK; 

	if (m_ssrcOfSelectedSource == 0) return S_FALSE;

	ASSERT(m_pRtpBufferedListenerFilter);
	ASSERT((m_pRtpBufferedListenerFilter->m_uTimePerFrame / 10000) > 30);
	ASSERT((m_pRtpBufferedListenerFilter->m_uTimePerFrame / 10000) <= 1000);

	m_uTimerDelay = (m_pRtpBufferedListenerFilter->m_uTimePerFrame / 10000);//  (UINT)(1000 / m_pRtpBufferedListenerFilter->m_uFramesPerSecondCalculated);

	if (m_pRtpBufferedListenerFilter && m_pRtpBufferedListenerFilter->m_pRtpPayloadPacketizer)
	{
		m_dwTimerId = timeSetEvent(
			m_uTimerDelay, m_uTimerResolution, 
			(LPTIMECALLBACK)CRtpBufferedOutputStream::TimeCallbackWithRtpPayloadPacketizer, (DWORD_PTR)this, 
			(MyTimeKillSynchronousFlagAvailable() ? TIME_PERIODIC|TIME_CALLBACK_FUNCTION|TIME_KILL_SYNCHRONOUS : TIME_PERIODIC|TIME_CALLBACK_FUNCTION));

	}
	else
	{
		m_dwTimerId = timeSetEvent(
			m_uTimerDelay, m_uTimerResolution, 
			(LPTIMECALLBACK)CRtpBufferedOutputStream::TimeCallback, (DWORD_PTR)this, 
			(MyTimeKillSynchronousFlagAvailable() ? TIME_PERIODIC|TIME_CALLBACK_FUNCTION|TIME_KILL_SYNCHRONOUS : TIME_PERIODIC|TIME_CALLBACK_FUNCTION));

	}
	ASSERT(m_dwTimerId != 0);
	m_dwStartTime = timeGetTime();

	Beep(800, 230);
	DXTRACE_MSG("CRtpBufferedOutputStream::Run TIMER STARTED \r\n");

	return (m_dwTimerId == MMSYSERR_NOERROR) ? S_OK : E_FAIL;
}
//////////////////////////////////////////////////////////////////////////
// Kein Packetizer
void CALLBACK CRtpBufferedOutputStream::TimeCallback(UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2)
{
	ASSERT(dwUser);
	((CRtpBufferedOutputStream*)dwUser)->InstanceTimeCallback(uTimerID, uMsg, dwUser, dw1, dw2);
}

// Kopiere alle samples in einen Puffer, liefere diesen aus
void CALLBACK CRtpBufferedOutputStream::InstanceTimeCallback(UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2)
{
	// Fetch DeliveryUnit from RtpBufferedListener
	ASSERT(m_pRtpBufferedListenerFilter);
	ASSERT(m_pRtpListener);
	ASSERT(m_pRtpBufferedListener);

	if (m_ssrcOfSelectedSource == 0) return;

	RtpParsedPacket **ppParsedPackets = NULL;
	UINT cParsedPackets = 0;

	HRESULT hr = m_pRtpBufferedListener->GetDeliveryUnit(m_ssrcOfSelectedSource, &ppParsedPackets, &cParsedPackets);

	if (SUCCEEDED(hr))
	{
#define _27082003 1
#if _27082003
		if (hr == S_OK)
		{
			if (cParsedPackets > 0)
			{
				IMediaSample** ppMediaSample = (IMediaSample**)SAFE_ALLOC(cParsedPackets * sizeof(IMediaSample*));
				
				if (ppMediaSample == NULL)
				{
					return /*E_OUTOFMEMORY*/;
				}

				BYTE *pCurrentSampleBuffer = NULL;
				INT cbCurrentSampleBuffer = 0;
				UINT uBaseSequence = ppParsedPackets[0]->seqNum;
				BOOL bMarker = FALSE;

				LONGLONG tMediaStart = ppParsedPackets[0]->timestamp;
				LONGLONG tMediaEnd = tMediaStart;

				for (UINT uCurrentPacket = 0; uCurrentPacket < cParsedPackets; uCurrentPacket++)
				{	
					 hr = GetDeliveryBuffer(&(ppMediaSample[uCurrentPacket]), NULL, NULL, 0);

					 if (FAILED(hr))
					 {
						 ASSERT(0);
						 goto cleanup;
					 }

					 hr = ppMediaSample[uCurrentPacket]->GetPointer(&pCurrentSampleBuffer);
					 if (FAILED(hr))
					 {
						 ASSERT(0);
						 goto cleanup;
					 }

					 // Copy Buffer
					 ASSERT(ppParsedPackets[uCurrentPacket]->cbData <= ppMediaSample[uCurrentPacket]->GetSize());

					 CopyMemory(pCurrentSampleBuffer, ppParsedPackets[uCurrentPacket]->pData, ppParsedPackets[uCurrentPacket]->cbData);

					 ppMediaSample[uCurrentPacket]->SetActualDataLength(ppParsedPackets[uCurrentPacket]->cbData);

					 // Set SequenceNumber - ich sehe nicht, wenn am Anfang pakete fehlen
					 // Sequence Number wird lokal berechnet. Erstes Paket ist 0, dann inkrement um 1
					 *(((UINT*)pCurrentSampleBuffer) - 1) = ppParsedPackets[uCurrentPacket]->seqNum - uBaseSequence;

					 // Set Timing Infos ...
					 hr = ppMediaSample[uCurrentPacket]->SetMediaTime(&tMediaStart, &tMediaEnd);

					 bMarker = ppParsedPackets[uCurrentPacket]->marker;
					 SAFE_FREE(ppParsedPackets[uCurrentPacket]);
				}

				// Es kann nur das letzte Paket gemarkert sein (wenn es nicht fehlt)
				if (bMarker)
				{
					ppMediaSample[cParsedPackets - 1]->SetSyncPoint(TRUE);
				}

				SAFE_FREE(ppParsedPackets);

				long cProcessed = 0;
				hr = m_pInputPin->ReceiveMultiple(ppMediaSample, (long)cParsedPackets, &cProcessed);
				ASSERT(SUCCEEDED(hr));
				ASSERT(cProcessed == cParsedPackets);
				
cleanup:
				for (UINT uCurrentPacket = 0; uCurrentPacket < cParsedPackets; uCurrentPacket++)
				{
					SAFE_RELEASE(ppMediaSample[uCurrentPacket]);
				}
				SAFE_FREE(ppMediaSample);
				return;
			}
#else
			CComPtr<IMediaSample> pSample;

			// TODO Timing
			hr = GetDeliveryBuffer(&pSample,NULL,NULL,0);
			//JIF(hr);
			/*
			S_OK Success. 
			VFW_E_NOT_COMMITTED Allocator is decommitted. 
			VFW_E_TIMEOUT Timed out. 
			*/
			ASSERT(SUCCEEDED(hr) && pSample);

			BYTE* pSampleBuffer = NULL;
			BYTE* pSampleBufferPrefixPtr = NULL;
			hr = pSample->GetPointer(&pSampleBuffer);
			ASSERT(SUCCEEDED(hr));
			pSampleBufferPrefixPtr = pSampleBuffer - m_cbBufferPrefix;

			UINT cbSampleBuffer = (UINT)pSample->GetSize();
			UINT cbWritten = 0;

			ASSERT(!IsBadWritePtr(pSampleBufferPrefixPtr, m_cbBufferPrefix));
			ASSERT(!IsBadWritePtr(pSampleBuffer, cbSampleBuffer));

			LONGLONG tMediaStart = ppParsedPackets[0]->timestamp;
			LONGLONG tMediaEnd = tMediaStart;
			hr = pSample->SetMediaTime(&tMediaStart, &tMediaEnd);

			// Copy RtpPayload Header of first packet to Prefix
			if (m_cbBufferPrefix)
			{
				CopyMemory(pSampleBufferPrefixPtr, ppParsedPackets[0]->pData, m_cbBufferPrefix);
			}

			for (UINT u = 0; u < cParsedPackets; u++)
			{
				// Copy The Packet
				ASSERT(ppParsedPackets[u]);

				if (cbSampleBuffer < (cbWritten + ppParsedPackets[u]->cbData))
				{
					// Buffer too small
					ASSERT(0);
				}

				CopyMemory(
					pSampleBuffer + cbWritten, 
					(ppParsedPackets[u]->pData + m_cbBufferPrefix), 
					(ppParsedPackets[u]->cbData - m_cbBufferPrefix));

				cbWritten += ppParsedPackets[u]->cbData;

				SAFE_FREE(ppParsedPackets[u]);
			}

			hr = m_pInputPin->Receive(pSample);
#endif
		}
		else
		{
			// S_FALSE --> no samples in Buffer
		}
	}

cleanupOld:

	return;
}
//////////////////////////////////////////////////////////////////////////
// MIT Packetizer
void CALLBACK CRtpBufferedOutputStream::TimeCallbackWithRtpPayloadPacketizer(UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2)
{
	ASSERT(dwUser);
	((CRtpBufferedOutputStream*)dwUser)->InstanceTimeCallbackWithRtpPayloadPacketizer(uTimerID, uMsg, dwUser, dw1, dw2);
}

// Kopiere alle samples in einen Puffer, liefere diesen aus
void CALLBACK CRtpBufferedOutputStream::InstanceTimeCallbackWithRtpPayloadPacketizer(UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2)
{
	// Fetch DeliveryUnit from RtpBufferedListener
	ASSERT(m_pRtpBufferedListenerFilter);
	ASSERT(m_pRtpListener);
	ASSERT(m_pRtpBufferedListener);
	ASSERT(m_pRtpBufferedListenerFilter->m_pRtpPayloadPacketizer);

	if (m_ssrcOfSelectedSource == 0) return;

	RtpParsedPacket **ppParsedPackets = NULL;
	UINT cParsedPackets = 0;

	HRESULT hr = m_pRtpBufferedListener->GetDeliveryUnit(m_ssrcOfSelectedSource, &ppParsedPackets, &cParsedPackets);

	if (SUCCEEDED(hr))
	{
		if (hr == S_OK)
		{
			if (cParsedPackets > 0)
			{
				IMediaSample* pOutputMediaSample = NULL;
				hr = GetDeliveryBuffer(&pOutputMediaSample, NULL, NULL, /*Flags*/ 0);
				JIF(hr);

				BYTE* pOutputBuffer = NULL;
				UINT cbOutputBuffer = pOutputMediaSample->GetSize();
				hr = pOutputMediaSample->GetPointer(&pOutputBuffer);
				JIF(hr);

				BYTE** ppInputBuffers = new BYTE*[cParsedPackets];
				UINT *pcbBuffers = new UINT[cParsedPackets];
				UINT *pSeqNums = new UINT[cParsedPackets];
				
				for (UINT i = 0; i < cParsedPackets; i++)
				{
					if (ppParsedPackets[i] == NULL)
					{
						// cleanup;
						goto cleanup;
					}

					ppInputBuffers[i] = ppParsedPackets[i]->pData;
					pcbBuffers[i] = ppParsedPackets[i]->cbData;
					pSeqNums[i] = ppParsedPackets[i]->seqNum;
				}

				UINT cbSkippedOnDepacketization = 0;
				// [in,out] BYTE* pBuffer, [in,out] UINT *pcbBuffer, [out] UINT *pcbSkipped);
				hr = m_pRtpBufferedListenerFilter->m_pRtpPayloadPacketizer->Depacketize(
					ppInputBuffers, pcbBuffers, pSeqNums, 
					cParsedPackets, 
					pOutputBuffer, 
					&cbOutputBuffer,
					&cbSkippedOnDepacketization);
				JIF(hr);

				hr = pOutputMediaSample->SetActualDataLength(cbOutputBuffer);
				JIF(hr);

				// Deliver
				LONGLONG tMediaStart = ppParsedPackets[0]->timestamp;
				LONGLONG tMediaEnd = tMediaStart;

				// Set Timing Infos ...
				hr = pOutputMediaSample->SetMediaTime(&tMediaStart, &tMediaEnd);

				hr = m_pInputPin->Receive(pOutputMediaSample);
				ASSERT(SUCCEEDED(hr));
cleanup:
				for (UINT i = 0; i < cParsedPackets; i++)
				{
					SAFE_FREE(ppParsedPackets[i]);
				}
				SAFE_FREE(ppParsedPackets);
				SAFE_DELETE_ARRAY(ppInputBuffers);
				SAFE_DELETE_ARRAY(pcbBuffers);
				SAFE_DELETE_ARRAY(pSeqNums);

				return;
			}
		}
	}
	else
	{
		// S_FALSE --> no samples in Buffer
	}
}

//////////////////////////////////////////////////////////////////////////

HRESULT CRtpBufferedOutputStream::SelectSsrc(UINT ssrc)
{
	ASSERT(m_pRtpBufferedListenerFilter);

	if (m_ssrcOfSelectedSource == 0)
	{
		m_ssrcOfSelectedSource = ssrc;	
		Run(0);
	}

	m_ssrcOfSelectedSource = ssrc;

	_RPT4(_CRT_WARN, "CRtpBufferedOutputStream::SelectSsrc OutputPin Ptr 0x%x Pin Index %d is Switching from SSRC %d to SSRC %d",
		this,
		m_pRtpBufferedListenerFilter->FindPinNumber(this),
		m_ssrcOfSelectedSource,
		ssrc);

	return m_pRtpBufferedListenerFilter->m_pRtpListener->SubscribeSsrc(ssrc);

	return S_OK;
}
STDMETHODIMP CRtpBufferedOutputStream::DeselectSsrc()
{
	HRESULT hr = m_pRtpBufferedListenerFilter->m_pRtpListener->UnsubscribeSsrc(m_ssrcOfSelectedSource);
	m_ssrcOfSelectedSource = 0;
	// TODO kill timer;

	if (m_dwTimerId) timeKillEvent(m_dwTimerId);
	m_dwTimerId = 0;

	return hr;
}
STDMETHODIMP CRtpBufferedOutputStream::IsSubscribed(BOOL *pbSubscribed)
{
	CheckPointer(pbSubscribed, E_POINTER);
	(*pbSubscribed) = !!m_ssrcOfSelectedSource;
	return S_OK;
}

STDMETHODIMP CRtpBufferedOutputStream::GetMaxStreamOffset(
						   REFERENCE_TIME *prtMaxOffset
						   )
{
	CheckPointer(prtMaxOffset, E_POINTER);
	*prtMaxOffset = m_uMaxStreamOffset;
	return S_OK;
}

STDMETHODIMP CRtpBufferedOutputStream::SetMaxStreamOffset(
						   REFERENCE_TIME rtMaxOffset
						   )
{
	m_uMaxStreamOffset = rtMaxOffset;
	return S_OK;
}

STDMETHODIMP CRtpBufferedOutputStream::GetStreamOffset(
						REFERENCE_TIME *prtOffset
						)
{
	CheckPointer(prtOffset, E_POINTER);
	*prtOffset = m_uStreamOffset;
	return E_NOTIMPL;
}

STDMETHODIMP CRtpBufferedOutputStream::SetStreamOffset(
						REFERENCE_TIME rtOffset
						)
{
	// Latency + rtOffset == reale verz�gerung
	m_uStreamOffset = (UINT)rtOffset;
	return S_OK;
}

STDMETHODIMP CRtpBufferedOutputStream::GetPushSourceFlags(
						   ULONG *pFlags
						   )
{
	CheckPointer(pFlags, E_POINTER);
	(*pFlags) = AM_PUSHSOURCECAPS_INTERNAL_RM;
	return S_OK;
}

STDMETHODIMP CRtpBufferedOutputStream::SetPushSourceFlags(
						   ULONG Flags
						   )
{
	return E_NOTIMPL;
}
// IAMLatency via IAMPushSource
STDMETHODIMP CRtpBufferedOutputStream::GetLatency(
					  REFERENCE_TIME *prtLatency
					  )
{
	CheckPointer(prtLatency, E_POINTER);
	// Hav to select a source first
	CheckPointer(m_ssrcOfSelectedSource, E_UNEXPECTED);

	// 1 Frame puffern bei 30 fps --> 33 ms latency --> 33 * 10000 Latency
	if (m_pRtpBufferedListener == NULL) return E_UNEXPECTED;
	UINT uBufferedListenerLatency = 0;
	HRESULT hr = m_pRtpBufferedListener->GetJitterBufferLatency(m_ssrcOfSelectedSource, &uBufferedListenerLatency);
	(*prtLatency) = uBufferedListenerLatency;
	return hr;
}


STDMETHODIMP CRtpBufferedOutputStream::NonDelegatingQueryInterface(REFIID riid, void **ppVoid)
{
	if (IsEqualGUID(riid, IID_IAMLatency))
	{
		return GetInterface((IAMLatency*)this, ppVoid);
	}

	if (IsEqualGUID(riid, IID_IAMPushSource))
	{
		return GetInterface((IAMPushSource*)this, ppVoid);
	}

	if (IsEqualGUID(riid, IID_IRtpListenerOutputPin))
	{
		return GetInterface((IRtpListenerOutputPin*)this, ppVoid);
	}

	return CBaseOutputPin::NonDelegatingQueryInterface(riid, ppVoid);
}

STDMETHODIMP_(ULONG) CRtpBufferedOutputStream::NonDelegatingRelease(void)
{
	ULONG uRefCount = CBaseOutputPin::NonDelegatingRelease();

	return uRefCount;
}

STDMETHODIMP CRtpBufferedOutputStream::GetSsrc(UINT *puSsrc)
{
	CheckPointer(puSsrc, E_POINTER);
	if (m_ssrcOfSelectedSource != 0)
	{
		*puSsrc = m_ssrcOfSelectedSource;
		return S_OK;
	}

	return S_FALSE;
}

#endif