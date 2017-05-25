#include "GameManager.h"



GameManager::GameManager()
{
	Player = new Object(Vector3(600, 50, 1), 3.14, new aie::Texture("./textures/ship.png"));
	Alien1 = new Alien(Vector3(80, 700, 0), 0, new aie::Texture("./textures/car.png"), Vector3(80, 700, 0), Vector3(1000, 700, 0));
	debugShit = new aie::Texture("./textures/laser.png");
}


GameManager::~GameManager()
{
	delete Player;
	delete Alien1;
}

void GameManager::update(float deltaTime)
{
	BulletUpdate(deltaTime);
	Alien1->Update(deltaTime);
	Player->Update(deltaTime);
}

void GameManager::draw(aie::Renderer2D* a_renderer)
{
	Alien1->Draw(a_renderer);
	Player->Draw(a_renderer);
	a_renderer->drawSprite(debugShit, 250, 250, 50, 50, 0);
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
	std::vector<Bullet*> bullets;
	bullets.reserve(10000);
	for (int i = 0; i < 100; i++)
	{
		bullets.push_back((Player->mBullets[i]));
	}

	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i]->isVisible)
		{
			if (bullets[i]->collCheck->collidesWith(*Alien1->collCheck))
			{
				bullets[i]->setPosition(Player->Global->position);
				bullets[i]->isVisible = false;
				std::cout << "collision" << std::endl;
			}
		}
	}
}