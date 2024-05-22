#pragma once
#ifndef RTPLISTENEREVENTCALLBACKS_H
#define RTPLISTENEREVENTCALLBACKS_H
//#include "RtpStructs.h"


[
	object,
	uuid("1ABEA164-797F-4A07-93AD-7DACBE477F48"),
	helpstring("IRtpBufferedListenerFilterEventConsumer Interface"),
	pointer_default(unique)
]
__interface IRtpBufferedListenerFilterEventConsumer : IUnknown
{
	[helpstring("method ActiveSourceAdded")] HRESULT ActiveSourceAdded([in] UINT ssrc);
	[helpstring("method ActiveSourceRemoved")] HRESULT ActiveSourceRemoved([in] UINT ssrc);
	
	HRESULT SourceActiveValueChanged([in] UINT ssrc, [in] INT active);
	HRESULT SourceMuteValueChanged([in] UINT ssrc, [in] INT muted);

	HRESULT SourceEvent([in] UINT ssrc, [in] INT eventType);
	HRESULT SourceReception([in] UINT ssrc, INT packetsRecvd, INT packetsLost, INT packetsMisordered, INT jitter, INT validityTime);
	HRESULT SourceAttributes([in] UINT ssrc, LPWSTR cname, LPWSTR name, LPWSTR email, LPWSTR phone, LPWSTR loc, LPWSTR tool, LPWSTR note);

};


[
	object,
	uuid("1ABEA165-797F-4A07-93AD-7DACBE477F48"),
	helpstring("IRtpBufferedListenerFilterEventConsumerEx Interface"),
	pointer_default(unique)
]
__interface IRtpBufferedListenerFilterEventConsumerEx : IUnknown
{
};


// Defines Interfaces that clients need to implement to receive Callback notifications from the RtpListener
// Vergleichbar mit dem "RegisterListener"-Modell von Java
// Peinlich: was besseres ist mir nicht eingefallen

[
	object,
	uuid("1ABEA162-797F-4A07-93AD-7DACBE477F48"),
	helpstring("IRtpListenerEventConsumer Interface"),
	pointer_default(unique)
]
__interface IRtpListenerEventConsumer : IUnknown
{
	[helpstring("method ActiveSourceAdded")] HRESULT ActiveSourceAdded([in] UINT ssrc);
	[helpstring("method ActiveSourceRemoved")] HRESULT ActiveSourceRemoved([in] UINT ssrc);
	[helpstring("method ActiveSourceRemoved")] HRESULT ActiveSourceChanged([in] UINT ssrc, [in] INT eventType);
};

[
	object,
	uuid("1ABEA163-797F-4A07-93AD-7DACBE477F48"),
	helpstring("IRtpBufferedListenerEventConsumer Interface"),
	pointer_default(unique)
]
__interface IRtpBufferedListenerEventConsumer : IUnknown
{
};

[
	object,
	uuid("2ABEA162-797F-4A07-93AD-7DACBE477F48"),
	helpstring("IRtpRendererEventConsumer Interface"),
	pointer_default(unique)
]
__interface IRtpRendererEventConsumer : IUnknown
{
	[helpstring("method ReceiverReportReceived")] HRESULT ReceiverReportReceived([in] UINT ssrcReportSource);
};

#endif