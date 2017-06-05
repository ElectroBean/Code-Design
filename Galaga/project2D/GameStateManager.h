#pragma once
#include <Renderer2D.h>

class GameManager;
class GameOverScreen;
class MenuState;

class GameStateManager
{
public:
	GameStateManager();
	~GameStateManager();

	enum State
	{
		Splash,
		Menu, 
		Controls,
		Playing, 
		GameOver,
	};

	void update(float deltaTime);				//updates current game state
	void draw(aie::Renderer2D* renderer);		//draws current game state
	void setState(State a_state);				//sets current game state

private:
	GameManager* worldManager;
	GameOverScreen*	 gameOverScreen;
	MenuState* menuScreen;
	State GameState;	
	
};

