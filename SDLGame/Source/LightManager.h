#pragma once

// new OpenGL/GLEW headers:
#define GL3_PROTOTYPES 1
#include "glew.h"

class LightManager
{
public:
	static LightManager* GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new LightManager();
		}
		return instance;
	}

	void SetupSimpleLighting();
	void ApplyLighting();

private:

	LightManager();
	~LightManager();

	GLfloat ambientLightColor[4] = { 0.25f, 0.1f, 0.052f, 1.0f };
	GLfloat diffuseLightColor[4] = { 0.25f, 0.25f, 0.25f, 1.0f };
	GLfloat specularLightColor[4] = { 0.25f,0.125f, 0.0f, 1.0f };

	GLfloat ambientLightColor2[4] = { 1.0f, 0.7f, 0.3f, 1.0f };
	GLfloat diffuseLightColor2[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat specularLightColor2[4] = { 1.0f,0.5f, 0.0f, 1.0f };

	static LightManager* instance;
};

