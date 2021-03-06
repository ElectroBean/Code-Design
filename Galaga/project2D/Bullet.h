#pragma once
#include "aabb.h"
#include <vector>
#include <Vector3.h>
#include <Matrix3D.h>
#include <Texture.h>
#include "Renderer2D.h""

class Alien;
class Bullet 
{
public:
	Bullet(const Vector3& a_pos, const float a_rotation, aie::Texture* const a_texture);
	~Bullet();

	void update(float deltaTime);

	void Draw(aie::Renderer2D * a_Render);

	void SetRotation(const float a_rotation);

	void setPosition(Vector3 position);

	void setAlien(Alien* a_alien);

	void SetSpeed(const float a_speed);
	void ScreenWrap();
	void drawAABB(aie::Renderer2D * renderer);
	float rotation = 0.0f;
	bool isVisible = false;
	Matrix3*		Global = nullptr;
	Matrix3*		Local = nullptr;
	aabb* collCheck = nullptr;

protected:
	Alien * parent = nullptr;
	std::vector<Bullet>* children = nullptr;
	aie::Texture*	Texture = nullptr;
	float fSpeed = 0.0f;
	float fHealth = 100.0f;

	Vector3 V3Direction = Vector3(0.0f, 0.0f, 0.0f);
	Vector3 V3Velocity = Vector3(0.0f, 0.0f, 0.0f);
};

