#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include "Object.h"
#include "aabb.h"
#include "Alien.h"

class GameManager
{
public:
	GameManager();
	~GameManager();

	virtual void update(float deltaTime);
	virtual void draw(aie::Renderer2D* a_renderer);
	void drawAABB(const aabb & aabb, aie::Renderer2D * renderer);

private:
	Object* Player;
	Alien*	Alien1;
};

