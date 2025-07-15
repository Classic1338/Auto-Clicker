#include <iostream>
#include "InClick.h"
#include "Menu.h"
#include "Utilities.h"

void HandleClicks()
{
	while (true)
	{
		if (InClick::IsLButtonPressed())
			InClick::Clicking(); //if button is clicked then do the autoclicker
		else
			Utilities::Sleep(50); //else sleep thread

		if (GetAsyncKeyState(VK_DELETE) & 1)
			exit( EXIT_SUCCESS ); //close the program (incase of emergency)
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
			oldTripwireAuto  != InClick::bTripwireAutomation) {

			OldRageModeState = InClick::RageMode;	 //update old ragemode state for on and off updating
			OldLegitCount	 = InClick::LegitCPS;	 //update old legitcps state for counting update
			OldMCState		 = InClick::PlayingMC;	 //update old mc state for on and off updating
			oldRightClick	 = InClick::bRightClick; //update old right click for on and off updating
			oldChestMode     = InClick::bChestAnnoyance; //update old chest mode for on and off updating
			oldSpaceKey      = InClick::bSpaceKey;		 //update old space key check for on and off updating
			oldTripwireAuto = InClick::bTripwireAutomation; //update old tripwire automation check for on and off updating

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