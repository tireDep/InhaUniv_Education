// GroundEatingGame.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "GroundEatingGame.h"
#include "PlayerClass.h"
#include "MapClass.h"
#include "UiClass.h"

#pragma comment(lib, "msimg32.lib")

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
    LoadStringW(hInstance, IDC_GROUNDEATINGGAME, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GROUNDEATINGGAME));

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

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_GROUNDEATINGGAME));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_GROUNDEATINGGAME);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
	   eWinPosX, eWinPosY, eWinWidth, eWinHeight, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}


HBITMAP hBackImage;
BITMAP bitBack;

void CreateBitmap();
void DrawBitMap(HWND hWnd, HDC hdc);
void DeleteBitmap();

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static Player player(eStartposX, eStartPosY);
	static HideMap map = { ePosLeft,ePosTop,ePosRight,ePosBottom };
	static UI playerUI;

	int nowScreen = playerUI.GetScreenNum();
    switch (message)
    {
	case WM_CREATE:
		CreateBitmap();
		SetTimer(hWnd, 0, 10, NULL);
		break;

	case WM_TIMER:
	{
		if (eGameScreen == nowScreen)
		{
			playerUI.Update();
		}

		InvalidateRect(hWnd, NULL, false);
		break;
	}

	case WM_CHAR:
		if (eStartScreen == nowScreen)
		{
			playerUI.SetPlayerName(wParam);
		}
		break;

	case WM_LBUTTONDOWN:
		if (eResultScreen == nowScreen)
		{
			if (!playerUI.PushBtn(lParam, &player))
				DestroyWindow(hWnd);
		}
		break;

	case WM_KEYDOWN:
		if (eGameScreen == nowScreen)
		{
			if (wParam == 'A' || wParam == 'a' || wParam == VK_LEFT)
				player.CheckPlayerPos(-emoveSpeed, eLeft, map);
			else if (wParam == 'W' || wParam == 'w' || wParam == VK_UP)
				player.CheckPlayerPos(-emoveSpeed, eUp, map);
			else if (wParam == 'D' || wParam == 'd' || wParam == VK_RIGHT)
				player.CheckPlayerPos(emoveSpeed, eRight, map);
			else if (wParam == 'S' || wParam == 's' || wParam == VK_DOWN)
				player.CheckPlayerPos(emoveSpeed, eDown, map);
		}
		InvalidateRect(hWnd, NULL, FALSE);
		break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		RECT rectView;
		HDC memDc;
		HBITMAP hBit, oldBit;

		HDC finalDc;
		HBITMAP fhBit, fhOldBit;

		GetClientRect(hWnd, &rectView);
		memDc = CreateCompatibleDC(hdc);
		hBit = CreateCompatibleBitmap(hdc, rectView.right, rectView.bottom);
		oldBit = (HBITMAP)SelectObject(memDc, hBit);
		PatBlt(memDc, rectView.left, rectView.top, rectView.right, rectView.bottom, WHITENESS);

		finalDc = CreateCompatibleDC(hdc);
		fhBit = CreateCompatibleBitmap(hdc, rectView.right, rectView.bottom);
		fhOldBit = (HBITMAP)SelectObject(finalDc, fhBit);
		PatBlt(finalDc, rectView.left, rectView.top, rectView.right, rectView.bottom, WHITENESS);

		if (eStartScreen == nowScreen)
		{
			playerUI.DrawStartUI(finalDc);
		}
		else if (eGameScreen == nowScreen)
		{
			playerUI.DrawGameUI(memDc, player.GetPlayerMapCnt(), player.GetMapArea());

			DrawBitMap(hWnd, finalDc);	// 배경사진

			HBRUSH hBrush, oldBrush;
			hBrush = CreateSolidBrush(RGB(255, 255, 255));
			oldBrush = (HBRUSH)SelectObject(memDc, hBrush);

			map.DrawPolygon(memDc);	// 가림판

			SelectObject(memDc, oldBrush);
			DeleteObject(hBrush);

			player.DrawPlayer(memDc);	// 플레이어 및 색칠 영역
										// 플레이어 위치

			TransparentBlt(finalDc, 0, 0, rectView.right, rectView.bottom, memDc, 0, 0, rectView.right, rectView.bottom, RGB(255, 65, 255)); // 투명 처리
		}
		else if (eResultScreen == nowScreen)
		{
			playerUI.DrawResultUI(finalDc);
		}

		BitBlt(hdc, 0, 0, rectView.right, rectView.bottom, finalDc, 0, 0, SRCCOPY);	// 더블버퍼링

		SelectObject(memDc, oldBit);
		DeleteObject(hBit);
		DeleteDC(memDc);

		SelectObject(finalDc, fhOldBit);
		DeleteObject(fhBit);
		DeleteDC(finalDc);


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
		// FreeConsole();
		DeleteBitmap();
		KillTimer(hWnd, 0);
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

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

void CreateBitmap()
{
	hBackImage = (HBITMAP)LoadImage(
		NULL,
		TEXT("../Image/test.bmp"),
		IMAGE_BITMAP,
		0,
		0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION
	);
	
	GetObject(hBackImage, sizeof(BITMAP), &bitBack);
}

void DrawBitMap(HWND hWnd, HDC hdc)
{
	HDC hMemDc;
	HBITMAP hOldBitmap;
	int bx, by;

	hMemDc = CreateCompatibleDC(hdc);
	hOldBitmap = (HBITMAP)SelectObject(hMemDc, hBackImage);
	bx = bitBack.bmWidth;
	by = bitBack.bmHeight;

	BitBlt(hdc, ePosLeft, ePosTop, bx, by, hMemDc, 0, 0, SRCCOPY);

	SelectObject(hMemDc, hOldBitmap);
	DeleteDC(hMemDc);
}

void DeleteBitmap()
{
	DeleteObject(hBackImage);
}