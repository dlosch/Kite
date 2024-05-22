#ifndef WINSOCKHELPER_H
#define WINSOCKHELPER_H
#pragma once
#include <WinSock2.h>
#include <WS2tcpip.h>

#include "SocketData.h"

// Caller has to free *pbstrAddress using SysFreeString
HRESULT WinsockHelper_AddressToBstr(BSTR *pbstrAddress, sockaddr* pSockAddr, UINT cbSockAddr);

// Resolves DNS name or IPNotation (v4/v6) to sockaddr
// Caller has to free ppsckaddrResolvedAddress using CoTaskMemFree
HRESULT WinsockHelper_ResolveAddress(
									 /*OUT*/ sockaddr** ppsckaddrResolvedAddress, 
									 /*OUT*/ INT *pcbSockaddr,
									 ///*IN*/  INT* pAf,
									 /*IN*/  LPCTSTR lpctstrServerName, 
									 /*IN*/  USHORT ushrtPort);

HRESULT WinsockHelper_DebugPrintSockaddr(sockaddr* psckaddrResolvedAddress, UINT cbAddress);

// Caller has to free ppsckaddrinLocalRoutingInterface with SAFE_FREE
HRESULT WinsockHelper_GetLocalRoutingInterface(
	sockaddr* psckaddrinRemoteHost, 
	INT cbSockaddr, 
	sockaddr* psckaddrinLocalRoutingInterface, 
	INT *pcbSockaddr);

HRESULT WinsockHelper_PrintLastError(INT wsaLastError = -1);

// S_False = false, S_OK = TRUE
HRESULT WinsockHelper_IsMulticastAddress(sockaddr* pAddress, INT cbAddress);

INT WinsockHelper_ValidateRetVal(INT retVal);

// Caller needs to free *ppSocketAddressesExpanded using SAFE_FREE
HRESULT WinsockHelper_ExpandMulticastAddress(
	SocketAddresses *pSocketAddressesOrig,
	SocketAddressesIPMcast **ppSocketAddressesExpanded);

HRESULT WinsockHelper_BindSingleAddress(/* OUT */ SocketAddressList** ppSocketAddressList, 
										INT af, INT sockType, INT ipproto, USHORT uLocalPort, BOOL bRtcpAlso, 
										sockaddr* pLocalAddress, UINT cbLocalAddress,
										BOOL bExclusiveUse = FALSE,
										WSAPROTOCOL_INFO* pWsaProtocolInfo = NULL, DWORD dwFlags = WSA_FLAG_MULTIPOINT_C_LEAF|WSA_FLAG_MULTIPOINT_D_LEAF|WSA_FLAG_OVERLAPPED);


// Binds on any local Address explicitly on the Port
HRESULT WinsockHelper_BindAnyAddress(/* OUT */ SocketAddressList** ppSockatAddressList, 
									 INT af, INT sockType, INT ipproto, USHORT uLocalPort, BOOL bRtcpAlso,
									 BOOL bExclusiveUse = FALSE,
									 WSAPROTOCOL_INFO* pWsaProtocolInfo = NULL, 
									 DWORD dwFlags = WSA_FLAG_MULTIPOINT_C_LEAF|WSA_FLAG_MULTIPOINT_D_LEAF|WSA_FLAG_OVERLAPPED);

HRESULT WinsockHelper_FreeSocketAddressList(SocketAddressList* pSocketAddressList);

HRESULT WinsockHelper_SetReuseAddress(SOCKET s, BOOL bReuse);
#endif
