#pragma once
#include <SFML/Graphics.hpp>

class Transform
{
private:
	float m_distance;
	sf::Vector2f m_acceleration;
	sf::Vector2f m_velocity;
	sf::Vector2f m_point;
	sf::Vector2f m_jumpPoint;
	float deltaTime;
public:
	Transform(sf::Vector2f point) : m_point(point), m_distance(0), deltaTime(0), m_jumpPoint(0, 1000){ }
	Transform(float x, float y) : m_point(x, y), m_distance(0), deltaTime(0), m_jumpPoint(0, 1000) { }

	sf::Vector2f move(float deltaTime);
	void addForce(sf::Vector2f force);
	void calculateVelocity();

	void setJumpVelocity(float velocity, float distanceJump);
	void moveUp(float velocity);
	void moveDown(float velocity);
	sf::Vector2f getVelocity();
};
