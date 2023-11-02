#pragma once
#include "SDL.h"

enum ControlsEvents
{
	W_PRESSED,
	S_PRESSED,
	UP_PRESSED,
	DOWN_PRESSED,
	LEFT_PRESSED,
	RIGHT_PRESSED,
	Y_PRESSED,
	Z_PRESSED,
	X_PRESSED,
	V_PRESSED,
	O_PRESSED,
	F_PRESSED,
	R_PRESSED,
	MINUS_PRESSED,
	PLUS_PRESSED,

	NUM_CONTROLS_EVENTS

};

class EventHandler
{
public:
	EventHandler();
	~EventHandler();

	static bool Update();

	static const int NUM_EVENTS = 10;

	static bool events[ControlsEvents::NUM_CONTROLS_EVENTS];

	static bool changeInMatrix;
private:

	static void SetButton(ControlsEvents eventNum, bool pressed);
};


