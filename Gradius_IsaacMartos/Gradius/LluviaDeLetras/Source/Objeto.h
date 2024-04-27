#pragma once

class Objeto
{

protected:
	int posX, posY;
	int prevPosX,prevPosY;

public:
    Objeto(int x, int y) : posX(x), posY(y)
    {
        prevPosX = posX;
        prevPosY = posY;
    }

    int GetPosX() const {
        return posX;
    }

    int GetPosY() const {
        return posY;
    }

    int GetPrevPosX() const {
        return prevPosX;
    }

    int GetPrevPosY() const {
        return prevPosY;
    }
};

