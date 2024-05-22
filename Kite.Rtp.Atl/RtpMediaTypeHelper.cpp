#include "StdAfx.h"
#include ".\rtpmediatypehelper.h"

// avifmt.h/mmsystem.h
#ifndef mmioFOURCC
#	define mmioFOURCC( ch0, ch1, ch2, ch3 )				\
		( (DWORD)(BYTE)(ch0) | ( (DWORD)(BYTE)(ch1) << 8 ) |	\
		( (DWORD)(BYTE)(ch2) << 16 ) | ( (DWORD)(BYTE)(ch3) << 24 ) )
#endif

// From ffmpeguuids - unique, since Fourccc, aber hack 0x0001,
#define FOURCC_H263 mmioFOURCC('H','2','6','3')
#define FOURCC_h263 mmioFOURCC('h','2','6','3')
#define FOURCC_h26p mmioFOURCC('h','2','6','p')
#define FOURCC_H26P mmioFOURCC('H','2','6','P')

//		#define FOURCC_PPRP mmioFOURCC('P','P','R','P')
// Wishful thinking
#define FOURCC_H261 mmioFOURCC('H','2','6','1')
#define FOURCC_MP2T mmioFOURCC('M','P','2','T')	// Mpeg 2 Transport

#define FOURCC_iLBC mmioFOURCC('i', 'L', 'B', 'C')

struct FourCCToPayloadTypeMap
{
	UINT fourCC;
	BYTE payloadType;
	BOOL bVideoJitterBuffer;
};

static UINT s_fourCCPayloadTypeCount = 4;

static FourCCToPayloadTypeMap s_fourCCPayloatTypeMap[] =
{
	{
		FOURCC_H263,
			0x22,
			TRUE
	},
	{
		FOURCC_h263,
			0x22,
			TRUE
	},
	{
		FOURCC_H26P,
			0x22,
			TRUE
	},
	{
		FOURCC_h26p,
			0x22,
			TRUE
	},
	{
		FOURCC_H261,
			0x1F,
			TRUE
	},
	{
		FOURCC_MP2T,
			0x21,
			TRUE
	},
	{
		FOURCC_iLBC,
			0x63, // 99
			FALSE
	}
};

STDMETHODIMP RtpMediatypeHelper_FourCCToPayloadType(UINT fourCC, BYTE *pPayloadType)
{
	CheckPointer(pPayloadType, E_POINTER);
	
	for (UINT i = 0; i < s_fourCCPayloadTypeCount; i++)
	{
		if (s_fourCCPayloatTypeMap[i].fourCC == fourCC)
		{
			(*pPayloadType) = s_fourCCPayloatTypeMap[i].payloadType;
			return S_OK;
		}
	}

	return E_FAIL;
}
