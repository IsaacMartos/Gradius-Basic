#pragma once
#include "DrawEngine.h"
#include "TimeManager.h"

class GameEngine
{
protected:
	DrawEngine *drawEngine;
	TimeManager *timeManager;
	bool executeNextFrame;

public:
	GameEngine(int boardSizeX, int boardSizeY, float timePerFrame)
	{
		timeManager = new TimeManager(timePerFrame);
		drawEngine = new DrawEngine(boardSizeX, boardSizeY);
		executeNextFrame = true;
	}

	~GameEngine()
	{
		delete timeManager;
		delete drawEngine;
	}

	void updateEngine();

	virtual void update() = 0;
	virtual void draw() = 0;
};

