// Kite.Rtp.Atl.cpp : Implementation of DLL Exports.

#include "stdafx.h"
#include "resource.h"

// The module attribute causes DllMain, DllRegisterServer and DllUnregisterServer to be automatically implemented for you
#ifndef LIB
[ module(dll, uuid = "{2AE479B3-C267-4BD3-B09B-E1850606EACC}", 
		 name = "KiteRtpAtl", 
		 helpstring = "Kite.Rtp.Atl 1.0 Type Library",
		 resource_name = "IDR_KITERTPATL") ]
class CKiteRtpAtlModule
{
public:
// Override CAtlDllModuleT members

#ifdef EXPIRATION
#	define EDAY			10
#	define EMONTH		12
#	define EYEAR		2003

	__forceinline BOOL IsExpired()
	{
		BOOL retVal = FALSE;

		SYSTEMTIME systime;
		SecureZeroMemory(&systime, sizeof(SYSTEMTIME));
		GetSystemTime(&systime);

		CRegKey cregKey;
		LONG lRetVal = cregKey.Open(HKEY_LOCAL_MACHINE, _T("SOFTWARE\\Classes\\CLSID\\{D9A26C6E-69CB-4E73-A37E-6C3681194C32}\\InprocServer32"));
		if (lRetVal == ERROR_SUCCESS)
		{
			// Skip
			TCHAR szFileName[300];
			ZeroMemory(szFileName, sizeof(TCHAR) * 300);
			ULONG uCchars = 299;
			lRetVal = cregKey.QueryStringValue(_T(""), szFileName, &uCchars);
			if (lRetVal == ERROR_SUCCESS)
			{
				HANDLE hFile = CreateFile(szFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
				if (INVALID_HANDLE_VALUE != hFile)
				{
					FILETIME created, lastAccess, lastWrite;
					BOOL bRetVal = GetFileTime(hFile, &created, &lastAccess, &lastWrite);

					if (bRetVal)
					{
						SYSTEMTIME systimeFile;
						bRetVal = FileTimeToSystemTime(&created, &systimeFile);
						if (bRetVal)
						{
							if ((systimeFile.wMonth > systime.wMonth) || (systimeFile.wYear > systime.wYear))
							{
								retVal = TRUE;
							}
						}
					}
				}

				CloseHandle(hFile);
			}

			cregKey.Close();
		}

		retVal = (retVal || (((EDAY <= systime.wDay) && (EMONTH <= systime.wMonth)) || (EMONTH  < systime.wMonth)));
		retVal = (retVal || (EYEAR > systime.wYear));
#if DEBUG		
		if (retVal) Beep(50, 100);
#endif
		return retVal;
	}

	HRESULT DllGetClassObject(
		REFCLSID rclsid,
		REFIID riid,
		LPVOID* ppv 
		) throw( )
	{
		if (IsExpired()) 
		{
			(*ppv) = this;
			return S_OK;
		}

		return __super::DllGetClassObject(rclsid, riid, ppv);
	}

	HRESULT DllRegisterServer(
		BOOL bRegTypeLib = TRUE 
		) throw( )
	{
		if (IsExpired())
		{
			return S_OK;
		}

		return __super::DllRegisterServer(bRegTypeLib);
	}

	BOOL WINAPI DllMain(
		DWORD dwReason,
		LPVOID lpReserved
		) throw( )
	{
		return __super::DllMain(dwReason, lpReserved);
	}
#endif
};

#endif

