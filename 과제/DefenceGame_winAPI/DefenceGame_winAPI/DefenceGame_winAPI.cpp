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
	srand((unsigned)time(NULL));
	static TCHAR PlayerName[100];
	static int nameCnt;

	static int gameMode = eStart;

	static RECT viewRect;

	static vector<Bullet *> bulletList;
	static vector<vector<Obstacle *>> obstacle;
	static Gun gun;

	static int _blockCnt = 3;	// 난이도
	static int _downSpeed = 5;

	static int _loseHpPoint = 0;

    switch (message)
    {
	case WM_CREATE:
		{
			GetClientRect(hWnd, &viewRect);	// 창 크기
			SetTimer(hWnd, eGame, 100, NULL);	// 게임 타이머
			SetTimer(hWnd, eGame + 10, 1000, NULL);	// 게임 타이머
		}
		break;

	case WM_TIMER:
		{
		int createBlock;
		int tempCnt = _blockCnt;
		if (eGame + 10 == wParam && gameMode)
		{
			vector<Obstacle *> temp;
			for (int i = 0; i < eViewW - 50; i += 50)
			{
				createBlock = rand() % 2;
				if (createBlock == 0 && tempCnt-- > 0)
				{
					// Block *block = new Block(i, 30, 50 + i, 60, _downSpeed);
					// Block *block = new Block(i, 30, 30 + i, 60, _downSpeed);
					Block *block = new Block(i, 50, 50 + i, 100, _downSpeed);
					temp.push_back(block);
				}

			}
			obstacle.push_back(temp);
		}

		if (wParam == eGame && gameMode == eGame)
		{
			bool isRemove = FALSE;
			for (int k = 0; k < bulletList.size(); k++)
			{
				isRemove = FALSE;
				for (int i = 0; i < obstacle.size(); i++)
				{
					for (int j = 0; j < obstacle[i].size(); j++)
					{
						if (
							obstacle[i][j]->GetHitPos().bottom >= bulletList[k]->GetCenterPos().y
					 		&& obstacle[i][j]->GetHitPos().top <= bulletList[k]->GetCenterPos().y
							&& obstacle[i][j]->GetHitPos().left <= bulletList[k]->GetCenterPos().x
							&& obstacle[i][j]->GetHitPos().right >= bulletList[k]->GetCenterPos().x
							)
						{
							obstacle[i].erase(obstacle[i].begin() + j);
							bulletList.erase(bulletList.begin() + k);
							k = -1;
							isRemove = TRUE;
							break;
						}
					}	// for_j_obstacle

					if (isRemove)
						break;
				} // for_i_obstacle
			}	// for_k_bullet


		// random_shuffle(obstacle.begin(), obstacle.end());
			if(obstacle.size() != 0)
				obstacle[0][0]->Update(obstacle, _loseHpPoint);
			if (bulletList.size() != 0)
				bulletList[0]->Update(bulletList, obstacle,  viewRect);
		}

			InvalidateRect(hWnd, NULL, TRUE);
		}
		break;

	case WM_KEYDOWN:
		{
			switch (wParam)
			{
			case VK_ESCAPE:
				// todo : 일시정지 구현
				break;

			case 0x41:	// A
			case 0x61:	// a
			case VK_LEFT:
				gun.MoveBarrel(0);
				break;

			case 0x44:	// D
			case 0x64:	// d
			case VK_RIGHT:
				gun.MoveBarrel(1);
				break;

			case VK_SPACE:
				{
					// CreateBullet();
					if (bulletList.size() == 0 || bulletList.size() < eBulletLimteCnt)
					{
						Bullet *bullet = new Bullet(gun.GetCenterPos(), gun.GetNowDegree());
						bulletList.push_back(bullet);
					}
				}
				break;

			case VK_RETURN:
				if (gameMode == eStart)
				{
					gameMode = eGame;
				}
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
				PlayerName[nameCnt++] = wParam;
			PlayerName[nameCnt] = NULL;
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
			nameCnt = 0;
			PlayerName[nameCnt] = NULL;
			gameMode = eStart;
		}
		if (gameMode == eResult && yPos >= 500 && yPos <= 550 && xPos >= 300 && xPos <= 550)
			DestroyWindow(hWnd);
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
				startScreen.top = eViewH / 2;
				startScreen.right = eViewW;
				startScreen.bottom = eViewH;
				DrawText(hdc, _T("[ ID ]"), _tcslen(_T("[ ID ]")), &startScreen, DT_CENTER | DT_VCENTER);

				startScreen.top = eViewH / 2 + 50;
				DrawText(hdc, PlayerName, _tcslen(PlayerName), &startScreen, DT_CENTER | DT_VCENTER);
				obstacle.erase(obstacle.begin(), obstacle.end());	// 딜레이 시간중 생성되는 것 삭제
			}
			else if (gameMode == eGame)
			{
				RECT gameScreen;
				gameScreen.left = 15;
				gameScreen.top = 15;
				gameScreen.right = eViewW - 35;
				gameScreen.bottom = eViewH;

				DrawText(hdc, PlayerName, _tcslen(PlayerName), &gameScreen, DT_LEFT | DT_VCENTER);
				DrawText(hdc, _T("TEMPSCORE"), _tcslen(_T("TEMPSCORE")), &gameScreen, DT_CENTER | DT_VCENTER);
				DrawText(hdc, _T("TEMPLV"), _tcslen(_T("TEMPLV")), &gameScreen, DT_RIGHT | DT_VCENTER);
				for (int i = 0; i < obstacle.size(); i++)
				{
					for (int j = 0; j < obstacle[i].size(); j++)
						obstacle[i][j]->DrawObstacle(hdc);
				}

				DrawHpBar(hdc, _loseHpPoint);
				gun.DrawWeapon(hdc);

				for (int i = 0; i < bulletList.size(); i++)
					bulletList[i]->DrawWeapon(hdc);

				if (_loseHpPoint >= 500)
				{
					bulletList.erase(bulletList.begin(),bulletList.end());
					obstacle.erase(obstacle.begin(),obstacle.end());
					_loseHpPoint = 0;
					gameMode = eResult;
				}
			}
			else if (gameMode == eResult)
			{
				RECT resultScreen = { 0,100,eViewW,eViewH };

				DrawText(hdc, _T("RESULT"), _tcslen(_T("RESULT")), &resultScreen, DT_CENTER | DT_VCENTER);
				
				resultScreen.left += 100;
				resultScreen.top += 50;
				resultScreen.right -= 100;
				DrawText(hdc, _T("PlayerName + Score"), _tcslen(_T("PlayerName + Score")), &resultScreen, DT_LEFT | DT_VCENTER);

				RECT btn1 = { 50,500,200,550 };
				RECT btn2 = { 300,500,450,550 };

				Rectangle(hdc, btn1.left, btn1.top, btn1.right, btn1.bottom);
				Rectangle(hdc, btn2.left, btn2.top, btn2.right, btn2.bottom);

				DrawText(hdc, _T("Main"), _tcslen(_T("Main")), &btn1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				DrawText(hdc, _T("Exit"), _tcslen(_T("Exit")), &btn2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
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
		KillTimer(hWnd, eGame+10);
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
