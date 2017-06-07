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
#include "extraAlien.h"

using namespace std;
class GameStateManager;

class GameManager
{
public:
	GameManager(GameStateManager* a_gameState);
	~GameManager();

	virtual void update(float deltaTime);
	virtual void draw(aie::Renderer2D* a_renderer);
	void drawAABB(const aabb & aabb, aie::Renderer2D * renderer);

	void BulletUpdate(float deltaTime);

	void DidILose();

	void PlayerTakeDamage();

	void AliensMoveDown();

	void AlienSpeedUp();

	void CheckWon();

	void ResetPositions();

	int randRange(unsigned int min, unsigned int max);

	bool gameIsOver = false;
private:
	Object* Player;
	aie::Audio* m_invaderKilled;
	aie::Audio* m_killed;
	bool gameOver = false;
	aie::Texture* m_Background;
	Vector2 backGroundPosition;
	GameStateManager* GameState;
	bool won = false;
	float alienShoot = 0.0f;

	Alien* aliens[55];
	Alien* randomAlien;
	extraAlien* alienMegaPrime;

	std::vector<Bullet*> bullets;
};

