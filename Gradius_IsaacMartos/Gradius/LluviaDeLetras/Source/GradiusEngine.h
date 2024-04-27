#pragma once
#include <vector>
#include "Actor.h"
#include "GameEngine.h"
#include "PlayerShip.h"
#include "Enemigo.h"

class GradiusEngine : public GameEngine
{

	int currentScore;
	int record;
	int prevLastSegmentX;
	int prevLastSegmentY;

	std::vector<Actor*> actorsList;
	PlayerShip* playerShip;

	bool isGameOver;
	int screenWidth;
	int screenHeight;
	char** screenBuffer;

public:

	GradiusEngine(int _boardSizeX, int _boardSizeY, int _timePerFrame)
		: GameEngine(_boardSizeX, _boardSizeY, _timePerFrame),screenWidth(_boardSizeX), screenHeight(_boardSizeY),
					playerShip(nullptr)
	{
		Restart();
		playerShip = new PlayerShip(5, _boardSizeY / 2);
		actorsList.push_back(playerShip);
		InitializeScreenBuffer();
	}

	~GradiusEngine()
	{
		delete playerShip;
		for (Actor* actor : actorsList) {
			delete actor;
		}
		DeleteScreenBuffer();
	}

	void draw() override;
	void update() override;

	void DrawBoard();
	void DrawScore();
	void DrawAnimatedElements();
	void DrawExplosion(int xPos, int yPos);

	int GetScreenWidth() { return screenWidth; }
	int GetScreenHeight() { return screenHeight; }
	bool GetGameOverState() { return isGameOver; }

	void CheckCollisions();
	void AddActors();
	void DestroyActor(Actor* actorToDestroy);

	void InitializeScreenBuffer();
	void DeleteScreenBuffer();

	void Restart();
};

