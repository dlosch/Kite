// InternetProtocolHelper.h : Declaration of the CInternetProtocolHelper

#pragma once
#include "resource.h"       // main symbols

[export]
struct SimpleInterfaceInfo
{
	BSTR bstrInterfaceName;

	DWORD dwInterfaceIndex;

	DWORD dwMtu;

	DWORD dwType;
};

// IInternetProtocolHelper
[
	object,
	uuid("011B1D0D-BC47-46E7-9859-8F7016D96543"),
	helpstring("IInternetProtocolHelper Interface"),
	pointer_default(unique)
]
__interface IInternetProtocolHelper : IUnknown
{
	[helpstring("method QueryMtuForInterface")] HRESULT QueryMtuForInterface([in] UINT interfaceIndex, [out,retval] UINT* pMtu);
	[helpstring("method ")] HRESULT GetAdapterInfoConcise([in] UINT interfaceIndex, [in,out]SimpleInterfaceInfo* pInterfaceInfo);
	[helpstring("method ")] HRESULT GetAdapterInfoConciseForAllAdapters([in,out] SimpleInterfaceInfo* pInterfaceInfo, [in,out] UINT *pcAdapters);
	[helpstring("method ")] HRESULT FindAdapterForAddress([in] BSTR bstrAddress, [out] UINT *pIndex);
};


// CInternetProtocolHelper
// Wraps IP Helper Functions, so's they may be called from C++ as well as from .net
[
	coclass,
	threading("both"),
	aggregatable("never"),
	vi_progid("KiteRtpAtl.InternetProtocolHelper"),
	progid("KiteRtpAtl.InternetProtocolHelper.1"),
	version(1.0),
	uuid("A1A6FBF9-1273-4A9D-98CF-D8B8DD3384B1"),
	helpstring("InternetProtocolHelper Class")
]
class ATL_NO_VTABLE CInternetProtocolHelper : 
	public IInternetProtocolHelper
{
public:
	CInternetProtocolHelper();
	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct();
	void FinalRelease();

public:

	STDMETHOD(QueryMtuForInterface)(UINT interfaceIndex, UINT* pMtu);
	STDMETHOD(GetAdapterCount)(UINT *pAdapterCount);
	STDMETHOD(GetAdapterInfoConcise)(UINT interfaceIndex, SimpleInterfaceInfo* pInterfaceInfo);
	// Array of values
	STDMETHOD(GetAdapterInfoConciseForAllAdapters)(SimpleInterfaceInfo* pInterfaceInfo, UINT *pcAdapters);
	
	STDMETHOD(FindAdapterForAddress)(BSTR bstrAddress, UINT *pIndex);
};

