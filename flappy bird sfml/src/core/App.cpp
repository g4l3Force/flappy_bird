#include "App.h"
#include <state/GameState.h>
#include <state/SplashState.h>
#include "Log.h"
#include "StateManager.h"
#include <core/Configure.h>

bool App::isPress = false;

App::App() 
{
	m_window = std::make_shared<sf::RenderWindow>();
}

App::~App()
{

}

void App::run()
{
	StateManager::instance().pushBack(std::make_shared<SplashState>());


	m_window->create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "flappy bird", sf::Style::Close);
	m_window->setVerticalSyncEnabled(true);

	while (m_window->isOpen()) {
		//if (m_window->hasFocus())
		{
			input();
		}
		draw();
		StateManager::instance().update(m_time.calculateDeltaTime());
	}

}

void App::input() 
{
	while (m_window->pollEvent(m_event)) {
		if (m_event.type == sf::Event::Closed) {
			m_window->close();
		}
		if (m_event.type == sf::Event::KeyPressed) {
			if (!isPress) {
				isPress = true;
				//LOG(isPress);
			}
		}
		if (m_event.type == sf::Event::KeyReleased)
		{
			isPress = false;
			//LOG(isPress);
		}
	}
	if (m_window->hasFocus())
		StateManager::instance().handleInput();	
}

void App::update() 
{

}

void App::draw() 
{
	StateManager::instance().draw(*m_window.get());
	m_window->display();
}