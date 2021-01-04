#include <iostream>
#include <string>
#include <stdlib.h>
#include <crtdbg.h>
#include "GameManager.h"

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);
	// _CrtSetBreakAlloc(147); // string
	char input;

	while (true)
	{
		cout << "1 : Main / 2 : Game / 3 : Pause / 4 : End" << endl;
		cin >> input;

		if (input == '1')
			g_pGameManager->CheckSceneChange(eMainScene);
		if (input == '2')
			g_pGameManager->CheckSceneChange(eGameScene);
		if (input == '3')
			g_pGameManager->CheckSceneChange(ePauseScene);
		if (input == '4')
		{
			g_pGameManager->CheckSceneChange(eEndScene);
			break;
		}
		
		cout << endl;
	}

	g_pGameManager->Destroy();
	_CrtDumpMemoryLeaks();

	return 0;
}