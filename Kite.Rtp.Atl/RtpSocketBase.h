#pragma once

#include <atlcoll.h>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <MMSystem.h>
#pragma comment(lib, "winmm.lib")

#include "WinsockHelper.h"
#include "WinsockLoader.h"
#include "RtpPacket.h"
#include "RtpSessionMember.h"

class CRtpSocketBase;


#define SINGLE_RTP_BUFFER 0

enum RTP_SESSION_MEMBER_EVENT_TYPE 
{
	RTP_SESSION_MEMBER_EVENT_TYPE_CREATED = 1,
	RTP_SESSION_MEMBER_EVENT_TYPE_DELETED = 2,
	RTP_SESSION_MEMBER_EVENT_TYPE_MUTED = 4,
	RTP_SESSION_MEMBER_EVENT_TYPE_UNMUTED = 4,
	RTP_SESSION_MEMBER_EVENT_TYPE_SDES_CHANGED = 16,
	RTP_SESSION_MEMBER_EVENT_TYPE_PAYLOADTYPE_CHANGED = 32,
};

struct RtpSessionMemberEventArgs
{
	CRtpSocketBase *pRtpSocketBaseEventSource;
	UINT ssrc;
	RTP_SESSION_MEMBER_EVENT_TYPE rtpSessionMemberEventType;
};


struct WSAOVERLAPPED_INSTANCE_DATA
{
	UINT uIndex;
	BOOL bCallPending;
	LPVOID lpInstance;
	WSABUF* pWsaBuf;
	sockaddr* pSockaddressReceivedFrom;
	INT cbSockaddr;
};

#include "SocketData.h"

class CRtpSocketBase 
	: CWinsockLoader
{
	SocketAddressList *m_pReservedSockets;

#if GQOS_ENABLED
	BOOL m_bGQoSEnabled;
	STDMETHOD(SetQoS)();
#endif
public:
	STDMETHOD(Initialize)(void);
private:
	
	LPWSABUF m_pwsabufRtpReceiver;
	LPWSABUF m_pwsabufRtcpReceiver;

	LPWSAOVERLAPPED m_pWsaOverlappedRtpReceiver;
	LPWSAOVERLAPPED m_pWsaOverlappedRtcpReceiver;

	BYTE* m_pRtpReceiveBufferContinuous;
	BYTE* m_pRtcpReceiveBufferContinuous;

	BOOL m_bRtcpReceiveQueuedCallPending;

	UINT m_cRtpReceiveBuffer;
	UINT m_cRtcpReceiveBuffer;
	UINT m_cbRtpReceiveBuffer;
	UINT m_cbRtcpReceiveBuffer;

public:
	BYTE m_payloadType;

	UINT m_uRtcpTimerResolution;
	UINT m_uCurrentTimerId;

	STDMETHOD(CreateRtcpTimer)(VOID);
	STDMETHOD(UninitializeRtcpTimer)(VOID);
	static void CALLBACK RtcpTimerProc(
		UINT uID,      
		UINT uMsg,     
		DWORD dwUser,  
		DWORD dw1,     
		DWORD dw2      
		);

	STDMETHOD(RtcpTimerCallback)();
	DWORD CalculateRtcpTimeout();

	BOOL m_bIsListener;
protected:
	BOOL m_bListenState;
	UINT m_ssrc;

	SOCKET m_scktRtpSocket;
	SOCKET m_scktRtcpSocket;
	
	SOCKET m_scktRtpBaseSocket;
	SOCKET m_scktRtcpBaseSocket;

	sockaddr* m_pSockkaddrRecvFromRtpSocket;
	sockaddr* m_pSockkaddrRecvFromRtcpSocket;
	INT m_cbSockkaddrRecvFromRtpSocketFromLen;
	INT m_cbSockkaddrRecvFromRtcpSocketFromLen;

	SocketAddresses *m_pRtpAddresses;
	SocketAddresses *m_pRtcpAddresses;

	DWORD m_dwWsaReceiveEvents;
	HANDLE m_hEventWorkerThreadDied;
	WSAEVENT m_wsaReceiveEvents[3];
	HANDLE m_hReceiverWorkerThread;
	HANDLE m_hEventWorkerThreadStartThreadProc;
	CRITICAL_SECTION m_critSectReceiverWorkerThread;
	BOOL m_bReceiveWorkerThreadAlive;
	BOOL m_bReceiveWorkerThreadListening;

	STDMETHOD(InitializeReceiverThread)(VOID);
	STDMETHOD(CleanupReceiverThread)(VOID);

	static DWORD WINAPI StaticReceiveThreadThreadProc( LPVOID lpThreadParameter );
	DWORD WINAPI InstanceReceiveThreadThreadProc(VOID);
private:
#if SINGLE_RTP_BUFFER
	WSAOVERLAPPED m_wsaoverlappedRtpRecvFrom;
#endif
	WSAOVERLAPPED m_wsaoverlappedRtcpRecvFrom;

	STDMETHOD(InitializeOverlapped)(VOID);

#if !SINGLE_RTP_BUFFER

#define PARALLEL_PENDING_RTP_RECVFROM_CALLS 1 //	3
#define RTP_RECV_BUFFER_SIZE	4096
	WSAOVERLAPPED *m_pWsaOverlappedRtpRecvFrom;
	WSAOVERLAPPED_INSTANCE_DATA *m_pWsaOverlappedInstanceData;
	UINT m_cWsaOverlappedInstanceData;
	HANDLE m_hEventReceiveWorkerThreadWakeupEvent;

#endif

	STDMETHOD(IntializeOverlappedReceiveStruct)(VOID);

	STDMETHOD(RtpListen)(UINT uBufIdx);
	STDMETHOD(RtcpListen)();

	static VOID __stdcall CALLBACK ReceiveFromRtpSocketCompletionRoutine(
		IN DWORD dwError, 
		IN DWORD cbTransferred, 
		IN LPWSAOVERLAPPED lpOverlapped, 
		IN DWORD dwFlags);

	static VOID __stdcall CALLBACK ReceiveFromRtcpSocketCompletionRoutine(
		IN DWORD dwError, 
		IN DWORD cbTransferred, 
		IN LPWSAOVERLAPPED lpOverlapped, 
		IN DWORD dwFlags);

	STDMETHOD(HandleRtpData)(UINT uBufferIndex, DWORD dwBytesRead);
	STDMETHOD(HandleRtcpData)(BYTE* pBuffer, DWORD dwBytesRead);
	
protected:
	CRITICAL_SECTION m_critSectObjectLock;
	
	CRITICAL_SECTION m_critSectRtpSessionMembersMapSynchronization;
	
	CAtlMap<UINT, CRtpSessionMember*> m_mapRtpSessionMembers;
	UINT m_rtpSessionBandwidthKilobitPerSecond;
	STDMETHOD(SetRtpBandwidth)(UINT uSessionBandwidthKilobitPerSecond, BOOL bEnforce);

	STDMETHOD(UpdateSessionMember/*ByRtpPacket*/)(RtpParsedPacket *pRtpParsedPacket);
	STDMETHOD(UpdateSessionMember/*ByRtcpSenderReport*/)(RtcpSenderReport *pRtcpSenderReport);
	STDMETHOD(UpdateSessionMember/*ByRtcpReceiverReport*/)(RtcpReceiverReport *pRtcpReceiverReport);
	STDMETHOD(RemoveSessionMember/*ByRtcpBye*/)(RtcpBye *pRtcpBye);

	STDMETHOD(HandleSourceAdded)(UINT ssrc);
	STDMETHOD(HandleSourceRemoved)(UINT ssrc);
	STDMETHOD(HandleSourceChanged)(UINT ssrc, RTP_SESSION_MEMBER_EVENT_TYPE eventType);
	STDMETHOD(HandleParsedRtpPacket)(RtpParsedPacket *pParsedPacket) /*PURE*/;
	STDMETHOD(RaiseActiveRtpSourceAddedEvent)(UINT ssrc);
	STDMETHOD(RaiseActiveRtpSourceDeletedEvent)(UINT ssrc);
	STDMETHOD(RaiseActiveRtpSourceChangedEvent)(UINT ssrc, RTP_SESSION_MEMBER_EVENT_TYPE eventType);

#if (_WIN32_WINNT >= 0x0500) 
	static DWORD WINAPI QueueUserWorkItemThreadProc_RaiseEventRtpSessionMemberRemoved(LPVOID lpThreadParameter);
	static DWORD WINAPI QueueUserWorkItemThreadProc_RaiseEventRtpSourceAdded(LPVOID lpThreadParameter);
	static DWORD WINAPI QueueUserWorkItemThreadProc_RaiseEventRtpSourceChanged(LPVOID lpThreadParameter);
#endif

private:
	STDMETHOD(TimeoutRtpSessionMembers)();		
protected:
	CComPtr<IPerformanceCounterFactory> m_pPerfCounterFactory;
	
	CComPtr<IPerformanceCounterWrapper> m_pPerfCounterNumberOfSessionMembers;
	CComPtr<IPerformanceCounterWrapper> m_pPerfCounterNumberOfActiveSources;
	CComPtr<IPerformanceCounterWrapper> m_pPerfCounterTimestampLastRtpPacketSent;
	CComPtr<IPerformanceCounterWrapper> m_pPerfCounterTimestampLastRtcpReportSent;
	CComPtr<IPerformanceCounterWrapper> m_pPerfCounterRtcpPacketsSent;
	CComPtr<IPerformanceCounterWrapper> m_pPerfCounterRtcpOctetsSent;

	STDMETHOD(InitializePerformanceCounter)(void);

#ifdef _DEBUG
public:
#else
protected:
#endif
	CRtpSocketBase(void);
	~CRtpSocketBase(void);

	STDMETHOD(SetIsListener)(BOOL rtpListener);
	STDMETHOD(SendBye)(void);
public:
	STDMETHOD(CreateSockets)(SocketAddresses*);
	STDMETHOD(StartListen)(VOID);
	STDMETHOD(StopListen)(VOID);

	STDMETHOD(SendRtcpDataRaw)(BYTE** ppBuffer, UINT* pcbBufferLengths, UINT cBuffers);


	HRESULT InternalReserveNetworkAddress(
		LPWSTR szRemoteAddress, 
		LPWSTR szLocalInterface, 
		USHORT uMinLocalPort, USHORT uMaxLocalPort, LPWSTR szLocalInterfaceOut, INT cchLocalAddress, USHORT *puLocalPortBase);

	HRESULT InternalReserveNetworkAddressAndCreateSockets(
		LPWSTR szRemoteAddress, 
		LPWSTR szLocalInterface, 
		USHORT uMinLocalPort,
		USHORT uMaxLocalPort, INT ttl);

	HRESULT InternalGetNetworkParameter(
		LPWSTR szRemoteAddress, INT cchRemoteAddress, USHORT* puRemotePort, 
		LPWSTR szLocalInterface, INT cchLocalAddress, USHORT* puLocalPortBase, INT* pTtl);

	HRESULT InternalGetSessionMemberInfo(UINT ssrc, RtpSessionMemberInfo *pInfo, BOOL bIncludeSdesItems);
};

