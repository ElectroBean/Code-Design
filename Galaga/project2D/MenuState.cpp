#include "MenuState.h"
#include "GameStateManager.h"


MenuState::MenuState(GameStateManager* a_state)
{
	currentChoice = Play;
	state = a_state;
	menuTexture = new aie::Texture("./textures/menuscreen.png");
}


MenuState::~MenuState()
{
	delete menuTexture;
}

void MenuState::update(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();

	switch (currentChoice)
	{
	case Choice::Play:
	{
		if (input->isKeyDown(aie::INPUT_KEY_ENTER))
		{
			state->setState(state->Playing);
		}
		else if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		{
			currentChoice = KeyBindings;
		}
		break;

	}
	case Choice::KeyBindings:
	{
		if (input->isKeyDown(aie::INPUT_KEY_ENTER))
		{
			state->setState(state->Controls);
		}
		else if (input->isKeyDown(aie::INPUT_KEY_UP))
		{
			currentChoice = Play;
		}
		else if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		{
			currentChoice = Quit;
		}
		break;

	}
	case Choice::Quit:
	{
		if (input->isKeyDown(aie::INPUT_KEY_ENTER))
		{
			
		}
		break;

	}
	}
}

void MenuState::draw(aie::Renderer2D* renderer)
{
	renderer->drawSprite(menuTexture, 400, 360);
	switch (currentChoice)
	{
	case Choice::Play:
	{
		renderer->drawLine(310, 320, 500, 320);
		break;

	}
	case Choice::KeyBindings:
	{
		renderer->drawLine(310, 250, 500, 250);
		break;

	}
	case Choice::Quit:
	{
		renderer->drawLine(310, 320, 500, 320);
		break;

	}
	}
}
