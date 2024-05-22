#ifndef IRTPBUFFEREDLISTENERFILTER_H
#define IRTPBUFFEREDLISTENERFILTER_H

/*
Folgende Settings m�ssen von der App konfiguriert werden:
- Frames Per Second
*/

#if !EXTERNAL_INTERFACES
DECLARE_INTERFACE_(IRtpBufferedListenerFilter, IUnknown) 
{
	STDMETHOD(SetNetworkParameter)(THIS_ 
		LPWSTR szRemoteAddress, 
		USHORT uRemotePort, 
		LPWSTR szLocalInterface, 
		USHORT uLocalInterface,
		INT ttl);

	STDMETHOD(SetMediaParameterDefaults)(THIS_ 
		BOOL bAduSpansMultiplePackets,
		BYTE payloadType,
		UINT uRtpTimeStampIncrementPerSecond,
		UINT uExpectedTimePerAduNanoseconds);

	STDMETHOD(SetOutputMediaType)(THIS_ AM_MEDIA_TYPE *pMediaType);

	//////////////////////////////////////////////////////////////////////////
	STDMETHOD(SetRtpBandwidth)(THIS_ UINT uSessionBandwidth, BOOL bEnforce);

	STDMETHOD(SetJitterBufferParameter)(UINT ssrc, UINT uLatency);

	STDMETHOD(SelectActiveSourceForOutputPin)(THIS_ UINT index, UINT ssrc) PURE;
	STDMETHOD(AddOutputPin)(THIS_ /*out*/ INT *pIndex) PURE;
	STDMETHOD(AddOutputPinForActiveSource)(THIS_ UINT ssrc, INT *pIndex) PURE;
	STDMETHOD(RemoveOutputPin)(THIS_ UINT index) PURE;

	STDMETHOD(RegisterEventHandler)(THIS_ IRtpBufferedListenerFilterEventConsumer *pEventConsumer) PURE;
	STDMETHOD(RegisterEventHandlerEx)(THIS_ IRtpBufferedListenerFilterEventConsumerEx *pEventConsumerEx) PURE;

	STDMETHOD(GetSubscribedSourcesCount)(INT *pcSubscribed);
	STDMETHOD(GetSubscribedSources)(INT** pSubscribedSources, INT* pcSubscribedSources);
	STDMETHOD(GetActiveSourcesCount)(INT *pcActive);
	STDMETHOD(GetActiveSources)(INT** pActiveSources, INT* pcActiveSources);

	STDMETHOD(SetAutoSubscribeActiveSources)(BOOL bValue);
	STDMETHOD(GetAutoSubscribeActiveSources)(BOOL *pbValue);

	// Test
	STDMETHOD(GetActiveSourcesSafeArray)(SAFEARRAY** ppSafeArray);

	// 0809
	STDMETHOD(SetRtpPayloadPacketizer)(
		THIS_
		IRtpPayloadPacketizer *pPacketizer);

	STDMETHOD(ReserveNetworkAddress)(
		THIS_ /*[in]*/ LPWSTR szRemoteAddress, 
		/*[in,out]*/ LPWSTR szLocalAddress,
		USHORT uLocalMinPort,
		USHORT uLocalMaxPort,
		LPWSTR szLocalOut, INT cchLocal, USHORT *puLocal);


	STDMETHOD(GetNetworkParameter)(
		THIS_
		LPWSTR szRemoteAddress, INT cchRemoteAddress, USHORT *puRemotePort, 
		LPWSTR szLocalInterface, INT cchLocalAddress, USHORT *puLocalPortBase, INT* pTtl);

	STDMETHOD(SetJitterBufferLatency)(THIS_ UINT ssrc, UINT uLatency);
	STDMETHOD(GetJitterBufferLatency)(THIS_ UINT ssrc, UINT* puLatency);

	STDMETHOD(GetRtcpAttributes)(THIS_ UINT ssrc, SdesItems *pSdesItems);
	STDMETHOD(SetMuted)(THIS_ UINT ssrc, INT bMuted);
	STDMETHOD(GetMuted)(THIS_ UINT ssrc, INT *pbIsMuted);

	STDMETHOD(SetPinCount)(THIS_ INT pinCount);
	STDMETHOD(GetPinCount)(THIS_ INT *pPinCount);
	STDMETHOD(GetPinIndexForSource)(THIS_ UINT ssrc, INT *pIndex);
};
#endif

#endif
