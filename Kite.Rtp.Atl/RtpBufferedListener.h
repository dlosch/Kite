#pragma once
#ifndef RTPBUFFEREDLISTENER_H
#define RTPBUFFEREDLISTENER_H

#include "RtpListener.h"
#include <atlcoll.h>
#include "RtpListenerEventCallbacks.h"

[
	coclass,
	// threading("apartment"),
	
	threading("both"),

	event_source("com"),
	vi_progid("KiteRtpAtl.RtpBufferedListener"),
	progid("KiteRtpAtl.RtpBufferedListener.1"),
	version(1.0),
	uuid("D9A26C6E-69CB-4E73-A37E-6C3681194C32"),
	helpstring("RtpBufferedListener Class")
]
class ATL_NO_VTABLE CRtpBufferedListener 
	: public CRtpListenerBase
	, public IRtpListenerConfiguration
	, public IRtpListenerConfigurationOut
	, public IRtpListenerControl
	, public IRtpListenerCallbackRegistration
	, public IRtpBufferedListener
	, public IRtpBufferedListenerData
	, public IRtpListener
{
protected:
	CComPtr<IClassFactory> m_pPlayoutBufferClassFactory;
	STDMETHOD(CreateClassFactory)(BOOL bVideo);

	STDMETHOD(HandleParsedRtpPacket)(RtpParsedPacket *pParsedPacket);

	CRITICAL_SECTION m_critSectMapJitterBufferForSourcesSynchronization;
	
	BOOL m_bAduSpansMultiplePackets;
	BYTE m_payloadType;
	UINT m_uExpectedTimePerAduNanoseconds;
	
	CAtlMap<UINT /*ssrc*/, IPlayoutBuffer* /*pJitterBuffer*/> m_mapJitterBuffersForSources; 

	UINT m_uTimestampIncrementPerSecond;
	UINT m_uTimePerFrameNanos;
	UINT m_uBufferDurationMilliseconds;

public:
	CRtpBufferedListener();
	__event __interface IRtpListenerEventConsumer;
	DECLARE_PROTECT_FINAL_CONSTRUCT()
	HRESULT FinalConstruct();
	void FinalRelease();

	STDMETHOD(Configure)(BYTE* pSocketAddresses, UINT cbSocketAddresses/*, BYTE* pSdesItems, UINT cbSdesItems*/);
	STDMETHOD(Start)(void);
	STDMETHOD(Stop)(void);

	STDMETHOD(SetNetworkParameter)(
		LPWSTR szRemoteAddress, 
		USHORT uRemotePort, 
		LPWSTR szLocalInterface, 
		USHORT uLocalPort,
		INT ttl);
	STDMETHOD(SetMediaParameterDefaults)(
		BOOL bAduSpansMultiplePackets,
		BYTE payloadType,
		UINT uRtpTimeStampIncrementPerSecond,
		UINT uExpectedTimePerAduNanoseconds,
		BOOL bUpdateExistingBuffers);

	STDMETHOD(SetRtpBandwidth)(UINT uSessionBandwidth, BOOL bEnforce);
	STDMETHOD(GetLatency)(UINT* pLatency);
	STDMETHOD(SetLatency)(UINT uLatency);

	STDMETHOD(RegisterCallback)(IRtpListenerEventConsumer *pEventConsumer);
	//
	STDMETHOD(GetDeliveryUnit)(UINT ssrc, RtpParsedPacket*** pppDeliveryUnit, UINT *pcPackets);

	STDMETHOD(SubscribeSsrc)(UINT ssrc);
	STDMETHOD(SubscribeSsrcAndGetPointer)(UINT ssrc, IPlayoutBuffer** ppPlayoutBuffer);
	STDMETHOD(SubscribeSsrcAndGetPointerEx)(UINT ssrc, 
		LPGUID guidJitterBuffer,
		BYTE payloadType,
		UINT uRtpTimeStampIncrementPerSecond,
		UINT uExpectedTimePerAduNanoseconds,

		IPlayoutBuffer** ppPlayoutBuffer);

	STDMETHOD(UnsubscribeSsrc)(UINT ssrc);
	STDMETHOD(GetSubscribedSourcesCount)(INT *pcSubscribed);
	STDMETHOD(GetSubscribedSources)(INT** ppSubscribedSources, INT* pcSubscribedSources);
	STDMETHOD(GetActiveSourcesCount)(INT *pcActive);
	STDMETHOD(GetActiveSources)(INT** ppActiveSources, INT* pcActiveSources);
	STDMETHOD(GetActiveSourcesSafeArray)(/*[out, satype(VT_U4)]*/ SAFEARRAY** ppActiveSources);

	STDMETHOD(InternalHandleSourceRemoved)(UINT ssrc);

	STDMETHOD(ReserveNetworkAddress)(LPWSTR szRemoteAddress, LPWSTR szLocalInterface, USHORT uMinLocalPort, USHORT uMaxLocalPort, LPWSTR szLocalInterfaceOut, INT cchLocalAddress, USHORT *puLocalPortBase);
	STDMETHOD(ReserveNetworkAddressAndCreateSockets)(LPWSTR szRemoteAddress, LPWSTR szLocalInterface, USHORT uMinLocalPort, USHORT uMaxLocalPort, INT ttl);

	STDMETHOD(GetNetworkParameter)(
		LPWSTR szRemoteAddress, INT cchRemoteAddress, USHORT *puRemotePort, 
		LPWSTR szLocalInterface, INT cchLocalAddress, USHORT *puLocalPortBase, INT* pTtl);

	STDMETHOD(SetJitterBufferLatency)(UINT ssrc, UINT uLatency);
	STDMETHOD(GetJitterBufferLatency)(UINT ssrc, UINT* puLatency);
	STDMETHOD(GetRtcpAttributes)(UINT ssrc, SdesItems *pSdesItems);
	STDMETHOD(SetMuted)(UINT ssrc, INT bMuted);
	STDMETHOD(GetMuted)(UINT ssrc, INT *pbIsMuted);

protected:
	STDMETHOD(SetParameterOnJitterBuffer)();

	STDMETHOD(GetSessionMemberInfo)(UINT ssrc, RtpSessionMemberInfo *pSessionMemberInfo, BOOL bIncludeSdesItems);
	STDMETHOD(SetPlayoutBufferGuid)(LPGUID playoutBufferGuid);

	STDMETHOD(RaiseActiveRtpSourceAddedEvent)(UINT ssrc);
	STDMETHOD(RaiseActiveRtpSourceDeletedEvent)(UINT ssrc);
	STDMETHOD(RaiseActiveRtpSourceChangedEvent)(UINT ssrc, RTP_SESSION_MEMBER_EVENT_TYPE eventType);
public:
	STDMETHOD(get_LocalSsrc)(UINT* pVal);
	STDMETHOD(put_LocalSsrc)(UINT newVal);
};

#endif
