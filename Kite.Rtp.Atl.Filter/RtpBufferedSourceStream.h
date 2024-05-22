#ifdef SOURCESTREAM
CRtpBufferedSourceStream::CRtpBufferedSourceStream(CRtpBufferedListenerFilter *pParentFilter, LPWSTR szPinName, HRESULT *phr)
: CSourceStream(_T("Kite.Rtp.Atl.Filter.Listener.BufferedSourceStream(SetWaitableTimer)"),
				phr,
				(CSource*)pParentFilter,
				szPinName)
{
	m_pRtpBufferedListenerFilter = pParentFilter;
	m_pRtpBufferedListener = m_pRtpBufferedListenerFilter->m_pRtpBufferedListener;
	m_pRtpListener = m_pRtpBufferedListenerFilter->m_pRtpListener;

	m_hWaitableTimer = CreateWaitableTimer(NULL, FALSE, NULL);
	if (NULL == m_hWaitableTimer)
		(*phr) = E_FAIL;
}

CRtpBufferedSourceStream::~CRtpBufferedSourceStream()
{
	if (m_hWaitableTimer)
		CancelWaitableTimer(m_hWaitableTimer);
	SAFE_CLOSE_HANDLE(m_hWaitableTimer);
}

// Must override
// if supports only MANY MediaType
HRESULT CRtpBufferedSourceStream::GetMediaType(
	int iPosition,
	CMediaType *pMediaType
	)
{
	return E_NOTIMPL;
}

HRESULT CRtpBufferedSourceStream::DecideBufferSize(
	IMemAllocator *pMemAllocator,
	ALLOCATOR_PROPERTIES *pAllocatorProperties)
{
	CheckPointer(pMemAllocator, E_POINTER);
	CheckPointer(pAllocatorProperties, E_POINTER);

	ALLOCATOR_PROPERTIES actual;
	ZeroMemory(&actual, sizeof(ALLOCATOR_PROPERTIES));
}


HRESULT CRtpBufferedSourceStream::FillBuffer(
	IMediaSample *pSample
	) 
{
	return E_NOTIMPL;
}

HRESULT CRtpBufferedSourceStream::SelectSsrc(UINT ssrc)
{
	return E_NOTIMPL;
}

// May override
// possibly the 
HRESULT CRtpBufferedSourceStream::CheckMediaType(
	const CMediaType *pMediaType
	)
{
	return E_NOTIMPL;
}

// DoBufferProcessingLoop
//
// Grabs a buffer and calls the users processing function.
// Overridable, so that different delivery styles can be catered for.
HRESULT CRtpBufferedSourceStream::OnThreadStartPlay(void)
{
	ASSERT(m_hWaitableTimer);

	LARGE_INTEGER lDueTime;
	ZeroMemory(&lDueTime, sizeof(LARGE_INTEGER));
	lDueTime.QuadPart = -(INT)((1000 * 10000) / 10); // 1000 Millis, expand to Ticks (100 nanos), divide bya fps

	BOOL bRetVal = SetWaitableTimer(m_hWaitableTimer, &lDueTime, (UINT)(lDueTime.QuadPart / 10000) - 1, CRtpBufferedSourceStream::ApcTimerCallback, this, FALSE);
	ASSERT(bRetVal);

	SleepEx(INFINITE, TRUE);

	return S_OK;
}

HRESULT CRtpBufferedSourceStream::DoBufferProcessingLoop(void) 
{
	OnThreadStartPlay();

	return S_FALSE;
}

VOID APIENTRY CALLBACK CRtpBufferedSourceStream::ApcTimerCallback(
	LPVOID lpArgToCompletionRoutine, DWORD dwTimerLowValue, DWORD dwTimerHighValue)
{
	ASSERT(lpArgToCompletionRoutine);
	if (!lpArgToCompletionRoutine) return;

	CRtpBufferedSourceStream* pInstance = (CRtpBufferedSourceStream*)lpArgToCompletionRoutine;
}


#endif
