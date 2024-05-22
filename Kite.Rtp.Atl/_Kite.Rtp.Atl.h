

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef ___Kite2ERtp2EAtl_h__
#define ___Kite2ERtp2EAtl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IPlayoutBuffer_FWD_DEFINED__
#define __IPlayoutBuffer_FWD_DEFINED__
typedef interface IPlayoutBuffer IPlayoutBuffer;
#endif 	/* __IPlayoutBuffer_FWD_DEFINED__ */


#ifndef __IDisposable_FWD_DEFINED__
#define __IDisposable_FWD_DEFINED__
typedef interface IDisposable IDisposable;
#endif 	/* __IDisposable_FWD_DEFINED__ */


#ifndef __IRtpBufferedListenerFilterEventConsumer_FWD_DEFINED__
#define __IRtpBufferedListenerFilterEventConsumer_FWD_DEFINED__
typedef interface IRtpBufferedListenerFilterEventConsumer IRtpBufferedListenerFilterEventConsumer;
#endif 	/* __IRtpBufferedListenerFilterEventConsumer_FWD_DEFINED__ */


#ifndef __IRtpBufferedListenerFilterEventConsumerEx_FWD_DEFINED__
#define __IRtpBufferedListenerFilterEventConsumerEx_FWD_DEFINED__
typedef interface IRtpBufferedListenerFilterEventConsumerEx IRtpBufferedListenerFilterEventConsumerEx;
#endif 	/* __IRtpBufferedListenerFilterEventConsumerEx_FWD_DEFINED__ */


#ifndef __IRtpListenerEventConsumer_FWD_DEFINED__
#define __IRtpListenerEventConsumer_FWD_DEFINED__
typedef interface IRtpListenerEventConsumer IRtpListenerEventConsumer;
#endif 	/* __IRtpListenerEventConsumer_FWD_DEFINED__ */


#ifndef __IRtpBufferedListenerEventConsumer_FWD_DEFINED__
#define __IRtpBufferedListenerEventConsumer_FWD_DEFINED__
typedef interface IRtpBufferedListenerEventConsumer IRtpBufferedListenerEventConsumer;
#endif 	/* __IRtpBufferedListenerEventConsumer_FWD_DEFINED__ */


#ifndef __IRtpRendererEventConsumer_FWD_DEFINED__
#define __IRtpRendererEventConsumer_FWD_DEFINED__
typedef interface IRtpRendererEventConsumer IRtpRendererEventConsumer;
#endif 	/* __IRtpRendererEventConsumer_FWD_DEFINED__ */


#ifndef __IRtpReceiverStatistics_FWD_DEFINED__
#define __IRtpReceiverStatistics_FWD_DEFINED__
typedef interface IRtpReceiverStatistics IRtpReceiverStatistics;
#endif 	/* __IRtpReceiverStatistics_FWD_DEFINED__ */


#ifndef __IRtpSenderStatistics_FWD_DEFINED__
#define __IRtpSenderStatistics_FWD_DEFINED__
typedef interface IRtpSenderStatistics IRtpSenderStatistics;
#endif 	/* __IRtpSenderStatistics_FWD_DEFINED__ */


#ifndef __IInternetProtocolHelper_FWD_DEFINED__
#define __IInternetProtocolHelper_FWD_DEFINED__
typedef interface IInternetProtocolHelper IInternetProtocolHelper;
#endif 	/* __IInternetProtocolHelper_FWD_DEFINED__ */


#ifndef __IRtpListenerConfiguration_FWD_DEFINED__
#define __IRtpListenerConfiguration_FWD_DEFINED__
typedef interface IRtpListenerConfiguration IRtpListenerConfiguration;
#endif 	/* __IRtpListenerConfiguration_FWD_DEFINED__ */


#ifndef __IRtpListenerConfigurationOut_FWD_DEFINED__
#define __IRtpListenerConfigurationOut_FWD_DEFINED__
typedef interface IRtpListenerConfigurationOut IRtpListenerConfigurationOut;
#endif 	/* __IRtpListenerConfigurationOut_FWD_DEFINED__ */


#ifndef __IRtpListenerControl_FWD_DEFINED__
#define __IRtpListenerControl_FWD_DEFINED__
typedef interface IRtpListenerControl IRtpListenerControl;
#endif 	/* __IRtpListenerControl_FWD_DEFINED__ */


#ifndef __IRtpListenerCallbackRegistration_FWD_DEFINED__
#define __IRtpListenerCallbackRegistration_FWD_DEFINED__
typedef interface IRtpListenerCallbackRegistration IRtpListenerCallbackRegistration;
#endif 	/* __IRtpListenerCallbackRegistration_FWD_DEFINED__ */


#ifndef __IRtpBufferedListener_FWD_DEFINED__
#define __IRtpBufferedListener_FWD_DEFINED__
typedef interface IRtpBufferedListener IRtpBufferedListener;
#endif 	/* __IRtpBufferedListener_FWD_DEFINED__ */


#ifndef __IRtpBufferedListenerData_FWD_DEFINED__
#define __IRtpBufferedListenerData_FWD_DEFINED__
typedef interface IRtpBufferedListenerData IRtpBufferedListenerData;
#endif 	/* __IRtpBufferedListenerData_FWD_DEFINED__ */


#ifndef __IRtpListener_FWD_DEFINED__
#define __IRtpListener_FWD_DEFINED__
typedef interface IRtpListener IRtpListener;
#endif 	/* __IRtpListener_FWD_DEFINED__ */


#ifndef __IRtpPayloadPacketizer_FWD_DEFINED__
#define __IRtpPayloadPacketizer_FWD_DEFINED__
typedef interface IRtpPayloadPacketizer IRtpPayloadPacketizer;
#endif 	/* __IRtpPayloadPacketizer_FWD_DEFINED__ */


#ifndef __IRtpRendererConfiguration_FWD_DEFINED__
#define __IRtpRendererConfiguration_FWD_DEFINED__
typedef interface IRtpRendererConfiguration IRtpRendererConfiguration;
#endif 	/* __IRtpRendererConfiguration_FWD_DEFINED__ */


#ifndef __IRtpRendererConfigurationOut_FWD_DEFINED__
#define __IRtpRendererConfigurationOut_FWD_DEFINED__
typedef interface IRtpRendererConfigurationOut IRtpRendererConfigurationOut;
#endif 	/* __IRtpRendererConfigurationOut_FWD_DEFINED__ */


#ifndef __IRtpRendererControl_FWD_DEFINED__
#define __IRtpRendererControl_FWD_DEFINED__
typedef interface IRtpRendererControl IRtpRendererControl;
#endif 	/* __IRtpRendererControl_FWD_DEFINED__ */


#ifndef __IRtpRenderer_FWD_DEFINED__
#define __IRtpRenderer_FWD_DEFINED__
typedef interface IRtpRenderer IRtpRenderer;
#endif 	/* __IRtpRenderer_FWD_DEFINED__ */


#ifndef __IRtpRendererFilterConfiguration_Export_FWD_DEFINED__
#define __IRtpRendererFilterConfiguration_Export_FWD_DEFINED__
typedef interface IRtpRendererFilterConfiguration_Export IRtpRendererFilterConfiguration_Export;
#endif 	/* __IRtpRendererFilterConfiguration_Export_FWD_DEFINED__ */


#ifndef __IRtpListenerOutputPin_Export_FWD_DEFINED__
#define __IRtpListenerOutputPin_Export_FWD_DEFINED__
typedef interface IRtpListenerOutputPin_Export IRtpListenerOutputPin_Export;
#endif 	/* __IRtpListenerOutputPin_Export_FWD_DEFINED__ */


#ifndef __IRtpBufferedListenerFilter_Export_FWD_DEFINED__
#define __IRtpBufferedListenerFilter_Export_FWD_DEFINED__
typedef interface IRtpBufferedListenerFilter_Export IRtpBufferedListenerFilter_Export;
#endif 	/* __IRtpBufferedListenerFilter_Export_FWD_DEFINED__ */


#ifndef __IRtpBufferedListenerFilterSingleOutputPin_Export_FWD_DEFINED__
#define __IRtpBufferedListenerFilterSingleOutputPin_Export_FWD_DEFINED__
typedef interface IRtpBufferedListenerFilterSingleOutputPin_Export IRtpBufferedListenerFilterSingleOutputPin_Export;
#endif 	/* __IRtpBufferedListenerFilterSingleOutputPin_Export_FWD_DEFINED__ */


#ifndef __ITestRtpJitterBuffer_FWD_DEFINED__
#define __ITestRtpJitterBuffer_FWD_DEFINED__
typedef interface ITestRtpJitterBuffer ITestRtpJitterBuffer;
#endif 	/* __ITestRtpJitterBuffer_FWD_DEFINED__ */


#ifndef __CAudioPlayoutBuffer_FWD_DEFINED__
#define __CAudioPlayoutBuffer_FWD_DEFINED__

#ifdef __cplusplus
typedef class CAudioPlayoutBuffer CAudioPlayoutBuffer;
#else
typedef struct CAudioPlayoutBuffer CAudioPlayoutBuffer;
#endif /* __cplusplus */

#endif 	/* __CAudioPlayoutBuffer_FWD_DEFINED__ */


#ifndef __CVideoPlayoutBuffer_FWD_DEFINED__
#define __CVideoPlayoutBuffer_FWD_DEFINED__

#ifdef __cplusplus
typedef class CVideoPlayoutBuffer CVideoPlayoutBuffer;
#else
typedef struct CVideoPlayoutBuffer CVideoPlayoutBuffer;
#endif /* __cplusplus */

#endif 	/* __CVideoPlayoutBuffer_FWD_DEFINED__ */


#ifndef __CInternetProtocolHelper_FWD_DEFINED__
#define __CInternetProtocolHelper_FWD_DEFINED__

#ifdef __cplusplus
typedef class CInternetProtocolHelper CInternetProtocolHelper;
#else
typedef struct CInternetProtocolHelper CInternetProtocolHelper;
#endif /* __cplusplus */

#endif 	/* __CInternetProtocolHelper_FWD_DEFINED__ */


#ifndef ___IRtpListenerEvents_FWD_DEFINED__
#define ___IRtpListenerEvents_FWD_DEFINED__
typedef interface _IRtpListenerEvents _IRtpListenerEvents;
#endif 	/* ___IRtpListenerEvents_FWD_DEFINED__ */


#ifndef __CRtpListener_FWD_DEFINED__
#define __CRtpListener_FWD_DEFINED__

#ifdef __cplusplus
typedef class CRtpListener CRtpListener;
#else
typedef struct CRtpListener CRtpListener;
#endif /* __cplusplus */

#endif 	/* __CRtpListener_FWD_DEFINED__ */


#ifndef __CRtpBufferedListener_FWD_DEFINED__
#define __CRtpBufferedListener_FWD_DEFINED__

#ifdef __cplusplus
typedef class CRtpBufferedListener CRtpBufferedListener;
#else
typedef struct CRtpBufferedListener CRtpBufferedListener;
#endif /* __cplusplus */

#endif 	/* __CRtpBufferedListener_FWD_DEFINED__ */


#ifndef __CRtpRenderer_FWD_DEFINED__
#define __CRtpRenderer_FWD_DEFINED__

#ifdef __cplusplus
typedef class CRtpRenderer CRtpRenderer;
#else
typedef struct CRtpRenderer CRtpRenderer;
#endif /* __cplusplus */

#endif 	/* __CRtpRenderer_FWD_DEFINED__ */


#ifndef __CTest_FWD_DEFINED__
#define __CTest_FWD_DEFINED__

#ifdef __cplusplus
typedef class CTest CTest;
#else
typedef struct CTest CTest;
#endif /* __cplusplus */

#endif 	/* __CTest_FWD_DEFINED__ */


#ifndef __CTestRtpJitterBuffer_FWD_DEFINED__
#define __CTestRtpJitterBuffer_FWD_DEFINED__

#ifdef __cplusplus
typedef class CTestRtpJitterBuffer CTestRtpJitterBuffer;
#else
typedef struct CTestRtpJitterBuffer CTestRtpJitterBuffer;
#endif /* __cplusplus */

#endif 	/* __CTestRtpJitterBuffer_FWD_DEFINED__ */


/* header files for imported files */
#include "prsht.h"
#include "mshtml.h"
#include "mshtmhst.h"
#include "exdisp.h"
#include "objsafe.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf__Kite2ERtp2EAtl_0000 */
/* [local] */ 

struct RtpParsedPacket
    {
    BOOL pad;
    BOOL ext;
    BOOL marker;
    UINT cc;
    UINT timestamp;
    UINT ssrc;
    USHORT seqNum;
    USHORT cbData;
    UINT payloadType;
    BYTE *pData;
    } ;
struct SdesItems
    {
    CHAR cname[ 255 ];
    CHAR name[ 255 ];
    CHAR email[ 255 ];
    CHAR phone[ 255 ];
    CHAR loc[ 255 ];
    CHAR tool[ 255 ];
    CHAR note[ 255 ];
    UINT ssrc;
    } ;


extern RPC_IF_HANDLE __MIDL_itf__Kite2ERtp2EAtl_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf__Kite2ERtp2EAtl_0000_v0_0_s_ifspec;

#ifndef __IPlayoutBuffer_INTERFACE_DEFINED__
#define __IPlayoutBuffer_INTERFACE_DEFINED__

/* interface IPlayoutBuffer */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPlayoutBuffer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("53F0C4D4-9926-4F1E-B0FF-47EAF6AA1F5A")
    IPlayoutBuffer : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EnqueuePacket( 
            /* [in] */ struct RtpParsedPacket *pPacket) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DequeuePackets( 
            /* [in] */ struct RtpParsedPacket ***pppRtpParsedPackets,
            /* [in] */ UINT *pcPackets) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ExpireOlderThanOrEqual( 
            /* [in] */ UINT uTimestamp) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ClearBuffer( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBufferParameter( 
            /* [in] */ UINT uBufferDurationMilliseconds,
            /* [in] */ UINT uTimestampIncrementPerSecond,
            /* [in] */ UINT uTimePerFrameNanos) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetLatency( 
            /* [in] */ UINT uLatency) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLatency( 
            /* [in] */ UINT *puLatency) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMuted( 
            /* [in] */ BOOL bMuted) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMuted( 
            /* [in] */ BOOL *pbMuted) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PayloadType( 
            /* [retval][out] */ BYTE *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_PayloadType( 
            /* [in] */ BYTE newVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_DueTime( 
            /* [retval][out] */ UINT *pDueTimeMilliseconds) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_EventHandle( 
            /* [retval][out] */ LONG_PTR **pEventHandle) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_BufferDurationMilliseconds( 
            /* [retval][out] */ UINT *pVal) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_BufferDurationMilliseconds( 
            /* [in] */ UINT newVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_RtpTimestampIncrementPerSecond( 
            /* [retval][out] */ UINT *pVal) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_RtpTimestampIncrementPerSecond( 
            /* [in] */ UINT newVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_TimePerSampleNanos( 
            /* [retval][out] */ UINT *pVal) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_TimePerSampleNanos( 
            /* [in] */ UINT newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlayoutBufferVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPlayoutBuffer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPlayoutBuffer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPlayoutBuffer * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnqueuePacket )( 
            IPlayoutBuffer * This,
            /* [in] */ struct RtpParsedPacket *pPacket);
        
        HRESULT ( STDMETHODCALLTYPE *DequeuePackets )( 
            IPlayoutBuffer * This,
            /* [in] */ struct RtpParsedPacket ***pppRtpParsedPackets,
            /* [in] */ UINT *pcPackets);
        
        HRESULT ( STDMETHODCALLTYPE *ExpireOlderThanOrEqual )( 
            IPlayoutBuffer * This,
            /* [in] */ UINT uTimestamp);
        
        HRESULT ( STDMETHODCALLTYPE *ClearBuffer )( 
            IPlayoutBuffer * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetBufferParameter )( 
            IPlayoutBuffer * This,
            /* [in] */ UINT uBufferDurationMilliseconds,
            /* [in] */ UINT uTimestampIncrementPerSecond,
            /* [in] */ UINT uTimePerFrameNanos);
        
        HRESULT ( STDMETHODCALLTYPE *SetLatency )( 
            IPlayoutBuffer * This,
            /* [in] */ UINT uLatency);
        
        HRESULT ( STDMETHODCALLTYPE *GetLatency )( 
            IPlayoutBuffer * This,
            /* [in] */ UINT *puLatency);
        
        HRESULT ( STDMETHODCALLTYPE *SetMuted )( 
            IPlayoutBuffer * This,
            /* [in] */ BOOL bMuted);
        
        HRESULT ( STDMETHODCALLTYPE *GetMuted )( 
            IPlayoutBuffer * This,
            /* [in] */ BOOL *pbMuted);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PayloadType )( 
            IPlayoutBuffer * This,
            /* [retval][out] */ BYTE *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PayloadType )( 
            IPlayoutBuffer * This,
            /* [in] */ BYTE newVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_DueTime )( 
            IPlayoutBuffer * This,
            /* [retval][out] */ UINT *pDueTimeMilliseconds);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_EventHandle )( 
            IPlayoutBuffer * This,
            /* [retval][out] */ LONG_PTR **pEventHandle);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_BufferDurationMilliseconds )( 
            IPlayoutBuffer * This,
            /* [retval][out] */ UINT *pVal);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_BufferDurationMilliseconds )( 
            IPlayoutBuffer * This,
            /* [in] */ UINT newVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_RtpTimestampIncrementPerSecond )( 
            IPlayoutBuffer * This,
            /* [retval][out] */ UINT *pVal);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_RtpTimestampIncrementPerSecond )( 
            IPlayoutBuffer * This,
            /* [in] */ UINT newVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_TimePerSampleNanos )( 
            IPlayoutBuffer * This,
            /* [retval][out] */ UINT *pVal);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_TimePerSampleNanos )( 
            IPlayoutBuffer * This,
            /* [in] */ UINT newVal);
        
        END_INTERFACE
    } IPlayoutBufferVtbl;

    interface IPlayoutBuffer
    {
        CONST_VTBL struct IPlayoutBufferVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlayoutBuffer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlayoutBuffer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlayoutBuffer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlayoutBuffer_EnqueuePacket(This,pPacket)	\
    (This)->lpVtbl -> EnqueuePacket(This,pPacket)

#define IPlayoutBuffer_DequeuePackets(This,pppRtpParsedPackets,pcPackets)	\
    (This)->lpVtbl -> DequeuePackets(This,pppRtpParsedPackets,pcPackets)

#define IPlayoutBuffer_ExpireOlderThanOrEqual(This,uTimestamp)	\
    (This)->lpVtbl -> ExpireOlderThanOrEqual(This,uTimestamp)

#define IPlayoutBuffer_ClearBuffer(This)	\
    (This)->lpVtbl -> ClearBuffer(This)

#define IPlayoutBuffer_SetBufferParameter(This,uBufferDurationMilliseconds,uTimestampIncrementPerSecond,uTimePerFrameNanos)	\
    (This)->lpVtbl -> SetBufferParameter(This,uBufferDurationMilliseconds,uTimestampIncrementPerSecond,uTimePerFrameNanos)

#define IPlayoutBuffer_SetLatency(This,uLatency)	\
    (This)->lpVtbl -> SetLatency(This,uLatency)

#define IPlayoutBuffer_GetLatency(This,puLatency)	\
    (This)->lpVtbl -> GetLatency(This,puLatency)

#define IPlayoutBuffer_SetMuted(This,bMuted)	\
    (This)->lpVtbl -> SetMuted(This,bMuted)

#define IPlayoutBuffer_GetMuted(This,pbMuted)	\
    (This)->lpVtbl -> GetMuted(This,pbMuted)

#define IPlayoutBuffer_get_PayloadType(This,pVal)	\
    (This)->lpVtbl -> get_PayloadType(This,pVal)

#define IPlayoutBuffer_put_PayloadType(This,newVal)	\
    (This)->lpVtbl -> put_PayloadType(This,newVal)

#define IPlayoutBuffer_get_DueTime(This,pDueTimeMilliseconds)	\
    (This)->lpVtbl -> get_DueTime(This,pDueTimeMilliseconds)

#define IPlayoutBuffer_get_EventHandle(This,pEventHandle)	\
    (This)->lpVtbl -> get_EventHandle(This,pEventHandle)

#define IPlayoutBuffer_get_BufferDurationMilliseconds(This,pVal)	\
    (This)->lpVtbl -> get_BufferDurationMilliseconds(This,pVal)

#define IPlayoutBuffer_put_BufferDurationMilliseconds(This,newVal)	\
    (This)->lpVtbl -> put_BufferDurationMilliseconds(This,newVal)

#define IPlayoutBuffer_get_RtpTimestampIncrementPerSecond(This,pVal)	\
    (This)->lpVtbl -> get_RtpTimestampIncrementPerSecond(This,pVal)

#define IPlayoutBuffer_put_RtpTimestampIncrementPerSecond(This,newVal)	\
    (This)->lpVtbl -> put_RtpTimestampIncrementPerSecond(This,newVal)

#define IPlayoutBuffer_get_TimePerSampleNanos(This,pVal)	\
    (This)->lpVtbl -> get_TimePerSampleNanos(This,pVal)

#define IPlayoutBuffer_put_TimePerSampleNanos(This,newVal)	\
    (This)->lpVtbl -> put_TimePerSampleNanos(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlayoutBuffer_EnqueuePacket_Proxy( 
    IPlayoutBuffer * This,
    /* [in] */ struct RtpParsedPacket *pPacket);


void __RPC_STUB IPlayoutBuffer_EnqueuePacket_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayoutBuffer_DequeuePackets_Proxy( 
    IPlayoutBuffer * This,
    /* [in] */ struct RtpParsedPacket ***pppRtpParsedPackets,
    /* [in] */ UINT *pcPackets);


void __RPC_STUB IPlayoutBuffer_DequeuePackets_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayoutBuffer_ExpireOlderThanOrEqual_Proxy( 
    IPlayoutBuffer * This,
    /* [in] */ UINT uTimestamp);


void __RPC_STUB IPlayoutBuffer_ExpireOlderThanOrEqual_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayoutBuffer_ClearBuffer_Proxy( 
    IPlayoutBuffer * This);


void __RPC_STUB IPlayoutBuffer_ClearBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayoutBuffer_SetBufferParameter_Proxy( 
    IPlayoutBuffer * This,
    /* [in] */ UINT uBufferDurationMilliseconds,
    /* [in] */ UINT uTimestampIncrementPerSecond,
    /* [in] */ UINT uTimePerFrameNanos);


void __RPC_STUB IPlayoutBuffer_SetBufferParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayoutBuffer_SetLatency_Proxy( 
    IPlayoutBuffer * This,
    /* [in] */ UINT uLatency);


void __RPC_STUB IPlayoutBuffer_SetLatency_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayoutBuffer_GetLatency_Proxy( 
    IPlayoutBuffer * This,
    /* [in] */ UINT *puLatency);


void __RPC_STUB IPlayoutBuffer_GetLatency_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayoutBuffer_SetMuted_Proxy( 
    IPlayoutBuffer * This,
    /* [in] */ BOOL bMuted);


void __RPC_STUB IPlayoutBuffer_SetMuted_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlayoutBuffer_GetMuted_Proxy( 
    IPlayoutBuffer * This,
    /* [in] */ BOOL *pbMuted);


void __RPC_STUB IPlayoutBuffer_GetMuted_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IPlayoutBuffer_get_PayloadType_Proxy( 
    IPlayoutBuffer * This,
    /* [retval][out] */ BYTE *pVal);


void __RPC_STUB IPlayoutBuffer_get_PayloadType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IPlayoutBuffer_put_PayloadType_Proxy( 
    IPlayoutBuffer * This,
    /* [in] */ BYTE newVal);


void __RPC_STUB IPlayoutBuffer_put_PayloadType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IPlayoutBuffer_get_DueTime_Proxy( 
    IPlayoutBuffer * This,
    /* [retval][out] */ UINT *pDueTimeMilliseconds);


void __RPC_STUB IPlayoutBuffer_get_DueTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IPlayoutBuffer_get_EventHandle_Proxy( 
    IPlayoutBuffer * This,
    /* [retval][out] */ LONG_PTR **pEventHandle);


void __RPC_STUB IPlayoutBuffer_get_EventHandle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IPlayoutBuffer_get_BufferDurationMilliseconds_Proxy( 
    IPlayoutBuffer * This,
    /* [retval][out] */ UINT *pVal);


void __RPC_STUB IPlayoutBuffer_get_BufferDurationMilliseconds_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IPlayoutBuffer_put_BufferDurationMilliseconds_Proxy( 
    IPlayoutBuffer * This,
    /* [in] */ UINT newVal);


void __RPC_STUB IPlayoutBuffer_put_BufferDurationMilliseconds_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IPlayoutBuffer_get_RtpTimestampIncrementPerSecond_Proxy( 
    IPlayoutBuffer * This,
    /* [retval][out] */ UINT *pVal);


void __RPC_STUB IPlayoutBuffer_get_RtpTimestampIncrementPerSecond_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IPlayoutBuffer_put_RtpTimestampIncrementPerSecond_Proxy( 
    IPlayoutBuffer * This,
    /* [in] */ UINT newVal);


void __RPC_STUB IPlayoutBuffer_put_RtpTimestampIncrementPerSecond_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IPlayoutBuffer_get_TimePerSampleNanos_Proxy( 
    IPlayoutBuffer * This,
    /* [retval][out] */ UINT *pVal);


void __RPC_STUB IPlayoutBuffer_get_TimePerSampleNanos_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IPlayoutBuffer_put_TimePerSampleNanos_Proxy( 
    IPlayoutBuffer * This,
    /* [in] */ UINT newVal);


void __RPC_STUB IPlayoutBuffer_put_TimePerSampleNanos_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlayoutBuffer_INTERFACE_DEFINED__ */


#ifndef __IDisposable_INTERFACE_DEFINED__
#define __IDisposable_INTERFACE_DEFINED__

/* interface IDisposable */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IDisposable;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("53F0C4D5-9926-4F1E-B0FF-47EAF6AA1F5A")
    IDisposable : public IUnknown
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Disposed( 
            /* [retval][out] */ BOOL *pVal) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Dispose( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDisposableVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDisposable * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDisposable * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDisposable * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Disposed )( 
            IDisposable * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Dispose )( 
            IDisposable * This);
        
        END_INTERFACE
    } IDisposableVtbl;

    interface IDisposable
    {
        CONST_VTBL struct IDisposableVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDisposable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDisposable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDisposable_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDisposable_get_Disposed(This,pVal)	\
    (This)->lpVtbl -> get_Disposed(This,pVal)

#define IDisposable_Dispose(This)	\
    (This)->lpVtbl -> Dispose(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IDisposable_get_Disposed_Proxy( 
    IDisposable * This,
    /* [retval][out] */ BOOL *pVal);


void __RPC_STUB IDisposable_get_Disposed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDisposable_Dispose_Proxy( 
    IDisposable * This);


void __RPC_STUB IDisposable_Dispose_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDisposable_INTERFACE_DEFINED__ */


#ifndef __IRtpBufferedListenerFilterEventConsumer_INTERFACE_DEFINED__
#define __IRtpBufferedListenerFilterEventConsumer_INTERFACE_DEFINED__

/* interface IRtpBufferedListenerFilterEventConsumer */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRtpBufferedListenerFilterEventConsumer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1ABEA164-797F-4A07-93AD-7DACBE477F48")
    IRtpBufferedListenerFilterEventConsumer : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ActiveSourceAdded( 
            /* [in] */ UINT ssrc) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ActiveSourceRemoved( 
            /* [in] */ UINT ssrc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SourceActiveValueChanged( 
            /* [in] */ UINT ssrc,
            /* [in] */ INT active) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SourceMuteValueChanged( 
            /* [in] */ UINT ssrc,
            /* [in] */ INT muted) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SourceEvent( 
            /* [in] */ UINT ssrc,
            /* [in] */ INT eventType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SourceReception( 
            /* [in] */ UINT ssrc,
            /* [in] */ INT packetsRecvd,
            /* [in] */ INT packetsLost,
            /* [in] */ INT packetsMisordered,
            /* [in] */ INT jitter,
            /* [in] */ INT validityTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SourceAttributes( 
            /* [in] */ UINT ssrc,
            /* [in] */ LPWSTR cname,
            /* [in] */ LPWSTR name,
            /* [in] */ LPWSTR email,
            /* [in] */ LPWSTR phone,
            /* [in] */ LPWSTR loc,
            /* [in] */ LPWSTR tool,
            /* [in] */ LPWSTR note) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRtpBufferedListenerFilterEventConsumerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRtpBufferedListenerFilterEventConsumer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRtpBufferedListenerFilterEventConsumer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRtpBufferedListenerFilterEventConsumer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ActiveSourceAdded )( 
            IRtpBufferedListenerFilterEventConsumer * This,
            /* [in] */ UINT ssrc);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ActiveSourceRemoved )( 
            IRtpBufferedListenerFilterEventConsumer * This,
            /* [in] */ UINT ssrc);
        
        HRESULT ( STDMETHODCALLTYPE *SourceActiveValueChanged )( 
            IRtpBufferedListenerFilterEventConsumer * This,
            /* [in] */ UINT ssrc,
            /* [in] */ INT active);
        
        HRESULT ( STDMETHODCALLTYPE *SourceMuteValueChanged )( 
            IRtpBufferedListenerFilterEventConsumer * This,
            /* [in] */ UINT ssrc,
            /* [in] */ INT muted);
        
        HRESULT ( STDMETHODCALLTYPE *SourceEvent )( 
            IRtpBufferedListenerFilterEventConsumer * This,
            /* [in] */ UINT ssrc,
            /* [in] */ INT eventType);
        
        HRESULT ( STDMETHODCALLTYPE *SourceReception )( 
            IRtpBufferedListenerFilterEventConsumer * This,
            /* [in] */ UINT ssrc,
            /* [in] */ INT packetsRecvd,
            /* [in] */ INT packetsLost,
            /* [in] */ INT packetsMisordered,
            /* [in] */ INT jitter,
            /* [in] */ INT validityTime);
        
        HRESULT ( STDMETHODCALLTYPE *SourceAttributes )( 
            IRtpBufferedListenerFilterEventConsumer * This,
            /* [in] */ UINT ssrc,
            /* [in] */ LPWSTR cname,
            /* [in] */ LPWSTR name,
            /* [in] */ LPWSTR email,
            /* [in] */ LPWSTR phone,
            /* [in] */ LPWSTR loc,
            /* [in] */ LPWSTR tool,
            /* [in] */ LPWSTR note);
        
        END_INTERFACE
    } IRtpBufferedListenerFilterEventConsumerVtbl;

    interface IRtpBufferedListenerFilterEventConsumer
    {
        CONST_VTBL struct IRtpBufferedListenerFilterEventConsumerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRtpBufferedListenerFilterEventConsumer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRtpBufferedListenerFilterEventConsumer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRtpBufferedListenerFilterEventConsumer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRtpBufferedListenerFilterEventConsumer_ActiveSourceAdded(This,ssrc)	\
    (This)->lpVtbl -> ActiveSourceAdded(This,ssrc)

#define IRtpBufferedListenerFilterEventConsumer_ActiveSourceRemoved(This,ssrc)	\
    (This)->lpVtbl -> ActiveSourceRemoved(This,ssrc)

#define IRtpBufferedListenerFilterEventConsumer_SourceActiveValueChanged(This,ssrc,active)	\
    (This)->lpVtbl -> SourceActiveValueChanged(This,ssrc,active)

#define IRtpBufferedListenerFilterEventConsumer_SourceMuteValueChanged(This,ssrc,muted)	\
    (This)->lpVtbl -> SourceMuteValueChanged(This,ssrc,muted)

#define IRtpBufferedListenerFilterEventConsumer_SourceEvent(This,ssrc,eventType)	\
    (This)->lpVtbl -> SourceEvent(This,ssrc,eventType)

#define IRtpBufferedListenerFilterEventConsumer_SourceReception(This,ssrc,packetsRecvd,packetsLost,packetsMisordered,jitter,validityTime)	\
    (This)->lpVtbl -> SourceReception(This,ssrc,packetsRecvd,packetsLost,packetsMisordered,jitter,validityTime)

#define IRtpBufferedListenerFilterEventConsumer_SourceAttributes(This,ssrc,cname,name,email,phone,loc,tool,note)	\
    (This)->lpVtbl -> SourceAttributes(This,ssrc,cname,name,email,phone,loc,tool,note)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRtpBufferedListenerFilterEventConsumer_ActiveSourceAdded_Proxy( 
    IRtpBufferedListenerFilterEventConsumer * This,
    /* [in] */ UINT ssrc);


void __RPC_STUB IRtpBufferedListenerFilterEventConsumer_ActiveSourceAdded_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRtpBufferedListenerFilterEventConsumer_ActiveSourceRemoved_Proxy( 
    IRtpBufferedListenerFilterEventConsumer * This,
    /* [in] */ UINT ssrc);


void __RPC_STUB IRtpBufferedListenerFilterEventConsumer_ActiveSourceRemoved_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListenerFilterEventConsumer_SourceActiveValueChanged_Proxy( 
    IRtpBufferedListenerFilterEventConsumer * This,
    /* [in] */ UINT ssrc,
    /* [in] */ INT active);


void __RPC_STUB IRtpBufferedListenerFilterEventConsumer_SourceActiveValueChanged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListenerFilterEventConsumer_SourceMuteValueChanged_Proxy( 
    IRtpBufferedListenerFilterEventConsumer * This,
    /* [in] */ UINT ssrc,
    /* [in] */ INT muted);


void __RPC_STUB IRtpBufferedListenerFilterEventConsumer_SourceMuteValueChanged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListenerFilterEventConsumer_SourceEvent_Proxy( 
    IRtpBufferedListenerFilterEventConsumer * This,
    /* [in] */ UINT ssrc,
    /* [in] */ INT eventType);


void __RPC_STUB IRtpBufferedListenerFilterEventConsumer_SourceEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListenerFilterEventConsumer_SourceReception_Proxy( 
    IRtpBufferedListenerFilterEventConsumer * This,
    /* [in] */ UINT ssrc,
    /* [in] */ INT packetsRecvd,
    /* [in] */ INT packetsLost,
    /* [in] */ INT packetsMisordered,
    /* [in] */ INT jitter,
    /* [in] */ INT validityTime);


void __RPC_STUB IRtpBufferedListenerFilterEventConsumer_SourceReception_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListenerFilterEventConsumer_SourceAttributes_Proxy( 
    IRtpBufferedListenerFilterEventConsumer * This,
    /* [in] */ UINT ssrc,
    /* [in] */ LPWSTR cname,
    /* [in] */ LPWSTR name,
    /* [in] */ LPWSTR email,
    /* [in] */ LPWSTR phone,
    /* [in] */ LPWSTR loc,
    /* [in] */ LPWSTR tool,
    /* [in] */ LPWSTR note);


void __RPC_STUB IRtpBufferedListenerFilterEventConsumer_SourceAttributes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRtpBufferedListenerFilterEventConsumer_INTERFACE_DEFINED__ */


#ifndef __IRtpBufferedListenerFilterEventConsumerEx_INTERFACE_DEFINED__
#define __IRtpBufferedListenerFilterEventConsumerEx_INTERFACE_DEFINED__

/* interface IRtpBufferedListenerFilterEventConsumerEx */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRtpBufferedListenerFilterEventConsumerEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1ABEA165-797F-4A07-93AD-7DACBE477F48")
    IRtpBufferedListenerFilterEventConsumerEx : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IRtpBufferedListenerFilterEventConsumerExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRtpBufferedListenerFilterEventConsumerEx * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRtpBufferedListenerFilterEventConsumerEx * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRtpBufferedListenerFilterEventConsumerEx * This);
        
        END_INTERFACE
    } IRtpBufferedListenerFilterEventConsumerExVtbl;

    interface IRtpBufferedListenerFilterEventConsumerEx
    {
        CONST_VTBL struct IRtpBufferedListenerFilterEventConsumerExVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRtpBufferedListenerFilterEventConsumerEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRtpBufferedListenerFilterEventConsumerEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRtpBufferedListenerFilterEventConsumerEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRtpBufferedListenerFilterEventConsumerEx_INTERFACE_DEFINED__ */


#ifndef __IRtpListenerEventConsumer_INTERFACE_DEFINED__
#define __IRtpListenerEventConsumer_INTERFACE_DEFINED__

/* interface IRtpListenerEventConsumer */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRtpListenerEventConsumer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1ABEA162-797F-4A07-93AD-7DACBE477F48")
    IRtpListenerEventConsumer : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ActiveSourceAdded( 
            /* [in] */ UINT ssrc) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ActiveSourceRemoved( 
            /* [in] */ UINT ssrc) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ActiveSourceChanged( 
            /* [in] */ UINT ssrc,
            /* [in] */ INT eventType) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRtpListenerEventConsumerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRtpListenerEventConsumer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRtpListenerEventConsumer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRtpListenerEventConsumer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ActiveSourceAdded )( 
            IRtpListenerEventConsumer * This,
            /* [in] */ UINT ssrc);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ActiveSourceRemoved )( 
            IRtpListenerEventConsumer * This,
            /* [in] */ UINT ssrc);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ActiveSourceChanged )( 
            IRtpListenerEventConsumer * This,
            /* [in] */ UINT ssrc,
            /* [in] */ INT eventType);
        
        END_INTERFACE
    } IRtpListenerEventConsumerVtbl;

    interface IRtpListenerEventConsumer
    {
        CONST_VTBL struct IRtpListenerEventConsumerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRtpListenerEventConsumer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRtpListenerEventConsumer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRtpListenerEventConsumer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRtpListenerEventConsumer_ActiveSourceAdded(This,ssrc)	\
    (This)->lpVtbl -> ActiveSourceAdded(This,ssrc)

#define IRtpListenerEventConsumer_ActiveSourceRemoved(This,ssrc)	\
    (This)->lpVtbl -> ActiveSourceRemoved(This,ssrc)

#define IRtpListenerEventConsumer_ActiveSourceChanged(This,ssrc,eventType)	\
    (This)->lpVtbl -> ActiveSourceChanged(This,ssrc,eventType)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRtpListenerEventConsumer_ActiveSourceAdded_Proxy( 
    IRtpListenerEventConsumer * This,
    /* [in] */ UINT ssrc);


void __RPC_STUB IRtpListenerEventConsumer_ActiveSourceAdded_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRtpListenerEventConsumer_ActiveSourceRemoved_Proxy( 
    IRtpListenerEventConsumer * This,
    /* [in] */ UINT ssrc);


void __RPC_STUB IRtpListenerEventConsumer_ActiveSourceRemoved_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRtpListenerEventConsumer_ActiveSourceChanged_Proxy( 
    IRtpListenerEventConsumer * This,
    /* [in] */ UINT ssrc,
    /* [in] */ INT eventType);


void __RPC_STUB IRtpListenerEventConsumer_ActiveSourceChanged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRtpListenerEventConsumer_INTERFACE_DEFINED__ */


#ifndef __IRtpBufferedListenerEventConsumer_INTERFACE_DEFINED__
#define __IRtpBufferedListenerEventConsumer_INTERFACE_DEFINED__

/* interface IRtpBufferedListenerEventConsumer */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRtpBufferedListenerEventConsumer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1ABEA163-797F-4A07-93AD-7DACBE477F48")
    IRtpBufferedListenerEventConsumer : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IRtpBufferedListenerEventConsumerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRtpBufferedListenerEventConsumer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRtpBufferedListenerEventConsumer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRtpBufferedListenerEventConsumer * This);
        
        END_INTERFACE
    } IRtpBufferedListenerEventConsumerVtbl;

    interface IRtpBufferedListenerEventConsumer
    {
        CONST_VTBL struct IRtpBufferedListenerEventConsumerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRtpBufferedListenerEventConsumer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRtpBufferedListenerEventConsumer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRtpBufferedListenerEventConsumer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRtpBufferedListenerEventConsumer_INTERFACE_DEFINED__ */


#ifndef __IRtpRendererEventConsumer_INTERFACE_DEFINED__
#define __IRtpRendererEventConsumer_INTERFACE_DEFINED__

/* interface IRtpRendererEventConsumer */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRtpRendererEventConsumer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2ABEA162-797F-4A07-93AD-7DACBE477F48")
    IRtpRendererEventConsumer : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ReceiverReportReceived( 
            /* [in] */ UINT ssrcReportSource) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRtpRendererEventConsumerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRtpRendererEventConsumer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRtpRendererEventConsumer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRtpRendererEventConsumer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ReceiverReportReceived )( 
            IRtpRendererEventConsumer * This,
            /* [in] */ UINT ssrcReportSource);
        
        END_INTERFACE
    } IRtpRendererEventConsumerVtbl;

    interface IRtpRendererEventConsumer
    {
        CONST_VTBL struct IRtpRendererEventConsumerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRtpRendererEventConsumer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRtpRendererEventConsumer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRtpRendererEventConsumer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRtpRendererEventConsumer_ReceiverReportReceived(This,ssrcReportSource)	\
    (This)->lpVtbl -> ReceiverReportReceived(This,ssrcReportSource)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRtpRendererEventConsumer_ReceiverReportReceived_Proxy( 
    IRtpRendererEventConsumer * This,
    /* [in] */ UINT ssrcReportSource);


void __RPC_STUB IRtpRendererEventConsumer_ReceiverReportReceived_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRtpRendererEventConsumer_INTERFACE_DEFINED__ */


#ifndef __IRtpReceiverStatistics_INTERFACE_DEFINED__
#define __IRtpReceiverStatistics_INTERFACE_DEFINED__

/* interface IRtpReceiverStatistics */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRtpReceiverStatistics;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DC2F8E5E-17F2-4921-9804-F1EAFDD20843")
    IRtpReceiverStatistics : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetPacketLoss( 
            /* [in] */ UINT ssrc,
            /* [out] */ DOUBLE *pdblPacketLoss) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetReceptionStatistics( 
            /* [in] */ UINT ssrc,
            /* [out] */ UINT *pcPacketsReceived,
            /* [out] */ UINT *pcPacketsLost,
            /* [out] */ UINT *pJitter) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPerformanceCounterPrefix( 
            /* [in] */ UINT ssrc,
            /* [size_is][out][in] */ LPWSTR szPerfCounterPrefix,
            /* [in] */ INT cchPerfCounterPrefix) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRtpReceiverStatisticsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRtpReceiverStatistics * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRtpReceiverStatistics * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRtpReceiverStatistics * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetPacketLoss )( 
            IRtpReceiverStatistics * This,
            /* [in] */ UINT ssrc,
            /* [out] */ DOUBLE *pdblPacketLoss);
        
        HRESULT ( STDMETHODCALLTYPE *GetReceptionStatistics )( 
            IRtpReceiverStatistics * This,
            /* [in] */ UINT ssrc,
            /* [out] */ UINT *pcPacketsReceived,
            /* [out] */ UINT *pcPacketsLost,
            /* [out] */ UINT *pJitter);
        
        HRESULT ( STDMETHODCALLTYPE *GetPerformanceCounterPrefix )( 
            IRtpReceiverStatistics * This,
            /* [in] */ UINT ssrc,
            /* [size_is][out][in] */ LPWSTR szPerfCounterPrefix,
            /* [in] */ INT cchPerfCounterPrefix);
        
        END_INTERFACE
    } IRtpReceiverStatisticsVtbl;

    interface IRtpReceiverStatistics
    {
        CONST_VTBL struct IRtpReceiverStatisticsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRtpReceiverStatistics_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRtpReceiverStatistics_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRtpReceiverStatistics_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRtpReceiverStatistics_GetPacketLoss(This,ssrc,pdblPacketLoss)	\
    (This)->lpVtbl -> GetPacketLoss(This,ssrc,pdblPacketLoss)

#define IRtpReceiverStatistics_GetReceptionStatistics(This,ssrc,pcPacketsReceived,pcPacketsLost,pJitter)	\
    (This)->lpVtbl -> GetReceptionStatistics(This,ssrc,pcPacketsReceived,pcPacketsLost,pJitter)

#define IRtpReceiverStatistics_GetPerformanceCounterPrefix(This,ssrc,szPerfCounterPrefix,cchPerfCounterPrefix)	\
    (This)->lpVtbl -> GetPerformanceCounterPrefix(This,ssrc,szPerfCounterPrefix,cchPerfCounterPrefix)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRtpReceiverStatistics_GetPacketLoss_Proxy( 
    IRtpReceiverStatistics * This,
    /* [in] */ UINT ssrc,
    /* [out] */ DOUBLE *pdblPacketLoss);


void __RPC_STUB IRtpReceiverStatistics_GetPacketLoss_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpReceiverStatistics_GetReceptionStatistics_Proxy( 
    IRtpReceiverStatistics * This,
    /* [in] */ UINT ssrc,
    /* [out] */ UINT *pcPacketsReceived,
    /* [out] */ UINT *pcPacketsLost,
    /* [out] */ UINT *pJitter);


void __RPC_STUB IRtpReceiverStatistics_GetReceptionStatistics_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpReceiverStatistics_GetPerformanceCounterPrefix_Proxy( 
    IRtpReceiverStatistics * This,
    /* [in] */ UINT ssrc,
    /* [size_is][out][in] */ LPWSTR szPerfCounterPrefix,
    /* [in] */ INT cchPerfCounterPrefix);


void __RPC_STUB IRtpReceiverStatistics_GetPerformanceCounterPrefix_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRtpReceiverStatistics_INTERFACE_DEFINED__ */


#ifndef __IRtpSenderStatistics_INTERFACE_DEFINED__
#define __IRtpSenderStatistics_INTERFACE_DEFINED__

/* interface IRtpSenderStatistics */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRtpSenderStatistics;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DC2F8E5F-17F2-4921-9804-F1EAFDD20843")
    IRtpSenderStatistics : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetSenderStatistics( 
            /* [out] */ UINT *pcPacketsSent,
            /* [out] */ UINT *pcOctetsSent,
            /* [out] */ UINT *pMillisecs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStatisticsForReceiver( 
            /* [in] */ UINT ssrcRRSource,
            /* [out] */ BYTE *pFractionLost,
            /* [out] */ UINT *pcCumulativeNumberOfPacketsLost,
            /* [out] */ UINT *pInterarrivalJitter) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPerformanceCounterPrefix( 
            /* [in] */ UINT ssrc,
            /* [size_is][out][in] */ LPWSTR szPerfCounterPrefix,
            /* [in] */ INT cchPerfCounterPrefix) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRtpSenderStatisticsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRtpSenderStatistics * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRtpSenderStatistics * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRtpSenderStatistics * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetSenderStatistics )( 
            IRtpSenderStatistics * This,
            /* [out] */ UINT *pcPacketsSent,
            /* [out] */ UINT *pcOctetsSent,
            /* [out] */ UINT *pMillisecs);
        
        HRESULT ( STDMETHODCALLTYPE *GetStatisticsForReceiver )( 
            IRtpSenderStatistics * This,
            /* [in] */ UINT ssrcRRSource,
            /* [out] */ BYTE *pFractionLost,
            /* [out] */ UINT *pcCumulativeNumberOfPacketsLost,
            /* [out] */ UINT *pInterarrivalJitter);
        
        HRESULT ( STDMETHODCALLTYPE *GetPerformanceCounterPrefix )( 
            IRtpSenderStatistics * This,
            /* [in] */ UINT ssrc,
            /* [size_is][out][in] */ LPWSTR szPerfCounterPrefix,
            /* [in] */ INT cchPerfCounterPrefix);
        
        END_INTERFACE
    } IRtpSenderStatisticsVtbl;

    interface IRtpSenderStatistics
    {
        CONST_VTBL struct IRtpSenderStatisticsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRtpSenderStatistics_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRtpSenderStatistics_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRtpSenderStatistics_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRtpSenderStatistics_GetSenderStatistics(This,pcPacketsSent,pcOctetsSent,pMillisecs)	\
    (This)->lpVtbl -> GetSenderStatistics(This,pcPacketsSent,pcOctetsSent,pMillisecs)

#define IRtpSenderStatistics_GetStatisticsForReceiver(This,ssrcRRSource,pFractionLost,pcCumulativeNumberOfPacketsLost,pInterarrivalJitter)	\
    (This)->lpVtbl -> GetStatisticsForReceiver(This,ssrcRRSource,pFractionLost,pcCumulativeNumberOfPacketsLost,pInterarrivalJitter)

#define IRtpSenderStatistics_GetPerformanceCounterPrefix(This,ssrc,szPerfCounterPrefix,cchPerfCounterPrefix)	\
    (This)->lpVtbl -> GetPerformanceCounterPrefix(This,ssrc,szPerfCounterPrefix,cchPerfCounterPrefix)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRtpSenderStatistics_GetSenderStatistics_Proxy( 
    IRtpSenderStatistics * This,
    /* [out] */ UINT *pcPacketsSent,
    /* [out] */ UINT *pcOctetsSent,
    /* [out] */ UINT *pMillisecs);


void __RPC_STUB IRtpSenderStatistics_GetSenderStatistics_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpSenderStatistics_GetStatisticsForReceiver_Proxy( 
    IRtpSenderStatistics * This,
    /* [in] */ UINT ssrcRRSource,
    /* [out] */ BYTE *pFractionLost,
    /* [out] */ UINT *pcCumulativeNumberOfPacketsLost,
    /* [out] */ UINT *pInterarrivalJitter);


void __RPC_STUB IRtpSenderStatistics_GetStatisticsForReceiver_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpSenderStatistics_GetPerformanceCounterPrefix_Proxy( 
    IRtpSenderStatistics * This,
    /* [in] */ UINT ssrc,
    /* [size_is][out][in] */ LPWSTR szPerfCounterPrefix,
    /* [in] */ INT cchPerfCounterPrefix);


void __RPC_STUB IRtpSenderStatistics_GetPerformanceCounterPrefix_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRtpSenderStatistics_INTERFACE_DEFINED__ */


/* interface __MIDL_itf__Kite2ERtp2EAtl_0748 */
/* [local] */ 

struct SimpleInterfaceInfo
    {
    BSTR bstrInterfaceName;
    DWORD dwInterfaceIndex;
    DWORD dwMtu;
    DWORD dwType;
    } ;


extern RPC_IF_HANDLE __MIDL_itf__Kite2ERtp2EAtl_0748_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf__Kite2ERtp2EAtl_0748_v0_0_s_ifspec;

#ifndef __IInternetProtocolHelper_INTERFACE_DEFINED__
#define __IInternetProtocolHelper_INTERFACE_DEFINED__

/* interface IInternetProtocolHelper */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IInternetProtocolHelper;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("011B1D0D-BC47-46E7-9859-8F7016D96543")
    IInternetProtocolHelper : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE QueryMtuForInterface( 
            /* [in] */ UINT interfaceIndex,
            /* [retval][out] */ UINT *pMtu) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetAdapterInfoConcise( 
            /* [in] */ UINT interfaceIndex,
            /* [out][in] */ struct SimpleInterfaceInfo *pInterfaceInfo) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetAdapterInfoConciseForAllAdapters( 
            /* [out][in] */ struct SimpleInterfaceInfo *pInterfaceInfo,
            /* [out][in] */ UINT *pcAdapters) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE FindAdapterForAddress( 
            /* [in] */ BSTR bstrAddress,
            /* [out] */ UINT *pIndex) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInternetProtocolHelperVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInternetProtocolHelper * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInternetProtocolHelper * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInternetProtocolHelper * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *QueryMtuForInterface )( 
            IInternetProtocolHelper * This,
            /* [in] */ UINT interfaceIndex,
            /* [retval][out] */ UINT *pMtu);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetAdapterInfoConcise )( 
            IInternetProtocolHelper * This,
            /* [in] */ UINT interfaceIndex,
            /* [out][in] */ struct SimpleInterfaceInfo *pInterfaceInfo);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetAdapterInfoConciseForAllAdapters )( 
            IInternetProtocolHelper * This,
            /* [out][in] */ struct SimpleInterfaceInfo *pInterfaceInfo,
            /* [out][in] */ UINT *pcAdapters);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *FindAdapterForAddress )( 
            IInternetProtocolHelper * This,
            /* [in] */ BSTR bstrAddress,
            /* [out] */ UINT *pIndex);
        
        END_INTERFACE
    } IInternetProtocolHelperVtbl;

    interface IInternetProtocolHelper
    {
        CONST_VTBL struct IInternetProtocolHelperVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInternetProtocolHelper_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IInternetProtocolHelper_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IInternetProtocolHelper_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IInternetProtocolHelper_QueryMtuForInterface(This,interfaceIndex,pMtu)	\
    (This)->lpVtbl -> QueryMtuForInterface(This,interfaceIndex,pMtu)

#define IInternetProtocolHelper_GetAdapterInfoConcise(This,interfaceIndex,pInterfaceInfo)	\
    (This)->lpVtbl -> GetAdapterInfoConcise(This,interfaceIndex,pInterfaceInfo)

#define IInternetProtocolHelper_GetAdapterInfoConciseForAllAdapters(This,pInterfaceInfo,pcAdapters)	\
    (This)->lpVtbl -> GetAdapterInfoConciseForAllAdapters(This,pInterfaceInfo,pcAdapters)

#define IInternetProtocolHelper_FindAdapterForAddress(This,bstrAddress,pIndex)	\
    (This)->lpVtbl -> FindAdapterForAddress(This,bstrAddress,pIndex)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IInternetProtocolHelper_QueryMtuForInterface_Proxy( 
    IInternetProtocolHelper * This,
    /* [in] */ UINT interfaceIndex,
    /* [retval][out] */ UINT *pMtu);


void __RPC_STUB IInternetProtocolHelper_QueryMtuForInterface_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IInternetProtocolHelper_GetAdapterInfoConcise_Proxy( 
    IInternetProtocolHelper * This,
    /* [in] */ UINT interfaceIndex,
    /* [out][in] */ struct SimpleInterfaceInfo *pInterfaceInfo);


void __RPC_STUB IInternetProtocolHelper_GetAdapterInfoConcise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IInternetProtocolHelper_GetAdapterInfoConciseForAllAdapters_Proxy( 
    IInternetProtocolHelper * This,
    /* [out][in] */ struct SimpleInterfaceInfo *pInterfaceInfo,
    /* [out][in] */ UINT *pcAdapters);


void __RPC_STUB IInternetProtocolHelper_GetAdapterInfoConciseForAllAdapters_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IInternetProtocolHelper_FindAdapterForAddress_Proxy( 
    IInternetProtocolHelper * This,
    /* [in] */ BSTR bstrAddress,
    /* [out] */ UINT *pIndex);


void __RPC_STUB IInternetProtocolHelper_FindAdapterForAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IInternetProtocolHelper_INTERFACE_DEFINED__ */


/* interface __MIDL_itf__Kite2ERtp2EAtl_0749 */
/* [local] */ 

struct RtpSessionMemberInfo
    {
    UINT ssrc;
    UINT payloadType;
    UINT delaySinceLastPacketMillis;
    UINT interarrivalJitter;
    UINT packetsLost;
    UINT octetsLost;
    struct SdesItems *pSdesItems;
    } ;


extern RPC_IF_HANDLE __MIDL_itf__Kite2ERtp2EAtl_0749_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf__Kite2ERtp2EAtl_0749_v0_0_s_ifspec;

#ifndef __IRtpListenerConfiguration_INTERFACE_DEFINED__
#define __IRtpListenerConfiguration_INTERFACE_DEFINED__

/* interface IRtpListenerConfiguration */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IRtpListenerConfiguration;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C24FF91D-56E8-4bf7-8E4B-4B4409862FBB")
    IRtpListenerConfiguration : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetNetworkParameter( 
            /* [in] */ LPWSTR szRemoteAddress,
            /* [in] */ USHORT uRemotePort,
            /* [in] */ LPWSTR szLocalInterface,
            /* [in] */ USHORT uLocalPort,
            /* [in] */ INT ttl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMediaParameterDefaults( 
            /* [in] */ BOOL bAduSpansMultiplePackets,
            /* [in] */ BYTE payloadType,
            /* [in] */ UINT uRtpTimeStampIncrementPerSecond,
            /* [in] */ UINT uExpectedTimePerAduNanoseconds,
            /* [in] */ BOOL bUpdateExistingBuffers) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRtpBandwidth( 
            /* [in] */ UINT uSessionBandwidth,
            /* [in] */ BOOL bEnforce) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReserveNetworkAddressAndCreateSockets( 
            /* [in] */ LPWSTR szRemoteAddress,
            /* [out][in] */ LPWSTR szLocalInterface,
            /* [in] */ USHORT uMinLocalPort,
            /* [in] */ USHORT uMaxLocalPort,
            /* [in] */ INT ttl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReserveNetworkAddress( 
            /* [in] */ LPWSTR szRemoteAddress,
            /* [in] */ LPWSTR szLocalInterface,
            /* [in] */ USHORT uMinLocalPort,
            /* [in] */ USHORT uMaxLocalPort,
            /* [out][in] */ LPWSTR szLocalInterfaceOut,
            /* [in] */ INT cchLocal,
            /* [out] */ USHORT *puLocalPort) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_LocalSsrc( 
            /* [retval][out] */ UINT *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_LocalSsrc( 
            /* [in] */ UINT newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRtpListenerConfigurationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRtpListenerConfiguration * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRtpListenerConfiguration * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRtpListenerConfiguration * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetNetworkParameter )( 
            IRtpListenerConfiguration * This,
            /* [in] */ LPWSTR szRemoteAddress,
            /* [in] */ USHORT uRemotePort,
            /* [in] */ LPWSTR szLocalInterface,
            /* [in] */ USHORT uLocalPort,
            /* [in] */ INT ttl);
        
        HRESULT ( STDMETHODCALLTYPE *SetMediaParameterDefaults )( 
            IRtpListenerConfiguration * This,
            /* [in] */ BOOL bAduSpansMultiplePackets,
            /* [in] */ BYTE payloadType,
            /* [in] */ UINT uRtpTimeStampIncrementPerSecond,
            /* [in] */ UINT uExpectedTimePerAduNanoseconds,
            /* [in] */ BOOL bUpdateExistingBuffers);
        
        HRESULT ( STDMETHODCALLTYPE *SetRtpBandwidth )( 
            IRtpListenerConfiguration * This,
            /* [in] */ UINT uSessionBandwidth,
            /* [in] */ BOOL bEnforce);
        
        HRESULT ( STDMETHODCALLTYPE *ReserveNetworkAddressAndCreateSockets )( 
            IRtpListenerConfiguration * This,
            /* [in] */ LPWSTR szRemoteAddress,
            /* [out][in] */ LPWSTR szLocalInterface,
            /* [in] */ USHORT uMinLocalPort,
            /* [in] */ USHORT uMaxLocalPort,
            /* [in] */ INT ttl);
        
        HRESULT ( STDMETHODCALLTYPE *ReserveNetworkAddress )( 
            IRtpListenerConfiguration * This,
            /* [in] */ LPWSTR szRemoteAddress,
            /* [in] */ LPWSTR szLocalInterface,
            /* [in] */ USHORT uMinLocalPort,
            /* [in] */ USHORT uMaxLocalPort,
            /* [out][in] */ LPWSTR szLocalInterfaceOut,
            /* [in] */ INT cchLocal,
            /* [out] */ USHORT *puLocalPort);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LocalSsrc )( 
            IRtpListenerConfiguration * This,
            /* [retval][out] */ UINT *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LocalSsrc )( 
            IRtpListenerConfiguration * This,
            /* [in] */ UINT newVal);
        
        END_INTERFACE
    } IRtpListenerConfigurationVtbl;

    interface IRtpListenerConfiguration
    {
        CONST_VTBL struct IRtpListenerConfigurationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRtpListenerConfiguration_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRtpListenerConfiguration_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRtpListenerConfiguration_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRtpListenerConfiguration_SetNetworkParameter(This,szRemoteAddress,uRemotePort,szLocalInterface,uLocalPort,ttl)	\
    (This)->lpVtbl -> SetNetworkParameter(This,szRemoteAddress,uRemotePort,szLocalInterface,uLocalPort,ttl)

#define IRtpListenerConfiguration_SetMediaParameterDefaults(This,bAduSpansMultiplePackets,payloadType,uRtpTimeStampIncrementPerSecond,uExpectedTimePerAduNanoseconds,bUpdateExistingBuffers)	\
    (This)->lpVtbl -> SetMediaParameterDefaults(This,bAduSpansMultiplePackets,payloadType,uRtpTimeStampIncrementPerSecond,uExpectedTimePerAduNanoseconds,bUpdateExistingBuffers)

#define IRtpListenerConfiguration_SetRtpBandwidth(This,uSessionBandwidth,bEnforce)	\
    (This)->lpVtbl -> SetRtpBandwidth(This,uSessionBandwidth,bEnforce)

#define IRtpListenerConfiguration_ReserveNetworkAddressAndCreateSockets(This,szRemoteAddress,szLocalInterface,uMinLocalPort,uMaxLocalPort,ttl)	\
    (This)->lpVtbl -> ReserveNetworkAddressAndCreateSockets(This,szRemoteAddress,szLocalInterface,uMinLocalPort,uMaxLocalPort,ttl)

#define IRtpListenerConfiguration_ReserveNetworkAddress(This,szRemoteAddress,szLocalInterface,uMinLocalPort,uMaxLocalPort,szLocalInterfaceOut,cchLocal,puLocalPort)	\
    (This)->lpVtbl -> ReserveNetworkAddress(This,szRemoteAddress,szLocalInterface,uMinLocalPort,uMaxLocalPort,szLocalInterfaceOut,cchLocal,puLocalPort)

#define IRtpListenerConfiguration_get_LocalSsrc(This,pVal)	\
    (This)->lpVtbl -> get_LocalSsrc(This,pVal)

#define IRtpListenerConfiguration_put_LocalSsrc(This,newVal)	\
    (This)->lpVtbl -> put_LocalSsrc(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRtpListenerConfiguration_SetNetworkParameter_Proxy( 
    IRtpListenerConfiguration * This,
    /* [in] */ LPWSTR szRemoteAddress,
    /* [in] */ USHORT uRemotePort,
    /* [in] */ LPWSTR szLocalInterface,
    /* [in] */ USHORT uLocalPort,
    /* [in] */ INT ttl);


void __RPC_STUB IRtpListenerConfiguration_SetNetworkParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpListenerConfiguration_SetMediaParameterDefaults_Proxy( 
    IRtpListenerConfiguration * This,
    /* [in] */ BOOL bAduSpansMultiplePackets,
    /* [in] */ BYTE payloadType,
    /* [in] */ UINT uRtpTimeStampIncrementPerSecond,
    /* [in] */ UINT uExpectedTimePerAduNanoseconds,
    /* [in] */ BOOL bUpdateExistingBuffers);


void __RPC_STUB IRtpListenerConfiguration_SetMediaParameterDefaults_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpListenerConfiguration_SetRtpBandwidth_Proxy( 
    IRtpListenerConfiguration * This,
    /* [in] */ UINT uSessionBandwidth,
    /* [in] */ BOOL bEnforce);


void __RPC_STUB IRtpListenerConfiguration_SetRtpBandwidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpListenerConfiguration_ReserveNetworkAddressAndCreateSockets_Proxy( 
    IRtpListenerConfiguration * This,
    /* [in] */ LPWSTR szRemoteAddress,
    /* [out][in] */ LPWSTR szLocalInterface,
    /* [in] */ USHORT uMinLocalPort,
    /* [in] */ USHORT uMaxLocalPort,
    /* [in] */ INT ttl);


void __RPC_STUB IRtpListenerConfiguration_ReserveNetworkAddressAndCreateSockets_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpListenerConfiguration_ReserveNetworkAddress_Proxy( 
    IRtpListenerConfiguration * This,
    /* [in] */ LPWSTR szRemoteAddress,
    /* [in] */ LPWSTR szLocalInterface,
    /* [in] */ USHORT uMinLocalPort,
    /* [in] */ USHORT uMaxLocalPort,
    /* [out][in] */ LPWSTR szLocalInterfaceOut,
    /* [in] */ INT cchLocal,
    /* [out] */ USHORT *puLocalPort);


void __RPC_STUB IRtpListenerConfiguration_ReserveNetworkAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRtpListenerConfiguration_get_LocalSsrc_Proxy( 
    IRtpListenerConfiguration * This,
    /* [retval][out] */ UINT *pVal);


void __RPC_STUB IRtpListenerConfiguration_get_LocalSsrc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IRtpListenerConfiguration_put_LocalSsrc_Proxy( 
    IRtpListenerConfiguration * This,
    /* [in] */ UINT newVal);


void __RPC_STUB IRtpListenerConfiguration_put_LocalSsrc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRtpListenerConfiguration_INTERFACE_DEFINED__ */


#ifndef __IRtpListenerConfigurationOut_INTERFACE_DEFINED__
#define __IRtpListenerConfigurationOut_INTERFACE_DEFINED__

/* interface IRtpListenerConfigurationOut */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IRtpListenerConfigurationOut;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C24FF91C-56E8-4bf7-8E4B-4B4409862FBB")
    IRtpListenerConfigurationOut : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetNetworkParameter( 
            /* [out][in] */ LPWSTR szRemoteAddress,
            /* [in] */ INT cchRemoteAddress,
            /* [out] */ USHORT *puRemotePort,
            /* [out][in] */ LPWSTR szLocalInterface,
            /* [in] */ INT cchLocalAddress,
            /* [out] */ USHORT *puLocalPortBase,
            /* [out] */ INT *pTtl) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRtpListenerConfigurationOutVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRtpListenerConfigurationOut * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRtpListenerConfigurationOut * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRtpListenerConfigurationOut * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetNetworkParameter )( 
            IRtpListenerConfigurationOut * This,
            /* [out][in] */ LPWSTR szRemoteAddress,
            /* [in] */ INT cchRemoteAddress,
            /* [out] */ USHORT *puRemotePort,
            /* [out][in] */ LPWSTR szLocalInterface,
            /* [in] */ INT cchLocalAddress,
            /* [out] */ USHORT *puLocalPortBase,
            /* [out] */ INT *pTtl);
        
        END_INTERFACE
    } IRtpListenerConfigurationOutVtbl;

    interface IRtpListenerConfigurationOut
    {
        CONST_VTBL struct IRtpListenerConfigurationOutVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRtpListenerConfigurationOut_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRtpListenerConfigurationOut_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRtpListenerConfigurationOut_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRtpListenerConfigurationOut_GetNetworkParameter(This,szRemoteAddress,cchRemoteAddress,puRemotePort,szLocalInterface,cchLocalAddress,puLocalPortBase,pTtl)	\
    (This)->lpVtbl -> GetNetworkParameter(This,szRemoteAddress,cchRemoteAddress,puRemotePort,szLocalInterface,cchLocalAddress,puLocalPortBase,pTtl)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRtpListenerConfigurationOut_GetNetworkParameter_Proxy( 
    IRtpListenerConfigurationOut * This,
    /* [out][in] */ LPWSTR szRemoteAddress,
    /* [in] */ INT cchRemoteAddress,
    /* [out] */ USHORT *puRemotePort,
    /* [out][in] */ LPWSTR szLocalInterface,
    /* [in] */ INT cchLocalAddress,
    /* [out] */ USHORT *puLocalPortBase,
    /* [out] */ INT *pTtl);


void __RPC_STUB IRtpListenerConfigurationOut_GetNetworkParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRtpListenerConfigurationOut_INTERFACE_DEFINED__ */


#ifndef __IRtpListenerControl_INTERFACE_DEFINED__
#define __IRtpListenerControl_INTERFACE_DEFINED__

/* interface IRtpListenerControl */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IRtpListenerControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C24FF91E-56E8-4bf7-8E4B-4B4409862FBB")
    IRtpListenerControl : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Start( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Stop( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRtpListenerControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRtpListenerControl * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRtpListenerControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRtpListenerControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *Start )( 
            IRtpListenerControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IRtpListenerControl * This);
        
        END_INTERFACE
    } IRtpListenerControlVtbl;

    interface IRtpListenerControl
    {
        CONST_VTBL struct IRtpListenerControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRtpListenerControl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRtpListenerControl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRtpListenerControl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRtpListenerControl_Start(This)	\
    (This)->lpVtbl -> Start(This)

#define IRtpListenerControl_Stop(This)	\
    (This)->lpVtbl -> Stop(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRtpListenerControl_Start_Proxy( 
    IRtpListenerControl * This);


void __RPC_STUB IRtpListenerControl_Start_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpListenerControl_Stop_Proxy( 
    IRtpListenerControl * This);


void __RPC_STUB IRtpListenerControl_Stop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRtpListenerControl_INTERFACE_DEFINED__ */


#ifndef __IRtpListenerCallbackRegistration_INTERFACE_DEFINED__
#define __IRtpListenerCallbackRegistration_INTERFACE_DEFINED__

/* interface IRtpListenerCallbackRegistration */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IRtpListenerCallbackRegistration;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C24FF920-56E8-4bf7-8E4B-4B4409862FBB")
    IRtpListenerCallbackRegistration : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE RegisterCallback( 
            /* [in] */ IRtpListenerEventConsumer *pEventConsumer) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRtpListenerCallbackRegistrationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRtpListenerCallbackRegistration * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRtpListenerCallbackRegistration * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRtpListenerCallbackRegistration * This);
        
        HRESULT ( STDMETHODCALLTYPE *RegisterCallback )( 
            IRtpListenerCallbackRegistration * This,
            /* [in] */ IRtpListenerEventConsumer *pEventConsumer);
        
        END_INTERFACE
    } IRtpListenerCallbackRegistrationVtbl;

    interface IRtpListenerCallbackRegistration
    {
        CONST_VTBL struct IRtpListenerCallbackRegistrationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRtpListenerCallbackRegistration_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRtpListenerCallbackRegistration_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRtpListenerCallbackRegistration_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRtpListenerCallbackRegistration_RegisterCallback(This,pEventConsumer)	\
    (This)->lpVtbl -> RegisterCallback(This,pEventConsumer)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRtpListenerCallbackRegistration_RegisterCallback_Proxy( 
    IRtpListenerCallbackRegistration * This,
    /* [in] */ IRtpListenerEventConsumer *pEventConsumer);


void __RPC_STUB IRtpListenerCallbackRegistration_RegisterCallback_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRtpListenerCallbackRegistration_INTERFACE_DEFINED__ */


#ifndef __IRtpBufferedListener_INTERFACE_DEFINED__
#define __IRtpBufferedListener_INTERFACE_DEFINED__

/* interface IRtpBufferedListener */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IRtpBufferedListener;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C24FF921-56E8-4bf7-8E4B-4B4409862FBB")
    IRtpBufferedListener : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetPlayoutBufferGuid( 
            /* [in] */ LPGUID playoutBufferGuid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SubscribeSsrc( 
            /* [in] */ UINT ssrc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SubscribeSsrcAndGetPointerEx( 
            /* [in] */ UINT ssrc,
            /* [in] */ LPGUID guidJitterBuffer,
            /* [in] */ BYTE payloadType,
            /* [in] */ UINT uRtpTimeStampIncrementPerSecond,
            /* [in] */ UINT uExpectedTimePerAduNanoseconds,
            /* [out] */ IPlayoutBuffer **ppPlayoutBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnsubscribeSsrc( 
            /* [in] */ UINT ssrc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSubscribedSourcesCount( 
            /* [out][in] */ INT *pcSubscribed) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSubscribedSources( 
            /* [out][in] */ INT **pSubscribedSources,
            /* [out][in] */ INT *pcSubscribedSources) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetActiveSourcesCount( 
            /* [out][in] */ INT *pcActive) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetActiveSources( 
            /* [out][in] */ INT **pActiveSources,
            /* [out][in] */ INT *pcActiveSources) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMuted( 
            /* [in] */ UINT ssrc,
            /* [in] */ INT bMuted) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMuted( 
            /* [in] */ UINT ssrc,
            /* [in] */ INT *pbIsMuted) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetJitterBufferLatency( 
            /* [in] */ UINT ssrc,
            /* [in] */ UINT uLatency) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetJitterBufferLatency( 
            /* [in] */ UINT ssrc,
            /* [in] */ UINT *puLatency) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRtpBufferedListenerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRtpBufferedListener * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRtpBufferedListener * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRtpBufferedListener * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetPlayoutBufferGuid )( 
            IRtpBufferedListener * This,
            /* [in] */ LPGUID playoutBufferGuid);
        
        HRESULT ( STDMETHODCALLTYPE *SubscribeSsrc )( 
            IRtpBufferedListener * This,
            /* [in] */ UINT ssrc);
        
        HRESULT ( STDMETHODCALLTYPE *SubscribeSsrcAndGetPointerEx )( 
            IRtpBufferedListener * This,
            /* [in] */ UINT ssrc,
            /* [in] */ LPGUID guidJitterBuffer,
            /* [in] */ BYTE payloadType,
            /* [in] */ UINT uRtpTimeStampIncrementPerSecond,
            /* [in] */ UINT uExpectedTimePerAduNanoseconds,
            /* [out] */ IPlayoutBuffer **ppPlayoutBuffer);
        
        HRESULT ( STDMETHODCALLTYPE *UnsubscribeSsrc )( 
            IRtpBufferedListener * This,
            /* [in] */ UINT ssrc);
        
        HRESULT ( STDMETHODCALLTYPE *GetSubscribedSourcesCount )( 
            IRtpBufferedListener * This,
            /* [out][in] */ INT *pcSubscribed);
        
        HRESULT ( STDMETHODCALLTYPE *GetSubscribedSources )( 
            IRtpBufferedListener * This,
            /* [out][in] */ INT **pSubscribedSources,
            /* [out][in] */ INT *pcSubscribedSources);
        
        HRESULT ( STDMETHODCALLTYPE *GetActiveSourcesCount )( 
            IRtpBufferedListener * This,
            /* [out][in] */ INT *pcActive);
        
        HRESULT ( STDMETHODCALLTYPE *GetActiveSources )( 
            IRtpBufferedListener * This,
            /* [out][in] */ INT **pActiveSources,
            /* [out][in] */ INT *pcActiveSources);
        
        HRESULT ( STDMETHODCALLTYPE *SetMuted )( 
            IRtpBufferedListener * This,
            /* [in] */ UINT ssrc,
            /* [in] */ INT bMuted);
        
        HRESULT ( STDMETHODCALLTYPE *GetMuted )( 
            IRtpBufferedListener * This,
            /* [in] */ UINT ssrc,
            /* [in] */ INT *pbIsMuted);
        
        HRESULT ( STDMETHODCALLTYPE *SetJitterBufferLatency )( 
            IRtpBufferedListener * This,
            /* [in] */ UINT ssrc,
            /* [in] */ UINT uLatency);
        
        HRESULT ( STDMETHODCALLTYPE *GetJitterBufferLatency )( 
            IRtpBufferedListener * This,
            /* [in] */ UINT ssrc,
            /* [in] */ UINT *puLatency);
        
        END_INTERFACE
    } IRtpBufferedListenerVtbl;

    interface IRtpBufferedListener
    {
        CONST_VTBL struct IRtpBufferedListenerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRtpBufferedListener_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRtpBufferedListener_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRtpBufferedListener_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRtpBufferedListener_SetPlayoutBufferGuid(This,playoutBufferGuid)	\
    (This)->lpVtbl -> SetPlayoutBufferGuid(This,playoutBufferGuid)

#define IRtpBufferedListener_SubscribeSsrc(This,ssrc)	\
    (This)->lpVtbl -> SubscribeSsrc(This,ssrc)

#define IRtpBufferedListener_SubscribeSsrcAndGetPointerEx(This,ssrc,guidJitterBuffer,payloadType,uRtpTimeStampIncrementPerSecond,uExpectedTimePerAduNanoseconds,ppPlayoutBuffer)	\
    (This)->lpVtbl -> SubscribeSsrcAndGetPointerEx(This,ssrc,guidJitterBuffer,payloadType,uRtpTimeStampIncrementPerSecond,uExpectedTimePerAduNanoseconds,ppPlayoutBuffer)

#define IRtpBufferedListener_UnsubscribeSsrc(This,ssrc)	\
    (This)->lpVtbl -> UnsubscribeSsrc(This,ssrc)

#define IRtpBufferedListener_GetSubscribedSourcesCount(This,pcSubscribed)	\
    (This)->lpVtbl -> GetSubscribedSourcesCount(This,pcSubscribed)

#define IRtpBufferedListener_GetSubscribedSources(This,pSubscribedSources,pcSubscribedSources)	\
    (This)->lpVtbl -> GetSubscribedSources(This,pSubscribedSources,pcSubscribedSources)

#define IRtpBufferedListener_GetActiveSourcesCount(This,pcActive)	\
    (This)->lpVtbl -> GetActiveSourcesCount(This,pcActive)

#define IRtpBufferedListener_GetActiveSources(This,pActiveSources,pcActiveSources)	\
    (This)->lpVtbl -> GetActiveSources(This,pActiveSources,pcActiveSources)

#define IRtpBufferedListener_SetMuted(This,ssrc,bMuted)	\
    (This)->lpVtbl -> SetMuted(This,ssrc,bMuted)

#define IRtpBufferedListener_GetMuted(This,ssrc,pbIsMuted)	\
    (This)->lpVtbl -> GetMuted(This,ssrc,pbIsMuted)

#define IRtpBufferedListener_SetJitterBufferLatency(This,ssrc,uLatency)	\
    (This)->lpVtbl -> SetJitterBufferLatency(This,ssrc,uLatency)

#define IRtpBufferedListener_GetJitterBufferLatency(This,ssrc,puLatency)	\
    (This)->lpVtbl -> GetJitterBufferLatency(This,ssrc,puLatency)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRtpBufferedListener_SetPlayoutBufferGuid_Proxy( 
    IRtpBufferedListener * This,
    /* [in] */ LPGUID playoutBufferGuid);


void __RPC_STUB IRtpBufferedListener_SetPlayoutBufferGuid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListener_SubscribeSsrc_Proxy( 
    IRtpBufferedListener * This,
    /* [in] */ UINT ssrc);


void __RPC_STUB IRtpBufferedListener_SubscribeSsrc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListener_SubscribeSsrcAndGetPointerEx_Proxy( 
    IRtpBufferedListener * This,
    /* [in] */ UINT ssrc,
    /* [in] */ LPGUID guidJitterBuffer,
    /* [in] */ BYTE payloadType,
    /* [in] */ UINT uRtpTimeStampIncrementPerSecond,
    /* [in] */ UINT uExpectedTimePerAduNanoseconds,
    /* [out] */ IPlayoutBuffer **ppPlayoutBuffer);


void __RPC_STUB IRtpBufferedListener_SubscribeSsrcAndGetPointerEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListener_UnsubscribeSsrc_Proxy( 
    IRtpBufferedListener * This,
    /* [in] */ UINT ssrc);


void __RPC_STUB IRtpBufferedListener_UnsubscribeSsrc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListener_GetSubscribedSourcesCount_Proxy( 
    IRtpBufferedListener * This,
    /* [out][in] */ INT *pcSubscribed);


void __RPC_STUB IRtpBufferedListener_GetSubscribedSourcesCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListener_GetSubscribedSources_Proxy( 
    IRtpBufferedListener * This,
    /* [out][in] */ INT **pSubscribedSources,
    /* [out][in] */ INT *pcSubscribedSources);


void __RPC_STUB IRtpBufferedListener_GetSubscribedSources_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListener_GetActiveSourcesCount_Proxy( 
    IRtpBufferedListener * This,
    /* [out][in] */ INT *pcActive);


void __RPC_STUB IRtpBufferedListener_GetActiveSourcesCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListener_GetActiveSources_Proxy( 
    IRtpBufferedListener * This,
    /* [out][in] */ INT **pActiveSources,
    /* [out][in] */ INT *pcActiveSources);


void __RPC_STUB IRtpBufferedListener_GetActiveSources_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListener_SetMuted_Proxy( 
    IRtpBufferedListener * This,
    /* [in] */ UINT ssrc,
    /* [in] */ INT bMuted);


void __RPC_STUB IRtpBufferedListener_SetMuted_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListener_GetMuted_Proxy( 
    IRtpBufferedListener * This,
    /* [in] */ UINT ssrc,
    /* [in] */ INT *pbIsMuted);


void __RPC_STUB IRtpBufferedListener_GetMuted_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListener_SetJitterBufferLatency_Proxy( 
    IRtpBufferedListener * This,
    /* [in] */ UINT ssrc,
    /* [in] */ UINT uLatency);


void __RPC_STUB IRtpBufferedListener_SetJitterBufferLatency_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListener_GetJitterBufferLatency_Proxy( 
    IRtpBufferedListener * This,
    /* [in] */ UINT ssrc,
    /* [in] */ UINT *puLatency);


void __RPC_STUB IRtpBufferedListener_GetJitterBufferLatency_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRtpBufferedListener_INTERFACE_DEFINED__ */


#ifndef __IRtpBufferedListenerData_INTERFACE_DEFINED__
#define __IRtpBufferedListenerData_INTERFACE_DEFINED__

/* interface IRtpBufferedListenerData */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IRtpBufferedListenerData;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C24FF922-56E8-4bf7-8E4B-4B4409862FBB")
    IRtpBufferedListenerData : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDeliveryUnit( 
            /* [in] */ UINT ssrc,
            /* [out][in] */ struct RtpParsedPacket ***pppDeliveryUnit,
            /* [out][in] */ UINT *pcPackets) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRtpBufferedListenerDataVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRtpBufferedListenerData * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRtpBufferedListenerData * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRtpBufferedListenerData * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeliveryUnit )( 
            IRtpBufferedListenerData * This,
            /* [in] */ UINT ssrc,
            /* [out][in] */ struct RtpParsedPacket ***pppDeliveryUnit,
            /* [out][in] */ UINT *pcPackets);
        
        END_INTERFACE
    } IRtpBufferedListenerDataVtbl;

    interface IRtpBufferedListenerData
    {
        CONST_VTBL struct IRtpBufferedListenerDataVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRtpBufferedListenerData_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRtpBufferedListenerData_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRtpBufferedListenerData_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRtpBufferedListenerData_GetDeliveryUnit(This,ssrc,pppDeliveryUnit,pcPackets)	\
    (This)->lpVtbl -> GetDeliveryUnit(This,ssrc,pppDeliveryUnit,pcPackets)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRtpBufferedListenerData_GetDeliveryUnit_Proxy( 
    IRtpBufferedListenerData * This,
    /* [in] */ UINT ssrc,
    /* [out][in] */ struct RtpParsedPacket ***pppDeliveryUnit,
    /* [out][in] */ UINT *pcPackets);


void __RPC_STUB IRtpBufferedListenerData_GetDeliveryUnit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRtpBufferedListenerData_INTERFACE_DEFINED__ */


#ifndef __IRtpListener_INTERFACE_DEFINED__
#define __IRtpListener_INTERFACE_DEFINED__

/* interface IRtpListener */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IRtpListener;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C24FF923-56E8-4bf7-8E4B-4B4409862FBB")
    IRtpListener : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetRtcpAttributes( 
            /* [in] */ UINT ssrc,
            /* [out][in] */ struct SdesItems *pSdesItems) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSessionMemberInfo( 
            /* [in] */ UINT ssrc,
            /* [out][in] */ struct RtpSessionMemberInfo *pSessionMemberInfo,
            /* [in] */ BOOL bIncludeSdesItems) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRtpListenerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRtpListener * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRtpListener * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRtpListener * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetRtcpAttributes )( 
            IRtpListener * This,
            /* [in] */ UINT ssrc,
            /* [out][in] */ struct SdesItems *pSdesItems);
        
        HRESULT ( STDMETHODCALLTYPE *GetSessionMemberInfo )( 
            IRtpListener * This,
            /* [in] */ UINT ssrc,
            /* [out][in] */ struct RtpSessionMemberInfo *pSessionMemberInfo,
            /* [in] */ BOOL bIncludeSdesItems);
        
        END_INTERFACE
    } IRtpListenerVtbl;

    interface IRtpListener
    {
        CONST_VTBL struct IRtpListenerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRtpListener_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRtpListener_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRtpListener_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRtpListener_GetRtcpAttributes(This,ssrc,pSdesItems)	\
    (This)->lpVtbl -> GetRtcpAttributes(This,ssrc,pSdesItems)

#define IRtpListener_GetSessionMemberInfo(This,ssrc,pSessionMemberInfo,bIncludeSdesItems)	\
    (This)->lpVtbl -> GetSessionMemberInfo(This,ssrc,pSessionMemberInfo,bIncludeSdesItems)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRtpListener_GetRtcpAttributes_Proxy( 
    IRtpListener * This,
    /* [in] */ UINT ssrc,
    /* [out][in] */ struct SdesItems *pSdesItems);


void __RPC_STUB IRtpListener_GetRtcpAttributes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpListener_GetSessionMemberInfo_Proxy( 
    IRtpListener * This,
    /* [in] */ UINT ssrc,
    /* [out][in] */ struct RtpSessionMemberInfo *pSessionMemberInfo,
    /* [in] */ BOOL bIncludeSdesItems);


void __RPC_STUB IRtpListener_GetSessionMemberInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRtpListener_INTERFACE_DEFINED__ */


/* interface __MIDL_itf__Kite2ERtp2EAtl_0756 */
/* [local] */ 

struct MyRegPinTypes
    {
    GUID clsMajorType;
    GUID clsMinorType;
    } ;


extern RPC_IF_HANDLE __MIDL_itf__Kite2ERtp2EAtl_0756_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf__Kite2ERtp2EAtl_0756_v0_0_s_ifspec;

#ifndef __IRtpPayloadPacketizer_INTERFACE_DEFINED__
#define __IRtpPayloadPacketizer_INTERFACE_DEFINED__

/* interface IRtpPayloadPacketizer */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRtpPayloadPacketizer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("66AA121D-17DD-469B-9D25-C7F7250CDD99")
    IRtpPayloadPacketizer : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_MaxBufferSize( 
            /* [retval][out] */ UINT *pcbMtu) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_MaxBufferSize( 
            /* [in] */ UINT cbMtu) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_GuidCount( 
            /* [retval][out] */ UINT *pcGuids) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGuids( 
            /* [out][in] */ struct MyRegPinTypes *pRegPinTypes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Packetize( 
            /* [in] */ BYTE *pBuffer,
            /* [in] */ UINT cbBuffer,
            /* [out] */ BYTE ***ppBuffer,
            /* [out] */ UINT **ppcbBuffers,
            /* [out] */ UINT *pcBuffers) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Depacketize( 
            /* [in] */ BYTE **pBuffers,
            /* [in] */ UINT *pcbBuffers,
            /* [in] */ UINT *pSeqNums,
            /* [in] */ UINT cBuffers,
            /* [out][in] */ BYTE *pBuffer,
            /* [out][in] */ UINT *pcbBuffer,
            /* [out] */ UINT *pcbSkipped) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRtpPayloadPacketizerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRtpPayloadPacketizer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRtpPayloadPacketizer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRtpPayloadPacketizer * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxBufferSize )( 
            IRtpPayloadPacketizer * This,
            /* [retval][out] */ UINT *pcbMtu);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaxBufferSize )( 
            IRtpPayloadPacketizer * This,
            /* [in] */ UINT cbMtu);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_GuidCount )( 
            IRtpPayloadPacketizer * This,
            /* [retval][out] */ UINT *pcGuids);
        
        HRESULT ( STDMETHODCALLTYPE *GetGuids )( 
            IRtpPayloadPacketizer * This,
            /* [out][in] */ struct MyRegPinTypes *pRegPinTypes);
        
        HRESULT ( STDMETHODCALLTYPE *Packetize )( 
            IRtpPayloadPacketizer * This,
            /* [in] */ BYTE *pBuffer,
            /* [in] */ UINT cbBuffer,
            /* [out] */ BYTE ***ppBuffer,
            /* [out] */ UINT **ppcbBuffers,
            /* [out] */ UINT *pcBuffers);
        
        HRESULT ( STDMETHODCALLTYPE *Depacketize )( 
            IRtpPayloadPacketizer * This,
            /* [in] */ BYTE **pBuffers,
            /* [in] */ UINT *pcbBuffers,
            /* [in] */ UINT *pSeqNums,
            /* [in] */ UINT cBuffers,
            /* [out][in] */ BYTE *pBuffer,
            /* [out][in] */ UINT *pcbBuffer,
            /* [out] */ UINT *pcbSkipped);
        
        END_INTERFACE
    } IRtpPayloadPacketizerVtbl;

    interface IRtpPayloadPacketizer
    {
        CONST_VTBL struct IRtpPayloadPacketizerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRtpPayloadPacketizer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRtpPayloadPacketizer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRtpPayloadPacketizer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRtpPayloadPacketizer_get_MaxBufferSize(This,pcbMtu)	\
    (This)->lpVtbl -> get_MaxBufferSize(This,pcbMtu)

#define IRtpPayloadPacketizer_put_MaxBufferSize(This,cbMtu)	\
    (This)->lpVtbl -> put_MaxBufferSize(This,cbMtu)

#define IRtpPayloadPacketizer_get_GuidCount(This,pcGuids)	\
    (This)->lpVtbl -> get_GuidCount(This,pcGuids)

#define IRtpPayloadPacketizer_GetGuids(This,pRegPinTypes)	\
    (This)->lpVtbl -> GetGuids(This,pRegPinTypes)

#define IRtpPayloadPacketizer_Packetize(This,pBuffer,cbBuffer,ppBuffer,ppcbBuffers,pcBuffers)	\
    (This)->lpVtbl -> Packetize(This,pBuffer,cbBuffer,ppBuffer,ppcbBuffers,pcBuffers)

#define IRtpPayloadPacketizer_Depacketize(This,pBuffers,pcbBuffers,pSeqNums,cBuffers,pBuffer,pcbBuffer,pcbSkipped)	\
    (This)->lpVtbl -> Depacketize(This,pBuffers,pcbBuffers,pSeqNums,cBuffers,pBuffer,pcbBuffer,pcbSkipped)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget] */ HRESULT STDMETHODCALLTYPE IRtpPayloadPacketizer_get_MaxBufferSize_Proxy( 
    IRtpPayloadPacketizer * This,
    /* [retval][out] */ UINT *pcbMtu);


void __RPC_STUB IRtpPayloadPacketizer_get_MaxBufferSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IRtpPayloadPacketizer_put_MaxBufferSize_Proxy( 
    IRtpPayloadPacketizer * This,
    /* [in] */ UINT cbMtu);


void __RPC_STUB IRtpPayloadPacketizer_put_MaxBufferSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IRtpPayloadPacketizer_get_GuidCount_Proxy( 
    IRtpPayloadPacketizer * This,
    /* [retval][out] */ UINT *pcGuids);


void __RPC_STUB IRtpPayloadPacketizer_get_GuidCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpPayloadPacketizer_GetGuids_Proxy( 
    IRtpPayloadPacketizer * This,
    /* [out][in] */ struct MyRegPinTypes *pRegPinTypes);


void __RPC_STUB IRtpPayloadPacketizer_GetGuids_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpPayloadPacketizer_Packetize_Proxy( 
    IRtpPayloadPacketizer * This,
    /* [in] */ BYTE *pBuffer,
    /* [in] */ UINT cbBuffer,
    /* [out] */ BYTE ***ppBuffer,
    /* [out] */ UINT **ppcbBuffers,
    /* [out] */ UINT *pcBuffers);


void __RPC_STUB IRtpPayloadPacketizer_Packetize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpPayloadPacketizer_Depacketize_Proxy( 
    IRtpPayloadPacketizer * This,
    /* [in] */ BYTE **pBuffers,
    /* [in] */ UINT *pcbBuffers,
    /* [in] */ UINT *pSeqNums,
    /* [in] */ UINT cBuffers,
    /* [out][in] */ BYTE *pBuffer,
    /* [out][in] */ UINT *pcbBuffer,
    /* [out] */ UINT *pcbSkipped);


void __RPC_STUB IRtpPayloadPacketizer_Depacketize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRtpPayloadPacketizer_INTERFACE_DEFINED__ */


#ifndef __IRtpRendererConfiguration_INTERFACE_DEFINED__
#define __IRtpRendererConfiguration_INTERFACE_DEFINED__

/* interface IRtpRendererConfiguration */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IRtpRendererConfiguration;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DA2B5441-D7AE-45c4-AE59-8620361525DC")
    IRtpRendererConfiguration : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetNetworkParameter( 
            /* [in] */ LPWSTR szRemoteAddress,
            /* [in] */ USHORT uRemotePort,
            /* [in] */ LPWSTR szLocalInterface,
            /* [in] */ USHORT uLocalPort,
            /* [in] */ INT ttl,
            /* [in] */ LPWSTR szCname) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReserveNetworkAddressAndCreateSockets( 
            /* [in] */ LPWSTR szRemoteAddress,
            /* [out][in] */ LPWSTR szLocalInterface,
            /* [in] */ USHORT uMinLocalPort,
            /* [in] */ USHORT uMaxLocalPort,
            /* [in] */ INT ttl,
            /* [in] */ LPWSTR cname) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReserveNetworkAddress( 
            /* [in] */ LPWSTR szRemoteAddress,
            /* [in] */ LPWSTR szLocalInterface,
            /* [in] */ USHORT uMinLocalPort,
            /* [in] */ USHORT uMaxLocalPort,
            /* [out][in] */ LPWSTR szLocalInterfaceOut,
            /* [in] */ INT cchLocal,
            /* [out] */ USHORT *puLocalPort) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPayloadType( 
            /* [in] */ BYTE payloadType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRtpBandwidth( 
            /* [in] */ UINT uSessionBandwidth,
            /* [in] */ BOOL bEnforce) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRtcpParameter( 
            /* [in] */ LPWSTR szName,
            /* [in] */ LPWSTR szEMail,
            /* [in] */ LPWSTR szPhone,
            /* [in] */ LPWSTR szLoc,
            /* [in] */ LPWSTR szTool,
            /* [in] */ LPWSTR szNote) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_LocalSsrc( 
            /* [retval][out] */ UINT *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_LocalSsrc( 
            /* [in] */ UINT newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRtpRendererConfigurationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRtpRendererConfiguration * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRtpRendererConfiguration * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRtpRendererConfiguration * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetNetworkParameter )( 
            IRtpRendererConfiguration * This,
            /* [in] */ LPWSTR szRemoteAddress,
            /* [in] */ USHORT uRemotePort,
            /* [in] */ LPWSTR szLocalInterface,
            /* [in] */ USHORT uLocalPort,
            /* [in] */ INT ttl,
            /* [in] */ LPWSTR szCname);
        
        HRESULT ( STDMETHODCALLTYPE *ReserveNetworkAddressAndCreateSockets )( 
            IRtpRendererConfiguration * This,
            /* [in] */ LPWSTR szRemoteAddress,
            /* [out][in] */ LPWSTR szLocalInterface,
            /* [in] */ USHORT uMinLocalPort,
            /* [in] */ USHORT uMaxLocalPort,
            /* [in] */ INT ttl,
            /* [in] */ LPWSTR cname);
        
        HRESULT ( STDMETHODCALLTYPE *ReserveNetworkAddress )( 
            IRtpRendererConfiguration * This,
            /* [in] */ LPWSTR szRemoteAddress,
            /* [in] */ LPWSTR szLocalInterface,
            /* [in] */ USHORT uMinLocalPort,
            /* [in] */ USHORT uMaxLocalPort,
            /* [out][in] */ LPWSTR szLocalInterfaceOut,
            /* [in] */ INT cchLocal,
            /* [out] */ USHORT *puLocalPort);
        
        HRESULT ( STDMETHODCALLTYPE *SetPayloadType )( 
            IRtpRendererConfiguration * This,
            /* [in] */ BYTE payloadType);
        
        HRESULT ( STDMETHODCALLTYPE *SetRtpBandwidth )( 
            IRtpRendererConfiguration * This,
            /* [in] */ UINT uSessionBandwidth,
            /* [in] */ BOOL bEnforce);
        
        HRESULT ( STDMETHODCALLTYPE *SetRtcpParameter )( 
            IRtpRendererConfiguration * This,
            /* [in] */ LPWSTR szName,
            /* [in] */ LPWSTR szEMail,
            /* [in] */ LPWSTR szPhone,
            /* [in] */ LPWSTR szLoc,
            /* [in] */ LPWSTR szTool,
            /* [in] */ LPWSTR szNote);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LocalSsrc )( 
            IRtpRendererConfiguration * This,
            /* [retval][out] */ UINT *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LocalSsrc )( 
            IRtpRendererConfiguration * This,
            /* [in] */ UINT newVal);
        
        END_INTERFACE
    } IRtpRendererConfigurationVtbl;

    interface IRtpRendererConfiguration
    {
        CONST_VTBL struct IRtpRendererConfigurationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRtpRendererConfiguration_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRtpRendererConfiguration_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRtpRendererConfiguration_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRtpRendererConfiguration_SetNetworkParameter(This,szRemoteAddress,uRemotePort,szLocalInterface,uLocalPort,ttl,szCname)	\
    (This)->lpVtbl -> SetNetworkParameter(This,szRemoteAddress,uRemotePort,szLocalInterface,uLocalPort,ttl,szCname)

#define IRtpRendererConfiguration_ReserveNetworkAddressAndCreateSockets(This,szRemoteAddress,szLocalInterface,uMinLocalPort,uMaxLocalPort,ttl,cname)	\
    (This)->lpVtbl -> ReserveNetworkAddressAndCreateSockets(This,szRemoteAddress,szLocalInterface,uMinLocalPort,uMaxLocalPort,ttl,cname)

#define IRtpRendererConfiguration_ReserveNetworkAddress(This,szRemoteAddress,szLocalInterface,uMinLocalPort,uMaxLocalPort,szLocalInterfaceOut,cchLocal,puLocalPort)	\
    (This)->lpVtbl -> ReserveNetworkAddress(This,szRemoteAddress,szLocalInterface,uMinLocalPort,uMaxLocalPort,szLocalInterfaceOut,cchLocal,puLocalPort)

#define IRtpRendererConfiguration_SetPayloadType(This,payloadType)	\
    (This)->lpVtbl -> SetPayloadType(This,payloadType)

#define IRtpRendererConfiguration_SetRtpBandwidth(This,uSessionBandwidth,bEnforce)	\
    (This)->lpVtbl -> SetRtpBandwidth(This,uSessionBandwidth,bEnforce)

#define IRtpRendererConfiguration_SetRtcpParameter(This,szName,szEMail,szPhone,szLoc,szTool,szNote)	\
    (This)->lpVtbl -> SetRtcpParameter(This,szName,szEMail,szPhone,szLoc,szTool,szNote)

#define IRtpRendererConfiguration_get_LocalSsrc(This,pVal)	\
    (This)->lpVtbl -> get_LocalSsrc(This,pVal)

#define IRtpRendererConfiguration_put_LocalSsrc(This,newVal)	\
    (This)->lpVtbl -> put_LocalSsrc(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRtpRendererConfiguration_SetNetworkParameter_Proxy( 
    IRtpRendererConfiguration * This,
    /* [in] */ LPWSTR szRemoteAddress,
    /* [in] */ USHORT uRemotePort,
    /* [in] */ LPWSTR szLocalInterface,
    /* [in] */ USHORT uLocalPort,
    /* [in] */ INT ttl,
    /* [in] */ LPWSTR szCname);


void __RPC_STUB IRtpRendererConfiguration_SetNetworkParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpRendererConfiguration_ReserveNetworkAddressAndCreateSockets_Proxy( 
    IRtpRendererConfiguration * This,
    /* [in] */ LPWSTR szRemoteAddress,
    /* [out][in] */ LPWSTR szLocalInterface,
    /* [in] */ USHORT uMinLocalPort,
    /* [in] */ USHORT uMaxLocalPort,
    /* [in] */ INT ttl,
    /* [in] */ LPWSTR cname);


void __RPC_STUB IRtpRendererConfiguration_ReserveNetworkAddressAndCreateSockets_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpRendererConfiguration_ReserveNetworkAddress_Proxy( 
    IRtpRendererConfiguration * This,
    /* [in] */ LPWSTR szRemoteAddress,
    /* [in] */ LPWSTR szLocalInterface,
    /* [in] */ USHORT uMinLocalPort,
    /* [in] */ USHORT uMaxLocalPort,
    /* [out][in] */ LPWSTR szLocalInterfaceOut,
    /* [in] */ INT cchLocal,
    /* [out] */ USHORT *puLocalPort);


void __RPC_STUB IRtpRendererConfiguration_ReserveNetworkAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpRendererConfiguration_SetPayloadType_Proxy( 
    IRtpRendererConfiguration * This,
    /* [in] */ BYTE payloadType);


void __RPC_STUB IRtpRendererConfiguration_SetPayloadType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpRendererConfiguration_SetRtpBandwidth_Proxy( 
    IRtpRendererConfiguration * This,
    /* [in] */ UINT uSessionBandwidth,
    /* [in] */ BOOL bEnforce);


void __RPC_STUB IRtpRendererConfiguration_SetRtpBandwidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpRendererConfiguration_SetRtcpParameter_Proxy( 
    IRtpRendererConfiguration * This,
    /* [in] */ LPWSTR szName,
    /* [in] */ LPWSTR szEMail,
    /* [in] */ LPWSTR szPhone,
    /* [in] */ LPWSTR szLoc,
    /* [in] */ LPWSTR szTool,
    /* [in] */ LPWSTR szNote);


void __RPC_STUB IRtpRendererConfiguration_SetRtcpParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IRtpRendererConfiguration_get_LocalSsrc_Proxy( 
    IRtpRendererConfiguration * This,
    /* [retval][out] */ UINT *pVal);


void __RPC_STUB IRtpRendererConfiguration_get_LocalSsrc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IRtpRendererConfiguration_put_LocalSsrc_Proxy( 
    IRtpRendererConfiguration * This,
    /* [in] */ UINT newVal);


void __RPC_STUB IRtpRendererConfiguration_put_LocalSsrc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRtpRendererConfiguration_INTERFACE_DEFINED__ */


#ifndef __IRtpRendererConfigurationOut_INTERFACE_DEFINED__
#define __IRtpRendererConfigurationOut_INTERFACE_DEFINED__

/* interface IRtpRendererConfigurationOut */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IRtpRendererConfigurationOut;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DA2B5442-D7AE-45c4-AE59-8620361525DC")
    IRtpRendererConfigurationOut : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetNetworkParameter( 
            /* [out][in] */ LPWSTR szRemoteAddress,
            /* [in] */ INT cchRemoteAddress,
            /* [out] */ USHORT *puRemotePort,
            /* [out][in] */ LPWSTR szLocalInterface,
            /* [in] */ INT cchLocalAddress,
            /* [out] */ USHORT *puLocalPortBase,
            /* [out] */ INT *pTtl) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRtpRendererConfigurationOutVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRtpRendererConfigurationOut * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRtpRendererConfigurationOut * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRtpRendererConfigurationOut * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetNetworkParameter )( 
            IRtpRendererConfigurationOut * This,
            /* [out][in] */ LPWSTR szRemoteAddress,
            /* [in] */ INT cchRemoteAddress,
            /* [out] */ USHORT *puRemotePort,
            /* [out][in] */ LPWSTR szLocalInterface,
            /* [in] */ INT cchLocalAddress,
            /* [out] */ USHORT *puLocalPortBase,
            /* [out] */ INT *pTtl);
        
        END_INTERFACE
    } IRtpRendererConfigurationOutVtbl;

    interface IRtpRendererConfigurationOut
    {
        CONST_VTBL struct IRtpRendererConfigurationOutVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRtpRendererConfigurationOut_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRtpRendererConfigurationOut_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRtpRendererConfigurationOut_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRtpRendererConfigurationOut_GetNetworkParameter(This,szRemoteAddress,cchRemoteAddress,puRemotePort,szLocalInterface,cchLocalAddress,puLocalPortBase,pTtl)	\
    (This)->lpVtbl -> GetNetworkParameter(This,szRemoteAddress,cchRemoteAddress,puRemotePort,szLocalInterface,cchLocalAddress,puLocalPortBase,pTtl)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRtpRendererConfigurationOut_GetNetworkParameter_Proxy( 
    IRtpRendererConfigurationOut * This,
    /* [out][in] */ LPWSTR szRemoteAddress,
    /* [in] */ INT cchRemoteAddress,
    /* [out] */ USHORT *puRemotePort,
    /* [out][in] */ LPWSTR szLocalInterface,
    /* [in] */ INT cchLocalAddress,
    /* [out] */ USHORT *puLocalPortBase,
    /* [out] */ INT *pTtl);


void __RPC_STUB IRtpRendererConfigurationOut_GetNetworkParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRtpRendererConfigurationOut_INTERFACE_DEFINED__ */


#ifndef __IRtpRendererControl_INTERFACE_DEFINED__
#define __IRtpRendererControl_INTERFACE_DEFINED__

/* interface IRtpRendererControl */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IRtpRendererControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DA2B5443-D7AE-45c4-AE59-8620361525DC")
    IRtpRendererControl : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Start( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Stop( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRtpRendererControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRtpRendererControl * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRtpRendererControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRtpRendererControl * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Start )( 
            IRtpRendererControl * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IRtpRendererControl * This);
        
        END_INTERFACE
    } IRtpRendererControlVtbl;

    interface IRtpRendererControl
    {
        CONST_VTBL struct IRtpRendererControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRtpRendererControl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRtpRendererControl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRtpRendererControl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRtpRendererControl_Start(This)	\
    (This)->lpVtbl -> Start(This)

#define IRtpRendererControl_Stop(This)	\
    (This)->lpVtbl -> Stop(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRtpRendererControl_Start_Proxy( 
    IRtpRendererControl * This);


void __RPC_STUB IRtpRendererControl_Start_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRtpRendererControl_Stop_Proxy( 
    IRtpRendererControl * This);


void __RPC_STUB IRtpRendererControl_Stop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRtpRendererControl_INTERFACE_DEFINED__ */


#ifndef __IRtpRenderer_INTERFACE_DEFINED__
#define __IRtpRenderer_INTERFACE_DEFINED__

/* interface IRtpRenderer */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRtpRenderer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("23AAF37A-90F4-48E9-B816-9EEAFE4912A8")
    IRtpRenderer : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SendRtpPacket( 
            /* [in] */ BYTE *pBuffer,
            /* [in] */ UINT cbBuffer,
            /* [in] */ BOOL bMarker,
            /* [in] */ UINT timestamp) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SendRtpPayloadData( 
            /* [in] */ BOOL bMarker,
            /* [in] */ UINT timestamp,
            /* [in] */ BYTE *pProperlyPacketizedData,
            /* [in] */ UINT cbProperlyPacketizedData) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRtpRendererVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRtpRenderer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRtpRenderer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRtpRenderer * This);
        
        HRESULT ( STDMETHODCALLTYPE *SendRtpPacket )( 
            IRtpRenderer * This,
            /* [in] */ BYTE *pBuffer,
            /* [in] */ UINT cbBuffer,
            /* [in] */ BOOL bMarker,
            /* [in] */ UINT timestamp);
        
        HRESULT ( STDMETHODCALLTYPE *SendRtpPayloadData )( 
            IRtpRenderer * This,
            /* [in] */ BOOL bMarker,
            /* [in] */ UINT timestamp,
            /* [in] */ BYTE *pProperlyPacketizedData,
            /* [in] */ UINT cbProperlyPacketizedData);
        
        END_INTERFACE
    } IRtpRendererVtbl;

    interface IRtpRenderer
    {
        CONST_VTBL struct IRtpRendererVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRtpRenderer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRtpRenderer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRtpRenderer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRtpRenderer_SendRtpPacket(This,pBuffer,cbBuffer,bMarker,timestamp)	\
    (This)->lpVtbl -> SendRtpPacket(This,pBuffer,cbBuffer,bMarker,timestamp)

#define IRtpRenderer_SendRtpPayloadData(This,bMarker,timestamp,pProperlyPacketizedData,cbProperlyPacketizedData)	\
    (This)->lpVtbl -> SendRtpPayloadData(This,bMarker,timestamp,pProperlyPacketizedData,cbProperlyPacketizedData)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRtpRenderer_SendRtpPacket_Proxy( 
    IRtpRenderer * This,
    /* [in] */ BYTE *pBuffer,
    /* [in] */ UINT cbBuffer,
    /* [in] */ BOOL bMarker,
    /* [in] */ UINT timestamp);


void __RPC_STUB IRtpRenderer_SendRtpPacket_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpRenderer_SendRtpPayloadData_Proxy( 
    IRtpRenderer * This,
    /* [in] */ BOOL bMarker,
    /* [in] */ UINT timestamp,
    /* [in] */ BYTE *pProperlyPacketizedData,
    /* [in] */ UINT cbProperlyPacketizedData);


void __RPC_STUB IRtpRenderer_SendRtpPayloadData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRtpRenderer_INTERFACE_DEFINED__ */


#ifndef __IRtpRendererFilterConfiguration_Export_INTERFACE_DEFINED__
#define __IRtpRendererFilterConfiguration_Export_INTERFACE_DEFINED__

/* interface IRtpRendererFilterConfiguration_Export */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IRtpRendererFilterConfiguration_Export;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DA2B5440-D7AE-45c4-AE59-8620361525DC")
    IRtpRendererFilterConfiguration_Export : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetRtpRenderer( 
            /* [in] */ IRtpRenderer *pRenderer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetProtocolMediaParameter( 
            /* [in] */ UINT avgTimePerFrame,
            /* [in] */ UINT rtpTsIncPerFrame) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRtpPayloadPacketizer( 
            /* [in] */ IRtpPayloadPacketizer *pPacketizer) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRtpRendererFilterConfiguration_ExportVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRtpRendererFilterConfiguration_Export * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRtpRendererFilterConfiguration_Export * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRtpRendererFilterConfiguration_Export * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetRtpRenderer )( 
            IRtpRendererFilterConfiguration_Export * This,
            /* [in] */ IRtpRenderer *pRenderer);
        
        HRESULT ( STDMETHODCALLTYPE *SetProtocolMediaParameter )( 
            IRtpRendererFilterConfiguration_Export * This,
            /* [in] */ UINT avgTimePerFrame,
            /* [in] */ UINT rtpTsIncPerFrame);
        
        HRESULT ( STDMETHODCALLTYPE *SetRtpPayloadPacketizer )( 
            IRtpRendererFilterConfiguration_Export * This,
            /* [in] */ IRtpPayloadPacketizer *pPacketizer);
        
        END_INTERFACE
    } IRtpRendererFilterConfiguration_ExportVtbl;

    interface IRtpRendererFilterConfiguration_Export
    {
        CONST_VTBL struct IRtpRendererFilterConfiguration_ExportVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRtpRendererFilterConfiguration_Export_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRtpRendererFilterConfiguration_Export_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRtpRendererFilterConfiguration_Export_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRtpRendererFilterConfiguration_Export_SetRtpRenderer(This,pRenderer)	\
    (This)->lpVtbl -> SetRtpRenderer(This,pRenderer)

#define IRtpRendererFilterConfiguration_Export_SetProtocolMediaParameter(This,avgTimePerFrame,rtpTsIncPerFrame)	\
    (This)->lpVtbl -> SetProtocolMediaParameter(This,avgTimePerFrame,rtpTsIncPerFrame)

#define IRtpRendererFilterConfiguration_Export_SetRtpPayloadPacketizer(This,pPacketizer)	\
    (This)->lpVtbl -> SetRtpPayloadPacketizer(This,pPacketizer)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRtpRendererFilterConfiguration_Export_SetRtpRenderer_Proxy( 
    IRtpRendererFilterConfiguration_Export * This,
    /* [in] */ IRtpRenderer *pRenderer);


void __RPC_STUB IRtpRendererFilterConfiguration_Export_SetRtpRenderer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpRendererFilterConfiguration_Export_SetProtocolMediaParameter_Proxy( 
    IRtpRendererFilterConfiguration_Export * This,
    /* [in] */ UINT avgTimePerFrame,
    /* [in] */ UINT rtpTsIncPerFrame);


void __RPC_STUB IRtpRendererFilterConfiguration_Export_SetProtocolMediaParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpRendererFilterConfiguration_Export_SetRtpPayloadPacketizer_Proxy( 
    IRtpRendererFilterConfiguration_Export * This,
    /* [in] */ IRtpPayloadPacketizer *pPacketizer);


void __RPC_STUB IRtpRendererFilterConfiguration_Export_SetRtpPayloadPacketizer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRtpRendererFilterConfiguration_Export_INTERFACE_DEFINED__ */


/* interface __MIDL_itf__Kite2ERtp2EAtl_0762 */
/* [local] */ 

typedef struct _AMMediaType
    {
    GUID majortype;
    GUID subtype;
    BOOL bFixedSizeSamples;
    BOOL bTemporalCompression;
    ULONG lSampleSize;
    GUID formattype;
    IUnknown *pUnk;
    ULONG cbFormat;
    BYTE *pbFormat;
    } 	AM_MEDIA_TYPE;



extern RPC_IF_HANDLE __MIDL_itf__Kite2ERtp2EAtl_0762_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf__Kite2ERtp2EAtl_0762_v0_0_s_ifspec;

#ifndef __IRtpListenerOutputPin_Export_INTERFACE_DEFINED__
#define __IRtpListenerOutputPin_Export_INTERFACE_DEFINED__

/* interface IRtpListenerOutputPin_Export */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IRtpListenerOutputPin_Export;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D32EA7FB-59D2-4a6b-ACCF-E70A323004A3")
    IRtpListenerOutputPin_Export : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetBufferPrefix( 
            /* [in] */ INT *pcbPrefix) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRtpListenerOutputPin_ExportVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRtpListenerOutputPin_Export * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRtpListenerOutputPin_Export * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRtpListenerOutputPin_Export * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetBufferPrefix )( 
            IRtpListenerOutputPin_Export * This,
            /* [in] */ INT *pcbPrefix);
        
        END_INTERFACE
    } IRtpListenerOutputPin_ExportVtbl;

    interface IRtpListenerOutputPin_Export
    {
        CONST_VTBL struct IRtpListenerOutputPin_ExportVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRtpListenerOutputPin_Export_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRtpListenerOutputPin_Export_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRtpListenerOutputPin_Export_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRtpListenerOutputPin_Export_GetBufferPrefix(This,pcbPrefix)	\
    (This)->lpVtbl -> GetBufferPrefix(This,pcbPrefix)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRtpListenerOutputPin_Export_GetBufferPrefix_Proxy( 
    IRtpListenerOutputPin_Export * This,
    /* [in] */ INT *pcbPrefix);


void __RPC_STUB IRtpListenerOutputPin_Export_GetBufferPrefix_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRtpListenerOutputPin_Export_INTERFACE_DEFINED__ */


#ifndef __IRtpBufferedListenerFilter_Export_INTERFACE_DEFINED__
#define __IRtpBufferedListenerFilter_Export_INTERFACE_DEFINED__

/* interface IRtpBufferedListenerFilter_Export */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IRtpBufferedListenerFilter_Export;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D32EA7F5-59D2-4a6b-ACCF-E70A323004A3")
    IRtpBufferedListenerFilter_Export : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetNetworkParameter( 
            /* [in] */ LPWSTR szRemoteAddress,
            /* [in] */ USHORT uRemotePort,
            /* [in] */ LPWSTR szLocalInterface,
            /* [in] */ USHORT uLocalInterface,
            /* [in] */ INT ttl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMediaParameterDefaults( 
            /* [in] */ BOOL bAduSpansMultiplePackets,
            /* [in] */ BYTE payloadType,
            /* [in] */ UINT uRtpTimeStampIncrementPerSecond,
            /* [in] */ UINT uExpectedTimePerAduNanoseconds) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetOutputMediaType( 
            /* [in] */ AM_MEDIA_TYPE *pMediaType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRtpBandwidth( 
            /* [in] */ UINT uSessionBandwidth,
            /* [in] */ BOOL bEnforce) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetJitterBufferParameter( 
            /* [in] */ UINT ssrc,
            /* [in] */ UINT uLatency) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SelectActiveSourceForOutputPin( 
            /* [in] */ UINT index,
            /* [in] */ UINT ssrc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddOutputPin( 
            /* [in] */ INT *pIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddOutputPinForActiveSource( 
            /* [in] */ UINT ssrc,
            /* [in] */ INT *pIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveOutputPin( 
            /* [in] */ UINT index) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RegisterEventHandler( 
            /* [in] */ IRtpBufferedListenerFilterEventConsumer *pEventConsumer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RegisterEventHandlerEx( 
            /* [in] */ IRtpBufferedListenerFilterEventConsumerEx *pEventConsumerEx) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSubscribedSourcesCount( 
            /* [in] */ INT *pcSubscribed) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSubscribedSources( 
            /* [in] */ INT **pSubscribedSources,
            /* [in] */ INT *pcSubscribedSources) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetActiveSourcesCount( 
            /* [in] */ INT *pcActive) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetActiveSources( 
            /* [in] */ INT **pActiveSources,
            /* [in] */ INT *pcActiveSources) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAutoSubscribeActiveSources( 
            /* [in] */ BOOL bValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAutoSubscribeActiveSources( 
            /* [in] */ BOOL *pbValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRtpPayloadPacketizer( 
            /* [in] */ IRtpPayloadPacketizer *pPacketizer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReserveNetworkAddress( 
            /* [in] */ LPWSTR szRemoteAddress,
            /* [in] */ LPWSTR szLocalAddress,
            /* [in] */ USHORT uLocalMinPort,
            /* [in] */ USHORT uLocalMaxPort,
            /* [in] */ LPWSTR szLocalOut,
            /* [in] */ INT cchLocal,
            /* [in] */ USHORT *puLocal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNetworkParameter( 
            /* [in] */ LPWSTR szRemoteAddress,
            /* [in] */ INT cchRemoteAddress,
            /* [in] */ USHORT *puRemotePort,
            /* [in] */ LPWSTR szLocalInterface,
            /* [in] */ INT cchLocalAddress,
            /* [in] */ USHORT *puLocalPortBase,
            /* [in] */ INT *pTtl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetJitterBufferLatency( 
            /* [in] */ UINT ssrc,
            /* [in] */ UINT uLatency) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetJitterBufferLatency( 
            /* [in] */ UINT ssrc,
            /* [in] */ UINT *puLatency) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRtcpAttributes( 
            /* [in] */ UINT ssrc,
            /* [in] */ struct SdesItems *pSdesItems) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMuted( 
            /* [in] */ UINT ssrc,
            /* [in] */ INT bMuted) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMuted( 
            /* [in] */ UINT ssrc,
            /* [in] */ INT *pbIsMuted) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPinCount( 
            /* [in] */ INT pinCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPinCount( 
            /* [in] */ INT *pPinCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPinIndexForSource( 
            /* [in] */ UINT ssrc,
            /* [in] */ INT *pIndex) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRtpBufferedListenerFilter_ExportVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRtpBufferedListenerFilter_Export * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRtpBufferedListenerFilter_Export * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRtpBufferedListenerFilter_Export * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetNetworkParameter )( 
            IRtpBufferedListenerFilter_Export * This,
            /* [in] */ LPWSTR szRemoteAddress,
            /* [in] */ USHORT uRemotePort,
            /* [in] */ LPWSTR szLocalInterface,
            /* [in] */ USHORT uLocalInterface,
            /* [in] */ INT ttl);
        
        HRESULT ( STDMETHODCALLTYPE *SetMediaParameterDefaults )( 
            IRtpBufferedListenerFilter_Export * This,
            /* [in] */ BOOL bAduSpansMultiplePackets,
            /* [in] */ BYTE payloadType,
            /* [in] */ UINT uRtpTimeStampIncrementPerSecond,
            /* [in] */ UINT uExpectedTimePerAduNanoseconds);
        
        HRESULT ( STDMETHODCALLTYPE *SetOutputMediaType )( 
            IRtpBufferedListenerFilter_Export * This,
            /* [in] */ AM_MEDIA_TYPE *pMediaType);
        
        HRESULT ( STDMETHODCALLTYPE *SetRtpBandwidth )( 
            IRtpBufferedListenerFilter_Export * This,
            /* [in] */ UINT uSessionBandwidth,
            /* [in] */ BOOL bEnforce);
        
        HRESULT ( STDMETHODCALLTYPE *SetJitterBufferParameter )( 
            IRtpBufferedListenerFilter_Export * This,
            /* [in] */ UINT ssrc,
            /* [in] */ UINT uLatency);
        
        HRESULT ( STDMETHODCALLTYPE *SelectActiveSourceForOutputPin )( 
            IRtpBufferedListenerFilter_Export * This,
            /* [in] */ UINT index,
            /* [in] */ UINT ssrc);
        
        HRESULT ( STDMETHODCALLTYPE *AddOutputPin )( 
            IRtpBufferedListenerFilter_Export * This,
            /* [in] */ INT *pIndex);
        
        HRESULT ( STDMETHODCALLTYPE *AddOutputPinForActiveSource )( 
            IRtpBufferedListenerFilter_Export * This,
            /* [in] */ UINT ssrc,
            /* [in] */ INT *pIndex);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveOutputPin )( 
            IRtpBufferedListenerFilter_Export * This,
            /* [in] */ UINT index);
        
        HRESULT ( STDMETHODCALLTYPE *RegisterEventHandler )( 
            IRtpBufferedListenerFilter_Export * This,
            /* [in] */ IRtpBufferedListenerFilterEventConsumer *pEventConsumer);
        
        HRESULT ( STDMETHODCALLTYPE *RegisterEventHandlerEx )( 
            IRtpBufferedListenerFilter_Export * This,
            /* [in] */ IRtpBufferedListenerFilterEventConsumerEx *pEventConsumerEx);
        
        HRESULT ( STDMETHODCALLTYPE *GetSubscribedSourcesCount )( 
            IRtpBufferedListenerFilter_Export * This,
            /* [in] */ INT *pcSubscribed);
        
        HRESULT ( STDMETHODCALLTYPE *GetSubscribedSources )( 
            IRtpBufferedListenerFilter_Export * This,
            /* [in] */ INT **pSubscribedSources,
            /* [in] */ INT *pcSubscribedSources);
        
        HRESULT ( STDMETHODCALLTYPE *GetActiveSourcesCount )( 
            IRtpBufferedListenerFilter_Export * This,
            /* [in] */ INT *pcActive);
        
        HRESULT ( STDMETHODCALLTYPE *GetActiveSources )( 
            IRtpBufferedListenerFilter_Export * This,
            /* [in] */ INT **pActiveSources,
            /* [in] */ INT *pcActiveSources);
        
        HRESULT ( STDMETHODCALLTYPE *SetAutoSubscribeActiveSources )( 
            IRtpBufferedListenerFilter_Export * This,
            /* [in] */ BOOL bValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetAutoSubscribeActiveSources )( 
            IRtpBufferedListenerFilter_Export * This,
            /* [in] */ BOOL *pbValue);
        
        HRESULT ( STDMETHODCALLTYPE *SetRtpPayloadPacketizer )( 
            IRtpBufferedListenerFilter_Export * This,
            /* [in] */ IRtpPayloadPacketizer *pPacketizer);
        
        HRESULT ( STDMETHODCALLTYPE *ReserveNetworkAddress )( 
            IRtpBufferedListenerFilter_Export * This,
            /* [in] */ LPWSTR szRemoteAddress,
            /* [in] */ LPWSTR szLocalAddress,
            /* [in] */ USHORT uLocalMinPort,
            /* [in] */ USHORT uLocalMaxPort,
            /* [in] */ LPWSTR szLocalOut,
            /* [in] */ INT cchLocal,
            /* [in] */ USHORT *puLocal);
        
        HRESULT ( STDMETHODCALLTYPE *GetNetworkParameter )( 
            IRtpBufferedListenerFilter_Export * This,
            /* [in] */ LPWSTR szRemoteAddress,
            /* [in] */ INT cchRemoteAddress,
            /* [in] */ USHORT *puRemotePort,
            /* [in] */ LPWSTR szLocalInterface,
            /* [in] */ INT cchLocalAddress,
            /* [in] */ USHORT *puLocalPortBase,
            /* [in] */ INT *pTtl);
        
        HRESULT ( STDMETHODCALLTYPE *SetJitterBufferLatency )( 
            IRtpBufferedListenerFilter_Export * This,
            /* [in] */ UINT ssrc,
            /* [in] */ UINT uLatency);
        
        HRESULT ( STDMETHODCALLTYPE *GetJitterBufferLatency )( 
            IRtpBufferedListenerFilter_Export * This,
            /* [in] */ UINT ssrc,
            /* [in] */ UINT *puLatency);
        
        HRESULT ( STDMETHODCALLTYPE *GetRtcpAttributes )( 
            IRtpBufferedListenerFilter_Export * This,
            /* [in] */ UINT ssrc,
            /* [in] */ struct SdesItems *pSdesItems);
        
        HRESULT ( STDMETHODCALLTYPE *SetMuted )( 
            IRtpBufferedListenerFilter_Export * This,
            /* [in] */ UINT ssrc,
            /* [in] */ INT bMuted);
        
        HRESULT ( STDMETHODCALLTYPE *GetMuted )( 
            IRtpBufferedListenerFilter_Export * This,
            /* [in] */ UINT ssrc,
            /* [in] */ INT *pbIsMuted);
        
        HRESULT ( STDMETHODCALLTYPE *SetPinCount )( 
            IRtpBufferedListenerFilter_Export * This,
            /* [in] */ INT pinCount);
        
        HRESULT ( STDMETHODCALLTYPE *GetPinCount )( 
            IRtpBufferedListenerFilter_Export * This,
            /* [in] */ INT *pPinCount);
        
        HRESULT ( STDMETHODCALLTYPE *GetPinIndexForSource )( 
            IRtpBufferedListenerFilter_Export * This,
            /* [in] */ UINT ssrc,
            /* [in] */ INT *pIndex);
        
        END_INTERFACE
    } IRtpBufferedListenerFilter_ExportVtbl;

    interface IRtpBufferedListenerFilter_Export
    {
        CONST_VTBL struct IRtpBufferedListenerFilter_ExportVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRtpBufferedListenerFilter_Export_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRtpBufferedListenerFilter_Export_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRtpBufferedListenerFilter_Export_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRtpBufferedListenerFilter_Export_SetNetworkParameter(This,szRemoteAddress,uRemotePort,szLocalInterface,uLocalInterface,ttl)	\
    (This)->lpVtbl -> SetNetworkParameter(This,szRemoteAddress,uRemotePort,szLocalInterface,uLocalInterface,ttl)

#define IRtpBufferedListenerFilter_Export_SetMediaParameterDefaults(This,bAduSpansMultiplePackets,payloadType,uRtpTimeStampIncrementPerSecond,uExpectedTimePerAduNanoseconds)	\
    (This)->lpVtbl -> SetMediaParameterDefaults(This,bAduSpansMultiplePackets,payloadType,uRtpTimeStampIncrementPerSecond,uExpectedTimePerAduNanoseconds)

#define IRtpBufferedListenerFilter_Export_SetOutputMediaType(This,pMediaType)	\
    (This)->lpVtbl -> SetOutputMediaType(This,pMediaType)

#define IRtpBufferedListenerFilter_Export_SetRtpBandwidth(This,uSessionBandwidth,bEnforce)	\
    (This)->lpVtbl -> SetRtpBandwidth(This,uSessionBandwidth,bEnforce)

#define IRtpBufferedListenerFilter_Export_SetJitterBufferParameter(This,ssrc,uLatency)	\
    (This)->lpVtbl -> SetJitterBufferParameter(This,ssrc,uLatency)

#define IRtpBufferedListenerFilter_Export_SelectActiveSourceForOutputPin(This,index,ssrc)	\
    (This)->lpVtbl -> SelectActiveSourceForOutputPin(This,index,ssrc)

#define IRtpBufferedListenerFilter_Export_AddOutputPin(This,pIndex)	\
    (This)->lpVtbl -> AddOutputPin(This,pIndex)

#define IRtpBufferedListenerFilter_Export_AddOutputPinForActiveSource(This,ssrc,pIndex)	\
    (This)->lpVtbl -> AddOutputPinForActiveSource(This,ssrc,pIndex)

#define IRtpBufferedListenerFilter_Export_RemoveOutputPin(This,index)	\
    (This)->lpVtbl -> RemoveOutputPin(This,index)

#define IRtpBufferedListenerFilter_Export_RegisterEventHandler(This,pEventConsumer)	\
    (This)->lpVtbl -> RegisterEventHandler(This,pEventConsumer)

#define IRtpBufferedListenerFilter_Export_RegisterEventHandlerEx(This,pEventConsumerEx)	\
    (This)->lpVtbl -> RegisterEventHandlerEx(This,pEventConsumerEx)

#define IRtpBufferedListenerFilter_Export_GetSubscribedSourcesCount(This,pcSubscribed)	\
    (This)->lpVtbl -> GetSubscribedSourcesCount(This,pcSubscribed)

#define IRtpBufferedListenerFilter_Export_GetSubscribedSources(This,pSubscribedSources,pcSubscribedSources)	\
    (This)->lpVtbl -> GetSubscribedSources(This,pSubscribedSources,pcSubscribedSources)

#define IRtpBufferedListenerFilter_Export_GetActiveSourcesCount(This,pcActive)	\
    (This)->lpVtbl -> GetActiveSourcesCount(This,pcActive)

#define IRtpBufferedListenerFilter_Export_GetActiveSources(This,pActiveSources,pcActiveSources)	\
    (This)->lpVtbl -> GetActiveSources(This,pActiveSources,pcActiveSources)

#define IRtpBufferedListenerFilter_Export_SetAutoSubscribeActiveSources(This,bValue)	\
    (This)->lpVtbl -> SetAutoSubscribeActiveSources(This,bValue)

#define IRtpBufferedListenerFilter_Export_GetAutoSubscribeActiveSources(This,pbValue)	\
    (This)->lpVtbl -> GetAutoSubscribeActiveSources(This,pbValue)

#define IRtpBufferedListenerFilter_Export_SetRtpPayloadPacketizer(This,pPacketizer)	\
    (This)->lpVtbl -> SetRtpPayloadPacketizer(This,pPacketizer)

#define IRtpBufferedListenerFilter_Export_ReserveNetworkAddress(This,szRemoteAddress,szLocalAddress,uLocalMinPort,uLocalMaxPort,szLocalOut,cchLocal,puLocal)	\
    (This)->lpVtbl -> ReserveNetworkAddress(This,szRemoteAddress,szLocalAddress,uLocalMinPort,uLocalMaxPort,szLocalOut,cchLocal,puLocal)

#define IRtpBufferedListenerFilter_Export_GetNetworkParameter(This,szRemoteAddress,cchRemoteAddress,puRemotePort,szLocalInterface,cchLocalAddress,puLocalPortBase,pTtl)	\
    (This)->lpVtbl -> GetNetworkParameter(This,szRemoteAddress,cchRemoteAddress,puRemotePort,szLocalInterface,cchLocalAddress,puLocalPortBase,pTtl)

#define IRtpBufferedListenerFilter_Export_SetJitterBufferLatency(This,ssrc,uLatency)	\
    (This)->lpVtbl -> SetJitterBufferLatency(This,ssrc,uLatency)

#define IRtpBufferedListenerFilter_Export_GetJitterBufferLatency(This,ssrc,puLatency)	\
    (This)->lpVtbl -> GetJitterBufferLatency(This,ssrc,puLatency)

#define IRtpBufferedListenerFilter_Export_GetRtcpAttributes(This,ssrc,pSdesItems)	\
    (This)->lpVtbl -> GetRtcpAttributes(This,ssrc,pSdesItems)

#define IRtpBufferedListenerFilter_Export_SetMuted(This,ssrc,bMuted)	\
    (This)->lpVtbl -> SetMuted(This,ssrc,bMuted)

#define IRtpBufferedListenerFilter_Export_GetMuted(This,ssrc,pbIsMuted)	\
    (This)->lpVtbl -> GetMuted(This,ssrc,pbIsMuted)

#define IRtpBufferedListenerFilter_Export_SetPinCount(This,pinCount)	\
    (This)->lpVtbl -> SetPinCount(This,pinCount)

#define IRtpBufferedListenerFilter_Export_GetPinCount(This,pPinCount)	\
    (This)->lpVtbl -> GetPinCount(This,pPinCount)

#define IRtpBufferedListenerFilter_Export_GetPinIndexForSource(This,ssrc,pIndex)	\
    (This)->lpVtbl -> GetPinIndexForSource(This,ssrc,pIndex)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRtpBufferedListenerFilter_Export_SetNetworkParameter_Proxy( 
    IRtpBufferedListenerFilter_Export * This,
    /* [in] */ LPWSTR szRemoteAddress,
    /* [in] */ USHORT uRemotePort,
    /* [in] */ LPWSTR szLocalInterface,
    /* [in] */ USHORT uLocalInterface,
    /* [in] */ INT ttl);


void __RPC_STUB IRtpBufferedListenerFilter_Export_SetNetworkParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListenerFilter_Export_SetMediaParameterDefaults_Proxy( 
    IRtpBufferedListenerFilter_Export * This,
    /* [in] */ BOOL bAduSpansMultiplePackets,
    /* [in] */ BYTE payloadType,
    /* [in] */ UINT uRtpTimeStampIncrementPerSecond,
    /* [in] */ UINT uExpectedTimePerAduNanoseconds);


void __RPC_STUB IRtpBufferedListenerFilter_Export_SetMediaParameterDefaults_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListenerFilter_Export_SetOutputMediaType_Proxy( 
    IRtpBufferedListenerFilter_Export * This,
    /* [in] */ AM_MEDIA_TYPE *pMediaType);


void __RPC_STUB IRtpBufferedListenerFilter_Export_SetOutputMediaType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListenerFilter_Export_SetRtpBandwidth_Proxy( 
    IRtpBufferedListenerFilter_Export * This,
    /* [in] */ UINT uSessionBandwidth,
    /* [in] */ BOOL bEnforce);


void __RPC_STUB IRtpBufferedListenerFilter_Export_SetRtpBandwidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListenerFilter_Export_SetJitterBufferParameter_Proxy( 
    IRtpBufferedListenerFilter_Export * This,
    /* [in] */ UINT ssrc,
    /* [in] */ UINT uLatency);


void __RPC_STUB IRtpBufferedListenerFilter_Export_SetJitterBufferParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListenerFilter_Export_SelectActiveSourceForOutputPin_Proxy( 
    IRtpBufferedListenerFilter_Export * This,
    /* [in] */ UINT index,
    /* [in] */ UINT ssrc);


void __RPC_STUB IRtpBufferedListenerFilter_Export_SelectActiveSourceForOutputPin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListenerFilter_Export_AddOutputPin_Proxy( 
    IRtpBufferedListenerFilter_Export * This,
    /* [in] */ INT *pIndex);


void __RPC_STUB IRtpBufferedListenerFilter_Export_AddOutputPin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListenerFilter_Export_AddOutputPinForActiveSource_Proxy( 
    IRtpBufferedListenerFilter_Export * This,
    /* [in] */ UINT ssrc,
    /* [in] */ INT *pIndex);


void __RPC_STUB IRtpBufferedListenerFilter_Export_AddOutputPinForActiveSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListenerFilter_Export_RemoveOutputPin_Proxy( 
    IRtpBufferedListenerFilter_Export * This,
    /* [in] */ UINT index);


void __RPC_STUB IRtpBufferedListenerFilter_Export_RemoveOutputPin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListenerFilter_Export_RegisterEventHandler_Proxy( 
    IRtpBufferedListenerFilter_Export * This,
    /* [in] */ IRtpBufferedListenerFilterEventConsumer *pEventConsumer);


void __RPC_STUB IRtpBufferedListenerFilter_Export_RegisterEventHandler_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListenerFilter_Export_RegisterEventHandlerEx_Proxy( 
    IRtpBufferedListenerFilter_Export * This,
    /* [in] */ IRtpBufferedListenerFilterEventConsumerEx *pEventConsumerEx);


void __RPC_STUB IRtpBufferedListenerFilter_Export_RegisterEventHandlerEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListenerFilter_Export_GetSubscribedSourcesCount_Proxy( 
    IRtpBufferedListenerFilter_Export * This,
    /* [in] */ INT *pcSubscribed);


void __RPC_STUB IRtpBufferedListenerFilter_Export_GetSubscribedSourcesCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListenerFilter_Export_GetSubscribedSources_Proxy( 
    IRtpBufferedListenerFilter_Export * This,
    /* [in] */ INT **pSubscribedSources,
    /* [in] */ INT *pcSubscribedSources);


void __RPC_STUB IRtpBufferedListenerFilter_Export_GetSubscribedSources_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListenerFilter_Export_GetActiveSourcesCount_Proxy( 
    IRtpBufferedListenerFilter_Export * This,
    /* [in] */ INT *pcActive);


void __RPC_STUB IRtpBufferedListenerFilter_Export_GetActiveSourcesCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListenerFilter_Export_GetActiveSources_Proxy( 
    IRtpBufferedListenerFilter_Export * This,
    /* [in] */ INT **pActiveSources,
    /* [in] */ INT *pcActiveSources);


void __RPC_STUB IRtpBufferedListenerFilter_Export_GetActiveSources_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListenerFilter_Export_SetAutoSubscribeActiveSources_Proxy( 
    IRtpBufferedListenerFilter_Export * This,
    /* [in] */ BOOL bValue);


void __RPC_STUB IRtpBufferedListenerFilter_Export_SetAutoSubscribeActiveSources_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListenerFilter_Export_GetAutoSubscribeActiveSources_Proxy( 
    IRtpBufferedListenerFilter_Export * This,
    /* [in] */ BOOL *pbValue);


void __RPC_STUB IRtpBufferedListenerFilter_Export_GetAutoSubscribeActiveSources_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListenerFilter_Export_SetRtpPayloadPacketizer_Proxy( 
    IRtpBufferedListenerFilter_Export * This,
    /* [in] */ IRtpPayloadPacketizer *pPacketizer);


void __RPC_STUB IRtpBufferedListenerFilter_Export_SetRtpPayloadPacketizer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListenerFilter_Export_ReserveNetworkAddress_Proxy( 
    IRtpBufferedListenerFilter_Export * This,
    /* [in] */ LPWSTR szRemoteAddress,
    /* [in] */ LPWSTR szLocalAddress,
    /* [in] */ USHORT uLocalMinPort,
    /* [in] */ USHORT uLocalMaxPort,
    /* [in] */ LPWSTR szLocalOut,
    /* [in] */ INT cchLocal,
    /* [in] */ USHORT *puLocal);


void __RPC_STUB IRtpBufferedListenerFilter_Export_ReserveNetworkAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListenerFilter_Export_GetNetworkParameter_Proxy( 
    IRtpBufferedListenerFilter_Export * This,
    /* [in] */ LPWSTR szRemoteAddress,
    /* [in] */ INT cchRemoteAddress,
    /* [in] */ USHORT *puRemotePort,
    /* [in] */ LPWSTR szLocalInterface,
    /* [in] */ INT cchLocalAddress,
    /* [in] */ USHORT *puLocalPortBase,
    /* [in] */ INT *pTtl);


void __RPC_STUB IRtpBufferedListenerFilter_Export_GetNetworkParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListenerFilter_Export_SetJitterBufferLatency_Proxy( 
    IRtpBufferedListenerFilter_Export * This,
    /* [in] */ UINT ssrc,
    /* [in] */ UINT uLatency);


void __RPC_STUB IRtpBufferedListenerFilter_Export_SetJitterBufferLatency_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListenerFilter_Export_GetJitterBufferLatency_Proxy( 
    IRtpBufferedListenerFilter_Export * This,
    /* [in] */ UINT ssrc,
    /* [in] */ UINT *puLatency);


void __RPC_STUB IRtpBufferedListenerFilter_Export_GetJitterBufferLatency_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListenerFilter_Export_GetRtcpAttributes_Proxy( 
    IRtpBufferedListenerFilter_Export * This,
    /* [in] */ UINT ssrc,
    /* [in] */ struct SdesItems *pSdesItems);


void __RPC_STUB IRtpBufferedListenerFilter_Export_GetRtcpAttributes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListenerFilter_Export_SetMuted_Proxy( 
    IRtpBufferedListenerFilter_Export * This,
    /* [in] */ UINT ssrc,
    /* [in] */ INT bMuted);


void __RPC_STUB IRtpBufferedListenerFilter_Export_SetMuted_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListenerFilter_Export_GetMuted_Proxy( 
    IRtpBufferedListenerFilter_Export * This,
    /* [in] */ UINT ssrc,
    /* [in] */ INT *pbIsMuted);


void __RPC_STUB IRtpBufferedListenerFilter_Export_GetMuted_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListenerFilter_Export_SetPinCount_Proxy( 
    IRtpBufferedListenerFilter_Export * This,
    /* [in] */ INT pinCount);


void __RPC_STUB IRtpBufferedListenerFilter_Export_SetPinCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListenerFilter_Export_GetPinCount_Proxy( 
    IRtpBufferedListenerFilter_Export * This,
    /* [in] */ INT *pPinCount);


void __RPC_STUB IRtpBufferedListenerFilter_Export_GetPinCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListenerFilter_Export_GetPinIndexForSource_Proxy( 
    IRtpBufferedListenerFilter_Export * This,
    /* [in] */ UINT ssrc,
    /* [in] */ INT *pIndex);


void __RPC_STUB IRtpBufferedListenerFilter_Export_GetPinIndexForSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRtpBufferedListenerFilter_Export_INTERFACE_DEFINED__ */


#ifndef __IRtpBufferedListenerFilterSingleOutputPin_Export_INTERFACE_DEFINED__
#define __IRtpBufferedListenerFilterSingleOutputPin_Export_INTERFACE_DEFINED__

/* interface IRtpBufferedListenerFilterSingleOutputPin_Export */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IRtpBufferedListenerFilterSingleOutputPin_Export;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D32EA7E5-59D2-4A6B-ACCF-E70A323004A3")
    IRtpBufferedListenerFilterSingleOutputPin_Export : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Configure( 
            /* [in] */ UINT ssrc,
            /* [in] */ IRtpBufferedListener *pRtpBufferedListener,
            /* [in] */ IPlayoutBuffer *pPlayoutBuffer,
            /* [in] */ IRtpPayloadPacketizer *pPacketizer,
            /* [in] */ LPGUID lpGuidMajorType,
            /* [in] */ LPGUID lpGuidMinorType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetOutputMediaType( 
            /* [in] */ AM_MEDIA_TYPE *pMediaType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetJitterBufferParameter( 
            /* [in] */ UINT uLatency) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSubscribedSsrc( 
            /* [in] */ UINT *pSsrc) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRtpBufferedListenerFilterSingleOutputPin_ExportVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRtpBufferedListenerFilterSingleOutputPin_Export * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRtpBufferedListenerFilterSingleOutputPin_Export * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRtpBufferedListenerFilterSingleOutputPin_Export * This);
        
        HRESULT ( STDMETHODCALLTYPE *Configure )( 
            IRtpBufferedListenerFilterSingleOutputPin_Export * This,
            /* [in] */ UINT ssrc,
            /* [in] */ IRtpBufferedListener *pRtpBufferedListener,
            /* [in] */ IPlayoutBuffer *pPlayoutBuffer,
            /* [in] */ IRtpPayloadPacketizer *pPacketizer,
            /* [in] */ LPGUID lpGuidMajorType,
            /* [in] */ LPGUID lpGuidMinorType);
        
        HRESULT ( STDMETHODCALLTYPE *SetOutputMediaType )( 
            IRtpBufferedListenerFilterSingleOutputPin_Export * This,
            /* [in] */ AM_MEDIA_TYPE *pMediaType);
        
        HRESULT ( STDMETHODCALLTYPE *SetJitterBufferParameter )( 
            IRtpBufferedListenerFilterSingleOutputPin_Export * This,
            /* [in] */ UINT uLatency);
        
        HRESULT ( STDMETHODCALLTYPE *GetSubscribedSsrc )( 
            IRtpBufferedListenerFilterSingleOutputPin_Export * This,
            /* [in] */ UINT *pSsrc);
        
        END_INTERFACE
    } IRtpBufferedListenerFilterSingleOutputPin_ExportVtbl;

    interface IRtpBufferedListenerFilterSingleOutputPin_Export
    {
        CONST_VTBL struct IRtpBufferedListenerFilterSingleOutputPin_ExportVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRtpBufferedListenerFilterSingleOutputPin_Export_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRtpBufferedListenerFilterSingleOutputPin_Export_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRtpBufferedListenerFilterSingleOutputPin_Export_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRtpBufferedListenerFilterSingleOutputPin_Export_Configure(This,ssrc,pRtpBufferedListener,pPlayoutBuffer,pPacketizer,lpGuidMajorType,lpGuidMinorType)	\
    (This)->lpVtbl -> Configure(This,ssrc,pRtpBufferedListener,pPlayoutBuffer,pPacketizer,lpGuidMajorType,lpGuidMinorType)

#define IRtpBufferedListenerFilterSingleOutputPin_Export_SetOutputMediaType(This,pMediaType)	\
    (This)->lpVtbl -> SetOutputMediaType(This,pMediaType)

#define IRtpBufferedListenerFilterSingleOutputPin_Export_SetJitterBufferParameter(This,uLatency)	\
    (This)->lpVtbl -> SetJitterBufferParameter(This,uLatency)

#define IRtpBufferedListenerFilterSingleOutputPin_Export_GetSubscribedSsrc(This,pSsrc)	\
    (This)->lpVtbl -> GetSubscribedSsrc(This,pSsrc)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRtpBufferedListenerFilterSingleOutputPin_Export_Configure_Proxy( 
    IRtpBufferedListenerFilterSingleOutputPin_Export * This,
    /* [in] */ UINT ssrc,
    /* [in] */ IRtpBufferedListener *pRtpBufferedListener,
    /* [in] */ IPlayoutBuffer *pPlayoutBuffer,
    /* [in] */ IRtpPayloadPacketizer *pPacketizer,
    /* [in] */ LPGUID lpGuidMajorType,
    /* [in] */ LPGUID lpGuidMinorType);


void __RPC_STUB IRtpBufferedListenerFilterSingleOutputPin_Export_Configure_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListenerFilterSingleOutputPin_Export_SetOutputMediaType_Proxy( 
    IRtpBufferedListenerFilterSingleOutputPin_Export * This,
    /* [in] */ AM_MEDIA_TYPE *pMediaType);


void __RPC_STUB IRtpBufferedListenerFilterSingleOutputPin_Export_SetOutputMediaType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListenerFilterSingleOutputPin_Export_SetJitterBufferParameter_Proxy( 
    IRtpBufferedListenerFilterSingleOutputPin_Export * This,
    /* [in] */ UINT uLatency);


void __RPC_STUB IRtpBufferedListenerFilterSingleOutputPin_Export_SetJitterBufferParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRtpBufferedListenerFilterSingleOutputPin_Export_GetSubscribedSsrc_Proxy( 
    IRtpBufferedListenerFilterSingleOutputPin_Export * This,
    /* [in] */ UINT *pSsrc);


void __RPC_STUB IRtpBufferedListenerFilterSingleOutputPin_Export_GetSubscribedSsrc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRtpBufferedListenerFilterSingleOutputPin_Export_INTERFACE_DEFINED__ */


#ifndef __ITestRtpJitterBuffer_INTERFACE_DEFINED__
#define __ITestRtpJitterBuffer_INTERFACE_DEFINED__

/* interface ITestRtpJitterBuffer */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ITestRtpJitterBuffer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7507A94E-B7EB-4974-A0C4-CFBFA5A74874")
    ITestRtpJitterBuffer : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Test( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TestAudioBuffer( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITestRtpJitterBufferVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITestRtpJitterBuffer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITestRtpJitterBuffer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITestRtpJitterBuffer * This);
        
        HRESULT ( STDMETHODCALLTYPE *Test )( 
            ITestRtpJitterBuffer * This);
        
        HRESULT ( STDMETHODCALLTYPE *TestAudioBuffer )( 
            ITestRtpJitterBuffer * This);
        
        END_INTERFACE
    } ITestRtpJitterBufferVtbl;

    interface ITestRtpJitterBuffer
    {
        CONST_VTBL struct ITestRtpJitterBufferVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITestRtpJitterBuffer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITestRtpJitterBuffer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITestRtpJitterBuffer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITestRtpJitterBuffer_Test(This)	\
    (This)->lpVtbl -> Test(This)

#define ITestRtpJitterBuffer_TestAudioBuffer(This)	\
    (This)->lpVtbl -> TestAudioBuffer(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITestRtpJitterBuffer_Test_Proxy( 
    ITestRtpJitterBuffer * This);


void __RPC_STUB ITestRtpJitterBuffer_Test_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITestRtpJitterBuffer_TestAudioBuffer_Proxy( 
    ITestRtpJitterBuffer * This);


void __RPC_STUB ITestRtpJitterBuffer_TestAudioBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITestRtpJitterBuffer_INTERFACE_DEFINED__ */



#ifndef __KiteRtpAtl_LIBRARY_DEFINED__
#define __KiteRtpAtl_LIBRARY_DEFINED__

/* library KiteRtpAtl */
/* [helpstring][uuid][version] */ 


EXTERN_C const IID LIBID_KiteRtpAtl;

EXTERN_C const CLSID CLSID_CAudioPlayoutBuffer;

#ifdef __cplusplus

class DECLSPEC_UUID("9CC3E35B-B934-4CA8-A392-F4F702F88A32")
CAudioPlayoutBuffer;
#endif

EXTERN_C const CLSID CLSID_CVideoPlayoutBuffer;

#ifdef __cplusplus

class DECLSPEC_UUID("E493FD51-97B1-4126-829E-24F63A7FD50D")
CVideoPlayoutBuffer;
#endif

EXTERN_C const CLSID CLSID_CInternetProtocolHelper;

#ifdef __cplusplus

class DECLSPEC_UUID("A1A6FBF9-1273-4A9D-98CF-D8B8DD3384B1")
CInternetProtocolHelper;
#endif

#ifndef ___IRtpListenerEvents_DISPINTERFACE_DEFINED__
#define ___IRtpListenerEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IRtpListenerEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IRtpListenerEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("23815B72-D00C-40EF-B373-FD8D4DBAD698")
    _IRtpListenerEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IRtpListenerEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IRtpListenerEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IRtpListenerEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IRtpListenerEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IRtpListenerEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IRtpListenerEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IRtpListenerEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IRtpListenerEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IRtpListenerEventsVtbl;

    interface _IRtpListenerEvents
    {
        CONST_VTBL struct _IRtpListenerEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IRtpListenerEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IRtpListenerEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IRtpListenerEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IRtpListenerEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IRtpListenerEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IRtpListenerEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IRtpListenerEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IRtpListenerEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CRtpListener;

#ifdef __cplusplus

class DECLSPEC_UUID("D9A26C6D-69CB-4E73-A37E-6C3681194C32")
CRtpListener;
#endif

EXTERN_C const CLSID CLSID_CRtpBufferedListener;

#ifdef __cplusplus

class DECLSPEC_UUID("D9A26C6E-69CB-4E73-A37E-6C3681194C32")
CRtpBufferedListener;
#endif

EXTERN_C const CLSID CLSID_CRtpRenderer;

#ifdef __cplusplus

class DECLSPEC_UUID("7A6BE560-2C33-4426-BF2B-17B0DCCFF523")
CRtpRenderer;
#endif

EXTERN_C const CLSID CLSID_CTest;

#ifdef __cplusplus

class DECLSPEC_UUID("07136823-BDF2-4A41-B965-CCE9E450F41F")
CTest;
#endif

EXTERN_C const CLSID CLSID_CTestRtpJitterBuffer;

#ifdef __cplusplus

class DECLSPEC_UUID("4DBA237A-C934-4521-A021-846256D11FC7")
CTestRtpJitterBuffer;
#endif
#endif /* __KiteRtpAtl_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


