#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "Time.h"

class App {
private:
	std::shared_ptr<sf::RenderWindow> m_window;
	Time m_time;

	void input();
	void update();
	void draw();
public:
	App();
	~App();
	void run();
};