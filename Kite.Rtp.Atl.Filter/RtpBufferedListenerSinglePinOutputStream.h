#pragma once
#ifndef CRTPBUFFEREDLISTENERSINGLEPINOUTPUTSTREAM_H
#define CRTPBUFFEREDLISTENERSINGLEPINOUTPUTSTREAM_H
#include <streams.h>

// #include "IRtpListenerFilter.h"

class CRtpListenerFilterSingleOutputPin;

class CRtpBufferedListenerSinglePinOutputStream 
	: public CBaseOutputPin
	, public IAMPushSource 
	, public IRtpListenerOutputPin
{
	REFERENCE_TIME m_tStart;
	UINT m_uStartTime;


public:
	CRtpBufferedListenerSinglePinOutputStream(CRtpListenerFilterSingleOutputPin *pFilter, HRESULT *phr, LPCWSTR pName);
	~CRtpBufferedListenerSinglePinOutputStream(void);

	// Must override
	HRESULT DecideBufferSize (IMemAllocator *pAlloc,
		ALLOCATOR_PROPERTIES *ppropInputRequest);
	// May override
	// CBasePin
	HRESULT Run(REFERENCE_TIME tStart);
	HRESULT Active(void);
	HRESULT Inactive(void);

	// CBAsePin
	HRESULT SetMediaType(
		const CMediaType *pMediaType
		);
	HRESULT GetMediaType(
		int iPosition,
		CMediaType *pMediaType
		);

	// CBasePin Must override
	HRESULT CheckMediaType(
		const CMediaType *pmt
		);

	// TIMER
	// Ohne PayloadPacketizer
	static void CALLBACK TimeCallback(UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2);
	void CALLBACK InstanceTimeCallback(UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2);

	// Mit PayloadPacketizer
	static void CALLBACK TimeCallbackWithRtpPayloadPacketizer(UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2);
	void CALLBACK InstanceTimeCallbackWithRtpPayloadPacketizer(UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2);

	//////////////////////////////////////////////////////////////////////////
	// Parent Filter
	CRtpListenerFilterSingleOutputPin *m_pParentFilter;
	
	DWORD m_dwDeliveryMode;

	DWORD m_dwStartTime;

	static DWORD WINAPI WorkerThreadProc(LPVOID lpInstance);
	DWORD WINAPI InstanceWorkerThreadProc();
	HANDLE m_hWorkerThread;
	DWORD m_dwWorkerThreadId;
	UINT m_uWorkerThreadIntervalMillis;
	BOOL m_bWorkerThreadAlive;
	BOOL m_bWorkerThreadActive;
	FLOAT m_fDxUtilTimer;
	HANDLE m_hEventWorkerThreadDied;

	HANDLE m_hPlayoutBufferEventHandle;

	UINT m_cbBufferPrefix;
	UINT m_cBuffers;
	UINT m_cbBuffer;

	CCritSec m_critSect;

	STDMETHOD(GetMaxStreamOffset)(
		REFERENCE_TIME *prtMaxOffset
		);
	STDMETHOD(SetMaxStreamOffset)(
		REFERENCE_TIME rtMaxOffset
		);

	STDMETHOD(GetStreamOffset)(
		REFERENCE_TIME *prtOffset
		);
	STDMETHOD(SetStreamOffset)(
		REFERENCE_TIME rtOffset
		);

	STDMETHOD(GetPushSourceFlags)(
		ULONG *pFlags
		);
	STDMETHOD(SetPushSourceFlags)(
		ULONG Flags
		);

	STDMETHOD(GetLatency)(
		REFERENCE_TIME *prtLatency
		);

	UINT m_uStreamOffset;
	UINT m_uMaxStreamOffset;

	STDMETHODIMP NonDelegatingQueryInterface(REFIID, void **);
	STDMETHODIMP_(ULONG) NonDelegatingRelease(void);
	DECLARE_IUNKNOWN;

	STDMETHOD(GetBufferPrefix)(INT *pcbPrefix);
};

#endif
