#include "Alien.h"



Alien::Alien(const Vector3& a_pos, const float a_rotation, aie::Texture* const a_texture, Vector3 start, Vector3 end)
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
	moveTimer = 9.0f;
	begin = start;
	ending = end;
	moveTimer2 = 0.1f;
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
}

void Alien::Move(float deltaTime)
{
	if (moveTimer <= 0)
	{
		Local->position.y -= 50;
		moveTimer = 9;
		std::cout << "it should've worked" << std::endl;
	}
}

void Alien::Update(float deltaTime)
{
	*Global = *Local;
	interpolate(deltaTime);
	collCheck->y = Global->position.y;
	collCheck->x = Global->position.x;
	moveTimer -= deltaTime;
	Move(deltaTime);
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
	moveTimer2 += 0.1f * deltaTime;
	begin = Vector3(80, Local->position.y, 0);
	ending = Vector3(1000, Local->position.y, 0);

	if (Local->position.x <= 80)
	{
		direction = true;
		moveTimer2 = 0.1f;
	}
	else if (Local->position.x >= 1000)
	{
		direction = false;
		moveTimer2 = 0.1f;
	}
	if (direction)
	{
		Local->position = begin.Interpolate(Vector3(1000, Global->position.y, 0), moveTimer2);
	}
	else if (!direction)
	{
		Local->position = ending.Interpolate(Vector3(80, Global->position.y, 0), moveTimer2);
	}
}