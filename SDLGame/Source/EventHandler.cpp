#include "EventHandler.h"
#include <stdio.h>
#include <string.h>

bool EventHandler::events[];
bool EventHandler::changeInMatrix = true;

EventHandler::EventHandler()
{
}

EventHandler::~EventHandler()
{
}

bool EventHandler::Update()
{
	bool success = true;

	SDL_Event currEvents;
	// Check for events
	while (SDL_PollEvent(&currEvents))
	{
		switch (currEvents.key.keysym.sym)
		{
			case SDLK_w:
			{
				SetButton(ControlsEvents::W_PRESSED, currEvents.key.type == SDL_KEYDOWN);
				break;
			}
			case SDLK_s:
			{
				SetButton(ControlsEvents::S_PRESSED, currEvents.key.type == SDL_KEYDOWN);
				break;
			}
			case SDLK_UP:
			{
				SetButton(ControlsEvents::UP_PRESSED, currEvents.key.type == SDL_KEYDOWN);
				break;
			}
			case SDLK_DOWN:
			{
				SetButton(ControlsEvents::DOWN_PRESSED, currEvents.key.type == SDL_KEYDOWN);
				break;
			}
			case SDLK_LEFT:
			{
				SetButton(ControlsEvents::LEFT_PRESSED, currEvents.key.type == SDL_KEYDOWN);
				break;
			}
			case SDLK_RIGHT:
			{
				SetButton(ControlsEvents::RIGHT_PRESSED, currEvents.key.type == SDL_KEYDOWN);
				break;
			}
			case SDLK_y:
			{
				SetButton(ControlsEvents::Y_PRESSED, currEvents.key.type == SDL_KEYDOWN);
				break;
			}
			case SDLK_x:
			{
				SetButton(ControlsEvents::X_PRESSED, currEvents.key.type == SDL_KEYDOWN);
				break;
			}
			case SDLK_z:
			{
				SetButton(ControlsEvents::Z_PRESSED, currEvents.key.type == SDL_KEYDOWN);
				break;
			}
			case SDLK_v:
			{
				SetButton(ControlsEvents::V_PRESSED, currEvents.key.type == SDL_KEYDOWN);
				break;
			}
			case SDLK_o:
			{
				SetButton(ControlsEvents::O_PRESSED, currEvents.key.type == SDL_KEYDOWN);
				break;
			}
			case SDLK_f:
			{
				SetButton(ControlsEvents::F_PRESSED, currEvents.key.type == SDL_KEYDOWN);
				break;
			}
			case SDLK_r:
			{
				SetButton(ControlsEvents::R_PRESSED, currEvents.key.type == SDL_KEYDOWN);
				break;
			}
			case SDLK_MINUS:
			{
				SetButton(ControlsEvents::MINUS_PRESSED, currEvents.key.type == SDL_KEYDOWN);
				break;
			}
			case SDLK_EQUALS:
			{
				SetButton(ControlsEvents::PLUS_PRESSED, currEvents.key.type == SDL_KEYDOWN);
				break;
			}
		}
	}	
	return success;
}

void EventHandler::SetButton(ControlsEvents eventNum, bool pressed)
{
	events[eventNum] = pressed;
	EventHandler::changeInMatrix = true;
}
