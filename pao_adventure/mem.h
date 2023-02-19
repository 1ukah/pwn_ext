#pragma once

#include "includes.h"

namespace mem
{
	namespace pointers
	{
		inline std::uintptr_t pManaPtr = 0x0168C37C;
		inline std::uintptr_t pNamePtr = 0x0166BAB4;
	}

	namespace offsets
	{
		inline std::vector<DWORD> pManaOffsets{ 0x198, 0x6C, 0x20, 0x50C, 0xBC };
		inline std::vector<DWORD> pNameOffsets{ 0x470, 0xAC, 0x20, 0x75C, 0x250, 0x50C, 0x08 };
	}
}