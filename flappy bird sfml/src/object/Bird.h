#pragma once 
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include <physic/Physic.h>
#include <core/Log.h>
#include "Object.h"

class Bird : public Object
{
private:
	std::shared_ptr<Physic> m_physic;

	bool m_currentEventState;
	bool m_previousEventState;
	bool m_isPress;
public:
	Bird() { }
	void init() override;
	void handleInput();
	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window) override;
};
