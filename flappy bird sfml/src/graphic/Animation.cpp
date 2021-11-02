#include "Animation.h"
#include <core/Log.h>

void Animation::setAnimation(const std::vector<sf::Sprite>& sprite, float timeBetween2Animation)
{
	m_vecSprite = sprite;
	m_timeBetween2Animation = timeBetween2Animation;
}

void Animation::setTime(float deltaTime)
{
	m_time = deltaTime;
}

sf::Sprite Animation::getAnimation()
{
	if (m_animationState == AnimationState::RUN) {
		return m_vecSprite.at(m_animationCount);
	}
	if (m_animationState == AnimationState::STOP) {
		return m_vecSprite.at(m_stopAnimation);
	}
	if (m_animationState == AnimationState::RESET) {
		return m_vecSprite.at(0);
	}
}

void Animation::update(float deltaTime)
{
	m_time += deltaTime;
	if (m_time > m_timeBetween2Animation) {
		m_animationCount++;
		if (m_animationCount > m_vecSprite.size() - 1) {
			m_animationCount = 0;
		}
		m_time -= m_timeBetween2Animation;
		//LOG(m_animationCount);
	}
}

void Animation::start()
{
	if (m_animationState != AnimationState::RUN) {
		m_animationState = AnimationState::RUN;
	}
}

void Animation::stop()
{
	if (m_animationState != AnimationState::STOP) {
		m_animationState = AnimationState::STOP;
		m_stopAnimation = m_animationCount;
	}
}

void Animation::resume()
{
	if (m_animationState == AnimationState::STOP) {
		m_animationCount = m_stopAnimation;
		m_animationState = AnimationState::RUN;
	}
}

void Animation::reset()
{
	m_animationState = AnimationState::RUN;
	m_animationCount = 0;
}

std::vector<sf::Sprite>& Animation::getVecSprite()
{
	return m_vecSprite;
}

