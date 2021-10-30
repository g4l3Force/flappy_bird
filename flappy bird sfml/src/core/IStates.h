#pragma once
#include <SFML/Graphics.hpp>

class IState
{
private:

public:
	virtual void init() = 0;
	virtual void handleInput() = 0;
	virtual void update(float deltaTime) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void onPushState() = 0;
	virtual void onPopState() = 0;
};
