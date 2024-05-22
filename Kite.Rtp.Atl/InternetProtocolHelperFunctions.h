#ifndef INTERNETPROTOCOLHELPERFUNCTIONS_H
#define INTERNETPROTOCOLHELPERFUNCTIONS_H

#include <WinSock2.h>

// IPHelper
#include <IPHlpApi.h>
#pragma comment(lib, "Iphlpapi")

HRESULT InternetProtocolHelper_FindAvailablePortbase(INT af, INT ipproto, sockaddr_in* psockaddrLocalAddress, USHORT *puPortBaseHostByteOrder, UINT cPorts);

// S_OK - Port is not used
// S_FALSE - Port is in use
// E_FAIL - error
HRESULT InternetProtocolHelper_IsPortAvailable(INT af, INT ipproto, sockaddr_in* psockaddrLocalAddress, USHORT uPortHostByteOrder);

#endif