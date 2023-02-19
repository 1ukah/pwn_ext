#pragma once

#include "includes.h"
#include "proc.h"
#include "mem.h"

class player
{
public:
	// Read
	std::string getName(HANDLE hProcess, std::uintptr_t moduleBase, std::uintptr_t ptr, std::vector<DWORD> offsets);
	std::string getTeam(HANDLE hProcess, std::uintptr_t moduleBase, std::uintptr_t ptr, std::vector<DWORD> offsets);
	int getHealth(HANDLE hProcess, std::uintptr_t moduleBase, std::uintptr_t ptr, std::vector<DWORD> offsets);
	int getMana(HANDLE hProcess, std::uintptr_t moduleBase, std::uintptr_t ptr, std::vector<DWORD> offsets);

private:
	// Write
	float setWalkingSpeed(HANDLE hProcess, std::uintptr_t moduleBase, std::uintptr_t ptr, std::vector<DWORD> offsets, float val);
	float setJumpHoldTime(HANDLE hProcess, std::uintptr_t moduleBase, std::uintptr_t ptr, std::vector<DWORD> offsets, float val);
	float setJumpSpeed(HANDLE hProcess, std::uintptr_t moduleBase, std::uintptr_t ptr, std::vector<DWORD> offsets, float val);
	bool setPvp(HANDLE hProcess, std::uintptr_t moduleBase, std::uintptr_t ptr, std::vector<DWORD> offsets, bool val);
	bool setPvpDesired(HANDLE hProcess, std::uintptr_t moduleBase, std::uintptr_t ptr, std::vector<DWORD> offsets, bool val);

public:
	void update(HANDLE hProcess, std::uintptr_t moduleBase);
};

inline auto gPlayer = std::make_unique<player>();

