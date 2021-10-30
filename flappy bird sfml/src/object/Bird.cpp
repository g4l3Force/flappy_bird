#include "Bird.h"
#include <core/App.h>

void Bird::init()
{
	m_currentEventState = false;
	m_previousEventState = false;
	m_isPress = false;

	m_image.loadFromFile("assets\\bird1.png");
	m_image.createMaskFromColor(sf::Color::White);
	m_texture.loadFromImage(m_image);
	m_sprite.setTexture(m_texture);

	//m_physic = std::make_shared<Physic>(m_Sprite,
	//								m_Sprite.getPosition().x,
	//								m_Sprite.getPosition().y);
	m_physic = std::make_shared<Physic>(m_sprite);
}

//  1     2    3     4      5     6    7     8;
//false false true  true  true  true  false false;
//false false true  false false false true  false;
// 
//1 == 2 return false;
//2 != 3 return true;
//3 == 4 return false;

void Bird::handleInput()
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
			//m_Sprite.move(0, -3);
			//m_Sprite.setPosition(0, 0);
			m_physic->addForce(4.0f);
			//m_physic->setPos(50.0f, 20.0f);
			LOG("SPACE");
		}
	}
}

void Bird::update(float deltaTime)
{
	//m_Sprite.move(0, 1);
	m_physic->update(deltaTime);
	//m_animation->update();
}

void Bird::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}
