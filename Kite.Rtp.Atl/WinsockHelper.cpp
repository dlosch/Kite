#include "StdAfx.h"
#include "winsockhelper.h"

HRESULT WinsockHelper_AddressToBstr(BSTR *pbstrAddress, sockaddr* pSockAddr, UINT cbSockAddr)
{
	TCHAR addressString[101];
	ZeroMemory(addressString, sizeof(TCHAR) * 101);

	DWORD dwMaxLen = 100;
	INT wsaRetVal = WSAAddressToString(pSockAddr, cbSockAddr, NULL, addressString, &dwMaxLen);
	if (wsaRetVal == 0)
	{
		CComBSTR comBstr(addressString);
		(*pbstrAddress) = SysAllocStringLen(NULL, comBstr.Length());
		return comBstr.CopyTo(pbstrAddress);
	}
	else
	{
		INT wsaLastError = WSAGetLastError();
		ASSERT(0);
		return E_FAIL;
	}

}


HRESULT WinsockHelper_PrintLastError(INT wsaLastError/* = -1*/)
{
	if (wsaLastError == -1) wsaLastError = WSAGetLastError();
	ATLTRACE2("WSAGetLastError: %d, '%s' \r\n", wsaLastError, gai_strerror(wsaLastError));
	return NOERROR;
}

HRESULT WinsockHelper_ResolveAddress(
									 /*OUT*/ sockaddr** ppsckaddrResolvedAddress, 
									 /*OUT*/ INT *pcbSockaddr,
									 // /*IN*/  INT *pAf,
									 /*IN*/  LPCTSTR lpctstrServerName, 
									 /*IN*/  USHORT ushrtPort)
{
	CheckPointer(ppsckaddrResolvedAddress, E_POINTER);
	CheckPointer(pcbSockaddr, E_POINTER);
	CheckPointer(lpctstrServerName, E_POINTER);

	if (_tcslen(lpctstrServerName) == 0)
	{
		return E_INVALIDARG;
	}

	HRESULT hr = E_FAIL;

	addrinfo addrinfoHints;
	ZeroMemory(&addrinfoHints, sizeof(addrinfoHints));
	addrinfoHints.ai_flags = AI_NUMERICHOST|AI_PASSIVE; // used for call to bind

	addrinfo *pAddrInfoRetVal = NULL;

	int intWsaError = getaddrinfo(lpctstrServerName, NULL, &addrinfoHints, &pAddrInfoRetVal);

	if (intWsaError != 0)
	{
		LPSTR lpstrErrorMessage = gai_strerror(intWsaError);
		ATLTRACE2(lpstrErrorMessage);

		return E_FAIL;
	}
	else 
	{
		if (pAddrInfoRetVal != NULL)
		{
			for(addrinfo *pAddrCurrent = pAddrInfoRetVal; pAddrCurrent != NULL; pAddrCurrent = pAddrCurrent->ai_next)
			{

				if ((pAddrCurrent->ai_addrlen == sizeof(sockaddr_in)) || (pAddrCurrent->ai_addrlen == sizeof(sockaddr_in6)))
				{
					(*ppsckaddrResolvedAddress) = (sockaddr*)SAFE_ALLOC(pAddrCurrent->ai_addrlen);
					CheckPointerJIF((*ppsckaddrResolvedAddress), E_OUTOFMEMORY);

					(*pcbSockaddr) = pAddrCurrent->ai_addrlen;
					CopyMemory(*ppsckaddrResolvedAddress, pAddrCurrent->ai_addr, pAddrCurrent->ai_addrlen);
					((sockaddr_in*)(*ppsckaddrResolvedAddress))->sin_port = htons(ushrtPort);
					hr = S_OK;


					break;
				}
				else
				{
					ATLTRACE2(_T("Address is not Sockkaddr_in "));
				}
			}

			freeaddrinfo(pAddrInfoRetVal);
		}
	}

	return hr;

cleanup:
	if (pAddrInfoRetVal != NULL)
	{
		freeaddrinfo(pAddrInfoRetVal);
	}
	
	return hr;
}

HRESULT WinsockHelper_DebugPrintSockaddr(sockaddr* psckaddrResolvedAddress, UINT cbSockaddr)
{
#ifdef _DEBUG
	TCHAR address[256];
	DWORD len = 255;
	INT wsaRetVal = WSAAddressToString(psckaddrResolvedAddress, cbSockaddr, NULL, address, &len);
	ATLTRACE2("Sockaddr: '%s', Port %d ntohs(%d) \r\n", address, ((sockaddr_in*)psckaddrResolvedAddress)->sin_port, ntohs(((sockaddr_in*)psckaddrResolvedAddress)->sin_port));
#endif

	return S_OK;
}

HRESULT WinsockHelper_GetLocalRoutingInterface(
	sockaddr* psckaddrinRemoteHost, 
	INT cbSockaddr, 
	sockaddr* psckaddrinLocalRoutingInterface, 
	INT *pcbSockaddr)
{
	CheckPointer(psckaddrinLocalRoutingInterface, E_POINTER);
	CheckPointer(psckaddrinRemoteHost, E_POINTER);

	if (cbSockaddr != sizeof(sockaddr_in) && cbSockaddr != sizeof(sockaddr_in6))
	{
		return E_INVALIDARG;
	}

	SOCKET scktTempSocket = socket(psckaddrinRemoteHost->sa_family, NULL, NULL);
	if (scktTempSocket == INVALID_SOCKET)
	{
		return E_FAIL;
	}

	INT intWsaError = WSAIoctl(
		scktTempSocket, 
		SIO_ROUTING_INTERFACE_QUERY, 
		psckaddrinRemoteHost, cbSockaddr, 
		psckaddrinLocalRoutingInterface, *pcbSockaddr, 
		(DWORD*)pcbSockaddr, 
		NULL, NULL);

	INT wsaRetVal = closesocket(scktTempSocket);
	ASSERT(wsaRetVal == 0);

	scktTempSocket = INVALID_SOCKET;

	if (intWsaError == SOCKET_ERROR)
	{
		return E_FAIL;
	}

	if (*pcbSockaddr != cbSockaddr)
	{
		return E_FAIL;
	}
	
	((sockaddr_in*)psckaddrinLocalRoutingInterface)->sin_port = ((sockaddr_in*)psckaddrinRemoteHost)->sin_port;

	WinsockHelper_DebugPrintSockaddr(psckaddrinLocalRoutingInterface, cbSockaddr);//(*pcbSockaddr));

	return S_OK;
}	

HRESULT WinsockHelper_IsMulticastAddress(sockaddr* pAddress, INT cbAddress)
{
	WinsockHelper_DebugPrintSockaddr(pAddress, cbAddress);

	HRESULT hr = S_FALSE;
	if (cbAddress == sizeof(sockaddr_in))
	{
		hr = (((((sockaddr_in*)pAddress)->sin_addr.S_un.S_un_b.s_b1 & 0xE0) == 0xE0) ? S_OK : S_FALSE);
	}
	else if (cbAddress == sizeof(sockaddr_in6))
	{
		hr = (IN6_IS_ADDR_MULTICAST(&(((sockaddr_in6*)pAddress)->sin6_addr)) ? S_OK : S_FALSE);
	}
	else
	{
		hr = E_INVALIDARG;
	}
	return hr;
}

INT WinsockHelper_ValidateRetVal(INT retVal)
{
	if (retVal != SOCKET_ERROR)
	{
		return S_OK;
	}

	INT wsaLastError = WSAGetLastError();
	WinsockHelper_PrintLastError(wsaLastError);

	return retVal;
}

HRESULT WinsockHelper_ExpandMulticastAddress(
	SocketAddresses *pSocketAddressesOrig,
	SocketAddressesIPMcast **ppSocketAddressesExpanded)
{
	CheckPointer(pSocketAddressesOrig, E_POINTER);
	CheckPointer(ppSocketAddressesExpanded, E_POINTER);
	
	if (S_FALSE == WinsockHelper_IsMulticastAddress((sockaddr*)(&pSocketAddressesOrig->remoteAddress), pSocketAddressesOrig->cbSockaddr)) return E_INVALIDARG;
	if ((pSocketAddressesOrig->cbSockaddr != sizeof(sockaddr_in)) && (pSocketAddressesOrig->cbSockaddr != sizeof(sockaddr_in6))) return E_INVALIDARG;
	
	(*ppSocketAddressesExpanded) = (SocketAddressesIPMcast*)SAFE_ALLOC(sizeof(SocketAddressesIPMcast));
	CheckPointer((*ppSocketAddressesExpanded), E_OUTOFMEMORY);
	CopyMemory((*ppSocketAddressesExpanded), pSocketAddressesOrig, sizeof(SocketAddresses));
	
	(*ppSocketAddressesExpanded)->cbSize = sizeof(SocketAddressesIPMcast);

	if ((*ppSocketAddressesExpanded)->cbSockaddr == sizeof(sockaddr_in))
	{
		(*ppSocketAddressesExpanded)->cbMreq = sizeof(ip_mreq);
		CopyMemory(
			&((*ppSocketAddressesExpanded)->multicastEndpoint.ipv4mreq.imr_multiaddr), 
			&((*ppSocketAddressesExpanded)->remoteAddress.ipv4.sin_addr), 
			sizeof(in_addr));

		if ((*ppSocketAddressesExpanded)->isLocalAddressSpecified)
		{
			CopyMemory(
				&((*ppSocketAddressesExpanded)->multicastEndpoint.ipv4mreq.imr_interface), 
				&((*ppSocketAddressesExpanded)->localAddress.ipv4.sin_addr), 
				sizeof(in_addr));
		}
		else
		{
			ZeroMemory(&((*ppSocketAddressesExpanded)->multicastEndpoint.ipv4mreq.imr_interface), sizeof(in_addr));
			(*ppSocketAddressesExpanded)->localAddress.ipv4.sin_addr.s_addr = INADDR_ANY;
			(*ppSocketAddressesExpanded)->localAddress.ipv4.sin_port = (*ppSocketAddressesExpanded)->remoteAddress.ipv4.sin_port;
		}
	}
	else 
	{
		(*ppSocketAddressesExpanded)->cbMreq = sizeof(ipv6_mreq);
		CopyMemory(
			&((*ppSocketAddressesExpanded)->multicastEndpoint.ipv6mreq.ipv6mr_multiaddr), 
			&((*ppSocketAddressesExpanded)->remoteAddress.ipv6.sin6_addr), 
			sizeof(in6_addr));

		if ((*ppSocketAddressesExpanded)->isLocalAddressSpecified)
		{
		}
		else
		{
			(*ppSocketAddressesExpanded)->multicastEndpoint.ipv6mreq.ipv6mr_interface = 0;
			//
			(*ppSocketAddressesExpanded)->localAddress.ipv6.sin6_port = (*ppSocketAddressesExpanded)->remoteAddress.ipv6.sin6_port;
			(*ppSocketAddressesExpanded)->localAddress.ipv6.sin6_addr = in6addr_any;
		}
	}
	return S_OK;
}

HRESULT WinsockHelper_BindSingleAddress(/* OUT */ SocketAddressList** ppSocketAddressList, 
										INT af, INT sockType, INT ipproto, USHORT uLocalPort, BOOL bRtcpAlso, 
										sockaddr* pLocalAddress, UINT cbLocalAddress,
										BOOL bExclusiveUse /*= FALSE*/,
										WSAPROTOCOL_INFO* pWsaProtocolInfo/* = NULL*/, DWORD dwFlags/* = WSA_FLAG_MULTIPOINT_C_LEAF|WSA_FLAG_MULTIPOINT_D_LEAF|WSA_FLAG_OVERLAPPED*/)
{
	CheckPointer(ppSocketAddressList, E_POINTER);
	CheckPointer(pLocalAddress, E_POINTER);
	CheckPointer(cbLocalAddress, E_INVALIDARG);
	if (cbLocalAddress == sizeof(sockaddr_in) && af != AF_INET) return E_INVALIDARG;
	if (cbLocalAddress == sizeof(sockaddr_in6) && af != AF_INET6) return E_INVALIDARG;
	if (af != AF_INET && af != AF_INET6) return E_INVALIDARG;
	
	HRESULT hr = S_OK;

	if (af == AF_INET)
	{
		if (INADDR_ANY == ((sockaddr_in*)pLocalAddress)->sin_addr.s_addr)
		{
			ASSERT(0);
			return WinsockHelper_BindAnyAddress(ppSocketAddressList, af, sockType, ipproto, uLocalPort, bRtcpAlso, bExclusiveUse, pWsaProtocolInfo, dwFlags);
		}
	}
	else if (af == AF_INET6)
	{
		if ( IN6ADDR_ISANY((sockaddr_in6*)pLocalAddress) )
		{
			ASSERT(0);
			return WinsockHelper_BindAnyAddress(ppSocketAddressList, af, sockType, ipproto, uLocalPort, bRtcpAlso, bExclusiveUse, pWsaProtocolInfo, dwFlags);
			// return E_INVALIDARG;
		}
	}

	(*ppSocketAddressList) = (SocketAddressList*)SAFE_ALLOC(sizeof(SocketAddressList));
	CheckPointer((*ppSocketAddressList), E_OUTOFMEMORY);

	(*ppSocketAddressList)->iAddressCount = 1;
	(*ppSocketAddressList)->Address[0].bExclusive = bExclusiveUse;
	(*ppSocketAddressList)->Address[0].bInUse = FALSE;
	(*ppSocketAddressList)->Address[0].cbLocalAddress = cbLocalAddress;
	(*ppSocketAddressList)->Address[0].pLocalAddress = (sockaddr*)SAFE_ALLOC(cbLocalAddress);
	CopyMemory((*ppSocketAddressList)->Address[0].pLocalAddress, pLocalAddress, cbLocalAddress);

	((sockaddr_in*)(*ppSocketAddressList)->Address[0].pLocalAddress)->sin_port = htons(uLocalPort);

	(*ppSocketAddressList)->Address[0].rtpSocket = WSASocket(af, sockType, ipproto, pWsaProtocolInfo, NULL, dwFlags);
	if (INVALID_SOCKET == (*ppSocketAddressList)->Address[0].rtpSocket)
	{
		hr = E_FAIL;
		goto cleanup;
	}

	if (!bExclusiveUse) hr = WinsockHelper_SetReuseAddress((*ppSocketAddressList)->Address[0].rtpSocket, TRUE);

	INT wsaRetVal = bind((*ppSocketAddressList)->Address[0].rtpSocket, 
		(sockaddr*)(*ppSocketAddressList)->Address[0].pLocalAddress,
		(*ppSocketAddressList)->Address[0].cbLocalAddress);

	if (wsaRetVal == SOCKET_ERROR)
	{
		ATLTRACE2("%s %d %s %d %s \r\n", __FUNCTION__, __LINE__, __FILE__, WSAGetLastError(), gai_strerror(WSAGetLastError()));
		hr = E_FAIL;
	}

	if (bRtcpAlso)
	{
		(*ppSocketAddressList)->Address[0].rtcpSocket = WSASocket(af, sockType, ipproto, pWsaProtocolInfo, NULL, dwFlags);
		if (INVALID_SOCKET == (*ppSocketAddressList)->Address[0].rtcpSocket)
		{
			hr = E_FAIL;
			goto cleanup;
		}

		hr = WinsockHelper_SetReuseAddress((*ppSocketAddressList)->Address[0].rtcpSocket, TRUE);

		((sockaddr_in*)(*ppSocketAddressList)->Address[0].pLocalAddress)->sin_port = htons(ntohs(((sockaddr_in*)(*ppSocketAddressList)->Address[0].pLocalAddress)->sin_port) + 1);

		INT wsaRetVal = bind((*ppSocketAddressList)->Address[0].rtcpSocket, 
			(sockaddr*)(*ppSocketAddressList)->Address[0].pLocalAddress,
			(*ppSocketAddressList)->Address[0].cbLocalAddress);

		((sockaddr_in*)(*ppSocketAddressList)->Address[0].pLocalAddress)->sin_port = htons(ntohs(((sockaddr_in*)(*ppSocketAddressList)->Address[0].pLocalAddress)->sin_port) - 1);

		if (wsaRetVal == SOCKET_ERROR)
		{
			ATLTRACE2("%s %d %s %d %s \r\n", __FUNCTION__, __LINE__, __FILE__, WSAGetLastError(), gai_strerror(WSAGetLastError()));
			hr = E_FAIL;
		}
	}

	return S_OK;
cleanup:
	if ((*ppSocketAddressList))
	{
		for (INT i = 0; i < (*ppSocketAddressList)->iAddressCount; i++)
		{
			SAFE_CLOSE_SOCKET((*ppSocketAddressList)->Address[i].rtpSocket);
			SAFE_CLOSE_SOCKET((*ppSocketAddressList)->Address[i].rtcpSocket);
			SAFE_FREE((*ppSocketAddressList)->Address[i].pLocalAddress);
		}

		SAFE_FREE((*ppSocketAddressList));
	}

	return hr;
}

HRESULT WinsockHelper_BindAnyAddress(/* OUT */ SocketAddressList** ppSocketAddressList, 
									 INT af, INT sockType, INT ipproto, USHORT uLocalPort, BOOL bRtcpAlso, 
									 BOOL bExclusiveUse /*= FALSE*/,
									 WSAPROTOCOL_INFO* pWsaProtocolInfo/* = NULL*/, DWORD dwFlags/* = WSA_FLAG_MULTIPOINT_C_LEAF|WSA_FLAG_MULTIPOINT_D_LEAF|WSA_FLAG_OVERLAPPED*/)
{
	SOCKET tempSocket = WSASocket(af, sockType, ipproto, NULL, NULL, NULL);

	if (tempSocket == INVALID_SOCKET)
	{
		return E_FAIL;
	}

	HRESULT hr = S_OK;

	DWORD dwRequiredSize = 0;
	INT wsaRetVal = WSAIoctl(tempSocket, SIO_ADDRESS_LIST_QUERY, NULL, 0, NULL, 0, &dwRequiredSize, NULL, NULL);

	SOCKET_ADDRESS_LIST *pSal = NULL;

	if (wsaRetVal == SOCKET_ERROR)
	{
		if (WSAEFAULT == WSAGetLastError())
		{
			pSal = (SOCKET_ADDRESS_LIST*)SAFE_ALLOC(dwRequiredSize);

			wsaRetVal = WSAIoctl(tempSocket, SIO_ADDRESS_LIST_QUERY, NULL, 0, pSal, dwRequiredSize, &dwRequiredSize, NULL, NULL);

			if (wsaRetVal == SOCKET_ERROR || pSal->iAddressCount <= 0)
			{
				SAFE_FREE(pSal);
				return E_FAIL;
			}

			(*ppSocketAddressList) = (SocketAddressList*)SAFE_ALLOC(sizeof(SocketAddressList) + ((pSal->iAddressCount - 1) * sizeof(LocallyBoundSocket)));
			CheckPointer((*ppSocketAddressList), E_OUTOFMEMORY);
			(*ppSocketAddressList)->iAddressCount = pSal->iAddressCount;

			for (INT i = 0; i < pSal->iAddressCount; i++)
			{
				(*ppSocketAddressList)->Address[i].pLocalAddress = (sockaddr*)SAFE_ALLOC(pSal->Address[i].iSockaddrLength);
				CheckPointerJIF((*ppSocketAddressList)->Address[i].pLocalAddress, E_OUTOFMEMORY);
		
				(*ppSocketAddressList)->Address[i].cbLocalAddress = pSal->Address[i].iSockaddrLength;
				CopyMemory((*ppSocketAddressList)->Address[i].pLocalAddress, pSal->Address[i].lpSockaddr, pSal->Address[i].iSockaddrLength);

				(*ppSocketAddressList)->Address[i].rtpSocket = WSASocket(af, sockType, ipproto, pWsaProtocolInfo, NULL, dwFlags);
				if ((*ppSocketAddressList)->Address[i].rtpSocket == INVALID_SOCKET)
				{
					hr = E_FAIL;
					goto cleanup;
				}

				// Bind the socket
				// set the port
				((sockaddr_in*)(*ppSocketAddressList)->Address[i].pLocalAddress)->sin_port = htons(uLocalPort);

				wsaRetVal = bind((*ppSocketAddressList)->Address[i].rtpSocket, (sockaddr*)(*ppSocketAddressList)->Address[i].pLocalAddress,(*ppSocketAddressList)->Address[i].cbLocalAddress);

				if (wsaRetVal != 0)
				{
					ATLTRACE2("%s %d %s %d %s \r\n", __FUNCTION__, __LINE__, __FILE__, WSAGetLastError(), gai_strerror(WSAGetLastError()));
					hr = E_FAIL;
					goto cleanup;
				}

				(*ppSocketAddressList)->Address[i].bExclusive = bExclusiveUse;

				// enable reuse of the socket
				if (!bExclusiveUse) hr = WinsockHelper_SetReuseAddress((*ppSocketAddressList)->Address[i].rtpSocket, TRUE);

				// same for RTCP, if needed
				if (bRtcpAlso)
				{
					(*ppSocketAddressList)->Address[i].rtcpSocket = WSASocket(af, sockType, ipproto, pWsaProtocolInfo, NULL, dwFlags);
					if ((*ppSocketAddressList)->Address[i].rtcpSocket == INVALID_SOCKET)
					{
						hr = E_FAIL;
						goto cleanup;
					}

					// Bind the socket
					// increment the port
					((sockaddr_in*)(*ppSocketAddressList)->Address[i].pLocalAddress)->sin_port = htons(uLocalPort + 1);
					wsaRetVal = bind((*ppSocketAddressList)->Address[i].rtcpSocket, (sockaddr*)(*ppSocketAddressList)->Address[i].pLocalAddress,(*ppSocketAddressList)->Address[i].cbLocalAddress);

					if (wsaRetVal != 0)
					{
						ATLTRACE2("%s %d %s %d %s \r\n", __FUNCTION__, __LINE__, __FILE__, WSAGetLastError(), gai_strerror(WSAGetLastError()));
						hr = E_FAIL;
						goto cleanup;
					}

					// enable reuse of the socket
					if (!bExclusiveUse) hr = WinsockHelper_SetReuseAddress((*ppSocketAddressList)->Address[i].rtcpSocket, TRUE);

					// decrement the port
					((sockaddr_in*)(*ppSocketAddressList)->Address[i].pLocalAddress)->sin_port = htons(uLocalPort);
				}
			}

			SAFE_FREE(pSal);
		}
	}

	SAFE_CLOSE_SOCKET(tempSocket);

	return S_OK;

cleanup:
	SAFE_CLOSE_SOCKET(tempSocket);
	SAFE_FREE(pSal);

	if ((*ppSocketAddressList))
	{
		for (INT i = 0; i < (*ppSocketAddressList)->iAddressCount; i++)
		{
			SAFE_CLOSE_SOCKET((*ppSocketAddressList)->Address[i].rtpSocket);
			SAFE_CLOSE_SOCKET((*ppSocketAddressList)->Address[i].rtcpSocket);
			SAFE_FREE((*ppSocketAddressList)->Address[i].pLocalAddress);
		}

		SAFE_FREE((*ppSocketAddressList));
	}
	
	return hr;
}

HRESULT WinsockHelper_FreeSocketAddressList(SocketAddressList* pSocketAddressList)
{
	CheckPointer(pSocketAddressList, E_POINTER);

	for (INT i = 0; i < pSocketAddressList->iAddressCount; i++)
	{
		// Close the Socket
		SAFE_CLOSE_SOCKET(pSocketAddressList->Address[i].rtpSocket);
		SAFE_CLOSE_SOCKET(pSocketAddressList->Address[i].rtcpSocket);
		// Free Address
		SAFE_FREE(pSocketAddressList->Address[i].pLocalAddress);
		pSocketAddressList->Address[i].cbLocalAddress = 0;
	}

	SAFE_FREE(pSocketAddressList);
 
	return S_OK;
}

HRESULT WinsockHelper_SetReuseAddress(SOCKET s, BOOL bReuse)
{
	// SO_EXCLUSIVEADDRUSE ist sch�rfer als SO_REUSEADDR
	// SO_REUSEADDR
	DWORD dwValue = !bReuse;
	INT wsaRetVal = setsockopt(s, SOL_SOCKET, SO_EXCLUSIVEADDRUSE, (char*)&dwValue, sizeof(DWORD));

	if (wsaRetVal != 0)
	{
		return E_FAIL;
	}

	dwValue = bReuse;
	wsaRetVal = setsockopt(s, SOL_SOCKET, SO_REUSEADDR, (char*)&dwValue, sizeof(DWORD));

	if (wsaRetVal != 0)
	{
		return E_FAIL;
	}

	return S_OK;
}
