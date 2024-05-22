#pragma once
#ifndef UTILITIES_H
#define UTILITIES_H
		  
#ifndef MY_HELPERS
#define MY_HELPERS

#define LOG(msg) \
	ATLTRACE2("LOG: File %s Line %d \r\n", __FILE__, __LINE__); \
	if (IDNO == MessageBox(NULL, _T(msg), _T("Test"), MB_YESNO )) \
	ASSERT(0); \

#define LOGCALL \
	ATLTRACE2("LOG: File %s Line %d \r\n", __FILE__, __LINE__); \
	if (IDNO == MessageBox(NULL, _T("Here, there and everywhere"), _T("Test"), MB_YESNO )) \
	ASSERT(0); \


#ifdef DEBUG
#	define TRACECALL _RPT4(_CRT_WARN, "Function: %s, File: %s, Line %d, Compiled: %s \r\n", __FUNCTION__, __FILE__, __LINE__, __TIMESTAMP__);
#else
#	define TRACECALL __noop
#endif

// locks a critical section, and unlocks it automatically
// when the lock goes out of scope
class CAutoLock 
{
	// make copy constructor and assignment operator inaccessible
	CAutoLock(const CAutoLock &refAutoLock);
	CAutoLock &operator=(const CAutoLock &refAutoLock);

protected:
	CRITICAL_SECTION *m_pLock;

public:
	CAutoLock(CRITICAL_SECTION * plock);
	~CAutoLock();
};

BOOL MmsystemHelper_TimeKillSynchronousFlagAvailable(VOID);

#ifndef ASSERT
#	ifdef ATLASSERT
#		define ASSERT(x) ATLASSERT(x)
#	endif
#endif

// Validate HRESULT
#ifdef _DEBUG
#	define VALHR(hr) \
		if (FAILED(hr)) \
		{ \
			ATLTRACE2("VALHR: Failure: hr was: 0x%x, Filename: %s, Line %d \r\n", hr, __FILE__, __LINE__); \
			ASSERT(0); \
			return hr; \
		}

#	define VALRV(retVal, hr) \
		if (retVal == 0) \
		{ \
			LPVOID pBuffer; \
			FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER , NULL, GetLastError(), NULL, (LPTSTR)&pBuffer, 0, NULL); \
			ATLTRACE2("VALRV: Message: '%s' File: '%s', Line: %d", (LPTSTR)pBuffer, __FILE__, __LINE__); \
			LocalFree(pBuffer); \
			ATLASSERT(0); \
			return hr; \
		} \

#else
#	define VALHR(hr) \
		if (FAILED(hr)) \
		{ \
			ATLTRACE2("VALHR: Failure: hr was: 0x%x, Filename: %s, Line %d \r\n", hr, __FILE__, __LINE__); \
			return hr; \
		}

#	define VALRV(retVal, hr) \
	if (retVal == 0) \
		{ \
			LPVOID pBuffer; \
			FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER , NULL, GetLastError(), NULL, (LPTSTR)&pBuffer, 0, NULL); \
			ATLTRACE2("VALRV: Message: '%s' File: '%s', Line: %d", (LPTSTR)pBuffer, __FILE__, __LINE__); \
			LocalFree(pBuffer); \
			return hr; \
		} \

#endif


#define ALLOC(cbSize) CoTaskMemAlloc(cbSize);
#define FREE(pMemPtr) CoTaskMemFree(pMemPtr);
#define REALLOC(pMemPtr, cbSize) CoTaskMemRealloc(pMemPtr, cbSize);

LPVOID SAFE_ALLOC(SIZE_T cbSize);
LPVOID SAFE_ALLOC_SPIN(SIZE_T cbSize, UINT spinCount);
LPVOID SAFE_REALLOC(LPVOID pMemPtr, SIZE_T cbSize);

#define SAFE_DELETE(obj) \
	if (obj) \
	{ \
		delete obj; obj = NULL; \
	} 

#define SAFE_DELETE_ARRAY(arry) \
	if (arry) \
	{ \
		delete [] arry; arry = NULL; \
	} 

#define SAFE_RELEASE(pComPtr) \
	if (pComPtr) \
	{ \
		pComPtr->Release(); pComPtr = NULL; \
	} 

#define SAFE_FREE(pMemPtr) \
	if (pMemPtr) \
	{ \
		FREE(pMemPtr); pMemPtr = NULL; \
	} 


#define SAFE_DISPOSE_AND_RELEASE(obj) \
	if (obj) \
	{ \
		HRESULT inner_hr = S_OK; \
		{ \
			CComQIPtr<IDisposable> pDisposable = obj; \
			if (pDisposable != NULL) \
			{ \
				inner_hr = pDisposable->Dispose(); \
			} \
			else \
				LOG("Object Does not Implement IDisposable.\r\n"); \
		} \
		if (inner_hr == S_OK || inner_hr == E_DISPOSED) \
		{ \
			LOG("Disposed successfully"); \
		} \
		else \
		{ \
			LOG("ERROR Disposing"); \
			ATLASSERT((inner_hr == S_OK || inner_hr == E_DISPOSED)); \
		} \
		SAFE_RELEASE(obj); \
	}

HRESULT CheckIsPlayoutBufferDisposed(IPlayoutBuffer *pobj);

#define CheckPointer(pPtr, hr) \
if (!pPtr) return hr;

#define SAFE_CLOSE_SOCKET(sckt) \
	if (sckt != INVALID_SOCKET && sckt != NULL) \
	{ \
		shutdown(sckt, SD_BOTH); \
		closesocket(sckt); \
	}

#define SAFE_CLOSE_WSAEVENT(evnt) \
	if (evnt != WSA_INVALID_EVENT) \
	{ \
		WSACloseEvent(evnt); \
		evnt = WSA_INVALID_EVENT; \
	}

#define SAFE_CLOSE_HANDLE(hndl) \
	if (hndl != NULL && hndl != INVALID_HANDLE_VALUE) \
	{ \
		CloseHandle(hndl); \
		hndl = INVALID_HANDLE_VALUE; \
	}

#define SAFE_POINTER_ARRAY_FREE_ONLY_FIRST_ITEM(arryptr, cItems) \
	if (arryptr) \
	 { \
		SAFE_FREE(arryptr[0]); \
		SAFE_FREE(arryptr); \
	 }

#define SAFE_POINTER_ARRAY_FREE_ALL_ITEMS(arryptr, cItems) \
	if (arryptr) \
	 { \
		for (INT i = 0; i < cItems; i++) \
		{ \
			SAFE_FREE(arryptr[i]); \
		} \
		SAFE_FREE(arryptr); \
	 }

#define CheckPointerJIF(p, ret) if((p)==NULL) { hr = ret; goto cleanup;}

#endif

#endif // UTILITIES_H
