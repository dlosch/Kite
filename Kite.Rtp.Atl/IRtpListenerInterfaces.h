//////////////////////////////////////////////////////////////////////////
[
	object,
	uuid("C24FF91D-56E8-4bf7-8E4B-4B4409862FBB"),
	pointer_default(unique)
]
__interface IRtpListenerConfiguration : IUnknown
{
	HRESULT SetNetworkParameter(
		[in] LPWSTR szRemoteAddress, 
		[in] USHORT uRemotePort, 
		[in] LPWSTR szLocalInterface, 
		[in] USHORT uLocalPort,
		[in] INT ttl);

	HRESULT SetMediaParameterDefaults(
		[in] BOOL bAduSpansMultiplePackets,
		[in] BYTE payloadType,
		[in] UINT uRtpTimeStampIncrementPerSecond,
		[in] UINT uExpectedTimePerAduNanoseconds,
		[in] BOOL bUpdateExistingBuffers);

	HRESULT SetRtpBandwidth(
		[in] UINT uSessionBandwidth, 
		[in] BOOL bEnforce);

	HRESULT ReserveNetworkAddressAndCreateSockets(
		[in] LPWSTR szRemoteAddress, 
		[in,out] LPWSTR szLocalInterface,
		[in] USHORT uMinLocalPort, 
		[in] USHORT uMaxLocalPort,
		[in] INT ttl);

	HRESULT ReserveNetworkAddress(
		[in] LPWSTR szRemoteAddress, 
		[in] LPWSTR szLocalInterface, 
		[in] USHORT uMinLocalPort, 
		[in] USHORT uMaxLocalPort, 
		[in,out] LPWSTR szLocalInterfaceOut, 
		[in] INT cchLocal, 
		[out] USHORT *puLocalPort);
	[propget, helpstring("property LocalSsrc")] HRESULT LocalSsrc([out, retval] UINT* pVal);
	[propput, helpstring("property LocalSsrc")] HRESULT LocalSsrc([in] UINT newVal);
};

[
	object,
	uuid("C24FF91C-56E8-4bf7-8E4B-4B4409862FBB"),
	pointer_default(unique)
]
__interface IRtpListenerConfigurationOut : IUnknown
{
	HRESULT GetNetworkParameter(
		[in,out] LPWSTR szRemoteAddress, INT cchRemoteAddress, [out] USHORT *puRemotePort, 
		[in,out] LPWSTR szLocalInterface, INT cchLocalAddress, [out] USHORT *puLocalPortBase, [out] INT* pTtl);
};

[
	object,
	uuid("C24FF91E-56E8-4bf7-8E4B-4B4409862FBB"),
	pointer_default(unique)
]
__interface IRtpListenerControl : IUnknown
{
	HRESULT Start(void);
	HRESULT Stop(void);
};

[
	object,
	uuid("C24FF920-56E8-4bf7-8E4B-4B4409862FBB"),
	pointer_default(unique)
]
__interface IRtpListenerCallbackRegistration : IUnknown
{
	HRESULT RegisterCallback([in] IRtpListenerEventConsumer *pEventConsumer);
};

[
	object,
	uuid("C24FF921-56E8-4bf7-8E4B-4B4409862FBB"),
	pointer_default(unique)
]
__interface IRtpBufferedListener : IUnknown
{
	HRESULT SetPlayoutBufferGuid([in] LPGUID playoutBufferGuid);

	HRESULT SubscribeSsrc([in] UINT ssrc);

	HRESULT SubscribeSsrcAndGetPointerEx(
		UINT ssrc,
		[in] LPGUID guidJitterBuffer,
		BYTE payloadType,
		UINT uRtpTimeStampIncrementPerSecond,
		UINT uExpectedTimePerAduNanoseconds,
		[out] IPlayoutBuffer** ppPlayoutBuffer);

	HRESULT UnsubscribeSsrc([in] UINT ssrc);

	HRESULT GetSubscribedSourcesCount([in,out] INT *pcSubscribed);
	HRESULT GetSubscribedSources([in,out] INT** pSubscribedSources, [in,out] INT* pcSubscribedSources);
	HRESULT GetActiveSourcesCount([in,out] INT *pcActive);
	HRESULT GetActiveSources([in,out] INT** pActiveSources, [in,out] INT* pcActiveSources);

	HRESULT SetMuted(UINT ssrc, INT bMuted);
	HRESULT GetMuted(UINT ssrc, INT *pbIsMuted);

	HRESULT SetJitterBufferLatency(UINT ssrc, UINT uLatency);
	HRESULT GetJitterBufferLatency(UINT ssrc, UINT* puLatency);
};

[
	object,
	uuid("C24FF922-56E8-4bf7-8E4B-4B4409862FBB"),
	pointer_default(unique)
]
__interface IRtpBufferedListenerData : IUnknown
{
	HRESULT GetDeliveryUnit([in] UINT ssrc, [in,out] RtpParsedPacket*** pppDeliveryUnit, [in, out]UINT *pcPackets);
};

[
	object,
	uuid("C24FF923-56E8-4bf7-8E4B-4B4409862FBB"),
	pointer_default(unique)
]
__interface IRtpListener: IUnknown
{
	HRESULT GetRtcpAttributes(UINT ssrc, [in,out]SdesItems *pSdesItems);
	HRESULT GetSessionMemberInfo([in] UINT ssrc, [in,out] RtpSessionMemberInfo *pSessionMemberInfo, [in] BOOL bIncludeSdesItems);
};

#if OLD_INTERFACES
[
	object,
	uuid("1ABEA160-797F-4A07-93AD-7DACBE477F48"),
	helpstring("IRtpListener Interface"),
	pointer_default(unique)
]
__interface IRtpListener : IUnknown	 // : IDispatch
{
	[helpstring("method Start")] HRESULT Start(void);
	[helpstring("method Stop")] HRESULT Stop(void);

	[helpstring("method SetNetworkParameter")] HRESULT SetNetworkParameter(
		[in] LPWSTR szRemoteAddress, 
		[in] USHORT uRemotePort, 
		[in] LPWSTR szLocalInterface, 
		[in] USHORT uLocalPort,
		[in] INT ttl);

	STDMETHOD(SetMediaParameterDefaults)(
		BOOL bAduSpansMultiplePackets,
		BYTE payloadType,
		UINT uRtpTimeStampIncrementPerSecond,
		UINT uExpectedTimePerAduNanoseconds,
		BOOL bUpdateExistingBuffers);

	[helpstring("method SetRtpBandwidth")] HRESULT SetRtpBandwidth(
		[in] UINT uSessionBandwidth, BOOL bEnforce);

	[helpstring("method RegisterCallback")] HRESULT RegisterCallback([in] IRtpListenerEventConsumer *pEventConsumer);
	
	
	HRESULT SubscribeSsrc([in] UINT ssrc);

	HRESULT SubscribeSsrcAndGetPointerEx(
		UINT ssrc,
		[in] LPGUID guidJitterBuffer,
		BYTE payloadType,
		UINT uRtpTimeStampIncrementPerSecond,
		UINT uExpectedTimePerAduNanoseconds,
		[out] IPlayoutBuffer** ppPlayoutBuffer);

	[helpstring("method UnsubscribeSsrc")] HRESULT UnsubscribeSsrc([in] UINT ssrc);

	// 0709	
	[helpstring("ReserveNetworkAddress")] HRESULT ReserveNetworkAddressAndCreateSockets(
		[in] LPWSTR szRemoteAddress, 
		[in,out] LPWSTR szLocalInterface,
		[in] USHORT uMinLocalPort, 
		[in] USHORT uMaxLocalPort,
		[in] INT ttl);

	HRESULT ReserveNetworkAddress(
		[in] LPWSTR szRemoteAddress, 
		[in] LPWSTR szLocalInterface, 
		[in] USHORT uMinLocalPort, [in] USHORT uMaxLocalPort, [in,out] LPWSTR szLocalInterfaceOut, [in] INT cchLocal, [out] USHORT *puLocalPort);

	HRESULT GetNetworkParameter(
		[in,out] LPWSTR szRemoteAddress, INT cchRemoteAddress, [out] USHORT *puRemotePort, 
		[in,out] LPWSTR szLocalInterface, INT cchLocalAddress, [out] USHORT *puLocalPortBase, [out] INT* pTtl);
};

[
	object,
	uuid("1ABEA161-797F-4A07-93AD-7DACBE477F48"),
	helpstring("IRtpBufferedListener Interface"),
	pointer_default(unique)
]
__interface IRtpBufferedListener : IUnknown
{
	[helpstring("method GetDeliveryUnit")] HRESULT GetDeliveryUnit([in] UINT ssrc, [in,out] RtpParsedPacket*** pppDeliveryUnit, [in, out]UINT *pcPackets);
	
	
	[helpstring("method GetSubscribedSourcesCount")] HRESULT GetSubscribedSourcesCount([in,out] INT *pcSubscribed);
	[helpstring("method GetSubscribedSources")] HRESULT GetSubscribedSources([in,out] INT** pSubscribedSources, [in,out] INT* pcSubscribedSources);
	[helpstring("method GetActiveSourcesCount")] HRESULT GetActiveSourcesCount([in,out] INT *pcActive);
	[helpstring("method GetActiveSources")] HRESULT GetActiveSources([in,out] INT** pActiveSources, [in,out] INT* pcActiveSources);
	[helpstring("method GetActiveSourcesSafeArray")] HRESULT GetActiveSourcesSafeArray([out, satype(UINT)] SAFEARRAY** ppActiveSources);

	HRESULT SetJitterBufferLatency(UINT ssrc, UINT uLatency);
	HRESULT GetJitterBufferLatency(UINT ssrc, UINT* puLatency);

	HRESULT GetRtcpAttributes(UINT ssrc, SdesItems *pSdesItems);
	HRESULT SetMuted(UINT ssrc, INT bMuted);
	HRESULT GetMuted(UINT ssrc, INT *pbIsMuted);
	HRESULT GetSessionMemberInfo([in] UINT ssrc, [in,out] RtpSessionMemberInfo *pSessionMemberInfo, [in] BOOL bIncludeSdesItems);
	HRESULT SetPlayoutBufferGuid([in] LPGUID playoutBufferGuid);

	HRESULT SubscribeSsrcAndGetPointerEx(
		UINT ssrc, 
		[in] LPGUID guidJitterBuffer,
		BYTE payloadType,
		UINT uRtpTimeStampIncrementPerSecond,
		UINT uExpectedTimePerAduNanoseconds,
		[out] IPlayoutBuffer** ppPlayoutBuffer);
};
#endif //#if OLD_INTERFACES


