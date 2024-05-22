#pragma once
#ifndef RTPCONFIGURATIONHELPER_H
#define RTPCONFIGURATIONHELPER_H

#include <WinSock2.h>
#include <WS2tcpip.h>
#include "SocketData.h"
//#include "RtpStructs.h"

#define RTCP_SDES_ITEM_TOOL	_T("Kite.RtpStack. THIS IS ALPHA SOFTWARE. THIS SOFTWARE IS NOT FREE. THIS IS A LOOOOOONG STRING.")

enum RTP_CONFIGURATION_HELPER_ADDRESS_FAMILY_SPECIFICATION
{
	RTP_CONFIGURATION_HELPER_ADDRESS_FAMILY_SPECIFICATION_UNSPECIFIED = 0,
	RTP_CONFIGURATION_HELPER_ADDRESS_FAMILY_SPECIFICATION_IPv4 = AF_INET, // 2
	RTP_CONFIGURATION_HELPER_ADDRESS_FAMILY_SPECIFICATION_IPv6 = AF_INET6 // 23
};

// Caller Needs to Free ppSocketAddresses using SAFE_FREE
HRESULT RtpConfigurationHelper_CreateConfiguration(
	LPTSTR remoteAddress,
	
	USHORT remotePort,

	LPTSTR localInterface,

	USHORT uLocalPort,

	INT ttl,

	SocketAddresses** ppSocketAddresses);

// SAFE_FREE
HRESULT RtpConfigurationHelper_CreateSdesItems(
	LPTSTR cname,
	LPTSTR name,
	LPTSTR email,
	LPTSTR phone,
	LPTSTR loc,
	LPTSTR tool,
	LPTSTR note,
	SdesItems** ppSdesItems);

#endif
