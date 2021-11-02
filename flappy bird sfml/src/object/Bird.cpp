#include "Bird.h"
#include <core/App.h>
#include <core/Configure.h>

void Bird::init()
{
	m_currentEventState = false;
	m_previousEventState = false;
	m_isPress = false;
	m_animationTime = 0;
	m_birdState = BirdState::NONE;

	// animation
	bird1Image.loadFromFile("assets\\bird1.png");
	bird1Image.createMaskFromColor(sf::Color::White);
	bird1Texture.loadFromImage(bird1Image);
	bird1Sprite.setTexture(bird1Texture);
	bird1Sprite.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

	bird2Image.loadFromFile("assets\\bird2.png");
	bird2Image.createMaskFromColor(sf::Color::White);
	bird2Texture.loadFromImage(bird2Image);
	bird2Sprite.setTexture(bird2Texture);
	bird2Sprite.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

	bird3Image.loadFromFile("assets\\bird3.png");
	bird3Image.createMaskFromColor(sf::Color::White);
	bird3Texture.loadFromImage(bird3Image);
	bird3Sprite.setTexture(bird3Texture);
	bird3Sprite.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	
	bird4Image.loadFromFile("assets\\bird4.png");
	bird4Image.createMaskFromColor(sf::Color::White);
	bird4Texture.loadFromImage(bird4Image);
	bird4Sprite.setTexture(bird4Texture);
	bird4Sprite.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

	birdSprite.push_back(bird1Sprite);
	birdSprite.push_back(bird2Sprite);
	birdSprite.push_back(bird3Sprite);
	birdSprite.push_back(bird4Sprite);
	birdSprite.push_back(bird2Sprite);
	animation.setAnimation(birdSprite, 0.1);
	animation.stop();

	// bird sound
	m_wingBuffer.loadFromFile("assets\\wing.wav");
	m_wingSound.setBuffer(m_wingBuffer);
	m_dieBuffer.loadFromFile("assets\\die.wav");
	m_dieSound.setBuffer(m_dieBuffer);
}

//  1     2    3     4      5     6    7     8;
//false false true  true  true  true  false false;
//false false true  false false false true  false;
// 
//1 == 2 return false;
//2 != 3 return true;
//3 == 4 return false;

void Bird::handleInput()
{
	m_currentEventState = App::isPress;
	if (m_currentEventState != m_previousEventState &&
		m_currentEventState == true) m_isPress = true;
	else m_isPress = false;
	m_previousEventState = m_currentEventState;

	if (m_isPress)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			//LOG("SPACE");
			m_birdState = BirdState::FLY;
			m_animationTime = 0;
			animation.reset();
			animation.start();
			m_wingSound.play();
		}
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		m_birdState = BirdState::FLY;
		m_animationTime = 0;
		animation.reset();
		animation.start();
		m_wingSound.play();
	}
}

void Bird::update(float deltaTime)
{
	animation.update(deltaTime);

	if (m_birdState == BirdState::FLY) {
		m_animationTime += deltaTime;
		if (m_animationTime > 0.3f) {
			m_birdState = BirdState::FALL;
			//LOG("FALL");
		}
	}
	else if (m_birdState == BirdState::FALL) {
		animation.stop();
	}
	else if (m_birdState == BirdState::NONE) {
		animation.start();
	}
	else if (m_birdState == BirdState::DIE) {
		animation.stop();
	}
	for (auto& sprite : animation.getVecSprite()) {
		Physic(sprite, deltaTime);
	}
}

void Bird::draw(sf::RenderWindow& window)
{
	window.draw(animation.getAnimation());
}

void Bird::die()
{
	m_dieSound.play();
	m_birdState = BirdState::DIE;
}

void Bird::Physic(sf::Sprite& sprite, float deltaTime)
{
	// move
	if (m_birdState == BirdState::FALL) {
		sprite.move(0, MOVE_SPEED * 1.2 * deltaTime);
		sprite.rotate(3);
	}
	else if (m_birdState == BirdState::FLY) {
		sprite.move(0, -MOVE_SPEED * deltaTime);
		sprite.rotate(-3);
	}
	else if (m_birdState == BirdState::DIE) {
		sprite.move(0, 2 * MOVE_SPEED * deltaTime);
		sprite.rotate(5);
	}

	// rotate
	int angle = 15;
	if (m_birdState == BirdState::DIE) angle = 40;
	if (sprite.getRotation() > angle && sprite.getRotation() < 100) sprite.setRotation(angle);
	else if (sprite.getRotation() < 360 - angle && sprite.getRotation() > 100) sprite.setRotation(360 - angle);
	
	m_sprite = sprite;
}

