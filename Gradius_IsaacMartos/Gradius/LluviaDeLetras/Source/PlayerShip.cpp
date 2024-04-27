#include "PlayerShip.h"

void PlayerShip::BeginPlay()
{
}

void PlayerShip::Tick()
{
	InputDirection dir = Input::GetDirection();

    switch (dir) {
    case InputDirection::Up:
        Move(0, -1); // Mover hacia arriba
        break;
    case InputDirection::Down:
        Move(0, 1); // Mover hacia abajo
        break;
    case InputDirection::Left:
        Move(-1, 0); // Mover hacia la izquierda
        break;
    case InputDirection::Right:
        Move(1, 0); // Mover hacia la derecha
        break;
    case InputDirection::None:
        Move(0, 0);
        break;
    default:
        dir = InputDirection::None;
        break;
    }
}

void PlayerShip::Move(int x, int y)
{
    prevPosX = posX;
    prevPosY = posY;

    int newX = posX + x;
    int newY = posY + y;

    if (newX >= 1 && newX < (60 - 1) && newY >= 4 && newY < 27 - 1)
    {
        posX = newX;
        posY = newY;
    }
}

void PlayerShip::ShootBullets(int posX, int posY)
{
    balasList.emplace_back(posX, posY, '.');
}

void PlayerShip::RemoveBullets(int maxXPos)
{
    auto it = std::remove_if(balasList.begin(), balasList.end(), [maxXPos](const Bala& bala) {
        return bala.ThrowOutBullet(maxXPos);
        });

    balasList.erase(it, balasList.end());
}

void PlayerShip::MoveBullets()
{
    for (auto& bala : balasList) {
        bala.MoveBullet();
    }
}

