#include <cstdio>
#include <windows.h>
#include <VersionHelpers.h>

#define Kilobytes(Value) ((Value)*1024LL)
#define Megabytes(Value) (Kilobytes(Value)*1024LL)
#define Gigabytes(Value) (Megabytes(Value)*1024LL)
#define Terabytes(Value) (Gigabytes(Value)*1024LL)

static SYSTEM_INFO sysInfo;

void idProcessorArchitecture()
{
    char *pArchType;
    switch(sysInfo.wProcessorArchitecture)
    {
        case 9:
        {
            pArchType = "64 bit (x86_64)";
        } break;
        case 0:
        {
            pArchType = "32 bit (x86)";
        } break;
        case 5:
        {
            pArchType = "ARM processor";
        } break;
        case 1:
        {
            pArchType = "MIPS processor";
        } break;
        case 2:
        {
            pArchType = "ALPHA processor";
        } break;
        case 3:
        {
            pArchType = "PPC processor";
        } break;
        case 4:
        {
            pArchType = "SHX processor";
        } break;
        case 7:
        {
            pArchType = "ALPHA64 processor";
        } break;
        case 8:
        {
            pArchType = "MSIL processor";
        } break;
        case 10:
        {
            pArchType = "IA32_ON_WIN64 processor";
        } break;
        case 6:
        {
            pArchType = "Intel Itanium-based processor";
        } break;
        case 0xffff:
        {
            pArchType = "Unknown processor";
        } break;
    }

    printf("\nProcessor Architecture : %s", pArchType);
}

void dectectOS() //TODO:Fix this as it doesn't know how to check version
{
    char *osVersion;
    //if(IsWindows10OrGreater()) osVersion = "Windows 10";
    if(IsWindows8Point1OrGreater()) osVersion = "Windows 8.1";
    else if(IsWindows8OrGreater()) osVersion = "Windows 8";
    else if(IsWindows7SP1OrGreater()) osVersion = "Windows 7 Service Pack 1";
    else if(IsWindowsVistaSP2OrGreater()) osVersion = "Windows Vista Service Pack 2";
    else if(IsWindowsVistaSP1OrGreater()) osVersion = "Windows Vista Service Pack 1";
    else if(IsWindowsVistaOrGreater()) osVersion = "Windows Vista";
    else if(IsWindowsXPSP3OrGreater()) osVersion = "Windows XP Service Pack 3";
    else if(IsWindowsXPSP2OrGreater()) osVersion = "Windows XP Service Pack 2";
    else if(IsWindowsXPSP1OrGreater()) osVersion = "Windows XP Service Pack 1";
    else if(IsWindowsXPOrGreater()) osVersion = "Windows XP";
    else if(IsWindowsServer()) osVersion = "Windows Server";

    printf("\nOS Version : %s", osVersion);
}

void currentSystemMemoryInformation()
{
    unsigned long long installedMemory = 0;
    GetPhysicallyInstalledSystemMemory(&installedMemory);

    MEMORYSTATUSEX memstatus; memstatus.dwLength = sizeof(memstatus);
    GlobalMemoryStatusEx(&memstatus);

    printf("\nInstalled Memory : %lld Gigabytes",((installedMemory/1024)/1024));
    printf("\nPhysical Usable memory %lld, Gigabytes",((memstatus.ullTotalPhys/1024)/1024));
    printf("\nCurrent memory in use : %d%", memstatus.dwMemoryLoad);

    printf("\nPage Size : %d", sysInfo.dwPageSize); // Page Size
}

void main()
{
    GetNativeSystemInfo(&sysInfo); // 64bit

    dectectOS();
//    if(sysInfo.dwOemId) {printf("\nOEM ID : %s", sysInfo.dwOemId);}
    idProcessorArchitecture(); // get CPU ARCHITECTURE
    printf("\nNumber of Logical Processors : %d", sysInfo.dwNumberOfProcessors);
    currentSystemMemoryInformation();

}

