#include "StateManager.h"
#include "Log.h"
#include <algorithm>
#include <iostream>

void StateManager::pushBack(const std::shared_ptr<IState>& state)
{
	LOG("StateManager pushBack");
	m_state.push_back(state);
	m_state.back()->init();
}

void StateManager::popBack()
{
	LOG("StateManager popBack");
	m_state.pop_back();
}

void StateManager::popFront()
{
	LOG("StateManager popFront");
	m_state.pop_front();
}

std::shared_ptr<IState> StateManager::getState()
{
	return m_state.back();
}

void StateManager::update(float deltaTime)
{
	m_state.back().get()->update(deltaTime);
}

void StateManager::draw(sf::RenderWindow& window)
{
	m_state.back().get()->draw(window);
}

void StateManager::handleInput()
{
	m_state.back().get()->handleInput();
}


