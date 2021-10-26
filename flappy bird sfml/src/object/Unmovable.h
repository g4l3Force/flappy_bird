#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"

class Unmovable
{
protected:
	sf::Image m_image;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
public:
	virtual void init() = 0;
	virtual void update(float deltaTime) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void moveHorizontal(float speed, float deltaTime) = 0;
};