#pragma once
#include <Renderer2D.h>
#include <Input.h>
#include <iostream>
#include <Texture.h>

class GameStateManager;

class MenuState
{
public:
	MenuState(GameStateManager* a_state);
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
};

