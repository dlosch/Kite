// Kite.Rtp.Atl.cpp : Implementation of DLL Exports.

#include "stdafx.h"
#include "resource.h"

// Modern ATL implementation without deprecated attributes
class CKiteRtpAtlModule : public ATL::CAtlDllModuleT< CKiteRtpAtlModule >
{
public :
	DECLARE_LIBID(LIBID_KiteRtpAtl)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_KITERTPATL, "{2AE479B3-C267-4BD3-B09B-E1850606EACC}")

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
		HRESULT hr = cregKey.Open(HKEY_LOCAL_MACHINE, _T("Software\\DLosch\\Kite.Rtp.Atl"));
		if (SUCCEEDED(hr))
		{
			DWORD dwEnabledValue;
			hr = cregKey.QueryDWORDValue(_T("Enabled"), dwEnabledValue);
			if (SUCCEEDED(hr) && dwEnabledValue == 1)
			{
				return FALSE;
			}
		}

		if ((systime.wYear > EYEAR) || 
			((systime.wYear == EYEAR) && (systime.wMonth > EMONTH)) ||
			((systime.wYear == EYEAR) && (systime.wMonth == EMONTH) && (systime.wDay > EDAY)))
		{
			retVal = TRUE;
		}

		return retVal;
	}

	HRESULT DllGetClassObject(
		REFCLSID rclsid,
		REFIID riid,
		LPVOID* ppv 
		) throw( )
	{
#ifdef EXPIRATION
		if (IsExpired()) 
		{
			(*ppv) = this;
			return S_OK;
		}
#endif

		return __super::DllGetClassObject(rclsid, riid, ppv);
	}

	HRESULT DllRegisterServer(
		BOOL bRegTypeLib = TRUE 
		) throw( )
	{
#ifdef EXPIRATION
		if (IsExpired())
		{
			return S_OK;
		}
#endif

		return __super::DllRegisterServer(bRegTypeLib);
	}

	BOOL WINAPI DllMain(
		DWORD dwReason,
		LPVOID lpReserved
		) throw( )
	{
		return __super::DllMain(dwReason, lpReserved);
	}
};

CKiteRtpAtlModule _AtlModule;

// DLL Entry Point
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	return _AtlModule.DllMain(dwReason, lpReserved);
}

// Used to determine whether the DLL can be unloaded by OLE.
STDAPI DllCanUnloadNow(void)
{
	return _AtlModule.DllCanUnloadNow();
}

// Returns a class factory to create an object of the requested type.
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
	return _AtlModule.DllGetClassObject(rclsid, riid, ppv);
}

// DllRegisterServer - Adds entries to the system registry.
STDAPI DllRegisterServer(void)
{
	// registers object, typelib and all interfaces in typelib
	HRESULT hr = _AtlModule.DllRegisterServer();
	return hr;
}

// DllUnregisterServer - Removes entries from the system registry.
STDAPI DllUnregisterServer(void)
{
	HRESULT hr = _AtlModule.DllUnregisterServer();
	return hr;
}

// DllInstall - Adds/Removes entries to the system registry per user per machine.	
STDAPI DllInstall(BOOL bInstall, LPCWSTR pszCmdLine)
{
	HRESULT hr = E_FAIL;
	static const wchar_t szUserSwitch[] = L"user";

	if (pszCmdLine != NULL)
	{
		if (_wcsnicmp(pszCmdLine, szUserSwitch, _countof(szUserSwitch)) == 0)
		{
			ATL::AtlSetPerUserRegistration(true);
		}
	}

	if (bInstall)
	{	
		hr = DllRegisterServer();
		if (FAILED(hr))
		{
			DllUnregisterServer();
		}
	}
	else
	{
		hr = DllUnregisterServer();
	}

	return hr;
}