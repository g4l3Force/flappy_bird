#pragma once
#include <core/StateManager.h>
#include <SFML/Graphics.hpp>

class MenuState : public IState
{
private:
	sf::Image m_playImage;
	sf::Texture m_playTexture;
	sf::Sprite m_playButton;

	sf::Image m_hightScoreImage;
	sf::Texture m_highScoreTexture;
	sf::Sprite m_highScoreButton;

	sf::Texture m_backgroundTexture;
	sf::Sprite m_backgroundSprite;

	sf::Vector2i m_windowPos;

public:
	// Inherited via IState
	virtual void init() override;
	virtual void handleInput() override;
	virtual void update(float deltaTime) override;
	virtual void draw(sf::RenderWindow& window) override;
	virtual void onPushState() override;
	virtual void onPopState() override;
};

