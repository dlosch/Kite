#ifdef  SOURCESTREAM
class CRtpBufferedSourceStream 
	: public CSourceStream
{
public:
	CRtpBufferedSourceStream(CRtpBufferedListenerFilter *pParentFilter, LPWSTR szPinName, HRESULT *phr);
	~CRtpBufferedSourceStream();

	// is nix com

	// Must override
	// if supports only MANY MediaType
	HRESULT GetMediaType(
		int iPosition,
		CMediaType *pMediaType
		);

	//// if supports only one MediaType
	//HRESULT GetMediaType(
	//	CMediaType *pMediaType
	//	);

	HRESULT DecideBufferSize(
		IMemAllocator *pAlloc,
		ALLOCATOR_PROPERTIES *ppropInputRequest
		);

	HRESULT FillBuffer(
		IMediaSample *pSample
		);

	// May override
	// possibly the 
	HRESULT CheckMediaType(
		const CMediaType *pMediaType
		);


	//////////////////////////////////////////////////////////////////////////
	// Methods for RtpSourceStream
	STDMETHOD(SelectSsrc)(UINT ssrc);

	// Parent Filter
	CRtpBufferedListenerFilter *m_pRtpBufferedListenerFilter;
	CComPtr<IRtpListener> m_pRtpListener;
	CComPtr<IRtpBufferedListener> m_pRtpBufferedListener;

	// Customized Threading			
	HANDLE m_hWaitableTimer;
	HRESULT OnThreadStartPlay(void);
	HRESULT DoBufferProcessingLoop(void);
	static VOID APIENTRY CALLBACK ApcTimerCallback(LPVOID lpArgToCompletionRoutine, DWORD dwTimerLowValue, DWORD dwTimerHighValue );


};
#endif
