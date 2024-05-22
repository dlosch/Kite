

/* this ALWAYS GENERATED file contains the proxy stub code */


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
#if _MSC_VER >= 1200
#pragma warning(push)
#endif
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */
#pragma warning( disable: 4211 )  /* redefine extent to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif // __RPCPROXY_H_VERSION__


#include "_Kite.Rtp.Atl.h"

#define TYPE_FORMAT_STRING_SIZE   523                               
#define PROC_FORMAT_STRING_SIZE   4585                              
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   1            

typedef struct _MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } MIDL_TYPE_FORMAT_STRING;

typedef struct _MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } MIDL_PROC_FORMAT_STRING;


static RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString;
extern const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IPlayoutBuffer_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IPlayoutBuffer_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IDisposable_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IDisposable_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRtpBufferedListenerFilterEventConsumer_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRtpBufferedListenerFilterEventConsumer_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRtpBufferedListenerFilterEventConsumerEx_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRtpBufferedListenerFilterEventConsumerEx_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRtpListenerEventConsumer_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRtpListenerEventConsumer_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRtpBufferedListenerEventConsumer_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRtpBufferedListenerEventConsumer_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRtpRendererEventConsumer_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRtpRendererEventConsumer_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRtpReceiverStatistics_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRtpReceiverStatistics_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRtpSenderStatistics_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRtpSenderStatistics_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IInternetProtocolHelper_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IInternetProtocolHelper_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRtpListenerConfiguration_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRtpListenerConfiguration_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRtpListenerConfigurationOut_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRtpListenerConfigurationOut_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRtpListenerControl_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRtpListenerControl_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRtpListenerCallbackRegistration_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRtpListenerCallbackRegistration_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRtpBufferedListener_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRtpBufferedListener_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRtpBufferedListenerData_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRtpBufferedListenerData_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRtpListener_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRtpListener_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRtpPayloadPacketizer_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRtpPayloadPacketizer_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRtpRendererConfiguration_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRtpRendererConfiguration_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRtpRendererConfigurationOut_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRtpRendererConfigurationOut_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRtpRendererControl_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRtpRendererControl_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRtpRenderer_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRtpRenderer_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRtpRendererFilterConfiguration_Export_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRtpRendererFilterConfiguration_Export_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRtpListenerOutputPin_Export_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRtpListenerOutputPin_Export_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRtpBufferedListenerFilter_Export_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRtpBufferedListenerFilter_Export_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRtpBufferedListenerFilterSingleOutputPin_Export_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRtpBufferedListenerFilterSingleOutputPin_Export_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ITestRtpJitterBuffer_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ITestRtpJitterBuffer_ProxyInfo;


extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT50_OR_LATER)
#error You need a Windows 2000 or later to run this stub because it uses these features:
#error   /robust command line switch.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will die there with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure EnqueuePacket */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x3 ),	/* 3 */
/*  8 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10 */	NdrFcShort( 0x5d ),	/* 93 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 16 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPacket */

/* 24 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 26 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 28 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Return value */

/* 30 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 32 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 34 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DequeuePackets */

/* 36 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 38 */	NdrFcLong( 0x0 ),	/* 0 */
/* 42 */	NdrFcShort( 0x4 ),	/* 4 */
/* 44 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 46 */	NdrFcShort( 0xa1 ),	/* 161 */
/* 48 */	NdrFcShort( 0x8 ),	/* 8 */
/* 50 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 52 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 54 */	NdrFcShort( 0x0 ),	/* 0 */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */
/* 58 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pppRtpParsedPackets */

/* 60 */	NdrFcShort( 0x200a ),	/* Flags:  must free, in, srv alloc size=8 */
/* 62 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 64 */	NdrFcShort( 0x22 ),	/* Type Offset=34 */

	/* Parameter pcPackets */

/* 66 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 68 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 70 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 72 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 74 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 76 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetJitterBufferParameter */


	/* Procedure ExpireOlderThanOrEqual */

/* 78 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 80 */	NdrFcLong( 0x0 ),	/* 0 */
/* 84 */	NdrFcShort( 0x5 ),	/* 5 */
/* 86 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 88 */	NdrFcShort( 0x8 ),	/* 8 */
/* 90 */	NdrFcShort( 0x8 ),	/* 8 */
/* 92 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 94 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 96 */	NdrFcShort( 0x0 ),	/* 0 */
/* 98 */	NdrFcShort( 0x0 ),	/* 0 */
/* 100 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter uLatency */


	/* Parameter uTimestamp */

/* 102 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 104 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 106 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 108 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 110 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 112 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ClearBuffer */

/* 114 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 116 */	NdrFcLong( 0x0 ),	/* 0 */
/* 120 */	NdrFcShort( 0x6 ),	/* 6 */
/* 122 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 124 */	NdrFcShort( 0x0 ),	/* 0 */
/* 126 */	NdrFcShort( 0x8 ),	/* 8 */
/* 128 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 130 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 132 */	NdrFcShort( 0x0 ),	/* 0 */
/* 134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 136 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 138 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 140 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 142 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetBufferParameter */

/* 144 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 146 */	NdrFcLong( 0x0 ),	/* 0 */
/* 150 */	NdrFcShort( 0x7 ),	/* 7 */
/* 152 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 154 */	NdrFcShort( 0x18 ),	/* 24 */
/* 156 */	NdrFcShort( 0x8 ),	/* 8 */
/* 158 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 160 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 164 */	NdrFcShort( 0x0 ),	/* 0 */
/* 166 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter uBufferDurationMilliseconds */

/* 168 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 170 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 172 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter uTimestampIncrementPerSecond */

/* 174 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 176 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 178 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter uTimePerFrameNanos */

/* 180 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 182 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 184 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 186 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 188 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 190 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetLatency */

/* 192 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 194 */	NdrFcLong( 0x0 ),	/* 0 */
/* 198 */	NdrFcShort( 0x8 ),	/* 8 */
/* 200 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 202 */	NdrFcShort( 0x8 ),	/* 8 */
/* 204 */	NdrFcShort( 0x8 ),	/* 8 */
/* 206 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 208 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 214 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter uLatency */

/* 216 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 218 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 220 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 222 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 224 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 226 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddOutputPin */


	/* Procedure GetLatency */

/* 228 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 230 */	NdrFcLong( 0x0 ),	/* 0 */
/* 234 */	NdrFcShort( 0x9 ),	/* 9 */
/* 236 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 238 */	NdrFcShort( 0x1c ),	/* 28 */
/* 240 */	NdrFcShort( 0x8 ),	/* 8 */
/* 242 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 244 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 246 */	NdrFcShort( 0x0 ),	/* 0 */
/* 248 */	NdrFcShort( 0x0 ),	/* 0 */
/* 250 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pIndex */


	/* Parameter puLatency */

/* 252 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 254 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 256 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 258 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 260 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 262 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_LocalSsrc */


	/* Procedure SetMuted */

/* 264 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 266 */	NdrFcLong( 0x0 ),	/* 0 */
/* 270 */	NdrFcShort( 0xa ),	/* 10 */
/* 272 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 274 */	NdrFcShort( 0x8 ),	/* 8 */
/* 276 */	NdrFcShort( 0x8 ),	/* 8 */
/* 278 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 280 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 282 */	NdrFcShort( 0x0 ),	/* 0 */
/* 284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 286 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */


	/* Parameter bMuted */

/* 288 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 290 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 292 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 294 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 296 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 298 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMuted */

/* 300 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 302 */	NdrFcLong( 0x0 ),	/* 0 */
/* 306 */	NdrFcShort( 0xb ),	/* 11 */
/* 308 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 310 */	NdrFcShort( 0x1c ),	/* 28 */
/* 312 */	NdrFcShort( 0x8 ),	/* 8 */
/* 314 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 316 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 318 */	NdrFcShort( 0x0 ),	/* 0 */
/* 320 */	NdrFcShort( 0x0 ),	/* 0 */
/* 322 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbMuted */

/* 324 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 326 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 328 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 330 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 332 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 334 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_PayloadType */

/* 336 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 338 */	NdrFcLong( 0x0 ),	/* 0 */
/* 342 */	NdrFcShort( 0xc ),	/* 12 */
/* 344 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 346 */	NdrFcShort( 0x0 ),	/* 0 */
/* 348 */	NdrFcShort( 0x21 ),	/* 33 */
/* 350 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 352 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 354 */	NdrFcShort( 0x0 ),	/* 0 */
/* 356 */	NdrFcShort( 0x0 ),	/* 0 */
/* 358 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 360 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 362 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 364 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Return value */

/* 366 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 368 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 370 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_PayloadType */

/* 372 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 374 */	NdrFcLong( 0x0 ),	/* 0 */
/* 378 */	NdrFcShort( 0xd ),	/* 13 */
/* 380 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 382 */	NdrFcShort( 0x5 ),	/* 5 */
/* 384 */	NdrFcShort( 0x8 ),	/* 8 */
/* 386 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 388 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 390 */	NdrFcShort( 0x0 ),	/* 0 */
/* 392 */	NdrFcShort( 0x0 ),	/* 0 */
/* 394 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 396 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 398 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 400 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Return value */

/* 402 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 404 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 406 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_DueTime */

/* 408 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 410 */	NdrFcLong( 0x0 ),	/* 0 */
/* 414 */	NdrFcShort( 0xe ),	/* 14 */
/* 416 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 418 */	NdrFcShort( 0x0 ),	/* 0 */
/* 420 */	NdrFcShort( 0x24 ),	/* 36 */
/* 422 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 424 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 426 */	NdrFcShort( 0x0 ),	/* 0 */
/* 428 */	NdrFcShort( 0x0 ),	/* 0 */
/* 430 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDueTimeMilliseconds */

/* 432 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 434 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 436 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 438 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 440 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 442 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_EventHandle */

/* 444 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 446 */	NdrFcLong( 0x0 ),	/* 0 */
/* 450 */	NdrFcShort( 0xf ),	/* 15 */
/* 452 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 454 */	NdrFcShort( 0x0 ),	/* 0 */
/* 456 */	NdrFcShort( 0x38 ),	/* 56 */
/* 458 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 460 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 462 */	NdrFcShort( 0x0 ),	/* 0 */
/* 464 */	NdrFcShort( 0x0 ),	/* 0 */
/* 466 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pEventHandle */

/* 468 */	NdrFcShort( 0x2012 ),	/* Flags:  must free, out, srv alloc size=8 */
/* 470 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 472 */	NdrFcShort( 0x3a ),	/* Type Offset=58 */

	/* Return value */

/* 474 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 476 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 478 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_BufferDurationMilliseconds */

/* 480 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 482 */	NdrFcLong( 0x0 ),	/* 0 */
/* 486 */	NdrFcShort( 0x10 ),	/* 16 */
/* 488 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 490 */	NdrFcShort( 0x0 ),	/* 0 */
/* 492 */	NdrFcShort( 0x24 ),	/* 36 */
/* 494 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 496 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 498 */	NdrFcShort( 0x0 ),	/* 0 */
/* 500 */	NdrFcShort( 0x0 ),	/* 0 */
/* 502 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 504 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 506 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 508 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 510 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 512 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 514 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_BufferDurationMilliseconds */

/* 516 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 518 */	NdrFcLong( 0x0 ),	/* 0 */
/* 522 */	NdrFcShort( 0x11 ),	/* 17 */
/* 524 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 526 */	NdrFcShort( 0x8 ),	/* 8 */
/* 528 */	NdrFcShort( 0x8 ),	/* 8 */
/* 530 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 532 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 534 */	NdrFcShort( 0x0 ),	/* 0 */
/* 536 */	NdrFcShort( 0x0 ),	/* 0 */
/* 538 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 540 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 542 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 544 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 546 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 548 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 550 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_RtpTimestampIncrementPerSecond */

/* 552 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 554 */	NdrFcLong( 0x0 ),	/* 0 */
/* 558 */	NdrFcShort( 0x12 ),	/* 18 */
/* 560 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 562 */	NdrFcShort( 0x0 ),	/* 0 */
/* 564 */	NdrFcShort( 0x24 ),	/* 36 */
/* 566 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 568 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 570 */	NdrFcShort( 0x0 ),	/* 0 */
/* 572 */	NdrFcShort( 0x0 ),	/* 0 */
/* 574 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 576 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 578 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 580 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 582 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 584 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 586 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_RtpTimestampIncrementPerSecond */

/* 588 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 590 */	NdrFcLong( 0x0 ),	/* 0 */
/* 594 */	NdrFcShort( 0x13 ),	/* 19 */
/* 596 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 598 */	NdrFcShort( 0x8 ),	/* 8 */
/* 600 */	NdrFcShort( 0x8 ),	/* 8 */
/* 602 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 604 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 606 */	NdrFcShort( 0x0 ),	/* 0 */
/* 608 */	NdrFcShort( 0x0 ),	/* 0 */
/* 610 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 612 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 614 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 616 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 618 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 620 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 622 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_TimePerSampleNanos */

/* 624 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 626 */	NdrFcLong( 0x0 ),	/* 0 */
/* 630 */	NdrFcShort( 0x14 ),	/* 20 */
/* 632 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 634 */	NdrFcShort( 0x0 ),	/* 0 */
/* 636 */	NdrFcShort( 0x24 ),	/* 36 */
/* 638 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 640 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 642 */	NdrFcShort( 0x0 ),	/* 0 */
/* 644 */	NdrFcShort( 0x0 ),	/* 0 */
/* 646 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 648 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 650 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 652 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 654 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 656 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 658 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_TimePerSampleNanos */

/* 660 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 662 */	NdrFcLong( 0x0 ),	/* 0 */
/* 666 */	NdrFcShort( 0x15 ),	/* 21 */
/* 668 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 670 */	NdrFcShort( 0x8 ),	/* 8 */
/* 672 */	NdrFcShort( 0x8 ),	/* 8 */
/* 674 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 676 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 678 */	NdrFcShort( 0x0 ),	/* 0 */
/* 680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 682 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 684 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 686 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 688 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 690 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 692 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 694 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_MaxBufferSize */


	/* Procedure get_Disposed */

/* 696 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 698 */	NdrFcLong( 0x0 ),	/* 0 */
/* 702 */	NdrFcShort( 0x3 ),	/* 3 */
/* 704 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 706 */	NdrFcShort( 0x0 ),	/* 0 */
/* 708 */	NdrFcShort( 0x24 ),	/* 36 */
/* 710 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 712 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 714 */	NdrFcShort( 0x0 ),	/* 0 */
/* 716 */	NdrFcShort( 0x0 ),	/* 0 */
/* 718 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pcbMtu */


	/* Parameter pVal */

/* 720 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 722 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 724 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 726 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 728 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 730 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure TestAudioBuffer */


	/* Procedure Stop */


	/* Procedure Stop */


	/* Procedure Dispose */

/* 732 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 734 */	NdrFcLong( 0x0 ),	/* 0 */
/* 738 */	NdrFcShort( 0x4 ),	/* 4 */
/* 740 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 742 */	NdrFcShort( 0x0 ),	/* 0 */
/* 744 */	NdrFcShort( 0x8 ),	/* 8 */
/* 746 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 748 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 750 */	NdrFcShort( 0x0 ),	/* 0 */
/* 752 */	NdrFcShort( 0x0 ),	/* 0 */
/* 754 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 756 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 758 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 760 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ReceiverReportReceived */


	/* Procedure ActiveSourceAdded */


	/* Procedure ActiveSourceAdded */

/* 762 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 764 */	NdrFcLong( 0x0 ),	/* 0 */
/* 768 */	NdrFcShort( 0x3 ),	/* 3 */
/* 770 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 772 */	NdrFcShort( 0x8 ),	/* 8 */
/* 774 */	NdrFcShort( 0x8 ),	/* 8 */
/* 776 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 778 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 780 */	NdrFcShort( 0x0 ),	/* 0 */
/* 782 */	NdrFcShort( 0x0 ),	/* 0 */
/* 784 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ssrcReportSource */


	/* Parameter ssrc */


	/* Parameter ssrc */

/* 786 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 788 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 790 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 792 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 794 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 796 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_MaxBufferSize */


	/* Procedure SubscribeSsrc */


	/* Procedure ActiveSourceRemoved */


	/* Procedure ActiveSourceRemoved */

/* 798 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 800 */	NdrFcLong( 0x0 ),	/* 0 */
/* 804 */	NdrFcShort( 0x4 ),	/* 4 */
/* 806 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 808 */	NdrFcShort( 0x8 ),	/* 8 */
/* 810 */	NdrFcShort( 0x8 ),	/* 8 */
/* 812 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 814 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 816 */	NdrFcShort( 0x0 ),	/* 0 */
/* 818 */	NdrFcShort( 0x0 ),	/* 0 */
/* 820 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cbMtu */


	/* Parameter ssrc */


	/* Parameter ssrc */


	/* Parameter ssrc */

/* 822 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 824 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 826 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 828 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 830 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 832 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetRtpBandwidth */


	/* Procedure ActiveSourceChanged */


	/* Procedure SourceActiveValueChanged */

/* 834 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 836 */	NdrFcLong( 0x0 ),	/* 0 */
/* 840 */	NdrFcShort( 0x5 ),	/* 5 */
/* 842 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 844 */	NdrFcShort( 0x10 ),	/* 16 */
/* 846 */	NdrFcShort( 0x8 ),	/* 8 */
/* 848 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 850 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 852 */	NdrFcShort( 0x0 ),	/* 0 */
/* 854 */	NdrFcShort( 0x0 ),	/* 0 */
/* 856 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter uSessionBandwidth */


	/* Parameter ssrc */


	/* Parameter ssrc */

/* 858 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 860 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 862 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bEnforce */


	/* Parameter eventType */


	/* Parameter active */

/* 864 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 866 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 868 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 870 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 872 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 874 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetRtpBandwidth */


	/* Procedure SourceMuteValueChanged */

/* 876 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 878 */	NdrFcLong( 0x0 ),	/* 0 */
/* 882 */	NdrFcShort( 0x6 ),	/* 6 */
/* 884 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 886 */	NdrFcShort( 0x10 ),	/* 16 */
/* 888 */	NdrFcShort( 0x8 ),	/* 8 */
/* 890 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 892 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 894 */	NdrFcShort( 0x0 ),	/* 0 */
/* 896 */	NdrFcShort( 0x0 ),	/* 0 */
/* 898 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter uSessionBandwidth */


	/* Parameter ssrc */

/* 900 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 902 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 904 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bEnforce */


	/* Parameter muted */

/* 906 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 908 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 910 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 912 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 914 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 916 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetJitterBufferParameter */


	/* Procedure SetRtpBandwidth */


	/* Procedure SourceEvent */

/* 918 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 920 */	NdrFcLong( 0x0 ),	/* 0 */
/* 924 */	NdrFcShort( 0x7 ),	/* 7 */
/* 926 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 928 */	NdrFcShort( 0x10 ),	/* 16 */
/* 930 */	NdrFcShort( 0x8 ),	/* 8 */
/* 932 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 934 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 936 */	NdrFcShort( 0x0 ),	/* 0 */
/* 938 */	NdrFcShort( 0x0 ),	/* 0 */
/* 940 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ssrc */


	/* Parameter uSessionBandwidth */


	/* Parameter ssrc */

/* 942 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 944 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 946 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter uLatency */


	/* Parameter bEnforce */


	/* Parameter eventType */

/* 948 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 950 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 952 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 954 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 956 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 958 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SourceReception */

/* 960 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 962 */	NdrFcLong( 0x0 ),	/* 0 */
/* 966 */	NdrFcShort( 0x8 ),	/* 8 */
/* 968 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 970 */	NdrFcShort( 0x30 ),	/* 48 */
/* 972 */	NdrFcShort( 0x8 ),	/* 8 */
/* 974 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x7,		/* 7 */
/* 976 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 978 */	NdrFcShort( 0x0 ),	/* 0 */
/* 980 */	NdrFcShort( 0x0 ),	/* 0 */
/* 982 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ssrc */

/* 984 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 986 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 988 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter packetsRecvd */

/* 990 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 992 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 994 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter packetsLost */

/* 996 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 998 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1000 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter packetsMisordered */

/* 1002 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1004 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1006 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter jitter */

/* 1008 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1010 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1012 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter validityTime */

/* 1014 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1016 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1018 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1020 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1022 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1024 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SourceAttributes */

/* 1026 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1028 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1032 */	NdrFcShort( 0x9 ),	/* 9 */
/* 1034 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 1036 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1038 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1040 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x9,		/* 9 */
/* 1042 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1044 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1046 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1048 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ssrc */

/* 1050 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1052 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1054 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter cname */

/* 1056 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1058 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1060 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Parameter name */

/* 1062 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1064 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1066 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Parameter email */

/* 1068 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1070 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1072 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Parameter phone */

/* 1074 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1076 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1078 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Parameter loc */

/* 1080 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1082 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1084 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Parameter tool */

/* 1086 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1088 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1090 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Parameter note */

/* 1092 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1094 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1096 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Return value */

/* 1098 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1100 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 1102 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPacketLoss */

/* 1104 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1106 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1110 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1112 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1114 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1116 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1118 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1120 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1122 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1124 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1126 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ssrc */

/* 1128 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1130 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1132 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pdblPacketLoss */

/* 1134 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1136 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1138 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 1140 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1142 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1144 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetReceptionStatistics */

/* 1146 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1148 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1152 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1154 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1156 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1158 */	NdrFcShort( 0x5c ),	/* 92 */
/* 1160 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 1162 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1164 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1166 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1168 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ssrc */

/* 1170 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1172 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1174 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pcPacketsReceived */

/* 1176 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1178 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1180 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pcPacketsLost */

/* 1182 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1184 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1186 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pJitter */

/* 1188 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1190 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1192 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1194 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1196 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1198 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPerformanceCounterPrefix */

/* 1200 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1202 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1206 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1208 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1210 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1212 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1214 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 1216 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 1218 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1220 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1222 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ssrc */

/* 1224 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1226 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1228 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter szPerfCounterPrefix */

/* 1230 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 1232 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1234 */	NdrFcShort( 0x4e ),	/* Type Offset=78 */

	/* Parameter cchPerfCounterPrefix */

/* 1236 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1238 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1240 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1242 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1244 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1246 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSenderStatistics */

/* 1248 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1250 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1254 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1256 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1258 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1260 */	NdrFcShort( 0x5c ),	/* 92 */
/* 1262 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 1264 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1266 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1268 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1270 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pcPacketsSent */

/* 1272 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1274 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1276 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pcOctetsSent */

/* 1278 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1280 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1282 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pMillisecs */

/* 1284 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1286 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1288 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1290 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1292 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1294 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStatisticsForReceiver */

/* 1296 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1298 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1302 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1304 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1306 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1308 */	NdrFcShort( 0x59 ),	/* 89 */
/* 1310 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 1312 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1314 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1316 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1318 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ssrcRRSource */

/* 1320 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1322 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1324 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pFractionLost */

/* 1326 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1328 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1330 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter pcCumulativeNumberOfPacketsLost */

/* 1332 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1334 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1336 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pInterarrivalJitter */

/* 1338 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1340 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1342 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1344 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1346 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1348 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPerformanceCounterPrefix */

/* 1350 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1352 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1356 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1358 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1360 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1362 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1364 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 1366 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 1368 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1370 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1372 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ssrc */

/* 1374 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1376 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1378 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter szPerfCounterPrefix */

/* 1380 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 1382 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1384 */	NdrFcShort( 0x5a ),	/* Type Offset=90 */

	/* Parameter cchPerfCounterPrefix */

/* 1386 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1388 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1390 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1392 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1394 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1396 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure QueryMtuForInterface */

/* 1398 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1400 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1404 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1406 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1408 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1410 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1412 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1414 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1416 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1418 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1420 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter interfaceIndex */

/* 1422 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1424 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1426 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pMtu */

/* 1428 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1430 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1432 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1434 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1436 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1438 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAdapterInfoConcise */

/* 1440 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1442 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1446 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1448 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1450 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1452 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1454 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1456 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 1458 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1460 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1462 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter interfaceIndex */

/* 1464 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1466 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1468 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pInterfaceInfo */

/* 1470 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 1472 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1474 */	NdrFcShort( 0x8a ),	/* Type Offset=138 */

	/* Return value */

/* 1476 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1478 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1480 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAdapterInfoConciseForAllAdapters */

/* 1482 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1484 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1488 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1490 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1492 */	NdrFcShort( 0x1c ),	/* 28 */
/* 1494 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1496 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1498 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 1500 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1502 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1504 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pInterfaceInfo */

/* 1506 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 1508 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1510 */	NdrFcShort( 0x8a ),	/* Type Offset=138 */

	/* Parameter pcAdapters */

/* 1512 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 1514 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1516 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1518 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1520 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1522 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindAdapterForAddress */

/* 1524 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1526 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1530 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1532 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1534 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1536 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1538 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1540 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1542 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1544 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1546 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrAddress */

/* 1548 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1550 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1552 */	NdrFcShort( 0x9e ),	/* Type Offset=158 */

	/* Parameter pIndex */

/* 1554 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1556 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1558 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1560 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1562 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1564 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetNetworkParameter */


	/* Procedure SetNetworkParameter */

/* 1566 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1568 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1572 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1574 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1576 */	NdrFcShort( 0x14 ),	/* 20 */
/* 1578 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1580 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 1582 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1584 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1588 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter szRemoteAddress */


	/* Parameter szRemoteAddress */

/* 1590 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1592 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1594 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Parameter uRemotePort */


	/* Parameter uRemotePort */

/* 1596 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1598 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1600 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter szLocalInterface */


	/* Parameter szLocalInterface */

/* 1602 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1604 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1606 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Parameter uLocalInterface */


	/* Parameter uLocalPort */

/* 1608 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1610 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1612 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter ttl */


	/* Parameter ttl */

/* 1614 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1616 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1618 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 1620 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1622 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1624 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMediaParameterDefaults */

/* 1626 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1628 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1632 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1634 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1636 */	NdrFcShort( 0x25 ),	/* 37 */
/* 1638 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1640 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x6,		/* 6 */
/* 1642 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1644 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1646 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1648 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bAduSpansMultiplePackets */

/* 1650 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1652 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1654 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter payloadType */

/* 1656 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1658 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1660 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter uRtpTimeStampIncrementPerSecond */

/* 1662 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1664 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1666 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter uExpectedTimePerAduNanoseconds */

/* 1668 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1670 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1672 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bUpdateExistingBuffers */

/* 1674 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1676 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1678 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1680 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1682 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1684 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ReserveNetworkAddressAndCreateSockets */

/* 1686 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1688 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1692 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1694 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1696 */	NdrFcShort( 0x14 ),	/* 20 */
/* 1698 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1700 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 1702 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1704 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1706 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1708 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter szRemoteAddress */

/* 1710 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1712 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1714 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Parameter szLocalInterface */

/* 1716 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 1718 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1720 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Parameter uMinLocalPort */

/* 1722 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1724 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1726 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter uMaxLocalPort */

/* 1728 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1730 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1732 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter ttl */

/* 1734 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1736 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1738 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1740 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1742 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1744 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ReserveNetworkAddress */

/* 1746 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1748 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1752 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1754 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 1756 */	NdrFcShort( 0x14 ),	/* 20 */
/* 1758 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1760 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 1762 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1764 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1766 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1768 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter szRemoteAddress */

/* 1770 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1772 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1774 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Parameter szLocalInterface */

/* 1776 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1778 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1780 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Parameter uMinLocalPort */

/* 1782 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1784 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1786 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter uMaxLocalPort */

/* 1788 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1790 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1792 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter szLocalInterfaceOut */

/* 1794 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 1796 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1798 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Parameter cchLocal */

/* 1800 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1802 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1804 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter puLocalPort */

/* 1806 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1808 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1810 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1812 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1814 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1816 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_LocalSsrc */

/* 1818 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1820 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1824 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1826 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1828 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1830 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1832 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1834 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1836 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1838 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1840 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 1842 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1844 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1846 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1848 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1850 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1852 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_LocalSsrc */

/* 1854 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1856 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1860 */	NdrFcShort( 0x9 ),	/* 9 */
/* 1862 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1864 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1866 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1868 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1870 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1872 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1874 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1876 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 1878 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1880 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1882 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1884 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1886 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1888 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetNetworkParameter */


	/* Procedure GetNetworkParameter */

/* 1890 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1892 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1896 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1898 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 1900 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1902 */	NdrFcShort( 0x58 ),	/* 88 */
/* 1904 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 1906 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1908 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1910 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1912 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter szRemoteAddress */


	/* Parameter szRemoteAddress */

/* 1914 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 1916 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1918 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Parameter cchRemoteAddress */


	/* Parameter cchRemoteAddress */

/* 1920 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1922 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1924 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter puRemotePort */


	/* Parameter puRemotePort */

/* 1926 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1928 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1930 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter szLocalInterface */


	/* Parameter szLocalInterface */

/* 1932 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 1934 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1936 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Parameter cchLocalAddress */


	/* Parameter cchLocalAddress */

/* 1938 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1940 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1942 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter puLocalPortBase */


	/* Parameter puLocalPortBase */

/* 1944 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1946 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1948 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pTtl */


	/* Parameter pTtl */

/* 1950 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1952 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1954 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 1956 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1958 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1960 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Test */


	/* Procedure Start */


	/* Procedure Start */

/* 1962 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1964 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1968 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1970 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1972 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1974 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1976 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1978 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1980 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1982 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1984 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 1986 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1988 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1990 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RegisterCallback */

/* 1992 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1994 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1998 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2000 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2002 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2004 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2006 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2008 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2010 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2012 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2014 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pEventConsumer */

/* 2016 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2018 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2020 */	NdrFcShort( 0xac ),	/* Type Offset=172 */

	/* Return value */

/* 2022 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2024 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2026 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPlayoutBufferGuid */

/* 2028 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2030 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2034 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2036 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2038 */	NdrFcShort( 0x44 ),	/* 68 */
/* 2040 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2042 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2044 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2046 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2048 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2050 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter playoutBufferGuid */

/* 2052 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 2054 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2056 */	NdrFcShort( 0xc8 ),	/* Type Offset=200 */

	/* Return value */

/* 2058 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2060 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2062 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SubscribeSsrcAndGetPointerEx */

/* 2064 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2066 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2070 */	NdrFcShort( 0x5 ),	/* 5 */
/* 2072 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2074 */	NdrFcShort( 0x61 ),	/* 97 */
/* 2076 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2078 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x7,		/* 7 */
/* 2080 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2082 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2084 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2086 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ssrc */

/* 2088 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2090 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2092 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter guidJitterBuffer */

/* 2094 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 2096 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2098 */	NdrFcShort( 0xc8 ),	/* Type Offset=200 */

	/* Parameter payloadType */

/* 2100 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2102 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2104 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter uRtpTimeStampIncrementPerSecond */

/* 2106 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2108 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2110 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter uExpectedTimePerAduNanoseconds */

/* 2112 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2114 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2116 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppPlayoutBuffer */

/* 2118 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2120 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2122 */	NdrFcShort( 0xd4 ),	/* Type Offset=212 */

	/* Return value */

/* 2124 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2126 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2128 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UnsubscribeSsrc */

/* 2130 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2132 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2136 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2138 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2140 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2142 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2144 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2146 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2148 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2150 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2152 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ssrc */

/* 2154 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2156 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2158 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2160 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2162 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2164 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSubscribedSourcesCount */

/* 2166 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2168 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2172 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2174 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2176 */	NdrFcShort( 0x1c ),	/* 28 */
/* 2178 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2180 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2182 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2184 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2186 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2188 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pcSubscribed */

/* 2190 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 2192 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2194 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2196 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2198 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2200 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSubscribedSources */

/* 2202 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2204 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2208 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2210 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2212 */	NdrFcShort( 0x4c ),	/* 76 */
/* 2214 */	NdrFcShort( 0x54 ),	/* 84 */
/* 2216 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2218 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2220 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2222 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2224 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSubscribedSources */

/* 2226 */	NdrFcShort( 0x201a ),	/* Flags:  must free, in, out, srv alloc size=8 */
/* 2228 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2230 */	NdrFcShort( 0x3a ),	/* Type Offset=58 */

	/* Parameter pcSubscribedSources */

/* 2232 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 2234 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2236 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2238 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2240 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2242 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetActiveSourcesCount */

/* 2244 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2246 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2250 */	NdrFcShort( 0x9 ),	/* 9 */
/* 2252 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2254 */	NdrFcShort( 0x1c ),	/* 28 */
/* 2256 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2258 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2260 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2262 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2264 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2266 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pcActive */

/* 2268 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 2270 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2272 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2274 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2276 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2278 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetActiveSources */

/* 2280 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2282 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2286 */	NdrFcShort( 0xa ),	/* 10 */
/* 2288 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2290 */	NdrFcShort( 0x4c ),	/* 76 */
/* 2292 */	NdrFcShort( 0x54 ),	/* 84 */
/* 2294 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2296 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2300 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2302 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pActiveSources */

/* 2304 */	NdrFcShort( 0x201a ),	/* Flags:  must free, in, out, srv alloc size=8 */
/* 2306 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2308 */	NdrFcShort( 0x3a ),	/* Type Offset=58 */

	/* Parameter pcActiveSources */

/* 2310 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 2312 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2314 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2316 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2318 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2320 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMuted */

/* 2322 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2324 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2328 */	NdrFcShort( 0xb ),	/* 11 */
/* 2330 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2332 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2334 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2336 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2338 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2340 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2342 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2344 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ssrc */

/* 2346 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2348 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2350 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bMuted */

/* 2352 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2354 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2356 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2358 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2360 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2362 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMuted */

/* 2364 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2366 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2370 */	NdrFcShort( 0xc ),	/* 12 */
/* 2372 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2374 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2376 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2378 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2380 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2384 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2386 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ssrc */

/* 2388 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2390 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2392 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pbIsMuted */

/* 2394 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 2396 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2398 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2400 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2402 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2404 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetJitterBufferLatency */

/* 2406 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2408 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2412 */	NdrFcShort( 0xd ),	/* 13 */
/* 2414 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2416 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2418 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2420 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2422 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2424 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2426 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2428 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ssrc */

/* 2430 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2432 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2434 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter uLatency */

/* 2436 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2438 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2440 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2442 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2444 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2446 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetJitterBufferLatency */

/* 2448 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2450 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2454 */	NdrFcShort( 0xe ),	/* 14 */
/* 2456 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2458 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2460 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2462 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2464 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2466 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2468 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2470 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ssrc */

/* 2472 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2474 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2476 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter puLatency */

/* 2478 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 2480 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2482 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2484 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2486 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2488 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDeliveryUnit */

/* 2490 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2492 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2496 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2498 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2500 */	NdrFcShort( 0xa9 ),	/* 169 */
/* 2502 */	NdrFcShort( 0xa9 ),	/* 169 */
/* 2504 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 2506 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2508 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2510 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2512 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ssrc */

/* 2514 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2516 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2518 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pppDeliveryUnit */

/* 2520 */	NdrFcShort( 0x201a ),	/* Flags:  must free, in, out, srv alloc size=8 */
/* 2522 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2524 */	NdrFcShort( 0xea ),	/* Type Offset=234 */

	/* Parameter pcPackets */

/* 2526 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 2528 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2530 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2532 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2534 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2536 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRtcpAttributes */

/* 2538 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2540 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2544 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2546 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2548 */	NdrFcShort( 0x79c ),	/* 1948 */
/* 2550 */	NdrFcShort( 0x79c ),	/* 1948 */
/* 2552 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2554 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2556 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2558 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2560 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ssrc */

/* 2562 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2564 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2566 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pSdesItems */

/* 2568 */	NdrFcShort( 0x11a ),	/* Flags:  must free, in, out, simple ref, */
/* 2570 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2572 */	NdrFcShort( 0x100 ),	/* Type Offset=256 */

	/* Return value */

/* 2574 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2576 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2578 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSessionMemberInfo */

/* 2580 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2582 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2586 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2588 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2590 */	NdrFcShort( 0x7e0 ),	/* 2016 */
/* 2592 */	NdrFcShort( 0x7d8 ),	/* 2008 */
/* 2594 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 2596 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2598 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2600 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2602 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ssrc */

/* 2604 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2606 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2608 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pSessionMemberInfo */

/* 2610 */	NdrFcShort( 0x11a ),	/* Flags:  must free, in, out, simple ref, */
/* 2612 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2614 */	NdrFcShort( 0x128 ),	/* Type Offset=296 */

	/* Parameter bIncludeSdesItems */

/* 2616 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2618 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2620 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2622 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2624 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2626 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_GuidCount */

/* 2628 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2630 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2634 */	NdrFcShort( 0x5 ),	/* 5 */
/* 2636 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2640 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2642 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2644 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2646 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2648 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2650 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pcGuids */

/* 2652 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2654 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2656 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2658 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2660 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2662 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetGuids */

/* 2664 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2666 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2670 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2672 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2674 */	NdrFcShort( 0x84 ),	/* 132 */
/* 2676 */	NdrFcShort( 0x8c ),	/* 140 */
/* 2678 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2680 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2682 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2684 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2686 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRegPinTypes */

/* 2688 */	NdrFcShort( 0x11a ),	/* Flags:  must free, in, out, simple ref, */
/* 2690 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2692 */	NdrFcShort( 0x146 ),	/* Type Offset=326 */

	/* Return value */

/* 2694 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2696 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2698 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Packetize */

/* 2700 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2702 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2706 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2708 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2710 */	NdrFcShort( 0x21 ),	/* 33 */
/* 2712 */	NdrFcShort( 0x95 ),	/* 149 */
/* 2714 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x6,		/* 6 */
/* 2716 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2718 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2720 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2722 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pBuffer */

/* 2724 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 2726 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2728 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter cbBuffer */

/* 2730 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2732 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2734 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppBuffer */

/* 2736 */	NdrFcShort( 0x2012 ),	/* Flags:  must free, out, srv alloc size=8 */
/* 2738 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2740 */	NdrFcShort( 0x158 ),	/* Type Offset=344 */

	/* Parameter ppcbBuffers */

/* 2742 */	NdrFcShort( 0x2012 ),	/* Flags:  must free, out, srv alloc size=8 */
/* 2744 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2746 */	NdrFcShort( 0x3a ),	/* Type Offset=58 */

	/* Parameter pcBuffers */

/* 2748 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2750 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2752 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2754 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2756 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2758 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Depacketize */

/* 2760 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2762 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2766 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2768 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 2770 */	NdrFcShort( 0xa2 ),	/* 162 */
/* 2772 */	NdrFcShort( 0x59 ),	/* 89 */
/* 2774 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x8,		/* 8 */
/* 2776 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2778 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2780 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2782 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pBuffers */

/* 2784 */	NdrFcShort( 0x200a ),	/* Flags:  must free, in, srv alloc size=8 */
/* 2786 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2788 */	NdrFcShort( 0x164 ),	/* Type Offset=356 */

	/* Parameter pcbBuffers */

/* 2790 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 2792 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2794 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pSeqNums */

/* 2796 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 2798 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2800 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter cBuffers */

/* 2802 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2804 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2806 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pBuffer */

/* 2808 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 2810 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2812 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter pcbBuffer */

/* 2814 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 2816 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2818 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pcbSkipped */

/* 2820 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2822 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2824 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2826 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2828 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2830 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetNetworkParameter */

/* 2832 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2834 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2838 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2840 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2842 */	NdrFcShort( 0x14 ),	/* 20 */
/* 2844 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2846 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 2848 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2850 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2852 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2854 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter szRemoteAddress */

/* 2856 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2858 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2860 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Parameter uRemotePort */

/* 2862 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2864 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2866 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter szLocalInterface */

/* 2868 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2870 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2872 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Parameter uLocalPort */

/* 2874 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2876 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2878 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter ttl */

/* 2880 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2882 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2884 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter szCname */

/* 2886 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2888 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2890 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Return value */

/* 2892 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2894 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2896 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ReserveNetworkAddressAndCreateSockets */

/* 2898 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2900 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2904 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2906 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2908 */	NdrFcShort( 0x14 ),	/* 20 */
/* 2910 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2912 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 2914 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2916 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2918 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2920 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter szRemoteAddress */

/* 2922 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2924 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2926 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Parameter szLocalInterface */

/* 2928 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 2930 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2932 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Parameter uMinLocalPort */

/* 2934 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2936 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2938 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter uMaxLocalPort */

/* 2940 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2942 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2944 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter ttl */

/* 2946 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2948 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2950 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter cname */

/* 2952 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2954 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2956 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Return value */

/* 2958 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2960 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2962 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ReserveNetworkAddress */

/* 2964 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2966 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2970 */	NdrFcShort( 0x5 ),	/* 5 */
/* 2972 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 2974 */	NdrFcShort( 0x14 ),	/* 20 */
/* 2976 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2978 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 2980 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2982 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2984 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2986 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter szRemoteAddress */

/* 2988 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2990 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2992 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Parameter szLocalInterface */

/* 2994 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2996 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2998 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Parameter uMinLocalPort */

/* 3000 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3002 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3004 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter uMaxLocalPort */

/* 3006 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3008 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3010 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter szLocalInterfaceOut */

/* 3012 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 3014 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3016 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Parameter cchLocal */

/* 3018 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3020 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3022 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter puLocalPort */

/* 3024 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3026 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3028 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 3030 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3032 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3034 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPayloadType */

/* 3036 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3038 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3042 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3044 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3046 */	NdrFcShort( 0x5 ),	/* 5 */
/* 3048 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3050 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3052 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3054 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3056 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3058 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter payloadType */

/* 3060 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3062 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3064 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Return value */

/* 3066 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3068 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3070 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetRtcpParameter */

/* 3072 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3074 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3078 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3080 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3082 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3084 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3086 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 3088 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3090 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3092 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3094 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter szName */

/* 3096 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3098 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3100 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Parameter szEMail */

/* 3102 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3104 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3106 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Parameter szPhone */

/* 3108 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3110 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3112 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Parameter szLoc */

/* 3114 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3116 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3118 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Parameter szTool */

/* 3120 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3122 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3124 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Parameter szNote */

/* 3126 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3128 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3130 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Return value */

/* 3132 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3134 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3136 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_LocalSsrc */

/* 3138 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3140 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3144 */	NdrFcShort( 0x9 ),	/* 9 */
/* 3146 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3148 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3150 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3152 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3154 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3156 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3158 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3160 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 3162 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3164 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3166 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3168 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3170 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3172 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SendRtpPacket */

/* 3174 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3176 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3180 */	NdrFcShort( 0x3 ),	/* 3 */
/* 3182 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3184 */	NdrFcShort( 0x31 ),	/* 49 */
/* 3186 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3188 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 3190 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3194 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3196 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pBuffer */

/* 3198 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 3200 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3202 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter cbBuffer */

/* 3204 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3206 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3208 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bMarker */

/* 3210 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3212 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3214 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter timestamp */

/* 3216 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3218 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3220 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3222 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3224 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3226 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SendRtpPayloadData */

/* 3228 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3230 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3234 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3236 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3238 */	NdrFcShort( 0x31 ),	/* 49 */
/* 3240 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3242 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 3244 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3246 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3248 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3250 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bMarker */

/* 3252 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3254 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3256 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter timestamp */

/* 3258 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3260 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3262 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pProperlyPacketizedData */

/* 3264 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 3266 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3268 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter cbProperlyPacketizedData */

/* 3270 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3272 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3274 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3276 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3278 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3280 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetRtpRenderer */

/* 3282 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3284 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3288 */	NdrFcShort( 0x3 ),	/* 3 */
/* 3290 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3292 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3294 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3296 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3298 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3300 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3302 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3304 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRenderer */

/* 3306 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3308 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3310 */	NdrFcShort( 0x16c ),	/* Type Offset=364 */

	/* Return value */

/* 3312 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3314 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3316 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetProtocolMediaParameter */

/* 3318 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3320 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3324 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3326 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3328 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3330 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3332 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 3334 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3336 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3340 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter avgTimePerFrame */

/* 3342 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3344 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3346 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter rtpTsIncPerFrame */

/* 3348 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3350 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3352 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3354 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3356 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3358 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetRtpPayloadPacketizer */

/* 3360 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3362 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3366 */	NdrFcShort( 0x5 ),	/* 5 */
/* 3368 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3370 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3372 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3374 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3376 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3378 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3380 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3382 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPacketizer */

/* 3384 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3386 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3388 */	NdrFcShort( 0x17e ),	/* Type Offset=382 */

	/* Return value */

/* 3390 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3392 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3394 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetBufferPrefix */

/* 3396 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3398 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3402 */	NdrFcShort( 0x3 ),	/* 3 */
/* 3404 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3406 */	NdrFcShort( 0x1c ),	/* 28 */
/* 3408 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3410 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3412 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3414 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3416 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3418 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pcbPrefix */

/* 3420 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 3422 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3424 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3426 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3428 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3430 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMediaParameterDefaults */

/* 3432 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3434 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3438 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3440 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3442 */	NdrFcShort( 0x1d ),	/* 29 */
/* 3444 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3446 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 3448 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3450 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3452 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3454 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bAduSpansMultiplePackets */

/* 3456 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3458 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3460 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter payloadType */

/* 3462 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3464 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3466 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter uRtpTimeStampIncrementPerSecond */

/* 3468 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3470 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3472 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter uExpectedTimePerAduNanoseconds */

/* 3474 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3476 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3478 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3480 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3482 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3484 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOutputMediaType */

/* 3486 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3488 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3492 */	NdrFcShort( 0x5 ),	/* 5 */
/* 3494 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3496 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3498 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3500 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3502 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3504 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3506 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3508 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pMediaType */

/* 3510 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3512 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3514 */	NdrFcShort( 0x1a6 ),	/* Type Offset=422 */

	/* Return value */

/* 3516 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3518 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3520 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SelectActiveSourceForOutputPin */

/* 3522 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3524 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3528 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3530 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3532 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3534 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3536 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 3538 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3540 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3542 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3544 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */

/* 3546 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3548 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3550 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ssrc */

/* 3552 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3554 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3556 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3558 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3560 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3562 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddOutputPinForActiveSource */

/* 3564 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3566 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3570 */	NdrFcShort( 0xa ),	/* 10 */
/* 3572 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3574 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3576 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3578 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 3580 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3582 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3584 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3586 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ssrc */

/* 3588 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3590 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3592 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pIndex */

/* 3594 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 3596 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3598 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3600 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3602 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3604 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoveOutputPin */

/* 3606 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3608 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3612 */	NdrFcShort( 0xb ),	/* 11 */
/* 3614 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3616 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3618 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3620 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3622 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3624 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3626 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3628 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */

/* 3630 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3632 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3634 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3636 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3638 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3640 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RegisterEventHandler */

/* 3642 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3644 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3648 */	NdrFcShort( 0xc ),	/* 12 */
/* 3650 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3652 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3654 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3656 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3658 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3660 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3662 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3664 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pEventConsumer */

/* 3666 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3668 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3670 */	NdrFcShort( 0x1c8 ),	/* Type Offset=456 */

	/* Return value */

/* 3672 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3674 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3676 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RegisterEventHandlerEx */

/* 3678 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3680 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3684 */	NdrFcShort( 0xd ),	/* 13 */
/* 3686 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3688 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3690 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3692 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3694 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3696 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3698 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3700 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pEventConsumerEx */

/* 3702 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3704 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3706 */	NdrFcShort( 0x1da ),	/* Type Offset=474 */

	/* Return value */

/* 3708 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3710 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3712 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSubscribedSourcesCount */

/* 3714 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3716 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3720 */	NdrFcShort( 0xe ),	/* 14 */
/* 3722 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3724 */	NdrFcShort( 0x1c ),	/* 28 */
/* 3726 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3728 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3730 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3732 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3734 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3736 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pcSubscribed */

/* 3738 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 3740 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3742 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3744 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3746 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3748 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSubscribedSources */

/* 3750 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3752 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3756 */	NdrFcShort( 0xf ),	/* 15 */
/* 3758 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3760 */	NdrFcShort( 0x4c ),	/* 76 */
/* 3762 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3764 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 3766 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3768 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3770 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3772 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSubscribedSources */

/* 3774 */	NdrFcShort( 0x200a ),	/* Flags:  must free, in, srv alloc size=8 */
/* 3776 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3778 */	NdrFcShort( 0x1ec ),	/* Type Offset=492 */

	/* Parameter pcSubscribedSources */

/* 3780 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 3782 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3784 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3786 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3788 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3790 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetActiveSourcesCount */

/* 3792 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3794 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3798 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3800 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3802 */	NdrFcShort( 0x1c ),	/* 28 */
/* 3804 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3806 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3808 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3810 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3812 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3814 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pcActive */

/* 3816 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 3818 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3820 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3822 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3824 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3826 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetActiveSources */

/* 3828 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3830 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3834 */	NdrFcShort( 0x11 ),	/* 17 */
/* 3836 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3838 */	NdrFcShort( 0x4c ),	/* 76 */
/* 3840 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3842 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 3844 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3846 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3848 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3850 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pActiveSources */

/* 3852 */	NdrFcShort( 0x200a ),	/* Flags:  must free, in, srv alloc size=8 */
/* 3854 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3856 */	NdrFcShort( 0x1ec ),	/* Type Offset=492 */

	/* Parameter pcActiveSources */

/* 3858 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 3860 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3862 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3864 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3866 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3868 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetAutoSubscribeActiveSources */

/* 3870 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3872 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3876 */	NdrFcShort( 0x12 ),	/* 18 */
/* 3878 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3880 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3882 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3884 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3886 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3888 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3890 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3892 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bValue */

/* 3894 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3896 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3898 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3900 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3902 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3904 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAutoSubscribeActiveSources */

/* 3906 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3908 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3912 */	NdrFcShort( 0x13 ),	/* 19 */
/* 3914 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3916 */	NdrFcShort( 0x1c ),	/* 28 */
/* 3918 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3920 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3922 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3924 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3926 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3928 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbValue */

/* 3930 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 3932 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3934 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3936 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3938 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3940 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetRtpPayloadPacketizer */

/* 3942 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3944 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3948 */	NdrFcShort( 0x14 ),	/* 20 */
/* 3950 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3952 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3954 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3956 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3958 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3960 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3962 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3964 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPacketizer */

/* 3966 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3968 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3970 */	NdrFcShort( 0x17e ),	/* Type Offset=382 */

	/* Return value */

/* 3972 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3974 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3976 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ReserveNetworkAddress */

/* 3978 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3980 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3984 */	NdrFcShort( 0x15 ),	/* 21 */
/* 3986 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 3988 */	NdrFcShort( 0x2e ),	/* 46 */
/* 3990 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3992 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 3994 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3996 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3998 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4000 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter szRemoteAddress */

/* 4002 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4004 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4006 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Parameter szLocalAddress */

/* 4008 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4010 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4012 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Parameter uLocalMinPort */

/* 4014 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4016 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4018 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter uLocalMaxPort */

/* 4020 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4022 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4024 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter szLocalOut */

/* 4026 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4028 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4030 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Parameter cchLocal */

/* 4032 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4034 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4036 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter puLocal */

/* 4038 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 4040 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 4042 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 4044 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4046 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 4048 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetNetworkParameter */

/* 4050 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4052 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4056 */	NdrFcShort( 0x16 ),	/* 22 */
/* 4058 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 4060 */	NdrFcShort( 0x60 ),	/* 96 */
/* 4062 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4064 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 4066 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4068 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4070 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4072 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter szRemoteAddress */

/* 4074 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4076 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4078 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Parameter cchRemoteAddress */

/* 4080 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4082 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4084 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter puRemotePort */

/* 4086 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 4088 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4090 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter szLocalInterface */

/* 4092 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4094 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4096 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Parameter cchLocalAddress */

/* 4098 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4100 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4102 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter puLocalPortBase */

/* 4104 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 4106 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4108 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pTtl */

/* 4110 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 4112 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 4114 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4116 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4118 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 4120 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetJitterBufferLatency */

/* 4122 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4124 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4128 */	NdrFcShort( 0x17 ),	/* 23 */
/* 4130 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4132 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4134 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4136 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 4138 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4140 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4144 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ssrc */

/* 4146 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4148 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4150 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter uLatency */

/* 4152 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4154 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4156 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4158 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4160 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4162 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetJitterBufferLatency */

/* 4164 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4166 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4170 */	NdrFcShort( 0x18 ),	/* 24 */
/* 4172 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4174 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4176 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4178 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 4180 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4182 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4184 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4186 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ssrc */

/* 4188 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4190 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4192 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter puLatency */

/* 4194 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 4196 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4198 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4200 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4202 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4204 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRtcpAttributes */

/* 4206 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4208 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4212 */	NdrFcShort( 0x19 ),	/* 25 */
/* 4214 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4216 */	NdrFcShort( 0x79c ),	/* 1948 */
/* 4218 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4220 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 4222 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4228 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ssrc */

/* 4230 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4232 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4234 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pSdesItems */

/* 4236 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 4238 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4240 */	NdrFcShort( 0x100 ),	/* Type Offset=256 */

	/* Return value */

/* 4242 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4244 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4246 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMuted */

/* 4248 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4250 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4254 */	NdrFcShort( 0x1a ),	/* 26 */
/* 4256 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4258 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4260 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4262 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 4264 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4266 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4268 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4270 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ssrc */

/* 4272 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4274 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4276 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bMuted */

/* 4278 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4280 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4282 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4284 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4286 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4288 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMuted */

/* 4290 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4292 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4296 */	NdrFcShort( 0x1b ),	/* 27 */
/* 4298 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4300 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4302 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4304 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 4306 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4308 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4310 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4312 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ssrc */

/* 4314 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4316 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4318 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pbIsMuted */

/* 4320 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 4322 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4324 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4326 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4328 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4330 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPinCount */

/* 4332 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4334 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4338 */	NdrFcShort( 0x1c ),	/* 28 */
/* 4340 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4342 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4344 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4346 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4348 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4350 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4352 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4354 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pinCount */

/* 4356 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4358 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4360 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4362 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4364 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4366 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPinCount */

/* 4368 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4370 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4374 */	NdrFcShort( 0x1d ),	/* 29 */
/* 4376 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4378 */	NdrFcShort( 0x1c ),	/* 28 */
/* 4380 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4382 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4384 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4386 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4388 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4390 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPinCount */

/* 4392 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 4394 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4396 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4398 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4400 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4402 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPinIndexForSource */

/* 4404 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4406 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4410 */	NdrFcShort( 0x1e ),	/* 30 */
/* 4412 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4414 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4416 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4418 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 4420 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4422 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4424 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4426 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ssrc */

/* 4428 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4430 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4432 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pIndex */

/* 4434 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 4436 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4438 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4440 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4442 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4444 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Configure */

/* 4446 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4448 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4452 */	NdrFcShort( 0x3 ),	/* 3 */
/* 4454 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 4456 */	NdrFcShort( 0x90 ),	/* 144 */
/* 4458 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4460 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 4462 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4464 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4466 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4468 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ssrc */

/* 4470 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4472 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4474 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pRtpBufferedListener */

/* 4476 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4478 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4480 */	NdrFcShort( 0x1f8 ),	/* Type Offset=504 */

	/* Parameter pPlayoutBuffer */

/* 4482 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4484 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4486 */	NdrFcShort( 0xd8 ),	/* Type Offset=216 */

	/* Parameter pPacketizer */

/* 4488 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4490 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4492 */	NdrFcShort( 0x17e ),	/* Type Offset=382 */

	/* Parameter lpGuidMajorType */

/* 4494 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 4496 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4498 */	NdrFcShort( 0xc8 ),	/* Type Offset=200 */

	/* Parameter lpGuidMinorType */

/* 4500 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 4502 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4504 */	NdrFcShort( 0xc8 ),	/* Type Offset=200 */

	/* Return value */

/* 4506 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4508 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 4510 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOutputMediaType */

/* 4512 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4514 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4518 */	NdrFcShort( 0x4 ),	/* 4 */
/* 4520 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4522 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4524 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4526 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4528 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4530 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4532 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4534 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pMediaType */

/* 4536 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4538 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4540 */	NdrFcShort( 0x1a6 ),	/* Type Offset=422 */

	/* Return value */

/* 4542 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4544 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4546 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSubscribedSsrc */

/* 4548 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4550 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4554 */	NdrFcShort( 0x6 ),	/* 6 */
/* 4556 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4558 */	NdrFcShort( 0x1c ),	/* 28 */
/* 4560 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4562 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4564 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4566 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4568 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4570 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSsrc */

/* 4572 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 4574 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4576 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4578 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4580 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4582 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x0,	/* FC_RP */
/*  4 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6) */
/*  6 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/*  8 */	NdrFcShort( 0x24 ),	/* 36 */
/* 10 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 12 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 14 */	NdrFcShort( 0x20 ),	/* 32 */
/* 16 */	NdrFcShort( 0x20 ),	/* 32 */
/* 18 */	0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 20 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 22 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 24 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 26 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 28 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 30 */	0x6,		/* FC_SHORT */
			0x8,		/* FC_LONG */
/* 32 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 34 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 36 */	NdrFcShort( 0x2 ),	/* Offset= 2 (38) */
/* 38 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 40 */	NdrFcShort( 0x2 ),	/* Offset= 2 (42) */
/* 42 */	
			0x12, 0x0,	/* FC_UP */
/* 44 */	NdrFcShort( 0xffda ),	/* Offset= -38 (6) */
/* 46 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 48 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 50 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 52 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 54 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 56 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 58 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 60 */	NdrFcShort( 0x2 ),	/* Offset= 2 (62) */
/* 62 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 64 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 66 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 68 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 70 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 72 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 74 */	
			0x11, 0x0,	/* FC_RP */
/* 76 */	NdrFcShort( 0x2 ),	/* Offset= 2 (78) */
/* 78 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 80 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 82 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 84 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 86 */	
			0x11, 0x0,	/* FC_RP */
/* 88 */	NdrFcShort( 0x2 ),	/* Offset= 2 (90) */
/* 90 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 92 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 94 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 96 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 98 */	
			0x11, 0x0,	/* FC_RP */
/* 100 */	NdrFcShort( 0x26 ),	/* Offset= 38 (138) */
/* 102 */	
			0x13, 0x0,	/* FC_OP */
/* 104 */	NdrFcShort( 0xe ),	/* Offset= 14 (118) */
/* 106 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 108 */	NdrFcShort( 0x2 ),	/* 2 */
/* 110 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 112 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 114 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 116 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 118 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 120 */	NdrFcShort( 0x8 ),	/* 8 */
/* 122 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (106) */
/* 124 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 126 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 128 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 130 */	NdrFcShort( 0x0 ),	/* 0 */
/* 132 */	NdrFcShort( 0x4 ),	/* 4 */
/* 134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 136 */	NdrFcShort( 0xffde ),	/* Offset= -34 (102) */
/* 138 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 140 */	NdrFcShort( 0x10 ),	/* 16 */
/* 142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 144 */	NdrFcShort( 0x0 ),	/* Offset= 0 (144) */
/* 146 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 148 */	NdrFcShort( 0xffec ),	/* Offset= -20 (128) */
/* 150 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 152 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 154 */	
			0x12, 0x0,	/* FC_UP */
/* 156 */	NdrFcShort( 0xffda ),	/* Offset= -38 (118) */
/* 158 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 160 */	NdrFcShort( 0x0 ),	/* 0 */
/* 162 */	NdrFcShort( 0x4 ),	/* 4 */
/* 164 */	NdrFcShort( 0x0 ),	/* 0 */
/* 166 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (154) */
/* 168 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 170 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 172 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 174 */	NdrFcLong( 0x1abea162 ),	/* 448700770 */
/* 178 */	NdrFcShort( 0x797f ),	/* 31103 */
/* 180 */	NdrFcShort( 0x4a07 ),	/* 18951 */
/* 182 */	0x93,		/* 147 */
			0xad,		/* 173 */
/* 184 */	0x7d,		/* 125 */
			0xac,		/* 172 */
/* 186 */	0xbe,		/* 190 */
			0x47,		/* 71 */
/* 188 */	0x7f,		/* 127 */
			0x48,		/* 72 */
/* 190 */	
			0x11, 0x0,	/* FC_RP */
/* 192 */	NdrFcShort( 0x8 ),	/* Offset= 8 (200) */
/* 194 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 196 */	NdrFcShort( 0x8 ),	/* 8 */
/* 198 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 200 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 202 */	NdrFcShort( 0x10 ),	/* 16 */
/* 204 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 206 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 208 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (194) */
			0x5b,		/* FC_END */
/* 212 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 214 */	NdrFcShort( 0x2 ),	/* Offset= 2 (216) */
/* 216 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 218 */	NdrFcLong( 0x53f0c4d4 ),	/* 1408287956 */
/* 222 */	NdrFcShort( 0x9926 ),	/* -26330 */
/* 224 */	NdrFcShort( 0x4f1e ),	/* 20254 */
/* 226 */	0xb0,		/* 176 */
			0xff,		/* 255 */
/* 228 */	0x47,		/* 71 */
			0xea,		/* 234 */
/* 230 */	0xf6,		/* 246 */
			0xaa,		/* 170 */
/* 232 */	0x1f,		/* 31 */
			0x5a,		/* 90 */
/* 234 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 236 */	NdrFcShort( 0x2 ),	/* Offset= 2 (238) */
/* 238 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 240 */	NdrFcShort( 0x2 ),	/* Offset= 2 (242) */
/* 242 */	
			0x13, 0x0,	/* FC_OP */
/* 244 */	NdrFcShort( 0xff12 ),	/* Offset= -238 (6) */
/* 246 */	
			0x11, 0x0,	/* FC_RP */
/* 248 */	NdrFcShort( 0x8 ),	/* Offset= 8 (256) */
/* 250 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 252 */	NdrFcShort( 0xff ),	/* 255 */
/* 254 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 256 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 258 */	NdrFcShort( 0x700 ),	/* 1792 */
/* 260 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 262 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (250) */
/* 264 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 266 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (250) */
/* 268 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 270 */	NdrFcShort( 0xffec ),	/* Offset= -20 (250) */
/* 272 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 274 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (250) */
/* 276 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 278 */	NdrFcShort( 0xffe4 ),	/* Offset= -28 (250) */
/* 280 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 282 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (250) */
/* 284 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 286 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (250) */
/* 288 */	0x3f,		/* FC_STRUCTPAD3 */
			0x8,		/* FC_LONG */
/* 290 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 292 */	
			0x11, 0x0,	/* FC_RP */
/* 294 */	NdrFcShort( 0x2 ),	/* Offset= 2 (296) */
/* 296 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 298 */	NdrFcShort( 0x1c ),	/* 28 */
/* 300 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 302 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 304 */	NdrFcShort( 0x18 ),	/* 24 */
/* 306 */	NdrFcShort( 0x18 ),	/* 24 */
/* 308 */	0x13, 0x0,	/* FC_OP */
/* 310 */	NdrFcShort( 0xffca ),	/* Offset= -54 (256) */
/* 312 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 314 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 316 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 318 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 320 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 322 */	
			0x11, 0x0,	/* FC_RP */
/* 324 */	NdrFcShort( 0x2 ),	/* Offset= 2 (326) */
/* 326 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 328 */	NdrFcShort( 0x20 ),	/* 32 */
/* 330 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 332 */	NdrFcShort( 0xff7c ),	/* Offset= -132 (200) */
/* 334 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 336 */	NdrFcShort( 0xff78 ),	/* Offset= -136 (200) */
/* 338 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 340 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 342 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 344 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 346 */	NdrFcShort( 0x2 ),	/* Offset= 2 (348) */
/* 348 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 350 */	NdrFcShort( 0x2 ),	/* Offset= 2 (352) */
/* 352 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 354 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 356 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 358 */	NdrFcShort( 0x2 ),	/* Offset= 2 (360) */
/* 360 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 362 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 364 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 366 */	NdrFcLong( 0x23aaf37a ),	/* 598406010 */
/* 370 */	NdrFcShort( 0x90f4 ),	/* -28428 */
/* 372 */	NdrFcShort( 0x48e9 ),	/* 18665 */
/* 374 */	0xb8,		/* 184 */
			0x16,		/* 22 */
/* 376 */	0x9e,		/* 158 */
			0xea,		/* 234 */
/* 378 */	0xfe,		/* 254 */
			0x49,		/* 73 */
/* 380 */	0x12,		/* 18 */
			0xa8,		/* 168 */
/* 382 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 384 */	NdrFcLong( 0x66aa121d ),	/* 1722421789 */
/* 388 */	NdrFcShort( 0x17dd ),	/* 6109 */
/* 390 */	NdrFcShort( 0x469b ),	/* 18075 */
/* 392 */	0x9d,		/* 157 */
			0x25,		/* 37 */
/* 394 */	0xc7,		/* 199 */
			0xf7,		/* 247 */
/* 396 */	0x25,		/* 37 */
			0xc,		/* 12 */
/* 398 */	0xdd,		/* 221 */
			0x99,		/* 153 */
/* 400 */	
			0x11, 0x0,	/* FC_RP */
/* 402 */	NdrFcShort( 0x14 ),	/* Offset= 20 (422) */
/* 404 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 406 */	NdrFcLong( 0x0 ),	/* 0 */
/* 410 */	NdrFcShort( 0x0 ),	/* 0 */
/* 412 */	NdrFcShort( 0x0 ),	/* 0 */
/* 414 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 416 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 418 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 420 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 422 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 424 */	NdrFcShort( 0x48 ),	/* 72 */
/* 426 */	NdrFcShort( 0x0 ),	/* 0 */
/* 428 */	NdrFcShort( 0x18 ),	/* Offset= 24 (452) */
/* 430 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 432 */	NdrFcShort( 0xff18 ),	/* Offset= -232 (200) */
/* 434 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 436 */	NdrFcShort( 0xff14 ),	/* Offset= -236 (200) */
/* 438 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 440 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 442 */	0x0,		/* 0 */
			NdrFcShort( 0xff0d ),	/* Offset= -243 (200) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 446 */	0x0,		/* 0 */
			NdrFcShort( 0xffd5 ),	/* Offset= -43 (404) */
			0x8,		/* FC_LONG */
/* 450 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 452 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 454 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 456 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 458 */	NdrFcLong( 0x1abea164 ),	/* 448700772 */
/* 462 */	NdrFcShort( 0x797f ),	/* 31103 */
/* 464 */	NdrFcShort( 0x4a07 ),	/* 18951 */
/* 466 */	0x93,		/* 147 */
			0xad,		/* 173 */
/* 468 */	0x7d,		/* 125 */
			0xac,		/* 172 */
/* 470 */	0xbe,		/* 190 */
			0x47,		/* 71 */
/* 472 */	0x7f,		/* 127 */
			0x48,		/* 72 */
/* 474 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 476 */	NdrFcLong( 0x1abea165 ),	/* 448700773 */
/* 480 */	NdrFcShort( 0x797f ),	/* 31103 */
/* 482 */	NdrFcShort( 0x4a07 ),	/* 18951 */
/* 484 */	0x93,		/* 147 */
			0xad,		/* 173 */
/* 486 */	0x7d,		/* 125 */
			0xac,		/* 172 */
/* 488 */	0xbe,		/* 190 */
			0x47,		/* 71 */
/* 490 */	0x7f,		/* 127 */
			0x48,		/* 72 */
/* 492 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 494 */	NdrFcShort( 0x2 ),	/* Offset= 2 (496) */
/* 496 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 498 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 500 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 502 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 504 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 506 */	NdrFcLong( 0xc24ff921 ),	/* -1034946271 */
/* 510 */	NdrFcShort( 0x56e8 ),	/* 22248 */
/* 512 */	NdrFcShort( 0x4bf7 ),	/* 19447 */
/* 514 */	0x8e,		/* 142 */
			0x4b,		/* 75 */
/* 516 */	0x4b,		/* 75 */
			0x44,		/* 68 */
/* 518 */	0x9,		/* 9 */
			0x86,		/* 134 */
/* 520 */	0x2f,		/* 47 */
			0xbb,		/* 187 */

			0x0
        }
    };

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            }

        };



/* Standard interface: __MIDL_itf__Kite2ERtp2EAtl_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IPlayoutBuffer, ver. 0.0,
   GUID={0x53F0C4D4,0x9926,0x4F1E,{0xB0,0xFF,0x47,0xEA,0xF6,0xAA,0x1F,0x5A}} */

#pragma code_seg(".orpc")
static const unsigned short IPlayoutBuffer_FormatStringOffsetTable[] =
    {
    0,
    36,
    78,
    114,
    144,
    192,
    228,
    264,
    300,
    336,
    372,
    408,
    444,
    480,
    516,
    552,
    588,
    624,
    660
    };

static const MIDL_STUBLESS_PROXY_INFO IPlayoutBuffer_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IPlayoutBuffer_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IPlayoutBuffer_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IPlayoutBuffer_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(22) _IPlayoutBufferProxyVtbl = 
{
    &IPlayoutBuffer_ProxyInfo,
    &IID_IPlayoutBuffer,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IPlayoutBuffer::EnqueuePacket */ ,
    (void *) (INT_PTR) -1 /* IPlayoutBuffer::DequeuePackets */ ,
    (void *) (INT_PTR) -1 /* IPlayoutBuffer::ExpireOlderThanOrEqual */ ,
    (void *) (INT_PTR) -1 /* IPlayoutBuffer::ClearBuffer */ ,
    (void *) (INT_PTR) -1 /* IPlayoutBuffer::SetBufferParameter */ ,
    (void *) (INT_PTR) -1 /* IPlayoutBuffer::SetLatency */ ,
    (void *) (INT_PTR) -1 /* IPlayoutBuffer::GetLatency */ ,
    (void *) (INT_PTR) -1 /* IPlayoutBuffer::SetMuted */ ,
    (void *) (INT_PTR) -1 /* IPlayoutBuffer::GetMuted */ ,
    (void *) (INT_PTR) -1 /* IPlayoutBuffer::get_PayloadType */ ,
    (void *) (INT_PTR) -1 /* IPlayoutBuffer::put_PayloadType */ ,
    (void *) (INT_PTR) -1 /* IPlayoutBuffer::get_DueTime */ ,
    (void *) (INT_PTR) -1 /* IPlayoutBuffer::get_EventHandle */ ,
    (void *) (INT_PTR) -1 /* IPlayoutBuffer::get_BufferDurationMilliseconds */ ,
    (void *) (INT_PTR) -1 /* IPlayoutBuffer::put_BufferDurationMilliseconds */ ,
    (void *) (INT_PTR) -1 /* IPlayoutBuffer::get_RtpTimestampIncrementPerSecond */ ,
    (void *) (INT_PTR) -1 /* IPlayoutBuffer::put_RtpTimestampIncrementPerSecond */ ,
    (void *) (INT_PTR) -1 /* IPlayoutBuffer::get_TimePerSampleNanos */ ,
    (void *) (INT_PTR) -1 /* IPlayoutBuffer::put_TimePerSampleNanos */
};

const CInterfaceStubVtbl _IPlayoutBufferStubVtbl =
{
    &IID_IPlayoutBuffer,
    &IPlayoutBuffer_ServerInfo,
    22,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IDisposable, ver. 0.0,
   GUID={0x53F0C4D5,0x9926,0x4F1E,{0xB0,0xFF,0x47,0xEA,0xF6,0xAA,0x1F,0x5A}} */

#pragma code_seg(".orpc")
static const unsigned short IDisposable_FormatStringOffsetTable[] =
    {
    696,
    732
    };

static const MIDL_STUBLESS_PROXY_INFO IDisposable_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IDisposable_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IDisposable_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IDisposable_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(5) _IDisposableProxyVtbl = 
{
    &IDisposable_ProxyInfo,
    &IID_IDisposable,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IDisposable::get_Disposed */ ,
    (void *) (INT_PTR) -1 /* IDisposable::Dispose */
};

const CInterfaceStubVtbl _IDisposableStubVtbl =
{
    &IID_IDisposable,
    &IDisposable_ServerInfo,
    5,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IRtpBufferedListenerFilterEventConsumer, ver. 0.0,
   GUID={0x1ABEA164,0x797F,0x4A07,{0x93,0xAD,0x7D,0xAC,0xBE,0x47,0x7F,0x48}} */

#pragma code_seg(".orpc")
static const unsigned short IRtpBufferedListenerFilterEventConsumer_FormatStringOffsetTable[] =
    {
    762,
    798,
    834,
    876,
    918,
    960,
    1026
    };

static const MIDL_STUBLESS_PROXY_INFO IRtpBufferedListenerFilterEventConsumer_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRtpBufferedListenerFilterEventConsumer_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRtpBufferedListenerFilterEventConsumer_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRtpBufferedListenerFilterEventConsumer_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _IRtpBufferedListenerFilterEventConsumerProxyVtbl = 
{
    &IRtpBufferedListenerFilterEventConsumer_ProxyInfo,
    &IID_IRtpBufferedListenerFilterEventConsumer,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListenerFilterEventConsumer::ActiveSourceAdded */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListenerFilterEventConsumer::ActiveSourceRemoved */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListenerFilterEventConsumer::SourceActiveValueChanged */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListenerFilterEventConsumer::SourceMuteValueChanged */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListenerFilterEventConsumer::SourceEvent */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListenerFilterEventConsumer::SourceReception */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListenerFilterEventConsumer::SourceAttributes */
};

const CInterfaceStubVtbl _IRtpBufferedListenerFilterEventConsumerStubVtbl =
{
    &IID_IRtpBufferedListenerFilterEventConsumer,
    &IRtpBufferedListenerFilterEventConsumer_ServerInfo,
    10,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IRtpBufferedListenerFilterEventConsumerEx, ver. 0.0,
   GUID={0x1ABEA165,0x797F,0x4A07,{0x93,0xAD,0x7D,0xAC,0xBE,0x47,0x7F,0x48}} */

#pragma code_seg(".orpc")
static const unsigned short IRtpBufferedListenerFilterEventConsumerEx_FormatStringOffsetTable[] =
    {
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IRtpBufferedListenerFilterEventConsumerEx_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRtpBufferedListenerFilterEventConsumerEx_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRtpBufferedListenerFilterEventConsumerEx_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRtpBufferedListenerFilterEventConsumerEx_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(3) _IRtpBufferedListenerFilterEventConsumerExProxyVtbl = 
{
    0,
    &IID_IRtpBufferedListenerFilterEventConsumerEx,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy
};

const CInterfaceStubVtbl _IRtpBufferedListenerFilterEventConsumerExStubVtbl =
{
    &IID_IRtpBufferedListenerFilterEventConsumerEx,
    &IRtpBufferedListenerFilterEventConsumerEx_ServerInfo,
    3,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IRtpListenerEventConsumer, ver. 0.0,
   GUID={0x1ABEA162,0x797F,0x4A07,{0x93,0xAD,0x7D,0xAC,0xBE,0x47,0x7F,0x48}} */

#pragma code_seg(".orpc")
static const unsigned short IRtpListenerEventConsumer_FormatStringOffsetTable[] =
    {
    762,
    798,
    834
    };

static const MIDL_STUBLESS_PROXY_INFO IRtpListenerEventConsumer_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRtpListenerEventConsumer_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRtpListenerEventConsumer_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRtpListenerEventConsumer_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(6) _IRtpListenerEventConsumerProxyVtbl = 
{
    &IRtpListenerEventConsumer_ProxyInfo,
    &IID_IRtpListenerEventConsumer,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IRtpListenerEventConsumer::ActiveSourceAdded */ ,
    (void *) (INT_PTR) -1 /* IRtpListenerEventConsumer::ActiveSourceRemoved */ ,
    (void *) (INT_PTR) -1 /* IRtpListenerEventConsumer::ActiveSourceChanged */
};

const CInterfaceStubVtbl _IRtpListenerEventConsumerStubVtbl =
{
    &IID_IRtpListenerEventConsumer,
    &IRtpListenerEventConsumer_ServerInfo,
    6,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IRtpBufferedListenerEventConsumer, ver. 0.0,
   GUID={0x1ABEA163,0x797F,0x4A07,{0x93,0xAD,0x7D,0xAC,0xBE,0x47,0x7F,0x48}} */

#pragma code_seg(".orpc")
static const unsigned short IRtpBufferedListenerEventConsumer_FormatStringOffsetTable[] =
    {
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IRtpBufferedListenerEventConsumer_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRtpBufferedListenerEventConsumer_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRtpBufferedListenerEventConsumer_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRtpBufferedListenerEventConsumer_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(3) _IRtpBufferedListenerEventConsumerProxyVtbl = 
{
    0,
    &IID_IRtpBufferedListenerEventConsumer,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy
};

const CInterfaceStubVtbl _IRtpBufferedListenerEventConsumerStubVtbl =
{
    &IID_IRtpBufferedListenerEventConsumer,
    &IRtpBufferedListenerEventConsumer_ServerInfo,
    3,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IRtpRendererEventConsumer, ver. 0.0,
   GUID={0x2ABEA162,0x797F,0x4A07,{0x93,0xAD,0x7D,0xAC,0xBE,0x47,0x7F,0x48}} */

#pragma code_seg(".orpc")
static const unsigned short IRtpRendererEventConsumer_FormatStringOffsetTable[] =
    {
    762
    };

static const MIDL_STUBLESS_PROXY_INFO IRtpRendererEventConsumer_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRtpRendererEventConsumer_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRtpRendererEventConsumer_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRtpRendererEventConsumer_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IRtpRendererEventConsumerProxyVtbl = 
{
    &IRtpRendererEventConsumer_ProxyInfo,
    &IID_IRtpRendererEventConsumer,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IRtpRendererEventConsumer::ReceiverReportReceived */
};

const CInterfaceStubVtbl _IRtpRendererEventConsumerStubVtbl =
{
    &IID_IRtpRendererEventConsumer,
    &IRtpRendererEventConsumer_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IRtpReceiverStatistics, ver. 0.0,
   GUID={0xDC2F8E5E,0x17F2,0x4921,{0x98,0x04,0xF1,0xEA,0xFD,0xD2,0x08,0x43}} */

#pragma code_seg(".orpc")
static const unsigned short IRtpReceiverStatistics_FormatStringOffsetTable[] =
    {
    1104,
    1146,
    1200
    };

static const MIDL_STUBLESS_PROXY_INFO IRtpReceiverStatistics_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRtpReceiverStatistics_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRtpReceiverStatistics_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRtpReceiverStatistics_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(6) _IRtpReceiverStatisticsProxyVtbl = 
{
    &IRtpReceiverStatistics_ProxyInfo,
    &IID_IRtpReceiverStatistics,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IRtpReceiverStatistics::GetPacketLoss */ ,
    (void *) (INT_PTR) -1 /* IRtpReceiverStatistics::GetReceptionStatistics */ ,
    (void *) (INT_PTR) -1 /* IRtpReceiverStatistics::GetPerformanceCounterPrefix */
};

const CInterfaceStubVtbl _IRtpReceiverStatisticsStubVtbl =
{
    &IID_IRtpReceiverStatistics,
    &IRtpReceiverStatistics_ServerInfo,
    6,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IRtpSenderStatistics, ver. 0.0,
   GUID={0xDC2F8E5F,0x17F2,0x4921,{0x98,0x04,0xF1,0xEA,0xFD,0xD2,0x08,0x43}} */

#pragma code_seg(".orpc")
static const unsigned short IRtpSenderStatistics_FormatStringOffsetTable[] =
    {
    1248,
    1296,
    1350
    };

static const MIDL_STUBLESS_PROXY_INFO IRtpSenderStatistics_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRtpSenderStatistics_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRtpSenderStatistics_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRtpSenderStatistics_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(6) _IRtpSenderStatisticsProxyVtbl = 
{
    &IRtpSenderStatistics_ProxyInfo,
    &IID_IRtpSenderStatistics,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IRtpSenderStatistics::GetSenderStatistics */ ,
    (void *) (INT_PTR) -1 /* IRtpSenderStatistics::GetStatisticsForReceiver */ ,
    (void *) (INT_PTR) -1 /* IRtpSenderStatistics::GetPerformanceCounterPrefix */
};

const CInterfaceStubVtbl _IRtpSenderStatisticsStubVtbl =
{
    &IID_IRtpSenderStatistics,
    &IRtpSenderStatistics_ServerInfo,
    6,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Standard interface: __MIDL_itf__Kite2ERtp2EAtl_0748, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IInternetProtocolHelper, ver. 0.0,
   GUID={0x011B1D0D,0xBC47,0x46E7,{0x98,0x59,0x8F,0x70,0x16,0xD9,0x65,0x43}} */

#pragma code_seg(".orpc")
static const unsigned short IInternetProtocolHelper_FormatStringOffsetTable[] =
    {
    1398,
    1440,
    1482,
    1524
    };

static const MIDL_STUBLESS_PROXY_INFO IInternetProtocolHelper_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IInternetProtocolHelper_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IInternetProtocolHelper_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IInternetProtocolHelper_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _IInternetProtocolHelperProxyVtbl = 
{
    &IInternetProtocolHelper_ProxyInfo,
    &IID_IInternetProtocolHelper,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IInternetProtocolHelper::QueryMtuForInterface */ ,
    (void *) (INT_PTR) -1 /* IInternetProtocolHelper::GetAdapterInfoConcise */ ,
    (void *) (INT_PTR) -1 /* IInternetProtocolHelper::GetAdapterInfoConciseForAllAdapters */ ,
    (void *) (INT_PTR) -1 /* IInternetProtocolHelper::FindAdapterForAddress */
};

const CInterfaceStubVtbl _IInternetProtocolHelperStubVtbl =
{
    &IID_IInternetProtocolHelper,
    &IInternetProtocolHelper_ServerInfo,
    7,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Standard interface: __MIDL_itf__Kite2ERtp2EAtl_0749, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IRtpListenerConfiguration, ver. 0.0,
   GUID={0xC24FF91D,0x56E8,0x4bf7,{0x8E,0x4B,0x4B,0x44,0x09,0x86,0x2F,0xBB}} */

#pragma code_seg(".orpc")
static const unsigned short IRtpListenerConfiguration_FormatStringOffsetTable[] =
    {
    1566,
    1626,
    834,
    1686,
    1746,
    1818,
    1854
    };

static const MIDL_STUBLESS_PROXY_INFO IRtpListenerConfiguration_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRtpListenerConfiguration_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRtpListenerConfiguration_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRtpListenerConfiguration_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _IRtpListenerConfigurationProxyVtbl = 
{
    &IRtpListenerConfiguration_ProxyInfo,
    &IID_IRtpListenerConfiguration,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IRtpListenerConfiguration::SetNetworkParameter */ ,
    (void *) (INT_PTR) -1 /* IRtpListenerConfiguration::SetMediaParameterDefaults */ ,
    (void *) (INT_PTR) -1 /* IRtpListenerConfiguration::SetRtpBandwidth */ ,
    (void *) (INT_PTR) -1 /* IRtpListenerConfiguration::ReserveNetworkAddressAndCreateSockets */ ,
    (void *) (INT_PTR) -1 /* IRtpListenerConfiguration::ReserveNetworkAddress */ ,
    (void *) (INT_PTR) -1 /* IRtpListenerConfiguration::get_LocalSsrc */ ,
    (void *) (INT_PTR) -1 /* IRtpListenerConfiguration::put_LocalSsrc */
};

const CInterfaceStubVtbl _IRtpListenerConfigurationStubVtbl =
{
    &IID_IRtpListenerConfiguration,
    &IRtpListenerConfiguration_ServerInfo,
    10,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IRtpListenerConfigurationOut, ver. 0.0,
   GUID={0xC24FF91C,0x56E8,0x4bf7,{0x8E,0x4B,0x4B,0x44,0x09,0x86,0x2F,0xBB}} */

#pragma code_seg(".orpc")
static const unsigned short IRtpListenerConfigurationOut_FormatStringOffsetTable[] =
    {
    1890
    };

static const MIDL_STUBLESS_PROXY_INFO IRtpListenerConfigurationOut_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRtpListenerConfigurationOut_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRtpListenerConfigurationOut_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRtpListenerConfigurationOut_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IRtpListenerConfigurationOutProxyVtbl = 
{
    &IRtpListenerConfigurationOut_ProxyInfo,
    &IID_IRtpListenerConfigurationOut,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IRtpListenerConfigurationOut::GetNetworkParameter */
};

const CInterfaceStubVtbl _IRtpListenerConfigurationOutStubVtbl =
{
    &IID_IRtpListenerConfigurationOut,
    &IRtpListenerConfigurationOut_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IRtpListenerControl, ver. 0.0,
   GUID={0xC24FF91E,0x56E8,0x4bf7,{0x8E,0x4B,0x4B,0x44,0x09,0x86,0x2F,0xBB}} */

#pragma code_seg(".orpc")
static const unsigned short IRtpListenerControl_FormatStringOffsetTable[] =
    {
    1962,
    732
    };

static const MIDL_STUBLESS_PROXY_INFO IRtpListenerControl_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRtpListenerControl_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRtpListenerControl_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRtpListenerControl_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(5) _IRtpListenerControlProxyVtbl = 
{
    &IRtpListenerControl_ProxyInfo,
    &IID_IRtpListenerControl,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IRtpListenerControl::Start */ ,
    (void *) (INT_PTR) -1 /* IRtpListenerControl::Stop */
};

const CInterfaceStubVtbl _IRtpListenerControlStubVtbl =
{
    &IID_IRtpListenerControl,
    &IRtpListenerControl_ServerInfo,
    5,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IRtpListenerCallbackRegistration, ver. 0.0,
   GUID={0xC24FF920,0x56E8,0x4bf7,{0x8E,0x4B,0x4B,0x44,0x09,0x86,0x2F,0xBB}} */

#pragma code_seg(".orpc")
static const unsigned short IRtpListenerCallbackRegistration_FormatStringOffsetTable[] =
    {
    1992
    };

static const MIDL_STUBLESS_PROXY_INFO IRtpListenerCallbackRegistration_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRtpListenerCallbackRegistration_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRtpListenerCallbackRegistration_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRtpListenerCallbackRegistration_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IRtpListenerCallbackRegistrationProxyVtbl = 
{
    &IRtpListenerCallbackRegistration_ProxyInfo,
    &IID_IRtpListenerCallbackRegistration,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IRtpListenerCallbackRegistration::RegisterCallback */
};

const CInterfaceStubVtbl _IRtpListenerCallbackRegistrationStubVtbl =
{
    &IID_IRtpListenerCallbackRegistration,
    &IRtpListenerCallbackRegistration_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IRtpBufferedListener, ver. 0.0,
   GUID={0xC24FF921,0x56E8,0x4bf7,{0x8E,0x4B,0x4B,0x44,0x09,0x86,0x2F,0xBB}} */

#pragma code_seg(".orpc")
static const unsigned short IRtpBufferedListener_FormatStringOffsetTable[] =
    {
    2028,
    798,
    2064,
    2130,
    2166,
    2202,
    2244,
    2280,
    2322,
    2364,
    2406,
    2448
    };

static const MIDL_STUBLESS_PROXY_INFO IRtpBufferedListener_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRtpBufferedListener_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRtpBufferedListener_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRtpBufferedListener_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(15) _IRtpBufferedListenerProxyVtbl = 
{
    &IRtpBufferedListener_ProxyInfo,
    &IID_IRtpBufferedListener,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListener::SetPlayoutBufferGuid */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListener::SubscribeSsrc */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListener::SubscribeSsrcAndGetPointerEx */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListener::UnsubscribeSsrc */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListener::GetSubscribedSourcesCount */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListener::GetSubscribedSources */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListener::GetActiveSourcesCount */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListener::GetActiveSources */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListener::SetMuted */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListener::GetMuted */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListener::SetJitterBufferLatency */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListener::GetJitterBufferLatency */
};

const CInterfaceStubVtbl _IRtpBufferedListenerStubVtbl =
{
    &IID_IRtpBufferedListener,
    &IRtpBufferedListener_ServerInfo,
    15,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IRtpBufferedListenerData, ver. 0.0,
   GUID={0xC24FF922,0x56E8,0x4bf7,{0x8E,0x4B,0x4B,0x44,0x09,0x86,0x2F,0xBB}} */

#pragma code_seg(".orpc")
static const unsigned short IRtpBufferedListenerData_FormatStringOffsetTable[] =
    {
    2490
    };

static const MIDL_STUBLESS_PROXY_INFO IRtpBufferedListenerData_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRtpBufferedListenerData_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRtpBufferedListenerData_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRtpBufferedListenerData_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IRtpBufferedListenerDataProxyVtbl = 
{
    &IRtpBufferedListenerData_ProxyInfo,
    &IID_IRtpBufferedListenerData,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListenerData::GetDeliveryUnit */
};

const CInterfaceStubVtbl _IRtpBufferedListenerDataStubVtbl =
{
    &IID_IRtpBufferedListenerData,
    &IRtpBufferedListenerData_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IRtpListener, ver. 0.0,
   GUID={0xC24FF923,0x56E8,0x4bf7,{0x8E,0x4B,0x4B,0x44,0x09,0x86,0x2F,0xBB}} */

#pragma code_seg(".orpc")
static const unsigned short IRtpListener_FormatStringOffsetTable[] =
    {
    2538,
    2580
    };

static const MIDL_STUBLESS_PROXY_INFO IRtpListener_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRtpListener_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRtpListener_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRtpListener_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(5) _IRtpListenerProxyVtbl = 
{
    &IRtpListener_ProxyInfo,
    &IID_IRtpListener,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IRtpListener::GetRtcpAttributes */ ,
    (void *) (INT_PTR) -1 /* IRtpListener::GetSessionMemberInfo */
};

const CInterfaceStubVtbl _IRtpListenerStubVtbl =
{
    &IID_IRtpListener,
    &IRtpListener_ServerInfo,
    5,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Standard interface: __MIDL_itf__Kite2ERtp2EAtl_0756, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IRtpPayloadPacketizer, ver. 0.0,
   GUID={0x66AA121D,0x17DD,0x469B,{0x9D,0x25,0xC7,0xF7,0x25,0x0C,0xDD,0x99}} */

#pragma code_seg(".orpc")
static const unsigned short IRtpPayloadPacketizer_FormatStringOffsetTable[] =
    {
    696,
    798,
    2628,
    2664,
    2700,
    2760
    };

static const MIDL_STUBLESS_PROXY_INFO IRtpPayloadPacketizer_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRtpPayloadPacketizer_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRtpPayloadPacketizer_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRtpPayloadPacketizer_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(9) _IRtpPayloadPacketizerProxyVtbl = 
{
    &IRtpPayloadPacketizer_ProxyInfo,
    &IID_IRtpPayloadPacketizer,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IRtpPayloadPacketizer::get_MaxBufferSize */ ,
    (void *) (INT_PTR) -1 /* IRtpPayloadPacketizer::put_MaxBufferSize */ ,
    (void *) (INT_PTR) -1 /* IRtpPayloadPacketizer::get_GuidCount */ ,
    (void *) (INT_PTR) -1 /* IRtpPayloadPacketizer::GetGuids */ ,
    (void *) (INT_PTR) -1 /* IRtpPayloadPacketizer::Packetize */ ,
    (void *) (INT_PTR) -1 /* IRtpPayloadPacketizer::Depacketize */
};

const CInterfaceStubVtbl _IRtpPayloadPacketizerStubVtbl =
{
    &IID_IRtpPayloadPacketizer,
    &IRtpPayloadPacketizer_ServerInfo,
    9,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IRtpRendererConfiguration, ver. 0.0,
   GUID={0xDA2B5441,0xD7AE,0x45c4,{0xAE,0x59,0x86,0x20,0x36,0x15,0x25,0xDC}} */

#pragma code_seg(".orpc")
static const unsigned short IRtpRendererConfiguration_FormatStringOffsetTable[] =
    {
    2832,
    2898,
    2964,
    3036,
    918,
    3072,
    3138,
    264
    };

static const MIDL_STUBLESS_PROXY_INFO IRtpRendererConfiguration_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRtpRendererConfiguration_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRtpRendererConfiguration_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRtpRendererConfiguration_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(11) _IRtpRendererConfigurationProxyVtbl = 
{
    &IRtpRendererConfiguration_ProxyInfo,
    &IID_IRtpRendererConfiguration,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IRtpRendererConfiguration::SetNetworkParameter */ ,
    (void *) (INT_PTR) -1 /* IRtpRendererConfiguration::ReserveNetworkAddressAndCreateSockets */ ,
    (void *) (INT_PTR) -1 /* IRtpRendererConfiguration::ReserveNetworkAddress */ ,
    (void *) (INT_PTR) -1 /* IRtpRendererConfiguration::SetPayloadType */ ,
    (void *) (INT_PTR) -1 /* IRtpRendererConfiguration::SetRtpBandwidth */ ,
    (void *) (INT_PTR) -1 /* IRtpRendererConfiguration::SetRtcpParameter */ ,
    (void *) (INT_PTR) -1 /* IRtpRendererConfiguration::get_LocalSsrc */ ,
    (void *) (INT_PTR) -1 /* IRtpRendererConfiguration::put_LocalSsrc */
};

const CInterfaceStubVtbl _IRtpRendererConfigurationStubVtbl =
{
    &IID_IRtpRendererConfiguration,
    &IRtpRendererConfiguration_ServerInfo,
    11,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IRtpRendererConfigurationOut, ver. 0.0,
   GUID={0xDA2B5442,0xD7AE,0x45c4,{0xAE,0x59,0x86,0x20,0x36,0x15,0x25,0xDC}} */

#pragma code_seg(".orpc")
static const unsigned short IRtpRendererConfigurationOut_FormatStringOffsetTable[] =
    {
    1890
    };

static const MIDL_STUBLESS_PROXY_INFO IRtpRendererConfigurationOut_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRtpRendererConfigurationOut_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRtpRendererConfigurationOut_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRtpRendererConfigurationOut_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IRtpRendererConfigurationOutProxyVtbl = 
{
    &IRtpRendererConfigurationOut_ProxyInfo,
    &IID_IRtpRendererConfigurationOut,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IRtpRendererConfigurationOut::GetNetworkParameter */
};

const CInterfaceStubVtbl _IRtpRendererConfigurationOutStubVtbl =
{
    &IID_IRtpRendererConfigurationOut,
    &IRtpRendererConfigurationOut_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IRtpRendererControl, ver. 0.0,
   GUID={0xDA2B5443,0xD7AE,0x45c4,{0xAE,0x59,0x86,0x20,0x36,0x15,0x25,0xDC}} */

#pragma code_seg(".orpc")
static const unsigned short IRtpRendererControl_FormatStringOffsetTable[] =
    {
    1962,
    732
    };

static const MIDL_STUBLESS_PROXY_INFO IRtpRendererControl_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRtpRendererControl_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRtpRendererControl_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRtpRendererControl_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(5) _IRtpRendererControlProxyVtbl = 
{
    &IRtpRendererControl_ProxyInfo,
    &IID_IRtpRendererControl,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IRtpRendererControl::Start */ ,
    (void *) (INT_PTR) -1 /* IRtpRendererControl::Stop */
};

const CInterfaceStubVtbl _IRtpRendererControlStubVtbl =
{
    &IID_IRtpRendererControl,
    &IRtpRendererControl_ServerInfo,
    5,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IRtpRenderer, ver. 0.0,
   GUID={0x23AAF37A,0x90F4,0x48E9,{0xB8,0x16,0x9E,0xEA,0xFE,0x49,0x12,0xA8}} */

#pragma code_seg(".orpc")
static const unsigned short IRtpRenderer_FormatStringOffsetTable[] =
    {
    3174,
    3228
    };

static const MIDL_STUBLESS_PROXY_INFO IRtpRenderer_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRtpRenderer_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRtpRenderer_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRtpRenderer_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(5) _IRtpRendererProxyVtbl = 
{
    &IRtpRenderer_ProxyInfo,
    &IID_IRtpRenderer,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IRtpRenderer::SendRtpPacket */ ,
    (void *) (INT_PTR) -1 /* IRtpRenderer::SendRtpPayloadData */
};

const CInterfaceStubVtbl _IRtpRendererStubVtbl =
{
    &IID_IRtpRenderer,
    &IRtpRenderer_ServerInfo,
    5,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IRtpRendererFilterConfiguration_Export, ver. 0.0,
   GUID={0xDA2B5440,0xD7AE,0x45c4,{0xAE,0x59,0x86,0x20,0x36,0x15,0x25,0xDC}} */

#pragma code_seg(".orpc")
static const unsigned short IRtpRendererFilterConfiguration_Export_FormatStringOffsetTable[] =
    {
    3282,
    3318,
    3360
    };

static const MIDL_STUBLESS_PROXY_INFO IRtpRendererFilterConfiguration_Export_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRtpRendererFilterConfiguration_Export_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRtpRendererFilterConfiguration_Export_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRtpRendererFilterConfiguration_Export_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(6) _IRtpRendererFilterConfiguration_ExportProxyVtbl = 
{
    &IRtpRendererFilterConfiguration_Export_ProxyInfo,
    &IID_IRtpRendererFilterConfiguration_Export,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IRtpRendererFilterConfiguration_Export::SetRtpRenderer */ ,
    (void *) (INT_PTR) -1 /* IRtpRendererFilterConfiguration_Export::SetProtocolMediaParameter */ ,
    (void *) (INT_PTR) -1 /* IRtpRendererFilterConfiguration_Export::SetRtpPayloadPacketizer */
};

const CInterfaceStubVtbl _IRtpRendererFilterConfiguration_ExportStubVtbl =
{
    &IID_IRtpRendererFilterConfiguration_Export,
    &IRtpRendererFilterConfiguration_Export_ServerInfo,
    6,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Standard interface: __MIDL_itf__Kite2ERtp2EAtl_0762, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IRtpListenerOutputPin_Export, ver. 0.0,
   GUID={0xD32EA7FB,0x59D2,0x4a6b,{0xAC,0xCF,0xE7,0x0A,0x32,0x30,0x04,0xA3}} */

#pragma code_seg(".orpc")
static const unsigned short IRtpListenerOutputPin_Export_FormatStringOffsetTable[] =
    {
    3396
    };

static const MIDL_STUBLESS_PROXY_INFO IRtpListenerOutputPin_Export_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRtpListenerOutputPin_Export_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRtpListenerOutputPin_Export_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRtpListenerOutputPin_Export_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IRtpListenerOutputPin_ExportProxyVtbl = 
{
    &IRtpListenerOutputPin_Export_ProxyInfo,
    &IID_IRtpListenerOutputPin_Export,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IRtpListenerOutputPin_Export::GetBufferPrefix */
};

const CInterfaceStubVtbl _IRtpListenerOutputPin_ExportStubVtbl =
{
    &IID_IRtpListenerOutputPin_Export,
    &IRtpListenerOutputPin_Export_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IRtpBufferedListenerFilter_Export, ver. 0.0,
   GUID={0xD32EA7F5,0x59D2,0x4a6b,{0xAC,0xCF,0xE7,0x0A,0x32,0x30,0x04,0xA3}} */

#pragma code_seg(".orpc")
static const unsigned short IRtpBufferedListenerFilter_Export_FormatStringOffsetTable[] =
    {
    1566,
    3432,
    3486,
    876,
    918,
    3522,
    228,
    3564,
    3606,
    3642,
    3678,
    3714,
    3750,
    3792,
    3828,
    3870,
    3906,
    3942,
    3978,
    4050,
    4122,
    4164,
    4206,
    4248,
    4290,
    4332,
    4368,
    4404
    };

static const MIDL_STUBLESS_PROXY_INFO IRtpBufferedListenerFilter_Export_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRtpBufferedListenerFilter_Export_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRtpBufferedListenerFilter_Export_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRtpBufferedListenerFilter_Export_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(31) _IRtpBufferedListenerFilter_ExportProxyVtbl = 
{
    &IRtpBufferedListenerFilter_Export_ProxyInfo,
    &IID_IRtpBufferedListenerFilter_Export,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListenerFilter_Export::SetNetworkParameter */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListenerFilter_Export::SetMediaParameterDefaults */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListenerFilter_Export::SetOutputMediaType */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListenerFilter_Export::SetRtpBandwidth */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListenerFilter_Export::SetJitterBufferParameter */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListenerFilter_Export::SelectActiveSourceForOutputPin */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListenerFilter_Export::AddOutputPin */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListenerFilter_Export::AddOutputPinForActiveSource */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListenerFilter_Export::RemoveOutputPin */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListenerFilter_Export::RegisterEventHandler */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListenerFilter_Export::RegisterEventHandlerEx */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListenerFilter_Export::GetSubscribedSourcesCount */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListenerFilter_Export::GetSubscribedSources */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListenerFilter_Export::GetActiveSourcesCount */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListenerFilter_Export::GetActiveSources */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListenerFilter_Export::SetAutoSubscribeActiveSources */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListenerFilter_Export::GetAutoSubscribeActiveSources */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListenerFilter_Export::SetRtpPayloadPacketizer */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListenerFilter_Export::ReserveNetworkAddress */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListenerFilter_Export::GetNetworkParameter */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListenerFilter_Export::SetJitterBufferLatency */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListenerFilter_Export::GetJitterBufferLatency */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListenerFilter_Export::GetRtcpAttributes */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListenerFilter_Export::SetMuted */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListenerFilter_Export::GetMuted */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListenerFilter_Export::SetPinCount */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListenerFilter_Export::GetPinCount */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListenerFilter_Export::GetPinIndexForSource */
};

const CInterfaceStubVtbl _IRtpBufferedListenerFilter_ExportStubVtbl =
{
    &IID_IRtpBufferedListenerFilter_Export,
    &IRtpBufferedListenerFilter_Export_ServerInfo,
    31,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IRtpBufferedListenerFilterSingleOutputPin_Export, ver. 0.0,
   GUID={0xD32EA7E5,0x59D2,0x4A6B,{0xAC,0xCF,0xE7,0x0A,0x32,0x30,0x04,0xA3}} */

#pragma code_seg(".orpc")
static const unsigned short IRtpBufferedListenerFilterSingleOutputPin_Export_FormatStringOffsetTable[] =
    {
    4446,
    4512,
    78,
    4548
    };

static const MIDL_STUBLESS_PROXY_INFO IRtpBufferedListenerFilterSingleOutputPin_Export_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRtpBufferedListenerFilterSingleOutputPin_Export_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRtpBufferedListenerFilterSingleOutputPin_Export_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRtpBufferedListenerFilterSingleOutputPin_Export_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _IRtpBufferedListenerFilterSingleOutputPin_ExportProxyVtbl = 
{
    &IRtpBufferedListenerFilterSingleOutputPin_Export_ProxyInfo,
    &IID_IRtpBufferedListenerFilterSingleOutputPin_Export,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListenerFilterSingleOutputPin_Export::Configure */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListenerFilterSingleOutputPin_Export::SetOutputMediaType */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListenerFilterSingleOutputPin_Export::SetJitterBufferParameter */ ,
    (void *) (INT_PTR) -1 /* IRtpBufferedListenerFilterSingleOutputPin_Export::GetSubscribedSsrc */
};

const CInterfaceStubVtbl _IRtpBufferedListenerFilterSingleOutputPin_ExportStubVtbl =
{
    &IID_IRtpBufferedListenerFilterSingleOutputPin_Export,
    &IRtpBufferedListenerFilterSingleOutputPin_Export_ServerInfo,
    7,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: ITestRtpJitterBuffer, ver. 0.0,
   GUID={0x7507A94E,0xB7EB,0x4974,{0xA0,0xC4,0xCF,0xBF,0xA5,0xA7,0x48,0x74}} */

#pragma code_seg(".orpc")
static const unsigned short ITestRtpJitterBuffer_FormatStringOffsetTable[] =
    {
    1962,
    732
    };

static const MIDL_STUBLESS_PROXY_INFO ITestRtpJitterBuffer_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &ITestRtpJitterBuffer_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ITestRtpJitterBuffer_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &ITestRtpJitterBuffer_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(5) _ITestRtpJitterBufferProxyVtbl = 
{
    &ITestRtpJitterBuffer_ProxyInfo,
    &IID_ITestRtpJitterBuffer,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* ITestRtpJitterBuffer::Test */ ,
    (void *) (INT_PTR) -1 /* ITestRtpJitterBuffer::TestAudioBuffer */
};

const CInterfaceStubVtbl _ITestRtpJitterBufferStubVtbl =
{
    &IID_ITestRtpJitterBuffer,
    &ITestRtpJitterBuffer_ServerInfo,
    5,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    __MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x6000169, /* MIDL Version 6.0.361 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0   /* Reserved5 */
    };

const CInterfaceProxyVtbl * __Kite2ERtp2EAtl_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IInternetProtocolHelperProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRtpListenerConfigurationOutProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRtpPayloadPacketizerProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRtpListenerConfigurationProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRtpListenerControlProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRtpListenerCallbackRegistrationProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRtpBufferedListenerProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRtpBufferedListenerDataProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRtpListenerProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRtpRendererFilterConfiguration_ExportProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRtpRendererConfigurationProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRtpRendererConfigurationOutProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRtpRendererControlProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ITestRtpJitterBufferProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRtpReceiverStatisticsProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRtpSenderStatisticsProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRtpListenerEventConsumerProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRtpRendererEventConsumerProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRtpBufferedListenerEventConsumerProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRtpBufferedListenerFilterEventConsumerProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRtpBufferedListenerFilterEventConsumerExProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRtpRendererProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IPlayoutBufferProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IDisposableProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRtpBufferedListenerFilterSingleOutputPin_ExportProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRtpBufferedListenerFilter_ExportProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRtpListenerOutputPin_ExportProxyVtbl,
    0
};

const CInterfaceStubVtbl * __Kite2ERtp2EAtl_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IInternetProtocolHelperStubVtbl,
    ( CInterfaceStubVtbl *) &_IRtpListenerConfigurationOutStubVtbl,
    ( CInterfaceStubVtbl *) &_IRtpPayloadPacketizerStubVtbl,
    ( CInterfaceStubVtbl *) &_IRtpListenerConfigurationStubVtbl,
    ( CInterfaceStubVtbl *) &_IRtpListenerControlStubVtbl,
    ( CInterfaceStubVtbl *) &_IRtpListenerCallbackRegistrationStubVtbl,
    ( CInterfaceStubVtbl *) &_IRtpBufferedListenerStubVtbl,
    ( CInterfaceStubVtbl *) &_IRtpBufferedListenerDataStubVtbl,
    ( CInterfaceStubVtbl *) &_IRtpListenerStubVtbl,
    ( CInterfaceStubVtbl *) &_IRtpRendererFilterConfiguration_ExportStubVtbl,
    ( CInterfaceStubVtbl *) &_IRtpRendererConfigurationStubVtbl,
    ( CInterfaceStubVtbl *) &_IRtpRendererConfigurationOutStubVtbl,
    ( CInterfaceStubVtbl *) &_IRtpRendererControlStubVtbl,
    ( CInterfaceStubVtbl *) &_ITestRtpJitterBufferStubVtbl,
    ( CInterfaceStubVtbl *) &_IRtpReceiverStatisticsStubVtbl,
    ( CInterfaceStubVtbl *) &_IRtpSenderStatisticsStubVtbl,
    ( CInterfaceStubVtbl *) &_IRtpListenerEventConsumerStubVtbl,
    ( CInterfaceStubVtbl *) &_IRtpRendererEventConsumerStubVtbl,
    ( CInterfaceStubVtbl *) &_IRtpBufferedListenerEventConsumerStubVtbl,
    ( CInterfaceStubVtbl *) &_IRtpBufferedListenerFilterEventConsumerStubVtbl,
    ( CInterfaceStubVtbl *) &_IRtpBufferedListenerFilterEventConsumerExStubVtbl,
    ( CInterfaceStubVtbl *) &_IRtpRendererStubVtbl,
    ( CInterfaceStubVtbl *) &_IPlayoutBufferStubVtbl,
    ( CInterfaceStubVtbl *) &_IDisposableStubVtbl,
    ( CInterfaceStubVtbl *) &_IRtpBufferedListenerFilterSingleOutputPin_ExportStubVtbl,
    ( CInterfaceStubVtbl *) &_IRtpBufferedListenerFilter_ExportStubVtbl,
    ( CInterfaceStubVtbl *) &_IRtpListenerOutputPin_ExportStubVtbl,
    0
};

PCInterfaceName const __Kite2ERtp2EAtl_InterfaceNamesList[] = 
{
    "IInternetProtocolHelper",
    "IRtpListenerConfigurationOut",
    "IRtpPayloadPacketizer",
    "IRtpListenerConfiguration",
    "IRtpListenerControl",
    "IRtpListenerCallbackRegistration",
    "IRtpBufferedListener",
    "IRtpBufferedListenerData",
    "IRtpListener",
    "IRtpRendererFilterConfiguration_Export",
    "IRtpRendererConfiguration",
    "IRtpRendererConfigurationOut",
    "IRtpRendererControl",
    "ITestRtpJitterBuffer",
    "IRtpReceiverStatistics",
    "IRtpSenderStatistics",
    "IRtpListenerEventConsumer",
    "IRtpRendererEventConsumer",
    "IRtpBufferedListenerEventConsumer",
    "IRtpBufferedListenerFilterEventConsumer",
    "IRtpBufferedListenerFilterEventConsumerEx",
    "IRtpRenderer",
    "IPlayoutBuffer",
    "IDisposable",
    "IRtpBufferedListenerFilterSingleOutputPin_Export",
    "IRtpBufferedListenerFilter_Export",
    "IRtpListenerOutputPin_Export",
    0
};


#define __Kite2ERtp2EAtl_CHECK_IID(n)	IID_GENERIC_CHECK_IID( __Kite2ERtp2EAtl, pIID, n)

int __stdcall __Kite2ERtp2EAtl_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( __Kite2ERtp2EAtl, 27, 16 )
    IID_BS_LOOKUP_NEXT_TEST( __Kite2ERtp2EAtl, 8 )
    IID_BS_LOOKUP_NEXT_TEST( __Kite2ERtp2EAtl, 4 )
    IID_BS_LOOKUP_NEXT_TEST( __Kite2ERtp2EAtl, 2 )
    IID_BS_LOOKUP_NEXT_TEST( __Kite2ERtp2EAtl, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( __Kite2ERtp2EAtl, 27, *pIndex )
    
}

const ExtendedProxyFileInfo _Kite2ERtp2EAtl_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & __Kite2ERtp2EAtl_ProxyVtblList,
    (PCInterfaceStubVtblList *) & __Kite2ERtp2EAtl_StubVtblList,
    (const PCInterfaceName * ) & __Kite2ERtp2EAtl_InterfaceNamesList,
    0, // no delegation
    & __Kite2ERtp2EAtl_IID_Lookup, 
    27,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

