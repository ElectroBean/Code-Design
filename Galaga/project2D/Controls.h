#pragma once
#include <Texture.h>
#include <Renderer2D.h>
#include <Input.h>

class GameStateManager;

class Controls
{
public:
	Controls(GameStateManager* state);
	~Controls();

	void update(float deltaTime);
	void draw(aie::Renderer2D* renderer);

private:
	aie::Texture* ControlsImage;
	GameStateManager* state;
};

