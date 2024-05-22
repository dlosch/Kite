// TestRtpJitterBuffer.cpp : Implementation of CTestRtpJitterBuffer

#include "stdafx.h"
#include "TestRtpJitterBuffer.h"

												  
// CTestRtpJitterBuffer

LONG g_seqNum = 0;
UINT g_timestamp = 0;

VOID CreatePacket(RtpParsedPacket **ppPacket, BOOL bMarker, UINT seqNum, UINT timestamp)
{
	*ppPacket = (RtpParsedPacket*)SAFE_ALLOC(sizeof(RtpParsedPacket));
	ASSERT(*ppPacket);
	(*ppPacket)->cbData = 640;
	(*ppPacket)->cc = 0;
	(*ppPacket)->ext = FALSE;
	(*ppPacket)->marker = bMarker;
	(*ppPacket)->pad = FALSE;
	(*ppPacket)->pData = (BYTE*)CoTaskMemAlloc((*ppPacket)->cbData);
	(*ppPacket)->seqNum = seqNum;
	(*ppPacket)->ssrc = 0;
	(*ppPacket)->timestamp = timestamp;
}

STDMETHODIMP CTestRtpJitterBuffer::Test()
{
	CVideoJitterBuffer *pJitterBuffer = new CVideoJitterBuffer();

	RtpParsedPacket *pPacket = NULL;
	HRESULT hr = S_OK;

	UINT seqNums[] = 
	{
		1,5,7,2,3,4,11,9,12,11,10,16,17,18,19,23,20,
		
		24,28,30,25,28,27,34,32,35,34,33,39,40,41,44,46,43
	};

	/*
	 *	0-4
		5-6
		7-11
		12-16
		17
		18-22
		23-26
	 */

	UINT timestamps[] = 
	{
		0,1,2,0,0,0,2,2,3,2,2,3,4,5,5,6,5,
		
		6,7,8,6,6,6,8,8,9,8,8,9,10,11,11,12,11	
	};

	UINT uNumItems = sizeof(seqNums) / sizeof(seqNums[0]);
	UINT uNumItems2 = sizeof(timestamps) / sizeof(timestamps[0]);
	ASSERT(uNumItems == uNumItems2);

	for (UINT u = 0; u < uNumItems; u++)
	{
		UINT seqNum = seqNums[u];// rand() % 100;
		UINT timestamp = timestamps[u]; //rand() % 10) * 90000;

		BOOL bMarker = (seqNum == 4 ||seqNum ==6 ||seqNum == 11||seqNum == 16||seqNum == 17||seqNum == 22||seqNum == 26);
		CreatePacket(&pPacket, bMarker, seqNum, timestamp * 90000);

		ATLTRACE2("Enqueue: Seq %u Time %u bMarker %d \r\n", pPacket->seqNum, pPacket->timestamp, pPacket->marker);;
		hr = pJitterBuffer->EnqueuePacket(pPacket);
		ATLTRACE2("Enqueue: Seq %u Time %u bMarker %d hr 0x%x \r\n", pPacket->seqNum, pPacket->timestamp, pPacket->marker, hr);;
	}

	pJitterBuffer->DebugPrint();

	Sleep(10000);

	delete pJitterBuffer;

	return S_FALSE;
	// Finder, der erfolg haben sollte
	pJitterBuffer->TimeoutDeliveryUnitsEarlierThan(2);

	ATLTRACE2("#######################################################################");
	UINT cPackets;
	RtpParsedPacket** ppParsedPacketsFrame = NULL; 

	do {
		hr = pJitterBuffer->DequeueDeliveryUnit(&ppParsedPacketsFrame, &cPackets);
		ATLTRACE2("DequeueDeliveryUnit returned 0x%x, numPackets %d\r\n", hr, cPackets);

		for (UINT u = 0; u < cPackets; u++)
		{
			ATLTRACE2("\t\tPacket: seqNum %d, ts %d, Size %d \r\n", ppParsedPacketsFrame[u]->seqNum, ppParsedPacketsFrame[u]->timestamp, ppParsedPacketsFrame[u]->cbData );
		}

	} while(hr == S_OK);

	ATLTRACE2("- - - - - - - - - - - Clear Buffer sizeof() == %d \r\n", sizeof(CVideoJitterBuffer));
	pJitterBuffer->ClearBuffer();

	delete pJitterBuffer;

	return S_OK;
}

STDMETHODIMP CTestRtpJitterBuffer::TestAudioBuffer()
{
	CAudioJitterBuffer *pBuffer = new CAudioJitterBuffer;
	pBuffer->DebugPrint();

	UINT seqNums[] = 
	{
		1,5,7,2,3,4,11,9,12,11,10,16,17,18,19,23,20,

	//	24,28,30,25,28,27,34,32,35,34,33,39,40,41,44,46,43
	};

	// Timestamp == SeqNum * 8000 / 30 == 267 
	
	UINT u = 0;
	RtpParsedPacket *pPacket = NULL;
	for (; u < sizeof(seqNums) / sizeof(seqNums[0]); u++)
	{
		CreatePacket(&pPacket, FALSE, seqNums[u], (seqNums[u] * 8000 / 30));

		pBuffer->Insert(pPacket);
		pBuffer->DebugPrint();
	}

	pPacket = NULL;
	u = 0;
	while ((pPacket = pBuffer->Dequeue()) != NULL)
	{
		u++;
		ATLTRACE2("\t * TimeStamp 0x%x (%d) \r\n", pPacket->timestamp, pPacket->timestamp);
		ATLTRACE2("\t * SeqNum    0x%x (%d) \r\n", pPacket->seqNum, pPacket->seqNum);
		ATLTRACE2("\t * Marker    %d \r\n", pPacket->marker);
		ATLTRACE2("\t * cbData    %d \r\n", pPacket->cbData);
		pBuffer->DebugPrint();

		if (u > 5) break;
	}

	pBuffer->DebugPrint();
	ATLTRACE2("	pBuffer->RemoveEarlierOrEqual(3000); \r\n");
	pBuffer->RemoveEarlierOrEqual(3000);
	pBuffer->DebugPrint();

	ATLTRACE2("	pBuffer->RemoveEarlierOrEqual(3000); \r\n");
	pBuffer->RemoveEarlierOrEqual(3000);
	pBuffer->DebugPrint();

	ATLTRACE2("	pBuffer->RemoveEarlierOrEqual(3200); \r\n");
	pBuffer->RemoveEarlierOrEqual(3200);
	pBuffer->DebugPrint();

	ATLTRACE2("	pBuffer->RemoveEarlierOrEqual(2800); \r\n");
	pBuffer->RemoveEarlierOrEqual(2800);
	pBuffer->DebugPrint();

	SAFE_DELETE(pBuffer);

	return S_OK;
}