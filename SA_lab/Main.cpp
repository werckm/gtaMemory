#include <iostream>
#include <windows.h>
#include <locale>

#include "Memory.h"

int main(int argc, char* argv[]) {
	Memory memoryHandler;
	
	HWND hWnd = FindWindow(0, "GTA: San Andreas");
	if(hWnd == 0) {
		DWORD errorCode = GetLastError();
		std::cerr << "ERROR: GTA:SA Process not found. Error code: " << errorCode;
		std::cout << "Please check the name of your GTA:SA process! The name: ";
		std::string processName;
		std::cin >> processName;
		hWnd = FindWindow(0, processName.c_str());
	}

	if(argc == 1) {
		std::cout << "MEMORY ADDRESS: ";
		int inputAddress;
		std::cin >> std::hex >> inputAddress;

		char userCommand;
		std::cout << "R/W? ";
		std::cin >> userCommand;

		char variableType;
		std::cout << "Type (i = DWORD, b = byte, f = float): ";
		std::cin >> variableType;

		if(std::tolower(userCommand, std::locale()) == 'r') {
			memoryHandler.ReadProcessMemorySA(hWnd, (LPVOID)inputAddress);
		} else {
			std::string numBuffer;
			std::cout << "Value: ";
			std::cin >> numBuffer;

			if(variableType == 'i') {
				if(memoryHandler.WriteProcessMemorySA(hWnd, (LPVOID)inputAddress, std::strtoul(numBuffer.c_str(), 0, 10)) == 1);
			} else if(variableType == 'b') {
				memoryHandler.WriteProcessMemorySA(hWnd, (LPVOID)inputAddress, (byte)numBuffer.c_str());
			} else {
				memoryHandler.WriteProcessMemorySA(hWnd, (LPVOID)inputAddress, std::stof(numBuffer.c_str()));
			}
		}
	} else {
		if(argv[2][0] == 'i') {
			memoryHandler.WriteProcessMemorySA(hWnd, (LPVOID)std::strtol(argv[1], 0, 16), std::strtoul(argv[3], 0, 10));
		} else if(argv[2][0] == 'b') {
			memoryHandler.WriteProcessMemorySA(hWnd, (LPVOID)std::strtol(argv[1], 0, 16), (byte)argv[3]);
		} else {
			memoryHandler.WriteProcessMemorySA(hWnd, (LPVOID)std::strtol(argv[1], 0, 16), std::stof(argv[3]));
		}
	}

	return 0;
}
