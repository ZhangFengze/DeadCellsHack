#include "console.h"
#include "structures.h"
#include <BlackBone/Process/Process.h>
#include <Windows.h>

using namespace blackbone;

DWORD WINAPI OnDllAttach(LPVOID base)
{
    CreateConsole();
    ConsolePrint("console created\n");

    Process thisProcess;
    if (!NT_SUCCESS(thisProcess.Attach(GetCurrentProcessId())))
    {
        ConsolePrintW(L"can not attach process %08X\n", GetCurrentProcessId());
        return TRUE;
    }
    ConsolePrintW(L"attached to process %08X\n", thisProcess.pid());

    auto& memory = thisProcess.memory();
    auto mainMod = thisProcess.modules().GetMainModule();

    auto [_, gameAddr] = memory.Read<uint32_t>({
        mainMod->baseAddress + 0x00016904,
        0x0,
        0x10,
        0x454,
        0x10C,
        0x0,
        0x18
        });
    ConsolePrint("game addr %0X\n", *gameAddr);

    Sleep(5000);
    ReleaseConsole();
    FreeLibraryAndExitThread(static_cast<HMODULE>(base), 1);
    return TRUE;
}

BOOL WINAPI OnDllDetach()
{
    ReleaseConsole();
    return TRUE;
}

BOOL WINAPI DllMain(
    _In_      HINSTANCE hinstDll,
    _In_      DWORD     fdwReason,
    _In_opt_  LPVOID    lpvReserved
)
{
    switch (fdwReason) {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hinstDll);
        CreateThread(nullptr, 0, OnDllAttach, hinstDll, 0, nullptr);
        return TRUE;
    case DLL_PROCESS_DETACH:
        if (lpvReserved == nullptr)
            return OnDllDetach();
        return TRUE;
    default:
        return TRUE;
    }
}
