#pragma once

// TODO [export]
struct SocketAddresses
{
	UINT cbSize;

	BOOL isIPv6;
	BOOL isMcast;

	BOOL isLocalAddressSpecified;

	//////////////////////////////////////////////////////////////////////////
	BOOL bDontReuseAddr;
	BOOL bExclusiveAddrUse;
	INT Ttl;
	//////////////////////////////////////////////////////////////////////////

	INT cbSockaddr;

	union
	{
		// 16 byte
		sockaddr_in ipv4;
		// 28
		sockaddr_in6 ipv6;
	} localAddress;

	union
	{
		// 16 byte
		sockaddr_in ipv4;
		// 28
		sockaddr_in6 ipv6;
	} remoteAddress;
};

struct SocketAddressesIPMcast : SocketAddresses
{
	INT cbMreq;
	union
	{
		// 8, 2*in_addr
		ip_mreq ipv4mreq;
		// 20, in6_addr + INT
		ipv6_mreq ipv6mreq;
	} multicastEndpoint;
};

struct LocallyBoundSocket
{
	SOCKET rtpSocket;
	SOCKET rtcpSocket;
	
	BOOL bInUse;
	BOOL bExclusive;
	
	sockaddr* pLocalAddress;
	INT cbLocalAddress;
};

struct SocketAddressList
{
	INT					iAddressCount;
	LocallyBoundSocket  Address[1];
};
