#ifndef RTPIDLEXPORTS_H
#define RTPIDLEXPORTS_H

[export]
struct RtpParsedPacket
{
	BOOL pad;
	BOOL ext;
	BOOL marker;
	// messes up alignment
	/*BYTE */ UINT cc;

	UINT timestamp;

	UINT ssrc;

	// align on 4 bytes
	USHORT seqNum;
	USHORT cbData;

	// Would be aligned on 4/8 nevertheless
	UINT payloadType;

	BYTE* pData;
};


#endif