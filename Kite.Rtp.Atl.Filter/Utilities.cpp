#include "StdAfx.h"
#include <streams.h>
#include "utilities.h"


#define ACCEPT_ONLY_CIF
#include <stdio.h>

BOOL MyTimeKillSynchronousFlagAvailable() 
{
	OSVERSIONINFO osversion;
	ZeroMemory(&osversion, sizeof(OSVERSIONINFO));
	osversion.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	return (GetVersionEx(&osversion) && osversion.dwMajorVersion >= 5 && osversion.dwMinorVersion >= 1);
}

HRESULT CopyVideoInfoHeaderFromMediaType(const AM_MEDIA_TYPE* pmt, VIDEOINFOHEADER **ppVIH)
{
	CheckPointer(pmt, E_POINTER);

	if (pmt->majortype == MEDIATYPE_Video 
		&& pmt->formattype == FORMAT_VideoInfo 
		&& pmt->cbFormat == sizeof(VIDEOINFOHEADER) 
		&& pmt->pbFormat)
	{
		if (*ppVIH) (*ppVIH) = (VIDEOINFOHEADER*)CoTaskMemRealloc(*ppVIH, sizeof(VIDEOINFOHEADER));
		else (*ppVIH) = (VIDEOINFOHEADER*)CoTaskMemAlloc(sizeof(VIDEOINFOHEADER));

		CheckPointer(*ppVIH, E_POINTER);

		CopyMemory((*ppVIH), pmt->pbFormat, sizeof(VIDEOINFOHEADER));

		return S_OK;
	}

	if (*ppVIH) CoTaskMemFree(*ppVIH);

	(*ppVIH) = NULL;

	return E_FAIL;;
}

HRESULT GetMediaTypeProperties(
							   const AM_MEDIA_TYPE *pMediaType, 
							   CLSID* pGuidMajorType,
							   CLSID* pGuidSubType,
							   DWORD *pdwFourCC,
							   INT *pWidth,
							   INT *pHeight,
							   DWORD *pdwBitRate,
							   // ffmpeg measures FramesPerSecond as 2 Integers (Value and base)
							   INT* pFrameRate
							   //LONGLONG* pAverageTimePerFrame
							   )
{
	CheckPointer(pMediaType, E_POINTER);

	*pGuidMajorType = MEDIATYPE_Video;
	*pGuidSubType = pMediaType->subtype;

	if ((pMediaType->majortype == MEDIATYPE_Video)
		&& pMediaType->formattype == FORMAT_VideoInfo
		&& pMediaType->cbFormat == sizeof(VIDEOINFOHEADER)
		&& pMediaType->pbFormat)
	{
		VIDEOINFOHEADER* pVIH = (VIDEOINFOHEADER*)pMediaType->pbFormat;
		*pdwFourCC = pVIH->bmiHeader.biCompression;
		*pWidth = pVIH->bmiHeader.biWidth;
		*pHeight = pVIH->bmiHeader.biHeight;
		*pdwBitRate = pVIH->dwBitRate;
		(*pFrameRate) = (INT)(pVIH->AvgTimePerFrame); 

		return S_OK;
	}

	return S_FALSE;
}

HRESULT ValidatePictureFormat(INT width, INT height)
{
#ifdef ACCEPT_ONLY_CIF	
	int baseWidth = 88, baseHeight = 72;

	for (int i = 0; i <= 4; i++)
	{
		if ((baseWidth << i) == width && (baseHeight << i) == height)
		{
			return S_OK;
		}
	}

	return E_FAIL;
#else
	return NOERROR;
#endif
}


HRESULT GetPictureFormat(INT width, INT height, PICTURE_FORMAT* pPictureFormat)
{
	if (width == 128 && height == 96) 
	{
		*pPictureFormat = PICTURE_FORMAT_SUBQCIF;
		return S_OK;
	}
	else if (width == 176 && height == 144) 
	{
		*pPictureFormat = PICTURE_FORMAT_QCIF;
		return S_OK;
	}
	else if (width == 352 && height == 288) 
	{
		*pPictureFormat = PICTURE_FORMAT_CIF;
		return S_OK;
	}
	else if (width == 704 && height == 576) 
	{
		*pPictureFormat = PICTURE_FORMAT_CIF4;
		return S_OK;
	}
	else if (width == 1408 && height == 1152) 
	{
		*pPictureFormat = PICTURE_FORMAT_CIF16;
		return S_OK;
	}
	else 
	{
		*pPictureFormat = PICTURE_FORMAT_RESERVED2;
		return S_FALSE;
	}
}

HRESULT FillMediaTypeStruct(
							CMediaType *pMediaType, 
							REFGUID majorType /*= MEDIATYPE_Video*/, 
							REFGUID subType /*= MEDIASUBTYPE_YV12*/, 
							REFGUID formatType,
							DWORD dwFourCC /*= mmioFOURCC('Y', 'V', '1', '2')*/, 
							INT width /*= 176*/, 
							INT height /*= 144*/, 
							DWORD dwBitRate,
							INT avgTimePerFrameNanos /*= 15*/)
{
	CheckPointer(pMediaType, E_POINTER);

	pMediaType->SetFormatType(&formatType);
	pMediaType->AllocFormatBuffer(sizeof(VIDEOINFOHEADER));
	VIDEOINFOHEADER *pVIH = (VIDEOINFOHEADER*)pMediaType->Format();

	// Init
	RECT rect = {0,0,0,0};
	pVIH->rcSource = rect;
	pVIH->rcTarget = rect;
	pVIH->AvgTimePerFrame = avgTimePerFrameNanos;//(LONGLONG)90000/fps/*fps*/;
	pVIH->dwBitErrorRate = 0;
	pVIH->dwBitRate = dwBitRate;
	pVIH->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);

	INT bitCount = 0;
	INT sampleSize = 0;

	if(dwFourCC == mmioFOURCC('Y', 'V', '1', '2'))
		bitCount = 12;
	else if (dwFourCC == mmioFOURCC('U', 'Y', 'V', 'Y'))
		bitCount = 16;
	else if (dwFourCC == mmioFOURCC('Y', 'U', 'Y', '2'))
		bitCount = 16;
	else if (dwFourCC == mmioFOURCC('Y', 'U', 'Y', 'V'))
		bitCount = 16;
	else 
		bitCount = 8;
	// >> 3
	sampleSize = width * height * (bitCount / 8);

	pVIH->bmiHeader.biBitCount = bitCount;
	pVIH->bmiHeader.biClrImportant = 0;
	pVIH->bmiHeader.biClrUsed = 0;
	pVIH->bmiHeader.biPlanes = 1;
	pVIH->bmiHeader.biSizeImage = sampleSize;
	pVIH->bmiHeader.biXPelsPerMeter = 0;
	pVIH->bmiHeader.biYPelsPerMeter = 0;
	pVIH->bmiHeader.biCompression = dwFourCC;
	pVIH->bmiHeader.biWidth = width;
	pVIH->bmiHeader.biHeight = height;

	pMediaType->bFixedSizeSamples = 1;
	pMediaType->bTemporalCompression = 0;
	pMediaType->lSampleSize = sampleSize; // 
	pMediaType->majortype = MEDIATYPE_Video;
	pMediaType->subtype = subType;
	pMediaType->pUnk = 0;

	return S_OK;
}


void pgm_save(unsigned char *buf,int wrap, int xsize,int ysize,char *filename_ignored) 
{
	static int counter = 0;
	if (++counter > 50) return;

	FILE *f;
	int i;

	CHAR filename[100];
	sprintf(filename, "%s_%d_%s.pgm\0", "f:\\trash\\image", (counter / 2), filename_ignored);

	f=fopen(filename,"w");
	fprintf(f,"P5\n%d %d\n%d\n",xsize,ysize,255);
	for(i=0;i<ysize;i++)
		fwrite(buf + i * wrap,1,xsize,f);
	fclose(f);
}

//////////////////////////////////////////////////////////////////////////
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

/*__forceinline */LPVOID SAFE_REALLOC(LPVOID pMemPtr, SIZE_T cbSize) 
{
	if (cbSize)	
	{ 
		
		return CoTaskMemRealloc(pMemPtr, cbSize); 
	}

	return NULL;
}