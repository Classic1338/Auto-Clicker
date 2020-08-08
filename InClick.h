#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
#include <thread>

namespace InClick
{
	bool IsLButtonPressed( );
	void ClickMouse( int x, int y );
	void Clicking( );

	inline bool RageMode;
	inline float LegitCPS = 11;
	inline bool PlayingMC;
}
