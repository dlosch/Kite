#ifndef RTPDEFINES_H
#define RTPDEFINES_H

#define RTP_SOCKET_BASE_PORT_BASE	5000

// includes SSRC
#define RTP_CONSTANTS_RTP_FIXED_HEADER_SIZE	12

#define RTP_CONSTANTS_RTCP_HEADER_SIZE	8

// Not including Header
#define RTP_CONSTANTS_RTCP_SR_SIZE	20
#define RTP_CONSTANTS_RTCP_RR_SIZE	24

#define RTP_COSTANTS_RTCP_SDES_ITEM_VALUE_MAXLENGTH 255

#define RTP_COSTANTS_RTP_MIN_SIZE 12
#define RTP_COSTANTS_RTCP_MIN_SIZE 12

// 5 Minutes
#define RTP_CONSTANTS_DEFAULT_INACTIVITY_TIMEOUT_MILLISECONDS	(1000 * 60 * 5)

#define RTP_CONSTANTS_RTCP_BANDWIDTH_FRACTION (DOUBLE)0.05
#define RTP_CONSTANTS_RTCP_BANDWIDTH_FRACTION_ACTIVE_SOURCES (DOUBLE)0.25

#define RTP_CONSTANTS_RTCP_MINIMUM_TRANSMISSION_INTERVAL_MILLISECONDS 5000


#define RTP_CONSTANTS_RTCP_PACKET_NETWORK_OVERHEAD_UDP_OVER_IP	28



// TODO dieser Wer muss variable im RtpStack zu konfigurieren sein, je nach payload
#define RTP_CONSTANTS_VIDEO_TIMESTAMP_INCREMENT_PER_MILLISECOND	90


// IANA Numbers
enum RTP_PAYLOAD_TYPE
{
	RTP_PAYLOAD_TYPE_PCMU			= 0, //	A              8000          1     [RFC-ietf-avt-profile-new-13.txt]
	//RTP_PAYLOAD_TYPE_PCMU			= 0,     //	A              8000          1     [RFC-ietf-avt-profile-new-13.txt]
	////RTP_PAYLOAD_TYPE_Reserved		= 1,		//	
	////RTP_PAYLOAD_TYPE_Reserved		= 2,	//	
	RTP_PAYLOAD_TYPE_GSM          = 3,	//	 A              8000          1     [RFC-ietf-avt-profile-new-13.txt]
	RTP_PAYLOAD_TYPE_G723         = 4,	//	 A              8000          1       [Kumar]
	RTP_PAYLOAD_TYPE_DVI4         = 5,	//	 A              8000          1     [RFC-ietf-avt-profile-new-13.txt]
	//RTP_PAYLOAD_TYPE_DVI4          = 6,	//	A              16000         1     [RFC-ietf-avt-profile-new-13.txt]
	RTP_PAYLOAD_TYPE_LPC           = 7,	//	A              8000          1     [RFC-ietf-avt-profile-new-13.txt]
	RTP_PAYLOAD_TYPE_PCMA          = 8,    //    A              8000          1     [RFC-ietf-avt-profile-new-13.txt]
	RTP_PAYLOAD_TYPE_G722          = 9,    //    A              8000          1     [RFC-ietf-avt-profile-new-13.txt]
	RTP_PAYLOAD_TYPE_L16           = 10,    //    A              44100         2     [RFC-ietf-avt-profile-new-13.txt]
	//RTP_PAYLOAD_TYPE_L16           = 11,    //    A              44100         1     [RFC-ietf-avt-profile-new-13.txt]
	RTP_PAYLOAD_TYPE_QCELP         = 12,    //    A              8000          1 
	RTP_PAYLOAD_TYPE_CN            = 12,    //    A              8000          1     [RFC3389]
	RTP_PAYLOAD_TYPE_MPA           = 14,    //    A              90000               [RFC-ietf-avt-profile-new-13.txt,RFC2250]
	RTP_PAYLOAD_TYPE_G728          = 15,    //    A                  8000          1     [RFC-ietf-avt-profile-new-13.txt]
	//RTP_PAYLOAD_TYPE_DVI4          = 16,    //    A              11025         1       [DiPol]
	//RTP_PAYLOAD_TYPE_DVI4          = 17,    //    A              22050         1       [DiPol]
	RTP_PAYLOAD_TYPE_G729          = 18,    //    A              8000          1
	////RTP_PAYLOAD_TYPE_reserved      = 19,    //    A
	////RTP_PAYLOAD_TYPE_unassigned    = 20,    //    A
	////RTP_PAYLOAD_TYPE_unassigned    = 21,    //    A
	////RTP_PAYLOAD_TYPE_unassigned    = 22,    //    A
	////RTP_PAYLOAD_TYPE_unassigned    = 23,    //    A
	////RTP_PAYLOAD_TYPE_unassigned    = 24,    //    V
	RTP_PAYLOAD_TYPE_CelB          = 25,    //    V              90000               [RFC2029]
	RTP_PAYLOAD_TYPE_JPEG          = 26,    //    V              90000               [RFC2435]
	////RTP_PAYLOAD_TYPE_unassigned    = 27,    //    V
	RTP_PAYLOAD_TYPE_nv            = 28,    //    V              90000               [RFC-ietf-avt-profile-new-13.txt]
	////RTP_PAYLOAD_TYPE_unassigned    = 29,    //    V
	////RTP_PAYLOAD_TYPE_unassigned    = 30,    //    V
	RTP_PAYLOAD_TYPE_H261          = 31,    //    V              90000               [RFC2032]
	RTP_PAYLOAD_TYPE_MPV           = 32,    //    V              90000               [RFC2250]
	RTP_PAYLOAD_TYPE_MP2T          = 33,    //    AV             90000               [RFC2250]
	RTP_PAYLOAD_TYPE_H263          = 34,    //    V              90000                   [Zhu]
	////35--71     unassigned    = ,	//	?
	////72--76     reserved		 = , //	for RTCP conflict avoidance             [RFC-draft-ietf-avt-rtp-new-11.txt]
	////77--95     unassigned    = ,	//	
	////96--127    dynamic       = ,	//	[RFC-ietf-avt-profile-new-13.txt] 
};

#endif