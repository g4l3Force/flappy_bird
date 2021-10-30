#pragma once
#include <core/StateManager.h>
#include <object/Bird.h>
#include <object/Pipe.h>
#include <object/Ground.h>

class GameState : public IState
{
private:
	std::shared_ptr<Bird> m_bird;
	std::shared_ptr<Ground> m_ground;
	std::shared_ptr<Pipe> m_pipe;
	float m_gameTime;
	int m_score;

public:
	// Inherited via IState
	virtual void init() override;
	virtual void handleInput() override;
	virtual void update(float deltaTime) override;
	virtual void draw(sf::RenderWindow& window) override;
	virtual void onPushState() override;
	virtual void onPopState() override;
	void print() { printf("%i", m_score); }
};

