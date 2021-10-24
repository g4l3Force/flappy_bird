#include "Time.h"
Time::Time()
{
	m_currentTime = std::chrono::high_resolution_clock::now();
	m_lastTime = std::chrono::high_resolution_clock::now();
	m_begin = std::chrono::high_resolution_clock::now();
}


Time::~Time()
{
}

void Time::restart()
{
	m_currentTime = std::chrono::high_resolution_clock::now();
	m_lastTime = std::chrono::high_resolution_clock::now();
	m_begin = std::chrono::high_resolution_clock::now();
}

void Time::startFrame()
{
	m_start = std::chrono::high_resolution_clock::now();
}

void Time::endFrame()
{
	m_end = std::chrono::high_resolution_clock::now();
	m_duration = m_end - m_start;
}

float Time::getDuration()
{
	return m_duration.count();
}

void Time::calculateDeltaTime()
{
	m_currentTime = std::chrono::high_resolution_clock::now();
	m_deltaTime = m_currentTime - m_lastTime;
	m_lastTime = m_currentTime;
}

float Time::getDeltaTime()
{
	return m_deltaTime.count();
}

float Time::getElapsed()
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(m_currentTime - m_begin).count();
}