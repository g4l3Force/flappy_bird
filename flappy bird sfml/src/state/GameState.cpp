#include "GameState.h"
#include <core/Log.h>
#include <SFML/Main.hpp>
#include <core/App.h>
#include <physic/Collision.h>
#include "ReplayState.h"

void GameState::init()
{
	m_gameTime = 0;
	m_score = 0;

	m_bird = std::make_shared<Bird>();
	m_ground = std::make_shared<Ground>();
	m_pipe = std::make_shared<Pipe>();

	m_bird->init();
	m_ground->init();
	m_pipe->init();

	Collision::instance().init();

}


void GameState::handleInput()
{
	m_bird->handleInput();
}

void GameState::update(float deltaTime)
{
	m_gameTime += deltaTime;
	m_bird->update(deltaTime);
	m_ground->update(deltaTime);
	m_pipe->update(deltaTime);
	Collision::instance().addBird(m_bird, sf::FloatRect(0, -10, 65, 55));
	Collision::instance().addPipe(m_pipe, sf::FloatRect(0, 0, 91, 450));
	int collided = Collision::instance().birdCollision(deltaTime);
	if (collided == 1)
		StateManager::instance().pushBack(std::make_shared< ReplayState>());
	else if (collided == 2) {
		m_score++;
		LOG(m_score);
	}
}

void GameState::draw(sf::RenderWindow& window)
{
	window.clear(sf::Color::White);
	Collision::instance().draw(window);
	m_pipe->draw(window);
	m_ground->draw(window);
	m_bird->draw(window);
}

void GameState::onPushState()
{
}

void GameState::onPopState()
{
}
