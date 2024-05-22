#ifndef RTPBUFFEREDOUTPUTSTREAM_H
#define RTPBUFFEREDOUTPUTSTREAM_H

class CRtpBufferedListenerFilter;

//////////////////////////////////////////////////////////////////////////


// In Byte
#define RTP_PAYLOAD_HEADER_H263_MODE_A 4
#define RTP_PAYLOAD_HEADER_H26P 2

class CRtpBufferedOutputStream
	: public CBaseOutputPin
	, public IAMPushSource 
	, public IRtpListenerOutputPin
{

public:
	CRtpBufferedOutputStream(CRtpBufferedListenerFilter *pParentFilter, HRESULT *phr, LPCWSTR pName);
	~CRtpBufferedOutputStream();

	//CSourceStream

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

	// Received Format
	CMediaType *m_pExpectedMediaType;
	// 7 Bits
	BYTE m_payloadType; 


	// Settings for Filter
	// DeliveryMode
	DWORD m_dwDeliveryMode;
	// UINT m_uRtpPayloadHeaderSize;

	DWORD m_dwStartTime;

	// Selected SSRC for which Frames are delivered
	UINT m_ssrcOfSelectedSource;

	// Parent Filter
	CRtpBufferedListenerFilter *m_pRtpBufferedListenerFilter;
	IRtpListener* m_pRtpListener;
	IRtpBufferedListener* m_pRtpBufferedListener;

	// Buffer-Prefix f�r DecideBufferSize (PayloadHeader)
	UINT m_cbBufferPrefix;

	DWORD m_dwTimerId;
	CCritSec m_critSect;

	// timer
	UINT m_uTimerResolution;
	UINT m_uTimerDelay;


	// IAMPushSource
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

	// IAMLatency via IAMPushSource
	STDMETHOD(GetLatency)(
		REFERENCE_TIME *prtLatency
		);

	UINT m_uStreamOffset;
	UINT m_uMaxStreamOffset;

	// COM Stuff
	STDMETHODIMP NonDelegatingQueryInterface(REFIID, void **);
	STDMETHODIMP_(ULONG) NonDelegatingRelease(void);
	DECLARE_IUNKNOWN;

	//////////////////////////////////////////////////////////////////////////
	// 
	STDMETHOD(SelectSsrc)(UINT ssrc);
	STDMETHOD(DeselectSsrc)();
	STDMETHOD(IsSubscribed)(BOOL*);

	// 	IRtpListenerOutputPin
	STDMETHOD(GetBufferPrefix)(INT *pcbPrefix);

	STDMETHOD(GetSsrc)(UINT *puSsrc);


	//////////////////////////////////////////////////////////////////////////
	//bool CanReconnectWhenActive(void) {return TRUE; }



};

#endif