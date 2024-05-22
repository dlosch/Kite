#ifndef DEBUGHELPERS_H
#define DEBUGHELPERS_H

#define DEBUG_PACKETS 0
#if DEBUG_PACKETS
#	define DebugHelpers_DebugPrintRtpParsedPacket(pPacket) \
	{ \
		ATLTRACE2("DebugHelpers_DebugPrintRtpParsedPacket \r\n"); \
		ATLTRACE2("Funtion %s, %s, %d \r\n", __FUNCTION__, __FILE__, __LINE__); \
		ATLTRACE2("SSRC 0x%x \r\n", pPacket->ssrc); \
		ATLTRACE2("TiumeStamp %d \r\n", pPacket->timestamp); \
		ATLTRACE2("SeqNum %d \r\n", pPacket->seqNum); \
		ATLTRACE2("cbData %d \r\n", pPacket->cbData); \
		ATLTRACE2("pPacket->marker %d \r\n", pPacket->marker); \
		ATLTRACE2("pPacket->pad %d \r\n", pPacket->pad); \
		ATLTRACE2("pPacket->ext %d \r\n", pPacket->ext); \
		ATLTRACE2("pPacket->cc %d \r\n", pPacket->cc); \
		ATLTRACE2("pPacket->payloadTye %d \r\n", pPacket->payloadType); \
		ATLTRACE2("########################################### \r\n"); \
	}
#else
#	define DebugHelpers_DebugPrintRtpParsedPacket(pPacket) __noop
#endif

#define DebugHelpers_DebugPrintSdesReport(pSdesItems) \
	{ \
		ATLTRACE2("DebugHelpers_DebugPrintSdesReport \r\n"); \
		ATLTRACE2("Funtion %s, %s, %d \r\n", __FUNCTION__, __FILE__, __LINE__); \
		ATLTRACE2("SSRC 0x%x, '%ud' \r\n", pSdesItems->ssrc, pSdesItems->ssrc); \
		ATLTRACE2("cname %s \r\n", pSdesItems->cname); \
		ATLTRACE2("name %s \r\n", pSdesItems->name); \
		ATLTRACE2("email %s \r\n", pSdesItems->email); \
		ATLTRACE2("pPacket->phone %s \r\n", pSdesItems->phone); \
		ATLTRACE2("pPacket->loc   %s \r\n", pSdesItems->loc); \
		ATLTRACE2("pPacket->tool  %s \r\n", pSdesItems->tool); \
		ATLTRACE2("pPacket->note  %s \r\n", pSdesItems->note); \
		ATLTRACE2("########################################### \r\n"); \
	}

#endif //DEBUGHELPERS_H