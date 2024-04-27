#include "GradiusEngine.h"
#include "Helpers.h"
#include "ScoreManager.h"
#include <iostream>
#include <string>
#include "Input.h"

using namespace std;

void GradiusEngine::update()
{
	DEBUG_LOG("UPDATE");

	Input::GetDirection();
	playerShip->Tick();
	playerShip->ShootBullets(playerShip->GetPosX(), playerShip->GetPosY());
	playerShip->MoveBullets();
	playerShip->RemoveBullets(screenWidth - 2);

	AddActors();
	CheckCollisions();

	for (size_t i = 0; i < actorsList.size(); ++i)
	{
		Enemigo* enemy = dynamic_cast<Enemigo*>(actorsList[i]);

		if (enemy != nullptr) enemy->Tick();
	}

}

void GradiusEngine::draw()
{
	drawEngine->ClearScreen();

	DrawBoard(); //Fill the matrix with the board
	DrawScore(); //Fill the matrix with the score
	DrawAnimatedElements(); //Fill the matrix with the animated elements

	drawEngine->DrawMatrix();
}

void GradiusEngine::DrawBoard()
{
	drawEngine->DrawAtPos(201, 0); // '╔';
	drawEngine->DrawAtPos(187, drawEngine->boardSizeX - 2, 0);//'╗';
	drawEngine->DrawAtPos(200, 0, drawEngine->boardSizeY - 1);//'╚';
	drawEngine->DrawAtPos(188, drawEngine->boardSizeX - 2, drawEngine->boardSizeY - 1);//'╝';

	drawEngine->DrawRow(205, 0, drawEngine->boardSizeX - 1);
	drawEngine->DrawRow(205, 2, drawEngine->boardSizeX - 1);
	drawEngine->DrawRow(205, 3, drawEngine->boardSizeX - 1);
	drawEngine->DrawRow(205, drawEngine->boardSizeY - 1, drawEngine->boardSizeX - 1);
	drawEngine->DrawColumn(186, drawEngine->boardSizeY, 0);
	drawEngine->DrawColumn(186, drawEngine->boardSizeY, drawEngine->boardSizeX - 2);

	drawEngine->DrawAtPos(185, drawEngine->boardSizeX - 2, 2);
	drawEngine->DrawAtPos(185, drawEngine->boardSizeX - 2, 3);
	drawEngine->DrawAtPos(204, 0, 2);
	drawEngine->DrawAtPos(204, 0, 3);

	drawEngine->DrawAtPos("PUNTUACION:", 1, 4);
	drawEngine->DrawAtPos("RECORD:", 1, drawEngine->boardSizeX - 16);

}

void GradiusEngine::DrawScore()
{
	char scoreChars[10];
	char recordChars[10];

	_itoa_s(ScoreManager::GetInstance()->GetPoints(), scoreChars, 10); //http://www.cplusplus.com/reference/cstdlib/itoa/
	_itoa_s(ScoreManager::GetInstance()->GetRecord(), recordChars, 10);

	for (int i = 0; i < 10; i++)
	{
		if (scoreChars[i] > 0)
			drawEngine->DrawAtPos(scoreChars[i], 15 + i, 1);
		if (recordChars[i] > 0)
			drawEngine->DrawAtPos(recordChars[i], drawEngine->boardSizeX - 9 + i, 1);
	}
}

void GradiusEngine::DrawAnimatedElements()
{
	for (size_t i = 0; i < actorsList.size(); ++i) {

		Actor* actor = actorsList[i];
		int actorX = actor->GetPosX();
		int actorY = actor->GetPosY();
		char actorChar = actor->GetActorRepresentation();

		drawEngine->DrawAtPos(actorChar, actorX, actorY);

		if (actor->GetPrevPosX() != actorX || actor->GetPrevPosY() != actorY) {
			if (actor->GetPrevPosX() < screenWidth - 1) {
				drawEngine->DrawAtPos(' ', actor->GetPrevPosX(), actor->GetPrevPosY());
			}
		}
	}

	const vector<Bala>& bulletsList = playerShip->GetBulletsList();
	for (size_t i = 0; i < bulletsList.size(); ++i) {

		const Bala& bullet = bulletsList[i];
		int bulletX = bullet.GetPosX();
		int bulletY = bullet.GetPosY();

		drawEngine->DrawAtPos(250, bulletX, bulletY);

		if (bullet.GetPrevPosX() != bulletX || bulletX != playerShip->GetPosX()) {
			if (bullet.GetPrevPosX() > playerShip->GetPosX()) {
				drawEngine->DrawAtPos(' ', bullet.GetPrevPosX(), bulletY);
			}
		}
	}
}

void GradiusEngine::DrawExplosion(int xPos, int yPos)
{
	drawEngine->DrawAtPos('*', xPos, yPos);
	drawEngine->DrawAtPos('|', xPos, yPos - 1);
	drawEngine->DrawAtPos('|', xPos, yPos + 1);
	drawEngine->DrawAtPos('-', xPos - 1, yPos);
	drawEngine->DrawAtPos('-', xPos + 1, yPos);
	drawEngine->DrawAtPos('/', xPos + 1, yPos - 1);
	drawEngine->DrawAtPos(92, xPos + 1, yPos + 1);
	drawEngine->DrawAtPos('/', xPos - 1, yPos - 1);
	drawEngine->DrawAtPos(92, xPos - 1, yPos - 1);
}

void GradiusEngine::CheckCollisions()
{
	const vector<Bala>& bulletsList = playerShip->GetBulletsList();
	for (size_t i = 0; i < bulletsList.size(); ++i)
	{
		for (size_t j = 0; j < actorsList.size(); ++j)
		{
			if (actorsList[j]->GetPosX() == bulletsList[i].GetPosX() &&
				actorsList[j]->GetPosY() == bulletsList[i].GetPosY())
			{
				ScoreManager::GetInstance()->AddPoints(10);
				DrawExplosion(actorsList[j]->GetPosX(), actorsList[j]->GetPosY());
				DestroyActor(actorsList[j]);
			}
		}
	}

	for (size_t x = 1; x < actorsList.size(); ++x)
	{
		if (actorsList[x]->GetPosX() <= 2)
		{
			drawEngine->DrawAtPos(' ', actorsList[x]->GetPosX(), actorsList[x]->GetPosY());
			DestroyActor(actorsList[x]);
		}
	}
}

void GradiusEngine::AddActors()
{
	int randomY = rand() % (screenHeight - 6) + 5; 
	Enemigo* enemy = new Enemigo(screenWidth - 1, randomY); 
	actorsList.push_back(enemy); 
}

void GradiusEngine::DestroyActor(Actor* actorToDestroy)
{
	auto x = find(actorsList.begin(), actorsList.end(), actorToDestroy);

	if (x != actorsList.end()) {
		actorsList.erase(x);
		delete actorToDestroy;
	}
}

void GradiusEngine::InitializeScreenBuffer()
{
	screenBuffer = new char* [screenHeight];
	for (int i = 0; i < screenHeight; ++i) {
		screenBuffer[i] = new char[screenWidth];
	}
}

void GradiusEngine::DeleteScreenBuffer()
{
	for (int i = 0; i < screenHeight; ++i) {
		delete[] screenBuffer[i];
	}
	delete[] screenBuffer;
}

void GradiusEngine::Restart()
{
	isGameOver = false;

	int currentPoints = ScoreManager::GetInstance()->GetPoints();
	int currentRecord = ScoreManager::GetInstance()->GetRecord();

	if (currentPoints > currentRecord) {
		ScoreManager::GetInstance()->SetNewRecord(currentPoints);
	}
	ScoreManager::GetInstance()->SetPoints(0);

	drawEngine->ClearScreen();
	drawEngine->ResetMatrix(' ');
}

