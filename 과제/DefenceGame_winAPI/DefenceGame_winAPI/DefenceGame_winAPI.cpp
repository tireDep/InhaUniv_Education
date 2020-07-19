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
	
	static RECT viewRect;

	static vector<Bullet *> bulletList;
	static vector<vector<Obstacle *>> obstacle;
	static Gun gun;

	static int _downSpeed = 1;

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

		if (eGame + 10 == wParam)
		{
			vector<Obstacle *> temp;
			for (int i = 0; i < eViewW - 50; i += 50)
			{
				createBlock = rand() % 2;
				if (createBlock == 0)
				{
					Block *block = new Block(i, 0, 50 + i, 30, 0);
					temp.push_back(block);
				}

			}
			obstacle.push_back(temp);
		}

		if (wParam == eGame)
		{
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
					if (bulletList.size() == 0 || bulletList[0]->GetBulletCnt() < eBulletLimteCnt)
					{
						Bullet *bullet = new Bullet(gun.GetCenterPos(), gun.GetNowDegree());
						bulletList.push_back(bullet);
					}
				}
				break;

				default:
					break;
			}
		}
		InvalidateRect(hWnd, NULL, TRUE);
		break;

	case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);

			for (int i = 0; i < obstacle.size(); i++)
			{
				for (int j = 0; j < obstacle[i].size(); j++)
				{
					obstacle[i][j]->DrawObstacle(hdc);
				}
			}

			DrawHpBar(hdc, _loseHpPoint);
			gun.DrawWeapon(hdc);

			for (int i = 0; i < bulletList.size(); i++)
				bulletList[i]->DrawWeapon(hdc);

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
