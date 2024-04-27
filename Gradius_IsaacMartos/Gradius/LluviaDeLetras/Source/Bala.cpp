#include "Bala.h"

void Bala::MoveBullet()
{
	previuosPosX = posX;
	posX += 1;
}

int Bala::GetPosX() const
{
	return posX;
}

int Bala::GetPosY() const
{
	return posY;
}

int Bala::GetPrevPosX() const
{
	return previuosPosX;
}

bool Bala::ThrowOutBullet(int limitX) const
{
	if (posX > limitX) return true;
	return false;
}
