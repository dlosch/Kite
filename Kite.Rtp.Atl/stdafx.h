// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#pragma once

#ifndef STRICT
#define STRICT
#endif

// Modify the following defines if you have to target a platform prior to the ones specified below.
// Refer to MSDN for the latest info on corresponding values for different platforms.
#ifndef WINVER				// Allow use of features specific to Windows 95 and Windows NT 4 or later.
#define WINVER 0x0400		// Change this to the appropriate value to target Windows 98 and Windows 2000 or later.
#endif

#ifndef _WIN32_WINNT		// Allow use of features specific to Windows NT 4 or later.
//#define _WIN32_WINNT 0x0400	// Change this to the appropriate value to target Windows 2000 or later.
//#define _WIN32_WINNT 0x0403	// WinNT 4 SP3, InitCritSectAndSpinCount
#define _WIN32_WINNT 0x0500 // win2k or higher, required for ThreadPool
#endif						

#ifndef _WIN32_WINDOWS		// Allow use of features specific to Windows 98 or later.
#define _WIN32_WINDOWS 0x0410 // Change this to the appropriate value to target Windows Me or later.
#endif

#ifndef _WIN32_IE			// Allow use of features specific to IE 4.0 or later.
#define _WIN32_IE 0x0400	// Change this to the appropriate value to target IE 5.0 or later.
#endif

// If you do not define any of these macros for your project, _ATL_FREE_THREADED will be in effect.
// #define _ATL_APARTMENT_THREADED
// #define _ATL_FREE_THREADED // korrekt, alle coms sind "both" == STA or MTA

#define _ATL_NO_AUTOMATIC_NAMESPACE

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// some CString constructors will be explicit

// turns off ATL's hiding of some common and often safely ignored warning messages
#define _ATL_ALL_WARNINGS

#include <atlbase.h>
#include <atlcom.h>
#include <atlwin.h>
#include <atltypes.h>
#include <atlctl.h>
#include <atlhost.h>


using namespace ATL;

// 07.10.2003
#define S_PROPERTY_CHANGED                             ((HRESULT)0x00000002L)

#include "rtpidlexports.h"
#include "RtpStructs.h"
#include "IPlayoutBuffer.h"
#include "Utilities.h"
#include "WinsockHelper.h"

// .net perfmon-wrapper
#import "..\\..\\Kite.Rtp.PerformanceCounter\\Kite.Rtp.PerfMon.tlb" no_namespace /*raw_interfaces_only*/
#include "RtpListenerEventCallbacks.h"

#include "DebugHelpers.h"
#include "IRtpStatistics.h"

#include "AudioPlayoutBuffer.h"
#include "VideoPlayoutBuffer.h"
