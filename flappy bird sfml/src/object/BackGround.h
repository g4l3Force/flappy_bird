#pragma once
#include "Unmovable.h"
#include <list>
#include <string>

class BackGround : public Unmovable
{
private:
	std::list<sf::Sprite> m_falcon;
	float m_time;
	int falcon_count;
	float m_moveSpeed;
public:
	void init() override;
	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window) override;
	void moveHorizontal(float speed, float deltaTime) override;
	void spawn();
	void set(std::string filePath, float moveSpeed);
};

