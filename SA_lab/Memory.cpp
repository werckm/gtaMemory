#include "Memory.h"
#include <iostream>
#include <Windows.h>

int Memory::ReadProcessMemorySA(HWND hWnd, LPVOID address) {
	DWORD processID;
	GetWindowThreadProcessId(hWnd, &processID);

	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);
	if(!hProcess) {
		DWORD errorCode = GetLastError();
		std::cerr << "ERROR: Could not open process! Error code: " << errorCode;
	} else {
		DWORD readData = 0;
		DWORD readDataSize = sizeof(readData);
		if(ReadProcessMemory(hProcess, address, &readData, readDataSize, NULL)) {
			std::cout << readData;
		} else {
			DWORD errorCode = GetLastError();
			std::cerr << "ERROR: Cannot read process memory! Error code: " << errorCode;
		}
		CloseHandle(hProcess);
	}

	return 0;
}

int Memory::WriteProcessMemorySA(HWND hWnd, LPVOID address, unsigned long newData) {
	DWORD processID;
	GetWindowThreadProcessId(hWnd, &processID);

	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);
	if(!hProcess) {
		DWORD errorCode = GetLastError();
		std::cerr << "ERROR: Could not open process! Error code: " << errorCode;
		return 1;
	} else {
		DWORD newDataSize = sizeof(newData);
		if(WriteProcessMemory(hProcess, address, &newData, newDataSize, NULL)) {
			std::cout << "INFO: WriteProcessMemory worked!";
		} else {
			DWORD errorCode = GetLastError();
			std::cerr << "ERROR: Cannot write process memory! Error code: " << errorCode;
			return 1;
		}
		CloseHandle(hProcess);
	}

	return 0;
}

int Memory::WriteProcessMemorySA(HWND hWnd, LPVOID address, byte newData) {
	DWORD processID;
	GetWindowThreadProcessId(hWnd, &processID);

	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);
	if(!hProcess) {
		DWORD errorCode = GetLastError();
		std::cerr << "ERROR: Could not open process! Error code: " << errorCode;
		return 1;
	} else {
		DWORD newDataSize = sizeof(newData);
		if(WriteProcessMemory(hProcess, address, &newData, newDataSize, NULL)) {
			std::cout << "INFO: WriteProcessMemory worked!";
		} else {
			DWORD errorCode = GetLastError();
			std::cerr << "ERROR: Cannot write process memory! Error code: " << errorCode;
			return 1;
		}
		CloseHandle(hProcess);
	}

	return 0;
}

int Memory::WriteProcessMemorySA(HWND hWnd, LPVOID address, float newData) {
	DWORD processID;
	GetWindowThreadProcessId(hWnd, &processID);

	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);
	if(!hProcess) {
		DWORD errorCode = GetLastError();
		std::cerr << "ERROR: Could not open process! Error code: " << errorCode;
		return 1;
	} else {
		DWORD newDataSize = sizeof(newData);
		if(WriteProcessMemory(hProcess, address, &newData, newDataSize, NULL)) {
			std::cout << "INFO: WriteProcessMemory worked!";
		} else {
			DWORD errorCode = GetLastError();
			std::cerr << "ERROR: Cannot write process memory! Error code: " << errorCode;
			return 1;
		}
		CloseHandle(hProcess);
	}

	return 0;
}