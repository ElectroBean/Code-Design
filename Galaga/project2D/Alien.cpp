#include "Alien.h"



Alien::Alien(const Vector3& a_pos, const float a_rotation, aie::Texture* const a_texture)
{
	Local = new Matrix3();
	Local->setRotateZ(a_rotation);
	V3Direction = (*Local)[1];
	(*Local)[2] = a_pos;
	Texture = a_texture;
	Global = new Matrix3(*Local);
	m_bullet = new aie::Texture("./textures/laser.png");
	for (int i = 0; i < 100; i++)
	{
		mBullets[i] = new Bullet(Vector3(), 0, m_bullet);
	}
	collCheck = new aabb(Global->position.x, Global->position.y, 93 / 4, 80 / 4);
	moveTimer2 = 0.1f;
	isVisible = true;
	moveDelay = 0.5f;
}

Alien::~Alien()
{
	delete Local;
	delete Global;
	delete m_bullet;
	for (int i = 0; i < 100; i++)
	{
		delete mBullets[i];
	}
	delete collCheck;
	delete Texture;
}

void Alien::Move()
{
	if (movedDownTimer >= 2.0f)
	{
		movedDownTimer = 0.0f;
		Local->position.y -= 50;
		if (direction)
		{
			direction = false;
		}
		else if (!direction)
		{
			direction = true;
		}
	}
}

void Alien::Update(float deltaTime)
{
	*Global = *Local;
	interpolate(deltaTime);
	collCheck->y = Global->position.y;
	collCheck->x = Global->position.x;
	moveTimer -= deltaTime;
	movedDownTimer += deltaTime;
}

void Alien::Draw(aie::Renderer2D * a_Render)
{
	a_Render->drawSpriteTransformed3x3(Texture, (float*)Global, 93 / 2, 80 / 2);
	drawAABB(a_Render);
}

void Alien::drawAABB(aie::Renderer2D* renderer)
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

void Alien::interpolate(float deltaTime)
{
	moveTimer2 += 0.25f * deltaTime;
	if (moveTimer2 >= moveDelay)
	{
		if (direction)
		{
			Local->position.x += 25.0f;
			moveTimer2 = 0.0f;
		}
		else if (!direction)
		{
			Local->position.x -= 25.0f;
			moveTimer2 = 0.0f;
		}
	}
}

void Alien::die()
{
	isVisible = false;
	collCheck->x = 0;
	collCheck->y = 0;
}

void Alien::setMoveSpeed(float aMoveSpeed)
{
	moveDelay = aMoveSpeed;
}
