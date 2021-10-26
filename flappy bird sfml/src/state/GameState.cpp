#include "GameState.h"
#include <core/Log.h>
#include <SFML/Main.hpp>
#include <core/App.h>

void GameState::init()
{
	bird.init();
	pipe.init();
}


void GameState::handleInput()
{
	bird.handleInput();
}

void GameState::update(float deltaTime)
{
	//printf("game update\n");
	bird.update(deltaTime);
	pipe.update(deltaTime);
	//collision::instance().set(bird, 0, 0, 3, 3);
	//collision::instance().set(pipe, 0, 0, 4, 4);
	//collision::instance().update(bird.getcollider(), pipe.getCollider());
}

void GameState::draw(sf::RenderWindow& window)
{
	//printf("game draw\n");
	pipe.draw(window);
	bird.draw(window);
	//collision::instance().draw("bird");
}

void GameState::onPushState()
{
}

void GameState::onPopState()
{
}
