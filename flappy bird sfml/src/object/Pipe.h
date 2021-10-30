#pragma once
#include "Unmovable.h"
#include <core/Configure.h>
#include <random>
#include <list>

// https://stackoverflow.com/questions/34126262/use-random-in-a-c-class
class Pipe : public Unmovable
{
private:
	std::random_device rd;
	typedef std::mt19937 MyRng;
	MyRng rng;
	std::uniform_int_distribution<int> dice;

	std::list<sf::Sprite> m_pipe;
	float m_time;
	int pipe_count;
public:
	Pipe() : rng(rd()), dice(std::uniform_int_distribution<>(200, SCREEN_HEIGHT - 200)) {
		rng.seed(::time(NULL));
	}

	void init() override;
	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window) override;
	void moveHorizontal(float speed, float deltaTime) override;
	int randomPipe();
	void spawn();
	std::list<sf::Sprite> getListSprite() { return m_pipe; }
};

