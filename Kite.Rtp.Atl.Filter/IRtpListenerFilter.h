#ifndef IRTPLISTENER_H
#define IRTPLISTENER_H

#if !EXTERNAL_INTERFACES
DECLARE_INTERFACE_(IRtpListenerOutputPin, IUnknown) 
{
	STDMETHOD(GetBufferPrefix)(INT *pcbPrefix);
};
#endif

// Flags
enum RTP_BUFFERED_LISTENER_DELIVERYMODES
{
	// Deliver one DeliveryUnit at a time, the Data-Buffers of the RtpPackets will be copied to one continuous buffer, excluding any rtp/payload headers
	RTP_BUFFERED_LISTENER_DELIVERYMODE_DELIVERYUNITS_CONCATENATED = 0x0001,
	// Deliver one DeliveryUnit at a time, the Data-Buffers of the RtpPackets will be copied multiple Samples, excluding any rtp/payload headers
	RTP_BUFFERED_LISTENER_DELIVERYMODE_DELIVERYUNITS_MULTIPLE_SAMPLES = 0x0002,
	// Deliver One RtpPacket at a time, excluding any header; Sequence is growing. (correct sequence)
	RTP_BUFFERED_LISTENER_DELIVERYMODE_DELIVERYUNITS_UNBUFFERED = 0x0004,

	// Combinable with:
	// Decide Buffersize will include a prefix where the header of the FIRST PACKET in the sample will be copied
	RTP_BUFFERED_LISTENER_DELIVERYMODE_REFIXED_BY_PAYLOADHEADER = 0x0100,
	// RTP_BUFFERED_LISTENER_DELIVERYMODE_REFIXED_BY_RTPHEADER = 0x0200
};

#endif
