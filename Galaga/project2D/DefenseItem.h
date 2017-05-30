#pragma once
#include "Player.h"
#include "aabb.h"
#include "Renderer2D.h"
#include "Bullet.h"

class DefenseItem :
	public Object
{
public:
	DefenseItem(Vector3 aPosition);
	~DefenseItem();

	void update(float deltaTime);

	void drawBox(aie::Renderer2D * a_Render);

	void getShot();


};

