#include "GameManager.h"

#include "GameStateManager.h"

GameManager::GameManager(GameStateManager* a_gameState)
{
	Player = new Object(Vector3(600, 50, 1), 3.14, new aie::Texture("./textures/ship.png"));
	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 11; i++)
		{
			aliens[j * 11 + i] = new Alien(Vector3(50 * (i + 1), 720 - ((j + 1) * 80), 0), 0, new aie::Texture("./textures/saucer1b.png"));
		}
	}
	bullets.reserve(100);
	for (int i = 0; i < 100; i++)
	{
		bullets.push_back((Player->mBullets[i]));
	}

	m_invaderKilled = new aie::Audio("./audio/invaderkilled.wav");
	m_killed = new aie::Audio("./audio/explosion.wav");
	m_Background = new aie::Texture(("./textures/background.png"));
	backGroundPosition = Vector2(0, 0);
	GameState = a_gameState;
	alienMegaPrime = new extraAlien(Vector3(60, 700, 0));
}


GameManager::~GameManager()
{
	delete Player;
	for (int i = 0; i < 55; i++)
	{
		delete aliens[i];
	}
	delete m_invaderKilled;
	delete m_killed;
	delete m_Background;
	delete alienMegaPrime;
}

void GameManager::update(float deltaTime)
{
	backGroundPosition.y -= 500.0f * deltaTime;
	if (backGroundPosition.y <= -340)
	{
		backGroundPosition.y = 1100;
	}
	if (!gameOver)
	{
		Player->Update(deltaTime);
		BulletUpdate(deltaTime);
		for (int i = 0; i < 55; i++)
		{
			if (aliens[i]->isVisible)
			{
				aliens[i]->Update(deltaTime);
			}
		}
		DidILose();
		PlayerTakeDamage();
		AliensMoveDown();
		AlienSpeedUp();
		CheckWon();

		//checks for escape input and goes to menu if true
		aie::Input* input = aie::Input::getInstance();
		if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		{
			GameState->setState(GameState->Menu);
		}
		if (input->wasKeyPressed(aie::INPUT_KEY_Y))
		{
			for (int i = 0; i < 55; i++)
			{
				if (aliens[i]->isVisible)
				{
					aliens[i]->isVisible = false;
				}
			}
		}
	}

	alienMegaPrime->Update(deltaTime);

	if (won)
	{
		GameState->setState(GameState->Won);
	}
}

void GameManager::draw(aie::Renderer2D* a_renderer)
{
	a_renderer->drawSprite(m_Background, 800 / 2, backGroundPosition.y, 800, 2160);
	if (!gameOver)
	{

		Player->Draw(a_renderer);
		alienMegaPrime->draw(a_renderer);
		for (int i = 0; i < 55; i++)
		{
			if (aliens[i]->isVisible)
				aliens[i]->Draw(a_renderer);
		}
	}
	else
	{

	}
}

void GameManager::drawAABB(const aabb & aabb, aie::Renderer2D * renderer)
{
	// LEFT
	renderer->drawLine(aabb.x - aabb.halfwidth, aabb.y - aabb.halfheight, aabb.x - aabb.halfwidth, aabb.y + aabb.halfheight);
	// RIGHT
	renderer->drawLine(aabb.x + aabb.halfwidth, aabb.y - aabb.halfheight, aabb.x + aabb.halfwidth, aabb.y + aabb.halfheight);
	// TOP
	renderer->drawLine(aabb.x - aabb.halfwidth, aabb.y + aabb.halfheight, aabb.x + aabb.halfwidth, aabb.y + aabb.halfheight);
	// BOTTOM
	renderer->drawLine(aabb.x - aabb.halfwidth, aabb.y - aabb.halfheight, aabb.x + aabb.halfwidth, aabb.y - aabb.halfheight);
}

void GameManager::BulletUpdate(float deltaTime)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i]->isVisible)
		{
			for (int j = 0; j < 55; j++)
			{
				if (aliens[j]->isVisible)
				{
					if (bullets[i]->collCheck->collidesWith(*aliens[j]->collCheck))
					{
						bullets[i]->isVisible = false;
						bullets[i]->setPosition(Vector3(0, 0, 1));
						aliens[j]->die();
						m_invaderKilled->setGain(0.1);
						m_invaderKilled->play();
					}
				}
			}
		}
	}
}

void GameManager::DidILose()
{
	if (Player->amIDead())
	{
		std::cout << "lost" << std::endl;
		m_killed->setGain(0.5);
		m_killed->play();
		gameOver = true;
		GameState->setState(GameState->GameOver);
	}
}

void GameManager::PlayerTakeDamage()
{
	for (int i = 0; i < 55; i++)
	{
		if (aliens[i]->isVisible)
		{
			if (aliens[i]->collCheck->collidesWith(*Player->collCheck))
			{
				Player->takeDamage(100);
			}
		}
	}
}

void GameManager::AliensMoveDown()
{
	for (int i = 0; i < 55; i++)
	{
		if (aliens[i]->isVisible)
		{
			if (aliens[i]->Global->position.x >= 770)
			{
				for (int j = 0; j < 55; j++)
				{
					aliens[j]->Move();
				}
			}
			if (aliens[i]->Global->position.x <= 30)
			{
				for (int j = 0; j < 55; j++)
				{
					aliens[j]->Move();
				}
			}
		}
	}
}

void GameManager::AlienSpeedUp()
{
	int numberAlive = 0;
	for (int i = 0; i < 55; i++)
	{
		if (aliens[i]->isVisible)
		{
			numberAlive++;
		}
	}

	if (numberAlive <= 44 && numberAlive > 33)
	{
		for (int i = 0; i < 55; i++)
		{
			aliens[i]->setMoveSpeed(0.25f);
		}
	}
	else if (numberAlive <= 33 && numberAlive > 22)
	{
		for (int i = 0; i < 55; i++)
		{
			aliens[i]->setMoveSpeed(0.2f);
		}
	}
	else if (numberAlive <= 22 && numberAlive > 11)
	{
		for (int i = 0; i < 55; i++)
		{
			aliens[i]->setMoveSpeed(0.1f);
		}
	}
	else if (numberAlive <= 11 && numberAlive > 1)
	{
		for (int i = 0; i < 55; i++)
		{
			aliens[i]->setMoveSpeed(0.05f);
		}
	}
	else if (numberAlive <= 1)
	{
		for (int i = 0; i < 55; i++)
		{
			aliens[i]->setMoveSpeed(0.01f);
		}
	}

}

void GameManager::CheckWon()
{
	int alienDeathCount = 0;

	for (int i = 0; i < 55; i++)
	{
		if (!aliens[i]->isVisible)
		{
			alienDeathCount++;
		}
	}

	if (alienDeathCount == 55)
	{
		won = true;
	}
}