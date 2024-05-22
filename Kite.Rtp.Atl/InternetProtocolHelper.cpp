// InternetProtocolHelper.cpp : Implementation of CInternetProtocolHelper

#include "stdafx.h"
#include "InternetProtocolHelper.h"

// Internet Protocol Helpers
#include <IPHlpApi.h>
#include ".\internetprotocolhelper.h"
#pragma comment(lib, "Iphlpapi.lib")

// CInternetProtocolHelper
CInternetProtocolHelper::CInternetProtocolHelper()
{
}

HRESULT CInternetProtocolHelper::FinalConstruct()
{
	return S_OK;
}

void CInternetProtocolHelper::FinalRelease() 
{
}

STDMETHODIMP CInternetProtocolHelper::QueryMtuForInterface(UINT interfaceIndex, UINT* pMtu)
{
	CheckPointer(pMtu, E_POINTER);

	//MTU-Query:
	ULONG ucbRequired = 0;
	// Query Required Space
	DWORD dwRetVal = GetIfTable(NULL, &ucbRequired, FALSE);
	VALRV(dwRetVal, E_FAIL);

	MIB_IFTABLE *pInterfaceTable = (MIB_IFTABLE*)SAFE_ALLOC(ucbRequired);
	CheckPointer(pInterfaceTable, E_OUTOFMEMORY);

	dwRetVal = GetIfTable(pInterfaceTable, &ucbRequired, TRUE);
	HRESULT hr = E_FAIL;
	
	if (dwRetVal == ERROR_SUCCESS)
	{
		for (UINT u = 0; u < pInterfaceTable->dwNumEntries; u++)
		{
			if (pInterfaceTable->table[u].dwIndex == interfaceIndex)
			{
				(*pMtu) = pInterfaceTable->table[u].dwMtu;
				hr = S_OK;
				break;
			}
		}
	}

	SAFE_FREE(pInterfaceTable);

	return hr;
}


STDMETHODIMP CInternetProtocolHelper::GetAdapterCount(UINT *pAdapterCount)
{
	CheckPointer(pAdapterCount, E_POINTER);	

	// TODO ist dieser Cast valid????
	DWORD dwRetVal = GetNumberOfInterfaces((DWORD*)pAdapterCount); // Excludes Local Loopback
	if (dwRetVal == ERROR_SUCCESS)
	{
		(*pAdapterCount)-= 1;
		return S_OK;
	}
	else
	{
		(*pAdapterCount) = 0;
		return E_FAIL;
	}
}

STDMETHODIMP CInternetProtocolHelper::GetAdapterInfoConcise(UINT interfaceIndex, SimpleInterfaceInfo* pInterfaceInfo)
{
	CheckPointer(pInterfaceInfo, E_POINTER);
	CheckPointer(pInterfaceInfo->bstrInterfaceName, E_POINTER);

	DWORD dwNumInterfaces = 0;
	DWORD dwRetVal = GetNumberOfInterfaces(&dwNumInterfaces);
	dwNumInterfaces -= 1;
	if (dwRetVal != ERROR_SUCCESS)
	{
		return E_FAIL;
	}

	if (dwNumInterfaces < interfaceIndex)
	{
		return E_INVALIDARG;
	}

	ULONG ucbApaptersInfoLength = 0;
	dwRetVal = GetAdaptersInfo(NULL, &ucbApaptersInfoLength);

	IP_ADAPTER_INFO* pAdapterInfos = (IP_ADAPTER_INFO*)SAFE_ALLOC(ucbApaptersInfoLength);
	CheckPointer(pAdapterInfos, E_OUTOFMEMORY);

	dwRetVal = GetAdaptersInfo(pAdapterInfos, &ucbApaptersInfoLength);
	HRESULT hr = E_FAIL;
	
	if (dwRetVal == ERROR_SUCCESS && pAdapterInfos)
	{
		IP_ADAPTER_INFO* pCurrentAdapter = pAdapterInfos;
		do 
		{
			if (pCurrentAdapter->Index == interfaceIndex)
			{
				if (strlen(pCurrentAdapter->AdapterName))
				{
					CComBSTR bstrAdapterName(pCurrentAdapter->AdapterName);
					bstrAdapterName.CopyTo(&(pInterfaceInfo->bstrInterfaceName));
				}
				pInterfaceInfo->dwType = pCurrentAdapter->Type;
				pInterfaceInfo->dwInterfaceIndex = pCurrentAdapter->Index;

				break;
			}
			
		} while(pCurrentAdapter = pCurrentAdapter->Next); 
	}

	SAFE_FREE(pAdapterInfos);

	return hr;
}

// Caller Allocated Array of Adapter Infos (by val)
STDMETHODIMP CInternetProtocolHelper::GetAdapterInfoConciseForAllAdapters(SimpleInterfaceInfo* pInterfaceInfo, UINT *pcAdapters)
{
	CheckPointer(pInterfaceInfo, E_POINTER);
		
	DWORD dwNumInterfaces = 0;
	DWORD dwRetVal = GetNumberOfInterfaces(&dwNumInterfaces);
	dwNumInterfaces -= 1;
	
	if (dwRetVal != ERROR_SUCCESS)
	{
		return E_FAIL;
	}

	if (dwNumInterfaces > (*pcAdapters))
	{
		return E_INVALIDARG;
	}

	ULONG ucbApaptersInfoLength = 0;
	dwRetVal = GetAdaptersInfo(NULL, &ucbApaptersInfoLength);

	IP_ADAPTER_INFO* pAdapterInfos = (IP_ADAPTER_INFO*)SAFE_ALLOC(ucbApaptersInfoLength);
	CheckPointer(pAdapterInfos, E_OUTOFMEMORY);

	dwRetVal = GetAdaptersInfo(pAdapterInfos, &ucbApaptersInfoLength);
	HRESULT hr = E_FAIL;

	UINT index = 0;
	if (dwRetVal == ERROR_SUCCESS && pAdapterInfos)
	{
		IP_ADAPTER_INFO* pCurrentAdapter = pAdapterInfos;
		do 
		{
			if (strlen(pCurrentAdapter->AdapterName))
			{
				CComBSTR bstrAdapterName(pCurrentAdapter->AdapterName);
				bstrAdapterName.CopyTo(&(pInterfaceInfo[index].bstrInterfaceName));
			}

			pInterfaceInfo[index].dwType = pCurrentAdapter->Type;
			// pInterfaceInfo[index].dwMtu = 0;
			pInterfaceInfo[index].dwInterfaceIndex = pCurrentAdapter->Index;

		} while(pCurrentAdapter = pCurrentAdapter->Next); 
	}

	SAFE_FREE(pAdapterInfos);

	return hr;
}

STDMETHODIMP CInternetProtocolHelper::FindAdapterForAddress(BSTR bstrAddress, UINT *pIndex)
{
	CheckPointer(bstrAddress, E_POINTER);
	CheckPointer(pIndex, E_POINTER);

	ULONG ucbApaptersInfoLength = 0;
	DWORD dwRetVal = GetAdaptersInfo(NULL, &ucbApaptersInfoLength);

	IP_ADAPTER_INFO* pAdapterInfos = (IP_ADAPTER_INFO*)SAFE_ALLOC(ucbApaptersInfoLength);
	CheckPointer(pAdapterInfos, E_OUTOFMEMORY);

	dwRetVal = GetAdaptersInfo(pAdapterInfos, &ucbApaptersInfoLength);
	HRESULT hr = E_FAIL;

	UINT index = 0;
	
	CComBSTR bstrAddressCom(bstrAddress);
	bstrAddressCom.ToLower();

	if (dwRetVal == ERROR_SUCCESS && pAdapterInfos)
	{
		IP_ADAPTER_INFO* pCurrentAdapter = pAdapterInfos;
		do 
		{
			// get Adapter Address - seems Ipv4 only :-(
			// if (pCurrentAdapter->IpAddressList)
			{
				IP_ADDR_STRING *pCurrent = &(pCurrentAdapter->IpAddressList);
				do 
				{
					CComBSTR bstrCurrentAddress(pCurrent->IpAddress.String);
					if (bstrCurrentAddress == bstrAddressCom)
					{
						*pIndex = pCurrentAdapter->Index;
						hr = S_OK;
						
						goto cleanup;
					}
				} while(pCurrent = pCurrentAdapter->IpAddressList.Next);
			}
		} while(pCurrentAdapter = pCurrentAdapter->Next); 
	}

cleanup:

	SAFE_FREE(pAdapterInfos);

	return hr;

}
