#ifndef IRTPSTATISTICS_H
#define IRTPSTATISTICS_H

[
	object,
	uuid("DC2F8E5E-17F2-4921-9804-F1EAFDD20843"),
	helpstring("IRtpReceiverStatistics Interface"),
	pointer_default(unique)
]
__interface IRtpReceiverStatistics : IUnknown
{
	HRESULT GetPacketLoss(UINT ssrc, [out] DOUBLE* pdblPacketLoss);
	HRESULT GetReceptionStatistics(UINT ssrc, [out] UINT *pcPacketsReceived, [out] UINT *pcPacketsLost, [out] UINT *pJitter);
	HRESULT GetPerformanceCounterPrefix(UINT ssrc, [in,out, size_is(cchPerfCounterPrefix)] LPWSTR szPerfCounterPrefix, INT cchPerfCounterPrefix);
};

[
	object,
	uuid("DC2F8E5F-17F2-4921-9804-F1EAFDD20843"),
	helpstring("IRtpSenderStatistics Interface"),
	pointer_default(unique)
]
__interface IRtpSenderStatistics : IUnknown
{
	// Own Packet stats
	HRESULT GetSenderStatistics([out] UINT *pcPacketsSent, [out] UINT *pcOctetsSent, [out] UINT *pMillisecs);
	// RRs
	HRESULT GetStatisticsForReceiver(UINT ssrcRRSource, [out] BYTE *pFractionLost, [out] UINT *pcCumulativeNumberOfPacketsLost, [out] UINT *pInterarrivalJitter);
	HRESULT GetPerformanceCounterPrefix(UINT ssrc, [in,out,size_is(cchPerfCounterPrefix)] LPWSTR szPerfCounterPrefix, INT cchPerfCounterPrefix);
};

#endif