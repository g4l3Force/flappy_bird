#pragma once
#include <object/Bird.h>

class Collision
{
private:
	Collision() {}
	static Collision* s_instance;
	Bird m_bird;
	// Pipe m_pipe;
	// Ground m_gound;
public:
	static Collision& instance()
	{
		if (s_instance == nullptr) s_instance = new Collision();
		return *s_instance;
	}

	void addBird(Bird bird) {
		m_bird = bird;
	}
	//void addPipe(Pipe pipe) {
	//	m_bird = bird;
	//}
	//void addBird(Bird bird) {
	//	m_bird = bird;
	//}
	//bool checkCollision(Object object1, Object object2) {}
	//void draw() {}
	//void draw(Object object) {}
};

//collision::instance().set(bird, 0, 0, 3, 3);
//collision::instance().set(pipe, 0, 0, 4, 4);
//collision::instance().update(bird.getcollider(), pipe.getCollider());
//collision::instance().draw("bird");

