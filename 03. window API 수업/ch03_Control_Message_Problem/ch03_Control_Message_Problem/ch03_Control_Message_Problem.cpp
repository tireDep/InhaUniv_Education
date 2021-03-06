// ch03_Control_Message_Problem.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "ch03_Control_Message_Problem.h"

#include "Class.h"

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
    LoadStringW(hInstance, IDC_CH03_CONTROL_MESSAGE_PROBLEM, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CH03_CONTROL_MESSAGE_PROBLEM));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CH03_CONTROL_MESSAGE_PROBLEM));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CH03_CONTROL_MESSAGE_PROBLEM);
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
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

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

	// TODO : 동적할당
	const int arrSize = 100;

	static POINT mousePos;

	static cCircle circle[arrSize];
	static int circleCnt = 0;
	static bool isCircle = FALSE;

	static cRect rectangle[arrSize];
	static int rectCnt = 0;
	static bool isRect = FALSE;

	static cStar star[arrSize];
	static int starCnt = 0;
	static bool isStar = FALSE;

	static RECT rectView;

    switch (message)
    {
	case WM_CREATE:
		GetClientRect(hWnd, &rectView);	// 창 크기
		SetTimer(hWnd, 0, 10, NULL);	// 타이머
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

	case WM_TIMER:
		// CheckCollision()
		circle[circleCnt - 1].Collision(circle, rectangle, circleCnt);
		rectangle[circleCnt - 1].Collision(rectangle, rectangle, rectCnt);
		star[circleCnt - 1].Collision(star, rectangle, starCnt);

		// RandomMove()
		circle[circleCnt - 1].MovePos(circle, circleCnt);
		rectangle[rectCnt - 1].MovePos(rectangle, rectCnt);
		star[starCnt - 1].MovePos(star, starCnt);
		
		// Rotation()
		//rectangle[rectCnt - 1].Rotation(90);

		// Update()
		circle[circleCnt - 1].Update(circle, rectView, circleCnt);
		rectangle[rectCnt - 1].Update(rectangle, rectView, rectCnt);
		star[starCnt - 1].Update(star, rectView, starCnt);
		// circle[starCnt - 1].Update(star, rectView, starCnt);

		InvalidateRect(hWnd, NULL, TRUE);
		break;

	case WM_LBUTTONDOWN:
	{
		//int rndFigure = rand() % 3;
		int rndFigure = rand() % 2;

		mousePos.x = LOWORD(lParam);
		mousePos.y = HIWORD(lParam);

		if (rndFigure == 0)
			isCircle = TRUE;
		if (rndFigure == 1)
			isRect = TRUE;
		if (rndFigure == 2)
			isStar = TRUE;

		InvalidateRect(hWnd, NULL, TRUE);
	}
		break;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

			if (isCircle)
			{
				circle[circleCnt++].SetPos(mousePos.x, mousePos.y, rectView);
				isCircle = FALSE;
			}
			if (isRect)
			{
				rectangle[rectCnt++].SetPos(mousePos.x, mousePos.y, rectView);
				isRect = FALSE;
			}
			if (isStar)
			{
				star[starCnt++].SetPos(mousePos.x, mousePos.y, rectView);
				isStar = FALSE;
			}

			for (int i = 0; i < circleCnt; i++)
				circle[i].DrawFigure(hdc);
			
			for (int i = 0; i < rectCnt; i++)
				rectangle[i].DrawFigure(hdc);

			for (int i = 0; i < starCnt; i++)
				star[i].DrawFigure(hdc);

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
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
