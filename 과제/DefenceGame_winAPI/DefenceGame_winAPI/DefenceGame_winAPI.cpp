// DefenceGame_winAPI.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "DefenceGame_winAPI.h"

#include "ObstalceClass.h"
#include "Function.h"
#include "WeaponClass.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_DEFENCEGAME_WINAPI, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DEFENCEGAME_WINAPI));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DEFENCEGAME_WINAPI));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_DEFENCEGAME_WINAPI);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
	   eViewX, eViewY, eViewW, eViewH, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(218);

	srand((unsigned)time(NULL));

	static multimap<int, string> playerData;

	static TCHAR playerName[100];
	static int nameCnt;
	static int playerScore = 0;
	static TCHAR *tcharScore = new TCHAR;
	static int _loseHpPoint = 0;

	static int _blockCnt = 3;	// 난이도
	static int _downSpeed = 5;

	static int gameMode = eStart;

	static RECT viewRect;

	static vector<Bullet *> bulletList;
	static vector<vector<Obstacle *>> obstacle;
	static Gun gun;

	static vector<Obstacle *> hitEffect;
	static vector<Obstacle *> deleteEffect;

    switch (message)
    {
	case WM_CREATE:
		{
			GetClientRect(hWnd, &viewRect);	// 창 크기
			SetTimer(hWnd, eGame, 100, NULL);	// 게임 타이머
			SetTimer(hWnd, eGame + 10, 1000, NULL);	// 게임 타이머_생성
			SetTimer(hWnd, eGame + 75, 100, NULL);	// 이펙트 타이머
			SetTimer(hWnd, eGame + 85, 100, NULL);

			vector<Obstacle *> temp;
			for (int i = 0; i < eViewW - 50; i += 50)
			{
				Block *block = new Block(i, 50, 50 + i, 100, _downSpeed);
				temp.push_back(block);
			}
			obstacle.push_back(temp);

			ReadRanking(&playerData);
		}
		break;

	case WM_TIMER:
		{
		if (eGame + 10 == wParam && gameMode == eGame)
		{
			int createBlock;
			int tempCnt = _blockCnt;
			vector<Obstacle *> temp;
			for (int i = 0; i < eViewW - 50; i += 50)
			{
				createBlock = rand() % 2;
				if (createBlock == 0 && tempCnt-- > 0)
				{
					Block *block = new Block(i, 30, 50 + i, 60, _downSpeed);
					temp.push_back(block);
				}
			
			}
			obstacle.push_back(temp);
		}

		if (wParam == eGame && gameMode == eGame)
		{
			bool isRemove;
			for (int i = 0; i < obstacle.size(); i++)
			{
				isRemove = FALSE;
				for (int j = 0; j < obstacle[i].size(); j++)
				{
					for (int k = 0; k < bulletList.size(); k++)
					{
						int deltaX = bulletList[k]->GetCenterPosX() - obstacle[i][j]->GetCenterPosX();
						int deltaY = bulletList[k]->GetCenterPosY() - obstacle[i][j]->GetCenterPosY();

						float length = sqrt(deltaX * deltaX + deltaY * deltaY);

						if (length <= (bulletList[k]->GetRadius() + obstacle[i][j]->GetRadius()))
						{
							playerScore += 10;

							hitEffect.push_back(obstacle[i][j]);

						//	Obstacle *dObs = obstacle[i][j];
						//	Bullet *dBul = bulletList[i];

							obstacle[i].erase(obstacle[i].begin() + j);
							bulletList.erase(bulletList.begin() + k);

						//	delete dObs;
						//	delete dBul;

							k = -1;
							j = -1;
							isRemove = TRUE;
							break;
						}

					}	// for_k
					if (obstacle[i].size() == 0)
					{
					//	vector<Obstacle *>::iterator iter;
					//	for (iter = obstacle[i].begin(); iter < obstacle[i].end(); iter++)
					//	{
					//		Obstacle *dObs = (*iter);
							obstacle.erase(obstacle.begin() + i);	// 빈 행 삭제
					//		delete dObs;
					//		break;
					//	}
						i = -1;
					}
					if (isRemove)
						break;
				}	// for_j
				
			}	// for_i

			// [충돌]
			// 기존 사유 : 중심좌표값을 이동량 만큼 +해서 좌표값이 음수가 되는 경우 존재
			// 해결 : 그때 그때 좌표값을 계산해서 리턴
			// 현재는 원vs원으로 충돌 판정 / 후에 원vs사각형으로 바꿔보기
			// but 딜레이 때문에 

			// -------------------------------------------------------------------------------

			if (obstacle.size() != 0)
				obstacle[0][0]->Update(obstacle, deleteEffect, _loseHpPoint);
			if (bulletList.size() != 0)
				bulletList[0]->Update(bulletList, viewRect);

			// -------------------------------------------------------------------------------
		
		}	// if

		if (wParam == eGame + 75 && gameMode == eGame)
		{
			for (int i = 0; i < hitEffect.size(); i++)
			{	
				for (int j = 0; j < 4; j++)
				{
					hitEffect[i]->SetBlockPos(j, 0, cos(45 * M_PI / 180) * (hitEffect[i]->GetBlockPos(j, 0) - hitEffect[i]->GetCenterPosX()) - sin(45 * M_PI / 180) * (hitEffect[i]->GetBlockPos(j, 1) - hitEffect[i]->GetCenterPosY()) + hitEffect[i]->GetCenterPosX());
					hitEffect[i]->SetBlockPos(j, 1, sin(45 * M_PI / 180) * (hitEffect[i]->GetBlockPos(j, 0) - hitEffect[i]->GetCenterPosX()) + cos(45 * M_PI / 180) * (hitEffect[i]->GetBlockPos(j, 1) - hitEffect[i]->GetCenterPosY()) + hitEffect[i]->GetCenterPosY());

					hitEffect[i]->SetSpinCnt();
					if (hitEffect[i]->GetSpinCnt() > 20)
					{
						//vector<Obstacle *>::iterator iter;
						//for (iter = hitEffect.begin(); iter < hitEffect.end(); iter++)
						//{
						//	if ((*iter) == hitEffect[i])
						//	{
						//		Obstacle *dObs = (*iter);
								hitEffect.erase(hitEffect.begin() + i);
					//			delete dObs;
					//			break;
					//		}
					//	}
						i = -1;
						break;
					}	// if
				}	// for_j
			}	// for_i


			for (int i = 0; i < deleteEffect.size(); i++)
			{
				for (int j = 0; j < 4; j++)
				{
					double tempX = cos(30 * M_PI / 180) * (deleteEffect[i]->GetBlockPos(j, 0) - deleteEffect[i]->GetCenterPosX()) - sin(30 * M_PI / 180) * (deleteEffect[i]->GetBlockPos(j, 1) - deleteEffect[i]->GetCenterPosY());
					double tempY = sin(30 * M_PI / 180) * (deleteEffect[i]->GetBlockPos(j, 0) - deleteEffect[i]->GetCenterPosX()) + cos(30 * M_PI / 180) * (deleteEffect[i]->GetBlockPos(j, 1) - deleteEffect[i]->GetCenterPosY());
					deleteEffect[i]->SetBlockPos(j, 0, tempX + deleteEffect[i]->GetCenterPosX());
					deleteEffect[i]->SetBlockPos(j, 1, tempY + deleteEffect[i]->GetCenterPosY());

					//deleteEffect[i]->SetBlockPos(j, 0, cos(135 * M_PI / 180) * (deleteEffect[i]->GetBlockPos(j, 0) - deleteEffect[i]->GetCenterPosX()) - sin(135 * M_PI / 180) * (deleteEffect[i]->GetBlockPos(j, 1) - deleteEffect[i]->GetCenterPosY()) + deleteEffect[i]->GetCenterPosX());
					//deleteEffect[i]->SetBlockPos(j, 1, sin(135 * M_PI / 180) * (deleteEffect[i]->GetBlockPos(j, 0) - deleteEffect[i]->GetCenterPosX()) + cos(135 * M_PI / 180) * (deleteEffect[i]->GetBlockPos(j, 1) - deleteEffect[i]->GetCenterPosY()) + deleteEffect[i]->GetCenterPosY());

					deleteEffect[i]->SetSpinCnt();
					if (deleteEffect[i]->GetSpinCnt() > 20)
					{
						//vector<Obstacle *>::iterator iter;
						//for (iter = hitEffect.begin(); iter < hitEffect.end(); iter++)
						//{
						//	if ((*iter) == deleteEffect[i])
						//	{
						//		Obstacle *dObs = (*iter);
								deleteEffect.erase(deleteEffect.begin() + i);
						//		delete dObs;
						//		break;
						//	}
						//}
						i = -1;
						break;
					}	// if
				}	// for_j
			}	// for_i

		}	// if

		if (wParam == eGame + 85 && gameMode == eGame)
		{
			
		}	// if

			InvalidateRect(hWnd, NULL, TRUE);
		}
		break;

	case WM_KEYDOWN:
		{
			switch (wParam)
			{
			case VK_ESCAPE:
				// system("pause");
				break;

			case 0x41:	// A
			case 0x61:	// a
			case VK_LEFT:
				if(gameMode == eGame) gun.MoveBarrel(0);
				break;

			case 0x44:	// D
			case 0x64:	// d
			case VK_RIGHT:
				if (gameMode == eGame)  gun.MoveBarrel(1);
				break;

			case VK_SPACE:
				{
					// CreateBullet();
				if (gameMode == eGame) 
				{
					if (bulletList.size() == 0 || bulletList.size() < eBulletLimteCnt)
					{
						Bullet *bullet = new Bullet(gun.GetCenterPos(), gun.GetNowDegree());
						bulletList.push_back(bullet);
					}
				}
				}
				break;

			case VK_RETURN:
				if (gameMode == eStart)
					gameMode = eGame;
				break;

				default:
					break;
			}
		}
		InvalidateRect(hWnd, NULL, TRUE);
		break;
	
	case WM_CHAR:
	{
		if (gameMode == eStart)
		{
			HDC hdc = GetDC(hWnd);
			if (wParam == VK_BACK && nameCnt > 0) 
				nameCnt--;
			else 
				playerName[nameCnt++] = wParam;
			playerName[nameCnt] = NULL;
			ReleaseDC(hWnd, hdc);
		}
	}
	break;
	case WM_LBUTTONDOWN:
	{
		// RECT btn1 = { 50,500,200,550 };
		// RECT btn2 = { 300,500,450,550 };
		int xPos = LOWORD(lParam);
		int yPos = HIWORD(lParam);
		if (gameMode == eResult && yPos >= 500 && yPos <= 550 && xPos >= 50 && xPos <= 200)
		{
			WriteRanking(&playerData);

			playerData.erase(playerData.begin(), playerData.end());
			ReadRanking(&playerData);

			nameCnt = 0;
			playerName[nameCnt] = NULL;
			playerScore = 0;
			gameMode = eStart;
		}
		if (gameMode == eResult && yPos >= 500 && yPos <= 550 && xPos >= 300 && xPos <= 550)
		{
			WriteRanking(&playerData);
			DestroyWindow(hWnd);
		}

		// RECT btn = { 208,500,308,550 };
		if (gameMode == eStart && yPos >= 500 && yPos <= 550 && xPos >= 208 && xPos <= 308)
		{
			WriteRanking(&playerData);
			DestroyWindow(hWnd);
		}
	}
		break;

	case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);
			
			SetBkMode(hdc, TRANSPARENT);
			if (gameMode == eStart)
			{
				RECT startScreen;
				startScreen.left = 0;
				startScreen.top = 100;
				startScreen.right = eViewW;
				startScreen.bottom = eViewH;
				
				DrawText(hdc, _T("DeffenceGame"), _tcslen(_T("DeffenceGame")), &startScreen, DT_CENTER | DT_VCENTER);

				startScreen.left = 0;
				startScreen.top = eViewH/2;
				startScreen.right = eViewW;
				startScreen.bottom = eViewH;
				DrawText(hdc, _T("[ ID ]"), _tcslen(_T("[ ID ]")), &startScreen, DT_CENTER | DT_VCENTER);

				startScreen.top += 50;
				DrawText(hdc, playerName, _tcslen(playerName), &startScreen, DT_CENTER | DT_VCENTER);

				RECT btn1 = { 208,500,308,550 };

				HPEN hPen, oldPen;
				HBRUSH hBrush, oldBrush;

				SetTextColor(hdc, RGB(0, 0, 0));
				SetColor(hdc, hPen, oldPen, 200, 200, 200);
				SetColor(hdc, hBrush, oldBrush, 200, 200, 200);

				Rectangle(hdc, btn1.left, btn1.top, btn1.right, btn1.bottom);

				DrawText(hdc, _T("Exit"), _tcslen(_T("Exit")), &btn1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

				SetTextColor(hdc, RGB(255, 255, 255));
				DeleteColor(hdc, hPen, oldPen);
				DeleteColor(hdc, hBrush, oldBrush);

				obstacle.erase(obstacle.begin(), obstacle.end());	// 딜레이 시간중 생성되는 것 삭제
			}
			else if (gameMode == eGame)
			{
				RECT gameScreen;
				gameScreen.left = 15;
				gameScreen.top = 15;
				gameScreen.right = eViewW - 35;
				gameScreen.bottom = eViewH;

				DrawText(hdc, playerName, _tcslen(playerName), &gameScreen, DT_LEFT | DT_VCENTER);
				_itot(playerScore, tcharScore, 10);

				DrawText(hdc, tcharScore, _tcslen(tcharScore), &gameScreen, DT_CENTER | DT_VCENTER);
				// DrawText(hdc, _T("TEMPLV"), _tcslen(_T("TEMPLV")), &gameScreen, DT_RIGHT | DT_VCENTER);
				for (int i = 0; i < obstacle.size(); i++)
				{
					for (int j = 0; j < obstacle[i].size(); j++)
						obstacle[i][j]->DrawObstacle(hdc);
				}

				DrawHpBar(hdc, _loseHpPoint);
				gun.DrawWeapon(hdc);

				for (int i = 0; i < bulletList.size(); i++)
					bulletList[i]->DrawWeapon(hdc);

				for (int i = 0; i < hitEffect.size(); i++)
					hitEffect[i]->DrawObstacle(hdc);

				for(int i=0;i<deleteEffect.size();i++)
					deleteEffect[i]->DrawObstacle(hdc);

				if (_loseHpPoint >= 500)
				{
					//vector<Bullet *>::iterator iter;
					//for (iter = bulletList.begin(); iter < bulletList.end(); iter++)
					//{
					//	Bullet *dBul = (*iter);
						bulletList.erase(bulletList.begin(),bulletList.end());
					//	delete (*iter);
					//	break;
					//}

					//for(int i=0;i<obstacle.size();i++)
					//{
					//	for (int j = 0; j < obstacle[i].size(); j++)
					//	{
					//		Obstacle *oOb = obstacle[i][j];
							obstacle.erase(obstacle.begin(), obstacle.end());
					//		delete oOb;
					//		break;
					//	}
					//}

					_loseHpPoint = 0;
					gameMode = eResult;
					SaveData(&playerData, playerName, playerScore);
				}
			}
			else if (gameMode == eResult)
			{
				ResultScreen(hdc, tcharScore, playerName, playerScore, &playerData);
			}

			EndPaint(hWnd, &ps);
		}
	break;

    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);

		KillTimer(hWnd, eGame);
		KillTimer(hWnd, eGame + 10);
		KillTimer(hWnd, eGame + 75);

		_CrtDumpMemoryLeaks();
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
