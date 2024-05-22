// RtpListener.cpp : Implementation of CRtpListener

#include "stdafx.h"
#include ".\rtplistener.h"

#include <WinCrypt.h>

#ifndef NOBUFFER
CRtpListener::CRtpListener()
{
}
HRESULT CRtpListener::FinalConstruct()
{
	return this->CRtpListenerBase::FinalConstruct();
}
void CRtpListener::FinalRelease()
{
	this->CRtpListenerBase::FinalRelease();
}
STDMETHODIMP CRtpListener::Configure(BYTE* pSocketAddresses, UINT cbSocketAddresses/*, BYTE* pSdesItems, UINT cbSdesItems*/)
{
	return this->CRtpListenerBase::Configure(pSocketAddresses, cbSocketAddresses);
}

STDMETHODIMP CRtpListener::Start(void)
{
	return this->CRtpListenerBase::Start();
}

STDMETHODIMP CRtpListener::Stop(void)
{
	return this->CRtpListenerBase::Stop();
}

STDMETHODIMP CRtpListener::SetNetworkParameter(LPWSTR szRemoteAddress, USHORT uRemotePort, LPWSTR szLocalInterface, USHORT uLocalPort, INT ttl)
{
	return this->CRtpListenerBase::SetNetworkParameter(szRemoteAddress, uRemotePort, szLocalInterface, uLocalPort, ttl);
}

STDMETHODIMP CRtpListener::RegisterCallback(IRtpListenerEventConsumer *pEventConsumer)
{
	return this->CRtpListenerBase::RegisterCallback(pEventConsumer);
}
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
CRtpListenerBase::CRtpListenerBase()
{
	this->SetIsListener(TRUE);
}

HRESULT CRtpListenerBase::FinalConstruct()
{
	HRESULT hr = S_OK;
	HCRYPTPROV hCryptProv = NULL;
	BOOL bRetVal = CryptAcquireContext(&hCryptProv, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT);
	ASSERT(bRetVal);
	// local ssrc
	bRetVal = CryptGenRandom(hCryptProv, sizeof(UINT), (BYTE*)&m_ssrc);
	ASSERT(bRetVal);
	bRetVal = CryptReleaseContext(hCryptProv, NULL);
	ASSERT(bRetVal);
	hCryptProv = NULL;

	// 
	hr = Initialize();

	return hr;
}

void CRtpListenerBase::FinalRelease() 
{
}

//////////////////////////////////////////////////////////////////////////
// Rtcp Timer
STDMETHODIMP CRtpListenerBase::RtcpTimerCallback()
{
	ATLTRACE2("CRtpListenerBase::RtcpTimerCallback \r\n");

	HRESULT hr = S_OK;

	UINT uActiveSources = (m_pPerfCounterNumberOfActiveSources->get_RawValueUint());

	if (uActiveSources == 0) return S_FALSE;

	ASSERT(uActiveSources < 10);
	BYTE* pRRNboBuffer = NULL;
	UINT cbOffset = RTP_CONSTANTS_RTCP_HEADER_SIZE;
	UINT cbBufferLength = 0;
	hr = RtcpReceiverReportUtil_AllocateRRsWithHeader(&pRRNboBuffer, &cbBufferLength, uActiveSources, m_ssrc);

	if (S_FALSE == hr)
	{
		// No active sources, no need to deliver RRs
		return S_FALSE;
	}

	{
		CAutoLock lock(&m_critSectRtpSessionMembersMapSynchronization);

		// iterate sources
		POSITION position = m_mapRtpSessionMembers.GetStartPosition();

		UINT currentSsrc;
		CRtpSessionMember *pCurrentSessionMember = NULL;

		while (position)
		{
			m_mapRtpSessionMembers.GetNextAssoc(position, currentSsrc, pCurrentSessionMember);
			if (!position) break;

			if (pCurrentSessionMember && pCurrentSessionMember->m_bIsSource)
			{
				hr = pCurrentSessionMember->CreateRR(pRRNboBuffer, &cbOffset, cbBufferLength);
				ASSERT(SUCCEEDED(hr));
			}
		}
	}

	// send Rtcp Buffer
	hr = SendRtcpDataRaw(&pRRNboBuffer, &cbBufferLength, 1);
	ASSERT(SUCCEEDED(hr));

	// Free Buffer
	SAFE_FREE(pRRNboBuffer);

	return hr;
}

STDMETHODIMP CRtpListenerBase::Configure(BYTE* pSocketAddressesByte, UINT cbSocketAddresses/*, BYTE* pSdesItems, UINT cbSdesItems*/)
{
	if (m_pRtpAddresses) return E_UNEXPECTED;
	CheckPointer(pSocketAddressesByte, E_POINTER);

	if (cbSocketAddresses != sizeof(SocketAddresses) && cbSocketAddresses != sizeof(SocketAddressesIPMcast)) return E_INVALIDARG;
	HRESULT hr = S_OK;

	SocketAddresses *pSocketAddresses = (SocketAddresses*)pSocketAddressesByte;

	hr = this->CreateSockets(pSocketAddresses);
	VALHR(hr);

	hr = this->CRtpSocketBase::InitializePerformanceCounter();
	VALHR(hr);

	return S_OK;
}

STDMETHODIMP CRtpListenerBase::Start(void)
{
	return this->CRtpSocketBase::StartListen();
}

STDMETHODIMP CRtpListenerBase::Stop(void)
{
	return this->CRtpSocketBase::StopListen();
}

STDMETHODIMP CRtpListenerBase::SetNetworkParameter(
	LPWSTR szRemoteAddress, USHORT uRemotePort, LPWSTR szLocalInterface, USHORT uLocalPort, INT ttl)
{
	HRESULT hr = S_OK;

	ATLTRACE2("CRtpListenerBase::SetNetworkParameter remote %ws %u Local %ws %u ttl %d\r\n", szRemoteAddress, uRemotePort, szLocalInterface != NULL ? szLocalInterface : L"<NULL>", uLocalPort, ttl);

	USES_CONVERSION;

	SocketAddresses *pSocketAddresses = NULL;
	hr = RtpConfigurationHelper_CreateConfiguration(
		W2T(szRemoteAddress), 
		uRemotePort, 
		W2T(szLocalInterface), 
		uLocalPort,
		ttl, 

		&pSocketAddresses);

	VALHR(hr);
	CheckPointer(pSocketAddresses, E_FAIL);

	return this->Configure((BYTE*)pSocketAddresses, pSocketAddresses->cbSize);
}

STDMETHODIMP CRtpListenerBase::RegisterCallback(IRtpListenerEventConsumer *pEventConsumer)
{
	CheckPointer(pEventConsumer, E_POINTER);
	CheckPointer(!m_pEventConsumer, E_UNEXPECTED);

	m_pEventConsumer = pEventConsumer;

	ATLTRACE2("CRtpListenerBase::RegisterCallback CONNECTED \r\n");

	return S_OK;
}

STDMETHODIMP CRtpListenerBase::HandleSourceAdded(UINT ssrc)
{
	ATLTRACE2("CRtpSocketBase::HandleSourceAdded %d\r\n", ssrc);
	
	return (m_pEventConsumer ? m_pEventConsumer->ActiveSourceAdded(ssrc) : S_FALSE);
}

STDMETHODIMP CRtpListenerBase::HandleSourceRemoved(UINT ssrc)
{
	ATLTRACE2("CRtpListenerBase::HandleSourceRemoved %d\r\n", ssrc);

	HRESULT hr = InternalHandleSourceRemoved(ssrc);

	return (m_pEventConsumer ? m_pEventConsumer->ActiveSourceRemoved(ssrc) : S_FALSE);
}

#else
CRtpListener::CRtpListener()
{
	this->SetIsListener(TRUE);
}

HRESULT CRtpListener::FinalConstruct()
{
	HRESULT hr = S_OK;
	HCRYPTPROV hCryptProv = NULL;
	BOOL bRetVal = CryptAcquireContext(&hCryptProv, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT);
	ASSERT(bRetVal);
	// local ssrc
	bRetVal = CryptGenRandom(hCryptProv, sizeof(UINT), (BYTE*)&m_ssrc);
	ASSERT(bRetVal);
	bRetVal = CryptReleaseContext(hCryptProv, NULL);
	ASSERT(bRetVal);
	hCryptProv = NULL;

	// 
	hr = Initialize();

	return hr;
}

void CRtpListener::FinalRelease() 
{
}

STDMETHODIMP CRtpListener::Configure(BYTE* pSocketAddressesByte, UINT cbSocketAddresses/*, BYTE* pSdesItems, UINT cbSdesItems*/)
{
	if (m_pRtpAddresses) return E_UNEXPECTED;
	CheckPointer(pSocketAddressesByte, E_POINTER);

	if (cbSocketAddresses != sizeof(SocketAddresses) && cbSocketAddresses != sizeof(SocketAddressesIPMcast)) return E_INVALIDARG;
	HRESULT hr = S_OK;

	SocketAddresses *pSocketAddresses = (SocketAddresses*)pSocketAddressesByte;

	hr = this->CreateSockets(pSocketAddresses);
	VALHR(hr);

	hr = this->CRtpSocketBase::InitializePerformanceCounter();
	VALHR(hr);

	return S_OK;
}

STDMETHODIMP CRtpListener::Start(void)
{
	return this->CRtpSocketBase::StartListen();
}

STDMETHODIMP CRtpListener::Stop(void)
{
	return this->CRtpSocketBase::StopListen();
}

HRESULT CRtpListener::HandleParsedRtpPacket(RtpParsedPacket *pParsedPacket)
{
	return E_NOTIMPL;
}

STDMETHODIMP CRtpListener::SetNetworkParameter(
	LPWSTR szRemoteAddress, USHORT uRemotePort, LPWSTR szLocalInterface, USHORT uLocalPort, INT ttl)
{
	HRESULT hr = S_OK;

	USES_CONVERSION;

	SocketAddresses *pSocketAddresses = NULL;
	hr = RtpConfigurationHelper_CreateConfiguration(
		W2T(szRemoteAddress), 
		uRemotePort, 
		W2T(szLocalInterface), 
		uLocalPort,
		ttl, 
		&pSocketAddresses);

	VALHR(hr);
	CheckPointer(pSocketAddresses, E_FAIL);

	return this->Configure((BYTE*)pSocketAddresses, pSocketAddresses->cbSize);
}

STDMETHODIMP CRtpListener::RegisterCallback(
	BYTE* 
	pCallback, 
	BYTE* pContext)
{
	m_pCallback = (PRTPLISTENER_RTP_PACKET_RECEIVED_CALLBACK)pCallback;
	m_pCallbackContext = pContext;

	return S_OK;
}
#endif
STDMETHODIMP CRtpListener::SubscribeSsrc(UINT ssrc)
{
	return E_NOTIMPL;
}

STDMETHODIMP CRtpListener::UnsubscribeSsrc(UINT ssrc)
{
	return S_OK;
}

STDMETHODIMP CRtpListener::SetMediaParameter(
		BOOL bAduSpansMultiplePackets,
		BYTE payloadType,
		UINT uRtpTimeStampIncrementPerSecond,
		UINT uExpectedTimePerAduNanoseconds)
{
	ASSERT(0);
	return E_NOTIMPL;
}

STDMETHODIMP CRtpListener::ReserveNetworkAddressAndCreateSockets(LPWSTR szRemoteAddress, LPWSTR szLocalInterface, USHORT uMinLocalPort, USHORT uMaxLocalPort, INT ttl) 
{
	return InternalReserveNetworkAddressAndCreateSockets(
		szRemoteAddress, 
		szLocalInterface, 
		uMinLocalPort, uMaxLocalPort, ttl);
}

STDMETHODIMP CRtpListener::ReserveNetworkAddress(LPWSTR szRemoteAddress, LPWSTR szLocalInterface, USHORT uMinLocalPort, USHORT uMaxLocalPort, LPWSTR szLocalInterfaceOut, INT cchLocalAddress, USHORT *puLocalPortBase)
{
	return InternalReserveNetworkAddress(
		szRemoteAddress, 
		szLocalInterface, 
		uMinLocalPort, uMaxLocalPort, szLocalInterfaceOut, cchLocalAddress, puLocalPortBase);
}

STDMETHODIMP CRtpListener::IsSubscribedTo(UINT ssrc, INT* retVal)
{
	// TODO: Add your implementation code here

	return S_OK;
}
