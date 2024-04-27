#include "GameEngine.h"
#include <iostream>

void GameEngine::updateEngine()
{
	if (timeManager->shouldExtecuteNextFrame())
	{
		update();
		draw();
	}
}

