

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 6.00.0361 */
/* at Sun Nov 16 14:21:23 2003
 */
/* Compiler settings for _Kite.Rtp.Atl.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#if !defined(_M_IA64) && !defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IPlayoutBuffer,0x53F0C4D4,0x9926,0x4F1E,0xB0,0xFF,0x47,0xEA,0xF6,0xAA,0x1F,0x5A);


MIDL_DEFINE_GUID(IID, IID_IDisposable,0x53F0C4D5,0x9926,0x4F1E,0xB0,0xFF,0x47,0xEA,0xF6,0xAA,0x1F,0x5A);


MIDL_DEFINE_GUID(IID, IID_IRtpBufferedListenerFilterEventConsumer,0x1ABEA164,0x797F,0x4A07,0x93,0xAD,0x7D,0xAC,0xBE,0x47,0x7F,0x48);


MIDL_DEFINE_GUID(IID, IID_IRtpBufferedListenerFilterEventConsumerEx,0x1ABEA165,0x797F,0x4A07,0x93,0xAD,0x7D,0xAC,0xBE,0x47,0x7F,0x48);


MIDL_DEFINE_GUID(IID, IID_IRtpListenerEventConsumer,0x1ABEA162,0x797F,0x4A07,0x93,0xAD,0x7D,0xAC,0xBE,0x47,0x7F,0x48);


MIDL_DEFINE_GUID(IID, IID_IRtpBufferedListenerEventConsumer,0x1ABEA163,0x797F,0x4A07,0x93,0xAD,0x7D,0xAC,0xBE,0x47,0x7F,0x48);


MIDL_DEFINE_GUID(IID, IID_IRtpRendererEventConsumer,0x2ABEA162,0x797F,0x4A07,0x93,0xAD,0x7D,0xAC,0xBE,0x47,0x7F,0x48);


MIDL_DEFINE_GUID(IID, IID_IRtpReceiverStatistics,0xDC2F8E5E,0x17F2,0x4921,0x98,0x04,0xF1,0xEA,0xFD,0xD2,0x08,0x43);


MIDL_DEFINE_GUID(IID, IID_IRtpSenderStatistics,0xDC2F8E5F,0x17F2,0x4921,0x98,0x04,0xF1,0xEA,0xFD,0xD2,0x08,0x43);


MIDL_DEFINE_GUID(IID, IID_IInternetProtocolHelper,0x011B1D0D,0xBC47,0x46E7,0x98,0x59,0x8F,0x70,0x16,0xD9,0x65,0x43);


MIDL_DEFINE_GUID(IID, IID_IRtpListenerConfiguration,0xC24FF91D,0x56E8,0x4bf7,0x8E,0x4B,0x4B,0x44,0x09,0x86,0x2F,0xBB);


MIDL_DEFINE_GUID(IID, IID_IRtpListenerConfigurationOut,0xC24FF91C,0x56E8,0x4bf7,0x8E,0x4B,0x4B,0x44,0x09,0x86,0x2F,0xBB);


MIDL_DEFINE_GUID(IID, IID_IRtpListenerControl,0xC24FF91E,0x56E8,0x4bf7,0x8E,0x4B,0x4B,0x44,0x09,0x86,0x2F,0xBB);


MIDL_DEFINE_GUID(IID, IID_IRtpListenerCallbackRegistration,0xC24FF920,0x56E8,0x4bf7,0x8E,0x4B,0x4B,0x44,0x09,0x86,0x2F,0xBB);


MIDL_DEFINE_GUID(IID, IID_IRtpBufferedListener,0xC24FF921,0x56E8,0x4bf7,0x8E,0x4B,0x4B,0x44,0x09,0x86,0x2F,0xBB);


MIDL_DEFINE_GUID(IID, IID_IRtpBufferedListenerData,0xC24FF922,0x56E8,0x4bf7,0x8E,0x4B,0x4B,0x44,0x09,0x86,0x2F,0xBB);


MIDL_DEFINE_GUID(IID, IID_IRtpListener,0xC24FF923,0x56E8,0x4bf7,0x8E,0x4B,0x4B,0x44,0x09,0x86,0x2F,0xBB);


MIDL_DEFINE_GUID(IID, IID_IRtpPayloadPacketizer,0x66AA121D,0x17DD,0x469B,0x9D,0x25,0xC7,0xF7,0x25,0x0C,0xDD,0x99);


MIDL_DEFINE_GUID(IID, IID_IRtpRendererConfiguration,0xDA2B5441,0xD7AE,0x45c4,0xAE,0x59,0x86,0x20,0x36,0x15,0x25,0xDC);


MIDL_DEFINE_GUID(IID, IID_IRtpRendererConfigurationOut,0xDA2B5442,0xD7AE,0x45c4,0xAE,0x59,0x86,0x20,0x36,0x15,0x25,0xDC);


MIDL_DEFINE_GUID(IID, IID_IRtpRendererControl,0xDA2B5443,0xD7AE,0x45c4,0xAE,0x59,0x86,0x20,0x36,0x15,0x25,0xDC);


MIDL_DEFINE_GUID(IID, IID_IRtpRenderer,0x23AAF37A,0x90F4,0x48E9,0xB8,0x16,0x9E,0xEA,0xFE,0x49,0x12,0xA8);


MIDL_DEFINE_GUID(IID, IID_IRtpRendererFilterConfiguration_Export,0xDA2B5440,0xD7AE,0x45c4,0xAE,0x59,0x86,0x20,0x36,0x15,0x25,0xDC);


MIDL_DEFINE_GUID(IID, IID_IRtpListenerOutputPin_Export,0xD32EA7FB,0x59D2,0x4a6b,0xAC,0xCF,0xE7,0x0A,0x32,0x30,0x04,0xA3);


MIDL_DEFINE_GUID(IID, IID_IRtpBufferedListenerFilter_Export,0xD32EA7F5,0x59D2,0x4a6b,0xAC,0xCF,0xE7,0x0A,0x32,0x30,0x04,0xA3);


MIDL_DEFINE_GUID(IID, IID_IRtpBufferedListenerFilterSingleOutputPin_Export,0xD32EA7E5,0x59D2,0x4A6B,0xAC,0xCF,0xE7,0x0A,0x32,0x30,0x04,0xA3);


MIDL_DEFINE_GUID(IID, IID_ITestRtpJitterBuffer,0x7507A94E,0xB7EB,0x4974,0xA0,0xC4,0xCF,0xBF,0xA5,0xA7,0x48,0x74);


MIDL_DEFINE_GUID(IID, LIBID_KiteRtpAtl,0x2AE479B3,0xC267,0x4BD3,0xB0,0x9B,0xE1,0x85,0x06,0x06,0xEA,0xCC);


MIDL_DEFINE_GUID(CLSID, CLSID_CAudioPlayoutBuffer,0x9CC3E35B,0xB934,0x4CA8,0xA3,0x92,0xF4,0xF7,0x02,0xF8,0x8A,0x32);


MIDL_DEFINE_GUID(CLSID, CLSID_CVideoPlayoutBuffer,0xE493FD51,0x97B1,0x4126,0x82,0x9E,0x24,0xF6,0x3A,0x7F,0xD5,0x0D);


MIDL_DEFINE_GUID(CLSID, CLSID_CInternetProtocolHelper,0xA1A6FBF9,0x1273,0x4A9D,0x98,0xCF,0xD8,0xB8,0xDD,0x33,0x84,0xB1);


MIDL_DEFINE_GUID(IID, DIID__IRtpListenerEvents,0x23815B72,0xD00C,0x40EF,0xB3,0x73,0xFD,0x8D,0x4D,0xBA,0xD6,0x98);


MIDL_DEFINE_GUID(CLSID, CLSID_CRtpListener,0xD9A26C6D,0x69CB,0x4E73,0xA3,0x7E,0x6C,0x36,0x81,0x19,0x4C,0x32);


MIDL_DEFINE_GUID(CLSID, CLSID_CRtpBufferedListener,0xD9A26C6E,0x69CB,0x4E73,0xA3,0x7E,0x6C,0x36,0x81,0x19,0x4C,0x32);


MIDL_DEFINE_GUID(CLSID, CLSID_CRtpRenderer,0x7A6BE560,0x2C33,0x4426,0xBF,0x2B,0x17,0xB0,0xDC,0xCF,0xF5,0x23);


MIDL_DEFINE_GUID(CLSID, CLSID_CTest,0x07136823,0xBDF2,0x4A41,0xB9,0x65,0xCC,0xE9,0xE4,0x50,0xF4,0x1F);


MIDL_DEFINE_GUID(CLSID, CLSID_CTestRtpJitterBuffer,0x4DBA237A,0xC934,0x4521,0xA0,0x21,0x84,0x62,0x56,0xD1,0x1F,0xC7);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

