#pragma once
#include "aabb.h"
#include <vector>
#include <Vector3.h>
#include <Matrix3D.h>
#include <Texture.h>
#include <Renderer2D.h>

class Bullet 
{
public:
	Bullet(const Vector3& a_pos, const float a_rotation, aie::Texture* const a_texture);
	~Bullet();

	void update(float deltaTime);

	void Draw(aie::Renderer2D * a_Render);

	void SetRotation(const float a_rotation);

	void setPosition(Vector3 position);

	void SetSpeed(const float a_speed);
	void ScreenWrap();
	float rotation = 0.0f;
	bool isVisible = false;
	Matrix3*		Global = nullptr;
	Matrix3*		Local = nullptr;
private:
	Bullet * parent = nullptr;
	std::vector<Bullet>* children = nullptr;
	aie::Texture*	Texture = nullptr;
	float fSpeed = 0.0f;
	float fHealth = 100.0f;

	Vector3 V3Direction = Vector3(0.0f, 0.0f, 0.0f);
	Vector3 V3Velocity = Vector3(0.0f, 0.0f, 0.0f);
};

