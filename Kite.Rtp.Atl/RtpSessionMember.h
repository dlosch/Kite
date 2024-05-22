#pragma once

#include <MMSystem.h>
#include "RtpPacket.h"
#include "RtpDefines.h"

[export]
struct RtpSessionMemberInfo
{
	UINT ssrc;

	UINT payloadType;

	UINT delaySinceLastPacketMillis;

	UINT interarrivalJitter;
	UINT packetsLost;
	UINT octetsLost;

	SdesItems *pSdesItems;
};

namespace Kite
{
	namespace Rtp
	{
		static UINT s_inactivityTimeoutMilliseconds = RTP_CONSTANTS_DEFAULT_INACTIVITY_TIMEOUT_MILLISECONDS;
	}
}

class CRtpSessionMember
{
private:
public:
	UINT m_ssrc;
	BOOL m_bIsSource;

	UINT m_uSeqNumCycleCount;
	USHORT m_uHighestReceivedSeqNum;

	LONG m_tTransitPrevious;

	SdesItems *m_pSdesItems;

	UINT m_payloadType;

	BOOL m_bRtpPacketsReceived;

	CComPtr<IPerformanceCounterWrapper> m_pPerfCounterNtpTimestampReceivedInLastSenderReport;
	CComPtr<IPerformanceCounterWrapper> m_pPerfCounterRtpTimestampReceivedInLastSenderReport;
	CComPtr<IPerformanceCounterWrapper> m_pPerfCounterSendersRtpPacketCount;
	CComPtr<IPerformanceCounterWrapper> m_pPerfCounterSendersRtpOctetCount;
	CComPtr<IPerformanceCounterWrapper> m_pPerfCounterRtpPacketsReceivedFromSource;
	CComPtr<IPerformanceCounterWrapper> m_pPerfCounterExtendedHighestSequenceNumberReceived;
	CComPtr<IPerformanceCounterWrapper> m_pPerfCounterInterarrivalJitter;
	CComPtr<IPerformanceCounterWrapper> m_pPerfCounterTimestampLastSRReceived;
	
	CComPtr<IPerformanceCounterWrapper> m_pPerfCounterLastSRReceivedAbsoluteTimeMilliseconds;

	CComPtr<IPerformanceCounterFactory> m_pPerfCounterFactory;

	CRtpSessionMember(UINT ssrc, BOOL bIsSender, IPerformanceCounterFactory *pFactory);
	~CRtpSessionMember();
	HRESULT SetIsActiveSource(void);

	UINT m_lastUpdateMillisecs;
	BOOL GetIsTimedOut(UINT currentTime);

	HRESULT CreateRR(BYTE* pBuffer, UINT *pcbOffset, UINT cbBufferLength);

	//////////////////////////////////////////////////////////////////////////
	
	STDMETHODIMP KeepAlive(void);
	HRESULT Update(SdesItems *pItems);
	HRESULT Update(RtpParsedPacket *pPacket);
	HRESULT Update(RtcpSenderReport *pPacket);
	HRESULT Update(RtcpReceiverReport *pPacket);
	HRESULT Update(RtcpBye *pPacket);

	HRESULT GetSdesItems(SdesItems *pItems);
	
	// Callee allocated
	HRESULT GetSourceInfo(RtpSessionMemberInfo *pInfo, BOOL bIncludeSdesItems);
};
