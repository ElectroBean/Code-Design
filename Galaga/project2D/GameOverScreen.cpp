#include "GameOverScreen.h"
#include "GameStateManager.h"


GameOverScreen::GameOverScreen(GameStateManager* gameState)
{
	gameOverTexture = new aie::Texture("./textures/splash.jpg");
	state = gameState;
}


GameOverScreen::~GameOverScreen()
{
	delete gameOverTexture;
}

void GameOverScreen::draw(aie::Renderer2D* renderer)
{
	//renderer->drawLine(0, 0, 800, 720);
	renderer->drawSprite(gameOverTexture, 400, 360);
}

void GameOverScreen::update(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();

	if (input->isKeyDown(aie::INPUT_KEY_ENTER))
	{
		state->setState(state->Quit);
	}
}
