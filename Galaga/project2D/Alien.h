#pragma once
#include "Object.h"


class Alien :
	public Object
{
public:

	Alien(const Vector3& a_pos, const float a_rotation, aie::Texture* const a_texture);
	~Alien();

	void Move(float deltaTime);
	void Update(float deltaTime);
	void Draw(aie::Renderer2D * a_Render);

	Matrix3*		Global = nullptr;
private:
	Object * parent = nullptr;
	std::vector<Object>* children = nullptr;
	Matrix3*		Local = nullptr;
	aie::Texture*	Texture = nullptr;
	Bullet *mBullets[100];
	aie::Texture*		m_bullet;

	Vector3 V3Direction = Vector3(0.0f, 0.0f, 0.0f);
	Vector3 V3Velocity = Vector3(0.0f, 0.0f, 0.0f);
};

