#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
aie::Font* g_systemFont = nullptr;

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {

	m_2dRenderer = new aie::Renderer2D();
	g_systemFont = new aie::Font("./font/consolas.ttf", 32);
	m_cameraX = 0;
	m_cameraY = 0;
	return true;
}

void Application2D::shutdown() {
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {
	// input example
	aie::Input* input = aie::Input::getInstance();

	static int value = 0;
	ImGui::InputInt("Value", &value);

	//if (ImGui::Button("Insert", ImVec2(50, 0)))
	//{
	//	m_binaryTree.insert(value);
	//	m_selectedNode = m_binaryTree.find(value);
	//}
	//if (ImGui::Button("Remove", ImVec2(50, 0)))
	//{
	//	m_binaryTree.remove(value);
	//}
	//if (ImGui::Button("Find", ImVec2(50, 0)))
	//{
	//	m_selectedNode = m_binaryTree.find(value);
	//}





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
	m_2dRenderer->drawText(g_systemFont, "Press ESC to quit", 0, 0);
	// done drawing sprites
	m_2dRenderer->end();
}