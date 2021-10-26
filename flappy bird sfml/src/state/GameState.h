#pragma once
#include <core/StateManager.h>
#include <object/Bird.h>

class GameState : public IState
{
private:
	sf::Image m_birdImage;
	sf::Texture m_birdTexture;
	sf::Sprite m_birdSprite;

	sf::Image m_pipeImage;
	sf::Texture m_pipeTexture;
	sf::Sprite m_pipeSprite;

	bool m_currentEventState;
	bool m_previousEventState;
	bool m_isPress;
	
public:
	// Inherited via IState
	virtual void init() override;
	virtual void handleInput() override;
	virtual void update(float deltaTime) override;
	virtual void draw(sf::RenderWindow& window) override;
	virtual void onPushState() override;
	virtual void onPopState() override;
};

