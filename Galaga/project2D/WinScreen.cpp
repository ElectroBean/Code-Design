#include "WinScreen.h"
#include "GameStateManager.h"


WinScreen::WinScreen(GameStateManager* gameState)
{
	state = gameState;
	winTexture = new aie::Texture("./textures/winscreen.png");
	winSong = new aie::Audio("./audio/won.wav");
	winSong->setGain(0.1);
}


WinScreen::~WinScreen()
{
	delete winTexture;
	delete winSong;
}

void WinScreen::update(float deltaTime)
{
	winSong->play();
	aie::Input* input = aie::Input::getInstance();

	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
	{
		state->setState(state->Menu);
		winSong->stop();
	}
}

void WinScreen::draw(aie::Renderer2D * renderer)
{
	renderer->drawSprite(winTexture, 400, 360);
}
