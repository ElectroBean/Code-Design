#pragma once
#include "Player.h"


class Alien :
	public Object
{
public:

	Alien();

	Alien(const Vector3& a_pos, const float a_rotation, aie::Texture* const a_texture);
	~Alien();

	void Move();								//moves aliens down if one in array is at screen bound
	void Update(float deltaTime);				//updates aliens
	void Draw(aie::Renderer2D * a_Render);		//draws aliens

	void drawAABB(aie::Renderer2D * renderer);	//draws alien collisions

	void interpolate(float deltaTime);			//moves aliens across the screen
	void die();

	void setMoveSpeed(float aMoveSpeed);		//changes movement delay

	Matrix3*		Global = nullptr;
	aabb*				collCheck;
	bool isVisible;
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
	float movedDownTimer = 0.0f;
	float moveDelay;

	aie::Audio* sound1;
	aie::Audio* sound2;
	aie::Audio* sound3;
	aie::Audio* sound4;
	int moveNumber;

	Vector3 V3Direction = Vector3(0.0f, 0.0f, 0.0f);
	Vector3 V3Velocity = Vector3(0.0f, 0.0f, 0.0f);
};

