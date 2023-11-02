#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//FALL 2022 - Graphics Programming 1 GAME300 Lab 4 - Collision of the pumpkins

// for loading sprites
#include "Utils.h"
#include "SDLHelper.h"

#define TINYOBJLOADER_IMPLEMENTATION

// processing events
#include "EventHandler.h"

#include "GamePlayManager.h"

#include "SDL.h"

// new OpenGL/GLEW headers:
#define GL3_PROTOTYPES 1
#include "glew.h"

#define WINDOW_WIDTH    800
#define WINDOW_HEIGHT   600

#define WIN32_LEAN_AND_MEAN 1
#include "windows.h"

// enable dedicated Graphics cards for AMD and NVidia
extern "C"
{
	_declspec(dllexport) DWORD NvOptimusEnablement = 1;
	_declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1;
}

// GameState
bool GameRunning = true;

bool Init(SDL_Window** mainWindow, SDL_Renderer** mainRenderer);

int main(int argc, char *argv[])
{
	srand(time(NULL));

	if (!SDLHelper::Init())
	{
		return false;
	}

	printf("OpenGL: %s\n", glGetString(GL_VERSION));
	printf("Graphics Card: %s - %s\n", glGetString(GL_VENDOR), glGetString(GL_RENDERER));

	// this will run for 1500ms before allowing input
	SDLHelper::DisplaySplashScreen();

	glEnable(GL_DEPTH_TEST);

	GamePlayManager::GetInstance()->InitGameplay();

	GameObject3D myObj;
	myObj.Init();

	// Main game loop
	while (GameRunning) 
	{
		// the order of everything within this loop is very important.
		// handle button events
		GameRunning = EventHandler::Update();

		// CLEAR THE SCREEN FIRST...
		glClearColor(0.0, 0.0, 0.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// PART 1:
		// 1a. set your matrix mode for dealing with the view
		glMatrixMode(GL_PROJECTION);
		// 1b. load up the identity matrix
		glLoadIdentity();
		// 1c. setup your view
		if (!Pumpkin::switchToOrthogonal)
		{
			glFrustum(-1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 100.0f);
		} 
		else
		{
			glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 100.0f);
		}
		// 1d. set the matrix mode
		glMatrixMode(GL_MODELVIEW);

		if (!Pumpkin::switchToWireframe)
		{
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		}
		else
		{
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		}

		GamePlayManager::GetInstance()->Update();

		SDL_GL_SwapWindow(SDLHelper::GetWindow());
	}

	SDL_Quit();
	return true;
}