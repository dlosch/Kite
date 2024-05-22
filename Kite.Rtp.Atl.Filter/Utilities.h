#pragma once

#include <streams.h>
#include <crtdbg.h>

#ifdef DEBUG
#	define TRACECALL _RPT4(_CRT_WARN, "Function: %s, File: %s, Line %d, Compiled: %s \r\n", __FUNCTION__, __FILE__, __LINE__, __TIMESTAMP__);
#else
#define TRACECALL __noop
#endif

BOOL MyTimeKillSynchronousFlagAvailable();

HRESULT CopyVideoInfoHeaderFromMediaType(const AM_MEDIA_TYPE* pmt, VIDEOINFOHEADER **ppVIH);

HRESULT GetMediaTypeProperties(
							   const AM_MEDIA_TYPE *pMediaType, 

							   CLSID* guidMajorType,
							   CLSID* guidSubType,
							   DWORD *pdwFourCC,
							   INT *pWidth,
							   INT *pHeight,
							   DWORD *pdwBitRate,
							   INT *pFrameRate
							   //LONGLONG* pAverageTimePerFrame
							   );

HRESULT ValidatePictureFormat(INT width, INT height);


HRESULT FillMediaTypeStruct(
							CMediaType *pMediaType, 
							REFGUID majorType /*= MEDIATYPE_Video*/, 
							REFGUID subType /*= MEDIASUBTYPE_YV12*/, 
							REFGUID formatType,
							DWORD dwFourCC /*= mmioFOURCC('Y', 'V', '1', '2')*/, 
							INT width /*= 176*/, 
							INT height /*= 144*/, 
							DWORD dwBitRate,
							INT avgTimePerFrameNanos /*= 15*/);

enum PICTURE_FORMAT
{


	PICTURE_FORMAT_SUBQCIF = 0x1,
	PICTURE_FORMAT_QCIF = 0x2,
	PICTURE_FORMAT_CIF = 0x3,
	PICTURE_FORMAT_CIF4 = 0x4,
	PICTURE_FORMAT_CIF16 = 0x5,
	PICTURE_FORMAT_RESERVED1 = 0x6,
	PICTURE_FORMAT_RESERVED2 = 0x7
};

HRESULT GetPictureFormat(INT width, INT height, PICTURE_FORMAT* pPictureFormat);

void pgm_save(unsigned char *buf,int wrap, int xsize,int ysize,char *filename_ignored);

//////////////////////////////////////////////////////////////////////////

// 23072003
// Jump If Failed
#ifdef DEBUG
#	if	_ATL_VER
#		define TRACEHR(hr) ATLTRACE2("ERROR hr = 0x%x Function: %s, File: %s, Line %d\r\n", hr, __FUNCTION__, __FILE__, __LINE__);
#else	
#		define TRACEHR(hr) _RPT4(_CRT_WARN, "ERROR hr = 0x%x Function: %s, File: %s, Line %d\r\n", hr, __FUNCTION__, __FILE__, __LINE__);
#	endif
#	define JIF(hr) \
		if (FAILED(hr)) \
		{ \
			TRACEHR(hr); \
			goto cleanup; \
		} 
#else
#	define JIF(hr) \
		if (FAILED(hr)) \
		{ \
			goto cleanup; \
		} 
#endif

// Validate HRESULT
#ifdef _DEBUG
#	define VALHR(hr) \
	if (FAILED(hr)) \
{ \
	_RPT3(_CRT_WARN, "VALHR: Failure: hr was: 0x%x, Filename: %s, Line %d \r\n", hr, __FILE__, __LINE__); \
	ASSERT(0); \
	return hr; \
}

#	define VALRV(retVal, hr) \
	if (retVal == 0) \
{ \
	LPVOID pBuffer; \
	FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER , NULL, GetLastError(), NULL, (LPTSTR)&pBuffer, 0, NULL); \
	_RPT3(_CRT_WARN, "VALRV: Message: '%s' File: '%s', Line: %d", (LPTSTR)pBuffer, __FILE__, __LINE__); \
	LocalFree(pBuffer); \
	ASSERT(0); \
	return hr; \
} \

#else
#	define VALHR(hr) \
	if (FAILED(hr)) \
{ \
	_RPT3(_CRT_WARN, "VALHR: Failure: hr was: 0x%x, Filename: %s, Line %d \r\n", hr, __FILE__, __LINE__); \
	return hr; \
}

#	define VALRV(retVal, hr) \
	if (retVal == 0) \
{ \
	LPVOID pBuffer; \
	FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER , NULL, GetLastError(), NULL, (LPTSTR)&pBuffer, 0, NULL); \
	_RPT3(_CRT_WARN, "VALRV: Message: '%s' File: '%s', Line: %d", (LPTSTR)pBuffer, __FILE__, __LINE__); \
	LocalFree(pBuffer); \
	return hr; \
} \

#endif


#define ALLOC(cbSize) CoTaskMemAlloc(cbSize);
#define FREE(pMemPtr) CoTaskMemFree(pMemPtr);
#define REALLOC(pMemPtr, cbSize) CoTaskMemRealloc(pMemPtr, cbSize);

LPVOID SAFE_ALLOC(SIZE_T cbSize);
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

#define HTONL(uintVal) \
	( ((uintVal & 0xFF) << 24) | ((uintVal & 0xFF00) << 8) |((uintVal & 0xFF0000) >> 8) |((uintVal & 0xFF000000) >> 24 ) )

#define HTONS(ushrtVal) \
	( ((ushrtVal & 0xFF) << 8) | ((ushrtVal & 0xFF00) >> 8))

#define SAFE_CLOSE_HANDLE(hndl) \
	if (hndl != NULL && hndl != INVALID_HANDLE_VALUE) \
	{ \
		CloseHandle(hndl); \
		hndl = INVALID_HANDLE_VALUE; \
	}

