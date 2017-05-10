#include "Obect.h"



Object::Object(const Vector3& a_pos, const float a_rotation, aie::Texture* const a_texture)
{
	//identity matrix
	Local = new Matrix3();
	//set rotation of matrix
	Local->setRotateZ(a_rotation);
	//set direction (right, forward, position)
	V3Direction = (*Local)[1];
	//set position
	(*Local)[2] = a_pos;

	Texture = a_texture;

	Global = new Matrix3(*Local);
}


Object::~Object()
{
	delete Local;
	delete Global;
}

void Object::Update(const float deltaTime)
{
	if (fSpeed < 0)
	{
		fSpeed = 0;
	}

	aie::Input* input = aie::Input::getInstance();
	if (!parent)
	{
		ScreenWrap();
	}

	if (!parent)
	{
		Local->columns[2] = Local->columns[2] + (V3Velocity * deltaTime);
		*Global = *(Local);

		SetRotation(rotation);
		SetSpeed(fSpeed);
		//Global->columns[2] = Global->columns[2] + (V3Velocity * deltaTime);

		if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		{
			Local->columns[2].x -= (500.0f * deltaTime);
		}
		if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		{
			Local->columns[2].x += (500.0f * deltaTime);
		}
	}
}

void Object::Draw(aie::Renderer2D * a_Render)
{
	a_Render->drawSpriteTransformed3x3(Texture, (float*)Global, 93 / 2, 80 / 2);
}

void Object::SetSpeed(const float a_speed)
{
	fSpeed = a_speed;
	//                    changed global to local to fix rotation of children
	V3Velocity = fSpeed * Local->columns[1];
}

void Object::SetRotation(const float a_rotation)
{
	Local->setRotateZ(a_rotation);
	//V3Velocity = fSpeed * Local->columns[1];
}

void Object::SetParent(Object * a_parent)
{
	parent = a_parent;
	Local->columns[1] = a_parent->Global->columns[1];
}

void Object::ScreenWrap()
{
	if (Local->columns[2].x > 1280)
	{
		Local->columns[2].x = 0;
	}
	if (Local->columns[2].x < 0)
	{
		Local->columns[2].x = 1280;
	}
	if (Local->columns[2].y > 720)
	{
		Local->columns[2].y = 0;
	}
	if (Local->columns[2].y < 0)
	{
		Local->columns[2].y = 720;
	}
}
