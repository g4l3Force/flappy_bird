#include "GameState.h"
#include <core/Log.h>
#include <SFML/Main.hpp>
#include <core/App.h>
#include <physic/Collision.h>
#include <string>

void GameState::init()
{
	m_gameTime = 0;
	m_score = 0;

	m_bird = std::make_shared<Bird>();
	m_ground = std::make_shared<Ground>();
	m_pipe = std::make_shared<Pipe>();
	m_falcon = std::make_shared<BackGround>();
	m_tree = std::make_shared<BackGround>();
	m_bird->init();
	m_ground->init();
	m_pipe->init();
	m_falcon->set("falcon.png", MOVE_SPEED * 0.75);
	m_tree->set("tree.png", MOVE_SPEED * 0.45);

	Collision::instance().init();

	// game over 
	GAME_OVER = false;
	m_replayImage.loadFromFile("assets\\playbutton.png");
	m_replayImage.createMaskFromColor(sf::Color::White);
	m_replayTexture.loadFromImage(m_replayImage);
	m_replaySprite.setTexture(m_replayTexture);
	m_replaySprite.setPosition(300, 200);
	m_gameOverBackGround.setFillColor(sf::Color(82, 82, 82, 100));
	m_gameOverBackGround.setPosition(0, 0);
	m_gameOverBackGround.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));

	if (!m_fontScore.loadFromFile("assets\\rainyhearts.ttf")) {
		LOG("could not load font!");
	}
	m_textScore.setFont(m_fontScore);
	m_textScore.setCharacterSize(100);
	m_textScore.setPosition(SCREEN_WIDTH / 2 - 15, SCREEN_HEIGHT / 50);
	m_textScore.setFillColor(sf::Color::Black);
	m_textScore.setString("0");

	m_pointBuffer.loadFromFile("assets\\point.wav");
	m_pointSound.setBuffer(m_pointBuffer);
}

void GameState::restart()
{
	GAME_OVER = false;
	m_gameTime = 0;
	m_score = 0;
	m_textScore.setString("0");

	m_pipe.reset();
	m_bird.reset();
	m_bird = std::make_shared<Bird>();
	m_pipe = std::make_shared<Pipe>();
	m_bird->init();
	m_pipe->init();
}


void GameState::handleInput()
{
	if (GAME_OVER == false) {
		m_bird->handleInput();
	}
}

void GameState::update(float deltaTime)
{
	m_gameTime += deltaTime;
	m_bird->update(deltaTime);
	if (m_bird->getBirdState() != Bird::BirdState::NONE) {
		m_pipe->update(deltaTime);
	}
	m_falcon->update(deltaTime);
	m_tree->update(deltaTime);
	m_ground->update(deltaTime);
	Collision::instance().addBird(m_bird, sf::FloatRect(0, -10, 65, 55));
	Collision::instance().addPipe(m_pipe, sf::FloatRect(0, 0, 91, 450));
	int collided = Collision::instance().birdCollision(deltaTime);
	if (collided == 1) {
		GAME_OVER = true;
		m_bird->die();
		//LOG("GAME OVER\n");
	}
	else if (collided == 2) {
		m_score++;
		LOG("m_score: ", m_score);
		m_textScore.setString(std::to_string(m_score));
		m_pointSound.play();
	}

	if (GAME_OVER == true) {
		if (Collision::instance().mouseCollision(sf::Mouse::getPosition() - m_windowPos,
			300, 300 + m_replaySprite.getTextureRect().width,
			200, 200 + m_replaySprite.getTextureRect().height))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				restart();
			}
		}
	}
}

void GameState::draw(sf::RenderWindow& window)
{
	window.clear(sf::Color::White);
	m_tree->draw(window);
	m_falcon->draw(window);

#ifdef _DEBUG
	Collision::instance().draw(window);
#endif
	Collision::instance().clearRect();

	m_pipe->draw(window);
	m_ground->draw(window);
	m_bird->draw(window);
	if (GAME_OVER == true) {
		window.draw(m_gameOverBackGround);
		m_windowPos = window.getPosition();
		window.draw(m_replaySprite);
	}
	window.draw(m_textScore);
}

void GameState::onPushState()
{
}

void GameState::onPopState()
{
}
