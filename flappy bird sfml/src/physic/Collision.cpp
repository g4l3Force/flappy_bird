#include "Collision.h"
#include <SFML/Graphics.hpp>
#include <core/Configure.h>
#include <algorithm>

Collision* Collision::s_instance = nullptr;

void Collision::init() 
{
	timeCheck = 0;

	noCollided = 0;

	// set zone collision
	m_zoneCollider.left = SCREEN_WIDTH / 2 - 50;
	m_zoneCollider.top = 2;
	m_zoneCollider.width = SCREEN_WIDTH / 2;
	m_zoneCollider.height = SCREEN_HEIGHT - 30;
	m_shapeZoneCollider = setShape(m_zoneCollider, sf::Color::Cyan);

	m_screenCollider.left = SCREEN_WIDTH / 2 - 48;
	m_screenCollider.top = 2;
	m_screenCollider.width = SCREEN_WIDTH;
	m_screenCollider.height = SCREEN_HEIGHT - 30;
	m_shapeScreeCollider = setShape(m_screenCollider, sf::Color::Magenta);

	clearCollision();

	previousScore = 0;
}

bool Collision::boxCollision(sf::FloatRect rect1, sf::FloatRect rect2)
{
	return (rect1.left <= rect2.left + rect2.width &&
		rect1.left + rect1.width >= rect2.left &&
		rect1.top <= rect2.top + rect2.height &&
		rect1.height + rect1.top >= rect2.top) ? true : false;

	//return (rect1.left < rect2.left + rect2.width &&
	//	rect1.left + rect1.width > rect2.left &&
	//	rect1.top < rect2.left + rect2.height &&
	//	rect1.top + rect1.height > rect2.left) ? true : false;
}

void Collision::addPipe(std::shared_ptr<Pipe> pipe, sf::FloatRect collider)
{
	int count = 0;
	for (auto sprite : pipe->getListSprite()) {
		if (count % 2 == 0) { // bottom pipe and score zone
			{ // bottom pipe
				sf::FloatRect rect;
				rect.left = sprite.getPosition().x + collider.left;
				rect.top = sprite.getPosition().y + collider.top;
				rect.width = collider.width;
				rect.height = collider.height;
				m_ColliderRects.push_back(rect);

				m_Shapes.push_back(setShape(rect, sf::Color::Green));
			}

			{ // score zone
				sf::FloatRect scoreRect;
				scoreRect.left = sprite.getPosition().x + collider.left + collider.width/2;
				scoreRect.top = sprite.getPosition().y + collider.top - PIPE_VERTICAL_DISTANCE;
				scoreRect.width = collider.width / 4;
				scoreRect.height = PIPE_VERTICAL_DISTANCE;
				m_ScoreZones.push_back(scoreRect);

				m_Shapes.push_back(setShape(scoreRect, sf::Color::Green));
			}
		}
		else { // top pipe
			sf::FloatRect rect;
			rect.left = sprite.getPosition().x + collider.left;
			rect.top = sprite.getPosition().y + collider.top - collider.height;
			rect.width = collider.width;
			rect.height = collider.height;
			m_ColliderRects.push_back(rect);

			m_Shapes.push_back(setShape(rect, sf::Color::Green));
		}
		count++;
	}
}

void Collision::addBird(std::shared_ptr<Bird> bird, sf::FloatRect collider)
{
	m_birdCollider.left = bird->getSprite().getPosition().x + collider.left;
	m_birdCollider.top = bird->getSprite().getPosition().y + collider.top;
	m_birdCollider.width = collider.width;
	m_birdCollider.height = collider.height;

	m_birdShape = setShape(m_birdCollider, sf::Color::Magenta);
}

void Collision::draw(sf::RenderWindow& window)
{
	window.draw(m_shapeZoneCollider);
	//window.draw(m_shapeScreeCollider);
	window.draw(m_birdShape);
	for (auto& shape : m_Shapes) {
		window.draw(shape);
	}
	for (auto& shape : m_Shape) {
		window.draw(shape);
	}
	clearRect();
}

void Collision::clearRect()
{
	m_Shapes.clear();
	m_ColliderRects.clear();
	m_ScoreZones.clear();

}

void Collision::clearCollision()
{
	m_ColliderRect.clear();
	m_ScoreZone.clear();
	m_Shape.clear();
}

int Collision::birdCollision(float deltaTime)
{
	int pipecount = 0;
	int scorecount = 0;
	timeCheck += deltaTime;
	if (timeCheck > 0.1)
	{
		clearCollision();
		for (auto& pipeRect : m_ColliderRects) {
			if (boxCollision(m_zoneCollider, pipeRect)) {
				++pipecount;
				m_ColliderRect.push_back(pipeRect);
				m_Shape.push_back(setShape(pipeRect, sf::Color::Magenta));
			}
		}
		for (auto& scoreRect : m_ScoreZones) {
			if (boxCollision(m_zoneCollider, scoreRect)) {
				++scorecount;
				m_ScoreZone.push_back(scoreRect);
				m_Shape.push_back(setShape(scoreRect, sf::Color::Magenta));
			}
		}
		//LOG("pipe: ", pipecount);
		//LOG("score: ", scorecount);
		timeCheck = 0;
	
		// pipe collision
		for (auto& pipeRect : m_ColliderRect) {
			if (boxCollision(m_birdCollider, pipeRect)) {
				//LOG("collided!!!!!!!!!!!");
				return 1;
			}
			else noCollided = 0;
		}
		if (!boxCollision(m_birdCollider, m_zoneCollider)) {
			//LOG("collided!!!!!!!!!!!");
			return 1;
		}
		else noCollided = 0;
	
		//score collision
		for (auto scoreRect = m_ScoreZone.begin(); scoreRect != m_ScoreZone.end(); scoreRect++)
		{
			if (boxCollision(m_birdCollider, *scoreRect)) {
				//LOG("collided score + 1"); 
				isScore = 2;
				if (isScore != previousScore) score = 2;
				else score = 0;
				previousScore = isScore;
				return score;
			}
			else {
				noCollided = 0;
				previousScore = 0;
			}
		}
	}

	return noCollided;
}

