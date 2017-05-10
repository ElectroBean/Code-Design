#pragma once
#include <Vector3.h>
#include <Matrix3D.h>
#include <Application.h>
#include <Texture.h>
#include <vector>
#include <Renderer2D.h>
#include <Input.h>
 
class Object
{
public:
	Object(const Vector3& a_pos, const float a_rotation, aie::Texture* const a_texture);
	virtual ~Object();// = 0 {};
	virtual void Update(const float deltaTime);
	void Draw(aie::Renderer2D* a_Render);
	void SetSpeed(const float a_speed);
	void SetRotation(const float a_rotation);
	void SetParent(Object* a_parent);
	void ScreenWrap();
	float rotation = 0.0f;

	Matrix3*		Global = nullptr;
private:
	Object * parent = nullptr;
	std::vector<Object>* children = nullptr;
	Matrix3*		Local = nullptr;
	aie::Texture*	Texture = nullptr;
	float fSpeed = 0.0f;
	
	Vector3 V3Direction = Vector3(0.0f, 0.0f, 0.0f);
	Vector3 V3Velocity = Vector3(0.0f, 0.0f, 0.0f);
};

