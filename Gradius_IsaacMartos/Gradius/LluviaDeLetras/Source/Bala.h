#pragma once

class Bala
{
	int posX, posY;
	int previuosPosX;
	char represantationChar;

public:

	Bala(int x, int y, char c): posX(x), posY(y), previuosPosX(x), represantationChar(c)
	{
		
	}

	void MoveBullet();
	int GetPosX() const;
	int GetPosY() const;
	int GetPrevPosX() const;

	bool ThrowOutBullet(int x) const;
};

