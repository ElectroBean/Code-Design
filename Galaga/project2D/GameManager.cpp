#include "GameManager.h"



GameManager::GameManager()
{
	Player = new Object(Vector3(600, 50, 1), 3.14, new aie::Texture("./textures/ship.png"));
	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 11; i++)
		{
			aliens[j * 11 + i] = new Alien(Vector3(80 * (i + 1), 720 - ((j + 1) * 80), 0), 0, new aie::Texture("./textures/car.png"));

		}
	}
	bullets.reserve(100);
	for (int i = 0; i < 100; i++)
	{
		bullets.push_back((Player->mBullets[i]));
	}
}


GameManager::~GameManager()
{
	delete Player;
	for (int i = 0; i < 55; i++)
	{
		delete aliens[i];
	}
}

void GameManager::update(float deltaTime)
{
	Player->Update(deltaTime);
	BulletUpdate(deltaTime);
	for (int i = 0; i < 55; i++)
	{
		if (aliens[i]->isVisible)
		{
			aliens[i]->Update(deltaTime);
		}
	}
	DidILose();
	PlayerTakeDamage();
	AliensMoveDown();
	AlienSpeedUp();
}

void GameManager::draw(aie::Renderer2D* a_renderer)
{
	Player->Draw(a_renderer);
	for (int i = 0; i < 55; i++)
	{
		if (aliens[i]->isVisible)
			aliens[i]->Draw(a_renderer);
	}

}

void GameManager::drawAABB(const aabb & aabb, aie::Renderer2D * renderer)
{
	// LEFT
	renderer->drawLine(aabb.x - aabb.halfwidth, aabb.y - aabb.halfheight, aabb.x - aabb.halfwidth, aabb.y + aabb.halfheight);
	// RIGHT
	renderer->drawLine(aabb.x + aabb.halfwidth, aabb.y - aabb.halfheight, aabb.x + aabb.halfwidth, aabb.y + aabb.halfheight);
	// TOP
	renderer->drawLine(aabb.x - aabb.halfwidth, aabb.y + aabb.halfheight, aabb.x + aabb.halfwidth, aabb.y + aabb.halfheight);
	// BOTTOM
	renderer->drawLine(aabb.x - aabb.halfwidth, aabb.y - aabb.halfheight, aabb.x + aabb.halfwidth, aabb.y - aabb.halfheight);
}

void GameManager::BulletUpdate(float deltaTime)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i]->isVisible)
		{
			for (int j = 0; j < 55; j++)
			{
				if (aliens[j]->isVisible)
				{
					if (bullets[i]->collCheck->collidesWith(*aliens[j]->collCheck))
					{
						bullets[i]->isVisible = false;
						bullets[i]->setPosition(Vector3(0, 0, 1));
						aliens[j]->die();
						std::cout << "collision" << std::endl;
					}
				}
			}
		}
	}
}

void GameManager::DidILose()
{
	if (Player->amIDead())
	{
		std::cout << "lost" << std::endl;
	}
}

void GameManager::PlayerTakeDamage()
{
	for (int i = 0; i < 55; i++)
	{
		if (aliens[i]->isVisible)
		{
			if (aliens[i]->collCheck->collidesWith(*Player->collCheck))
			{
				Player->takeDamage(100);
			}
		}
	}
}

void GameManager::AliensMoveDown()
{
	for (int i = 0; i < 55; i++)
	{
		if (aliens[i]->isVisible)
		{
			if (aliens[i]->Global->position.x >= 1000)
			{
				for (int j = 0; j < 55; j++)
				{
					aliens[j]->Move();
				}
			}
			if (aliens[i]->Global->position.x <= 80)
			{
				for (int j = 0; j < 55; j++)
				{
					aliens[j]->Move();
				}
			}
		}
	}
}

void GameManager::AlienSpeedUp()
{
	int numberAlive = 0;
	for (int i = 0; i < 55; i++)
	{
		if (aliens[i]->isVisible)
		{
			numberAlive++;
		}
	}

	if (numberAlive <= 44 && numberAlive > 33)
	{
		for (int i = 0; i < 55; i++)
		{
			aliens[i]->setMoveSpeed(0.4f);
		}
	}
	else if (numberAlive <= 33 && numberAlive > 22)
	{
		for (int i = 0; i < 55; i++)
		{
			aliens[i]->setMoveSpeed(0.3f);
		}
	}
	else if (numberAlive <= 22 && numberAlive > 11)
	{
		for (int i = 0; i < 55; i++)
		{
			aliens[i]->setMoveSpeed(0.2f);
		}
	}
	else if (numberAlive <= 11 && numberAlive > 1)
	{
		for (int i = 0; i < 55; i++)
		{
			aliens[i]->setMoveSpeed(0.1f);
		}
	}
	else if (numberAlive <= 1)
	{
		for (int i = 0; i < 55; i++)
		{
			aliens[i]->setMoveSpeed(0.01f);
		}
	}

}