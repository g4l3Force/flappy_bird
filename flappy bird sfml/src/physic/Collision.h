#pragma once
#include <object/Bird.h>
#include <object/Pipe.h>
#include <object/Object.h>
#include <map>

class Collision
{
private:
	Collision() {}
	static Collision* s_instance;

	std::vector<sf::RectangleShape> m_Shapes;
	std::vector<sf::FloatRect> m_ColliderRects;
	std::vector<sf::FloatRect> m_ScoreZones;

	sf::FloatRect m_birdCollider;
	sf::RectangleShape m_birdShape;

	// (time > 2) => check zonecollider
	// => store m_Shapes, m_ScoreZones from m_Shape and m_ScoreZone
	// => checkcollision m_Shape and m_ScoreZone
	sf::FloatRect m_zoneCollider;
	sf::RectangleShape m_shapeZoneCollider;
	std::vector<sf::RectangleShape> m_Shape;
	std::vector<sf::FloatRect> m_ColliderRect;
	std::vector<sf::FloatRect> m_ScoreZone;
	float timeCheck;

	sf::FloatRect m_screenCollider;
	sf::RectangleShape m_shapeScreeCollider;

	int noCollided;

	int isScore;
	int previousScore;
	int score;
public:
	static Collision& instance()
	{
		if (s_instance == nullptr) s_instance = new Collision();
		return *s_instance;
	}

	void init();

	bool boxCollision(sf::FloatRect rect1 , sf::FloatRect rect2);

	void addBird(std::shared_ptr<Bird> bird, sf::FloatRect collider);
	void addPipe(std::shared_ptr<Pipe> pipe, sf::FloatRect collider);

	// return 1 : replay
	//        2 : score + 1
	//        0 : no collider
	int birdCollision(float deltaTime);
	void draw(sf::RenderWindow& window);

private:
	sf::RectangleShape setShape(sf::FloatRect rect, const sf::Color& color = sf::Color::Black)
	{
		sf::RectangleShape shape;
		shape.setFillColor(sf::Color(255, 255, 255, 0));
		shape.setOutlineColor(color);
		shape.setOutlineThickness(2);
		shape.setPosition(rect.left, rect.top);
		shape.setSize(sf::Vector2f(rect.width, rect.height));
		return shape;
	}
	
	void clearCollision(); //clear all collision in birdCollision

public:
	void clearRect(); // clear all rect and shape
	bool mouseCollision(sf::Vector2i mousePosition, float x1, float x2, float y1, float y2)// 1 < 2
	{
		if (mousePosition.x > x1 && mousePosition.x < x2 && mousePosition.y > y1 && mousePosition.y < y2)
		{
			return true;
		}
		else return false;
	}
};
