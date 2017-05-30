#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include "Player.h"
#include "aabb.h"
#include "Alien.h"
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class GameManager
{
public:
	GameManager();
	~GameManager();

	virtual void update(float deltaTime);
	virtual void draw(aie::Renderer2D* a_renderer);
	void drawAABB(const aabb & aabb, aie::Renderer2D * renderer);

	void BulletUpdate(float deltaTime);

	void DidILose();

	void PlayerTakeDamage();

	void AliensMoveDown();

	void AlienSpeedUp();

private:
	Object* Player;

	Alien* aliens[55];
	std::vector<Bullet*> bullets;
};

