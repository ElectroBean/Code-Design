#include "GameStateManager.h"
#include "GameManager.h"
#include "GameOverScreen.h"
#include "MenuState.h"
#include "Application2D.h"
#include "Controls.h"
#include "WinScreen.h"


GameStateManager::GameStateManager(Application2D* application)
{
	worldManager = new GameManager(this);
	gameOverScreen = new GameOverScreen(this);
	menuScreen = new MenuState(this, worldManager);
	GameState = State::Menu;
	this->application = application;
	controlsScreen = new Controls(this);
	won = new WinScreen(this);
}


GameStateManager::~GameStateManager()
{
	delete worldManager;
	delete gameOverScreen;
	delete menuScreen;
	delete controlsScreen;
	delete won;
}

void GameStateManager::update(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();
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
	case State::Control:
	{
		controlsScreen->update(deltaTime);
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
	case State::Quit:
	{
		application->quit();
		break;
	}
	case State::Won:
	{
		won->update(deltaTime);
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
	case State::Control:
	{
		controlsScreen->draw(renderer);
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
	case State::Won:
	{
		won->draw(renderer);
		break;
	}
	}
}

void GameStateManager::setState(State a_state)
{
	GameState = a_state;
}

