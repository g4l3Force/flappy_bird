#include "Pipe.h"
#include <core/Log.h>

void Pipe::init()
{
	m_time = 0;

	m_image.loadFromFile("assets\\pipe.png");
	m_image.createMaskFromColor(sf::Color::White);
	m_texture.loadFromImage(m_image);
	m_sprite.setTexture(m_texture);
	//m_sprite.setPosition(SCREEN_WIDTH + 300, 300); //screen height - 100

	m_sprite.setPosition(SCREEN_WIDTH - 75, 400);
	m_pipe.push_back(m_sprite);

	m_sprite.setPosition(SCREEN_WIDTH - 75, 400 - PIPE_VERTICAL_DISTANCE);
	m_sprite.setScale(1, -1);
	m_pipe.push_back(m_sprite);
}

void Pipe::update(float deltaTime)
{
	moveHorizontal(MOVE_SPEED, deltaTime);
	if (m_time > 2)
	{
		if (m_pipe.size() < 5)
		{
			spawn();
			m_time = 0;
		}
		else 
		{
			m_pipe.pop_front();
			m_pipe.pop_front();
			LOG("delete pipe", "m_pipe.size: ", m_pipe.size());
		}
	}

	m_time += deltaTime;
}

void Pipe::draw(sf::RenderWindow& window)
{
	for (auto& pipe : m_pipe)
	{
		window.draw(pipe);
	}
}

void Pipe::moveHorizontal(float speed, float deltaTime)
{
	for (auto& pipe : m_pipe)
	{
		pipe.move(-speed * deltaTime, 0);
	}
}

int Pipe::randomPipe()
{
	return dice(rng);
}

void Pipe::spawn()
{
	int pipeHeight = randomPipe();
	LOG("spawn pipeHeight: ", pipeHeight);
	m_sprite.setPosition(SCREEN_WIDTH, pipeHeight);
	m_sprite.setScale(1, 1);
	m_pipe.push_back(m_sprite);

	m_sprite.setPosition(SCREEN_WIDTH, pipeHeight - PIPE_VERTICAL_DISTANCE);
	m_sprite.setScale(1, -1);
	m_pipe.push_back(m_sprite);
}