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

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	NotShip = new Object(Vector3(600, 50, 1), 3.14, m_shipTexture);
	alien1 = new Alien(Vector3(100, 680, 0), 0, new aie::Texture("./textures/car.png"));
	return true;
}

void Application2D::shutdown() {
	
	delete m_font;
	delete m_texture;
	delete m_shipTexture;
	delete m_2dRenderer;
	delete NotShip;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;
	NotShip->Update(deltaTime, m_2dRenderer);
	// input example
	aie::Input* input = aie::Input::getInstance();

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
	alien1->Draw(m_2dRenderer);

	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);

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

void Application2D::detectAlien()
{

}

void Application2D::detectBullets()
{

}

