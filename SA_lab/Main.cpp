#include <iostream>
#include <windows.h>
#include <locale>

#include "Memory.h"

int main(int argc, char* argv[]) {
	Memory memoryHandler;
	
	std::cout << "MEMORY ADDRESS: ";
	int inputAddress;
	std::cin >> std::hex >> inputAddress;
	
	char userCommand;
	std::cout << "R/W? ";
	std::cin >> userCommand;

	char variableType;
	std::cout << "Type (i = DWORD, b = byte, f = float): ";
	std::cin >> variableType;
	
	HWND hWnd = FindWindow(0, "GTA: San Andreas");
	if (hWnd == 0) {
		std::cerr << "ERROR: GTA:SA Process not found.";
		std::cout << "Please check the name of your GTA:SA process! The name: ";
		std::string processName;
		std::cin >> processName;
		hWnd = FindWindow(0, processName.c_str());
	}

	if(std::tolower(userCommand, std::locale()) == 'r') {
		memoryHandler.ReadProcessMemorySA(hWnd, (LPVOID)inputAddress);
	} else {
		std::string numBuffer;
		std::cout << "Value: ";
		std::cin >> numBuffer;
		
		if(variableType == 'i') {
			memoryHandler.WriteProcessMemorySA(hWnd, (LPVOID)inputAddress, std::strtoul(numBuffer.c_str(), 0, 10));
		} else if(variableType == 'b') {
			memoryHandler.WriteProcessMemorySA(hWnd, (LPVOID)inputAddress, (byte)numBuffer.c_str());
		} else {
			memoryHandler.WriteProcessMemorySA(hWnd, (LPVOID)inputAddress, std::stof(numBuffer.c_str()));
		}
	}

	return 0;
}
