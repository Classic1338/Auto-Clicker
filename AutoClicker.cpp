#include <iostream>
#include "InClick.h"
#include "Menu.h"
#include "Utilities.h"
#include <Windows.h>
#include <stdexcept>
#include <vector>
#include <complex>
#include <string_view>
#include <Psapi.h>
#include <TlHelp32.h>
#include <string>
#include <format>

HWND McHWND;
BOOL CALLBACK FindMC(HWND hwnd, LPARAM lParam)
{
	char classname[256];
	GetClassName(hwnd, classname, 256);
	//if you know the class name check with this.
	if (strcmp(classname, "GLFW30") == 0)
	{
		McHWND = hwnd;
		return FALSE;
	}
	//now get the caption
	//char caption[256];
	//GetWindowText(hwnd, caption, 256);
	////now do find substring "Notepad"
	//char* found = strstr(caption, "minecraft");
	//if (!found)
	//{
	//	//yes this is our notepad window
	//	//CAUTION:this MIGHT be our window, check if you have any other parameters you know.
	//	//save the HWND to the global variable
	//	McHWND = hwnd;
	//	return FALSE;
	//}
	return TRUE;
}


void HandleClicks()
{
	bool oldRightClick = InClick::bConstantlyRightClick;
	bool hasReleasedClick = false;
	BOOL bWorked = EnumChildWindows(NULL, (WNDENUMPROC)FindMC, NULL);

	while (true)
	{
		if (GetAsyncKeyState(VK_DELETE) & 1)
			exit(EXIT_SUCCESS); //close the program (incase of emergency)

		static int x, y; //we're gonna store the cursor pos on these
		POINT cursor;//we're gonna use this for GetCursorPos's argument
		GetCursorPos(&cursor);//set cursor to where ever the cursor is
		x = cursor.x; //set x to the cursors x pos
		y = cursor.y;//set y to the cursors y pos

		if (InClick::PlayingMC && GetForegroundWindow() != McHWND) {
			if (InClick::bConstantlyRightClick && !hasReleasedClick) {
				mouse_event(MOUSEEVENTF_RIGHTUP, x, y, 0, 0);
				hasReleasedClick = true;
			}
			continue;
		}

		hasReleasedClick = false;

		if (InClick::bConstantlyRightClick) {
			mouse_event(MOUSEEVENTF_RIGHTDOWN, x, y, 0, 0); //left click to well click the mouse
		}

		if (oldRightClick != InClick::bConstantlyRightClick) {
			oldRightClick = InClick::bConstantlyRightClick;
			mouse_event(MOUSEEVENTF_RIGHTUP, x, y, 0, 0); //release the left click so we can sleep the program 
			Utilities::Sleep((1.f / 30.f * 1000) - 1); //sleep the program for x ms to achieve the autoclick
		}

		if (InClick::bAntiAFK) {
			InClick::AntiAFK(x, y);
		}

		if (InClick::IsLButtonPressed())
			InClick::Clicking(); //if button is clicked then do the autoclicker
		else
			Utilities::Sleep(50); //else sleep thread
	}
}

void HandleConsole()
{
	bool OldRageModeState = InClick::RageMode;
	bool OldMCState = InClick::PlayingMC;
	float OldLegitCount = InClick::LegitCPS;
	bool oldRightClick = InClick::bRightClick;
	bool oldChestMode = InClick::bChestAnnoyance;
	bool oldSpaceKey = InClick::bSpaceKey;
	bool oldTripwireAuto = InClick::bTripwireAutomation;
	bool oldClooneyMode = InClick::bClooneyMode;
	bool oldAntiAFK = InClick::bAntiAFK;
	bool oldConstantlyRightClick = InClick::bConstantlyRightClick;
	system("TITLE Classic1337#1324 AutoClicker"); //sets the console little to whatever is after TITLE
	Menu::MenuState(); //can call here as code here is called once only
	while (true) //keep the program open until we close it
	{
		Menu::ChangeCPS(); //called so we can change the CP/s
		Menu::Settings(); //called so we can choose if we're on mc or not (maybe make more bypasses for more games)
		if (OldRageModeState != InClick::RageMode || //check if the oldvalue doesnt equal the new value
			OldLegitCount    != InClick::LegitCPS ||
			OldMCState       != InClick::PlayingMC ||
			oldRightClick	 != InClick::bRightClick ||
			oldChestMode	 != InClick::bChestAnnoyance ||
			oldSpaceKey		 != InClick::bSpaceKey ||
			oldTripwireAuto  != InClick::bTripwireAutomation ||
			oldClooneyMode   != InClick::bClooneyMode ||
			oldAntiAFK		 != InClick::bAntiAFK ||
			oldConstantlyRightClick != InClick::bConstantlyRightClick) {

			OldRageModeState = InClick::RageMode;	 //update old ragemode state for on and off updating
			OldLegitCount	 = InClick::LegitCPS;	 //update old legitcps state for counting update
			OldMCState		 = InClick::PlayingMC;	 //update old mc state for on and off updating
			oldRightClick	 = InClick::bRightClick; //update old right click for on and off updating
			oldChestMode     = InClick::bChestAnnoyance; //update old chest mode for on and off updating
			oldSpaceKey      = InClick::bSpaceKey;		 //update old space key check for on and off updating
			oldTripwireAuto  = InClick::bTripwireAutomation; //update old tripwire automation check for on and off updating
			oldClooneyMode   = InClick::bClooneyMode;
			oldAntiAFK		 = InClick::bAntiAFK;
			oldConstantlyRightClick = InClick::bConstantlyRightClick;

			system("cls");//clears console so we can update the menu yet again
			Menu::MenuState();//call menustate again to reshow menu
		}
		Sleep(50);
	}
}

int main()
{
	HANDLE ThreadHandle = CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(HandleConsole), nullptr, 0, nullptr); //create a handle to open a new thread for handling the console
	CloseHandle(ThreadHandle); //closing the handle to avoid a memory leak
	HandleClicks(); //handle clicks using the main thread 
	return EXIT_SUCCESS;
}

/* NOTE:
	This program is OPEN SOURCE if you're selling it. you're scum of the earth, other then that, please
	do not judge the code too harshly, I was bored of making my usual stuff and decided to make an auto-
	clicker, it was a fun journey but in the end it doesnt really appeal to me anymore, the 
	InClick::PlayingMC was a W.I.P thing to see if I could get it so it could block attack (1.8)
	but it never worked and just made me click slower. other then this setback the tool is pretty
	good at clicking fast, i mostly just use it on MW2 campaign as it's alot of fun. Also, if you're
	an employeer looking at my GitHub and saw this. for a start. Hi :) and secondly, this is mostly
	to expand my familiarity with the Windows API. Well to anyone who's using this for their own 
	personal use, I'd like to say thank you, perhaps like star/watch the github to show you like
	it, Enjoy!
*/