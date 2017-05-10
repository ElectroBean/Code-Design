#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <string>

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	m_texture = new aie::Texture("./textures/numbered_grid.tga");
	m_shipTexture = new aie::Texture("./textures/ship.png");

	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_bullet = new aie::Texture("./textures/roundthing.png");

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	NotShip = new Object(Vector3(600, 50, 1), 3.14, m_shipTexture);
	collision1 = new aabb(10, 10, 25, 25);
	collision2 = new aabb(50, 50, 40, 40);
	return true;
}

void Application2D::shutdown() {
	
	delete m_font;
	delete m_texture;
	delete m_shipTexture;
	delete m_2dRenderer;
	delete NotShip;
	delete m_bullet;
	delete collision1;
	delete collision2;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;
	NotShip->Update(deltaTime);
	// input example
	aie::Input* input = aie::Input::getInstance();

	collision1->x = NotShip->Global->position.x;
	collision1->y = NotShip->Global->position.y;

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	//draw ships
	NotShip->Draw(m_2dRenderer);
	drawAABB(*collision1, m_2dRenderer);
	drawAABB(*collision2, m_2dRenderer);

	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);

	if (collision1->collidesWith(*collision2))
	{
		m_2dRenderer->drawText(m_font, "SNAPE KILLS DUMBLEDORE", getWindowWidth() / 3, getWindowHeight() - 100);
	}

	// done drawing sprites
	m_2dRenderer->end();
}

void Application2D::drawAABB(const aabb& aabb, aie::Renderer2D* renderer) {
	// LEFT
	renderer->drawLine(aabb.x - aabb.halfwidth, aabb.y - aabb.halfheight, aabb.x - aabb.halfwidth, aabb.y + aabb.halfheight);
	// RIGHT
	renderer->drawLine(aabb.x + aabb.halfwidth, aabb.y - aabb.halfheight, aabb.x + aabb.halfwidth, aabb.y + aabb.halfheight);
	// TOP
	renderer->drawLine(aabb.x - aabb.halfwidth, aabb.y + aabb.halfheight, aabb.x + aabb.halfwidth, aabb.y + aabb.halfheight);
	// BOTTOM
	renderer->drawLine(aabb.x - aabb.halfwidth, aabb.y - aabb.halfheight, aabb.x + aabb.halfwidth, aabb.y - aabb.halfheight);
}