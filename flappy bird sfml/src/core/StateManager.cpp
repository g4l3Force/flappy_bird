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

std::shared_ptr<IState> StateManager::findState(std::shared_ptr<GameState> state)
{
	std::list<std::shared_ptr<IState>>::iterator l_front = m_state.begin();
	std::advance(l_front, 3);
	//std::shared_ptr<GameState> sta = std::make_shared<GameState>(l_front->get());
	//std::cout << *l_front << std::endl;
	//return std::make_shared<GameState>();
	//GameState& ptr = l_front->get();
	return std::make_shared<GameState>();
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


