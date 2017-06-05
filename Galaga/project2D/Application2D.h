#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include "GameManager.h"
#include "GameStateManager.h"

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	aie::Audio*			m_audio;
	GameStateManager*	m_gameStateManager;

	float m_cameraX, m_cameraY;
	float m_timer;
};