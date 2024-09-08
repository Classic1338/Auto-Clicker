#include "InClick.h"
#include "Menu.h"
#include "Utilities.h"

bool InClick::IsLButtonPressed() 
{
	return GetAsyncKeyState(0x05);
}

void InClick::ClickMouse(int x, int y)
{
	if (InClick::PlayingMC)
	{
		mouse_event(MOUSEEVENTF_RIGHTDOWN, x, y, 0, 0);//click the right button for block
		Utilities::Sleep(2);//sleep for 2 ms so it hopefully blocks an attack
		mouse_event(MOUSEEVENTF_RIGHTUP, x, y, 0, 0); //release the right buttons click
		Utilities::Sleep((1.f / 5.f * 1000) - 1); //hold off for this amount of time (5cps worth)
	}
	mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0); //left click to well click the mouse
	Utilities::Sleep(1);//sleep for 1ms to avoid any bugs involving the click not happening
	mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0); //release the left click so we can sleep the program 
	Utilities::Sleep(((1.f / (InClick::RageMode ? 300.f : InClick::LegitCPS)) * 1000) - 1); //sleep the program for x ms to achieve the autoclick
}

void InClick::Clicking()
{
	//get mouse position
	static int x, y; //we're gonna store the cursor pos on these
	POINT cursor;//we're gonna use this for GetCursorPos's argument
	GetCursorPos(&cursor);//set cursor to where ever the cursor is
	x = cursor.x; //set x to the cursors x pos
	y = cursor.y;//set y to the cursors y pos

	//click mouse
	ClickMouse(x, y);//we're parsing the x and y co-ords for the mouse pos so we're not just clicking in random places (which we would if we just did 0,0,0,0
					 //but instead we're clicking where ever the mouse is so instead we're clicking on a small button if that's it, but if its a game and they
					 //lock the cursor then this wont matter 
}