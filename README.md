# Diploma thesis (parts of, middle of the 2000s) :)

I just found (parts of) the code from my diploma thesis from ca. 20 years ago:D

This was a media streaming app using RTP for live audio-/video-conferencing. The code consists of a full from scratch RTP stack (C++), plus DirectShow filters. I did integrate some codecs from ffmpeg. The solution was interoperable with some unix tools and it also talked to the infamous [NetMeeting](https://en.wikipedia.org/wiki/Microsoft_NetMeeting). H.263 was the frequently used codec at that time with H.264 just becoming available.

**I had never written any meaningful C++, COM, ATL, DirectShow filter, or Winsock code before**. Didn't know about apartment states (which probably make you [sound like a crazy person](https://x.com/jaredpar/status/1569840321760206849)). This was the result. 

*Even though I have no idea whether the result was or is considered ok by seasoned experts in said areas, I am still super proud of the result. I started from absolute zero, got up to speed with everything and still tried to produce neat solutions along the way.* 

Probably (unfortunately) still to this day my most challenging project (work and pet projects). Seeing a C++ app doing audio and video streaming, processing megabytes of data with a varienty other clients without crashing or memory hogging for hours. Sweet.* Even integrated some existing codecs from ffmpeg into the solution. The app was written in C#.

