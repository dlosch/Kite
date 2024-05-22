#pragma once

#include "RtpSocketBase.h"

class CTestRtpSocketBase
{
	HRESULT hr;
	CRtpSocketBase *m_pBase;

	SocketAddresses m_scktAddressesIpv4Unicast;
	SocketAddresses m_scktAddressesIpv4UnicastNoLocal;

	SocketAddressesIPMcast m_scktAddressesIpv4MCast;

	SocketAddresses m_scktAddressesIpv6Unicast;
	SocketAddressesIPMcast m_scktAddressesIpv6MCast;

public:
	CTestRtpSocketBase(void);
	~CTestRtpSocketBase(void);

	void TestIpv4Uni(void);
	void TestIpv4UniNoLocal(void);
};
