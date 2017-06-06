#pragma once
#include <Texture.h>
#include <Input.h>
#include <Renderer2D.h>
#include <Audio.h>

class GameStateManager;

class WinScreen
{
public:
	WinScreen(GameStateManager* gameState);
	~WinScreen();

	void update(float deltaTime);
	void draw(aie::Renderer2D* renderer);

private:
	aie::Texture* winTexture;
	GameStateManager* state;
	aie::Audio* winSong;
};

