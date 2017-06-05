#include "GameStateManager.h"
#include "GameManager.h"
#include "GameOverScreen.h"
#include "MenuState.h"


GameStateManager::GameStateManager()
{
	worldManager = new GameManager(this);
	gameOverScreen = new GameOverScreen(this);
	menuScreen = new MenuState(this);
	GameState = State::Menu;
}


GameStateManager::~GameStateManager()
{
	delete worldManager;
	delete gameOverScreen;
	delete menuScreen;
}

void GameStateManager::update(float deltaTime)
{
	std::cout << GameState << std::endl;
	switch (GameState)
	{
	case State::Splash:
	{

		break;
	}
	case State::Menu:
	{
		menuScreen->update(deltaTime);
		break;
	}
	case State::Playing:
	{
		worldManager->update(deltaTime);
		break;
	}
	case State::GameOver:
	{
		gameOverScreen->update(deltaTime);
		break;
	}
	}
}

void GameStateManager::draw(aie::Renderer2D * renderer)
{
	switch (GameState)
	{
	case State::Splash:
	{

		break;
	}
	case State::Menu:
	{
		menuScreen->draw(renderer);
		break;
	}
	case State::Playing:
	{
		worldManager->draw(renderer);
		break;
	}
	case State::GameOver:
	{
		gameOverScreen->draw(renderer);
		break;
	}
	}
}

void GameStateManager::setState(State a_state)
{
	GameState = a_state;
}

