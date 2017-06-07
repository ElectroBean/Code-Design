#pragma once
#include <Renderer2D.h>
#include <Input.h>
#include <iostream>
#include <Texture.h>

class GameStateManager;
class GameManager;

class MenuState
{
public:
	MenuState(GameStateManager* a_state, GameManager* a_game);
	~MenuState();

	enum Choice
	{
		Play, 
		KeyBindings, 
		Quit,
	};

	void update(float deltaTime);
	void draw(aie::Renderer2D* renderer);

private:
	Choice currentChoice;
	GameStateManager* state;
	aie::Texture* menuTexture;
	bool canChoose = false;
	GameManager* worldManager;
};

