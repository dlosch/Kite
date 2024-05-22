#ifndef IRTPPAYLOADPACKETIZER_H
#define IRTPPAYLOADPACKETIZER_H

[export]
struct MyRegPinTypes 
{
	GUID clsMajorType;
	GUID clsMinorType;
};

[
	object,
	uuid("66AA121D-17DD-469B-9D25-C7F7250CDD99"),
	helpstring("IRtpPayloadPacketizer Interface"),
	pointer_default(unique)
]
__interface IRtpPayloadPacketizer : IUnknown
{
	// get and set Mtu
	[propget] HRESULT MaxBufferSize([out, retval] UINT *pcbMtu);
	[propput] HRESULT MaxBufferSize([in] UINT cbMtu);

	[propget] HRESULT GuidCount([out, retval] UINT *pcGuids);
	HRESULT GetGuids([in, out] MyRegPinTypes* pRegPinTypes);

	HRESULT Packetize(
		[in] BYTE* pBuffer, [in] UINT cbBuffer, [out] BYTE*** ppBuffer, 
		///*[in/out]*/ BYTE *pTargetBuffer, /*[in]*/ UINT cbTargetBuffer,
		[out] UINT **ppcbBuffers, [out] UINT *pcBuffers);


	HRESULT Depacketize([in] BYTE** pBuffers, [in] UINT *pcbBuffers, [in] UINT *pSeqNums, [in] UINT cBuffers, 
		//[out] BYTE** pBuffer, [out] UINT *pcbBuffer, [out] UINT *pcbSkipped);
		[in,out] BYTE* pBuffer, [in,out] UINT *pcbBuffer, [out] UINT *pcbSkipped);
};
#endif