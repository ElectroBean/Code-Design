#include "GameManager.h"



GameManager::GameManager()
{
	Player = new Object(Vector3(600, 50, 1), 3.14, new aie::Texture("./textures/ship.png"));
	Alien1 = new Alien(Vector3(100, 680, 0), 0, new aie::Texture("./textures/car.png"));
}


GameManager::~GameManager()
{
	delete Player;
	delete Alien1;
}

void GameManager::update(float deltaTime)
{
	Player->Update(deltaTime);
	Alien1->Update(deltaTime);
}

void GameManager::draw(aie::Renderer2D* a_renderer)
{
	Player->Draw(a_renderer);
	Alien1->Draw(a_renderer);
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
