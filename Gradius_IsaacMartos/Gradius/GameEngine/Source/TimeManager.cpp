#include "TimeManager.h"

float TimeManager::GetElapsedTime() const
{
	return m_elapsedTime;
}

bool TimeManager::shouldExtecuteNextFrame()
{
	bool m_shouldExecuteNextFrame = false;

	clock_t timeBetweenFrames = clock() - m_lastFrameTime;
	if (timeBetweenFrames >= m_ciclosPorFrame)
	{
		m_shouldExecuteNextFrame = true;
		m_lastFrameTime = clock() - (timeBetweenFrames - m_ciclosPorFrame);
	}
	m_elapsedTime = (timeBetweenFrames / CLOCKS_PER_SEC);

	return m_shouldExecuteNextFrame;
}
