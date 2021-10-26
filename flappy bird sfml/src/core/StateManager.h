#pragma once
#include <list>
#include <memory>
#include <SFML/Graphics.hpp>

class IState
{
private:

public:
	virtual void init() = 0;
	virtual void handleInput() = 0;
	virtual void update(float deltaTime) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void onPushState() = 0;
	virtual void onPopState() = 0;
};

class StateManager
{
private:
	std::list<std::shared_ptr<IState>> m_state;
	static StateManager* s_instance;
	StateManager() {}
public:
	static StateManager& instance()
	{
		if (s_instance == nullptr) s_instance = new StateManager();
		return *s_instance;
	}

	void pushBack(const std::shared_ptr<IState>& state);
	void popBack();
	void popFront();
	std::shared_ptr<IState> getState();
	void update(float deltaTime);
	void draw(sf::RenderWindow& window);
	void handleInput();
};

