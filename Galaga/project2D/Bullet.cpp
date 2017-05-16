#include "Bullet.h"



Bullet::Bullet(const Vector3& a_pos, const float a_rotation, aie::Texture* const a_texture)
{
	Local = new Matrix3();
	Local->columns[2] = a_pos;
	Local->setRotateZ(a_rotation);
	Texture = a_texture;
	Global = new Matrix3(*Local);
	collCheck = new aabb(a_pos.x, a_pos.y, 32 / 2, 32 / 2);
}

Bullet::~Bullet()
{
}

void Bullet::update(float deltaTime)
{
	Local->columns[2].y += 1500.0f * deltaTime;
	*Global = *(Local);
	ScreenWrap();
	collCheck->x = Local->columns[2].x;
	collCheck->y = Local->columns[2].y;
}

void Bullet::Draw(aie::Renderer2D * a_Render)
{
	a_Render->drawSpriteTransformed3x3(Texture, (float*)Global, 93 / 2, 80 / 2);
	drawAABB(a_Render);
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