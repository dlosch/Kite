#ifndef RTPUUIDS_H
#define RTPUUIDS_H

#include <streams.h>
#include <InitGuid.h>

#include "kiteshareduuids.h"


// DA2B5440-D7AE-45c4-AE59-8620361525DC
DEFINE_GUID(IID_IRtpRendererFilterConfiguration,
			0xDA2B5440, 0xD7AE, 0x45c4, 0xAE, 0x59, 0x86, 0x20, 0x36, 0x15, 0x25, 0xDC);


//	D32EA7F4-59D2-4A6B-ACCF-E70A323004A3
// {D32EA7F4-59D2-4a6b-ACCF-E70A323004A3}
DEFINE_GUID(CLSID_RtpBufferedListenerFilter, 
			0xd32ea7f4, 0x59d2, 0x4a6b, 0xac, 0xcf, 0xe7, 0xa, 0x32, 0x30, 0x4, 0xa3);

// {D32EA7A4-59D2-4a6b-ACCF-E70A323004A3}
DEFINE_GUID(CLSID_RtpBufferedListenerFilterSinglePin, 
			0xd32ea7a4, 0x59d2, 0x4a6b, 0xac, 0xcf, 0xe7, 0xa, 0x32, 0x30, 0x4, 0xa3);

// {D32EA7F5-59D2-4a6b-ACCF-E70A323004A3}
DEFINE_GUID(IID_IRtpBufferedListenerFilter, 
			0xd32ea7f5, 0x59d2, 0x4a6b, 0xac, 0xcf, 0xe7, 0xa, 0x32, 0x30, 0x4, 0xa3);

	
// {IRtpBufferedListenerFilterSingleOutputPinIRtpBufferedListenerFilterSingleOutputPin-59D2-4a6b-ACCF-E70A323004A3}
DEFINE_GUID(IID_IRtpBufferedListenerFilterSingleOutputPin, 
			0xd32ea7e5, 0x59d2, 0x4a6b, 0xac, 0xcf, 0xe7, 0xa, 0x32, 0x30, 0x4, 0xa3);

// {D32EA7F6-59D2-4a6b-ACCF-E70A323004A3}
DEFINE_GUID(CLSID_IRtpBufferedListenerFilterPropertyPage, 
			0xd32ea7f6, 0x59d2, 0x4a6b, 0xac, 0xcf, 0xe7, 0xa, 0x32, 0x30, 0x4, 0xa3);

//////////////////////////////////////////////////////////////////////////

// {D32EA7F7-59D2-4a6b-ACCF-E70A323004A3}
DEFINE_GUID(CLSID_RtpRenderer, 
			0xd32ea7f7, 0x59d2, 0x4a6b, 0xac, 0xcf, 0xe7, 0xa, 0x32, 0x30, 0x4, 0xa3);

// {D32EA7F8-59D2-4a6b-ACCF-E70A323004A3}
DEFINE_GUID(IID_IRtpRendererFilter, 
			0xd32ea7f8, 0x59d2, 0x4a6b, 0xac, 0xcf, 0xe7, 0xa, 0x32, 0x30, 0x4, 0xa3);

// {D32EA7F9-59D2-4a6b-ACCF-E70A323004A3}
DEFINE_GUID(CLSID_RtpRendererPropertyPage, 
			0xd32ea7f9, 0x59d2, 0x4a6b, 0xac, 0xcf, 0xe7, 0xa, 0x32, 0x30, 0x4, 0xa3);

// {D32EA7FA-59D2-4a6b-ACCF-E70A323004A3}
DEFINE_GUID(IID_IRtpRendererFilterEx, 
			0xd32ea7fa, 0x59d2, 0x4a6b, 0xac, 0xcf, 0xe7, 0xa, 0x32, 0x30, 0x4, 0xa3);

//////////////////////////////////////////////////////////////////////////

//// {D32EA7FB-59D2-4a6b-ACCF-E70A323004A3}
//DEFINE_GUID(IID_IRtpListenerOutputPin, 
//			0xd32ea7fb, 0x59d2, 0x4a6b, 0xac, 0xcf, 0xe7, 0xa, 0x32, 0x30, 0x4, 0xa3);

//////////////////////////////////////////////////////////////////////////
//// From ffmpeguuids - unique, since Fourccc, aber hack 0x0001,
//#define FOURCC_H263 mmioFOURCC('H','2','6','3')
//DEFINE_GUID(MEDIATYPE_H263, FOURCC_H263, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71);
//
//#define FOURCC_h263 mmioFOURCC('h','2','6','3')
//DEFINE_GUID(MEDIATYPE_h263, FOURCC_h263, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71);
//
//#define FOURCC_h26p mmioFOURCC('h','2','6','p')
//DEFINE_GUID(MEDIATYPE_h26p, FOURCC_h26p, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71);
//
//#define FOURCC_H26P mmioFOURCC('H','2','6','P')
//DEFINE_GUID(MEDIATYPE_H26P, FOURCC_H26P, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71);
//
//DEFINE_GUID(MEDIATYPE_H263_RTP, FOURCC_H263, 0x0001, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71);
//DEFINE_GUID(MEDIATYPE_h263_rtp, FOURCC_h263, 0x0001, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71);
//DEFINE_GUID(MEDIATYPE_h26p_rtp, FOURCC_h26p, 0x0001, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71);
//DEFINE_GUID(MEDIATYPE_H26P_RTP, FOURCC_H26P, 0x0001, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71);


////DEFINE_GUID(IID_IRtpRenderer,
////			0x23AAF37A, 0x90F4, 0x48E9, 0xB8, 0x16, 0x9E, 0xEA, 0xFE, 0x49, 0x12, 0xA8);
////
////DEFINE_GUID(CLSID_CRtpRenderer,
////			0x7A6BE560, 0x2C33, 0x4426, 0xBF, 0x2B, 0x17, 0xB0, 0xDC, 0xCF, 0xF5, 0x23);


#endif
