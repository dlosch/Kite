# Building Kite RTP Library - Modern Version

This guide covers building the modernized Kite RTP library with Visual Studio 2019/2022.

## Quick Start

### Prerequisites
1. **Visual Studio 2019 or 2022** (Community/Professional/Enterprise)
2. **Desktop development with C++** workload
3. **C++ ATL** for latest build tools (x86 & x64)
4. **Windows 10/11 SDK** (latest version)

### Building All Components
1. Open `Kite.Rtp.Atl/Kite.Rtp.Atl_modern.sln`
2. Select **Debug** or **Release** configuration
3. Select **x86** or **x64** platform
4. Build → Build Solution (Ctrl+Shift+B)

### Building DirectShow Filters
1. Open `Kite.Rtp.Atl.Filter/Kite.Rtp.Atl.Filter_modern.sln`
2. Select configuration and platform
3. Build → Build Solution

## Project Structure

### Main RTP Library (`Kite.Rtp.Atl_modern.sln`)
- **Kite.Rtp.Atl** - Main COM component with RTP protocol implementation
- **Kite.Rtp.AtlPS** - Proxy/Stub DLL for COM marshalling

### DirectShow Filters (`Kite.Rtp.Atl.Filter_modern.sln`)
- **Kite.Rtp.Atl.Filter** - DirectShow filters for media streaming

## Required Visual Studio Components

### Workloads (Install via Visual Studio Installer)
- ✅ **Desktop development with C++**
- ✅ **C++ ATL for latest v143 build tools (x86 & x64)**
- ✅ **Windows 10/11 SDK**

### Individual Components (if installing separately)
- MSVC v143 - VS 2022 C++ x64/x86 build tools
- Windows 10 SDK (10.0.19041.0 or later)
- C++ ATL for latest v143 build tools (x86 & x64)
- C++ MFC for latest v143 build tools (x86 & x64) - for DirectShow filters

## Outputs

After successful build, you'll have:
- `Kite.Rtp.Atl.dll` - Main RTP library
- `Kite.Rtp.AtlPS.dll` - Proxy/Stub for COM
- `Kite.Rtp.Atl.Filter.dll` - DirectShow filters

## Platform Support
- **Windows 10/11** (x86 and x64)
- **COM-compatible** with existing applications
- **No longer supports** Windows XP/Vista/7/8

## Troubleshooting

**Build Errors:**
- **ATL not found** → Install C++ ATL components
- **Windows SDK missing** → Install latest Windows 10/11 SDK
- **strmbase.lib not found** → Verify DirectShow components in Windows SDK

**Clean Build:**
1. Build → Clean Solution
2. Delete Debug/Release folders
3. Build → Rebuild Solution

## What's Different from Original

- **Updated** from Visual Studio 2003 (.vcproj) to 2022 (.vcxproj) format
- **Added** x64 platform support
- **Modernized** ATL implementation (removed deprecated attributes)
- **Fixed** compiler warnings and RTP logic bugs
- **Updated** Windows SDK targeting to Windows 10

For detailed technical information, see `README_MODERNIZATION.md`.