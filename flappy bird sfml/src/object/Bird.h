#pragma once 
#include <SFML/Audio.hpp>
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include <core/Log.h>
#include "Object.h"
#include <graphic/Animation.h>

class Bird : public Object
{
public:
	enum class BirdState { NONE = 0, FLY, FALL, DIE };
private:
	bool m_currentEventState;
	bool m_previousEventState;
	bool m_isPress;
	float m_animationTime;
	float m_jumpTime;

	BirdState m_birdState;

	Animation animation;
	std::vector<sf::Sprite> birdSprite;
	sf::Image bird1Image;
	sf::Texture bird1Texture;
	sf::Sprite bird1Sprite;
	sf::Image bird2Image;
	sf::Texture bird2Texture;
	sf::Sprite bird2Sprite;
	sf::Image bird3Image;
	sf::Texture bird3Texture;
	sf::Sprite bird3Sprite;
	sf::Image bird4Image;
	sf::Texture bird4Texture;
	sf::Sprite bird4Sprite;

	sf::SoundBuffer m_wingBuffer;
	sf::Sound m_wingSound;
	sf::SoundBuffer m_dieBuffer;
	sf::Sound m_dieSound;

public:

	Bird() { }
	void init() override;
	void handleInput();
	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window) override;
	sf::Sprite getSprite() { return m_sprite; }
	void die();
	void Physic(sf::Sprite& sprite, float deltaTime);
	BirdState getBirdState() const { return m_birdState; }
};
