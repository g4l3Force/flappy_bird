#include "Physic.h"
#include <core/Log.h>

void Physic::update(float deltaTime)
{
	m_pos = m_sprite.getPosition();

	m_pos = m_transform.move(deltaTime);

	m_sprite.setPosition(m_pos);

	if (m_transform.getVelocity().y < 0) {
		m_sprite.rotate(-3);
	}
	else {
		m_sprite.rotate(3);
	}
	int angle = 15;
	if (m_sprite.getRotation() > angle && m_sprite.getRotation() < 100) m_sprite.setRotation(angle);
	else if (m_sprite.getRotation() < 360 - angle && m_sprite.getRotation() > 100) m_sprite.setRotation(360 - angle);
}

void Physic::addForce(float force)
{
	//m_transform.addForce(force);
	m_transform.setJumpVelocity(70, 40);
}

void Physic::move(float deltaTime)
{

}

void Physic::setPos(float x, float y)
{
	
}
