#include "LightManager.h"

LightManager* LightManager::instance = nullptr;


LightManager::LightManager()
{
}


LightManager::~LightManager()
{
}

void LightManager::SetupSimpleLighting()
{
	glLightModeli(GL_LIGHT_MODEL_AMBIENT, 1);

	glLightfv(GL_LIGHT0, GL_DIFFUSE, ambientLightColor);
	glLightfv(GL_LIGHT0, GL_AMBIENT, diffuseLightColor);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLightColor);

	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.5);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.02);

	glEnable(GL_LIGHT0);

	glLightfv(GL_LIGHT1, GL_DIFFUSE, ambientLightColor2);
	glLightfv(GL_LIGHT1, GL_AMBIENT, diffuseLightColor2);
	glLightfv(GL_LIGHT1, GL_SPECULAR, specularLightColor2);

	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 0.25);
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.025);

	glEnable(GL_LIGHT1);

	glEnable(GL_LIGHTING);

}

void LightManager::ApplyLighting()
{
	GLfloat lightPosition[] = { 0.0, 0.0, 1.0, 0.0 };
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	static GLfloat lightDirection[] = { 0.0f,0.0f,0.01f,0.01f };

	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, lightDirection);
	
	GLfloat lightPosition2[] = { 10.0, 10.0, 10.0, 1.0 };
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	static GLfloat lightDirection2[] = { 1.0f,0.0f,0.08f,0.05f };

	glLightfv(GL_LIGHT1, GL_POSITION, lightPosition2);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, lightDirection2);
}