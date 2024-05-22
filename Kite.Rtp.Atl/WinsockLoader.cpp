#include "StdAfx.h"
#include ".\winsockloader.h"

#include <WinSock2.h>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32")

extern LONG s_lWinsockRefCount;
extern HANDLE s_hMutex;

CWinsockLoader::CWinsockLoader(void)
{
	if (s_hMutex == NULL)
	{
		s_hMutex = CreateMutex(NULL, TRUE, NULL);

		WSADATA wsadata;
		ZeroMemory(&wsadata, sizeof(WSADATA));

		if (0 == WSAStartup(MAKEWORD(2,0), &wsadata))
		{
			// Success
		}
		else
		{
			throw _T("WSA Startup failed");
		}
		
		ReleaseMutex(s_hMutex);
	}
	else
	{
		WaitForSingleObject(s_hMutex, INFINITE);
		InterlockedIncrement(&s_lWinsockRefCount);
		ReleaseMutex(s_hMutex);
	}
}

CWinsockLoader::~CWinsockLoader(void)
{
	WaitForSingleObject(s_hMutex, INFINITE);
	if (InterlockedDecrement(&s_lWinsockRefCount) == 0)
	{
		// Unload Winsock
		WSACleanup();

		CloseHandle(s_hMutex);
		//ReleaseMutex(s_hMutex);
		return;
	}

	ReleaseMutex(s_hMutex);
}
