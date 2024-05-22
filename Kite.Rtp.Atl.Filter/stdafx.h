// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once


#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

#define _WIN32_WINDOWS 0x0500	// win98 for WaitableTimer support (not in 95)
#define _WIN32_WINNT 0x0500	// win98 for WaitableTimer support (not in 95)

// Windows Header Files:
#include <windows.h>
// TODO: reference additional headers your program requires here
#include <tchar.h>

///
#include <atlcomcli.h>

//#define EXTERNAL_INTERFACES	1

// Include the rtp Stack via typelib
#import "..\\Kite.Rtp.Atl\\Kite.Rtp.Atl.tlb" no_namespace raw_interfaces_only  \
	rename("_AMMediaType", "x_AMMediaType") \
	rename("AM_MEDIA_TYPE", "xAM_MEDIA_TYPE") 

#include "kiteshareduuids.h"
#include "Utilities.h"
#include "IRtpBufferedListenerFilter.h"
#include "dxutil.h"