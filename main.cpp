#include <BlackBone/Process/Process.h>

using namespace blackbone;

const auto processName = L"deadcells.exe";

int main()
{
    Process gameProcess;
    if (!NT_SUCCESS(gameProcess.Attach(processName, PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_QUERY_INFORMATION)))
    {
        wprintf(L"can not attach to %s\n", processName);
        return -1;
    }
    wprintf(L"attached to %s [%d]\n", processName, gameProcess.pid());

    auto& memory = gameProcess.memory();
    auto mainMod = gameProcess.modules().GetMainModule();

    auto [_, gameAddr] = memory.Read<uint32_t>({
        mainMod->baseAddress + 0x00016904,
        0x0,
        0x10,
        0x454,
        0x10C,
        0x0,
        0x18
        });
    printf("game addr %0X\n", *gameAddr);

    auto [__, playerAddr] = memory.Read<uint32_t>({
        *gameAddr + 0x64
        });
    printf("player addr %0X\n", *playerAddr);

    auto [___, hpValue] = memory.Read<int32_t>({
        *playerAddr + 0xFC
        });
    printf("hp value %d\n", *hpValue);

    return 0;
}