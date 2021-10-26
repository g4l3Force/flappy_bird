#include "SplashState.h"
#include "MenuState.h"
#include <core/StateManager.h>
#include <SFML/Graphics.hpp>

StateManager* StateManager::s_instance = nullptr;

void SplashState::init()
{
	m_texture.loadFromFile("assets\\splashscreen.png");
	m_sprite.setTexture(m_texture);
	m_time = 0.0f;
}

void SplashState::handleInput()
{
}

void SplashState::update(float deltaTime)
{
	//printf("splash update\n");
	if (m_time > 1)
	{
		onPopState();
		m_sprite.move(8, 4);
	}
	if (m_time > 3)
	{
		StateManager::instance().pushBack(std::make_shared<MenuState>());
	}
	m_time += deltaTime;
}

void SplashState::draw(sf::RenderWindow& window)
{
	//printf("splash draw\n");
	window.draw(m_sprite);
}

void SplashState::onPushState()
{

}

void SplashState::onPopState()
{

}
