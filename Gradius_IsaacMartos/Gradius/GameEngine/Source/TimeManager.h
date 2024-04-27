#pragma once
#include <ctime>

class TimeManager
{
	float m_elapsedTime;
	clock_t m_lastFrameTime;
	int m_ciclosPorFrame;

public:
	TimeManager(float timePerFrame)
	{
		m_elapsedTime = 0;
		m_ciclosPorFrame = timePerFrame * CLOCKS_PER_SEC;
		m_lastFrameTime = clock();
	}

	float GetElapsedTime() const;
	bool shouldExtecuteNextFrame();
};

