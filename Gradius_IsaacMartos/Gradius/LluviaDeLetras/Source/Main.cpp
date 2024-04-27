#include <iostream>
#include "ScoreManager.h"
#include "GradiusEngine.h"
#include "Windows.h"

int main()
{

	GradiusEngine *gradiusEngine = new GradiusEngine(60, 27, 1.0f);

	ScoreManager* scoreManager = ScoreManager::GetInstance();
	scoreManager->LoadFromFile("puntos.txt");
	
	bool executeLoop = true;
	while (executeLoop)
	{
		gradiusEngine->updateEngine();

		if (GetKeyState(VK_ESCAPE) & 0x8000)
		{
			scoreManager->SetNewRecord(scoreManager->GetPoints());
			scoreManager->SaveToFile("puntos.txt");
			executeLoop = false;
		}
		
		if (gradiusEngine->GetGameOverState())
		{
			scoreManager->SetNewRecord(scoreManager->GetPoints());
			std::cout << "Game Over! Presiona la tecla Enter para volver a empezar...";
			while (!(GetAsyncKeyState(VK_RETURN) & 0x8000))
			{
				Sleep(100);
			}
			gradiusEngine->Restart();
		}
	}

	delete gradiusEngine;
	return 0;
}




