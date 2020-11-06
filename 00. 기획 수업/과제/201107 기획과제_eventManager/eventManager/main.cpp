#include <iostream>
#include "InputManager.h"
#include "Player.h"
#include "ObjectCreate.h"

#define g_inputManager CInputManager::GetInstance()

using namespace std;

int main()
{
	CPlayer player;
	CPlayer player2;
	CObjectCreate objCreate;
	g_inputManager->AddListener(&player);
	g_inputManager->AddListener(&player2);
	g_inputManager->AddListener(&objCreate);

	while (1)
	{
		if(!g_inputManager->CheckInput())
			break;
	}

	g_inputManager->RemoveListener(&player);

	while (1)
	{
		if (!g_inputManager->CheckInput())
			break;
	}
	return 0;
}