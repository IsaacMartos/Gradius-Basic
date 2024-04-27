#include "Enemigo.h"

void Enemigo::BeginPlay()
{
}

void Enemigo::Tick()
{
	Move();
}

void Enemigo::Move()
{
	prevPosX = posX;
	posX -= 1;
}

void Enemigo::SetRandomCharacter()
{
	std::srand(std::time(nullptr));
	int randomNumber = std::rand() % 94 + 33;
	actorRepresentation = static_cast<char>(randomNumber);
}
