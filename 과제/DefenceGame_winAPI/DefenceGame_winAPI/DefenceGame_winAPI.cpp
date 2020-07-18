// DefenceGame_winAPI.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "DefenceGame_winAPI.h"

#include "ObstalceClass.h"
#include "Function.h"

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

	static vector<Obstacle *> obstacle;

	static int _downSpeed = 35;

	static int hpPoint = 0;

	static POINT test[4] = { { 245,580 },{ 255,580 },{ 255,650 },{ 245,650 } };
	static POINT tempP[4] = { { 245,580 },{ 255,580 },{ 255,650 },{ 245,650 } };

	static int nowDeg = 0;
	static int addDegree = 30;

    switch (message)
    {
	case WM_CREATE:
		{
			SetTimer(hWnd, eGame, 100, NULL);	// 게임 타이머
		}
		break;

	case WM_TIMER:
		{
		int createBlock;

		//Polygon(hdc, test, 4);

		POINT center = { 250, 650 };		

		//if ( test[0].y > test[3].y )
		//{
		//	degree *= -1;
		//}
		//else if (test[1].y < test[4].y)
		//{
		//	degree = 15;
		//}

		//if (nowDeg >= -90 && nowDeg < 90)
			nowDeg += addDegree;
//		else if (nowDeg >= 90 && nowDeg > -90)
//			nowDeg -= addDegree;

		for (int i = 0; i < 4; i++)
		{
			test[i] = PointRotate(center.x, center.y, nowDeg, &tempP[i]);
		}

		//if (wParam == eGame)
		//	{
		//		for (int i = 0; i < eViewW - 50; i += 50)
		//		{
		//			createBlock = rand() % 2;
		//			if (createBlock == 0)
		//			{
		//				Block *block = new Block(i, 0, 50 + i, 30, _downSpeed);
		//				obstacle.push_back(block);
		//			}
		//
		//		}
		//
		//		for (int i = 0; i < obstacle.size(); i++)
		//		{
		//			obstacle[i]->DownObstacle();
		//			if (obstacle[i]->CheckDeadLine())
		//			{
		//				obstacle.erase(obstacle.begin() + i);
		//				hpPoint += 10;
		//			}
		//		}
		//	}

			InvalidateRect(hWnd, NULL, TRUE);
		}
		break;

	case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);
		
			Polygon(hdc, test, 4);
		//	DrawHpBar(hdc, hpPoint);
			DrawGun(hdc);

			for (int i = 0; i < obstacle.size(); i++)
			{
				obstacle[i]->DrawObstacle(hdc);
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
