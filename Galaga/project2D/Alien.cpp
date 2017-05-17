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
}

Alien::~Alien()
{
	delete Local;
	delete Global;
	delete m_bullet;
	delete mBullets;
	for (int i = 0; i < 100; i++)
	{
		delete mBullets[i];
	}
}

void Alien::Move(float deltaTime)
{
	float moveTimer = 5;
	moveTimer -= deltaTime;






	if (moveTimer <= 0)
	{
		Local->position.y -= 50;
		moveTimer = 5;
	}
}

void Alien::Update(float deltaTime)
{
	*Global = *Local;

}

void Alien::Draw(aie::Renderer2D * a_Render)
{
	a_Render->drawSpriteTransformed3x3(Texture, (float*)Global, 93 / 2, 80 / 2);
}