#pragma once
#include "Unmovable.h"
#include <list>

class Ground : public Unmovable
{
private:
	std::list<sf::Sprite> m_grounds;
	int m_count;
public:
	void init() override;
	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window) override;
	void moveHorizontal(float speed, float deltaTime) override;

	// count is the number of sprite
	void setScroll(int count);
	void spawn();
};

