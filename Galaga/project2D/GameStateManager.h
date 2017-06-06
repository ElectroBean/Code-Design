#pragma once
#include <Renderer2D.h>

class GameManager;
class GameOverScreen;
class MenuState;
class Application2D;
class Controls;
class WinScreen;

class GameStateManager
{
public:
	GameStateManager(Application2D* application);
	~GameStateManager();

	enum State
	{
		Splash,
		Menu, 
		Control,
		Playing, 
		GameOver,
		Quit,
		Won,
	};

	void update(float deltaTime);				//updates current game state
	void draw(aie::Renderer2D* renderer);		//draws current game state
	void setState(State a_state);				//sets current game state

private:
	GameManager* worldManager;
	GameOverScreen*	 gameOverScreen;
	MenuState* menuScreen;
	State GameState;	
	Application2D* application;
	Controls* controlsScreen;
	WinScreen* won;
};

