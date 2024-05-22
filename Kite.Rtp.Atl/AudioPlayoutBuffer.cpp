// AudioPlayoutBuffer.cpp : Implementation of CAudioPlayoutBuffer

#include "stdafx.h"
#include "AudioPlayoutBuffer.h"
#include ".\audioplayoutbuffer.h"


// CAudioPlayoutBuffer


STDMETHODIMP CAudioPlayoutBuffer::get_PayloadType(BYTE* pPayloadType)
{
	CheckPointer(pPayloadType, E_POINTER);
	(*pPayloadType) = m_payloadType;
	return S_OK;
}

STDMETHODIMP CAudioPlayoutBuffer::put_PayloadType(BYTE payloadType)
{
	if (payloadType > 127) return E_INVALIDARG;
	m_payloadType = payloadType;
	return S_OK;
}

STDMETHODIMP CAudioPlayoutBuffer::get_DueTime(UINT* pDueTimeMilliseconds)
{
	CheckPointer(pDueTimeMilliseconds, E_POINTER);
	(*pDueTimeMilliseconds) = (m_uTimePerFrameNanos / 10000);
	return S_OK;
}

STDMETHODIMP CAudioPlayoutBuffer::get_EventHandle(LONG_PTR** pEventHandle)
{
	CheckPointer(pEventHandle, E_POINTER);
	*pEventHandle = (LONG_PTR*)INVALID_HANDLE_VALUE;
	return S_OK;
}

// 08.10.2003
STDMETHODIMP CAudioPlayoutBuffer::get_BufferDurationMilliseconds(UINT* pVal)
{
	CheckPointer(pVal, E_POINTER);
	*pVal = m_tBufferDuration;
	return S_OK;
}

STDMETHODIMP CAudioPlayoutBuffer::put_BufferDurationMilliseconds(UINT newVal)
{
	if (newVal == 0 || newVal > 10000) return E_UNEXPECTED;
	CAutoLock lock(&m_critSectObjectLock);
	m_tBufferDuration = newVal;
	return S_OK;
}

STDMETHODIMP CAudioPlayoutBuffer::get_RtpTimestampIncrementPerSecond(UINT* pVal)
{
	CheckPointer(pVal, E_POINTER);
	*pVal = m_uTimestampIncrementPerSecond;
	return S_OK;
}

STDMETHODIMP CAudioPlayoutBuffer::put_RtpTimestampIncrementPerSecond(UINT newVal)
{
	CAutoLock lock(&m_critSectObjectLock);
	m_uTimestampIncrementPerSecond = newVal;
	return S_OK;
}

STDMETHODIMP CAudioPlayoutBuffer::get_TimePerSampleNanos(UINT* pVal)
{
	CheckPointer(pVal, E_POINTER);
	*pVal = m_uTimePerFrameNanos;
	return S_OK;
}

STDMETHODIMP CAudioPlayoutBuffer::put_TimePerSampleNanos(UINT newVal)
{
	if (newVal < 100000) return E_UNEXPECTED;
	CAutoLock lock(&m_critSectObjectLock);
	m_uTimePerFrameNanos = newVal;
	return S_OK;
}
