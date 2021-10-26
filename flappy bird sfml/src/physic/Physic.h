#pragma once
#include "Transform.h"
#include <memory>
#include <SFML/Graphics.hpp>
#include <core/Configure.h>

class Physic
{
private:
	Transform m_transform;
	sf::Sprite& m_sprite;
	sf::Vector2f m_pos;
public:
	//Physic(sf::Sprite& sprite, float x, float y) : m_transform(x, y), m_sprite(sprite) { }
	//Physic(sf::Vector2i vec2) : m_transform(vec2.x, vec2.y) { }
	Physic(sf::Sprite& sprite) : m_sprite(sprite), m_transform(SCREEN_WIDTH/2, SCREEN_HEIGHT/2) { }
	void update(float deltaTime);
	void move(float deltaTime);
	void addForce(float force);
	void setPos(float x, float y);
};