#include "StdAfx.h"

#define GQOS_ENABLED	0

#include ".\rtpsocketbase.h"
#include "RtpConfigurationHelper.h"
#include "InternetProtocolHelperFunctions.h"

#define MULTICAST_LOOP 1 // 1 ist korrekt (Receive Path muss 1)
#define ASYNC_EVENTS

// Enable or disable using GQoS
#if GQOS_ENABLED
#	include "RtpSocketGQoS.h"

STDMETHODIMP CRtpSocketBase::SetQoS()
{
	// Build FlowSpec
	QOS     qos;
	DWORD   dwBytes, cbQosLen;
	INT     wsaRetVal;

	ZeroMemory(&qos, sizeof(QOS));
	FLOWSPEC flowspec =
	{
		QOS_NOT_SPECIFIED, // 8500,
		680,
		32000, //256000, // Max Bandwidth Bytes/sec
		// microseconds
		QOS_NOT_SPECIFIED,
		QOS_NOT_SPECIFIED,
		SERVICETYPE_GUARANTEED,
		1500,
		0 // May be zero
	};

	if (m_bIsListener) 
		qos.ReceivingFlowspec = flowspec;
	else 
		qos.SendingFlowspec = flowspec;
	
	qos.ProviderSpecific.buf = NULL;
	qos.ProviderSpecific.len = 0;

	cbQosLen = sizeof(QOS) + qos.ProviderSpecific.len;

	// Out Buffer darf null sein
	// RSVP_STATUS_INFO rsvpStatus;

	wsaRetVal = WSAIoctl(
		m_scktRtpSocket, 
		SIO_SET_QOS, 
		(LPVOID)&qos, 
		cbQosLen, 
		NULL, //&rsvpStatus, 
		0, //sizeof(RSVP_STATUS_INFO), 
		&dwBytes, 
		NULL, NULL);

	if (wsaRetVal == SOCKET_ERROR)
	{
		ATLTRACE2("!!!!!!!!!!!!!!!!!!! Error requesting QOS %d %s \r\n", WSAGetLastError(), gai_strerror(WSAGetLastError()));
		return E_FAIL;
	}

	return S_OK;
}
#endif

HRESULT CRtpSocketBase::InternalGetNetworkParameter(
	LPWSTR szRemoteAddress, INT cchRemoteAddress, USHORT* puRemotePort, 
	LPWSTR szLocalInterface, INT cchLocalAddress, USHORT* puLocalPortBase, INT* pTtl)
{
	CheckPointer(szRemoteAddress, E_POINTER);
	CheckPointer(szLocalInterface, E_POINTER);
	CheckPointer(cchRemoteAddress, E_INVALIDARG);
	CheckPointer(cchLocalAddress, E_INVALIDARG);
	CheckPointer(pTtl, E_POINTER);

	if (m_pRtpAddresses && m_pRtcpAddresses)
	{
		DWORD dwLen = cchLocalAddress;
		INT wsaRetVal = WSAAddressToStringW((sockaddr*)&(m_pRtpAddresses->localAddress), m_pRtpAddresses->cbSize, NULL, szLocalInterface, &dwLen);
		if (wsaRetVal == SOCKET_ERROR)
		{
			return E_FAIL;
		}

		dwLen = cchRemoteAddress;
		wsaRetVal = WSAAddressToStringW((sockaddr*)&(m_pRtpAddresses->remoteAddress), m_pRtpAddresses->cbSize, NULL, szRemoteAddress, &dwLen);
		if (wsaRetVal == SOCKET_ERROR)
		{
			return E_FAIL;
		}

		// Ports auslesen
		(*puRemotePort) = ntohs(m_pRtpAddresses->remoteAddress.ipv4.sin_port);
		(*puLocalPortBase) = ntohs(m_pRtpAddresses->localAddress.ipv4.sin_port);

		// ttl
		if (m_scktRtpBaseSocket != INVALID_SOCKET && m_scktRtcpBaseSocket != NULL)
		{
			INT optlen = sizeof(INT);
			wsaRetVal = getsockopt(m_scktRtcpBaseSocket, IPPROTO_IP, IP_MULTICAST_TTL, (char*)pTtl, &optlen);
			if (wsaRetVal == SOCKET_ERROR)
			{
				return E_FAIL;
			}
		}

		return S_OK;
	}

	return E_UNEXPECTED;
}


HRESULT CRtpSocketBase::InternalReserveNetworkAddress(
	LPWSTR szRemoteAddress, 
	LPWSTR szLocalInterface, 
	USHORT uMinLocalPort,
	USHORT uMaxLocalPort, 
	
	LPWSTR szLocalInterfaceOut, 
	INT cchLocalAddress,
	USHORT *puLocal)
{
	CheckPointer(!m_pRtpAddresses, E_UNEXPECTED);

	CheckPointer(szLocalInterfaceOut, E_POINTER);
	CheckPointer(puLocal, E_POINTER);
	if (cchLocalAddress < 3) return E_INVALIDARG;

	CheckPointer(szRemoteAddress, E_POINTER);
	if (uMinLocalPort > uMaxLocalPort) return E_INVALIDARG;

	if (m_pReservedSockets)
	{
		WinsockHelper_FreeSocketAddressList(m_pReservedSockets);
		m_pReservedSockets = NULL;
	}

	sockaddr* pLocalAddress = NULL;
	INT cbLocalAddress = 0;
	sockaddr* pRemoteAddress = NULL;
	INT cbRemoteAddress = 0;

	__try
	{
		INT af = AF_UNSPEC;

		HRESULT hr = S_OK;

		if (szLocalInterface != NULL)
		{
			USES_CONVERSION;
			if (FAILED(WinsockHelper_ResolveAddress(&pLocalAddress, &cbLocalAddress, W2T(szLocalInterface), 0)))
			{
				return E_FAIL;
			}
		}
		else if (szRemoteAddress)
		{
			USES_CONVERSION;
			if (FAILED(WinsockHelper_ResolveAddress(&pRemoteAddress, &cbRemoteAddress, W2T(szRemoteAddress), 0)))
			{
				return E_FAIL;
			}

			cbLocalAddress = cbRemoteAddress;
			pLocalAddress = (sockaddr*)SAFE_ALLOC(cbLocalAddress);

			if (!pLocalAddress)
			{
				SAFE_FREE(pRemoteAddress);
				return E_OUTOFMEMORY;
			}

			hr = WinsockHelper_GetLocalRoutingInterface(
				pRemoteAddress, 
				cbRemoteAddress, 
				pLocalAddress,
				&cbLocalAddress);

			if (FAILED(hr))
			{
				return E_FAIL;
			}
		}

		USHORT uCurrentPort = uMinLocalPort;
		if (uCurrentPort % 2)
		{
			(uCurrentPort)++;
		}

		if (((sockaddr_in*)pLocalAddress)->sin_family == AF_INET)
		{
			af = AF_INET;

			if (S_OK == InternetProtocolHelper_FindAvailablePortbase(AF_INET, IPPROTO_UDP, NULL, &uCurrentPort, 2))
			{
				((sockaddr_in*)pLocalAddress)->sin_port = htons(uCurrentPort);
				{
					hr = WinsockHelper_BindSingleAddress(&m_pReservedSockets, AF_INET, SOCK_DGRAM, IPPROTO_UDP, uCurrentPort, TRUE, pLocalAddress, cbLocalAddress);
				}
			}
			else return E_FAIL;
		}
		else if (((sockaddr_in6*)pLocalAddress)->sin6_family == AF_INET6)
		{
			af = AF_INET6;

			do 
			{
				((sockaddr_in*)pLocalAddress)->sin_port = htons(uCurrentPort);

				{
					hr = WinsockHelper_BindSingleAddress(&m_pReservedSockets, AF_INET6, SOCK_DGRAM, IPPROTO_UDP, uCurrentPort, TRUE, pLocalAddress, cbLocalAddress);
				}

				if (hr == S_OK)
				{
					hr = S_OK;
					break;
				}
				else
				{
					uCurrentPort += 2;
				}
			} 
			while(uCurrentPort < uMaxLocalPort);

			if (hr != S_OK) 
			{
				return hr;
			}
		}

		ATLTRACE2("Alles fertig, vor CreateSockets \r\n");

		(*puLocal) = ntohs(((sockaddr_in*)pLocalAddress)->sin_port);
		DWORD dwLocal = cchLocalAddress;
		((sockaddr_in*)pLocalAddress)->sin_port = 0;
		INT wsaRetVal = WSAAddressToStringW(pLocalAddress, cbLocalAddress, NULL, szLocalInterfaceOut, &dwLocal); 
		
		return wsaRetVal == 0 ? S_OK : E_FAIL;
	}
	__finally
	{
		SAFE_FREE(pLocalAddress);
		SAFE_FREE(pRemoteAddress);
	}

	return E_FAIL;
}


HRESULT CRtpSocketBase::InternalReserveNetworkAddressAndCreateSockets(
	LPWSTR szRemoteAddress, 
	LPWSTR szLocalInterface, 
	USHORT uMinLocalPort,
	USHORT uMaxLocalPort, INT ttl)

{
	CheckPointer(!m_pRtpAddresses, E_UNEXPECTED);
	CheckPointer(szRemoteAddress, E_POINTER);
	if (uMinLocalPort > uMaxLocalPort) return E_INVALIDARG;

	ATLTRACE2("InternalReserveNetworkAddress %s %s %d %d %d\r\n", szRemoteAddress, szLocalInterface, uMinLocalPort, uMaxLocalPort, ttl);

	if (m_pReservedSockets)
	{
		WinsockHelper_FreeSocketAddressList(m_pReservedSockets);
		m_pReservedSockets = NULL;
	}

	sockaddr* pLocalAddress = NULL;
	INT cbLocalAddress = 0;
	sockaddr* pRemoteAddress = NULL;
	INT cbRemoteAddress = 0;

	__try
	{
		INT af = AF_UNSPEC;

		HRESULT hr = S_OK;

		if (szLocalInterface != NULL)
		{
			USES_CONVERSION;
			if (FAILED(WinsockHelper_ResolveAddress(&pLocalAddress, &cbLocalAddress, W2T(szLocalInterface), 0)))
			{
				return E_FAIL;
			}
		}
		else if (szRemoteAddress)
		{
			USES_CONVERSION;
			if (FAILED(WinsockHelper_ResolveAddress(&pRemoteAddress, &cbRemoteAddress, W2T(szRemoteAddress), 0)))
			{
				return E_FAIL;
			}

			cbLocalAddress = cbRemoteAddress;
			pLocalAddress = (sockaddr*)SAFE_ALLOC(cbLocalAddress);

			if (!pLocalAddress)
			{
				SAFE_FREE(pRemoteAddress);
				return E_OUTOFMEMORY;
			}

			hr = WinsockHelper_GetLocalRoutingInterface(
				pRemoteAddress, 
				cbRemoteAddress, 
				pLocalAddress,
				&cbLocalAddress);

			if (FAILED(hr))
			{
				return E_FAIL;
			}
		}

		USHORT uCurrentPort = uMinLocalPort;
		if (uCurrentPort % 2)
		{
			(uCurrentPort)++;
		}

		if (((sockaddr_in*)pLocalAddress)->sin_family == AF_INET)
		{
			af = AF_INET;

			if (S_OK == InternetProtocolHelper_FindAvailablePortbase(AF_INET, IPPROTO_UDP, NULL, &uCurrentPort, 2))
			{
				((sockaddr_in*)pLocalAddress)->sin_port = htons(uCurrentPort);
				{
					hr = WinsockHelper_BindSingleAddress(&m_pReservedSockets, AF_INET, SOCK_DGRAM, IPPROTO_UDP, uCurrentPort, TRUE, pLocalAddress, cbLocalAddress);
				}
			}
			else return E_FAIL;
		}
		else if (((sockaddr_in6*)pLocalAddress)->sin6_family == AF_INET6)
		{
			af = AF_INET6;

			do 
			{
				((sockaddr_in*)pLocalAddress)->sin_port = htons(uCurrentPort);
				{
					hr = WinsockHelper_BindSingleAddress(&m_pReservedSockets, AF_INET6, SOCK_DGRAM, IPPROTO_UDP, uCurrentPort, TRUE, pLocalAddress, cbLocalAddress);
				}

				if (hr == S_OK)
				{
					// RTP und RTCP gebunden
					hr = S_OK;
					break;
				}
				else
				{
					uCurrentPort += 2;
				}
			} 
			while(uCurrentPort < uMaxLocalPort);

			if (hr != S_OK) 
			{
				return hr;
			}
		}

		ATLTRACE2("Alles fertig, vor CreateSockets \r\n");

		SocketAddresses socketAddresses;
		ZeroMemory(&socketAddresses, sizeof(SocketAddresses));

		socketAddresses.bDontReuseAddr = FALSE;
		socketAddresses.bExclusiveAddrUse = FALSE;
		socketAddresses.cbSize = sizeof(SocketAddresses);
		socketAddresses.cbSockaddr = cbRemoteAddress;
		socketAddresses.isIPv6 = (af == AF_INET6);
		socketAddresses.isLocalAddressSpecified = TRUE;
		socketAddresses.isMcast = (S_OK == WinsockHelper_IsMulticastAddress(pRemoteAddress, cbRemoteAddress));
		CopyMemory(&(socketAddresses.remoteAddress.ipv4), pRemoteAddress, cbRemoteAddress);
		CopyMemory(&(socketAddresses.localAddress.ipv4), pLocalAddress, cbRemoteAddress);
		socketAddresses.Ttl = ttl;

		WinsockHelper_DebugPrintSockaddr((sockaddr*)&(socketAddresses.remoteAddress), cbRemoteAddress);
		WinsockHelper_DebugPrintSockaddr((sockaddr*)&(socketAddresses.localAddress), cbLocalAddress);

		return CreateSockets(&socketAddresses);
	}
	__finally
	{
		SAFE_FREE(pLocalAddress);
		SAFE_FREE(pRemoteAddress);
	}

	return E_FAIL;
}

// Winxp or higher
#ifndef TIME_KILL_SYNCHRONOUS
#	define TIME_KILL_SYNCHRONOUS   0x0100  /* This flag prevents the event from occurring */
											/* after the user calls timeKillEvent() to */
											/* destroy it. */
#endif

CRtpSocketBase::CRtpSocketBase(void)
{
	m_pReservedSockets = NULL;

#if GQOS_ENABLED
	m_bGQoSEnabled = FALSE;
#endif

	m_bListenState = FALSE;
	
	m_pwsabufRtpReceiver = NULL;
	m_pwsabufRtcpReceiver = NULL;

	m_pWsaOverlappedRtpReceiver = NULL;
	m_pWsaOverlappedRtcpReceiver = NULL;

	m_scktRtpSocket = INVALID_SOCKET;
	m_scktRtcpSocket = INVALID_SOCKET;

	m_pSockkaddrRecvFromRtpSocket = NULL;
	m_pSockkaddrRecvFromRtcpSocket = NULL;
	m_cbSockkaddrRecvFromRtpSocketFromLen = 0;
	m_cbSockkaddrRecvFromRtcpSocketFromLen = 0;

	m_bRtcpReceiveQueuedCallPending = FALSE;
	m_hEventWorkerThreadStartThreadProc = INVALID_HANDLE_VALUE;
	//////////////////////////////////////////////////////////////////////////
	m_dwWsaReceiveEvents = 0;
	m_hEventWorkerThreadDied = INVALID_HANDLE_VALUE;
	m_hReceiverWorkerThread = INVALID_HANDLE_VALUE;
	m_bReceiveWorkerThreadAlive = FALSE;	
	m_wsaReceiveEvents[0] = WSA_INVALID_EVENT;
	m_wsaReceiveEvents[1] = WSA_INVALID_EVENT;
	m_wsaReceiveEvents[2] = WSA_INVALID_EVENT;
	m_hReceiverWorkerThread = INVALID_HANDLE_VALUE;
	//m_critSectReceiverWorkerThread;
	//////////////////////////////////////////////////////////////////////////

	// Array of Pointer
	m_pWsaOverlappedRtpRecvFrom = NULL;
	m_pWsaOverlappedInstanceData = NULL;
	m_cWsaOverlappedInstanceData = 0;
	m_hEventReceiveWorkerThreadWakeupEvent = INVALID_HANDLE_VALUE;

	//////////////////////////////////////////////////////////////////////////
	m_pRtpAddresses = NULL;
	m_pRtcpAddresses = NULL;

	m_bIsListener = TRUE;

	m_pRtpReceiveBufferContinuous = NULL;
	m_pRtcpReceiveBufferContinuous = NULL;

	BOOL retVal = m_mapRtpSessionMembers.InitHashTable(7);
	ASSERT(retVal);

	m_rtpSessionBandwidthKilobitPerSecond = 128000;

	m_ssrc = 0;

	BOOL bRetVal = InitializeCriticalSectionAndSpinCount(&m_critSectObjectLock, 0x80000400);
	ASSERT(bRetVal);
}

CRtpSocketBase::~CRtpSocketBase(void)
{
	EnterCriticalSection(&m_critSectObjectLock);
	
	UninitializeRtcpTimer();

	CleanupReceiverThread();

	SAFE_FREE(m_pWsaOverlappedRtpReceiver);
	SAFE_FREE(m_pWsaOverlappedRtcpReceiver);
	SAFE_FREE(m_pwsabufRtpReceiver);
	SAFE_FREE(m_pwsabufRtcpReceiver);
	SAFE_FREE(m_pRtpReceiveBufferContinuous);
	SAFE_FREE(m_pRtcpReceiveBufferContinuous);

	if ((m_scktRtpBaseSocket != m_scktRtpSocket) && (m_scktRtpBaseSocket  != NULL) && (m_scktRtpBaseSocket != INVALID_SOCKET))
		SAFE_CLOSE_SOCKET(m_scktRtpBaseSocket);

	if ((m_scktRtcpBaseSocket != m_scktRtcpSocket) && (m_scktRtcpBaseSocket != NULL) && (m_scktRtcpBaseSocket != INVALID_SOCKET))
		SAFE_CLOSE_SOCKET(m_scktRtcpBaseSocket);

	SAFE_CLOSE_SOCKET(m_scktRtcpSocket);	
	SAFE_CLOSE_SOCKET(m_scktRtpSocket);	
	SAFE_FREE(m_pRtcpAddresses);
	SAFE_FREE(m_pRtpAddresses);

	SAFE_FREE(m_pSockkaddrRecvFromRtpSocket);
	SAFE_FREE(m_pSockkaddrRecvFromRtcpSocket);
	m_cbSockkaddrRecvFromRtpSocketFromLen = 0;
	m_cbSockkaddrRecvFromRtcpSocketFromLen = 0;

	//////////////////////////////////////////////////////////////////////////
	SAFE_FREE(m_pWsaOverlappedRtpRecvFrom);
	SAFE_FREE(m_pWsaOverlappedInstanceData);
	m_cWsaOverlappedInstanceData = 0;
	SAFE_CLOSE_HANDLE(m_hEventReceiveWorkerThreadWakeupEvent);
	//////////////////////////////////////////////////////////////////////////

	if (m_pReservedSockets)
	{
		WinsockHelper_FreeSocketAddressList(m_pReservedSockets);
		m_pReservedSockets = NULL;
	}

	// m_mapRtpSessionMembers.

	try
	{
		if (m_pPerfCounterFactory) m_pPerfCounterFactory->Dispose();
	}
	catch(...)
	{
		ATLTRACE2("!!!!!!!!!!!!!!!!!!! Caught exception in %s %s %d", __FUNCSIG__, __FILE__, __LINE__);
	}

	LeaveCriticalSection(&m_critSectObjectLock);
	DeleteCriticalSection(&m_critSectObjectLock);

	DeleteCriticalSection(&m_critSectRtpSessionMembersMapSynchronization);
}

STDMETHODIMP CRtpSocketBase::Initialize(void)
{
	CAutoLock lock(&m_critSectObjectLock);

	BOOL bRetVal = InitializeCriticalSectionAndSpinCount(&m_critSectRtpSessionMembersMapSynchronization, 0x80000400);
	VALRV(bRetVal, E_FAIL);

	bRetVal = InitializeCriticalSectionAndSpinCount(&m_critSectReceiverWorkerThread, 0x80000400);
	VALRV(bRetVal, E_FAIL);

	HRESULT hr = S_OK;

	return hr;
}

STDMETHODIMP CRtpSocketBase::SetIsListener(BOOL rtpListener)
{
	CAutoLock lock(&m_critSectObjectLock);
	m_bIsListener = rtpListener;
	return S_OK;
}

STDMETHODIMP CRtpSocketBase::CreateSockets(SocketAddresses* pAddresses)
{
	CheckPointer(pAddresses, E_POINTER);

	CheckPointer(!m_pRtpAddresses, E_UNEXPECTED);
	CheckPointer(!m_pRtcpAddresses, E_UNEXPECTED);

	CAutoLock lock(&m_critSectObjectLock);

	WinsockHelper_DebugPrintSockaddr((sockaddr*)&pAddresses->localAddress, pAddresses->cbSockaddr);
	WinsockHelper_DebugPrintSockaddr((sockaddr*)&pAddresses->remoteAddress, pAddresses->cbSockaddr);
	
	if (pAddresses->cbSize != sizeof(SocketAddresses) && pAddresses->cbSize != sizeof(SocketAddressesIPMcast))
	{
		return E_INVALIDARG;
	}

	HRESULT hr = S_OK;
	INT wsaRetVal = 0;
	INT wsaLastError = 0;

	m_pRtpAddresses = (SocketAddresses*)SAFE_ALLOC(pAddresses->cbSize);
	if (m_pRtpAddresses == NULL)
	{
		return E_OUTOFMEMORY;
	}
	CopyMemory(m_pRtpAddresses, pAddresses, pAddresses->cbSize);

	BOOL bDestinationIsMCast = (S_OK == WinsockHelper_IsMulticastAddress((sockaddr*)&(m_pRtpAddresses->remoteAddress), m_pRtpAddresses->cbSockaddr));
	if (bDestinationIsMCast)
	{
		SocketAddressesIPMcast *pSocketAddressesIPMCast = NULL;
		hr = WinsockHelper_ExpandMulticastAddress(m_pRtpAddresses, &pSocketAddressesIPMCast);
		VALHR(hr);

		SAFE_FREE(m_pRtpAddresses);
		m_pRtpAddresses = pSocketAddressesIPMCast;
	}

	m_pRtcpAddresses = (SocketAddresses*)SAFE_ALLOC(m_pRtpAddresses->cbSize);
	if (m_pRtcpAddresses == NULL)
	{
		ASSERT(0);
		return E_OUTOFMEMORY;
	}

	if (!m_pRtpAddresses->isLocalAddressSpecified && !bDestinationIsMCast)
	{
		ZeroMemory(&(m_pRtpAddresses->localAddress), m_pRtpAddresses->cbSockaddr);
		INT cbSockaddrLocal = m_pRtpAddresses->cbSockaddr;
		
		if (SUCCEEDED(WinsockHelper_GetLocalRoutingInterface(
			(sockaddr*)&(m_pRtpAddresses->remoteAddress), 
			m_pRtpAddresses->cbSockaddr, 
			(sockaddr*)&(m_pRtpAddresses->localAddress),
			&cbSockaddrLocal
			)) && (cbSockaddrLocal == m_pRtpAddresses->cbSockaddr))
		{
			// OK, resolved Local IFace
		}
		else
		{
			ATLASSERT(0);
			hr = E_FAIL;
			goto cleanup;
		}
	}

	CopyMemory(m_pRtcpAddresses, m_pRtpAddresses, m_pRtpAddresses->cbSize);

	m_pRtcpAddresses->remoteAddress.ipv4.sin_port = htons(ntohs(m_pRtpAddresses->remoteAddress.ipv4.sin_port) + 1);

	if (bDestinationIsMCast)
	{
		m_pRtcpAddresses->localAddress.ipv4.sin_port = m_pRtcpAddresses->remoteAddress.ipv4.sin_port;
	}
	else
	{
		m_pRtcpAddresses->localAddress.ipv4.sin_port = htons(ntohs(m_pRtpAddresses->localAddress.ipv4.sin_port) + 1);
	}

#if GQOS_ENABLED
	WSAPROTOCOL_INFO wsaProtocolInfo;
	hr = GQoSHelper_FindProvider(m_pRtpAddresses->remoteAddress.ipv4.sin_family, &wsaProtocolInfo);

	if (hr == S_OK)
	{
		m_bGQoSEnabled = TRUE;
		ATLTRACE2("Quality Of Service Enabled \r\n");
	}
	else
	{
		m_bGQoSEnabled = FALSE;
	}

retry:
	m_scktRtpBaseSocket = WSASocket(
		m_pRtpAddresses->remoteAddress.ipv4.sin_family, SOCK_DGRAM, IPPROTO_UDP, 
		(m_bGQoSEnabled ? &wsaProtocolInfo : NULL), 
		NULL, 
		WSA_FLAG_OVERLAPPED | WSA_FLAG_MULTIPOINT_C_LEAF | WSA_FLAG_MULTIPOINT_D_LEAF);
	if (m_scktRtpBaseSocket == INVALID_SOCKET)
	{
		if (m_bGQoSEnabled)
		{
			m_bGQoSEnabled = FALSE;
			goto retry;
		}

		wsaLastError = WSAGetLastError();
		hr = E_FAIL;
		goto cleanup;
	}

	m_scktRtcpBaseSocket = WSASocket(
		m_pRtcpAddresses->localAddress.ipv4.sin_family, SOCK_DGRAM, IPPROTO_UDP, 
		(m_bGQoSEnabled ? &wsaProtocolInfo : NULL), 
		NULL, 
		WSA_FLAG_OVERLAPPED | WSA_FLAG_MULTIPOINT_C_LEAF | WSA_FLAG_MULTIPOINT_D_LEAF);
	if (m_scktRtcpBaseSocket == INVALID_SOCKET)
	{
		wsaLastError = WSAGetLastError();
		hr = E_FAIL;
		goto cleanup;
	}
#else
	m_scktRtpBaseSocket = WSASocket(
		m_pRtpAddresses->remoteAddress.ipv4.sin_family, SOCK_DGRAM, IPPROTO_UDP, NULL, NULL, 
		WSA_FLAG_OVERLAPPED | WSA_FLAG_MULTIPOINT_C_LEAF | WSA_FLAG_MULTIPOINT_D_LEAF);
	if (m_scktRtpBaseSocket == INVALID_SOCKET)
	{
		wsaLastError = WSAGetLastError();
		hr = E_FAIL;
		goto cleanup;
	}

	m_scktRtcpBaseSocket = WSASocket(
		m_pRtcpAddresses->localAddress.ipv4.sin_family, SOCK_DGRAM, IPPROTO_UDP, NULL, NULL, 
		WSA_FLAG_OVERLAPPED | WSA_FLAG_MULTIPOINT_C_LEAF | WSA_FLAG_MULTIPOINT_D_LEAF);
	if (m_scktRtcpBaseSocket == INVALID_SOCKET)
	{
		wsaLastError = WSAGetLastError();
		hr = E_FAIL;
		goto cleanup;
	}
#endif
	
	DWORD dwValue;
	dwValue = m_pRtpAddresses->bExclusiveAddrUse;
	wsaRetVal = setsockopt(m_scktRtpBaseSocket, SOL_SOCKET, SO_EXCLUSIVEADDRUSE, (char*)&dwValue, sizeof(DWORD));
	wsaRetVal = setsockopt(m_scktRtcpBaseSocket, SOL_SOCKET, SO_EXCLUSIVEADDRUSE, (char*)&dwValue, sizeof(DWORD));

	dwValue = (!m_pRtpAddresses->bDontReuseAddr);
	wsaRetVal = setsockopt(m_scktRtpBaseSocket, SOL_SOCKET, SO_REUSEADDR, (char*)&dwValue, sizeof(DWORD));
	wsaRetVal = setsockopt(m_scktRtcpBaseSocket, SOL_SOCKET, SO_REUSEADDR, (char*)&dwValue, sizeof(DWORD));

	// Bind
	wsaRetVal = bind(m_scktRtpBaseSocket, (sockaddr*)&(m_pRtpAddresses->localAddress), m_pRtpAddresses->cbSockaddr);
	if (!m_pRtpAddresses->isLocalAddressSpecified)
	{
		INT cbSockaddr = m_pRtpAddresses->cbSockaddr;
		wsaRetVal = getsockname(m_scktRtpBaseSocket, (sockaddr*)&(m_pRtpAddresses->localAddress), &cbSockaddr);
	}

	wsaRetVal = bind(m_scktRtcpBaseSocket, (sockaddr*)&(m_pRtcpAddresses->localAddress), m_pRtcpAddresses->cbSockaddr);
	if (!m_pRtcpAddresses->isLocalAddressSpecified)
	{
		INT cbSockaddr = m_pRtcpAddresses->cbSockaddr;
		wsaRetVal = getsockname(m_scktRtcpBaseSocket, (sockaddr*)&(m_pRtcpAddresses->localAddress), &cbSockaddr);
	}
	
	// Join Mcast Group
	if (S_OK == WinsockHelper_IsMulticastAddress((sockaddr*)&(m_pRtpAddresses->remoteAddress), m_pRtpAddresses->cbSockaddr))
	{
		ATLASSERT(m_pRtpAddresses->cbSize == sizeof(SocketAddressesIPMcast));

		SocketAddressesIPMcast *pRtpMcast = (SocketAddressesIPMcast*)m_pRtpAddresses;
		SocketAddressesIPMcast *pRtcpMcast = (SocketAddressesIPMcast*)m_pRtcpAddresses;

		if (pRtpMcast->isIPv6)
		{
			dwValue = MULTICAST_LOOP;
			wsaRetVal = WinsockHelper_ValidateRetVal(setsockopt(m_scktRtpBaseSocket, IPPROTO_IPV6, IPV6_MULTICAST_LOOP, (char*)&dwValue, sizeof(DWORD)));
			wsaRetVal = WinsockHelper_ValidateRetVal(setsockopt(m_scktRtpBaseSocket, IPPROTO_IPV6, IPV6_MULTICAST_HOPS, (char*)&(pRtpMcast->Ttl), sizeof(DWORD)));

			m_scktRtpSocket = WSAJoinLeaf(
				m_scktRtpBaseSocket, 
				(sockaddr*)&(m_pRtpAddresses->remoteAddress), m_pRtpAddresses->cbSockaddr, NULL, NULL, NULL, NULL,
				(m_bIsListener ? JL_BOTH : JL_SENDER_ONLY));
			dwValue = MULTICAST_LOOP;
			wsaRetVal = setsockopt(m_scktRtcpBaseSocket, IPPROTO_IPV6, IPV6_MULTICAST_LOOP, (char*)&dwValue, sizeof(DWORD));
			wsaRetVal = setsockopt(m_scktRtcpBaseSocket, IPPROTO_IPV6, IPV6_MULTICAST_HOPS, (char*)&(pRtcpMcast->Ttl), sizeof(DWORD));
			
			m_scktRtcpSocket = WSAJoinLeaf(
				m_scktRtcpBaseSocket, 
				(sockaddr*)&(m_pRtcpAddresses->remoteAddress), 
				m_pRtcpAddresses->cbSockaddr, 
				NULL, NULL, NULL, NULL, 
				JL_BOTH);
		}
		else
		{
			dwValue = MULTICAST_LOOP;
			wsaRetVal = WinsockHelper_ValidateRetVal(setsockopt(m_scktRtpBaseSocket, IPPROTO_IP, IP_MULTICAST_LOOP, (char*)&dwValue, sizeof(DWORD)));
			wsaRetVal = WinsockHelper_ValidateRetVal(setsockopt(m_scktRtpBaseSocket, IPPROTO_IP, IP_MULTICAST_TTL, (char*)&(pRtpMcast->Ttl), sizeof(DWORD)));

			m_scktRtpSocket = WSAJoinLeaf(
				m_scktRtpBaseSocket, (sockaddr*)&(m_pRtpAddresses->remoteAddress), sizeof(sockaddr_in), NULL, NULL, NULL, NULL, 
				(m_bIsListener ? JL_BOTH : JL_SENDER_ONLY));

			dwValue = MULTICAST_LOOP;
			wsaRetVal = WinsockHelper_ValidateRetVal(setsockopt(m_scktRtcpBaseSocket, IPPROTO_IP, IP_MULTICAST_LOOP, (char*)&dwValue, sizeof(DWORD)));
			wsaRetVal = WinsockHelper_ValidateRetVal(setsockopt(m_scktRtcpBaseSocket, IPPROTO_IP, IP_MULTICAST_TTL, (char*)&(pRtcpMcast->Ttl), sizeof(DWORD)));
			m_scktRtcpSocket = WSAJoinLeaf(
				m_scktRtcpBaseSocket, 
				(sockaddr*)&(m_pRtcpAddresses->remoteAddress), 
				m_pRtcpAddresses->cbSockaddr, 
				NULL, NULL, NULL, NULL, 
				JL_BOTH);

			WinsockHelper_DebugPrintSockaddr((sockaddr*)&(pRtcpMcast->localAddress), sizeof(sockaddr_in));
			WinsockHelper_DebugPrintSockaddr((sockaddr*)&(pRtcpMcast->remoteAddress), sizeof(sockaddr_in));
		}
	}
	else
	{
		m_scktRtpSocket = m_scktRtpBaseSocket;
		m_scktRtcpSocket = m_scktRtcpBaseSocket;
	}

	//////////////////////////////////////////////////////////////////////////
	DWORD dwBytesReturned = 0;
	// SIO_ENABLE_CIRCULAR_QUEUEING anschalten
	wsaRetVal = WSAIoctl(m_scktRtpSocket, SIO_ENABLE_CIRCULAR_QUEUEING, NULL, 0, NULL, 0, &dwBytesReturned, NULL, NULL);
	wsaRetVal = WSAIoctl(m_scktRtcpSocket, SIO_ENABLE_CIRCULAR_QUEUEING, NULL, 0, NULL, 0, &dwBytesReturned, NULL, NULL);

	//////////////////////////////////////////////////////////////////////////
	m_pSockkaddrRecvFromRtpSocket = (sockaddr*)SAFE_ALLOC(m_pRtpAddresses->cbSockaddr);
	CheckPointerJIF(m_pSockkaddrRecvFromRtpSocket, E_OUTOFMEMORY);
	m_pSockkaddrRecvFromRtcpSocket = (sockaddr*)SAFE_ALLOC(m_pRtpAddresses->cbSockaddr);
	CheckPointerJIF(m_pSockkaddrRecvFromRtcpSocket, E_OUTOFMEMORY);
	m_cbSockkaddrRecvFromRtpSocketFromLen = sizeof(sockaddr_in);
	m_cbSockkaddrRecvFromRtcpSocketFromLen = sizeof(sockaddr_in);

	return IntializeOverlappedReceiveStruct();
	// return S_OK;
cleanup:
	SAFE_CLOSE_SOCKET(m_scktRtcpSocket);	
	SAFE_CLOSE_SOCKET(m_scktRtpSocket);	
	SAFE_FREE(m_pRtcpAddresses);
	SAFE_FREE(m_pRtpAddresses);

	SAFE_FREE(m_pSockkaddrRecvFromRtpSocket);
	SAFE_FREE(m_pSockkaddrRecvFromRtcpSocket);
	m_cbSockkaddrRecvFromRtpSocketFromLen = 0;
	m_cbSockkaddrRecvFromRtcpSocketFromLen = 0;

	return hr;
}

STDMETHODIMP CRtpSocketBase::InitializeOverlapped()
{
	CAutoLock lock(&m_critSectObjectLock);
	
	m_cRtpReceiveBuffer = 1;
	m_cRtcpReceiveBuffer = 1;
	m_cbRtpReceiveBuffer = 1500;
	m_cbRtcpReceiveBuffer = 1500;
	m_pRtpReceiveBufferContinuous = NULL;
	m_pRtcpReceiveBufferContinuous = NULL;

	HRESULT hr = S_OK;

	hr = InitializeReceiverThread();
	if (FAILED(hr)) goto cleanup;


	m_pWsaOverlappedRtcpReceiver = (LPWSAOVERLAPPED)SAFE_ALLOC(sizeof(WSAOVERLAPPED));
	CheckPointerJIF(m_pWsaOverlappedRtcpReceiver, E_OUTOFMEMORY);
	m_pWsaOverlappedRtcpReceiver->hEvent = this; //m_wsaReceiveEvents[1];

	m_pwsabufRtcpReceiver = (LPWSABUF)SAFE_ALLOC(sizeof(WSABUF) * m_cRtcpReceiveBuffer);
	CheckPointerJIF(m_pwsabufRtcpReceiver, E_OUTOFMEMORY);
	
	m_pRtcpReceiveBufferContinuous = (BYTE*)SAFE_ALLOC(m_cbRtcpReceiveBuffer * m_cRtcpReceiveBuffer);
	CheckPointerJIF(m_pRtcpReceiveBufferContinuous, E_OUTOFMEMORY);

	for (UINT u = 0; u < m_cRtcpReceiveBuffer; u++)
	{
		m_pwsabufRtcpReceiver[u].buf = (CHAR*)(m_pRtcpReceiveBufferContinuous + u * m_cbRtcpReceiveBuffer);
		m_pwsabufRtcpReceiver[u].len = m_cbRtcpReceiveBuffer;
	}

	return S_OK;

cleanup:
	SAFE_FREE(m_pWsaOverlappedRtpReceiver);
	SAFE_FREE(m_pWsaOverlappedRtcpReceiver);
	SAFE_FREE(m_pwsabufRtpReceiver);
	SAFE_FREE(m_pwsabufRtcpReceiver);
	SAFE_FREE(m_pRtpReceiveBufferContinuous);
	SAFE_FREE(m_pRtcpReceiveBufferContinuous);

	return hr;
}

STDMETHODIMP CRtpSocketBase::IntializeOverlappedReceiveStruct(VOID)
{
	CheckPointer(m_pRtpAddresses, E_UNEXPECTED);
	CheckPointer(!m_pWsaOverlappedInstanceData, E_UNEXPECTED);
	
	HRESULT hr = InitializeOverlapped();
	VALHR(hr);

	m_hEventReceiveWorkerThreadWakeupEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	if (m_hEventReceiveWorkerThreadWakeupEvent == NULL)
	{
		ASSERT(0);
		return E_FAIL;
	}

	if (m_pWsaOverlappedInstanceData != NULL)
	{
		if (m_cWsaOverlappedInstanceData == PARALLEL_PENDING_RTP_RECVFROM_CALLS)
		{
			// Did not change
			return S_FALSE;
		}
		else
		{
			ASSERT(FALSE);
			return E_FAIL;
		}
	}

	UINT cbReceiveBufferSize = RTP_RECV_BUFFER_SIZE;
	ASSERT(m_pRtpAddresses);
	ASSERT(m_pRtpAddresses->cbSockaddr);
	UINT cbSockaddress = m_pRtpAddresses->cbSockaddr;
	UINT cbNeeded = 
		PARALLEL_PENDING_RTP_RECVFROM_CALLS *
		(
			sizeof(WSAOVERLAPPED_INSTANCE_DATA)
			+ sizeof(WSABUF)
			+ cbSockaddress
			+ cbReceiveBufferSize
		);
	m_pWsaOverlappedInstanceData = (WSAOVERLAPPED_INSTANCE_DATA*)SAFE_ALLOC(cbNeeded);
	CheckPointer(m_pWsaOverlappedInstanceData, E_OUTOFMEMORY);

	m_cWsaOverlappedInstanceData = PARALLEL_PENDING_RTP_RECVFROM_CALLS;
	
	BYTE* pWsaOverlappedInstanceDataStart = (BYTE*)m_pWsaOverlappedInstanceData;
	BYTE* pSockaddrStart = pWsaOverlappedInstanceDataStart + m_cWsaOverlappedInstanceData * sizeof(WSAOVERLAPPED_INSTANCE_DATA);
	BYTE* pWsabufStart = pSockaddrStart + m_cWsaOverlappedInstanceData * cbSockaddress;
	BYTE* pRecvBufferStart = pWsabufStart + m_cWsaOverlappedInstanceData * sizeof(WSABUF);

	for (UINT intIterator = 0; intIterator < m_cWsaOverlappedInstanceData; intIterator++)
	{
		m_pWsaOverlappedInstanceData[intIterator].uIndex = intIterator;
		m_pWsaOverlappedInstanceData[intIterator].bCallPending = FALSE;
		m_pWsaOverlappedInstanceData[intIterator].cbSockaddr = cbSockaddress;
		m_pWsaOverlappedInstanceData[intIterator].lpInstance = this;
		m_pWsaOverlappedInstanceData[intIterator].pSockaddressReceivedFrom = (sockaddr*)(pSockaddrStart + (intIterator * cbSockaddress));
		m_pWsaOverlappedInstanceData[intIterator].pWsaBuf = (WSABUF*)(pWsabufStart + intIterator * sizeof(WSABUF));
		m_pWsaOverlappedInstanceData[intIterator].pWsaBuf->len = RTP_RECV_BUFFER_SIZE;
		m_pWsaOverlappedInstanceData[intIterator].pWsaBuf->buf = (CHAR*)(pRecvBufferStart + intIterator * RTP_RECV_BUFFER_SIZE);
	}

	// WSAOVERLAPPED allokieren
	m_pWsaOverlappedRtpRecvFrom = (WSAOVERLAPPED*)SAFE_ALLOC(sizeof(WSAOVERLAPPED) * m_cWsaOverlappedInstanceData);
	CheckPointerJIF(m_pWsaOverlappedRtpRecvFrom, E_OUTOFMEMORY);

	for (UINT intIterator = 0; intIterator < m_cWsaOverlappedInstanceData; intIterator++)
	{
		m_pWsaOverlappedRtpRecvFrom[intIterator].hEvent = &(m_pWsaOverlappedInstanceData[intIterator]);
	}
	
	return S_OK;
cleanup:
	SAFE_FREE(m_pWsaOverlappedRtpRecvFrom);
	SAFE_FREE(m_pWsaOverlappedInstanceData);
	m_cWsaOverlappedInstanceData = 0;

	return hr;
}

STDMETHODIMP CRtpSocketBase::InitializeReceiverThread()
{
	HRESULT hr = E_FAIL;
	m_wsaReceiveEvents[0] = WSACreateEvent();
	if (WSA_INVALID_EVENT == m_wsaReceiveEvents[0])
	{
		goto cleanup;
	}

	m_wsaReceiveEvents[1] = WSACreateEvent();
	if (WSA_INVALID_EVENT == m_wsaReceiveEvents[1])
	{
		goto cleanup;
	}

	m_dwWsaReceiveEvents = 2;

	if (m_bIsListener)
	{
		m_wsaReceiveEvents[2] = WSACreateEvent();
		if (WSA_INVALID_EVENT == m_wsaReceiveEvents[2])
		{
			goto cleanup;
		}
		m_dwWsaReceiveEvents = 3;
	}

	m_hEventWorkerThreadStartThreadProc = CreateEvent(NULL, TRUE, FALSE, NULL);
	if (NULL == m_hEventWorkerThreadStartThreadProc)
	{
		goto cleanup;
	}

	// Create Thread
	m_hReceiverWorkerThread = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)CRtpSocketBase::StaticReceiveThreadThreadProc, this, CREATE_SUSPENDED, NULL);
	if (m_hReceiverWorkerThread == NULL)
	{
		goto cleanup;
	}
	m_bReceiveWorkerThreadAlive = TRUE;	

	m_hEventWorkerThreadDied = CreateEvent(NULL, TRUE, FALSE, NULL);
	if (m_hEventWorkerThreadDied == NULL || m_hEventWorkerThreadDied == INVALID_HANDLE_VALUE)
	{
		goto cleanup;
	}

	DWORD dwRetVal = ResumeThread(m_hReceiverWorkerThread);
	if (dwRetVal != 1)
	{
		ASSERT(0);
		goto cleanup;
	}

	return S_OK;
cleanup:
	SAFE_CLOSE_WSAEVENT(m_wsaReceiveEvents[0]);
	SAFE_CLOSE_WSAEVENT(m_wsaReceiveEvents[1]);
	SAFE_CLOSE_WSAEVENT(m_wsaReceiveEvents[2]);
	SAFE_CLOSE_HANDLE(m_hReceiverWorkerThread);
	SAFE_CLOSE_HANDLE(m_hEventWorkerThreadDied);
	SAFE_CLOSE_HANDLE(m_hEventWorkerThreadStartThreadProc);
	DeleteCriticalSection(&m_critSectReceiverWorkerThread);
	m_bReceiveWorkerThreadAlive = FALSE;
	return hr;
}

DWORD WINAPI CRtpSocketBase::StaticReceiveThreadThreadProc( LPVOID lpThreadParameter )
{
	ASSERT(lpThreadParameter);

	HRESULT hr = CoInitializeEx(NULL, COINIT_MULTITHREADED|COINIT_SPEED_OVER_MEMORY);
	ATLTRACE2("CRtpSocketBase::StaticReceiveThreadThreadProc CoInitializeEx 0x%x \r\n", hr);

	return ((CRtpSocketBase*)lpThreadParameter)->InstanceReceiveThreadThreadProc();
}

DWORD WINAPI CRtpSocketBase::InstanceReceiveThreadThreadProc(VOID)
{
	DWORD dwWaitResult = 0;
	DWORD dwBytesRead = 0;
	DWORD dwFlags = 0;
	HRESULT hr = S_OK;

	HANDLE hEventsStartThreadProcOrExitThreadProc[2];
	hEventsStartThreadProcOrExitThreadProc[0] = m_hEventWorkerThreadStartThreadProc;
	hEventsStartThreadProcOrExitThreadProc[1] = m_hEventReceiveWorkerThreadWakeupEvent;

	do 
	{
		dwWaitResult = WaitForMultipleObjects(
			2,
			hEventsStartThreadProcOrExitThreadProc, 
			FALSE, 
			INFINITE);

		if (dwWaitResult == WAIT_OBJECT_0)
		{
			hr = RtcpListen();
			if (FAILED(hr))
			{
				ASSERT(0);
				return(99);
			}

			if (m_bIsListener) 
			{
				for (UINT iterator = 0; iterator < m_cWsaOverlappedInstanceData; iterator++)
				{
					hr = RtpListen(iterator);
					if (FAILED(hr))
					{
						ASSERT(0);
						// Fehler
						return(99);
					}
				}
			}			

			while (m_bReceiveWorkerThreadListening) 
			{
				dwWaitResult = WaitForSingleObjectEx(m_hEventReceiveWorkerThreadWakeupEvent, INFINITE, TRUE);
				ASSERT(dwWaitResult == WAIT_OBJECT_0 || dwWaitResult == WAIT_IO_COMPLETION);
				if (dwWaitResult == WAIT_IO_COMPLETION) 
				{
					// ATLTRACE2(" WaitForMultipleEventsEx WAIT_IO_COMPLETION \r\n");
				}
			}

			continue;
			if (dwWaitResult == WAIT_OBJECT_0)
			{
				// Wakeup Call
			}
			else if (dwWaitResult == (WAIT_OBJECT_0 + 1))
			{
				// RTCP data available
			}
			else if (dwWaitResult == (WAIT_OBJECT_0 + 2))
			{
				// RTP Data Available
				ASSERT(m_bIsListener);
			}
		}
		else if (dwWaitResult == (WAIT_OBJECT_0 + 1))
		{
			// terminate
			break;
		}
		else
		{
			// unexpected error
			if ((dwWaitResult == WAIT_ABANDONED_0) || (dwWaitResult == (WAIT_ABANDONED_0 + 1)))
			{
				ASSERT(0);
			}
			else if (dwWaitResult == WAIT_TIMEOUT)
			{
				// :-() geht nicht
			}
		}
	} 
	while(m_bReceiveWorkerThreadAlive);


	SetEvent(m_hEventWorkerThreadDied);
	ExitThread(0);
	return(0);
}


STDMETHODIMP CRtpSocketBase::StartListen(VOID)
{
	CAutoLock lock(&m_critSectObjectLock);
	
	if (m_bListenState) return S_FALSE;

	m_bListenState = TRUE;

	this->CreateRtcpTimer();

	m_bReceiveWorkerThreadListening = TRUE;
	BOOL bRetVal = SetEvent(m_hEventWorkerThreadStartThreadProc);
	if (!bRetVal) 
	{ 
		LPVOID pBuffer; 
		FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER , NULL, GetLastError(), NULL, (LPTSTR)&pBuffer, 0, NULL); 
		ATLTRACE2("VALRV: Message: '%s' File: '%s', Line: %d", (LPTSTR)pBuffer, __FILE__, __LINE__); 
		LocalFree(pBuffer); 
	} 
	ASSERT(bRetVal);

	if (m_hReceiverWorkerThread == NULL || m_hReceiverWorkerThread == INVALID_HANDLE_VALUE)
	{
		ASSERT(0);
		goto cleanup;
	}

	return S_OK;
cleanup:
	UninitializeRtcpTimer();

	return E_FAIL;
}

STDMETHODIMP CRtpSocketBase::StopListen()
{
	CAutoLock lock(&m_critSectObjectLock);

	m_bListenState = FALSE;
	this->UninitializeRtcpTimer();

	m_bReceiveWorkerThreadListening = FALSE;
	BOOL bRetVal = ResetEvent(m_hEventWorkerThreadStartThreadProc);
	ASSERT(bRetVal);
	// wakeup the thread
	bRetVal = SetEvent(m_hEventReceiveWorkerThreadWakeupEvent);
	ASSERT(bRetVal);
	
	return S_OK;
}

STDMETHODIMP CRtpSocketBase::RtpListen(UINT uBufIdx)
{
	CheckPointer(m_pWsaOverlappedRtpRecvFrom, E_UNEXPECTED);

	CAutoLock lock(&m_critSectObjectLock);

	if(!m_bListenState) return E_FAIL;

	if(uBufIdx >= m_cWsaOverlappedInstanceData) 
	{
		ASSERT(0);
		return E_INVALIDARG;
	}
	if (m_pWsaOverlappedInstanceData[uBufIdx].bCallPending)
	{
		return S_FALSE;
	}

	DWORD dwBytesReadIfSync = 0;
	DWORD dwFlags = 0;

	INT wsaRetVal = 0;
	do 
	{

#if SINGLE_RTP_BUFFER
		wsaRetVal = WSARecvFrom(
			m_scktRtpBaseSocket,

			m_pwsabufRtpReceiver, m_cRtpReceiveBuffer, 
			&dwBytesReadIfSync, &dwFlags, 
			
			m_pSockkaddrRecvFromRtpSocket, &m_cbSockkaddrRecvFromRtpSocketFromLen,
			
			m_pWsaOverlappedRtpReceiver,
			(LPWSAOVERLAPPED_COMPLETION_ROUTINE)CRtpSocketBase::ReceiveFromRtpSocketCompletionRoutine);
#else
		wsaRetVal = WSARecvFrom(
			m_scktRtpSocket,
			m_pWsaOverlappedInstanceData[uBufIdx].pWsaBuf, 1,
			&dwBytesReadIfSync, &dwFlags, 
			m_pWsaOverlappedInstanceData[uBufIdx].pSockaddressReceivedFrom, 		
			&(m_pWsaOverlappedInstanceData[uBufIdx].cbSockaddr), 
			&(m_pWsaOverlappedRtpRecvFrom[uBufIdx]),
			(LPWSAOVERLAPPED_COMPLETION_ROUTINE)CRtpSocketBase::ReceiveFromRtpSocketCompletionRoutine);

#endif
		if (wsaRetVal == 0)
		{
			while (WAIT_IO_COMPLETION == SleepEx(0, TRUE));

			return S_OK;
		}
		else
		{
			INT wsaLastError = WSAGetLastError();

			if (wsaLastError == WSA_IO_PENDING)
			{
				// Async
				m_pWsaOverlappedInstanceData[uBufIdx].bCallPending = TRUE;
				return S_FALSE;
			}
			else
			{
				wsaLastError = WSAGetLastError();
				ASSERT(FALSE);
			}
		}
	} while((wsaRetVal == 0) && m_bListenState);

	return E_FAIL;
}

STDMETHODIMP CRtpSocketBase::RtcpListen()
{
	CheckPointer(m_pWsaOverlappedRtcpReceiver, E_UNEXPECTED);

	if (!m_bListenState) return E_FAIL;

	if (m_bRtcpReceiveQueuedCallPending)
	{
		// still a call pending
		return S_FALSE;
	}

	DWORD dwBytesReadIfSync = 0;
	DWORD dwFlags = 0;
	INT wsaRetVal = 0;
	do 
	{
		wsaRetVal = WSARecvFrom(
			m_scktRtcpSocket, 
			m_pwsabufRtcpReceiver, m_cRtcpReceiveBuffer, 
			&dwBytesReadIfSync, &dwFlags, 
			m_pSockkaddrRecvFromRtcpSocket, &m_cbSockkaddrRecvFromRtcpSocketFromLen,
			m_pWsaOverlappedRtcpReceiver,
			(LPWSAOVERLAPPED_COMPLETION_ROUTINE)CRtpSocketBase::ReceiveFromRtcpSocketCompletionRoutine);

		if (wsaRetVal == 0)
		{
			while (WAIT_IO_COMPLETION == SleepEx(0, TRUE));

			return S_OK;
		}
		else
		{
			INT wsaLastError = WSAGetLastError();

			if (wsaLastError == WSA_IO_PENDING)
			{
				m_bRtcpReceiveQueuedCallPending = TRUE;
				// Async
				return S_FALSE;
			}
			else
			{
				wsaLastError = WSAGetLastError();
				ASSERT(FALSE);
			}
		}
	} while((wsaRetVal == 0) && m_bListenState);

	return E_FAIL;
}

VOID CALLBACK CRtpSocketBase::ReceiveFromRtpSocketCompletionRoutine(
	DWORD dwError, 
	DWORD cbTransferred, 
	LPWSAOVERLAPPED lpOverlapped, 
	DWORD dwFlags)
{
	if (!lpOverlapped) return;
	if (!lpOverlapped->hEvent) return;

#if SINGLE_RTP_BUFFER
	CRtpSocketBase *pRtpSocketBaseInstance = (CRtpSocketBase*)lpOverlapped->hEvent;
	ASSERT(0);
#else

	WSAOVERLAPPED_INSTANCE_DATA* pWsaInstanceData = (WSAOVERLAPPED_INSTANCE_DATA*)lpOverlapped->hEvent;
	if (pWsaInstanceData->lpInstance == NULL)
	{
		// unbehebbarer Fehler
		ASSERT(0);
		return;
	}

	CRtpSocketBase *pRtpSocketBaseInstance = (CRtpSocketBase*)pWsaInstanceData->lpInstance;

	// auch bei Fehler
	pWsaInstanceData->bCallPending = FALSE;

	HRESULT hr = S_OK;
	if ((dwError == 0) && pRtpSocketBaseInstance->m_bListenState)
	{
		hr = pRtpSocketBaseInstance->HandleRtpData(
			pWsaInstanceData->uIndex, cbTransferred);
		ASSERT(SUCCEEDED(hr));

		hr = pRtpSocketBaseInstance->RtpListen(pWsaInstanceData->uIndex);
		ASSERT(SUCCEEDED(hr));

		return;
	}
	else
	{
		if (dwError == SOCKET_ERROR)
		{
			INT wsaLastError = WSAGetLastError();
			ATLTRACE2("!!!!!!!!!!!!!!!!!!!! %s %d %s \r\n", __FUNCTION__, wsaLastError, gai_strerror(wsaLastError));
			ASSERT(0);
			return;
		}
	}
#endif

	ASSERT(0);
	ATLTRACE2("RTP LISTEN: Thread \"stirbt\" \r\n");
}

VOID CALLBACK CRtpSocketBase::ReceiveFromRtcpSocketCompletionRoutine(
	DWORD dwError, 
	DWORD cbTransferred, 
	LPWSAOVERLAPPED lpOverlapped, 
	DWORD dwFlags)
{
	if (!lpOverlapped) return;
	if (!lpOverlapped->hEvent) return;

	CRtpSocketBase *pInstanceData = (CRtpSocketBase*)lpOverlapped->hEvent;

	if (pInstanceData)
	{
		// auch wenn dwError != 0 !!!
		pInstanceData->m_bRtcpReceiveQueuedCallPending = FALSE;
	}

	HRESULT hr = S_OK;

	if ((dwError == 0) && pInstanceData->m_bListenState)
	{
		hr = pInstanceData->HandleRtcpData(
			pInstanceData->m_pRtcpReceiveBufferContinuous, cbTransferred);
		ASSERT(SUCCEEDED(hr));

		hr = pInstanceData->RtcpListen();
		ASSERT(SUCCEEDED(hr));

		return;
	}
	else
	{
		if (dwError == SOCKET_ERROR)
		{
			INT wsaLastError = WSAGetLastError();
			ATLTRACE2("!!!!!!!!!!!!!!!!!! %s %d %s \r\n", __FUNCTION__, wsaLastError, gai_strerror(wsaLastError));
			ASSERT(0);
			return;
		}
	}

	ATLTRACE2("RTCCCCP LISTEN: Thread \"stirbt\" \r\n");
}

STDMETHODIMP CRtpSocketBase::HandleRtpData(UINT uBufferIndex, DWORD dwBytesRead)
{
	if (uBufferIndex >= m_cWsaOverlappedInstanceData) return E_INVALIDARG;
	if (dwBytesRead < RTP_CONSTANTS_RTP_FIXED_HEADER_SIZE) return E_INVALIDARG;

	BYTE* pBuffer = (BYTE*)m_pWsaOverlappedInstanceData[uBufferIndex].pWsaBuf->buf;

	ASSERT(pBuffer);

	{
		UINT ssrc = 0;
		BufferUtil_GetHostByteOrderUint(pBuffer, 8, &ssrc);
		if (ssrc == m_ssrc) 
		{
			return S_FALSE;
		}
		if (ssrc == 0)
		{
			ASSERT(0);
			return S_FALSE;
		}

		RtpParsedPacket *pParsedPacket = NULL;
		HRESULT hr = RtpPacketUtil_ParseRtpPacket(pBuffer, dwBytesRead, &pParsedPacket);
		ASSERT(SUCCEEDED(hr));

		if (S_OK == UpdateSessionMember(pParsedPacket))
		{
			HandleParsedRtpPacket(pParsedPacket);
		}
	}
	
	return NOERROR;
}

STDMETHODIMP CRtpSocketBase::HandleRtcpData(BYTE* pBuffer, DWORD dwBytesRead) //BYTE* pWsaBuffers, INT cBuffers)
{
	CheckPointer(pBuffer, E_POINTER);
	if (dwBytesRead <= 0) return E_INVALIDARG;

	UINT cbParsed = 0;

	HRESULT hr = S_OK;
	BYTE* pCurrentBufferPtr = pBuffer;
	UINT cbCurrentBuffer = dwBytesRead;

	do 
	{
		ASSERT(!(cbCurrentBuffer % 4));

		UINT cbLength = RtcpHeaderUtil_GetPacketLengthByte(pCurrentBufferPtr);

		UINT ssrc = 0;
		BufferUtil_GetHostByteOrderUint(pCurrentBufferPtr, 4, &ssrc);
		if (m_ssrc == ssrc) 
		{
			return S_FALSE;
		}
		else
		{
			CRtpSessionMember *pMember = NULL;
			CAutoLock lock(&m_critSectRtpSessionMembersMapSynchronization);

			if (m_mapRtpSessionMembers.Lookup(ssrc, pMember))
			{
				if (!pMember)
				{
					ASSERT(0);
					pMember = NULL;
				}
			}
			else
			{
				pMember = NULL;
				ATLTRACE2("REceived A RTCP Packet from Unknown Source: 0x%x \r\n", ssrc);
			}

			switch(RtcpHeaderUtil_GetPacketType(pCurrentBufferPtr)) 
			{
			case RTCP_PACKET_TYPE_SDES:
				{
					ATLTRACE2("RTCP_PACKET_TYPE_SDES: 0x%x \r\n", ssrc);

					if (!pMember) break;

					SdesItems *pSdesItems = NULL;
					UINT cItems = 0;
					hr = RtcpSdesReportUtil_ParseSdes(pCurrentBufferPtr, cbCurrentBuffer, &pSdesItems, &cItems);
					VALHR(hr);

					if (pSdesItems)
					{
						hr = S_OK;
						if (pMember)
						{
							hr = pMember->Update(pSdesItems);
							if (SUCCEEDED(hr))
							{
								if (hr == S_FALSE)
								{
									RaiseActiveRtpSourceChangedEvent(pMember->m_ssrc, RTP_SESSION_MEMBER_EVENT_TYPE_SDES_CHANGED);
								}
							}
						}
						else
						{
							pMember = new CRtpSessionMember(ssrc, TRUE, m_pPerfCounterFactory);
							hr = pMember->Update(pSdesItems);

							{
								CAutoLock lock(&m_critSectRtpSessionMembersMapSynchronization);
								m_mapRtpSessionMembers.SetAt(pMember->m_ssrc, pMember);
							}

							RaiseActiveRtpSourceChangedEvent(pMember->m_ssrc, RTP_SESSION_MEMBER_EVENT_TYPE_SDES_CHANGED);
						}

					}

					SAFE_FREE(pSdesItems);
				}
				break;
			case RTCP_PACKET_TYPE_SR:
				{
					ATLTRACE2("RTCP_PACKET_TYPE_SR: 0x%x \r\n", ssrc);

					if (!pMember) break;

					RtcpSenderReport *pRtpSenderReport = NULL;
					hr = RtcpSenderReportUtil_ParseSR(pCurrentBufferPtr, cbCurrentBuffer, &pRtpSenderReport);
					VALHR(hr);
					ATLTRACE2("Sender Report geparst: hr 0x%x \r\n", hr);

					if (!pMember) 
					{
						pMember = new CRtpSessionMember(ssrc, TRUE, m_pPerfCounterFactory);
						CheckPointer(pMember, E_OUTOFMEMORY);

						hr = pMember->Update(pRtpSenderReport);
						VALHR(hr);

						{
							CAutoLock lock(&m_critSectRtpSessionMembersMapSynchronization);
							m_mapRtpSessionMembers.SetAt(pMember->m_ssrc, pMember);
						}
					}
					else
					{
						hr = pMember->Update(pRtpSenderReport);
						VALHR(hr);
					}

					SAFE_FREE(pRtpSenderReport);
				}
				break;
			case RTCP_PACKET_TYPE_RR:
				{
					ATLTRACE2("RTCP_PACKET_TYPE_RR: 0x%x \r\n", ssrc);
break;
					if (!pMember) 
					{
						pMember = new CRtpSessionMember(ssrc, FALSE, m_pPerfCounterFactory);
						CheckPointer(pMember, E_OUTOFMEMORY);
					}

					RtcpReceiverReport *pRtpReceiverReports = NULL;
					UINT cReceiverReports = 0;
					hr = RtcpReceiverReportUtil_ParseRR(pCurrentBufferPtr, cbCurrentBuffer, &pRtpReceiverReports, &cReceiverReports);
					VALHR(hr);

					SAFE_FREE(pRtpReceiverReports);
				}
				break;
			case RTCP_PACKET_TYPE_BYE:
				{
					ATLTRACE2("RTCP_PACKET_TYPE_BYE: 0x%x \r\n", ssrc);

					if (!pMember)
					{
						break;
					}

					RtcpBye* pBye = NULL;
					hr = RtcpByeUtil_ParseBye(pCurrentBufferPtr, cbCurrentBuffer, &pBye);
					VALHR(hr);

					hr = this->RemoveSessionMember(pBye);
					VALHR(hr);

					SAFE_FREE(pBye);
				}
				break;
			case RTCP_PACKET_TYPE_APP:
				ATLTRACE2("RTCP_PACKET_TYPE_APP not supported Length: %d", cbCurrentBuffer);

			case RTCP_PACKET_TYPE_RRC_2032_FIR_FULL_INTRA_FRAME_REQUEST:
				{
					ATLTRACE2("RTCP Packet of Type RTCP_PACKET_TYPE_RRC_2032_FIR_FULL_INTRA_FRAME_REQUEST received \r\n");
				}
				break;
			case RTCP_PACKET_TYPE_RRC_2032_NACK:
				{
					ATLTRACE2("RTCP Packet of Type RTCP_PACKET_TYPE_RRC_2032_NACK received \r\n");
				}
				break;
			default:
				ATLTRACE2("unsupported RtcpType Type %d Length:  %d", RtcpHeaderUtil_GetPacketType(pCurrentBufferPtr), cbCurrentBuffer);
				break;
			}
		}
		
		cbParsed += cbLength;
		pCurrentBufferPtr += cbLength;
		cbCurrentBuffer -= cbLength;
		
	} while(cbParsed < dwBytesRead);

	return NOERROR;
}

STDMETHODIMP CRtpSocketBase::CreateRtcpTimer()
{
	CAutoLock lock(&m_critSectObjectLock);

	m_uCurrentTimerId = NULL;
	m_uRtcpTimerResolution = 100;
	
	MMRESULT mmretVal = TIMERR_NOERROR; 
	do 
	{
		mmretVal = timeBeginPeriod(m_uRtcpTimerResolution);
		ASSERT(mmretVal == TIMERR_NOERROR);
		if (mmretVal == TIMERR_NOCANDO)
		{
			m_uRtcpTimerResolution <<= 1;
		}
	} while(mmretVal == TIMERR_NOCANDO);
	
	DWORD dwFlags = TIME_ONESHOT|TIME_CALLBACK_FUNCTION;

	if (MmsystemHelper_TimeKillSynchronousFlagAvailable())
		dwFlags |= TIME_KILL_SYNCHRONOUS;

	m_uCurrentTimerId = timeSetEvent(5000, m_uRtcpTimerResolution, (LPTIMECALLBACK)CRtpSocketBase::RtcpTimerProc, (DWORD_PTR)this, dwFlags);
	if (m_uCurrentTimerId == 0)
	{
		return E_FAIL;
	}

	return NOERROR;
}

STDMETHODIMP CRtpSocketBase::UninitializeRtcpTimer()
{
	CAutoLock lock(&m_critSectObjectLock);

	if (m_uCurrentTimerId)
	{
		timeKillEvent(m_uCurrentTimerId);
		m_uCurrentTimerId = NULL;
	}

	MMRESULT mmretVal = timeEndPeriod(m_uRtcpTimerResolution);
	ASSERT(TIMERR_NOERROR == mmretVal);

	return mmretVal == TIMERR_NOERROR ? NOERROR : E_FAIL;
}

void CALLBACK CRtpSocketBase::RtcpTimerProc(
					   UINT uID,   // TimerId
					   UINT uMsg,  // reserved
					   DWORD dwUser,  
					   DWORD dw1,  // reserved   
					   DWORD dw2   // reserved   
					   )
{
	ASSERT(dwUser);
	if (!dwUser) 
	{
		return;
	}
	CRtpSocketBase* pRtpSocketBaseInstance = (CRtpSocketBase*)dwUser;
	pRtpSocketBaseInstance->m_uCurrentTimerId = NULL;

	DWORD dwStartTime = timeGetTime();

	pRtpSocketBaseInstance->TimeoutRtpSessionMembers();

	HRESULT hr = pRtpSocketBaseInstance->RtcpTimerCallback();
	ASSERT(SUCCEEDED(hr));
	
	DWORD dwTimeout = pRtpSocketBaseInstance->CalculateRtcpTimeout();

	DWORD dwEndTime = timeGetTime();
	
	DWORD dwTemp = (dwEndTime - dwStartTime);
	if (dwEndTime > dwStartTime && dwTemp < dwTimeout) 
	{
		dwTimeout -= dwTemp;
	}

	if (pRtpSocketBaseInstance->m_bListenState)
	{
		DWORD dwFlags = TIME_ONESHOT|TIME_CALLBACK_FUNCTION;
		if (MmsystemHelper_TimeKillSynchronousFlagAvailable())
			dwFlags |= TIME_KILL_SYNCHRONOUS;
		pRtpSocketBaseInstance->m_uCurrentTimerId = timeSetEvent(dwTimeout, 250, (LPTIMECALLBACK)CRtpSocketBase::RtcpTimerProc, dwUser, dwFlags);
		if (pRtpSocketBaseInstance->m_uCurrentTimerId == 0)
		{
			ASSERT(0);
		}
	}
}

DWORD CRtpSocketBase::CalculateRtcpTimeout()
{
	HRESULT hr = S_OK;

	UINT uActiveSources;
	uActiveSources = m_pPerfCounterNumberOfActiveSources->get_RawValueUint();

	UINT uSessionMembers;
	{
		CAutoLock lock(&m_critSectRtpSessionMembersMapSynchronization);

		uSessionMembers = m_mapRtpSessionMembers.GetCount() + 1;
	}

	BOOL bWeSent = FALSE;
	if (!m_bIsListener)
	{
		bWeSent = TRUE;//(_perfCounterTimestampLastRtpPacketSent.RawValue >= _perfCounterTimestampLastRtcpReportSent.RawValue);
	}
	
	UINT uRtcpPacketsSent = m_pPerfCounterRtcpPacketsSent->get_RawValueUint();
	UINT uRtcpOctetsSent = m_pPerfCounterRtcpOctetsSent->get_RawValueUint();
	if (uRtcpPacketsSent == 0 || uRtcpOctetsSent == 0)
	{
		return RTP_CONSTANTS_RTCP_MINIMUM_TRANSMISSION_INTERVAL_MILLISECONDS;
	}

	UINT uAverageRtcpPacketSize = (UINT)(uRtcpOctetsSent / uRtcpPacketsSent);
	UINT uTransmissionIntervalMilliseconds = 0;

	DOUBLE dblRtcpBandwidthFraction = RTP_CONSTANTS_RTCP_BANDWIDTH_FRACTION;

	/*
	* If there were active senders, give them at least a minimum
	* share of the RTCP bandwidth.  Otherwise all participants share
	* the RTCP bandwidth equally.
	*/

	if ((uActiveSources > 0)
		&& (uActiveSources < uSessionMembers * RTP_CONSTANTS_RTCP_BANDWIDTH_FRACTION_ACTIVE_SOURCES)) 
	{
		if (bWeSent) 
		{
			dblRtcpBandwidthFraction *= RTP_CONSTANTS_RTCP_BANDWIDTH_FRACTION_ACTIVE_SOURCES;
			/*n*/ uSessionMembers = uActiveSources;
		} 
		else 
		{
			dblRtcpBandwidthFraction *= (1 - RTP_CONSTANTS_RTCP_BANDWIDTH_FRACTION_ACTIVE_SOURCES);
			/*n*/ uSessionMembers -= uActiveSources;
		}
	}

	uTransmissionIntervalMilliseconds = (int)((uAverageRtcpPacketSize * /*n*/ uSessionMembers) / (RTP_CONSTANTS_RTCP_BANDWIDTH_FRACTION * m_rtpSessionBandwidthKilobitPerSecond) * 1000);

	if (uTransmissionIntervalMilliseconds < RTP_CONSTANTS_RTCP_MINIMUM_TRANSMISSION_INTERVAL_MILLISECONDS) 
	{
		uTransmissionIntervalMilliseconds = RTP_CONSTANTS_RTCP_MINIMUM_TRANSMISSION_INTERVAL_MILLISECONDS;
	}

	return uTransmissionIntervalMilliseconds;
}

STDMETHODIMP CRtpSocketBase::RtcpTimerCallback()
{
	ATLTRACE2("CRtpSocketBase::RtcpTimerCallback \r\n");
	ASSERT(0);
	return E_NOTIMPL;
}

STDMETHODIMP CRtpSocketBase::TimeoutRtpSessionMembers()
{
	CAutoLock lock(&m_critSectRtpSessionMembersMapSynchronization);

	if (m_mapRtpSessionMembers.GetCount() > 0)
	{
		POSITION position = m_mapRtpSessionMembers.GetStartPosition();

		UINT currentSsrc = 0;
		CRtpSessionMember* pCurrentRtpSessionMember = NULL;
	
		UINT currentTime = timeGetTime();

		do 
		{
			m_mapRtpSessionMembers.GetNextAssoc(position, currentSsrc, pCurrentRtpSessionMember);
			if (!position) break;
			
			// TODO ist das erlaubt???
			if (!currentSsrc || !pCurrentRtpSessionMember)
			{
				ASSERT(0);
				m_mapRtpSessionMembers.RemoveAtPos(position);
			}
			else
			{
				if (pCurrentRtpSessionMember->GetIsTimedOut(currentTime))
				{
					ASSERT(0); //"Remove item from Map during iteration");
					if (pCurrentRtpSessionMember->m_bIsSource)
					{
						HandleSourceRemoved(pCurrentRtpSessionMember->m_ssrc);
					}

					SAFE_DELETE(pCurrentRtpSessionMember);
					m_mapRtpSessionMembers.RemoveAtPos(position);
				}
			}
		} while(TRUE);
	}

	return NOERROR;
}

STDMETHODIMP CRtpSocketBase::InitializePerformanceCounter()
{
	CAutoLock lock(&m_critSectObjectLock);

	if (m_pPerfCounterFactory)
	{
		return E_UNEXPECTED;
	}

	HRESULT hr = CoCreateInstance(__uuidof(PerformanceCounterFactory), NULL, CLSCTX_INPROC, __uuidof(IPerformanceCounterFactory), (void**)&m_pPerfCounterFactory);
	VALHR(hr);
	ASSERT(SUCCEEDED(hr));


	BSTR bstrSessionAddress = NULL; 
	hr = WinsockHelper_AddressToBstr(&bstrSessionAddress, (sockaddr*)&(m_pRtpAddresses->remoteAddress), m_pRtpAddresses->cbSockaddr);
	VALHR(hr);
	
	hr = m_pPerfCounterFactory->Initialize(
		bstrSessionAddress, 
		m_ssrc);

	SysFreeString(bstrSessionAddress);

	hr = m_pPerfCounterFactory->GetCountersForRtpBase(
		&m_pPerfCounterNumberOfSessionMembers,
		&m_pPerfCounterNumberOfActiveSources,
		&m_pPerfCounterTimestampLastRtpPacketSent,
		&m_pPerfCounterTimestampLastRtcpReportSent,
		&m_pPerfCounterRtcpPacketsSent,
		&m_pPerfCounterRtcpOctetsSent
		);

	m_pPerfCounterNumberOfSessionMembers->Increment();
	
	return hr;
}

STDMETHODIMP CRtpSocketBase::SendRtcpDataRaw(BYTE** ppBuffer, UINT* pcbBufferLengths, UINT cBuffers)
{
	CheckPointer(ppBuffer, E_POINTER);
	CheckPointer(pcbBufferLengths, E_POINTER);
	CheckPointer(cBuffers, E_INVALIDARG);

	LPWSABUF pWsaBuf = (LPWSABUF)SAFE_ALLOC(cBuffers * sizeof(WSABUF));
	CheckPointer(pWsaBuf, E_OUTOFMEMORY);

	UINT u;
	for (u = 0; u < cBuffers; u++)
	{
		pWsaBuf[u].buf = (CHAR*)ppBuffer[u];
		pWsaBuf[u].len = pcbBufferLengths[u];
	}

	DWORD dwBytesSent = 0;
	DWORD dwFlags = 0;
	INT wsaRetVal = WSASendTo(m_scktRtcpSocket, pWsaBuf, cBuffers, &dwBytesSent, dwFlags,(sockaddr*)&(m_pRtcpAddresses->remoteAddress), sizeof(sockaddr_in), NULL, NULL);
	INT wsaLastError;
	if (wsaRetVal != 0)
	{
		wsaLastError = WSAGetLastError();
	}

	SAFE_FREE(pWsaBuf);

	return ((wsaRetVal == 0) ? S_OK : E_FAIL);
}

//////////////////////////////////////////////////////////////////////////

STDMETHODIMP CRtpSocketBase::SetRtpBandwidth(UINT uSessionBandwidthKilobitPerSecond, BOOL bEnforce)
{
	// ASSERT(26000 < uSessionBandwidthKilobitPerSecond);
	ATLTRACE2("CRtpSocketBase::SetRtpParameter: Changing RtpSessionBandwidth From %d to %d \r\n", m_rtpSessionBandwidthKilobitPerSecond, uSessionBandwidthKilobitPerSecond);

	CAutoLock lock(&m_critSectObjectLock);
	m_rtpSessionBandwidthKilobitPerSecond = uSessionBandwidthKilobitPerSecond;

	return S_OK;
}

STDMETHODIMP CRtpSocketBase::UpdateSessionMember/*ByRtpPacket*/(RtpParsedPacket *pRtpParsedPacket)
{
	CheckPointer(pRtpParsedPacket, E_POINTER);

	// Lock the map
	CAutoLock lock(&m_critSectRtpSessionMembersMapSynchronization);

	CRtpSessionMember *pMember = NULL;
	if (m_mapRtpSessionMembers.Lookup(pRtpParsedPacket->ssrc, pMember))
	{
		if (!pMember)
		{
			ASSERT(0);
			ASSERT(m_mapRtpSessionMembers.RemoveKey(pRtpParsedPacket->ssrc));
		}
		else
		{
			if (!pMember->m_bRtpPacketsReceived)
			{
				pMember->m_bRtpPacketsReceived = TRUE;
				RaiseActiveRtpSourceAddedEvent(pMember->m_ssrc);

				return S_FALSE;
			}

			// Update the member
			return pMember->Update(pRtpParsedPacket);
		}
	}

	// Add the member
	pMember = new CRtpSessionMember(pRtpParsedPacket->ssrc, TRUE, m_pPerfCounterFactory);
	CheckPointer(pMember, E_OUTOFMEMORY);
	HRESULT hr = pMember->Update(pRtpParsedPacket);
	VALHR(hr);

	POSITION position = m_mapRtpSessionMembers.SetAt(pRtpParsedPacket->ssrc, pMember);
	ASSERT(position);

	RaiseActiveRtpSourceAddedEvent(pMember->m_ssrc);

	return S_FALSE;
}

STDMETHODIMP CRtpSocketBase::UpdateSessionMember/*ByRtcpSenderReport*/(RtcpSenderReport *pRtcpSenderReport)
{
	CheckPointer(pRtcpSenderReport, E_POINTER);

	CAutoLock lock(&m_critSectRtpSessionMembersMapSynchronization);

	CRtpSessionMember *pMember = NULL;
	if (m_mapRtpSessionMembers.Lookup(pRtcpSenderReport->ssrc, pMember))
	{
		if (!pMember)
		{
			ASSERT(0);
			ASSERT(m_mapRtpSessionMembers.RemoveKey(pRtcpSenderReport->ssrc));
		}
		else
		{
			// Update the member
			return pMember->Update(pRtcpSenderReport);
		}
	}

	// Add the member
	pMember = new CRtpSessionMember(pRtcpSenderReport->ssrc, TRUE, m_pPerfCounterFactory);
	CheckPointer(pMember, E_OUTOFMEMORY);
	HRESULT hr = pMember->Update(pRtcpSenderReport);
	VALHR(hr);

	POSITION position = m_mapRtpSessionMembers.SetAt(pRtcpSenderReport->ssrc, pMember);
	ASSERT(position);

	return hr;
}

STDMETHODIMP CRtpSocketBase::UpdateSessionMember/*ByRtcpReceiverReport*/(RtcpReceiverReport *pRtcpReceiverReport)
{
	CheckPointer(pRtcpReceiverReport, E_POINTER);

	// Lock the map
	CAutoLock lock(&m_critSectRtpSessionMembersMapSynchronization);

	CRtpSessionMember *pMember = NULL;
	if (m_mapRtpSessionMembers.Lookup(pRtcpReceiverReport->ssrc, pMember))
	{
		if (!pMember)
		{
			ASSERT(0);
			ASSERT(m_mapRtpSessionMembers.RemoveKey(pRtcpReceiverReport->ssrc));
		}
		else
		{
			// Update the member
			return pMember->Update(pRtcpReceiverReport);
		}
	}

	// Add the member
	pMember = new CRtpSessionMember(pRtcpReceiverReport->ssrc, FALSE, m_pPerfCounterFactory);
	CheckPointer(pMember, E_OUTOFMEMORY);
	HRESULT hr = pMember->Update(pRtcpReceiverReport);
	VALHR(hr);

	POSITION position = m_mapRtpSessionMembers.SetAt(pRtcpReceiverReport->ssrc, pMember);
	ASSERT(position);
	
	return hr;
}

STDMETHODIMP CRtpSocketBase::RemoveSessionMember/*ByRtcpBye*/(RtcpBye *pRtcpBye)
{
	CheckPointer(pRtcpBye, E_POINTER);

	// Lock the map
	CAutoLock lock(&m_critSectRtpSessionMembersMapSynchronization);

	CRtpSessionMember *pMember = NULL;
	if (m_mapRtpSessionMembers.Lookup(pRtcpBye->ssrc, pMember))
	{
		if (pMember)
		{
			m_mapRtpSessionMembers.RemoveKey(pRtcpBye->ssrc);		

			RaiseActiveRtpSourceDeletedEvent(pMember->m_ssrc);

#if (_WIN32_WINNT >= 0x0500) 
#pragma message("Compiling with ThreadPool support (Async events), _WIN32_WINNT >= 0x0500")
			RtpSessionMemberEventArgs* pEventArgs = (RtpSessionMemberEventArgs*)SAFE_ALLOC(sizeof(RtpSessionMemberEventArgs));
			if (pEventArgs)
			{
				pEventArgs->pRtpSocketBaseEventSource = this;
				pEventArgs->ssrc = pRtcpBye->ssrc;
				pEventArgs->rtpSessionMemberEventType = RTP_SESSION_MEMBER_EVENT_TYPE_DELETED;
				ASSERT(QueueUserWorkItem((LPTHREAD_START_ROUTINE)CRtpSocketBase::QueueUserWorkItemThreadProc_RaiseEventRtpSessionMemberRemoved, pEventArgs, WT_EXECUTEDEFAULT));
				SAFE_DELETE(pMember);
			}
			else
			{
				ASSERT(0);
				this->HandleSourceRemoved(pMember->m_ssrc);
				SAFE_DELETE(pMember);
			}
#else
			this->HandleSourceRemoved(pMember->m_ssrc);
			SAFE_DELETE(pMember);
#endif
		}

		return S_OK;
	}
	
	return S_FALSE;
}

STDMETHODIMP CRtpSocketBase::RaiseActiveRtpSourceDeletedEvent(UINT ssrc)
{
	return NOERROR;
}

STDMETHODIMP CRtpSocketBase::RaiseActiveRtpSourceAddedEvent(UINT ssrc)
{
	return NOERROR;

#if (_WIN32_WINNT >= 0x0500) 
#pragma message("Compiling with ThreadPool support (Async events), _WIN32_WINNT >= 0x0500")
	RtpSessionMemberEventArgs* pEventArgs = (RtpSessionMemberEventArgs*)SAFE_ALLOC(sizeof(RtpSessionMemberEventArgs));
	if (pEventArgs)
	{
		pEventArgs->pRtpSocketBaseEventSource = this;
		pEventArgs->ssrc = /*pMember->m_*/ssrc;
		pEventArgs->rtpSessionMemberEventType = RTP_SESSION_MEMBER_EVENT_TYPE_CREATED;
		ASSERT(QueueUserWorkItem(
			(LPTHREAD_START_ROUTINE)CRtpSocketBase::QueueUserWorkItemThreadProc_RaiseEventRtpSourceAdded
			, pEventArgs, WT_EXECUTEDEFAULT));
		return S_FALSE;
	}
	else
	{
		ASSERT(0);
		return this->HandleSourceAdded(/*pMember->m_*/ssrc);
	}
#else
	return this->HandleSourceAdded(pMember->m_ssrc);
#endif
}

STDMETHODIMP CRtpSocketBase::RaiseActiveRtpSourceChangedEvent(UINT ssrc, RTP_SESSION_MEMBER_EVENT_TYPE eventType)
{
	return NOERROR;

#if (_WIN32_WINNT >= 0x0500) 
#pragma message("Compiling with ThreadPool support (Async events), _WIN32_WINNT >= 0x0500")
	RtpSessionMemberEventArgs* pEventArgs = (RtpSessionMemberEventArgs*)SAFE_ALLOC(sizeof(RtpSessionMemberEventArgs));
	if (pEventArgs)
	{
		pEventArgs->pRtpSocketBaseEventSource = this;
		pEventArgs->ssrc = ssrc;
		pEventArgs->rtpSessionMemberEventType = eventType;

		ASSERT(QueueUserWorkItem(
			(LPTHREAD_START_ROUTINE)CRtpSocketBase::QueueUserWorkItemThreadProc_RaiseEventRtpSourceChanged
			, pEventArgs, WT_EXECUTEDEFAULT));
		return S_FALSE;
	}
	else
	{
		ASSERT(0);
		return this->HandleSourceChanged(ssrc, eventType);
	}
#else
	return this->HandleSourceAdded(ssrc, eventType);
#endif
}


#if (_WIN32_WINNT >= 0x0500) 
DWORD WINAPI CRtpSocketBase::QueueUserWorkItemThreadProc_RaiseEventRtpSessionMemberRemoved(LPVOID lpThreadParameter )
{
	if (lpThreadParameter)
	{
		RtpSessionMemberEventArgs* pEventArgs = (RtpSessionMemberEventArgs*)lpThreadParameter;
		if (/*pEventArgs->pRtpSessionMember && */pEventArgs->pRtpSocketBaseEventSource)
		{
			pEventArgs->pRtpSocketBaseEventSource->HandleSourceRemoved(pEventArgs->/*pRtpSessionMember->m_*/ssrc);
			//SAFE_DELETE(pEventArgs->pRtpSessionMember);
			SAFE_FREE(pEventArgs);
			return 0;
		}

		SAFE_FREE(pEventArgs);
	}

	return -1;
}

DWORD WINAPI CRtpSocketBase::QueueUserWorkItemThreadProc_RaiseEventRtpSourceAdded(LPVOID lpThreadParameter)
{
	if (lpThreadParameter)
	{
		RtpSessionMemberEventArgs* pEventArgs = (RtpSessionMemberEventArgs*)lpThreadParameter;
		if (/*pEventArgs->pRtpSessionMember && */pEventArgs->pRtpSocketBaseEventSource)
		{
			pEventArgs->pRtpSocketBaseEventSource->HandleSourceAdded(pEventArgs->/*pRtpSessionMember->m_*/ssrc);
			// Du bist soooo hohl, losch!
			//SAFE_DELETE(pEventArgs->pRtpSessionMember);
			SAFE_FREE(pEventArgs);
			return 0;
		}

		SAFE_FREE(pEventArgs);
	}

	return -1;
}

DWORD WINAPI CRtpSocketBase::QueueUserWorkItemThreadProc_RaiseEventRtpSourceChanged(LPVOID lpThreadParameter)
{
	if (lpThreadParameter)
	{
		RtpSessionMemberEventArgs* pEventArgs = (RtpSessionMemberEventArgs*)lpThreadParameter;
		if (/*pEventArgs->pRtpSessionMember && */pEventArgs->pRtpSocketBaseEventSource)
		{
			pEventArgs->pRtpSocketBaseEventSource->HandleSourceChanged(pEventArgs->ssrc, pEventArgs->rtpSessionMemberEventType);
			SAFE_FREE(pEventArgs);
			return 0;
		}

		SAFE_FREE(pEventArgs);
	}

	return -1;
}

#endif

STDMETHODIMP CRtpSocketBase::HandleSourceAdded(UINT ssrc)
{
	ATLTRACE2("CRtpSocketBase::HandleSourceAdded %d\r\n", ssrc);
	return NOERROR;
}

STDMETHODIMP CRtpSocketBase::HandleSourceRemoved(UINT ssrc)
{
	ATLTRACE2("CRtpSocketBase::HandleSourceRemoved %d\r\n", ssrc);
	return NOERROR;

STDMETHODIMP CRtpSocketBase::HandleSourceChanged(
	UINT ssrc, 
	RTP_SESSION_MEMBER_EVENT_TYPE eventType)
{
	ATLTRACE2("CRtpSocketBase::HandleSourceChanged %d\r\n", ssrc);
	return NOERROR;
	ASSERT(0);
}

// virtual methods 
STDMETHODIMP CRtpSocketBase::HandleParsedRtpPacket(RtpParsedPacket *pParsedPacket)
{
	ASSERT(0); // This may not be called
	return NOERROR;
}


STDMETHODIMP CRtpSocketBase::SendBye()
{
	BYTE *pBuffer = NULL;
	UINT cbBuffer = 0;
	HRESULT hr = RtcpByeUtil_CreateBye(&pBuffer, &cbBuffer, m_ssrc, NULL);
	VALHR(hr);

	hr = SendRtcpDataRaw(&pBuffer, &cbBuffer, 1);
	//VALHR(hr);

	return hr;
}

//////////////////////////////////////////////////////////////////////////
// Cleanup Functions

STDMETHODIMP CRtpSocketBase::CleanupReceiverThread()
{
	// TODO stop if necessary
	DWORD dwExitCode = 0;
	if (GetExitCodeThread(m_hReceiverWorkerThread, &dwExitCode))
	{
		if (dwExitCode == STILL_ACTIVE)
		{
			// Terminate smoothly
			m_bReceiveWorkerThreadAlive = FALSE;
			WSASetEvent(m_wsaReceiveEvents[0]);

			if (WAIT_TIMEOUT == WaitForSingleObject(m_hEventWorkerThreadDied, 1000))
			{
				// Hard way
				ASSERT(TerminateThread(m_hReceiverWorkerThread, 99));
			}
		}
	}

	SAFE_CLOSE_WSAEVENT(m_wsaReceiveEvents[0]);
	SAFE_CLOSE_WSAEVENT(m_wsaReceiveEvents[1]);
	SAFE_CLOSE_WSAEVENT(m_wsaReceiveEvents[2]);
	SAFE_CLOSE_HANDLE(m_hReceiverWorkerThread);
	SAFE_CLOSE_HANDLE(m_hEventWorkerThreadDied);
	DeleteCriticalSection(&m_critSectReceiverWorkerThread);
	m_bReceiveWorkerThreadAlive = FALSE;

	return NOERROR;
}

HRESULT CRtpSocketBase::InternalGetSessionMemberInfo(UINT ssrc, RtpSessionMemberInfo *pInfo, BOOL bIncludeSdesItems)
{
	ATLTRACE2("##### InternalGetSessionMemberInfo VOR\r\n");

	CheckPointer(pInfo, E_POINTER);
	CheckPointer(ssrc, E_UNEXPECTED); // ssrc of 0 is never valid for this stack

	// Lock Map
	CAutoLock lock(&m_critSectRtpSessionMembersMapSynchronization);
	ATLTRACE2("InternalGetSessionMemberInfo DRIN");
	// Find Member
	CRtpSessionMember *pMember = NULL;
	if (m_mapRtpSessionMembers.Lookup(ssrc, pMember))
	{
		return pMember->GetSourceInfo(pInfo, bIncludeSdesItems);
	}


	return S_FALSE;
}
