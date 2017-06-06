#include "Controls.h"
#include "GameStateManager.h"


Controls::Controls(GameStateManager* state)
{
	this->state = state;
	ControlsImage = new aie::Texture("./textures/controls.png");
}


Controls::~Controls()
{
	delete ControlsImage;
}

void Controls::update(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();

	if (input->wasKeyPressed(aie::INPUT_KEY_ESCAPE))
	{
		state->setState(state->Menu);
	}
}

void Controls::draw(aie::Renderer2D* renderer)
{
	renderer->drawSprite(ControlsImage, 400, 360);
}
