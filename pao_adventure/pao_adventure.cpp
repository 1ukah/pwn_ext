#include "includes.h"
#include "proc.h"
#include "player.h"

#pragma warning(disable : 4244)

#define nop "\x90"

int main()
{
    DWORD procId = gProcess->getProcId(L"PwnAdventure3-Win32-Shipping.exe");
    std::uintptr_t moduleBase = gProcess->getModuleBaseAddress(procId, L"PwnAdventure3-Win32-Shipping.exe");
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);

    SetConsoleTitleA("pao_adventure");

    gPlayer->update(hProcess, moduleBase);

    while (true)
    {
        if (GetAsyncKeyState(VK_END) & 1)
            return 0;
        
        system("cls");

        std::cout << "Name: " << gPlayer->getName(hProcess, moduleBase, mem::pointers::pNamePtr, mem::offsets::pNameOffsets) << std::endl;
        std::cout << "Team: " << gPlayer->getTeam(hProcess, moduleBase, mem::pointers::pNamePtr, mem::offsets::pNameOffsets) << std::endl;
        std::cout << "Health: " << gPlayer->getHealth(hProcess, moduleBase, mem::pointers::pNamePtr, mem::offsets::pNameOffsets) << std::endl;
        std::cout << "Mana: " << gPlayer->getMana(hProcess, moduleBase, mem::pointers::pManaPtr, mem::offsets::pManaOffsets) << std::endl;

        Sleep(100);
    }

    return 0;
}