#include "App.h"
#include <state/GameState.h>
#include <state/SplashState.h>
#include "Log.h"
#include "StateManager.h"


App::App() 
{
	m_window = std::make_shared<sf::RenderWindow>();
}

App::~App()
{

}

void App::run()
{
	StateManager::instance().pushBack(std::make_shared<GameState>());
	//m_stateManager->pushBack(std::make_shared<GameState>());
	//m_stateManager->pushBack(std::make_shared<SplashState>());

	m_window->create(sf::VideoMode(800, 600), "flappy bird", sf::Style::Close);
	m_window->setVerticalSyncEnabled(true);

	while (m_window->isOpen()) {
		sf::Event event;
		while (m_window->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				m_window->close();
			}
		}
		
		m_time.calculateDeltaTime();
		//m_stateManager->update(m_time.getDeltaTime());
		//m_stateManager->getState().get()->update(m_time.getDeltaTime());
		draw();
		LOG("deltaTime: ", m_time.getDeltaTime(), "bird");
	}
}

void App::input() 
{

}

void App::update() 
{

}

void App::draw() 
{
	m_window->clear(sf::Color::White);
	//m_stateManager->draw(*m_window.get());
	m_window->display();
}