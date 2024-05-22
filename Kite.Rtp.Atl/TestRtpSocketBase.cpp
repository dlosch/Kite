#include "StdAfx.h"
#include ".\testrtpsocketbase.h"

CTestRtpSocketBase::CTestRtpSocketBase(void)
{
	hr = NOERROR;

	m_pBase = NULL;
	// TODO
	//m_pBase = new CRtpSocketBase;

	//////////////////////////////////////////////////////////////////////////
	m_scktAddressesIpv4Unicast.cbSize = sizeof(SocketAddresses);
	m_scktAddressesIpv4Unicast.bDontReuseAddr = TRUE;
	m_scktAddressesIpv4Unicast.bExclusiveAddrUse = TRUE;
	m_scktAddressesIpv4Unicast.Ttl = 8;
	m_scktAddressesIpv4Unicast.isIPv6 = FALSE;
	m_scktAddressesIpv4Unicast.isLocalAddressSpecified = TRUE;
	m_scktAddressesIpv4Unicast.cbSockaddr = sizeof(sockaddr_in);

	sockaddr_in sainRemote;
	sainRemote.sin_family = AF_INET;
	sainRemote.sin_port = htons(5000);
	sainRemote.sin_addr.s_addr = inet_addr("192.168.123.66");

	sockaddr_in sainLocal;
	sainLocal.sin_family = AF_INET;
	sainLocal.sin_port = htons(15000);
	sainLocal.sin_addr.s_addr = INADDR_ANY;

	m_scktAddressesIpv4Unicast.localAddress.ipv4 = sainLocal;
	m_scktAddressesIpv4Unicast.remoteAddress.ipv4 = sainRemote;

	//////////////////////////////////////////////////////////////////////////
	CopyMemory(&m_scktAddressesIpv4UnicastNoLocal, &m_scktAddressesIpv4Unicast, sizeof(SocketAddresses));
	m_scktAddressesIpv4UnicastNoLocal.isLocalAddressSpecified = FALSE;
	ZeroMemory(&m_scktAddressesIpv4UnicastNoLocal.localAddress, m_scktAddressesIpv4UnicastNoLocal.cbSockaddr);

	// TODO
}

CTestRtpSocketBase::~CTestRtpSocketBase(void)
{

}

void CTestRtpSocketBase::TestIpv4Uni(void)
{
	hr = m_pBase->CreateSockets(&m_scktAddressesIpv4Unicast);
}

void CTestRtpSocketBase::TestIpv4UniNoLocal(void)
{
	hr = m_pBase->CreateSockets(&m_scktAddressesIpv4UnicastNoLocal);
}


