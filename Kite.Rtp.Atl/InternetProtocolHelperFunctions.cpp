#include "stdafx.h"
#include "InternetProtocolHelperFunctions.h"
#include "RtpDefines.h"



HRESULT InternetProtocolHelper_FindAvailablePortbase(INT af, INT ipproto, sockaddr_in* psockaddrLocalAddress, USHORT *puPortBaseHostByteOrder, UINT cPorts)
{
	CheckPointer(puPortBaseHostByteOrder, E_POINTER);


	if (af != AF_INET)
	{
		return E_INVALIDARG;
	}

	if (cPorts > 100)
	{
		return E_INVALIDARG;
	}

	if ((*puPortBaseHostByteOrder) == 0)
	{
		(*puPortBaseHostByteOrder) = RTP_SOCKET_BASE_PORT_BASE;
	}

	if (psockaddrLocalAddress)
	{
		psockaddrLocalAddress->sin_port = htons(*puPortBaseHostByteOrder);
	}

	UINT cFound = 0;
	do
	{
		if (S_FALSE == InternetProtocolHelper_IsPortAvailable(af, ipproto, psockaddrLocalAddress, (*puPortBaseHostByteOrder)))
		{
			do 
			{
				(*puPortBaseHostByteOrder)++;
			} 
			while(1 & (*puPortBaseHostByteOrder));

			cFound = 0;
		}
		else
		{
			(*puPortBaseHostByteOrder)++;
			cFound++;
		}

		if (psockaddrLocalAddress)
		{
			psockaddrLocalAddress->sin_port = htons(*puPortBaseHostByteOrder);
		}

	} 
	while (cFound < cPorts && (*puPortBaseHostByteOrder + cFound < 65535));

	return cFound == cPorts ? S_OK : E_FAIL;
}

HRESULT InternetProtocolHelper_IsPortAvailable(INT af, INT ipproto, sockaddr_in* psockaddrLocalAddress, USHORT uPortHostByteOrder)
{

	if (psockaddrLocalAddress && uPortHostByteOrder)
	{
		ASSERT(ntohs(psockaddrLocalAddress->sin_port ) != htons(uPortHostByteOrder));

		psockaddrLocalAddress->sin_port = htons(uPortHostByteOrder);
	}

	if (AF_INET != af)
	{
		return E_FAIL;
	}

	if (ipproto != IPPROTO_UDP && ipproto != IPPROTO_TCP)
	{
		return E_INVALIDARG;
	}

	DWORD dwSize = 0;

	DWORD dwRetVal;
	if (ipproto == IPPROTO_UDP)
		dwRetVal = GetUdpTable(NULL, &dwSize, NULL);
	else
		dwRetVal = GetTcpTable(NULL, &dwSize, NULL);

	if (dwRetVal == ERROR_NOT_SUPPORTED)
	{
		return E_FAIL;
	}
	if (dwRetVal == ERROR_INSUFFICIENT_BUFFER)
	{
		if (ipproto == IPPROTO_UDP)
		{
			MIB_UDPTABLE* pMibUdpTable = (MIB_UDPTABLE*)SAFE_ALLOC(dwSize);
			CheckPointer(pMibUdpTable, E_OUTOFMEMORY);

			__try
			{
				dwRetVal = GetUdpTable(pMibUdpTable, &dwSize, TRUE);

				if (dwRetVal == NO_ERROR)
				{
					USHORT uPortNbo = htons(uPortHostByteOrder);
					for (UINT i = 0; i < pMibUdpTable->dwNumEntries; i++)
					{
						if (psockaddrLocalAddress && psockaddrLocalAddress->sin_addr.s_addr != INADDR_ANY && psockaddrLocalAddress->sin_addr.s_addr != pMibUdpTable->table[i].dwLocalAddr)
						{
							continue;
						}

						// nbo
						if (!psockaddrLocalAddress || psockaddrLocalAddress->sin_addr.s_addr == INADDR_ANY || psockaddrLocalAddress->sin_addr.s_addr == pMibUdpTable->table[i].dwLocalAddr)
						{
							if (pMibUdpTable->table[i].dwLocalPort == uPortNbo ) // psockaddrLocalAddress->sin_port)
							{
								return S_FALSE;
							}
						}
					}

					return S_OK;
				}
			}
			__finally
			{
				SAFE_FREE(pMibUdpTable);
			}
		}
	}

	return E_FAIL;
}