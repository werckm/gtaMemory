#pragma once
#include <Windows.h>

class Memory {
public:
	int ReadProcessMemorySA(HWND hWnd, LPVOID address);

	int WriteProcessMemorySA(HWND hWnd, LPVOID address, unsigned long newData);
	int WriteProcessMemorySA(HWND hWnd, LPVOID address, byte newData);
	int WriteProcessMemorySA(HWND hWnd, LPVOID address, float newData);
};