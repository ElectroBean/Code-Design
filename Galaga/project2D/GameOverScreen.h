#pragma once
#include <Renderer2D.h>
#include <Texture.h>
#include <Input.h>

class GameStateManager;

class GameOverScreen
{
public:
	GameOverScreen(GameStateManager* gameState);
	~GameOverScreen();

	void draw(aie::Renderer2D* renderer);
	void update(float deltaTime);

private:
	aie::Texture* gameOverTexture;
	GameStateManager* state;
};

