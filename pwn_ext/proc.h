#pragma once

#include "includes.h"

class process
{
public:
	DWORD getProcId(const wchar_t* procName);
	uintptr_t getModuleBaseAddress(DWORD procId, const wchar_t* modName);
	uintptr_t findDynamicMemAddr(HANDLE hProc, uintptr_t ptr, std::vector<DWORD> offsets);

};

inline auto gProcess = std::make_unique<process>();