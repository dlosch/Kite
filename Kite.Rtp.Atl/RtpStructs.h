#pragma once
#ifndef RTPSTRUCTS_H
#define RTPSTRUCTS_H

#include "RtpDefines.h"
//0                   1                   2                   3
//0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//|V=2|P|X|  CC   |M|     PT      |       sequence number         |
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//|                           timestamp                           |
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//|           synchronization source (SSRC) identifier            |
//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
//|            contributing source (CSRC) identifiers             |
//|                             ....                              |
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//

// 8 * 4 == 32 Byte
////////[export]
////////struct RtpParsedPacket
////////{
////////	BOOL marker;
////////	BOOL pad;
////////	BOOL ext;
////////	// messes up alignment
////////	/*BYTE */ UINT cc;
////////
////////	UINT timestamp;
////////
////////	UINT ssrc;
////////
////////	// align on 4 bytes
////////	USHORT seqNum;
////////	USHORT cbData;
////////
////////	BYTE* pData;
////////
////////	//VOID FreeDataBuffer()
////////	//{
////////	//	// will be Freed when the struct is freeds using SAFE_FREE
////////	//	pData = NULL;
////////	//}
////////};

//////////////////////////////////////////////////////////////////////////
enum RTCP_PACKET_TYPE
{
	RTCP_PACKET_TYPE_SR = 200,
	RTCP_PACKET_TYPE_RR = 201,
	RTCP_PACKET_TYPE_SDES = 202,
	RTCP_PACKET_TYPE_BYE = 203,
	RTCP_PACKET_TYPE_APP = 204,

	// [RFC2032]  Turletti, T., and C. Huitema, " RTP Payload Format for H.261
	//full INTRA-frame request 192	[RFC2032]
	RTCP_PACKET_TYPE_RRC_2032_FIR_FULL_INTRA_FRAME_REQUEST = 192,       
	// negative acknowledgement 193      [RFC2032]
	RTCP_PACKET_TYPE_RRC_2032_NACK = 193
};

// Network Byte Order
struct RtcpPacket 
{

};

struct RtcpHeader
{
	USHORT length;
	BYTE ptype;
	BYTE verpadrc;

	UINT ssrc;
};

// Network-Ready [deprecated]
// Alle structs sind HostByteOrder; versandt werden nur BYTE-Buffer
struct RtcpReceiverReport
{
	// htonl
	UINT ssrc;
	UINT cumulativeNumberOfPacketsLostWithFractionLost;
	UINT extendedHighestSequmReceived;
	UINT interArrivalJitter;
	UINT lastSR;
	UINT delaySinceLastSR;
};

struct RtcpSenderReport
{
	// letztes feld des Headers
	UINT ssrc;

	UINT ntpTimeStampMsw;
	UINT ntpTimeStampLsw;
	UINT rtpTimeStamp;
	UINT sendersPacketCount;
	UINT sendersOctetCount;

	// Array
	UINT cReceiverReports;
	RtcpReceiverReport* pReceiverReports;
};

struct RtcpBye
{
	UINT ssrc;
	UINT* pCsrc;
	UINT cchByePhrase;
	LPSTR byePhrase;
};

enum RTCP_SDES_TYPE
{
	// end of SDES list                      
	RTCP_SDES_TYPE_END = 0,
	RTCP_SDES_TYPE_CNAME = 1,
	RTCP_SDES_TYPE_NAME = 2,
	RTCP_SDES_TYPE_EMAIL = 3,
	RTCP_SDES_TYPE_PHONE = 4,
	RTCP_SDES_TYPE_LOC = 5,
	RTCP_SDES_TYPE_TOOL = 6,
	RTCP_SDES_TYPE_NOTE = 7,

	// PRIV - not supported
	RTCP_SDES_TYPE_PRIV = 8,
};
//typedef TCHAR[255] SdesItemValue;
//SdesItemValue sdesItems[8];
// [export]
//struct SdesItems 
//{
//	TCHAR cname[RTP_COSTANTS_RTCP_SDES_ITEM_VALUE_MAXLENGTH];
//	TCHAR name[RTP_COSTANTS_RTCP_SDES_ITEM_VALUE_MAXLENGTH];
//	TCHAR email[RTP_COSTANTS_RTCP_SDES_ITEM_VALUE_MAXLENGTH];
//	TCHAR phone[RTP_COSTANTS_RTCP_SDES_ITEM_VALUE_MAXLENGTH];
//	TCHAR loc[RTP_COSTANTS_RTCP_SDES_ITEM_VALUE_MAXLENGTH];
//	TCHAR tool[RTP_COSTANTS_RTCP_SDES_ITEM_VALUE_MAXLENGTH];
//	TCHAR note[RTP_COSTANTS_RTCP_SDES_ITEM_VALUE_MAXLENGTH];
//	// priv - not supported
//	// TCHAR priv[]
//
//	// TODO ssrc???
//	// HBO
//	UINT ssrc;
//};

#ifndef SDESITEMS
#define SDESITEMS
[export]
struct SdesItems 
{
	CHAR cname[RTP_COSTANTS_RTCP_SDES_ITEM_VALUE_MAXLENGTH];
	CHAR name[RTP_COSTANTS_RTCP_SDES_ITEM_VALUE_MAXLENGTH];
	CHAR email[RTP_COSTANTS_RTCP_SDES_ITEM_VALUE_MAXLENGTH];
	CHAR phone[RTP_COSTANTS_RTCP_SDES_ITEM_VALUE_MAXLENGTH];
	CHAR loc[RTP_COSTANTS_RTCP_SDES_ITEM_VALUE_MAXLENGTH];
	CHAR tool[RTP_COSTANTS_RTCP_SDES_ITEM_VALUE_MAXLENGTH];
	CHAR note[RTP_COSTANTS_RTCP_SDES_ITEM_VALUE_MAXLENGTH];
	// priv - not supported
	// TCHAR priv[]

	// TODO ssrc???
	// HBO
	UINT ssrc;
};
#endif

#endif