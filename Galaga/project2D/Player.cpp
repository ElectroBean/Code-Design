#include "Player.h"


Object::Object()
{
	//identity matrix
	Local = new Matrix3();
	//set rotation of matrix
	Local->setRotateZ(0);
	//set direction (right, forward, position)
	V3Direction = (*Local)[1];
	//set position
	(*Local)[2] = Vector3();

	playerTexture = new aie::Texture();

	Global = new Matrix3(*Local);
	fHealth = 100.0f;
	m_bullet = new aie::Texture("./textures/laser.png");

	for (int i = 0; i < 100; i++)
	{
		mBullets[i] = new Bullet(Vector3(), 0, m_bullet);
	}
	collCheck = new aabb(Global->position.x, Global->position.y, 93 / 2, 80 / 2);
	m_audio = new aie::Audio("./audio/shootiesound - dklon.wav");
}

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

	playerTexture = a_texture;

	Global = new Matrix3(*Local);

	float fHealth = 100.0f;

	m_bullet = new aie::Texture("./textures/laser.png");

	for (int i = 0; i < 100; i++)
	{
		mBullets[i] = new Bullet(Vector3(), 0, m_bullet);
	}
	collCheck = new aabb(Global->position.x, Global->position.y, 93 / 5, 80 / 5);
	m_audio = new aie::Audio("./audio/shootiesound - dklon.wav");
}


Object::~Object()
{
	delete Local;
	delete Global;
	delete m_bullet;
	for (int i = 0; i < 100; i++)
	{
		delete mBullets[i];
	}
	delete collCheck;
	delete playerTexture;
	delete m_audio;
}

void Object::Update(const float deltaTime)
{
	shootTimer -= deltaTime;
	/*
	goes through bullet array
	updates all that are visible
	*/
	for (int i = 0; i < 100; i++)
	{
		if (mBullets[i]->isVisible)
		{
			mBullets[i]->update(deltaTime);
		}
	}
	if (fSpeed < 0)
	{
		fSpeed = 0;
	}

	aie::Input* input = aie::Input::getInstance();

	ScreenWrap();



	*Global = *(Local);
	SetRotation(rotation);

	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
	{
		Local->columns[2].x -= (500.0f * deltaTime);
	}
	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
	{
		Local->columns[2].x += (500.0f * deltaTime);
	}
	if (input->isKeyDown(aie::INPUT_KEY_SPACE))
	{
		shooting = true;
	}
	if (input->isKeyUp(aie::INPUT_KEY_SPACE))
	{
		shooting = false;
	}

	if (shooting && shootTimer <= 0)
	{
		ShootBullet();
		shootTimer += 0.5f;
	}
	if (shootTimer < 0)
	{
		shootTimer = 0;
	}

	// Updates collision box position/////
	collCheck->x = Global->position.x;
	collCheck->y = Global->position.y;
	//////////////////////////////////////
}

void Object::Draw(aie::Renderer2D * a_Render)
{
	/*
	goes through bullet array
	checks for visible bullets and draws them
	*/
	for (int i = 0; i < 100; i++)
	{
		if (mBullets[i]->isVisible)
		{
			mBullets[i]->Draw(a_Render);
		}
	}
	a_Render->drawSpriteTransformed3x3(playerTexture, (float*)Global, 93 / 2, 80 / 2);
	//a_Render->drawLine(Local->position.x, Local->position.y, Local->position.x, 720, 1);
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

//clamps the players position to stay inside the screen width
void Object::ScreenWrap()
{
	if (Local->position.x >= 800)
	{
		Local->position.x = 799;
	}
	if (Local->position.x <= 0)
	{
		Local->position.x = 1;
	}
}

void Object::takeDamage(int aDamage)
{
	fHealth -= aDamage;
}

void Object::ShootBullet()
{
	for (int i = 0; i < 100; i++)
	{
		/*
		if there is already a bullet visible
		breaks out of for loop so another isn't shot
		*/
		if (mBullets[i]->isVisible)
		{
			break;
		}
		if (!mBullets[i]->isVisible)
		{
			/*
			sets the first bullet that is invisible to visible
			sets its position to the players position
			plays shooting audio
			*/
			mBullets[i]->setPosition(this->Global->position);
			mBullets[i]->isVisible = true;
			m_audio->setGain(0.3);
			m_audio->play();
			return;
		}
	}
}

void Object::drawAABB(aie::Renderer2D* renderer)
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

bool Object::amIDead()
{
	if (fHealth <= 0)
	{
		return true;
	}
	return false;
}


