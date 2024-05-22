// TestRtpJitterBuffer.h : Declaration of the CTestRtpJitterBuffer

#pragma once
#include "resource.h"       // main symbols

#include "VideoJitterBuffer.h"
#include "AudioJitterBuffer.h"

// ITestRtpJitterBuffer
[
	object,
	uuid("7507A94E-B7EB-4974-A0C4-CFBFA5A74874"),
	helpstring("ITestRtpJitterBuffer Interface"),
	pointer_default(unique)
]
__interface ITestRtpJitterBuffer : IUnknown
{
	HRESULT Test();
	HRESULT TestAudioBuffer();
};



// CTestRtpJitterBuffer

[
	coclass,
	// threading("apartment"),
	threading("both"),
	aggregatable("never"),
	vi_progid("KiteRtpAtl.TestRtpJitterBuffer"),
	progid("KiteRtpAtl.TestRtpJitterBuffer.1"),
	version(1.0),
	uuid("4DBA237A-C934-4521-A021-846256D11FC7"),
	helpstring("TestRtpJitterBuffer Class")
]
class ATL_NO_VTABLE CTestRtpJitterBuffer : 
	public ITestRtpJitterBuffer
{
public:
	CTestRtpJitterBuffer()
	{
	}

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}
	
	void FinalRelease() 
	{
	}

public:

	STDMETHOD(Test)();
	STDMETHOD(TestAudioBuffer)();
};

