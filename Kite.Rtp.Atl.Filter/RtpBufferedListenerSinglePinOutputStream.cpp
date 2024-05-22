#include "StdAfx.h"
#include ".\rtplistenerfiltersingleoutputpin.h"
#include ".\rtpbufferedlistenersinglepinoutputstream.h"
#include <objbase.h>

#include <dxerr9.h>

#define PAYLOAD_PACKTIZER 1

#define BUFFER_PREFIX	4
#define BUFFER_SIZE		(4096 * 3)
#define BUFFER_COUNT	64
#define BUFFER_SIZE_CONCATENATED	102400
#define TEMP_BUFFER_SIZE	(4096 * 16)	// 65k

CRtpBufferedListenerSinglePinOutputStream::CRtpBufferedListenerSinglePinOutputStream(
	CRtpListenerFilterSingleOutputPin *pParentFilter, 
	HRESULT *phr, 
	LPCWSTR pName)
		:  CBaseOutputPin(_T("Kite.Rtp.Atl.Filter.BufferedListener.TimedOutputPin"),
				  pParentFilter,
				  &m_critSect,
				  phr,
				  pName)
				  , m_cbBufferPrefix(BUFFER_PREFIX) // sequence number
				  , m_cBuffers(BUFFER_COUNT)
				  , m_cbBuffer(BUFFER_SIZE)

				  , m_pParentFilter(pParentFilter)


				  , m_dwDeliveryMode(RTP_BUFFERED_LISTENER_DELIVERYMODE_DELIVERYUNITS_CONCATENATED|RTP_BUFFERED_LISTENER_DELIVERYMODE_REFIXED_BY_PAYLOADHEADER)
				  // EventHandle des PLayoutBuffers
				  , m_hPlayoutBufferEventHandle(INVALID_HANDLE_VALUE)
				  , m_hWorkerThread(INVALID_HANDLE_VALUE)
				  , m_dwWorkerThreadId(0)
				  , m_uWorkerThreadIntervalMillis(100)
				  , m_bWorkerThreadAlive(TRUE)
				  , m_bWorkerThreadActive(FALSE)
				  , m_hEventWorkerThreadDied(INVALID_HANDLE_VALUE)
{
	if (pParentFilter == NULL)
	{
		*phr = E_POINTER;
		return;
	}

	m_hWorkerThread = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)CRtpBufferedListenerSinglePinOutputStream::WorkerThreadProc, this, CREATE_SUSPENDED, &m_dwWorkerThreadId);
	
	if (NULL == m_hWorkerThread)
	{
		*phr = E_FAIL;
		return;
	}

	m_hEventWorkerThreadDied = CreateEvent(NULL, FALSE, FALSE, NULL);
	if (NULL == m_hEventWorkerThreadDied)
	{
		CloseHandle(m_hWorkerThread);
		*phr = E_FAIL;
		return;
	}

}

CRtpBufferedListenerSinglePinOutputStream::~CRtpBufferedListenerSinglePinOutputStream(void)
{
	m_bWorkerThreadAlive = FALSE;

	if (m_hEventWorkerThreadDied != NULL && m_hEventWorkerThreadDied != INVALID_HANDLE_VALUE)
	{
		ResumeThread(m_hWorkerThread);

		DWORD dwRetVal = WaitForSingleObject(m_hEventWorkerThreadDied, 2000);

		if (dwRetVal == WAIT_OBJECT_0)
		{
			SAFE_CLOSE_HANDLE(m_hWorkerThread);
			m_dwWorkerThreadId = 0;
		}
	}

}

STDMETHODIMP CRtpBufferedListenerSinglePinOutputStream::GetBufferPrefix(INT *pcbPrefix)
{
	CheckPointer(pcbPrefix, E_POINTER);
	// Sequence number is prepended
	(*pcbPrefix) = m_cbBufferPrefix;
	return S_OK;
}

HRESULT CRtpBufferedListenerSinglePinOutputStream::DecideBufferSize(
	IMemAllocator *pMemAllocator,
	ALLOCATOR_PROPERTIES *pAllocatorProperties
	)
{
	CheckPointer(pMemAllocator, E_POINTER);
	CheckPointer(pAllocatorProperties, E_POINTER);
	CheckPointer(m_pParentFilter, E_UNEXPECTED);

	ALLOCATOR_PROPERTIES actual;
	ZeroMemory(&actual, sizeof(ALLOCATOR_PROPERTIES));

	pAllocatorProperties->cbAlign = 1;
	pAllocatorProperties->cBuffers = ((m_dwDeliveryMode & RTP_BUFFERED_LISTENER_DELIVERYMODE_DELIVERYUNITS_MULTIPLE_SAMPLES) ? m_cBuffers : 1); 
	pAllocatorProperties->cbPrefix = 4; //((m_dwDeliveryMode & RTP_BUFFERED_LISTENER_DELIVERYMODE_DELIVERYUNITS_MULTIPLE_SAMPLES) ? m_cbBufferPrefix : 1); 
	pAllocatorProperties->cbBuffer = ((m_dwDeliveryMode & RTP_BUFFERED_LISTENER_DELIVERYMODE_DELIVERYUNITS_CONCATENATED) ? BUFFER_SIZE_CONCATENATED : m_cbBuffer);

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

HRESULT CRtpBufferedListenerSinglePinOutputStream::CheckMediaType(
	const CMediaType *pMediaType
	)
{
	CheckPointer(pMediaType, E_POINTER);
	CheckPointer(m_pParentFilter, E_UNEXPECTED);

	if (IsEqualGUID(pMediaType->majortype, MEDIATYPE_Audio))
	{
		m_dwDeliveryMode &= RTP_BUFFERED_LISTENER_DELIVERYMODE_DELIVERYUNITS_CONCATENATED;
		return S_OK;
	}
	else if (IsEqualGUID(pMediaType->majortype, MEDIATYPE_Video))
	{
		m_dwDeliveryMode &= 0xFF00;

		if (
			(IsEqualGUID(pMediaType->subtype, MEDIATYPE_H263))
			|| (IsEqualGUID(pMediaType->subtype, MEDIATYPE_h263))
			)
		{
			m_dwDeliveryMode |= RTP_BUFFERED_LISTENER_DELIVERYMODE_DELIVERYUNITS_CONCATENATED;

			return S_OK;
		}
		else if
			(
			(IsEqualGUID(pMediaType->subtype, MEDIATYPE_H26P))
			|| (IsEqualGUID(pMediaType->subtype, MEDIATYPE_h26p))
			)
		{
			m_dwDeliveryMode |= RTP_BUFFERED_LISTENER_DELIVERYMODE_DELIVERYUNITS_CONCATENATED;
			//m_uRtpPayloadHeaderSize = RTP_PAYLOAD_HEADER_H26P;

			return S_OK;
		}
		else if
			(
			(IsEqualGUID(pMediaType->subtype, MEDIATYPE_H263_RTP))
			|| (IsEqualGUID(pMediaType->subtype, MEDIATYPE_h263_rtp))
			)
		{
			m_dwDeliveryMode |= RTP_BUFFERED_LISTENER_DELIVERYMODE_DELIVERYUNITS_MULTIPLE_SAMPLES;
			//m_uRtpPayloadHeaderSize = RTP_PAYLOAD_HEADER_H263_MODE_A;

			return S_OK;
		}
		else if (
			(IsEqualGUID(pMediaType->subtype, MEDIATYPE_H26P_RTP))
			|| (IsEqualGUID(pMediaType->subtype, MEDIATYPE_h26p_rtp))
			)
		{
			m_dwDeliveryMode |= RTP_BUFFERED_LISTENER_DELIVERYMODE_DELIVERYUNITS_MULTIPLE_SAMPLES;
			//m_uRtpPayloadHeaderSize = RTP_PAYLOAD_HEADER_H26P;

			return S_OK;
		}
		else if (
			(IsEqualGUID(pMediaType->subtype, MEDIATYPE_H263_2429_RTP))
			)
		{
			m_dwDeliveryMode |= RTP_BUFFERED_LISTENER_DELIVERYMODE_DELIVERYUNITS_MULTIPLE_SAMPLES;
			//m_uRtpPayloadHeaderSize = RTP_PAYLOAD_HEADER_H26P;

			return S_OK;
		}

		// #define PAYLOAD_PACKTIZER 1
#if PAYLOAD_PACKTIZER
		else if (m_pParentFilter && m_pParentFilter->m_pRtpPayloadPacketizer)
		{
			UINT cTypes = 0;
			HRESULT hr = m_pParentFilter->m_pRtpPayloadPacketizer->get_GuidCount(&cTypes);

			if (SUCCEEDED(hr))
			{
				MyRegPinTypes *pMyRegPinTypes = new MyRegPinTypes[cTypes];

				__try
				{
					hr = m_pParentFilter->m_pRtpPayloadPacketizer->GetGuids(pMyRegPinTypes);
					if (SUCCEEDED(hr))
					{
						for (INT currentMediaType = 0; currentMediaType < cTypes; currentMediaType++)
						{
							if (IsEqualGUID(pMyRegPinTypes[currentMediaType].clsMinorType, pMediaType->subtype))
							{
								m_dwDeliveryMode |= RTP_BUFFERED_LISTENER_DELIVERYMODE_DELIVERYUNITS_CONCATENATED;
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
#endif
	}
	
	//else
	{
		if (IsEqualGUID(m_pParentFilter->m_pOutputMediaType->majortype, pMediaType->majortype))
		{
			if (IsEqualGUID(m_pParentFilter->m_pOutputMediaType->subtype, pMediaType->subtype))
			{
				m_cbBuffer = pMediaType->lSampleSize > 0 ? pMediaType->lSampleSize * 2 : m_cbBuffer;
				m_dwDeliveryMode |= RTP_BUFFERED_LISTENER_DELIVERYMODE_DELIVERYUNITS_CONCATENATED;

				return S_OK;
			}
		}
	}

	return VFW_E_TYPE_NOT_ACCEPTED;
}

HRESULT CRtpBufferedListenerSinglePinOutputStream::GetMediaType(
	int iPosition,
	CMediaType *pMediaType
	)
{
	if (iPosition < 0) return E_INVALIDARG;

	CheckPointer(m_pParentFilter, E_UNEXPECTED);
	CheckPointer(pMediaType, E_POINTER);

	if (m_pParentFilter->m_pOutputMediaType)
	{
		if (iPosition > 0) return VFW_S_NO_MORE_ITEMS;

		CopyMediaType(pMediaType, m_pParentFilter->m_pOutputMediaType);

		return S_OK;
	}
	else
	{
		BOOL bOk_But_Should_Not_Happen = FALSE;
		ASSERT(bOk_But_Should_Not_Happen);

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
			128000, 100 * 10000);
	}
	return S_OK;
}

HRESULT CRtpBufferedListenerSinglePinOutputStream::SetMediaType(
	const CMediaType *pMediaType
	)
{
	CheckPointer(pMediaType, E_POINTER);
	CheckPointer(pMediaType, E_POINTER);
	CheckPointer(m_pParentFilter, E_UNEXPECTED);

	if (IsEqualGUID(pMediaType->majortype, MEDIATYPE_Audio))
	{
		m_dwDeliveryMode &= RTP_BUFFERED_LISTENER_DELIVERYMODE_DELIVERYUNITS_CONCATENATED;
		return S_OK;
	}
	else if (IsEqualGUID(pMediaType->majortype, MEDIATYPE_Video))
	{
		// Erase right bit
		m_dwDeliveryMode &= 0xFF00;

		if (
			(IsEqualGUID(pMediaType->subtype, MEDIATYPE_H263))
			|| (IsEqualGUID(pMediaType->subtype, MEDIATYPE_h263))
			)
		{
			m_dwDeliveryMode |= RTP_BUFFERED_LISTENER_DELIVERYMODE_DELIVERYUNITS_CONCATENATED;
			return S_OK;
		}
		else if
			(
			(IsEqualGUID(pMediaType->subtype, MEDIATYPE_H26P))
			|| (IsEqualGUID(pMediaType->subtype, MEDIATYPE_h26p))
			)
		{
			m_dwDeliveryMode |= RTP_BUFFERED_LISTENER_DELIVERYMODE_DELIVERYUNITS_CONCATENATED;
			return S_OK;
		}
		else if
			(
			(IsEqualGUID(pMediaType->subtype, MEDIATYPE_H263_RTP))
			|| (IsEqualGUID(pMediaType->subtype, MEDIATYPE_h263_rtp))
			)
		{
			m_dwDeliveryMode |= RTP_BUFFERED_LISTENER_DELIVERYMODE_DELIVERYUNITS_MULTIPLE_SAMPLES;
			return S_OK;
		}
		else if (
			(IsEqualGUID(pMediaType->subtype, MEDIATYPE_H26P_RTP))
			|| (IsEqualGUID(pMediaType->subtype, MEDIATYPE_h26p_rtp))
			)
		{
			m_dwDeliveryMode |= RTP_BUFFERED_LISTENER_DELIVERYMODE_DELIVERYUNITS_MULTIPLE_SAMPLES;
			return S_OK;
		}
		else if (
			(IsEqualGUID(pMediaType->subtype, MEDIATYPE_H263_2429_RTP))
			)
		{
			m_dwDeliveryMode |= RTP_BUFFERED_LISTENER_DELIVERYMODE_DELIVERYUNITS_MULTIPLE_SAMPLES;
			return S_OK;
		}

		// #define PAYLOAD_PACKTIZER 1
#if PAYLOAD_PACKTIZER
		else if (m_pParentFilter && m_pParentFilter->m_pRtpPayloadPacketizer)
		{
			m_dwDeliveryMode |= RTP_BUFFERED_LISTENER_DELIVERYMODE_DELIVERYUNITS_CONCATENATED;
			return S_OK;
		}
#endif
	}
	else
	{
		if (IsEqualGUID(m_pParentFilter->m_pOutputMediaType->majortype, pMediaType->majortype))
		{
			if (IsEqualGUID(m_pParentFilter->m_pOutputMediaType->subtype, pMediaType->subtype))
			{
				m_cbBuffer = pMediaType->lSampleSize > 0 ? pMediaType->lSampleSize * 2 : m_cbBuffer;
				m_dwDeliveryMode |= RTP_BUFFERED_LISTENER_DELIVERYMODE_DELIVERYUNITS_CONCATENATED;

				return S_OK;
			}
		}
	}

	return S_OK;
}

// If you override this method, call the base-class method from your overriding method
HRESULT CRtpBufferedListenerSinglePinOutputStream::Active(void)
{
	DXTRACE_MSG("CRtpBufferedListenerSinglePinOutputStream::Active \r\n");

	HRESULT hr = S_OK;

	if (m_pFilter->IsActive())
	{
		return S_FALSE;
	}

	if (!IsConnected())
	{
		return S_OK;
	}

	if (!m_pParentFilter)
	{
		ASSERT(m_pParentFilter);
		return E_UNEXPECTED;
	}

	if (!m_pParentFilter->m_pRtpPlayoutBuffer)
	{
		ASSERT(m_pParentFilter->m_pRtpPlayoutBuffer);
		return E_UNEXPECTED;
	}
	
	hr = m_pParentFilter->m_pRtpPlayoutBuffer->get_DueTime(&m_uWorkerThreadIntervalMillis);
	VALHR(hr);
	if (m_uWorkerThreadIntervalMillis == 0 || m_uWorkerThreadIntervalMillis > 1000) m_uWorkerThreadIntervalMillis = 100;
	
	hr = m_pParentFilter->m_pRtpPlayoutBuffer->get_EventHandle((LONG_PTR**)&m_hPlayoutBufferEventHandle);
	VALHR(hr);
	if (m_hPlayoutBufferEventHandle == NULL || m_hPlayoutBufferEventHandle == INVALID_HANDLE_VALUE)
	{
		DXTRACE_MSG("(m_hPlayoutBufferEventHandle == NULL || m_hPlayoutBufferEventHandle == INVALID_HANDLE_VALUE)");
	}

	if (!m_bWorkerThreadActive)
	{
		m_bWorkerThreadActive = TRUE;
		m_bWorkerThreadAlive = TRUE;
		DXTRACE_MSG("SuspendThread(m_hWorkerThread);");
		DWORD dwResume = ResumeThread(m_hWorkerThread);
		ASSERT(dwResume == 1);
	}

	//////////////////////////////////////////////////////////////////////////
	
	hr = CBaseOutputPin::Active();
	if (FAILED(hr)) 
	{
		return hr;
	}

	return S_OK;
}

HRESULT CRtpBufferedListenerSinglePinOutputStream::Inactive(void)
{
	HRESULT hr;

	if (!IsConnected()) 
	{
		return NOERROR;
	}

	hr = CBaseOutputPin::Inactive();  // call this first to Decommit the allocator
	if (FAILED(hr)) 
	{
		return hr;
	}

	DXTRACE_MSG("SuspendThread(m_hWorkerThread);");
	SuspendThread(m_hWorkerThread);
	m_bWorkerThreadActive = FALSE;

	return S_OK;
}

HRESULT CRtpBufferedListenerSinglePinOutputStream::Run(REFERENCE_TIME tStart)
{
	HRESULT hr = S_OK; 

	m_tStart = tStart;
	m_uStartTime = timeGetTime();
	return /*(m_dwTimerId == MMSYSERR_NOERROR) ? S_OK : */E_FAIL;
}

void CALLBACK CRtpBufferedListenerSinglePinOutputStream::TimeCallback(UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2)
{
	ASSERT(dwUser);
	((CRtpBufferedListenerSinglePinOutputStream*)dwUser)->InstanceTimeCallback(uTimerID, uMsg, dwUser, dw1, dw2);
}


void CALLBACK CRtpBufferedListenerSinglePinOutputStream::InstanceTimeCallback(UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2)
{


	if (m_pParentFilter->m_ssrcOfSelectedSource == 0) return;

	RtpParsedPacket **ppParsedPackets = NULL;
	UINT cParsedPackets = 0;

	HRESULT hr = m_pParentFilter->m_pRtpPlayoutBuffer->DequeuePackets(&ppParsedPackets, &cParsedPackets);

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
				REFERENCE_TIME tReferenceTime = /*m_tStart + */((timeGetTime() - m_uStartTime) * 10000);
				REFERENCE_TIME tReferenceTimeEnd = tReferenceTime + (100 * 10000);

				tMediaStart = 0; tMediaEnd = 0;
				tReferenceTime = 0; tReferenceTimeEnd = 0;
				ZeroMemory(&tReferenceTime, sizeof(LONGLONG));
				ZeroMemory(&tReferenceTimeEnd, sizeof(LONGLONG));

				for (UINT uCurrentPacket = 0; uCurrentPacket < cParsedPackets; uCurrentPacket++)
				{	
					hr = GetDeliveryBuffer(&(ppMediaSample[uCurrentPacket]), NULL, NULL, 0);

					if (FAILED(hr))
					{
						//ASSERT(0);
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

					// TODO
					hr = ppMediaSample[uCurrentPacket]->SetTime(&tReferenceTime, &tReferenceTimeEnd);

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
				DXTRACE_MSG("VOR m_pInputPin->ReceiveMultiple\r\n");
				hr = m_pInputPin->ReceiveMultiple(ppMediaSample, (long)cParsedPackets, &cProcessed);
				DXTRACE_ERR("m_pInputPin->ReceiveMultiple", hr);
				//ASSERT(SUCCEEDED(hr));
				//ASSERT(cProcessed == cParsedPackets);

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
void CALLBACK CRtpBufferedListenerSinglePinOutputStream::TimeCallbackWithRtpPayloadPacketizer(UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2)
{
	ASSERT(dwUser);
	((CRtpBufferedListenerSinglePinOutputStream*)dwUser)->InstanceTimeCallbackWithRtpPayloadPacketizer(uTimerID, uMsg, dwUser, dw1, dw2);
}

// Kopiere alle samples in einen Puffer, liefere diesen aus
void CALLBACK CRtpBufferedListenerSinglePinOutputStream::InstanceTimeCallbackWithRtpPayloadPacketizer(UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2)
{
	// Fetch DeliveryUnit from RtpBufferedListener
	ASSERT(m_pParentFilter);
	ASSERT(m_pParentFilter->m_pRtpPayloadPacketizer);

	if (m_pParentFilter->m_ssrcOfSelectedSource == 0) return;

	RtpParsedPacket **ppParsedPackets = NULL;
	UINT cParsedPackets = 0;

	HRESULT hr = m_pParentFilter->m_pRtpPlayoutBuffer->DequeuePackets(&ppParsedPackets, &cParsedPackets);

	if (SUCCEEDED(hr))
	{
		// Liefere jedes RtpParsedPacket (optimierung: zusammenh�ngende Sequencenumbers k�nnen wir in ein Sample kopieren)
		//	als ein IMediaSample mit ReceiveMultiple aus
		if (hr == S_OK)
		{
			if (cParsedPackets > 0)
			{
				// Ausgabesample besorgen
				IMediaSample* pOutputMediaSample = NULL;
				// TODO timing
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
				hr = m_pParentFilter->m_pRtpPayloadPacketizer->Depacketize(
					ppInputBuffers, pcbBuffers, pSeqNums, 
					cParsedPackets, 
					pOutputBuffer, 
					&cbOutputBuffer,
					&cbSkippedOnDepacketization);
				JIF(hr);


				if (hr == S_FALSE)
				{
					ASSERT(cParsedPackets == 1 && pcbBuffers[0] < cbOutputBuffer);
					CopyMemory(pOutputBuffer, ppInputBuffers[0], pcbBuffers[0]);

					hr = pOutputMediaSample->SetActualDataLength(pcbBuffers[0]);
					JIF(hr);

				}
				else
				{
					hr = pOutputMediaSample->SetActualDataLength(cbOutputBuffer);
					JIF(hr);
				}

				// Deliver
				LONGLONG tMediaStart = ppParsedPackets[0]->timestamp;
				LONGLONG tMediaEnd = tMediaStart;

				// Set Timing Infos ...
				hr = pOutputMediaSample->SetMediaTime(&tMediaStart, &tMediaEnd);

				hr = m_pInputPin->Receive(pOutputMediaSample);
cleanup:
				ASSERT(SUCCEEDED(hr));
				// Pakete l�schen
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

STDMETHODIMP CRtpBufferedListenerSinglePinOutputStream::GetMaxStreamOffset(
	REFERENCE_TIME *prtMaxOffset
	)
{
	CheckPointer(prtMaxOffset, E_POINTER);
	*prtMaxOffset = m_uMaxStreamOffset;
	return S_OK;
}

STDMETHODIMP CRtpBufferedListenerSinglePinOutputStream::SetMaxStreamOffset(
	REFERENCE_TIME rtMaxOffset
	)
{
	m_uMaxStreamOffset = rtMaxOffset;
	return S_OK;
}

STDMETHODIMP CRtpBufferedListenerSinglePinOutputStream::GetStreamOffset(
	REFERENCE_TIME *prtOffset
	)
{
	CheckPointer(prtOffset, E_POINTER);
	*prtOffset = m_uStreamOffset;
	return E_NOTIMPL;
}

STDMETHODIMP CRtpBufferedListenerSinglePinOutputStream::SetStreamOffset(
	REFERENCE_TIME rtOffset
	)
{
	m_uStreamOffset = (UINT)rtOffset;
	return S_OK;
}

STDMETHODIMP CRtpBufferedListenerSinglePinOutputStream::GetPushSourceFlags(
	ULONG *pFlags
	)
{
	CheckPointer(pFlags, E_POINTER);
	(*pFlags) = AM_PUSHSOURCECAPS_INTERNAL_RM;
	return S_OK;
}

STDMETHODIMP CRtpBufferedListenerSinglePinOutputStream::SetPushSourceFlags(
	ULONG Flags
	)
{
	return E_NOTIMPL;
}

STDMETHODIMP CRtpBufferedListenerSinglePinOutputStream::GetLatency(
	REFERENCE_TIME *prtLatency
	)
{
	CheckPointer(prtLatency, E_POINTER);
	CheckPointer(m_pParentFilter->m_ssrcOfSelectedSource, E_UNEXPECTED);

	if (m_pParentFilter->m_pRtpBufferedListener == NULL) return E_UNEXPECTED;
	UINT uBufferedListenerLatency = 0;
	HRESULT hr = m_pParentFilter->m_pRtpPlayoutBuffer->GetLatency(&uBufferedListenerLatency);
	(*prtLatency) = uBufferedListenerLatency;
	return hr;
}

STDMETHODIMP CRtpBufferedListenerSinglePinOutputStream::NonDelegatingQueryInterface(REFIID riid, void **ppVoid)
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

STDMETHODIMP_(ULONG) CRtpBufferedListenerSinglePinOutputStream::NonDelegatingRelease(void)
{
	// Problem: wenn ich mich selber als EventReceiver an den RtpStack �bergebe, ist mein Refcount immer 1 ;-(
	ULONG uRefCount = CBaseOutputPin::NonDelegatingRelease();

	return uRefCount;
}

DWORD WINAPI CRtpBufferedListenerSinglePinOutputStream::WorkerThreadProc(LPVOID lpInstance)
{
	CoInitializeEx(0, COINIT_MULTITHREADED|COINIT_DISABLE_OLE1DDE|COINIT_SPEED_OVER_MEMORY);

	if (lpInstance)
	{
		return ((CRtpBufferedListenerSinglePinOutputStream*)lpInstance)->InstanceWorkerThreadProc();
	}

	return E_POINTER;
}

DWORD WINAPI CRtpBufferedListenerSinglePinOutputStream::InstanceWorkerThreadProc()
{
	UINT tStart = timeGetTime();
	UINT tNow = 0, tDiff = 0;
	UINT uElapsed = 0;

	m_uWorkerThreadIntervalMillis = 100;

	while (m_bWorkerThreadAlive)
	{

		if (m_pParentFilter->m_pRtpPayloadPacketizer)
		{
			InstanceTimeCallbackWithRtpPayloadPacketizer(0, 0, 0, 0, 0);
		}
		else
		{
			InstanceTimeCallback(0, 0, 0, 0, 0);
		}

		{
			Sleep(m_uWorkerThreadIntervalMillis);
		}
	}

	return 0;
}
