#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Animation
{
private:
	enum class AnimationState {RUN = 0, STOP, RESET};
	int maxAnimation;
	std::vector<sf::Sprite> m_vecSprite;
	float m_timeBetween2Animation;
	float m_time;
	int m_animationCount;
	int m_stopAnimation;
	AnimationState m_animationState;
public:
	Animation() : m_time(0), m_timeBetween2Animation(0),
		m_animationCount(0), maxAnimation(0), m_stopAnimation(0){}
	void setAnimation(const std::vector<sf::Sprite>& sprite, float timeBetween2Animation);
	void setTime(float deltaTime);
	sf::Sprite getAnimation();
	void start();
	void stop();
	void resume();
	void reset();
	void update(float deltaTime);
	std::vector<sf::Sprite>& getVecSprite();
};

