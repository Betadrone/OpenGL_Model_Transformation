#include "GamePlayManager.h"
#include <iostream>

GamePlayManager* GamePlayManager::instance = nullptr;

void printMVMatrix()
{
	GLfloat currentMatrix[16];
	glGetFloatv(GL_MODELVIEW_MATRIX, &currentMatrix[0]);

	for (int i = 0; i < 4; i++)
	{
		cout << currentMatrix[i] << "\t";
		cout << currentMatrix[i + 4] << "\t";
		cout << currentMatrix[i + 8] << "\t";
		cout << currentMatrix[i + 12] << "\t";
		cout << endl;
	}
	cout << endl;
}

GamePlayManager::GamePlayManager()
{

}


GamePlayManager::~GamePlayManager()
{
}

void GamePlayManager::InitGameplay()
{
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_CULL_FACE); // uncomment this to make the backfaces not render

	LightManager::GetInstance()->SetupSimpleLighting();

	pumpkin.Init("Data\\Art\\single_pumpkin.obj");
	walls.Init(20.0f);

}


void GamePlayManager::Update()
{
	    LightManager::GetInstance()->ApplyLighting();

		if (EventHandler::changeInMatrix)
		{
			system("cls");
			printMVMatrix();
		}

		walls.Update();
		walls.Draw();

		glPushMatrix();
			pumpkin.Update();
			pumpkin.Draw();
			if (EventHandler::changeInMatrix)
			{
				printMVMatrix();
				EventHandler::changeInMatrix = false;
			}
		glPopMatrix();
}

