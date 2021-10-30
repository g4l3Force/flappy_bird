#pragma once
#include <core/StateManager.h>
#include <SFML/Graphics.hpp>

class ReplayState : public IState
{
private:
	sf::Image m_replayImage;
	sf::Texture m_replayTexture;
	sf::Sprite m_replaySprite;

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

