#include "MenuState.h"
#include <SFML/Graphics.hpp>
#include <core/Log.h>
#include <core/StateManager.h>
#include "GameState.h"
#include <memory>
#include <physic/Collision.h>


void MenuState::init()
{
	m_playImage.loadFromFile("assets\\playbutton.png");
	m_playImage.createMaskFromColor(sf::Color::White);
	m_hightScoreImage.loadFromFile("assets\\highscore.png");
	m_hightScoreImage.createMaskFromColor(sf::Color::White);

	m_playTexture.loadFromImage(m_playImage);
	m_highScoreTexture.loadFromImage(m_hightScoreImage);
	m_backgroundTexture.loadFromFile("assets\\background.png");
	
	m_playTexture.setSrgb(true);
	m_highScoreTexture.setSrgb(true);

	m_playButton.setTexture(m_playTexture);
	m_highScoreButton.setTexture(m_highScoreTexture);
	m_backgroundSprite.setTexture(m_backgroundTexture);
	
	m_playButton.setPosition(300, 200);
	m_highScoreButton.setPosition(300, 400);
}

void MenuState::handleInput()
{
	if (Collision::instance().mouseCollision(sf::Mouse::getPosition() - m_windowPos,
		300, 300 + m_playButton.getTextureRect().width,
		200, 200 + m_playButton.getTextureRect().height))
	{
		m_playButton.rotate(3.0);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				StateManager::instance().pushBack(std::make_shared<GameState>());
			}
	}
	else m_playButton.setRotation(0);
}

void MenuState::update(float deltaTime)
{
}

void MenuState::draw(sf::RenderWindow& window)
{
	window.clear(sf::Color::White);
	m_windowPos = window.getPosition();
	window.draw(m_backgroundSprite);
	window.draw(m_playButton);
	window.draw(m_highScoreButton);
}

void MenuState::onPushState()
{
}

void MenuState::onPopState()
{
}
