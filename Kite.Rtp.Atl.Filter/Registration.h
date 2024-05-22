#ifndef REGISTRATION_H
#define REGISTRATION_H

#define KITE_CATEGORY

#define LISTENER_SINGLEPIN
#define RENDERER

#include "Rtpuuids.h"

#ifdef RTPLISTENERFILTER
#	include "RtpListenerFilter.h"
#endif

#include "RtpListenerFilterSingleOutputPin.h"
#include "RtpRendererFilter.h"

#include "kitesharedregistration.h"

extern "C" BOOL WINAPI DllEntryPoint(HINSTANCE, ULONG, LPVOID);

// Setup data for Filter Registration
// Input Pin
const REGPINTYPES regPinTypesOutputPinRtpListener[4] =
{
	// TODO nur den PayloadType RTP_PAYLOAD definieren, f�r alle m�glichen Typen; Properly Packetized Rtp Payload (PPRP)
	{
		&MEDIATYPE_Video,
		&MEDIATYPE_H263_RTP
	},
	{
		&MEDIATYPE_Video,
		&MEDIATYPE_h263_rtp
	},
	{
		&MEDIATYPE_Video,
		&MEDIATYPE_H26P_RTP
	},
	{
		&MEDIATYPE_Video,
		&MEDIATYPE_h26p_rtp
	},
};

const REGFILTERPINS regFilterPinsRtpListener[1] =
{
	{ 
		L"Output",				// Pin's string name
			FALSE,					// Is it rendered
			TRUE,					// Is it an output
			FALSE,					// Allowed none
			TRUE,					// Allowed many
			&CLSID_NULL,			// Connects to filter
			L"",					// Connects to pin

			4, //1,						// Number of types
			regPinTypesOutputPinRtpListener
	}
};

const AMOVIESETUP_FILTER amovieSetupRtpListener =
{
	&CLSID_RtpBufferedListenerFilter,	// CLSID of filter
		L"Kite.Rtp.Atl.Filter.BufferedListener",		// Filter's name
		MERIT_DO_NOT_USE,				// Filter merit
		1,							// Number of pins
		regFilterPinsRtpListener				// Pin information
};

#ifdef LISTENER_SINGLEPIN

const REGFILTERPINS regFilterPinsRtpListenerSinglePin[1] =
{
	{ 
		L"Output",				// Pin's string name
			FALSE,					// Is it rendered
			TRUE,					// Is it an output
			FALSE,					// Allowed none
			FALSE,					// Allowed many
			&CLSID_NULL,			// Connects to filter
			L"",					// Connects to pin

			4, //1,						// Number of types
			regPinTypesOutputPinRtpListener
	}
};

const AMOVIESETUP_FILTER amovieSetupRtpListenerSinglePin =
{
	&CLSID_RtpBufferedListenerFilterSinglePin,	// CLSID of filter
	L"Kite.Rtp.Atl.Filter.BufferedListener.SinglePin",		// Filter's name
	MERIT_DO_NOT_USE,				// Filter merit
	1,							// Number of pins
	regFilterPinsRtpListenerSinglePin				// Pin information
};

#endif


//Output Pin
const REGPINTYPES regPinTypesOutputPinRtpRenderer[4] =
{
	{
		&MEDIATYPE_Video,
			&MEDIATYPE_H263_RTP
	},
	{
		&MEDIATYPE_Video,
			&MEDIATYPE_h263_rtp
	},
	{
		&MEDIATYPE_Video,
			&MEDIATYPE_H26P_RTP
	},
	{
		&MEDIATYPE_Video,
			&MEDIATYPE_h26p_rtp
	},
};

const REGFILTERPINS regFilterPinsRtpRenderer[1] =
{
	{ 
		L"Input",				// Pin's string name
			FALSE,					// Is it rendered
			FALSE,					// Is it an output
			FALSE,					// Allowed none
			FALSE,					// Allowed many
			&CLSID_NULL,			// Connects to filter
			L"",					// Connects to pin

			0,					    // Number of types
			NULL
	},    
};

const AMOVIESETUP_FILTER amovieSetupRtpRenderer =
{
	&CLSID_RtpRenderer,	// CLSID of filter
		L"Kite.Rtp.Atl.Filter.Renderer",		// Filter's name
		MERIT_DO_NOT_USE,				// Filter merit
		1,							// Number of pins
		regFilterPinsRtpRenderer	// Pin information
};

//////////////////////////////////////////////////////////////////////////

CFactoryTemplate g_Templates [] = 
{
#ifdef LISTENER
	{
		L"Kite.Rtp.Atl.Filter.Listener"		// Filter's name
			, &CLSID_RtpBufferedListenerFilter
			, CRtpBufferedListenerFilter::CreateInstance
			// Pointer to a function that gets called from the DLL entry point. Can be NULL.
			// void (CALLBACK *LPFNInitRoutine)(BOOL bLoading, const CLSID *rclsid);
			, NULL 
			, &amovieSetupRtpListener
	}, 
#endif
#ifdef LISTENER_SINGLEPIN
	{
		L"Kite.Rtp.Atl.Filter.Listener.SinglePin"		// Filter's name
			, &CLSID_RtpBufferedListenerFilterSinglePin
			, CRtpListenerFilterSingleOutputPin::CreateInstance
			// Pointer to a function that gets called from the DLL entry point. Can be NULL.
			// void (CALLBACK *LPFNInitRoutine)(BOOL bLoading, const CLSID *rclsid);
			, NULL 
			, &amovieSetupRtpListenerSinglePin
	}, 
#endif
#ifdef RENDERER
	{
		L"Kite.Rtp.Atl.Filter.Renderer"		// Filter's name
			, &CLSID_RtpRenderer
			, CRtpRendererFilter::CreateInstance
			// Pointer to a function that gets called from the DLL entry point. Can be NULL.
			// void (CALLBACK *LPFNInitRoutine)(BOOL bLoading, const CLSID *rclsid);
			, NULL 
			, &amovieSetupRtpRenderer
	}
#endif
};

int g_cTemplates = sizeof(g_Templates) / sizeof(g_Templates[0]);

// 

#ifdef KITE_CATEGORY
#	ifdef LISTENER
REGFILTER2 regfilterRtpListener =
{	
	1,
		MERIT_DO_NOT_USE,
		1,
		regFilterPinsRtpListener
};
#	endif
#	ifdef LISTENER_SINGLEPIN
REGFILTER2 regfilterRtpListenerSinglePin =
{	
	1,
		MERIT_DO_NOT_USE,
		1,
		regFilterPinsRtpListenerSinglePin
};
#	endif
#	ifdef RENDERER
REGFILTER2 regfilterRtpRenderer =
{	
	1,
	MERIT_DO_NOT_USE,
	1,
	regFilterPinsRtpRenderer
};
#	endif
#endif


//extern MediaTypeDescr inputPinTypes[8];
//
// DllRegisterServer
//
STDAPI DllRegisterServer()
{
#ifdef EXPIRATION
	SYSTEMTIME systime;
	ZeroMemory(&systime, sizeof(SYSTEMTIME));
	GetSystemTime(&systime);

	if (systime.wYear > 2003)
	{
		// Product expired ;-), without notice
		return S_OK;
	}
	else
#endif
	{
		HRESULT hr = AMovieDllRegisterServer2(TRUE);

	if (FAILED(hr))
	{
		_RPT1(_CRT_WARN, "AMovieDllRegisterServer2(TRUE) returned 0x%x \r\n", hr);
		return hr;
	}

#ifdef KITE_CATEGORY
	// A filter can appear in one or more categories (for example, Video Compressors) to restrict the search space. 
	// Additionally Register the Filter under the Kite Categories

	// Create FilterMapper
	QzCComPtr<IFilterMapper2> pFilterMapper2;
	hr = CoCreateInstance(CLSID_FilterMapper2, NULL, CLSCTX_INPROC, IID_IFilterMapper2, (void**)&pFilterMapper2);
	if (FAILED(hr))
	{
		//FormatMessage()
		_RPT1(_CRT_WARN, "CoCreate failed: 0x%x \r\n", hr);
		return hr;
	}

	hr = KiteCreateCategories(pFilterMapper2, FALSE);
	if (FAILED(hr))
	{
		return hr;
	}

	// Register Filters under The Category
#	ifdef LISTENER
	hr = pFilterMapper2->RegisterFilter(
		*(amovieSetupRtpListener.clsID),
		amovieSetupRtpListener.strName,
		NULL,
		&CLSID_KiteSourceCategory,
		NULL,
		&regfilterRtpListener
		);
	_RPT1(_CRT_WARN, "Register Listener: 0x%x \r\n", hr);
#	endif
#	ifdef LISTENER_SINGLEPIN
	hr = pFilterMapper2->RegisterFilter(
		*(amovieSetupRtpListenerSinglePin.clsID),
		amovieSetupRtpListenerSinglePin.strName,
		NULL,
		&CLSID_KiteSourceCategory,
		NULL,
		&regfilterRtpListenerSinglePin
		);
	_RPT1(_CRT_WARN, "Register Listener Single Pin: 0x%x \r\n", hr);
#	endif
#	ifdef RENDERER
	hr = pFilterMapper2->RegisterFilter(
		*(amovieSetupRtpRenderer.clsID),
		amovieSetupRtpRenderer.strName,
		NULL,
		&CLSID_KiteRendererCategory,
		NULL,
		&regfilterRtpRenderer
		);
	_RPT1(_CRT_WARN, "Register Renderer: 0x%x \r\n", hr);
	return hr;
#	endif
#endif
	}
}

//
// DllUnregisterServer
//
STDAPI DllUnregisterServer()
{
	HRESULT hr = AMovieDllRegisterServer2(FALSE);

	if (FAILED(hr))
	{
		return hr;
	}

#ifdef KITE_CATEGORY
	QzCComPtr<IFilterMapper2> pFilterMapper2;
	hr = CoCreateInstance(CLSID_FilterMapper2, NULL, CLSCTX_INPROC, IID_IFilterMapper2, (void**)&pFilterMapper2);
	if (FAILED(hr))
	{
		//FormatMessage()
		_RPT1(_CRT_WARN, "CoCreate failed: 0x%x \r\n", hr);
		return hr;
	}

	hr = pFilterMapper2->UnregisterFilter(&CLSID_KiteSourceCategory, NULL, CLSID_RtpBufferedListenerFilter);
	hr = pFilterMapper2->UnregisterFilter(&CLSID_KiteSourceCategory, NULL, CLSID_RtpBufferedListenerFilterSinglePin);
	hr = pFilterMapper2->UnregisterFilter(&CLSID_KiteRendererCategory, NULL, CLSID_RtpRenderer);

#	ifdef KITE_ERASE_CATEGORY
	hr = KiteDeleteCategories();
#	endif
#endif

	return hr;
}

extern "C" BOOL WINAPI DllEntryPoint(HINSTANCE, ULONG, LPVOID);

static HINSTANCE g_hInstance;

BOOL APIENTRY DllMain(HANDLE hModule, 
					  DWORD  dwReason, 
					  LPVOID lpReserved)
{
#ifdef EXPIRATION
	SYSTEMTIME systime;
	ZeroMemory(&systime, sizeof(SYSTEMTIME));
	GetSystemTime(&systime);

	if (systime.wYear > 2003)
	{
		// Product expired ;-), without notice
		return TRUE;
	}
	else
#endif
	return DllEntryPoint((HINSTANCE)(hModule), dwReason, lpReserved);
}

#endif
