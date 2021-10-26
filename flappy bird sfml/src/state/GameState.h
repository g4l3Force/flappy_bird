#pragma once
#include <core/StateManager.h>
#include <object/Bird.h>
#include <object/Pipe.h>

class GameState : public IState
{
private:
	Bird bird;
	Pipe pipe;
public:
	// Inherited via IState
	virtual void init() override;
	virtual void handleInput() override;
	virtual void update(float deltaTime) override;
	virtual void draw(sf::RenderWindow& window) override;
	virtual void onPushState() override;
	virtual void onPopState() override;
};

