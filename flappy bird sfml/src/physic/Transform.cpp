#include "Transform.h"
#include <core/Log.h>
#include <core/Configure.h>

sf::Vector2f Transform::move(float deltaTime)
{
	this->deltaTime = deltaTime;
	if (m_jumpPoint.y - m_point.y >= 65) {
		m_jumpPoint = sf::Vector2f(0, 1000);
		moveDown(MOVE_SPEED * 1.2);
	}
	else {
		moveUp(MOVE_SPEED);
	}
	return m_point;
}

void Transform::addForce(sf::Vector2f force)
{
	//combine force
	m_acceleration += force;

	//float acceleration = force / 1; // a = f/m
	//m_distance = 0.5f * (deltaTime * deltaTime * force);
	//m_point.y -= m_distance;
}

void Transform::calculateVelocity()
{

}

void Transform::setJumpVelocity(float velocity, float distanceJump)
{
	m_jumpPoint = m_point;
	moveUp(3.0f);
}

void Transform::moveUp(float velocity)
{
	m_velocity.y = -velocity;
	m_point += m_velocity * deltaTime;
}

void Transform::moveDown(float velocity)
{
	m_velocity.y = velocity;
	m_point += m_velocity * deltaTime;
}

sf::Vector2f Transform::getVelocity()
{
	return m_velocity;
}