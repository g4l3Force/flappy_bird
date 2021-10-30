#include "Ground.h"
#include <core/Configure.h>
#include <core/Log.h>

void Ground::init()
{
	m_image.loadFromFile("assets\\ground.png");
	m_image.createMaskFromColor(sf::Color::White);
	m_texture.loadFromImage(m_image);
	m_sprite.setTexture(m_texture);
	setScroll(3);
}

void Ground::update(float deltaTime)
{
	if (m_grounds.size() == 0) spawn();
	else if (m_grounds.back().getPosition().x + m_grounds.back().getTextureRect().width < SCREEN_WIDTH) {
		spawn();
	}

	if (m_grounds.size() > m_count) {
		m_grounds.pop_front();
	}

	moveHorizontal(MOVE_SPEED, deltaTime);
}

void Ground::draw(sf::RenderWindow& window)
{
	for (auto& ground : m_grounds) {
		window.draw(ground);
	}
}

void Ground::moveHorizontal(float speed, float deltaTime)
{
	for (auto& ground : m_grounds) {
		ground.move(-speed * deltaTime, 0);
	}
}

void Ground::setScroll(int count)
{
	m_count = count;
}

void Ground::spawn()
{
	if (m_grounds.size() == 0) { 
		m_sprite.setPosition(0, SCREEN_HEIGHT - 80);
	}
	else {
		m_sprite.setPosition(m_grounds.back().getPosition().x + m_grounds.back().getTextureRect().width, SCREEN_HEIGHT - 80);
	}
	m_grounds.push_back(m_sprite);
}
