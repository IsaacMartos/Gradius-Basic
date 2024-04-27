#pragma once
#include "Actor.h"
#include <ctime>
#include <cstdlib>

class Enemigo : public Actor
{

public:
	Enemigo(int x, int y) : Actor(x, y, actorRepresentation)
	{
		SetRandomCharacter();
	}

	virtual void BeginPlay() override;

	virtual void Tick() override;

	void Move();

	void SetRandomCharacter();
};

