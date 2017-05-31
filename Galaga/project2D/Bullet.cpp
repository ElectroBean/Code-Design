#include "Bullet.h"



Bullet::Bullet(const Vector3& a_pos, const float a_rotation, aie::Texture* const a_texture)
{
	Local = new Matrix3();
	Local->columns[2] = a_pos;
	Local->setRotateZ(a_rotation);
	Texture = a_texture;
	Global = new Matrix3(*Local);
	collCheck = new aabb(a_pos.x, a_pos.y, 7 / 2, 32 / 2);
	isVisible = false;
}

Bullet::~Bullet()
{
	delete Local;
	delete Global;
	//delete Texture;
	delete collCheck;
}

void Bullet::update(float deltaTime)
{
		*Global = *(Local);
	if (isVisible)
	{
		Local->position.y += 1000.0f * deltaTime;
		collCheck->x = Local->columns[2].x;
		collCheck->y = Local->columns[2].y;
		//ScreenWrap();
	}
}

void Bullet::Draw(aie::Renderer2D * a_Render)
{
	if (isVisible)
	{
		*Global = *Local;
		a_Render->drawSpriteTransformed3x3(Texture, (float*)Global, 7, 32);
		drawAABB(a_Render);
	}
}

void Bullet::SetRotation(const float a_rotation)
{
	Local->setRotateZ(a_rotation);
}

void Bullet::setPosition(Vector3 position)
{
	Local->columns[2] = position;
	collCheck->x = position.x;
	collCheck->y = position.y;
}

void Bullet::SetSpeed(const float a_speed)
{
	fSpeed = a_speed;
	//changed global to local to fix rotation of children
	V3Velocity = fSpeed * Local->columns[1];
}

void Bullet::ScreenWrap()
{
	if (Local->columns[2].x > 1080)
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

void Bullet::drawAABB(aie::Renderer2D* renderer)
{
	// LEFT
	renderer->drawLine(collCheck->x - collCheck->halfwidth, collCheck->y - collCheck->halfheight, collCheck->x - collCheck->halfwidth, collCheck->y + collCheck->halfheight);
	// collCheck
	renderer->drawLine(collCheck->x + collCheck->halfwidth, collCheck->y - collCheck->halfheight, collCheck->x + collCheck->halfwidth, collCheck->y + collCheck->halfheight);
	// TOP
	renderer->drawLine(collCheck->x - collCheck->halfwidth, collCheck->y + collCheck->halfheight, collCheck->x + collCheck->halfwidth, collCheck->y + collCheck->halfheight);
	// BOTTOM
	renderer->drawLine(collCheck->x - collCheck->halfwidth, collCheck->y - collCheck->halfheight, collCheck->x + collCheck->halfwidth, collCheck->y - collCheck->halfheight);
}