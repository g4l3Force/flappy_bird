#include "BackGround.h"
#include <core/Configure.h>

void BackGround::init()
{
}

void BackGround::set(std::string filePath, float moveSpeed)
{
	m_moveSpeed = moveSpeed;
	m_image.loadFromFile(filePath);
	m_image.createMaskFromColor(sf::Color::White);
	m_texture.loadFromImage(m_image);
	m_sprite.setTexture(m_texture);
	m_falcon.push_back(m_sprite);
}

void BackGround::update(float deltaTime)
{
	moveHorizontal(m_moveSpeed, deltaTime);
	if (m_falcon.back().getPosition().x < 0) {
		spawn();
	}
	if (m_falcon.size() > 3) {
		m_falcon.pop_front();
	}
}

void BackGround::draw(sf::RenderWindow& window)
{
	for (auto& falcon : m_falcon)
	{
		window.draw(falcon);
	}
}

void BackGround::moveHorizontal(float speed, float deltaTime)
{
	for (auto& falcon : m_falcon)
	{
		falcon.move(-speed * deltaTime, 0);
	}
}

void BackGround::spawn()
{
	m_sprite.setPosition(m_falcon.back().getPosition().x + m_falcon.back().getTextureRect().width, 0);
	m_falcon.push_back(m_sprite);
}
