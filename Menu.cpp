#include "Menu.h"
#include "InClick.h"
#include <algorithm>

void Menu::ChangeCPS()
{
	if (GetAsyncKeyState(VK_F2) & 1) InClick::LegitCPS++; //increment the max cps count
	if (GetAsyncKeyState(VK_F1) & 1) InClick::LegitCPS--; //decrement the max cps count
	InClick::LegitCPS = std::clamp( InClick::LegitCPS, 1.f, 30.f); //clamp the max cps so it doesnt go above 30 or below 1
}

void Menu::ChooseGame()
{
	if (GetAsyncKeyState(VK_F3) & 1) 
		InClick::PlayingMC = !InClick::PlayingMC; //switch between playing mc or not
}

void Menu::MenuState()
{
	system("color a");
	std::cout << "Rage Mode: " << InClick::RageMode; //print the ragemode state
	std::cout << "\n";
	std::cout << "Legit CPS: " << InClick::LegitCPS; //print the legit cps count
	std::cout << "\n";
	std::cout << "Playing MC: " << InClick::PlayingMC; //print the game state
	std::cout << "\n";
}