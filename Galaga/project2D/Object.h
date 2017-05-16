#pragma once
#include <Renderer2D.h>
#include <Application.h>
#include "Bullet.h"
#include <Matrix3D.h>
#include <Vector3.h>
#include <Texture.h>
#include <vector>
#include <Input.h>
 
class Object
{
public:
	Object();
	Object(const Vector3& a_pos, const float a_rotation, aie::Texture* const a_texture);
	virtual ~Object();// = 0 {};
	virtual void Update(const float deltaTime, aie::Renderer2D * a_Render);
	void Draw(aie::Renderer2D* a_Render);
	void SetSpeed(const float a_speed);
	void SetRotation(const float a_rotation);
	void SetParent(Object* a_parent);
	void ScreenWrap();
	float rotation = 0.0f;
	void takeDamage(int aDamage);
	void ShootBullet();

	Matrix3*		Global = nullptr;
private:
	Object * parent = nullptr;
	std::vector<Object>* children = nullptr;
	Matrix3*		Local = nullptr;
	aie::Texture*	Texture = nullptr;
	float fSpeed = 0.0f;
	float fHealth = 100.0f;
	Bullet *mBullets[100];
	float shootTimer = 0.0f;
	bool shooting = false;
	aie::Texture*		m_bullet;

	Vector3 V3Direction = Vector3(0.0f, 0.0f, 0.0f);
	Vector3 V3Velocity = Vector3(0.0f, 0.0f, 0.0f);
};

