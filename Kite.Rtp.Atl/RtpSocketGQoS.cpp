#include "StdAfx.h"
#include ".\rtpsocketgqos.h"

// Caller allocated
HRESULT GQoSHelper_FindProvider(INT af, LPWSAPROTOCOL_INFO lpWsaProtocolInfo)
{
	CheckPointer(lpWsaProtocolInfo, E_POINTER);

	HRESULT hr = E_FAIL;

	DWORD dwBufferSize = 0;
	INT wsaRetVal = WSAEnumProtocols(NULL, NULL, &dwBufferSize);
	if ((wsaRetVal == SOCKET_ERROR) && (WSAGetLastError() != WSAENOBUFS))
	{
		ASSERT(0);
		return E_FAIL;
	}

	WSAPROTOCOL_INFO* lpwsaProtocolInfoAll = (LPWSAPROTOCOL_INFO)SAFE_ALLOC(dwBufferSize);
	wsaRetVal = WSAEnumProtocols(NULL, lpwsaProtocolInfoAll, &dwBufferSize);

	if (SOCKET_ERROR == wsaRetVal)
	{
		INT lastError = WSAGetLastError();
		ATLTRACE2("WSAEnumProtocols: 2nd time %d %s\n", lastError, gai_strerror(lastError));

		goto cleanup;
	}
	
	for (INT i = 0; i < (dwBufferSize / sizeof(WSAPROTOCOL_INFO)); i++)
	{
		// && (lpwsaProtocolInfoAll[i].dwServiceFlags1 & XP1_SUPPORT_BROADCAST)
		if(    (lpwsaProtocolInfoAll[i].dwServiceFlags1 & XP1_QOS_SUPPORTED)
			&& (lpwsaProtocolInfoAll[i].dwServiceFlags1 & XP1_CONNECTIONLESS)
			&& (lpwsaProtocolInfoAll[i].dwServiceFlags1 & XP1_SUPPORT_MULTIPOINT))
		{
			if ((af == 0) || (af == lpwsaProtocolInfoAll[i].iAddressFamily))
			{
				// accept all Protos
				CopyMemory(lpWsaProtocolInfo, &(lpwsaProtocolInfoAll[i]), sizeof(WSAPROTOCOL_INFO));
				hr = S_OK;
				goto cleanup;
			}
		}
	}

cleanup:
	SAFE_FREE(lpwsaProtocolInfoAll);

	return hr;
}