#pragma once

// For Completion routing, the Thread needs to be in an alertable state
// we use WsaEventSelect
class CSocketBaseReceiveWorkerThread
{
	HANDLE m_hWorkreThread;
	

public:
	CSocketBaseReceiveWorkerThread(void);
	~CSocketBaseReceiveWorkerThread(void);
};
