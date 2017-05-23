#pragma once
#include "Object.h"


class Alien :
	public Object
{
public:

	Alien(const Vector3& a_pos, const float a_rotation, aie::Texture* const a_texture, Vector3 start, Vector3 end);
	~Alien();

	void Move(float deltaTime);
	void Update(float deltaTime);
	void Draw(aie::Renderer2D * a_Render);

	void drawAABB(aie::Renderer2D * renderer);

	void interpolate(float deltaTime);

	Matrix3*		Global = nullptr;
	aabb*				collCheck;
protected:
	Object * parent = nullptr;
	std::vector<Object>* children = nullptr;
	Matrix3*		Local = nullptr;
	aie::Texture*	Texture = nullptr;
	Bullet *mBullets[100];
	aie::Texture*		m_bullet;
	float moveTimer;
	bool direction = true;
	Vector3 begin;
	Vector3 ending;
	float moveTimer2;

	Vector3 V3Direction = Vector3(0.0f, 0.0f, 0.0f);
	Vector3 V3Velocity = Vector3(0.0f, 0.0f, 0.0f);
};

