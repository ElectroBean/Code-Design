#include "extraAlien.h"



extraAlien::extraAlien(const Vector3& a_pos)
{
	Local = new Matrix3();
	Local->position = a_pos;
	Global = new Matrix3(*Local);
	collCheck = new aabb(Global->position.x, Global->position.y, 32 / 2, 32 / 2);

	Texture = new aie::Texture("./textures/special.png");

	direction = true;
	isVisible = true;

	begin = Vector3(20, 700, 0);
	ending = Vector3(780, 700, 0);
}


extraAlien::~extraAlien()
{
	delete Texture;
	delete Local;
	delete Global;
	delete collCheck;
}

void extraAlien::Update(float deltaTime)
{
	moveTimer += 0.1 * deltaTime;
	*Global = *Local;

	if (direction)
	{
		Local->position = ending.Interpolate(begin, moveTimer);

	}
	else if (!direction)
	{
		Local->position = begin.Interpolate(ending, moveTimer);
	}

	if (Local->position.x >= 780)
	{
		direction = false;
		Local->position.x = 779;
		moveTimer = 0.0f;
	}
	if (Local->position.x <= 20)
	{
		direction = true;
		Local->position.x = 21;
		moveTimer = 0.0f;
	}
	
}

void extraAlien::draw(aie::Renderer2D* renderer)
{
	renderer->drawSpriteTransformed3x3(Texture, (float*)Global, 64, 64);
}