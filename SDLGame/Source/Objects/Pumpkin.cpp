#include "Pumpkin.h"
#include "../EventHandler.h"

bool Pumpkin::switchToOrthogonal = false;
bool Pumpkin::switchToWireframe = false;

Pumpkin::Pumpkin()
{
}

Pumpkin::~Pumpkin()
{
}

void Pumpkin::Init(string modelFile)
{
	transform.position.z = 4.0f;
	transform.position.y = -1.0f;

	transform.scale.x = 1.0f;
	transform.scale.y = 1.0f;
	transform.scale.z = 1.0f;

	dimensions.x = 1.0;	// width
	dimensions.y = 1.0;	// height
	dimensions.z = 1.0;	// length

	ObjModel::Init(modelFile);
}

// this is used to process individual vertices for your model
void Pumpkin::ProcessVertice(int shapeId, float vx, float vy, float vz, float r, float g, float b)
{

	if (shapeId == CORE)
	{
		glMaterialfv(GL_FRONT, GL_DIFFUSE, pumpkinColor);
		glColor3f(0.8f, 0.5f, 0.3f);
	}
	else
	{
		glMaterialfv(GL_FRONT, GL_DIFFUSE, stemColor);
		glColor3f(0.3f, 0.9f, 0.7f);
	}

	ObjModel::ProcessVertice(shapeId, vx, vy, vz, r, g, b);
}

void Pumpkin::Update()
{
	// Part 2: object update code in here:
	// 2) Complete all directions to display the pumpkin in all translation movements (XYZ)(+ & -)
		// hint: this will require modifying the eventhandler to allow for more input
	// 3) rotate the pumpkin in all 3 directions XYZ (+ & -)
	// 4) scale the pumpkin in all directions equally down by half using a button press of your choosing

	// Translation in X, Y, and Z axis (+ and -)
	if (EventHandler::events[ControlsEvents::W_PRESSED])
	{
		transform.position.z -= 1.0f;
	}
	if (EventHandler::events[ControlsEvents::S_PRESSED])
	{
		transform.position.z += 1.0f;
	}
	if (EventHandler::events[ControlsEvents::UP_PRESSED])
	{
		transform.position.y += 1.0f;
	}
	if (EventHandler::events[ControlsEvents::DOWN_PRESSED])
	{
		transform.position.y -= 1.0f;
	}
	if (EventHandler::events[ControlsEvents::LEFT_PRESSED])
	{
		transform.position.x -= 1.0f;
	}
	if (EventHandler::events[ControlsEvents::RIGHT_PRESSED])
	{
		transform.position.x += 1.0f;
	}

	// Rotation in X, Y, and Z axis (+ and -)
	// Press V then X/Y/Z to - rotate
	// Press X/Y/Z only to + rotate
	if (EventHandler::events[ControlsEvents::V_PRESSED])
	{
		if (EventHandler::events[ControlsEvents::X_PRESSED])
		{
			transform.rotation.x -= 5.0f;
		}
		if (EventHandler::events[ControlsEvents::Y_PRESSED])
		{
			transform.rotation.y -= 5.0f;
		}
		if (EventHandler::events[ControlsEvents::Z_PRESSED])
		{
			transform.rotation.z -= 5.0f;
		}
	}
	else
	{
		if (EventHandler::events[ControlsEvents::X_PRESSED])
		{
			transform.rotation.x += 5.0f;
		}
		if (EventHandler::events[ControlsEvents::Y_PRESSED])
		{
			transform.rotation.y += 5.0f;
		}
		if (EventHandler::events[ControlsEvents::Z_PRESSED])
		{
			transform.rotation.z += 5.0f;
		}
	}

	// Scaling uniformly in all axis by half and double
	if (EventHandler::events[ControlsEvents::MINUS_PRESSED])
	{
		transform.scale.x = 0.5f;
		transform.scale.y = 0.5f;
		transform.scale.z = 0.5f;
	}
	if (EventHandler::events[ControlsEvents::PLUS_PRESSED])
	{
		transform.scale.x = 2.0f;
		transform.scale.y = 2.0f;
		transform.scale.z = 2.0f;
	}

	// Switch to orthogonal view or wireframe view
	if (EventHandler::events[ControlsEvents::O_PRESSED])
	{
		Pumpkin::switchToOrthogonal = !Pumpkin::switchToOrthogonal;
	}
	if (EventHandler::events[ControlsEvents::F_PRESSED])
	{
		Pumpkin::switchToWireframe = !Pumpkin::switchToWireframe;
	}

	// P
	if (EventHandler::events[ControlsEvents::R_PRESSED])
	{
		transform.position.x = 0.0f;
		transform.position.y = -1.0f;
		transform.position.z = 4.0f;

		transform.rotation.x = 0.0f;
		transform.rotation.y = 0.0f;
		transform.rotation.z = 0.0f;

		transform.scale.x = 1.0f;
		transform.scale.y = 1.0f;
		transform.scale.z = 1.0f;
	}

	ObjModel::Update();
}
