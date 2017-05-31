#pragma once
#include "Alien.h"

class extraAlien :
	public Alien
{
public:
	extraAlien(const Vector3 & a_pos, aie::Texture * const a_texture);
	~extraAlien();

	void Update(float deltaTime);

	Matrix3*		Global = nullptr;
	aabb*				collCheck;
	bool isVisible;
protected:
	Matrix3*		Local = nullptr;
	aie::Texture*	Texture = nullptr;

	Vector3 begin;
	Vector3 ending;

	bool direction = true;
};

