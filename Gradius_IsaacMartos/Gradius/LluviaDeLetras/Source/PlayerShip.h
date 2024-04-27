#pragma once
#include "Actor.h"
#include "Bala.h"
#include "Input.h"
#include <vector>

class PlayerShip : public Actor
{
    std::vector<Bala> balasList;

public:
    PlayerShip(int x, int y) : Actor(x, y, '>')
    {
	    
    }

    virtual void BeginPlay() override;

    virtual void Tick() override;

    void Move(int posX, int posY);

    void ShootBullets(int posX, int posY);

    const std::vector<Bala>& GetBulletsList() const {
        return balasList;
    }

    void RemoveBullets(int maxX);

    void MoveBullets();
};

