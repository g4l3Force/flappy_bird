#pragma once
#include <SFML/Audio.hpp>
#include <core/StateManager.h>
#include <object/Bird.h>
#include <object/Pipe.h>
#include <object/Ground.h>
#include <graphic/Animation.h>
#include <object/BackGround.h>

class GameState : public IState
{
private:
	std::shared_ptr<Bird> m_bird;
	std::shared_ptr<Ground> m_ground;
	std::shared_ptr<Pipe> m_pipe;
	std::shared_ptr<BackGround> m_falcon;
	std::shared_ptr<BackGround> m_tree;

	float m_gameTime;
	int m_score;

	bool GAME_OVER;
	sf::Image m_replayImage;
	sf::Texture m_replayTexture;
	sf::Sprite m_replaySprite;
	sf::Vector2i m_windowPos;
	sf::RectangleShape m_gameOverBackGround;

	sf::Font m_fontScore;
	sf::Text m_textScore;

	sf::SoundBuffer m_pointBuffer;
	sf::Sound m_pointSound;

public:
	// Inherited via IState
	virtual void init() override;
	virtual void handleInput() override;
	virtual void update(float deltaTime) override;
	virtual void draw(sf::RenderWindow& window) override;
	virtual void onPushState() override;
	virtual void onPopState() override;
	void print() { printf("%i", m_score); }
	void restart();
};

