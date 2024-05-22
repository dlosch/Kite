// RtpListener.h : Declaration of the CRtpListener

#pragma once
#include "resource.h"       // main symbols

#include <WinSock2.h>
#include "RtpSocketBase.h"
#include "RtpSessionMember.h"
#include "RtpConfigurationHelper.h"

// Buffer
#include "NetworkJitterBuffer.h"

#define MAX_ADDR_LEN	100

#include "rtpidlexports.h"
#include "IRtpListenerInterfaces.h"

// CRtpListener

class CRtpListenerBase 
	: public CRtpSocketBase
{
	CComPtr<IRtpListenerEventConsumer> m_pEventConsumer;

	STDMETHOD(HandleSourceAdded)(UINT ssrc);
	STDMETHOD(HandleSourceRemoved)(UINT ssrc);

protected:
	CRtpListenerBase();
public:
	HRESULT FinalConstruct();
	void FinalRelease();

	STDMETHOD(RtcpTimerCallback)(VOID);

	STDMETHOD(Configure)(BYTE* pSocketAddresses, UINT cbSocketAddresses/*, BYTE* pSdesItems, UINT cbSdesItems*/);
	STDMETHOD(Start)(void);
	STDMETHOD(Stop)(void);

	STDMETHOD(SetNetworkParameter)(LPWSTR szRemoteAddress, USHORT uRemotePort, LPWSTR szLocalInterface, USHORT uLocalPort, INT ttl);
	STDMETHOD(RegisterCallback)(IRtpListenerEventConsumer *pEventConsumer);

	// Virtual
	STDMETHOD(InternalHandleSourceRemoved)(UINT ssrc) PURE;

};

// _IRtpListenerEvents
[
	dispinterface,
	uuid("23815B72-D00C-40EF-B373-FD8D4DBAD698"),
	helpstring("_IRtpListenerEvents Interface")
]
__interface _IRtpListenerEvents
{

};

[
	coclass,
	// threading("apartment"),
	threading("both"),

	event_source("com"),
	vi_progid("KiteRtpAtl.RtpListener"),
	progid("KiteRtpAtl.RtpListener.1"),
	version(1.0),
	uuid("D9A26C6D-69CB-4E73-A37E-6C3681194C32"),
	helpstring("RtpListener Class")

	, noncreatable
]
class ATL_NO_VTABLE CRtpListener 
	: public CRtpListenerBase
	, public IRtpListener
{
public:
	CRtpListener();
	__event __interface _IRtpListenerEvents;
	DECLARE_PROTECT_FINAL_CONSTRUCT()
	HRESULT FinalConstruct();
	void FinalRelease();

	STDMETHOD(Configure)(BYTE* pSocketAddresses, UINT cbSocketAddresses/*, BYTE* pSdesItems, UINT cbSdesItems*/);
	STDMETHOD(Start)(void);
	STDMETHOD(Stop)(void);

	STDMETHOD(SetNetworkParameter)(LPWSTR szRemoteAddress, USHORT uRemotePort, LPWSTR szLocalInterface, USHORT uLocalPort, INT ttl);
	STDMETHOD(SetMediaParameter)(
			BOOL bAduSpansMultiplePackets,
			BYTE payloadType,
			UINT uRtpTimeStampIncrementPerSecond,
			UINT uExpectedTimePerAduNanoseconds);
	
	STDMETHOD(SetRtpBandwidth)(UINT uSessionBandwidth, BOOL bEnforce);
	STDMETHOD(RegisterCallback)(IRtpListenerEventConsumer *pEventConsumer);
	STDMETHOD(SubscribeSsrc)(UINT ssrc);
	STDMETHOD(UnsubscribeSsrc)(UINT ssrc);

	STDMETHOD(ReserveNetworkAddress)(LPWSTR szRemoteAddress, LPWSTR szLocalInterface, USHORT uMinLocalPort, USHORT uMaxLocalPort, LPWSTR szLocalOut, INT cchLocal, USHORT* puLocalPort);
	STDMETHOD(ReserveNetworkAddressAndCreateSockets)(LPWSTR szRemoteAddress, LPWSTR szLocalInterface, USHORT uMinLocalPort, USHORT uMaxLocalPort, INT ttl);

	STDMETHOD(IsSubscribedTo)(UINT ssrc, INT* retVal);
};

//////////////////////////////////////////////////////////////////////////



