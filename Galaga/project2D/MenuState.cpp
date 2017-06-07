#include "MenuState.h"
#include "GameStateManager.h"
#include "GameManager.h"

MenuState::MenuState(GameStateManager* a_state, GameManager* a_game)
{
	currentChoice = Play;
	state = a_state;
	menuTexture = new aie::Texture("./textures/menuscreen.png");
	worldManager = a_game;
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

		if (input->wasKeyPressed(aie::INPUT_KEY_ENTER))
		{
			if (!worldManager->gameIsOver)
				state->setState(state->Playing);

			else
			{
				worldManager->ResetPositions();
				state->setState(state->Playing);
			}
		}
		else if (input->wasKeyPressed(aie::INPUT_KEY_DOWN))
		{
			currentChoice = KeyBindings;

		}
		break;

	}
	case Choice::KeyBindings:
	{
		
		if (input->wasKeyPressed(aie::INPUT_KEY_ENTER))
		{
			state->setState(state->Control);
		}
		else if (input->wasKeyPressed(aie::INPUT_KEY_UP))
		{
			currentChoice = Play;

		}
		else if (input->wasKeyPressed(aie::INPUT_KEY_DOWN))
		{
			currentChoice = Quit;

		}
		break;

	}
	case Choice::Quit:
	{
		if (input->wasKeyPressed(aie::INPUT_KEY_ENTER))
		{
			state->setState(state->Quit);
		}
		else if (input->wasKeyPressed(aie::INPUT_KEY_UP))
		{
			currentChoice = KeyBindings;

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
		renderer->drawLine(310, 225, 500, 225);
		break;

	}
	case Choice::Quit:
	{
		renderer->drawLine(310, 100, 500, 100);
		break;

	}
	}
}
