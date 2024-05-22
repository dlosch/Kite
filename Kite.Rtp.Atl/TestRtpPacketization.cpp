#include "StdAfx.h"
#include ".\testrtppacketization.h"

CTestRtpPacketization::CTestRtpPacketization(void)
{
}

CTestRtpPacketization::~CTestRtpPacketization(void)
{
}

VOID CTestRtpPacketization::TestSdesWriter()
{
	SdesItems items;
	ZeroMemory(&items, sizeof(items));

	// 5 4 5 5 3 4 20 = 46 + 14
	_tcscpy(items.cname, _T("cname"));
	_tcscpy(items.name, _T("name"));
	_tcscpy(items.email, _T("email"));
	_tcscpy(items.phone, _T("phone"));
	_tcscpy(items.loc, _T("loc"));
	_tcscpy(items.tool, _T("tool"));
	_tcscpy(items.note, _T("notenotenotenotenote"));

	items.ssrc = 0xFF00FF00;

}