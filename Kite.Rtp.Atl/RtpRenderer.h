// RtpRenderer.h : Declaration of the CRtpRenderer

#pragma once
#include "resource.h"       // main symbols

#include "RtpSocketBase.h"
#include "RtpSessionMember.h"
#include "RtpPacket.h"
#include "RtpConfigurationHelper.h"
#include "IRtpPayloadPacketizer.h"

#define DEFAULT_CNAME_T	_T("Kite.RtpRenderer")

//////////////////////////////////////////////////////////////////////////

// IRtpRendererConfiguration
[
	object,
	uuid("DA2B5441-D7AE-45c4-AE59-8620361525DC"),
	pointer_default(unique)
]
__interface IRtpRendererConfiguration : IUnknown
{
	HRESULT SetNetworkParameter(
		[in] LPWSTR szRemoteAddress, 
		[in] USHORT uRemotePort, 
		[in] LPWSTR szLocalInterface, 
		[in] USHORT uLocalPort,
		[in] INT ttl, 
		// [in] UINT uTimeStampIncrementPerSecond, 
		[in] LPWSTR szCname);

	HRESULT ReserveNetworkAddressAndCreateSockets(
		[in] LPWSTR szRemoteAddress, 
		[in,out] LPWSTR szLocalInterface,
		[in] USHORT uMinLocalPort, 
		[in] USHORT uMaxLocalPort,
		[in] INT ttl, 
		[in] LPWSTR cname);

	HRESULT ReserveNetworkAddress(
		[in] LPWSTR szRemoteAddress, 
		[in] LPWSTR szLocalInterface, 
		[in] USHORT uMinLocalPort, [in] USHORT uMaxLocalPort, [in,out] LPWSTR szLocalInterfaceOut, [in] INT cchLocal, [out] USHORT *puLocalPort);

	HRESULT SetPayloadType([in] BYTE payloadType);

	HRESULT SetRtpBandwidth(UINT uSessionBandwidth, BOOL bEnforce);

	HRESULT SetRtcpParameter(
		[in] LPWSTR szName, [in] LPWSTR szEMail, [in] LPWSTR szPhone, [in] LPWSTR szLoc, [in] LPWSTR szTool, [in] LPWSTR szNote);

	// 21.10.2003
	[propget, helpstring("property LocalSsrc")] HRESULT LocalSsrc([out, retval] UINT* pVal);
	[propput, helpstring("property LocalSsrc")] HRESULT LocalSsrc([in] UINT newVal);
};

[
	object,
	uuid("DA2B5442-D7AE-45c4-AE59-8620361525DC"),
	pointer_default(unique)
]
__interface IRtpRendererConfigurationOut : IUnknown
{
	[helpstring("")] HRESULT GetNetworkParameter(
		[in,out] LPWSTR szRemoteAddress, [in] INT cchRemoteAddress, [out] USHORT *puRemotePort, 
		[in,out] LPWSTR szLocalInterface, [in] INT cchLocalAddress, [out] USHORT *puLocalPortBase, [out] INT* pTtl);
};

// IRtpRendererControl
[
	object,
	uuid("DA2B5443-D7AE-45c4-AE59-8620361525DC"),
	pointer_default(unique)
]
__interface IRtpRendererControl : IUnknown
{
	[helpstring("method Start")] HRESULT Start(void);
	[helpstring("method Stop")] HRESULT Stop(void);
};

// IRtpRenderer
[
	object,
	uuid("23AAF37A-90F4-48E9-B816-9EEAFE4912A8"),
	helpstring("IRtpRenderer Interface"),
	pointer_default(unique)
]
__interface IRtpRenderer : IUnknown
{
	HRESULT SendRtpPacket([in] BYTE* pBuffer, [in] UINT cbBuffer, [in] BOOL bMarker, [in] UINT timestamp);

	HRESULT SendRtpPayloadData(
		BOOL bMarker, UINT timestamp,
		BYTE* pProperlyPacketizedData, UINT cbProperlyPacketizedData);
};

[
	object,
	uuid("DA2B5440-D7AE-45c4-AE59-8620361525DC"),
	pointer_default(unique)
]
__interface IRtpRendererFilterConfiguration_Export : IUnknown
{
	HRESULT SetRtpRenderer([in] IRtpRenderer *pRenderer);
	HRESULT SetProtocolMediaParameter([in] UINT avgTimePerFrame, [in] UINT rtpTsIncPerFrame);
	HRESULT SetRtpPayloadPacketizer([in] IRtpPayloadPacketizer *pPacketizer);
};

//////////////////////////////////////////////////////////////////////////

// CRtpRenderer
[
	coclass,
	// threading("apartment"),

	threading("both"),
	event_source("com"),
	aggregatable("never"),
	vi_progid("KiteRtpAtl.RtpRenderer"),
	progid("KiteRtpAtl.RtpRenderer.1"),
	version(1.0),
	uuid("7A6BE560-2C33-4426-BF2B-17B0DCCFF523"),
	helpstring("RtpRenderer Class")
]
class ATL_NO_VTABLE CRtpRenderer : 
	public IRtpRenderer
	, public IRtpRendererControl
	, public IRtpRendererConfiguration
	, public IRtpRendererConfigurationOut
	, public IRtpSenderStatistics
	, public CRtpSocketBase
{
	BOOL m_bSendRRs;
	BOOL m_bLeightweightSdes;

	CRITICAL_SECTION m_critSectSdesBufferLock;
	BYTE* m_pBufferSdesHeader;
	BYTE* m_pBufferSdesFull;
	UINT m_cbBufferSdesFull;
	BYTE* m_pBufferSdesLeightweight;
	UINT m_cbBufferSdesLeightweight;
	UINT m_SdesFullIntervalMilliseconds;
	UINT m_TimeLastSdesFull;

	SdesItems *m_pSdesItems;
	STDMETHOD(InitializeRtcpReportGeneration)();
	STDMETHOD(RtcpTimerCallback)(VOID);

	CComPtr<IPerformanceCounterWrapper> m_pPerfCounterRtpPacketsSent;
	CComPtr<IPerformanceCounterWrapper> m_pPerfCounterRtpOctetsSent;

	UINT m_uNextSeqNum;
	BYTE m_bufferRtpHeader[12];
	
	STDMETHOD(InitializeRtpHeader)(void);
	STDMETHOD(InitializePerformanceCounterForRtpRenderer)(void);


public:
	__event __interface IRtpRendererEventConsumer;

	CRtpRenderer();

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct();
	void FinalRelease();


public:
	STDMETHOD(SendRtpPacket)(BYTE* pBuffer, UINT cbBuffer, BOOL bMarker, UINT timestamp);
	STDMETHOD(SetPayloadType)(BYTE payloadType);
	STDMETHOD(Start)(void);
	STDMETHOD(Stop)(void);
	STDMETHOD(Configure)(
		BYTE* pSocketAddresses, UINT cbSocketAddresses,
		BYTE* pSdesItems, UINT cbSdesItems
		);

	STDMETHOD(SendRtpPayloadData)(BOOL bMarker, UINT timestamp, BYTE* pProperlyPacketizedData, UINT cbProperlyPacketizedData);
	STDMETHOD(SetNetworkParameter)(
		LPWSTR szRemoteAddress, 
		USHORT uRemotePort, 
		LPWSTR szLocalInterface, 
		USHORT uLocalPort, 
		INT ttl, 
		LPWSTR szCname); //, UINT uTimeStampIncrementPerSecond, LPWSTR szCname);
	STDMETHOD(SetRtpBandwidth)(UINT uSessionBandwidth, BOOL bEnforce);
	STDMETHOD(SetRtcpParameter)(LPWSTR szName, LPWSTR szEMail, LPWSTR szPhone, LPWSTR szLoc, LPWSTR szTool, LPWSTR szNote);

	STDMETHOD(ReserveNetworkAddress)(
		LPWSTR szRemoteAddress, 
		LPWSTR szLocalInterface, 
		USHORT uMinLocalPort, USHORT uMaxLocalPort, LPWSTR szLocalInterfaceOut, INT cchLocal, USHORT *puLocalPort);

	STDMETHOD(ReserveNetworkAddressAndCreateSockets)(
		LPWSTR szRemoteAddress, 
		LPWSTR szLocalInterface, 
		USHORT uMinLocalPort, USHORT uMaxLocalPort, INT ttl, LPWSTR cname);

	STDMETHOD(GetNetworkParameter)(
		LPWSTR szRemoteAddress, INT cchRemoteAddress, USHORT *puRemotePort, 
		LPWSTR szLocalInterface, INT cchLocalAddress, USHORT *puLocalPortBase, INT* pTtl);

	// IRtpSenderStatistics
	STDMETHOD(GetSenderStatistics)(UINT *pcPacketsSent, UINT *pcOctetsSent, UINT *pMillisecs);
	STDMETHOD(GetStatisticsForReceiver)(UINT ssrcRRSource, BYTE *pFractionLost, UINT *pcCumulativeNumberOfPacketsLost, UINT *pInterarrivalJitter);
	STDMETHOD(GetPerformanceCounterPrefix)(UINT ssrc, LPWSTR szPerfCounterPrefix, INT cchPerfCounterPrefix);
	STDMETHOD(get_LocalSsrc)(UINT* pVal);
	STDMETHOD(put_LocalSsrc)(UINT newVal);
};

