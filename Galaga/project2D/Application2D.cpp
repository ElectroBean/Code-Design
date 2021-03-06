#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <string>
typedef std::shared_ptr<Resource<aie::Texture>> TexturePtr;

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	m_2dRenderer = new aie::Renderer2D();
	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	m_gameStateManager = new GameStateManager(this);

	//resource manager testing
	TexturePtr pShip = m_images.get("./textures/ship.png");
	m_player = new TempPlayer(pShip);

	std::cout << "images loaded: " << m_images.getCount() << std::endl;

	return true;
}

void Application2D::shutdown()
{
	delete m_font;
	delete m_2dRenderer;
	delete m_gameStateManager;

	//resource manager testing 
	std::cout << "images loaded: " << m_images.getCount() << std::endl;

	delete m_player;
	m_images.collectGarbage();

	std::cout << "images loaded: " << m_images.getCount() << std::endl;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();
	m_gameStateManager->update(deltaTime);

	// exit the application
	//if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
	//	quit();
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);
	// begin drawing sprites
	m_2dRenderer->begin();

	m_gameStateManager->draw(m_2dRenderer);

	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);

	// done drawing sprites
	m_2dRenderer->end();
}