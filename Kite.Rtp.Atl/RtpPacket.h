#pragma once
#include "RtpDefines.h"

VOID BufferUtil_GetHostByteOrderUint(BYTE* pBuffer, INT cbOffset, UINT *pUint);
VOID BufferUtil_GetHostByteOrderUshort(BYTE* pBuffer, INT cbOffset, USHORT *pUshrt);
VOID BufferUtil_PutNetworkByteOrderUint(BYTE* pBuffer, INT cbOffset, UINT val);
VOID BufferUtil_PutNetworkByteOrderUshort(BYTE* pBuffer, INT cbOffset, USHORT val);

HRESULT RtcpSenderReportUtil_AllocateSRAndRRsWithHeader(BYTE** pBuffer, UINT *pcbBufferLength, /*UINT */ BYTE cRR, UINT ssrc);
HRESULT RtcpReceiverReportUtil_AllocateRRsWithHeader(BYTE** pBuffer, UINT* pcbBufferLength, /*UINT*/BYTE cRR, UINT ssrc);
HRESULT RtcpReceiverReportUtil_WriteRR(BYTE* pBuffer, UINT *pcbOffset, UINT cbBufferLength, 
									   UINT ssrcOfSource, 
									   UINT cPacketsSentBySource, UINT cPacketsReceivedFromSource,
									   UINT extendedHighestSequmReceived,
									   UINT interarrivalJitter,
									   UINT tsLastSR,
									   UINT delaySinceLastSR);

HRESULT RtcpSenderReportUtil_WriteSR(BYTE* pBuffer, UINT *pcbOffset, UINT cbBufferLength, 
									 LONGLONG lNtpTimestamp,
									 UINT rtpTimestamp,
									 UINT cSendersPackets,
									 UINT cbSent);

LONGLONG RtcpSenderReportUtil_GenerateNtpTimestamp();

HRESULT RtcpReportUtil_Write8ByteHeader(
	BYTE* pBuffer, UINT *pcbOffset, UINT cbBufferLength, BOOL pad, BYTE reportCount, BYTE payloadType, UINT cPacketLengthDwordExclFirstHeaderDword, UINT ssrc);

VOID RtcpReceiverReportUtil_PutPacketLossInfo(RtcpReceiverReport* pRR, BYTE fractionLost, UINT packetsLostHbo);

HRESULT RtcpSdesUtil_CreateSdesPacketWithHeader(BYTE** ppBuffer, UINT *pcbBuffer, BYTE *pbPadded /*, RtcpHeader** ppHeader*/, SdesItems* pItems, BOOL bIsLeightweightPacket);


HRESULT RtpPacketUtil_WriteRtpHeader(BYTE *pBuffer, UINT *pcbOffset, UINT cbBufferLength, 
									 BOOL bMarker,
									 //BYTE cc,
									 BYTE payloadType,
									 USHORT seqNum,
									 UINT timestamp,
									 UINT ssrc);

HRESULT RtcpByeUtil_CreateBye(BYTE **ppBuffer, UINT *pcbBuffer,
							  UINT ssrcLeaving,
							  LPTSTR szReasonPhrase);


VOID RtcpReceiverReportUtil_GetPacketLossInfo(RtcpReceiverReport* pRR, BYTE *pFractionLost, UINT *pPacketsLostHbo);

BYTE RtcpHeaderUtil_GetPacketType(BYTE* pBuffer, UINT cbOffset = 0);
USHORT RtcpHeaderUtil_GetPacketLength(BYTE* pBuffer, UINT cbOffset = 0);
UINT RtcpHeaderUtil_GetPacketLengthByte(BYTE* pBuffer, UINT cbOffset = 0);
BYTE RtcpHeader_GetItemCount(BYTE* pBuffer, UINT cbOffset = 0);

HRESULT RtcpSenderReportUtil_ParseSR(BYTE* pBuffer, /*UINT cbOffset, */UINT cbBuffer, /*[out]*/ RtcpSenderReport** ppSR);

HRESULT RtcpReceiverReportUtil_ParseRR(BYTE* pBuffer, UINT cbBuffer, RtcpReceiverReport** ppRR, UINT* pcReceiverReportCount);
HRESULT RtcpSdesReportUtil_ParseSdes(BYTE* pBuffer, /*UINT cbOffset, */UINT cbBuffer, /*[out]*/ SdesItems** ppSdesItems, UINT* pcSdesItems);

HRESULT RtpPacketUtil_ParseRtpPacket(BYTE* pBuffer, UINT cbLength, RtpParsedPacket** ppParsedPacket);
HRESULT RtpPacketUtil_FreeParsedRtpPacket(RtpParsedPacket* pPacket);

HRESULT RtcpByeUtil_ParseBye(BYTE* pBuffer, UINT cbBuffer, RtcpBye **ppBye);