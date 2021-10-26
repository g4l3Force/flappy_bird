#include "GameState.h"
#include <core/Log.h>
#include <SFML/Main.hpp>
#include <core/App.h>

void GameState::init()
{
	m_currentEventState = false;
	m_previousEventState = false;
	m_isPress = false;

	m_birdImage.loadFromFile("assets\\bird1.png");
	m_birdImage.createMaskFromColor(sf::Color::White);
	m_pipeImage.loadFromFile("assets\\pipe.png");
	m_pipeImage.createMaskFromColor(sf::Color::White);

	m_birdTexture.loadFromImage(m_birdImage);
	m_pipeTexture.loadFromImage(m_pipeImage);

	m_birdSprite.setTexture(m_birdTexture);
	m_pipeSprite.setTexture(m_pipeTexture);

	m_pipeSprite.setPosition(100, 300);
}

//  1     2    3     4      5     6    7     8;
//false false true  true  true  true  false false;
//false false true  false false false true  false;
// 
//1 == 2 return false;
//2 != 3 return true;
//3 == 4 return false;

void GameState::handleInput()
{
	m_currentEventState = App::isPress;
	if (m_currentEventState != m_previousEventState && 
		m_currentEventState == true) m_isPress = true;
	else m_isPress = false;
	m_previousEventState = m_currentEventState;

	if (m_isPress)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			//m_birdSprite.move(0, -3);
			m_birdSprite.setPosition(0, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			m_birdSprite.move(-2, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			m_birdSprite.move(2, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			m_birdSprite.move(0, -3);
		}
	}
}

void GameState::update(float deltaTime)
{
	m_birdSprite.move(0, 1);
	//printf("game update\n");
	bird.update(deltaTime);
}

void GameState::draw(sf::RenderWindow& window)
{
	//printf("game draw\n");
	window.draw(m_pipeSprite);
	window.draw(m_birdSprite);
}

void GameState::onPushState()
{
}

void GameState::onPopState()
{
}
