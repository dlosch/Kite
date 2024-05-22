#ifndef KITESHAREDREGISTRATION_H
#define KITESHAREDREGISTRATION_H

#include <atlconv.h>

// CoInitialize must have been called
STDAPI KiteCreateCategories(IFilterMapper2 *pFilterMapper2, BOOL bForceCreation)
{
	if (pFilterMapper2 == NULL) return E_POINTER;

	// A filter can appear in one or more categories (for example, Video Compressors) to restrict the search space. 
	HRESULT hr = S_OK;

	// Query whether Category Registry Key exists
	HKEY hKeyClassesRootClsid;
	LONG lRetVal = RegOpenKeyEx(HKEY_CLASSES_ROOT, _T("CLSID"), NULL, KEY_READ, &hKeyClassesRootClsid);

	if (ERROR_SUCCESS != lRetVal)
	{
		return E_FAIL;
	}

	if (ERROR_SUCCESS == lRetVal)
	{	
		// Hierfür muss Conitialize sein
		LPOLESTR lpOleStrCategoryClsid = NULL; // 40 Chars sollten reichen
		hr = StringFromCLSID(CLSID_KiteRendererCategory, &lpOleStrCategoryClsid);

		if (FAILED(hr)) goto cleanup;

		// Lookup whether the category already exists, if yes, skip the creation and return S_FALSE
		HKEY hKeyCurrentCategory;
		USES_CONVERSION;
		lRetVal = RegOpenKeyEx(hKeyClassesRootClsid, OLE2A(lpOleStrCategoryClsid), NULL, KEY_READ, &hKeyCurrentCategory);
		_RPT1(_CRT_WARN, "RegOpen: 0x%x \r\n", lRetVal);

		if ((lRetVal != ERROR_SUCCESS) || bForceCreation)
		{
			hr = S_OK;
			// Assume Key does not exist, Create
			hr = pFilterMapper2->CreateCategory(CLSID_KiteDiagnosticCategory, MERIT_DO_NOT_USE, L"Kite.Diagnostics");
			_RPT1(_CRT_WARN, "CreateCategory: 0x%x \r\n", hr);

			hr = pFilterMapper2->CreateCategory(CLSID_KiteVideoCompressorCategory, MERIT_DO_NOT_USE, L"Kite.Video.Compressors");
			_RPT1(_CRT_WARN, "CreateCategory: 0x%x \r\n", hr);

			hr = pFilterMapper2->CreateCategory(CLSID_KiteVideoDecompressorCategory, MERIT_DO_NOT_USE, L"Kite.Video.Decompressors");
			_RPT1(_CRT_WARN, "CreateCategory: 0x%x \r\n", hr);

			hr = pFilterMapper2->CreateCategory(CLSID_KiteAudioCompressorCategory, MERIT_DO_NOT_USE, L"Kite.Audio.Compressors");
			_RPT1(_CRT_WARN, "CreateCategory: 0x%x \r\n", hr);

			hr = pFilterMapper2->CreateCategory(CLSID_KiteAudioDecompressorCategory, MERIT_DO_NOT_USE, L"Kite.Audio.Decompressors");
			_RPT1(_CRT_WARN, "CreateCategory: 0x%x \r\n", hr);

			hr = pFilterMapper2->CreateCategory(CLSID_KiteVideoUtilityCategory, MERIT_DO_NOT_USE, L"Kite.Video.Utilities");
			_RPT1(_CRT_WARN, "CreateCategory: 0x%x \r\n", hr);

			hr = pFilterMapper2->CreateCategory(CLSID_KiteRendererCategory, MERIT_DO_NOT_USE, L"Kite.Renderer");
			_RPT1(_CRT_WARN, "CreateCategory: 0x%x \r\n", hr);

			hr = pFilterMapper2->CreateCategory(CLSID_KiteSourceCategory, MERIT_DO_NOT_USE, L"Kite.Sources");
			_RPT1(_CRT_WARN, "CreateCategory: 0x%x \r\n", hr);
		}
		else
		{
			hr = S_FALSE;
			RegCloseKey(hKeyCurrentCategory);
		}

		CoTaskMemFree(lpOleStrCategoryClsid);

	}

cleanup:
	RegCloseKey(hKeyClassesRootClsid);

	return hr;
}

STDAPI KiteDeleteCategories()
{
	// Category
	// HKEY_LOCAL_MACHINE\SOFTWARE\Classes\CLSID\{1E263E40-0405-46F3-A72F-929DB9412045}
	// Category under ActiveMovieCategories
	// HKEY_LOCAL_MACHINE\SOFTWARE\Classes\CLSID\{da4e3da0-d07d-11d0-bd50-00a0c911ce86}\Instance\{1E263E40-0405-46F3-A72F-929DB9412045}
	HKEY hKeyLMSoftwareClassesClsid;
	LONG lRetVal = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SOFTWARE\\Classes\\CLSID", NULL, KEY_ALL_ACCESS, &hKeyLMSoftwareClassesClsid);

	if (lRetVal == ERROR_SUCCESS)
	{
		// use SHDeleteKey (recursive)
		lRetVal = RegDeleteKey(hKeyLMSoftwareClassesClsid, "{1E263E39-0405-46f3-A72F-929DB9412045}");
		lRetVal = RegDeleteKey(hKeyLMSoftwareClassesClsid, "{1E263E40-0405-46f3-A72F-929DB9412045}");
		lRetVal = RegDeleteKey(hKeyLMSoftwareClassesClsid, "{1E263E41-0405-46f3-A72F-929DB9412045}");
		lRetVal = RegDeleteKey(hKeyLMSoftwareClassesClsid, "{1E263E42-0405-46f3-A72F-929DB9412045}");
		lRetVal = RegDeleteKey(hKeyLMSoftwareClassesClsid, "{1E263E43-0405-46f3-A72F-929DB9412045}");
		lRetVal = RegDeleteKey(hKeyLMSoftwareClassesClsid, "{1E263E44-0405-46f3-A72F-929DB9412045}");
		lRetVal = RegDeleteKey(hKeyLMSoftwareClassesClsid, "{1E263E45-0405-46f3-A72F-929DB9412045}");
		lRetVal = RegDeleteKey(hKeyLMSoftwareClassesClsid, "{1E263E46-0405-46f3-A72F-929DB9412045}");

		RegCloseKey(hKeyLMSoftwareClassesClsid);
	}

	lRetVal = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SOFTWARE\\Classes\\CLSID\\{da4e3da0-d07d-11d0-bd50-00a0c911ce86}\\Instance", NULL, KEY_ALL_ACCESS, &hKeyLMSoftwareClassesClsid);
	if (lRetVal == ERROR_SUCCESS)
	{
		// use SHDeleteKey
		lRetVal = RegDeleteKey(hKeyLMSoftwareClassesClsid, "{1E263E39-0405-46f3-A72F-929DB9412045}");
		lRetVal = RegDeleteKey(hKeyLMSoftwareClassesClsid, "{1E263E40-0405-46f3-A72F-929DB9412045}");
		lRetVal = RegDeleteKey(hKeyLMSoftwareClassesClsid, "{1E263E41-0405-46f3-A72F-929DB9412045}");
		lRetVal = RegDeleteKey(hKeyLMSoftwareClassesClsid, "{1E263E42-0405-46f3-A72F-929DB9412045}");
		lRetVal = RegDeleteKey(hKeyLMSoftwareClassesClsid, "{1E263E43-0405-46f3-A72F-929DB9412045}");
		lRetVal = RegDeleteKey(hKeyLMSoftwareClassesClsid, "{1E263E44-0405-46f3-A72F-929DB9412045}");
		lRetVal = RegDeleteKey(hKeyLMSoftwareClassesClsid, "{1E263E45-0405-46f3-A72F-929DB9412045}");
		lRetVal = RegDeleteKey(hKeyLMSoftwareClassesClsid, "{1E263E46-0405-46f3-A72F-929DB9412045}");

		RegCloseKey(hKeyLMSoftwareClassesClsid);
	}

	return S_OK;
}

#endif