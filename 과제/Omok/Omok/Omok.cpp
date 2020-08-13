// Omok.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Omok.h"

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
    LoadStringW(hInstance, IDC_OMOK, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_OMOK));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_OMOK));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_OMOK);
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
      CW_USEDEFAULT, 0, 1100, 800, nullptr, nullptr, hInstance, nullptr);

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
#include <stdio.h>
#include <vector>

using std::vector;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static int map[defArrSize][defArrSize];
	// static bool colorMap[19][19];

	static vector<POINT> playerMark;
	static bool playerColor = false; // true;
	// 2개 필요

    switch (message)
    {
	case WM_CREATE:
		AllocConsole();
		freopen("CONOUT$", "wt", stdout);
		break;

	case WM_LBUTTONDOWN:
		{
			int posX = LOWORD(lParam);
			int posY = HIWORD(lParam);
			int tempX, tempY;
			int rangeDistance = eMarkDiameter / 2;

			if ((posX >= eMapLeft - rangeDistance && posX <= eMapRight + rangeDistance)
				&& (posY >= eMapTop - rangeDistance && posY <= eMapBottom + rangeDistance))
			{
				tempX = posX / eMarkDistance - 1;
				tempY = posY / 19 / 2;

				if(playerColor == false)
					map[tempY][tempX] = 1;
				else
					map[tempY][tempX] = -1;

				playerMark.push_back({ tempX * eMarkDistance + eMarkLeft + eMarkDiameter, tempY * eMarkDistance + eMarkTop + eMarkDiameter });
			}
			InvalidateRgn(hWnd, NULL, false);
		}
 		break;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            
			// 더블버퍼링
			RECT rectView;
			HDC memDc;
			HBITMAP hBit, oldBit;

			GetClientRect(hWnd, &rectView);
			memDc = CreateCompatibleDC(hdc);
			hBit = CreateCompatibleBitmap(hdc, rectView.right, rectView.bottom);
			oldBit = (HBITMAP)SelectObject(memDc, hBit);
			PatBlt(memDc, rectView.left, rectView.top, rectView.right, rectView.bottom, WHITENESS);
			// 더블버퍼링

			// 바둑판

			int j = 0;
			HBRUSH hBrush, oldBrush;
			hBrush = CreateSolidBrush(RGB(230, 186, 148));
			oldBrush = (HBRUSH)SelectObject(memDc, hBrush);
			Rectangle(memDc, 0, 0, 765, 800);
			Rectangle(memDc, 47, 35, 714, 705);

			for (int i = 2; i < 19; i++)
			{
				MoveToEx(memDc, 47, 37 * i, NULL);
				LineTo(memDc, 714, 37 * i);
				// 가로줄
			
				MoveToEx(memDc, (42 * i) - (5 * j), 36, NULL);
				LineTo(memDc, (42 * i) - (5 * j), 705);
				j++;
				// 세로줄
			}

			SelectObject(memDc, oldBrush);
			DeleteObject(hBrush);

			// 바둑판

			// 바둑판 점

			hBrush = CreateSolidBrush(RGB(0, 0, 0));
			oldBrush = (HBRUSH)SelectObject(memDc, hBrush);

			Ellipse(memDc, 42 + 37 * 3, 32 + 37 * 3, 52 + 37 * 3, 42 + 37 * 3);
			Ellipse(memDc, 42 + 37 * 9, 32 + 37 * 3, 52 + 37 * 9, 42 + 37 * 3);
			Ellipse(memDc, 42 + 37 * 15, 32 + 37 * 3, 52 + 37 * 15, 42 + 37 * 3);

			Ellipse(memDc, 42 + 37 * 3, 32 + 37 * 9, 52 + 37 * 3, 42 + 37 * 9);
			Ellipse(memDc, 42 + 37 * 9, 32 + 37 * 9, 52 + 37 * 9, 42 + 37 * 9);
			Ellipse(memDc, 42 + 37 * 15, 32 + 37 * 9, 52 + 37 * 15, 42 + 37 * 9);

			Ellipse(memDc, 42 + 37 * 3, 32 + 37 * 15, 52 + 37 * 3, 42 + 37 * 15);
			Ellipse(memDc, 42 + 37 * 9, 32 + 37 * 15, 52 + 37 * 9, 42 + 37 * 15);
			Ellipse(memDc, 42 + 37 * 15, 32 + 37 * 15, 52 + 37 * 15, 42 + 37 * 15);

			SelectObject(memDc, oldBrush);
			DeleteObject(hBrush);

			// 바둑판 점

			// playerDraw
			HBRUSH blackBrush, oldBrush1;
			HBRUSH whiteBrush, oldBrush2;

			for (int i = 0; i < playerMark.size(); i++)
			{
				if (playerColor == false)
				{
					blackBrush = CreateSolidBrush(RGB(0, 0, 0));
					oldBrush1 = (HBRUSH)SelectObject(memDc, blackBrush);

					Ellipse(memDc, playerMark[i].x - eMarkDiameter, playerMark[i].y - eMarkDiameter, playerMark[i].x + eMarkDiameter, playerMark[i].y + eMarkDiameter);

					SelectObject(memDc, oldBrush1);
					DeleteObject(blackBrush);
				}
				else
				{
					whiteBrush = CreateSolidBrush(RGB(255, 255, 255));
					oldBrush2 = (HBRUSH)SelectObject(memDc, whiteBrush);

					Ellipse(memDc, playerMark[i].x - eMarkDiameter, playerMark[i].y - eMarkDiameter, playerMark[i].x + eMarkDiameter, playerMark[i].y + eMarkDiameter);

					SelectObject(memDc, oldBrush2);
					DeleteObject(whiteBrush);
				}
			}

			// playerDraw

			// 더블버퍼링
			BitBlt(hdc, 0, 0, rectView.right, rectView.bottom, memDc, 0, 0, SRCCOPY);

			SelectObject(memDc, oldBit);
			DeleteObject(hBit);
			DeleteDC(memDc);
			// 더블버퍼링

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
		FreeConsole();
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
