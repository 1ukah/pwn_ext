#include "player.h"

std::string player::getName(HANDLE hProcess, std::uintptr_t moduleBase, std::uintptr_t ptr, std::vector<DWORD> offsets)
{
    std::uintptr_t nameAddr = gProcess->findDynamicMemAddr(hProcess, (moduleBase + ptr), offsets);
    char nameVal[12] = { 0 };
    ReadProcessMemory(hProcess, (BYTE*)nameAddr, &nameVal, sizeof(nameVal), nullptr);
    return nameVal;
}

std::string player::getTeam(HANDLE hProcess, std::uintptr_t moduleBase, std::uintptr_t ptr, std::vector<DWORD> offsets)
{
    std::uintptr_t teamAddr = gProcess->findDynamicMemAddr(hProcess, (moduleBase + ptr), offsets);
    char teamVal[12] = { 0 };
    ReadProcessMemory(hProcess, (BYTE*)teamAddr + 0x18, &teamVal, sizeof(teamVal), nullptr);
    return teamVal;
}

int player::getHealth(HANDLE hProcess, std::uintptr_t moduleBase, std::uintptr_t ptr, std::vector<DWORD> offsets)
{
    std::uintptr_t healthAddr = gProcess->findDynamicMemAddr(hProcess, (moduleBase + ptr), offsets);
    int healthVal = 0;
    ReadProcessMemory(hProcess, (BYTE*)healthAddr - 0x48, &healthVal, sizeof(healthVal), nullptr);
    return healthVal;
}

int player::getMana(HANDLE hProcess, std::uintptr_t moduleBase, std::uintptr_t ptr, std::vector<DWORD> offsets)
{
    std::uintptr_t manaAddr = gProcess->findDynamicMemAddr(hProcess, (moduleBase + ptr), offsets);
    int manaVal = 0;
    ReadProcessMemory(hProcess, (BYTE*)manaAddr, &manaVal, sizeof(manaVal), nullptr);
    return manaVal;
}

float player::setWalkingSpeed(HANDLE hProcess, std::uintptr_t moduleBase, std::uintptr_t ptr, std::vector<DWORD> offsets, float val)
{
    std::uintptr_t wsAddr = gProcess->findDynamicMemAddr(hProcess, (moduleBase + ptr), offsets);
    float jhtValue = val;
    return (float)(WriteProcessMemory(hProcess, (BYTE*)wsAddr + 0x64, &jhtValue, sizeof(jhtValue), nullptr));
}

float player::setJumpHoldTime(HANDLE hProcess, std::uintptr_t moduleBase, std::uintptr_t ptr, std::vector<DWORD> offsets, float val)
{
    std::uintptr_t jhtAddr = gProcess->findDynamicMemAddr(hProcess, (moduleBase + ptr), offsets);
    float jhtValue = val;
    return (float)(WriteProcessMemory(hProcess, (BYTE*)jhtAddr + 0x6C, &jhtValue, sizeof(jhtValue), nullptr));
}

float player::setJumpSpeed(HANDLE hProcess, std::uintptr_t moduleBase, std::uintptr_t ptr, std::vector<DWORD> offsets, float val)
{
    std::uintptr_t jsAddr = gProcess->findDynamicMemAddr(hProcess, (moduleBase + ptr), offsets);
    float jsValue = val;
    return (float)(WriteProcessMemory(hProcess, (BYTE*)jsAddr + 0x68, &jsValue, sizeof(jsValue), nullptr));
}

bool player::setPvp(HANDLE hProcess, std::uintptr_t moduleBase, std::uintptr_t ptr, std::vector<DWORD> offsets, bool val)
{
    std::uintptr_t pvpAddr = gProcess->findDynamicMemAddr(hProcess, (moduleBase + ptr), offsets);
    bool pvpValue = val;
    return WriteProcessMemory(hProcess, (BYTE*)pvpAddr + 0x6D, &pvpValue, sizeof(pvpValue), nullptr);
}

bool player::setPvpDesired(HANDLE hProcess, std::uintptr_t moduleBase, std::uintptr_t ptr, std::vector<DWORD> offsets, bool val)
{
    std::uintptr_t pvpDesAddr = gProcess->findDynamicMemAddr(hProcess, (moduleBase + ptr), offsets);
    bool pvpDesValue = val;
    return WriteProcessMemory(hProcess, (BYTE*)pvpDesAddr + 0x6E, &pvpDesValue, sizeof(pvpDesValue), nullptr);
}

void player::update(HANDLE hProcess, std::uintptr_t moduleBase)
{
    player::setWalkingSpeed(hProcess, moduleBase, mem::pointers::pManaPtr, mem::offsets::pManaOffsets, 5000.f);
    player::setJumpSpeed(hProcess, moduleBase, mem::pointers::pManaPtr, mem::offsets::pManaOffsets, 1337.f);
    player::setJumpHoldTime(hProcess, moduleBase, mem::pointers::pManaPtr, mem::offsets::pManaOffsets, 37.f);
}