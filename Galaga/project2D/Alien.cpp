#include "Alien.h"

Alien::Alien()
{

}

Alien::Alien(const Vector3& a_pos, const float a_rotation, aie::Texture* const a_texture)
{
	Local = new Matrix3();
	Local->setRotateZ(a_rotation);
	V3Direction = (*Local)[1];
	(*Local)[2] = a_pos;
	Texture = a_texture;
	Global = new Matrix3(*Local);
	m_bullet = new aie::Texture("./textures/bullet.png");

	mBullet = new Bullet(Vector3(), 0, m_bullet);
	mBullet->setAlien(this);

	collCheck = new aabb(Global->position.x, Global->position.y, 32 / 2, 32 / 2);
	moveTimer2 = 0.1f;
	isVisible = true;
	moveDelay = 0.35f;
	sound1 = new aie::Audio("./audio/fastinvader3.wav");
	sound1->setGain(0.02f);
	sound2 = new aie::Audio("./audio/fastinvader2.wav");
	sound2->setGain(0.02f);
	sound3 = new aie::Audio("./audio/fastinvader1.wav");
	sound3->setGain(0.02f);
	sound4 = new aie::Audio("./audio/fastinvader4.wav");
	sound4->setGain(0.02f);
	moveNumber = 4;
}

Alien::~Alien()
{
	delete Local;
	delete Global;
	delete m_bullet;

	delete mBullet;

	delete collCheck;
	delete Texture;
	delete sound1;
	delete sound2;
	delete sound3;
	delete sound4;
}

void Alien::Move()
{
	if (movedDownTimer >= 1.5f)
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
	mBullet->update(deltaTime);

}

void Alien::Draw(aie::Renderer2D * a_Render)
{
	a_Render->drawSpriteTransformed3x3(Texture, (float*)Global, 32, 32);
	mBullet->Draw(a_Render);

	//drawAABB(a_Render);
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
			if (isVisible)
			{
				switch (moveNumber)
				{
				case 1:
				{
					sound1->play();
					moveNumber = 4;
					break;
				}
				case 2:
				{
					sound2->play();
					moveNumber--;
					break;
				}
				case 3:
				{
					sound3->play();
					moveNumber--;
					break;
				}
				case 4:
				{
					sound4->play();
					moveNumber--;
					break;
				}
				}
			}
		}
		else if (!direction)
		{
			Local->position.x -= 25.0f;
			moveTimer2 = 0.0f;
			if (isVisible)
			{
				switch (moveNumber)
				{
				case 1:
				{
					sound1->play();
					moveNumber = 4;
					break;
				}
				case 2:
				{
					sound2->play();
					moveNumber--;
					break;
				}
				case 3:
				{
					sound3->play();
					moveNumber--;
					break;
				}
				case 4:
				{
					sound4->play();
					moveNumber--;
					break;
				}
				}

			}
		}
	}
}

void Alien::die()
{
	isVisible = false;
	collCheck->x = 0;
	collCheck->y = 0;
}

void Alien::setDirection(bool a_setting)
{
	moveDelay = 0.35f;
	direction = a_setting;
}

void Alien::setMoveSpeed(float aMoveSpeed)
{
	moveDelay = aMoveSpeed;
}

void Alien::SetLocal(Vector3 a_position)
{
	Local->position = a_position;
}

void Alien::AlienShoot()
{
	if (this)
	{
		if (!mBullet->isVisible)
		{
			mBullet->setPosition(Local->position);
			mBullet->isVisible = true;
			ShootTimer = 0.0f;
			std::cout << "should shoot" << std::endl;
		}

	}
}


