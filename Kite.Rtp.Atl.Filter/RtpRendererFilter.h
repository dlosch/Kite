#pragma once
#include <streams.h>

//////////////////////////////////////////////////////////////////////////

#if !EXTERNAL_INTERFACES
DECLARE_INTERFACE_(IRtpRendererFilterConfiguration, IUnknown)
{
	STDMETHOD(SetRtpRenderer)(IRtpRenderer *pRenderer);
	STDMETHOD(SetProtocolMediaParameter)(UINT avgTimePerFrame, UINT rtpTsIncPerFrame);

	STDMETHOD(SetRtpPayloadPacketizer)(
		THIS_
		IRtpPayloadPacketizer *pPacketizer);
};

DECLARE_INTERFACE_(IRtpRendererFilter, IUnknown) 
{
	STDMETHOD(SetNetworkParameter)(THIS_ 
		LPWSTR szRemoteAddress, 
		USHORT uRemotePort, 
		LPWSTR szLocalInterface, 
		USHORT uLocalPort,
		INT ttl, 
		//UINT uTimeStampIncrementPerSecond, 
		LPWSTR szCname);

	STDMETHOD(SetRtpParameter)(THIS_ BYTE payloadType);

	STDMETHOD(SetRtpBandwidth)(THIS_ UINT uSessionBandwidth, BOOL bEnforce);

	STDMETHOD(SetRtcpParameter)(THIS_ BSTR lpcwstrName, BSTR lpcwstrEMail, BSTR lpcwstrPhone, BSTR lpcwstrLoc, BSTR lpcwstrTool, BSTR lpcwstrNote );

	STDMETHOD(SetProtocolMediaParameter)(
		THIS_ 
		// nanos per Frame duration
		UINT uTimePerAduNanos, 
		UINT uRtpTimestampIncrementPerFrame);

	STDMETHOD(SetRtpPayloadPacketizer)(
		THIS_
		IRtpPayloadPacketizer *pPacketizer);


	STDMETHOD(ReserveNetworkAddress)(THIS_ 
		/*[in]*/ LPWSTR szRemoteAddress, /*[in,out]*/ LPWSTR szLocalAddress, 
		USHORT uMinLocalPort, USHORT uMaxLocalPort, LPWSTR szLocalOut, INT cchLocal, USHORT* puLocal);

	STDMETHOD(GetNetworkParameter)(
		THIS_
		LPWSTR szRemoteAddress, INT cchRemoteAddress, USHORT *puRemotePort, 
		LPWSTR szLocalInterface, INT cchLocalAddress, USHORT *puLocalPortBase, INT* pTtl);
};
#endif

#if !EXTERNAL_INTERFACES
DECLARE_INTERFACE_(IRtpRendererFilterEx, IRtpRendererFilter) 
{
	STDMETHOD(GetPerformanceCounterPrefix)(THIS_ /* out */ LPBSTR bstrPerfCounterPrefix);
	STDMETHOD(GetActiveSourcesCount)(INT *pcActive);
	STDMETHOD(GetActiveSources)(INT** pActiveSources, INT* pcActiveSources);
};
#endif

class CRtpRendererFilter :
	public CBaseRenderer
	, public IRtpRendererFilterConfiguration
{
	QzCComPtr<IRtpRenderer> m_pRtpRenderer;
	QzCComPtr<IRtpRendererConfiguration> m_pRtpRendererConfiguration;
	QzCComPtr<IRtpRendererConfigurationOut> m_pRtpRendererConfigurationOut;
	QzCComPtr<IRtpRendererControl> m_pRtpRendererControl;

	QzCComPtr<IRtpSenderStatistics> m_pRtpSenderStats;
	
	IRtpPayloadPacketizer* m_pRtpPayloadPacketizer;

	INT m_payloadType;

public:
	CRtpRendererFilter(LPUNKNOWN pUnk, HRESULT *phr);
	~CRtpRendererFilter(void);

	//////////////////////////////////////////////////////////////////////////
	// COM Stuff
	static CUnknown * WINAPI CreateInstance(LPUNKNOWN pUnk, HRESULT *phr);
	STDMETHODIMP NonDelegatingQueryInterface(REFIID, void **);
	STDMETHODIMP_(ULONG) NonDelegatingRelease(void);
	DECLARE_IUNKNOWN;
	//////////////////////////////////////////////////////////////////////////

	// Must overrides
	HRESULT CheckMediaType(
		const CMediaType *pmt
		);

	HRESULT DoRenderSample(
		IMediaSample *pMediaSample
		);

	//////////////////////////////////////////////////////////////////////////
	HRESULT ShouldDrawSampleNow(
		IMediaSample *pMediaSample,
		REFERENCE_TIME *pStartTime,
		REFERENCE_TIME *pEndTime
		);


	//////////////////////////////////////////////////////////////////////////
	HRESULT OnStartStreaming(void);
	HRESULT OnStopStreaming(void);

	HRESULT SetMediaType(
		const CMediaType *pMediaType);

	CComBSTR m_rtcpName;
	CComBSTR m_rtcpEMail;
	CComBSTR m_rtcpPhone;
	CComBSTR m_rtcpLoc;
	CComBSTR m_rtcpTool;
	CComBSTR m_rtcpNote;

	// IrtpRendererFilter
	LPWSTR m_szRemoteAddress;
	USHORT m_uRemotePort;
	LPWSTR m_szLocalAddress;
	USHORT m_uLocalPort;
	INT m_ttl;
	WCHAR m_szCname[256]; // 255 plus \0

	BOOL m_bIsFirstSample;
	LONGLONG m_lFirstSampleStartTime;

	UINT m_uTimePerAduNanos;
	UINT m_uTimestampIncrementPerAdu;

	UINT m_uRtpSessionBandwidth;
	
	STDMETHOD(SetNetworkParameter)(
		LPWSTR szRemoteAddress, 
		USHORT uRemotePort, 
		LPWSTR szLocalInterface, 
		USHORT uLocalPort,
		INT ttl, 
		//UINT uTimeStampIncrementPerSecond, 
		LPWSTR szCname);
	
	
	STDMETHOD(SetRtpBandwidth)(UINT uSessionBandwidth, BOOL bEnforce);
	STDMETHOD(SetRtpParameter)(BYTE payloadType);
	STDMETHOD(SetRtcpParameter)(BSTR lpcwstrName, BSTR lpcwstrEMail, BSTR lpcwstrPhone, BSTR lpcwstrLoc, BSTR lpcwstrTool, BSTR lpcwstrNote );
	
	STDMETHOD(SetProtocolMediaParameter)(
		// nanos per Frame duration
		UINT uTimePerAduNanos, 
		UINT uRtpTimestampIncrementPerFrame);

	STDMETHOD(SetRtpPayloadPacketizer)(
		IRtpPayloadPacketizer *pPacketizer);

	// STDMETHOD(ReserveNetworkAddressAndCreateSockets)(/*[in]*/ LPWSTR szRemoteAddress, /*[in,out]*/ LPWSTR szLocalAddress, USHORT uMinLocalPort, USHORT uMaxLocalPort, INT ttl);
	STDMETHOD(ReserveNetworkAddress)(/*[in]*/ LPWSTR szRemoteAddress, /*[in,out]*/ LPWSTR szLocalAddress, USHORT uMinLocalPort, USHORT uMaxLocalPort, LPWSTR szLOcalOut, INT cchLocal, USHORT *puLocal);

	STDMETHOD(GetNetworkParameter)(
		LPWSTR szRemoteAddress, INT cchRemoteAddress, USHORT *puRemotePort, 
		LPWSTR szLocalInterface, INT cchLocalAddress, USHORT *puLocalPortBase, INT* pTtl);


	//////////////////////////////////////////////////////////////////////////
	// IRtpSenderStats
	STDMETHOD(GetSenderStatistics)(UINT *pcPacketsSent, UINT *pcOctetsSent, UINT *pMillisecs);
	STDMETHOD(GetStatisticsForReceiver)(UINT ssrcRRSource, BYTE *pFractionLost, UINT *pcCumulativeNumberOfPacketsLost, UINT *pInterarrivalJitter);
	STDMETHOD(GetPerformanceCounterPrefix)(UINT ssrc, LPWSTR szPerfCounterPrefix, INT cchPerfCounterPrefix);

	// IRtpRendererFilterConfiguration
	STDMETHOD(SetRtpRenderer)(IRtpRenderer *pRenderer);

	STDMETHOD(AssignRtpRendererInstance)(IRtpRenderer *pRenderer);			
};
