#pragma once

static LONG s_lWinsockRefCount = 0;
static HANDLE s_hMutex = NULL;

class CWinsockLoader
{
public:
	CWinsockLoader(void);
	~CWinsockLoader(void);
};
