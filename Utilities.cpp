#include "Utilities.h"
#include <Windows.h>
#include <iostream>
#include <string>
#include <thread>

void Utilities::Sleep(int Ms) {
	std::this_thread::sleep_for(std::chrono::milliseconds(Ms)); //wrapper for sleep_for function as sleep_for is more accurate then Sleep
}