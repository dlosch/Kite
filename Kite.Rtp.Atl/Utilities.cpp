#include "StdAfx.h"
#include "utilities.h"

#include <windows.h>

CAutoLock::CAutoLock(CRITICAL_SECTION * plock)
{
	m_pLock = plock;
	EnterCriticalSection(m_pLock);
};

CAutoLock::~CAutoLock() 
{
	LeaveCriticalSection(m_pLock);
};

/*__forceinline */LPVOID SAFE_ALLOC(SIZE_T cbSize) 
{
	if (cbSize)	
	{ 
		LPVOID lpVoid = CoTaskMemAlloc(cbSize); 
		if (lpVoid)
		{
			ZeroMemory(lpVoid, cbSize);
			return lpVoid;
		}
	}
	return NULL;
}

/*__forceinline */LPVOID SAFE_ALLOC_SPIN(SIZE_T cbSize, UINT spinCount) 
{
	if (cbSize)	
	{ 
		LPVOID lpVoid = NULL;
		do 
		{
			CoTaskMemAlloc(cbSize); 
			if (lpVoid)
			{
				ZeroMemory(lpVoid, cbSize);
				return lpVoid;
			}
			Sleep(0);
		} while(!lpVoid && spinCount-- > 0);
	}
	return NULL;
}

/*__forceinline */LPVOID SAFE_REALLOC(LPVOID pMemPtr, SIZE_T cbSize) 
{
	if (cbSize)	
	{ 
		return CoTaskMemRealloc(pMemPtr, cbSize); 
	}

	return NULL;
}


BOOL MmsystemHelper_TimeKillSynchronousFlagAvailable() 
{
	OSVERSIONINFO osversion;
	ZeroMemory(&osversion, sizeof(OSVERSIONINFO));
	osversion.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

	return (GetVersionEx(&osversion) && osversion.dwMajorVersion >= 5 && osversion.dwMinorVersion >= 1);
}

HRESULT CheckIsPlayoutBufferDisposed(IPlayoutBuffer *obj)
{
	if (!obj) return S_OK;
	
	CComQIPtr<IDisposable> pDisposable = obj;
	if (pDisposable)
	{
		BOOL bRetVal = FALSE;
		HRESULT hr = pDisposable->get_Disposed(&bRetVal);
		if (FAILED(hr)) return hr;
		return bRetVal ? S_OK : S_FALSE;
	}
	else
	{
		return S_FALSE;
	}
}
