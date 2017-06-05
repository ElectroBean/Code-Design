#pragma once
#include <Renderer2D.h>
#include <Application.h>
#include "Bullet.h"
#include <Matrix3D.h>
#include <Vector3.h>
#include <Texture.h>
#include <vector>
#include <Input.h>
#include "Audio.h"
 
class Object
{
public:
	Object();
	Object(const Vector3& a_pos, const float a_rotation, aie::Texture* const a_texture);
	virtual ~Object();// = 0 {};
	virtual void Update(const float deltaTime);		//updates player
	void Draw(aie::Renderer2D* a_Render);			//draws player	
	void SetRotation(const float a_rotation);		//sets the rotation of player
	void SetParent(Object* a_parent);				//sets a parent
	void ScreenWrap();								//keeps player within game bounds
	void takeDamage(int aDamage);					//removes health from player
	void ShootBullet();								//fires a bullet

	void drawAABB(aie::Renderer2D * renderer);		//draws collision box

	bool amIDead();									//returns true if player is at or below 0 health


	float rotation = 0.0f;
	Matrix3*		Global = nullptr;
	Bullet *mBullets[100];
	aabb*	collCheck;
protected:
	Object * parent = nullptr;
	std::vector<Object>* children = nullptr;
	Matrix3*		Local = nullptr;
	aie::Texture*	playerTexture = nullptr;
	float fSpeed = 0.0f;
	float fHealth = 100.0f;
	float shootTimer = 0.0f;
	bool shooting = false;
	aie::Texture*		m_bullet;
	aie::Audio*			m_audio;

	Vector3 V3Direction = Vector3(0.0f, 0.0f, 0.0f);
	Vector3 V3Velocity = Vector3(0.0f, 0.0f, 0.0f);
};

