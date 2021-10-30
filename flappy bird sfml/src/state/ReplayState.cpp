#include "ReplayState.h"
#include <physic/Collision.h>
#include <core/StateManager.h>
#include "GameState.h"

void ReplayState::init()
{
	m_replayImage.loadFromFile("assets\\playbutton.png");
	m_replayImage.createMaskFromColor(sf::Color::White);

	m_replayTexture.loadFromImage(m_replayImage);

	m_replaySprite.setTexture(m_replayTexture);

	m_replaySprite.setPosition(300, 200);
}

void ReplayState::handleInput()
{
}

void ReplayState::update(float deltaTime)
{
	if (Collision::instance().mouseCollision(sf::Mouse::getPosition() - m_windowPos,
		300, 300 + m_replaySprite.getTextureRect().width,
		200, 200 + m_replaySprite.getTextureRect().height)) 
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
			StateManager::instance().popBack();
			StateManager::instance().popBack();
			StateManager::instance().pushBack(std::make_shared<GameState>());
		}
	}
}

void ReplayState::draw(sf::RenderWindow& window)
{
	window.clear(sf::Color::White);
	m_windowPos = window.getPosition();
	window.draw(m_replaySprite);
}

void ReplayState::onPushState()
{
}

void ReplayState::onPopState()
{
}
