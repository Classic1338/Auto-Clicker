#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
#include <thread>

namespace InClick
{
	bool IsLButtonPressed( );
	void AntiAFK(int x, int y);
	void TripwireAutomation( int x, int y );
	void ChestAnnoyance( int x, int y );
	void SpaceBar( );
	void ClickMouse( int x, int y );
	void Clicking( );
	void ClooneyMode(int x, int y);

	inline bool RageMode;
	inline float LegitCPS = 11;
	inline bool PlayingMC;
	inline bool bRightClick = false;
	inline bool bChestAnnoyance = false;
	inline bool bSpaceKey = false;
	inline bool bTripwireAutomation = false;
	inline bool bClooneyMode = false;
	inline bool bAntiAFK = false;
}
