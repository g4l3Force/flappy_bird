#pragma once
#include <chrono>

class Time
{
private:
	std::chrono::time_point<std::chrono::steady_clock> m_start, m_end;
	std::chrono::duration<float> m_duration;

	std::chrono::time_point<std::chrono::steady_clock> m_currentTime, m_lastTime, m_begin;
	std::chrono::duration<float> m_deltaTime;
public:
	Time();
	~Time();

	void restart();
	void startFrame();
	void endFrame();
	float getDuration();

	void calculateDeltaTime();
	float getDeltaTime();
	float getElapsed();
};

