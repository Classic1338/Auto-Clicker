#include "Menu.h"
#include "InClick.h"
#include <algorithm>

void Menu::ChangeCPS()
{
	if (GetAsyncKeyState(VK_F2) & 1) InClick::LegitCPS++; //increment the max cps count
	if (GetAsyncKeyState(VK_F1) & 1) InClick::LegitCPS--; //decrement the max cps count
	InClick::LegitCPS = std::clamp( InClick::LegitCPS, 1.f, 30.f); //clamp the max cps so it doesnt go above 30 or below 1
}

void Menu::Settings()
{
	if (GetAsyncKeyState(VK_INSERT) & 1)
		InClick::RageMode = !InClick::RageMode; //switch between rage mode

	if (GetAsyncKeyState(VK_F3) & 1)
		InClick::bRightClick = !InClick::bRightClick;

	if (GetAsyncKeyState(VK_F4) & 1) 
		InClick::PlayingMC = !InClick::PlayingMC; //switch between playing mc or not

	if (GetAsyncKeyState(VK_F5) & 1)
		InClick::bChestAnnoyance = !InClick::bChestAnnoyance;

	if (GetAsyncKeyState(VK_F6) & 1)
		InClick::bSpaceKey = !InClick::bSpaceKey;

	if (GetAsyncKeyState(VK_F7) & 1)
		InClick::bTripwireAutomation = !InClick::bTripwireAutomation;
}

std::string Menu::FromIntToText(bool& bVariable) {
	return bVariable ? "Enabled" : "Disabled";
}

void Menu::MenuState()
{
	system("color a");
	std::cout << "Rage Mode: " << FromIntToText(InClick::RageMode); //print the ragemode state
	std::cout << "\n";
	std::cout << "Legit CPS: " << InClick::LegitCPS; //print the legit cps count
	std::cout << "\n";
	std::cout << "Right Click: " << FromIntToText(InClick::bRightClick); //print the game state
	std::cout << "\n";
	std::cout << "Playing MC: " << FromIntToText(InClick::PlayingMC); //print the game state
	std::cout << "\n";
	std::cout << "Chest Annoyance: " << FromIntToText(InClick::bChestAnnoyance); //print the game state
	std::cout << "\n";
	std::cout << "Press Space Key: " << FromIntToText(InClick::bSpaceKey); //print the game state
	std::cout << "\n";
	std::cout << "Automate Tripwire: " << FromIntToText(InClick::bTripwireAutomation); //print the game state
}