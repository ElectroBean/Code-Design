#pragma once
#include <aabb.h>
#include <Matrix3D.h>
#include <Renderer2D.h>
#include <Texture.h>
#include <Audio.h>

class extraAlien 
{
public:
	extraAlien(const Vector3 & a_pos);
	~extraAlien();

	void Update(float deltaTime);

	void draw(aie::Renderer2D * renderer);

	Matrix3*		Global = nullptr;
	aabb*				collCheck;
	bool isVisible;
protected:
	Matrix3*		Local = nullptr;
	aie::Texture*	Texture = nullptr;


	Vector3 begin;
	Vector3 ending;

	bool direction = true;
	float moveTimer = 0.0f;
};

