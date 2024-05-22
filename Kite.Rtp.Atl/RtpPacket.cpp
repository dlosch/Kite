#include "StdAfx.h"
#include ".\rtppacket.h"

#include <sys/timeb.h>

// TODO Offset???
VOID RtcpReceiverReportUtil_PutPacketLossInfo(RtcpReceiverReport* pRR, BYTE fractionLost, UINT packetsLostHbo)
{
	pRR->cumulativeNumberOfPacketsLostWithFractionLost = htonl((fractionLost << 24 | packetsLostHbo & 0xFFFFFF));
}

VOID RtcpReceiverReportUtil_GetPacketLossInfo(RtcpReceiverReport* pRR, BYTE *pFractionLost, UINT *pPacketsLostHbo)
{
	UINT valueHbo = ntohl(pRR->cumulativeNumberOfPacketsLostWithFractionLost);
	(*pFractionLost) = (BYTE)&(valueHbo);
	(*pPacketsLostHbo) = (valueHbo & 0xFFFFFF);
}

VOID BufferUtil_GetHostByteOrderUint(BYTE* pBuffer, INT cbOffset, UINT *pUint)
{
	*pUint = ntohl(*(UINT*)(pBuffer + cbOffset));
}

VOID BufferUtil_GetHostByteOrderUshort(BYTE* pBuffer, INT cbOffset, USHORT *pUshrt)
{
	*pUshrt = ntohs(*(USHORT*)(pBuffer + cbOffset));
}

VOID BufferUtil_PutNetworkByteOrderUint(BYTE* pBuffer, INT cbOffset, UINT val)
{
	*(UINT*)(pBuffer + cbOffset) = htonl(val);
}

VOID BufferUtil_PutNetworkByteOrderUshort(BYTE* pBuffer, INT cbOffset, USHORT val)
{
	*(USHORT*)(pBuffer + cbOffset) = htons(val);
}

// diese art, den Header zu bef�llen, ist lauzt RFC1889 und RFC791 korrekt (Network Byte Order)
// Length2 (MSB), Length1(LSB), PayloadType, VersionPadRC
HRESULT RtcpSenderReportUtil_AllocateSRAndRRsWithHeader(BYTE** ppBuffer, UINT *pcbBufferLength, /*UINT*/BYTE cRR, UINT ssrc)
{
	if (cRR > 31) return E_INVALIDARG;

	// Header is ALWAYS extra, sending is done via multiple WSABUF
	*pcbBufferLength = RTP_CONSTANTS_RTCP_HEADER_SIZE + RTP_CONSTANTS_RTCP_SR_SIZE + (cRR * RTP_CONSTANTS_RTCP_RR_SIZE) /*+ 4 ???*/;
	*ppBuffer = (BYTE*)SAFE_ALLOC(*pcbBufferLength);

	// 2: PT, 3: V|P|SC, 0/1: htons-length
	// Compute Length
	// (((*pcbBufferLength) >> 2) - 1) Words minus 1 
	(*ppBuffer)[0] = 128 | (0xFF & cRR); // Pad is zero
	(*ppBuffer)[1] = RTCP_PACKET_TYPE_SR;
	BufferUtil_PutNetworkByteOrderUshort(*ppBuffer, 2, (((*pcbBufferLength) >> 2) - 1));

	// Write SSRC
	BufferUtil_PutNetworkByteOrderUint(*ppBuffer, 4, ssrc);

	return ((*ppBuffer == NULL) ? E_OUTOFMEMORY : S_OK);
}

HRESULT RtcpReceiverReportUtil_AllocateRRsWithHeader(BYTE** ppBuffer, UINT *pcbBufferLength, /*UINT*/ BYTE cRR, UINT ssrc)
{
	CheckPointer(ppBuffer, E_POINTER);
	CheckPointer(pcbBufferLength, E_POINTER);
	if (cRR == 0) 
	{
		(*ppBuffer) = NULL;
		(*pcbBufferLength) = 0;
		return S_FALSE;
	}

	// Header is ALWAYS extra
	*pcbBufferLength = RTP_CONSTANTS_RTCP_HEADER_SIZE + (cRR * RTP_CONSTANTS_RTCP_RR_SIZE);
	*ppBuffer = (BYTE*)SAFE_ALLOC(*pcbBufferLength);

	(*ppBuffer)[0] = 128 | (0xFF & cRR); // Pad is zero
	(*ppBuffer)[1] = RTCP_PACKET_TYPE_RR;
	BufferUtil_PutNetworkByteOrderUshort(*ppBuffer, 2, (((*pcbBufferLength) >> 2) - 1));

	return ((*ppBuffer == NULL) ? E_OUTOFMEMORY : S_OK);
}

HRESULT RtcpReceiverReportUtil_WriteRR(BYTE* pBuffer, UINT *pcbOffset, UINT cbBufferLength, 
										   UINT ssrcOfSource, 
										   UINT cPacketsSentBySource, UINT cPacketsReceivedFromSource,
										   UINT extendedHighestSequmReceived,
										   UINT interarrivalJitter,
										   UINT tsLastSR,
										   UINT delaySinceLastSR)
{
	CheckPointer(pBuffer, E_POINTER);
	CheckPointer(pcbOffset, E_POINTER);
	if (cbBufferLength - *pcbOffset < RTP_CONSTANTS_RTCP_RR_SIZE) return E_INVALIDARG;
	if (ssrcOfSource == 0) return E_UNEXPECTED;

	// write SSRC
	BufferUtil_PutNetworkByteOrderUint(pBuffer, *pcbOffset, ssrcOfSource);
	*pcbOffset += 4;
	// calculate Fraction

	*pcbOffset += 4;

	BufferUtil_PutNetworkByteOrderUint(pBuffer, *pcbOffset, extendedHighestSequmReceived);
	*pcbOffset += 4;

	BufferUtil_PutNetworkByteOrderUint(pBuffer, *pcbOffset, interarrivalJitter);
	*pcbOffset += 4;

	BufferUtil_PutNetworkByteOrderUint(pBuffer, *pcbOffset, tsLastSR);
	*pcbOffset += 4;

	BufferUtil_PutNetworkByteOrderUint(pBuffer, *pcbOffset, delaySinceLastSR);
	*pcbOffset += 4;

	return S_OK;
}

HRESULT RtcpSenderReportUtil_WriteSR(BYTE* pBuffer, UINT *pcbOffset, UINT cbBufferLength, 
									 LONGLONG lNtpTimestamp,
									 UINT rtpTimestamp,
									 UINT cSendersPackets,
									 UINT cbSent)
{
	CheckPointer(pBuffer, E_POINTER);
	CheckPointer(pcbOffset, E_POINTER);
	CheckPointer(cbBufferLength, E_INVALIDARG);
	if ((cbBufferLength - *pcbOffset) < RTP_CONSTANTS_RTCP_SR_SIZE) return E_INVALIDARG;

	BufferUtil_PutNetworkByteOrderUint(pBuffer, *pcbOffset, (lNtpTimestamp >> 32));
	(*pcbOffset) += 4;
	BufferUtil_PutNetworkByteOrderUint(pBuffer, *pcbOffset, (UINT)(lNtpTimestamp & 0xFFFFFFFF));
	(*pcbOffset) += 4;
	BufferUtil_PutNetworkByteOrderUint(pBuffer, *pcbOffset, rtpTimestamp);
	(*pcbOffset) += 4;
	BufferUtil_PutNetworkByteOrderUint(pBuffer, *pcbOffset, cSendersPackets);
	(*pcbOffset) += 4;
	BufferUtil_PutNetworkByteOrderUint(pBuffer, *pcbOffset, cbSent);
	(*pcbOffset) += 4;
	
	return S_OK;
}


// 2207520000
#define SECS_BEFORE_UNIX_SINCE_1900 (LONGLONG)2208988800u
LONGLONG RtcpSenderReportUtil_GenerateNtpTimestamp()
{

	// int64
	_timeb utc1970;
	_ftime(&utc1970);
	
	// TODO HIGH fraction berrechnen
	ASSERT((utc1970.time + SECS_BEFORE_UNIX_SINCE_1900) < (UINT)(~0));
	return (utc1970.time + SECS_BEFORE_UNIX_SINCE_1900) << 32 | ((UINT)0);

}

HRESULT RtcpReportUtil_Write8ByteHeader(
	BYTE* pBuffer, UINT *pcbOffset, UINT cbBufferLength, 
	BOOL bPad, BYTE reportCount, BYTE payloadType, UINT cPacketLengthDwordExclFirstHeaderDword, 
	UINT ssrc)
{
	CheckPointer(pBuffer, E_POINTER);
	CheckPointer(pcbOffset, E_POINTER);
	CheckPointer(cbBufferLength, E_INVALIDARG);
	if ((cbBufferLength - (*pcbOffset)) < RTP_CONSTANTS_RTCP_HEADER_SIZE) return E_INVALIDARG;
	if (reportCount > 31) return E_INVALIDARG;

	BYTE verPadRC = 128; // version
	if (bPad) verPadRC += 32; // Padding
	verPadRC += reportCount; // rc
	pBuffer[(*pcbOffset)++] = verPadRC;
	pBuffer[(*pcbOffset)++] = payloadType;

	BufferUtil_PutNetworkByteOrderUshort(pBuffer, *pcbOffset, cPacketLengthDwordExclFirstHeaderDword);
	(*pcbOffset) += 2;

	//if (cbHeader == 8)
	{
		BufferUtil_PutNetworkByteOrderUint(pBuffer, *pcbOffset, ssrc);
		(*pcbOffset) += 4;
	}

	return S_OK;
}


HRESULT RtcpSdesUtil_CreateSdesPacketWithHeader(BYTE** ppBuffer, UINT *pcbBuffer, BYTE *pPadded /*, RtcpHeader** ppHeader*/, SdesItems* pItems, BOOL bIsLeightweightPacket)
{
	CheckPointer(ppBuffer, E_POINTER);
	CheckPointer(pcbBuffer, E_POINTER);
	CheckPointer(pPadded, E_POINTER);
	CheckPointer(pItems, E_POINTER);

	UINT cbItemLength = 0;
	INT i = bIsLeightweightPacket ? 0 : 6;
	UINT cbItem = 0;
	for (; i >= 0; i--)
	{
		cbItem = _tcslen(((TCHAR*)pItems + i * RTP_COSTANTS_RTCP_SDES_ITEM_VALUE_MAXLENGTH));
		if (cbItem > 0)
			cbItemLength += (cbItem + 2);
	}

	BYTE cbPad = 0;
	if (cbItemLength % 4)
	{
		cbPad = (4 - (cbItemLength % 4)); 
	}
	(*pPadded) = cbPad;

	(*pcbBuffer) = (cbItemLength + cbPad + RTP_CONSTANTS_RTCP_HEADER_SIZE);
	(*ppBuffer) = (BYTE*)SAFE_ALLOC(*pcbBuffer);
	CheckPointer(*ppBuffer, E_OUTOFMEMORY);
	UINT cbOffset = 0;
	HRESULT hr = RtcpReportUtil_Write8ByteHeader(*ppBuffer, &cbOffset, *pcbBuffer, FALSE, 1, RTCP_PACKET_TYPE_SDES, (((cbItemLength + cbPad + RTP_CONSTANTS_RTCP_HEADER_SIZE) / 4) - 1), pItems->ssrc);

	BYTE* pBufferPtr = (*ppBuffer + cbOffset /*+ RTP_CONSTANTS_RTCP_HEADER_SIZE*/);
	INT numItems = (bIsLeightweightPacket ? 1 : 7);
	for (i = 0; i < numItems; i++)
	{
		TCHAR* szItem = ((TCHAR*)pItems + i * RTP_COSTANTS_RTCP_SDES_ITEM_VALUE_MAXLENGTH);

		cbItem = _tcslen(((TCHAR*)pItems + i * RTP_COSTANTS_RTCP_SDES_ITEM_VALUE_MAXLENGTH));
		if (cbItem)
		{
			(*pBufferPtr) = (i+1);
			*(pBufferPtr + 1) = cbItem;
			CopyMemory(pBufferPtr + 2, ((TCHAR*)pItems + i * RTP_COSTANTS_RTCP_SDES_ITEM_VALUE_MAXLENGTH), cbItem);
			pBufferPtr += (cbItem + 2);
		}
	}

	return S_OK;
}
//////////////////////////////////////////////////////////////////////////

// Padding is Currently not supported
// Only one SSRC/CSRC field
// pcbOffset will be incremented by 12
HRESULT RtpPacketUtil_WriteRtpHeader(BYTE *pBuffer, UINT *pcbOffset, UINT cbBufferLength, 
									 BOOL bMarker,
									 //BYTE cc,
									 BYTE payloadType,
									 USHORT seqNum,
									 UINT timestamp,
									 UINT ssrc)
{
	CheckPointer(pBuffer, E_POINTER);
	CheckPointer(pcbOffset, E_POINTER);
	if ((cbBufferLength - (*pcbOffset)) < RTP_CONSTANTS_RTP_FIXED_HEADER_SIZE) return E_INVALIDARG;
	if (payloadType > 127) return E_INVALIDARG;

	BYTE* pBufferPtr = pBuffer + (*pcbOffset);
	ZeroMemory(pBufferPtr, RTP_CONSTANTS_RTP_FIXED_HEADER_SIZE);

	// Put Version
	pBuffer[0] |= 128;

	if (bMarker) pBufferPtr[1] |= (BYTE)0x80;
	
	pBufferPtr[0] |= 0; 

	// payload Type
	pBufferPtr[1] &= (BYTE)(~0x7F);
	pBufferPtr[1] |= payloadType;

	// Put SeqNUm
	BufferUtil_PutNetworkByteOrderUshort(pBufferPtr, 2, seqNum);	

	// Put ts
	BufferUtil_PutNetworkByteOrderUint(pBufferPtr, 4, timestamp);

	// Put SSRC
	BufferUtil_PutNetworkByteOrderUint(pBufferPtr, 8, ssrc);

	(*pcbOffset) += 12;

	// DEBUG
	RtpParsedPacket *pParsedPacket = NULL;
	RtpPacketUtil_ParseRtpPacket(pBuffer, *pcbOffset, &pParsedPacket);
	SAFE_FREE(pParsedPacket);

	return S_OK;
}

HRESULT RtcpByeUtil_CreateBye(BYTE **ppBuffer, UINT *pcbBuffer,
							 UINT ssrcLeaving,
							 LPTSTR szReasonPhrase)
{
	CheckPointer(ppBuffer, E_POINTER);
	CheckPointer(pcbBuffer, E_POINTER);
	
	UINT cbPad = 3;
	(*pcbBuffer) = 12;
	UINT cReason = 0;
	if (szReasonPhrase)
	{
		cReason = _tcslen(szReasonPhrase);
		if (cReason > 255) cReason = 255;
		
		if (cReason > 3)
		{
			cbPad = (cReason - 3) % 4;
		}
		else
		{
			cbPad = 3 - cReason;
		}

		(*pcbBuffer) = RTP_CONSTANTS_RTCP_HEADER_SIZE + 1 /*StringLength*/ + cReason + cbPad;
	}
	ASSERT(!((*pcbBuffer) % 4));

	(*ppBuffer) = (BYTE*)SAFE_ALLOC((*pcbBuffer));
	CheckPointer(*ppBuffer, E_OUTOFMEMORY);

	UINT cbOffset = 0;
	HRESULT hr = RtcpReportUtil_Write8ByteHeader(*ppBuffer, &cbOffset, *pcbBuffer, !!(cbPad), 1, RTCP_PACKET_TYPE_BYE, (((*pcbBuffer) >> 2) - 1), ssrcLeaving);
	VALHR(hr);

	(*ppBuffer)[cbOffset++] = cReason;
	strncpy((CHAR*)((*ppBuffer)[cbOffset]), szReasonPhrase, cReason);

	// TODO
	if (cbPad)
	{
		(*ppBuffer)[(*pcbBuffer) - 1] = cbPad;
	}

	return S_OK;
}



//////////////////////////////////////////////////////////////////////////

// Steht an 0,1 in Nbo
USHORT RtcpHeaderUtil_GetPacketLength(BYTE* pBuffer, UINT cbOffset)
{
	if (!pBuffer) return 0;
	return ntohs(*(USHORT*)(pBuffer + cbOffset + 2));
}

UINT RtcpHeaderUtil_GetPacketLengthByte(BYTE* pBuffer, UINT cbOffset)
{
	if (!pBuffer) return 0;
	UINT cWordsMinusOne = (UINT)ntohs(*(USHORT*)(pBuffer + cbOffset + 2));
	return ((cWordsMinusOne + 1) << 2);
}

BYTE RtcpHeaderUtil_GetPacketType(BYTE* pBuffer, UINT cbOffset)
{
	ASSERT(pBuffer);
	return pBuffer[1 + cbOffset];
}

BYTE RtcpHeader_GetItemCount(BYTE* pBuffer, UINT cbOffset)
{
	ASSERT(pBuffer);
	return pBuffer[0 + cbOffset] & 0x1F;
}

// Caller has to free RtcpSenderReport using SAFE_FREE (Continuous Buffer)
HRESULT RtcpSenderReportUtil_ParseSR(BYTE* pBuffer, /*UINT cbOffset, */UINT cbBuffer, /*[out]*/ RtcpSenderReport** ppSR)
{
	// anzahl RRs
	BYTE cItems = RtcpHeader_GetItemCount(pBuffer);

	// TODO VERY HIGH: Diesen Krampf mit den Buffern bitte testen. Das stinkt
	// Speicher belegen 
	UINT cbBufferLength = sizeof(RtcpSenderReport) + (cItems * sizeof(RtcpReceiverReport));
	*ppSR = (RtcpSenderReport*)SAFE_ALLOC(cbBufferLength);
	CheckPointer(*ppSR, E_OUTOFMEMORY);
	
	(*ppSR)->pReceiverReports = (RtcpReceiverReport*)(((BYTE*)(*ppSR)) + sizeof(RtcpSenderReport));
	(*ppSR)->cReceiverReports = cItems;

	// Parse SR
	
	RtcpSenderReport* pSR = (RtcpSenderReport*)(pBuffer + (RTP_CONSTANTS_RTCP_HEADER_SIZE >> 1));
	(*ppSR)->ssrc = ntohl(pSR->ssrc); 

	(*ppSR)->ntpTimeStampMsw = ntohl(pSR->ntpTimeStampMsw);
	(*ppSR)->ntpTimeStampLsw = ntohl(pSR->ntpTimeStampLsw);
	(*ppSR)->rtpTimeStamp = ntohl(pSR->rtpTimeStamp);
	(*ppSR)->sendersPacketCount = ntohl(pSR->sendersPacketCount);
	(*ppSR)->sendersOctetCount = ntohl(pSR->sendersOctetCount); 

	// Parse RRs, if any
	for (BYTE i = 0; i < cItems; i++)
	{
		RtcpReceiverReport *pRR = (RtcpReceiverReport*)(pBuffer 
			+ RTP_CONSTANTS_RTCP_HEADER_SIZE 
			+ RTP_CONSTANTS_RTCP_SR_SIZE 
			+ (i * RTP_CONSTANTS_RTCP_RR_SIZE));

		(*ppSR)->pReceiverReports[i].ssrc = ntohl(pRR->ssrc);
		(*ppSR)->pReceiverReports[i].cumulativeNumberOfPacketsLostWithFractionLost = ntohl(pRR->cumulativeNumberOfPacketsLostWithFractionLost);
		(*ppSR)->pReceiverReports[i].extendedHighestSequmReceived = ntohl(pRR->extendedHighestSequmReceived);
		(*ppSR)->pReceiverReports[i].interArrivalJitter = ntohl(pRR->interArrivalJitter);
		(*ppSR)->pReceiverReports[i].lastSR = ntohl(pRR->lastSR);
		(*ppSR)->pReceiverReports[i].delaySinceLastSR = ntohl(pRR->delaySinceLastSR);
	}
	
	return S_OK;
}

// Caller has to free Array using SAFE_POINTER_ARRAY_FREE_ONLY_FIRST_ITEM
HRESULT RtcpSdesReportUtil_ParseSdes(BYTE* pBuffer, /*UINT cbOffset, */UINT cbBuffer, /*[out]*/ SdesItems** ppSdesItems, UINT* pcSdesItems)
{
	BYTE cItems = RtcpHeader_GetItemCount(pBuffer);
	ASSERT(0 < cItems);
	ASSERT(!(cbBuffer % 4));

	(*ppSdesItems) = (SdesItems*)SAFE_ALLOC(cItems * sizeof(SdesItems));
	CheckPointer(*ppSdesItems, E_OUTOFMEMORY);
	
	// Skip only 4 Bytes, since SSRC belongs to Sdes
	BYTE* pBufferPtr = pBuffer + (RTP_CONSTANTS_RTCP_HEADER_SIZE >> 1);
	
	ASSERT(cItems == 1);

	BYTE i; 
	for (i = 0; i < cItems; i++)
	{
		// Parse Sdes
		// SSRC
		(*ppSdesItems)[i].ssrc = ntohl(*((UINT*)pBufferPtr));
		pBufferPtr += 4;

		while(pBufferPtr < (pBuffer + cbBuffer))
		{
			if ((*pBufferPtr) == 0)
			{
				INT cbLeft = cbBuffer - (pBufferPtr - pBuffer);
				INT cbLeftToByteAlign = (cbLeft % 4);
				if (cbLeftToByteAlign == 0) cbLeftToByteAlign = 4;

				if (cbLeft == cbLeftToByteAlign) 
				{
					// End Of Buffer
					(*pcSdesItems)++;
					return S_OK;
				}

				// 1-4 nullbytes, entweder kommt hinterher noch ein weiterer NBlock, oder nicht
				for (INT i = 0; i < cbLeftToByteAlign; i++)
				{
					if (*pBufferPtr != 0)
					{
						ASSERT(0);
					}
					*pBufferPtr++;
				}
				break; // while 
			}

			BYTE type = (*pBufferPtr++);
			BYTE cbLength = (*pBufferPtr++);

			if (type < 1 || type > 7) 
			{
				SAFE_FREE(ppSdesItems);
				(*pcSdesItems) = 0;
				return E_FAIL;
			}
			CopyMemory( ((((BYTE*)&(*ppSdesItems)[i]) + ((type - 1) * RTP_COSTANTS_RTCP_SDES_ITEM_VALUE_MAXLENGTH))), pBufferPtr, cbLength);
			pBufferPtr += (cbLength);
		}

		(*pcSdesItems)++;
	}
	ASSERT(*pcSdesItems == cItems);

	return S_OK;

}

// Caller has to free *ppRR using SAFE_FREE
HRESULT RtcpReceiverReportUtil_ParseRR(BYTE* pBuffer, UINT cbBuffer, RtcpReceiverReport** ppRR, UINT* pcReceiverReportCount)
{
	CheckPointer(ppRR, E_POINTER);
	CheckPointer(pcReceiverReportCount, E_POINTER);

	BYTE cItems = RtcpHeader_GetItemCount(pBuffer);
	
	if (cItems == 0) 
	{
		(*ppRR) = NULL;
		(*pcReceiverReportCount) = 0;
		return S_FALSE;
	}

	UINT cbBufferLength = (cItems * sizeof(RtcpReceiverReport));
	(*ppRR) = (RtcpReceiverReport*)SAFE_ALLOC(cbBufferLength);
	CheckPointer(*ppRR, E_OUTOFMEMORY);
	
	for (BYTE i = 0; i < cItems; i++)
	{
		RtcpReceiverReport *pRR = (RtcpReceiverReport*)
			(pBuffer 
			+ RTP_CONSTANTS_RTCP_HEADER_SIZE 
			+ (i * RTP_CONSTANTS_RTCP_RR_SIZE));

		((*ppRR)[i]).ssrc = ntohl(pRR->ssrc);
		((*ppRR)[i]).cumulativeNumberOfPacketsLostWithFractionLost = ntohl(pRR->cumulativeNumberOfPacketsLostWithFractionLost);
		((*ppRR)[i]).extendedHighestSequmReceived = ntohl(pRR->extendedHighestSequmReceived);
		((*ppRR)[i]).interArrivalJitter = ntohl(pRR->interArrivalJitter);
		((*ppRR)[i]).lastSR = ntohl(pRR->lastSR);
		((*ppRR)[i]).delaySinceLastSR = ntohl(pRR->delaySinceLastSR);
	}

	(*pcReceiverReportCount) = cItems;

	return S_OK;
}

//////////////////////////////////////////////////////////////////////////
// Parse RtpData
// Caller has to free *ppParsedPacket using SAFE_FREE
HRESULT RtpPacketUtil_ParseRtpPacket(BYTE* pBuffer, UINT cbLength, RtpParsedPacket** ppParsedPacket)
{
	CheckPointer(pBuffer, E_POINTER);	
	CheckPointer(ppParsedPacket, E_POINTER);
	ASSERT(cbLength >= RTP_CONSTANTS_RTP_FIXED_HEADER_SIZE);

	if ((pBuffer[0] & 0xC0) != 0x80)
	{
		ATLTRACE2("!!!!! SEVERE ERROR: Version of Rtp Packet is NOT 2: 0x%x \r\n", pBuffer[0]);
	}

	// One allocation for RtpParsedPacket Struct and DataBuffer
	(*ppParsedPacket) = (RtpParsedPacket*)SAFE_ALLOC(cbLength - RTP_CONSTANTS_RTP_FIXED_HEADER_SIZE + sizeof(RtpParsedPacket));
	CheckPointer(*ppParsedPacket, E_OUTOFMEMORY);

	// Parse Marker
	(*ppParsedPacket)->marker = !!(pBuffer[1] & 0x80); // 128, leftMost Bit
	(*ppParsedPacket)->payloadType = (pBuffer[1] & 0x7F); // 127
	(*ppParsedPacket)->pad = !!(pBuffer[0] & 0x20); // 32
	(*ppParsedPacket)->ext = !!(pBuffer[0] & 0x10); // 16
	(*ppParsedPacket)->cc = (UINT)(pBuffer[0] & 0xF); // 15

	// Parse SeqNum, pos 0,1
	(*ppParsedPacket)->seqNum = ntohs(*(USHORT*)(pBuffer + 2));

	// Parse TS
	(*ppParsedPacket)->timestamp = ntohl(*(UINT*)(pBuffer + 4));

	// Parse SSRC
	(*ppParsedPacket)->ssrc = ntohl(*(UINT*)(pBuffer + 8));

	// CSRCS + Header ext
	UINT cbPacketStartPayloadOffset = 0;
	UINT cbPaddedAtEnd = 0;

	// Support multiple CSRC
	if ((*ppParsedPacket)->cc > 0)
	{
		ASSERT(((*ppParsedPacket)->cc > 0));
		cbPacketStartPayloadOffset += (4 * (*ppParsedPacket)->cc);
	}

	// Check for Header Ext
	if ((*ppParsedPacket)->ext)
	{
		ASSERT((*ppParsedPacket)->ext);
		/*
			The header extension contains a 16-bit length field that
			counts the number of 32-bit words in the extension, excluding the
			four-octet extension header (therefore zero is a valid length). Only
			a single extension may be appended to the RTP data header. To allow
			multiple interoperating implementations to each experiment
			independently with different header extensions, or to allow a
			particular implementation to experiment with more than one type of
			header extension, the first 16 bits of the header extension are left
			open for distinguishing identifiers or parameters.
		*/
		BYTE *pHeaderExtStart = pBuffer + (RTP_CONSTANTS_RTP_FIXED_HEADER_SIZE + cbPacketStartPayloadOffset);
		USHORT uHeaderId = *(USHORT*)pHeaderExtStart;
		pHeaderExtStart += sizeof(USHORT);
		USHORT uHeaderLength = *(USHORT*)pHeaderExtStart;
		USHORT uHeaderLengthByte = (1 + uHeaderLength) << 2;

		cbPacketStartPayloadOffset += uHeaderLengthByte;
	}

	// Check for Padding
	if ((*ppParsedPacket)->pad)
	{
		ASSERT(((*ppParsedPacket)->pad));
		/*UINT */cbPaddedAtEnd = pBuffer[cbLength - 1];

		if (cbPaddedAtEnd >= (cbLength - RTP_CONSTANTS_RTP_FIXED_HEADER_SIZE))
		{
			ASSERT(0);
		}

#ifdef DEBUG	
		// Debug: check that padding contains zeroes
		for(UINT u = 1; u < (cbPaddedAtEnd); u++)
		{
			ASSERT(pBuffer[cbLength - 1 - u] == 0);
		}
#endif
	}
	//////////////////////////////////////////////////////////////////////////
	
	ASSERT((cbLength >= (RTP_CONSTANTS_RTP_FIXED_HEADER_SIZE + cbPacketStartPayloadOffset + cbPaddedAtEnd)));
	
	if (cbLength > (RTP_CONSTANTS_RTP_FIXED_HEADER_SIZE + cbPacketStartPayloadOffset + cbPaddedAtEnd)) 
	{
		(*ppParsedPacket)->pData = (BYTE*)(*ppParsedPacket) + sizeof(RtpParsedPacket);
		(*ppParsedPacket)->cbData = cbLength - (RTP_CONSTANTS_RTP_FIXED_HEADER_SIZE + cbPacketStartPayloadOffset + cbPaddedAtEnd);
	
		BYTE *pPayloadPtr = pBuffer + (RTP_CONSTANTS_RTP_FIXED_HEADER_SIZE + cbPacketStartPayloadOffset);

		// Copy the Data Chunk
		CopyMemory(
			(*ppParsedPacket)->pData, 
			pPayloadPtr, 
			(*ppParsedPacket)->cbData);

		// assumes CSRC = 0, Pad = 0, ext = 0
		ASSERT(((*ppParsedPacket)->pData) == (((BYTE*)*ppParsedPacket) + sizeof(RtpParsedPacket)));
	}
	else
	{
		(*ppParsedPacket)->cbData = 0;
		(*ppParsedPacket)->pData = NULL;
	}

	return S_OK;
}

HRESULT RtpPacketUtil_FreeParsedRtpPacket(RtpParsedPacket* pPacket)
{
	SAFE_FREE(pPacket);
	return NOERROR;
}

// Bye Packets
// Continuous Buffer, need to be freed with SAFE_FREE
HRESULT RtcpByeUtil_ParseBye(BYTE* pBuffer, UINT cbBuffer, RtcpBye **ppBye)
{
	CheckPointer(pBuffer, E_POINTER);
	CheckPointer(ppBye, E_POINTER);
	if (cbBuffer < RTP_CONSTANTS_RTCP_HEADER_SIZE) return E_INVALIDARG;

	// Get Ssrc/csrc Count
	BYTE cItems = RtcpHeader_GetItemCount(pBuffer);
	UINT cbPacket = RtcpHeaderUtil_GetPacketLengthByte(pBuffer);

	UINT cchByePhrase = 0;
	if (cbPacket > (cItems * sizeof(UINT) + 4))
	{
		// Contains Reason Phrase
		cchByePhrase = *(pBuffer + (4 + (4 * cItems)));
	}

	(*ppBye) = (RtcpBye*)SAFE_ALLOC(sizeof(RtcpBye) + sizeof(UINT) * cItems + sizeof(CHAR) * cchByePhrase);
	CheckPointer(*ppBye, E_OUTOFMEMORY);

	(*ppBye)->pCsrc = (UINT*)((*ppBye) + sizeof(RtcpBye));
	(*ppBye)->byePhrase = (LPSTR)((*ppBye) + (sizeof(RtcpBye) + (cItems * sizeof(UINT))));

	BufferUtil_GetHostByteOrderUint(pBuffer, 4, &((*ppBye)->ssrc));

	BYTE b;
	for (b = 1; b < cItems; b++)
	{
		BufferUtil_GetHostByteOrderUint(pBuffer, 4 + (b * 4), &((*ppBye)->pCsrc[b - 1]));
	}
	
	(*ppBye)->cchByePhrase = cchByePhrase;
	CopyMemory(((*ppBye)->byePhrase), (pBuffer + (4 + (4 * cItems)) + 1), cchByePhrase);

	return S_OK;
}