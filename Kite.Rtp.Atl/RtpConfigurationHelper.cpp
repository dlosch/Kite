#include "StdAfx.h"

#include ".\rtpconfigurationhelper.h"

// Caller Needs to Free ppSocketAddresses using SAFE_FREE
HRESULT RtpConfigurationHelper_CreateConfiguration(
	LPTSTR szRemoteAddress,

	USHORT uRemotePort,

	LPTSTR szLocalInterface,

	USHORT uLocalPort,

	INT ttl,

	SocketAddresses** ppSocketAddresses)
{
	CheckPointer(szRemoteAddress, E_POINTER);
	CheckPointer(ppSocketAddresses, E_POINTER);

	if (_tcslen(szRemoteAddress) < 1) return E_INVALIDARG;
	if (szLocalInterface && (_tcslen(szLocalInterface) < 1)) 
	{
		szLocalInterface = NULL;
	}

	HRESULT hr = S_OK;

	addrinfo hintsRemote;
	ZeroMemory(&hintsRemote, sizeof(addrinfo));
	hintsRemote.ai_flags = AI_NUMERICHOST;

	addrinfo* pAddrinfoResolvedRemoteAddress = NULL;
	addrinfo* pAddrinfoResolvedLocalAddress = NULL;
	sockaddr* pSockaddrLocalAddressViaGetLocalRoutingInterface = NULL;

#ifndef GetAddrInfo
#	ifdef UNICODE
#		define GetAddrInfo     GetAddrInfoW
#	else
#		define GetAddrInfo     getaddrinfo
#	endif
#endif

	INT wsaLastError = GetAddrInfo(
		szRemoteAddress,
		NULL,
		&hintsRemote,
		&pAddrinfoResolvedRemoteAddress);

	ATLTRACE2("WSARETVAL %d\r\n", wsaLastError);

	if (wsaLastError == 0 && pAddrinfoResolvedRemoteAddress)
	{
		BOOL bMCast = (S_OK == WinsockHelper_IsMulticastAddress(pAddrinfoResolvedRemoteAddress->ai_addr, pAddrinfoResolvedRemoteAddress->ai_addrlen));

		if (szLocalInterface)
		{
			addrinfo hints;
			ZeroMemory(&hints, sizeof(addrinfo));
			hints.ai_family = pAddrinfoResolvedRemoteAddress->ai_family;
			hints.ai_flags = AI_NUMERICHOST|AI_PASSIVE;

			wsaLastError = GetAddrInfo(
				szLocalInterface,
				NULL,
				&hints,
				&pAddrinfoResolvedLocalAddress);
			
			ATLTRACE2("WSARETVAL %d\r\n", wsaLastError);

			// validate Retval
			CheckPointerJIF(!wsaLastError, E_FAIL);
			CheckPointerJIF(pAddrinfoResolvedLocalAddress, E_FAIL);
			if (pAddrinfoResolvedLocalAddress->ai_addrlen != sizeof(sockaddr_in) && pAddrinfoResolvedLocalAddress->ai_addrlen != sizeof(sockaddr_in))
			{
				hr = E_FAIL;
				goto cleanup;
			}

			if (bMCast)
			{
				((sockaddr_in*)pAddrinfoResolvedLocalAddress->ai_addr)->sin_port = htons(uRemotePort);
			}
			else
			{
				((sockaddr_in*)pAddrinfoResolvedLocalAddress->ai_addr)->sin_port = htons(uLocalPort);
			}
		}
		else
		{
			pSockaddrLocalAddressViaGetLocalRoutingInterface = (sockaddr*)SAFE_ALLOC(pAddrinfoResolvedRemoteAddress->ai_addrlen);
			INT cbSockaddrLocalAddressViaGetLocalRoutingInterface = pAddrinfoResolvedRemoteAddress->ai_addrlen;
			CheckPointerJIF(pSockaddrLocalAddressViaGetLocalRoutingInterface, E_OUTOFMEMORY);

			hr = WinsockHelper_GetLocalRoutingInterface(
				pAddrinfoResolvedRemoteAddress->ai_addr, pAddrinfoResolvedRemoteAddress->ai_addrlen,
				pSockaddrLocalAddressViaGetLocalRoutingInterface, &cbSockaddrLocalAddressViaGetLocalRoutingInterface);

			if (FAILED(hr))
			{
				if (sizeof(sockaddr_in6) == pAddrinfoResolvedRemoteAddress->ai_addrlen)
				{
					((sockaddr_in6*)pSockaddrLocalAddressViaGetLocalRoutingInterface)->sin6_addr = in6addr_any;
					((sockaddr_in6*)pSockaddrLocalAddressViaGetLocalRoutingInterface)->sin6_port = htons(uRemotePort);
				}
				else if (sizeof(sockaddr_in) == pAddrinfoResolvedRemoteAddress->ai_addrlen)
				{
					((sockaddr_in*)pSockaddrLocalAddressViaGetLocalRoutingInterface)->sin_addr.s_addr = INADDR_ANY;
					((sockaddr_in*)pSockaddrLocalAddressViaGetLocalRoutingInterface)->sin_port = htons(uRemotePort);
				}
			}
			else
			{
				if ((uLocalPort > 0) && (!bMCast))
				{
					((sockaddr_in*)pSockaddrLocalAddressViaGetLocalRoutingInterface)->sin_port = htons(uLocalPort);
				}
				else
				{
					((sockaddr_in*)pSockaddrLocalAddressViaGetLocalRoutingInterface)->sin_port = htons(uRemotePort);
				}
			}

			VALHR(hr);
			if (FAILED(hr)) goto cleanup;
		}

		{
			(*ppSocketAddresses) = (SocketAddresses*)SAFE_ALLOC(sizeof(SocketAddresses));
			(*ppSocketAddresses)->cbSize = sizeof(SocketAddresses);
			(*ppSocketAddresses)->bDontReuseAddr = FALSE;
			(*ppSocketAddresses)->bExclusiveAddrUse = FALSE;
			(*ppSocketAddresses)->cbSockaddr = pAddrinfoResolvedRemoteAddress->ai_addrlen;
			(*ppSocketAddresses)->isIPv6 = (pAddrinfoResolvedRemoteAddress->ai_family == AF_INET6);
			(*ppSocketAddresses)->isMcast = bMCast;
			
			// TODO
			(*ppSocketAddresses)->isLocalAddressSpecified = TRUE;

			CopyMemory(&((*ppSocketAddresses)->remoteAddress), pAddrinfoResolvedRemoteAddress->ai_addr, pAddrinfoResolvedRemoteAddress->ai_addrlen);

			if (pAddrinfoResolvedLocalAddress)
			{
				CopyMemory(&((*ppSocketAddresses)->localAddress), pAddrinfoResolvedLocalAddress->ai_addr, pAddrinfoResolvedLocalAddress->ai_addrlen);
			}
			else if (pSockaddrLocalAddressViaGetLocalRoutingInterface)
			{
				CopyMemory(&((*ppSocketAddresses)->localAddress), pSockaddrLocalAddressViaGetLocalRoutingInterface,  pAddrinfoResolvedRemoteAddress->ai_addrlen);
			}

			(*ppSocketAddresses)->remoteAddress.ipv4.sin_port = htons(uRemotePort);

			if (bMCast || uLocalPort == 0)
			{
				(*ppSocketAddresses)->localAddress.ipv4.sin_port = htons(uRemotePort);
			}

			(*ppSocketAddresses)->Ttl = ttl;

		}
	}
	else
	{
		ATLTRACE2("Error GetAddrInfo for %s: '%s'\r\n", szRemoteAddress, gai_strerror(wsaLastError));
		hr = E_FAIL;
		goto cleanup;
	}

	WinsockHelper_DebugPrintSockaddr(pAddrinfoResolvedRemoteAddress->ai_addr, pAddrinfoResolvedRemoteAddress->ai_addrlen);
	if (pAddrinfoResolvedLocalAddress) WinsockHelper_DebugPrintSockaddr(pAddrinfoResolvedLocalAddress->ai_addr, pAddrinfoResolvedLocalAddress->ai_addrlen);
	if (pSockaddrLocalAddressViaGetLocalRoutingInterface) WinsockHelper_DebugPrintSockaddr(pSockaddrLocalAddressViaGetLocalRoutingInterface, pAddrinfoResolvedRemoteAddress->ai_addrlen);

cleanup:
	SAFE_FREE(pSockaddrLocalAddressViaGetLocalRoutingInterface);
	if (pAddrinfoResolvedRemoteAddress) freeaddrinfo(pAddrinfoResolvedRemoteAddress);
	if (pAddrinfoResolvedLocalAddress) freeaddrinfo(pAddrinfoResolvedLocalAddress);
	pAddrinfoResolvedRemoteAddress = NULL;
	pAddrinfoResolvedLocalAddress = NULL;

	
	return hr;
}

HRESULT RtpConfigurationHelper_CreateSdesItems(
	LPTSTR cname,
	LPTSTR name,
	LPTSTR email,
	LPTSTR phone,
	LPTSTR loc,
	LPTSTR tool,
	LPTSTR note,
	SdesItems** ppSdesItems)
{
	CheckPointer(cname, E_POINTER);
	if (tool)
	{
		MessageBox(NULL, "RtpConfigurationHelper_CreateSdesItems Tool is ignored.", "Wer das liest, ist doof.", MB_OK);
	}

	(*ppSdesItems) = (SdesItems*)SAFE_ALLOC(sizeof(SdesItems));
	CheckPointer(*ppSdesItems, E_OUTOFMEMORY);

	_tcsncpy((*ppSdesItems)->cname, cname, RTP_COSTANTS_RTCP_SDES_ITEM_VALUE_MAXLENGTH);
	if (email) _tcsncpy((*ppSdesItems)->email, email, RTP_COSTANTS_RTCP_SDES_ITEM_VALUE_MAXLENGTH);
	if (loc) _tcsncpy((*ppSdesItems)->loc, loc, RTP_COSTANTS_RTCP_SDES_ITEM_VALUE_MAXLENGTH);
	if (name) _tcsncpy((*ppSdesItems)->name, name, RTP_COSTANTS_RTCP_SDES_ITEM_VALUE_MAXLENGTH);
	if (note) _tcsncpy((*ppSdesItems)->note, note, RTP_COSTANTS_RTCP_SDES_ITEM_VALUE_MAXLENGTH);
	if (phone) _tcsncpy((*ppSdesItems)->phone, phone, RTP_COSTANTS_RTCP_SDES_ITEM_VALUE_MAXLENGTH);
	_tcsncpy((*ppSdesItems)->tool, RTCP_SDES_ITEM_TOOL, RTP_COSTANTS_RTCP_SDES_ITEM_VALUE_MAXLENGTH);

	return S_OK;
}
