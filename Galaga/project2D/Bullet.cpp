#include "Bullet.h"



Bullet::Bullet(const Vector3& a_pos, const float a_rotation, aie::Texture* const a_texture)
{
	Local = new Matrix3();
	Local->columns[2] = a_pos;
	Local->setRotateZ(a_rotation);
	Texture = a_texture;
	Global = new Matrix3(*Local);
}

Bullet::~Bullet()
{
}

void Bullet::update(float deltaTime)
{
	Local->columns[2].y += 1000.0f * deltaTime;
	*Global = *(Local);
	ScreenWrap();
}

void Bullet::Draw(aie::Renderer2D * a_Render)
{
	a_Render->drawSpriteTransformed3x3(Texture, (float*)Global, 93 / 2, 80 / 2);
}

void Bullet::SetRotation(const float a_rotation)
{
	Local->setRotateZ(a_rotation);
	//V3Velocity = fSpeed * Local->columns[1];
}

void Bullet::setPosition(Vector3 position)
{
	Local->columns[2] = position;
}

void Bullet::SetSpeed(const float a_speed)
{
	fSpeed = a_speed;
	//                    changed global to local to fix rotation of children
	V3Velocity = fSpeed * Local->columns[1];
}

void Bullet::ScreenWrap()
{
	if (Local->columns[2].x > 1280)
	{
		isVisible = false;
	}
	if (Local->columns[2].x < 0)
	{
		isVisible = false;
	}
	if (Local->columns[2].y > 720)
	{
		isVisible = false;
	}
	if (Local->columns[2].y < 0)
	{
		isVisible = false;
	}
}