// ch05_Accelerator_Bitmap_Problem.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "ch05_Accelerator_Bitmap_Problem.h"

#include<commdlg.h>

#pragma comment(lib,"msimg32.lib")

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

// >>
TCHAR sKeyState[128];
RECT rectView;

HBITMAP hAniImage;
BITMAP bitAni;

int posX = 0;

int posLR = 0;
int posUpDown = 0;
bool isRight = 0;

const int spriteSizeX = 57;
const int spriteSizeY = 52;
int runFrameMax = 0;
int runFrameMin = 0;
int curFrame = runFrameMin;

void CreateBitmap();
void DrawBitmap(HWND hWnd, HDC hdc);
void DeleteBitmap();
void UpdateFrame(HWND hWnd);

void DrawRectText(HDC hdc);

VOID CALLBACK AniProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime);
 VOID CALLBACK KeyStateProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime);

// <<

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
    LoadStringW(hInstance, IDC_CH05_ACCELERATOR_BITMAP_PROBLEM, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CH05_ACCELERATOR_BITMAP_PROBLEM));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CH05_ACCELERATOR_BITMAP_PROBLEM));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CH05_ACCELERATOR_BITMAP_PROBLEM);
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
    switch (message)
    {

	case WM_CREATE:
		CreateBitmap();
		SetTimer(hWnd, 0, 100, KeyStateProc);
		SetTimer(hWnd, 10, 100, AniProc);
		SetTimer(hWnd, 20, 100, NULL);
		GetClientRect(hWnd, &rectView);
		break;

	case WM_TIMER:
		
		break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		
		Rectangle(hdc, 0, 0, rectView.right, rectView.bottom);
		DrawBitmap(hWnd, hdc);
		DrawRectText(hdc);

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
		KillTimer(hWnd, 0);
		KillTimer(hWnd, 10);
		KillTimer(hWnd, 20);
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

void CreateBitmap()
{
	hAniImage = (HBITMAP)LoadImage(NULL, TEXT("../Image/Zero_Run.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GetObject(hAniImage, sizeof(BITMAP), &bitAni);

	// 달리는 애니메이션만
	runFrameMax = bitAni.bmWidth / spriteSizeX - 1;	// 인덱스
	runFrameMin = 2;
	curFrame = runFrameMin;
}

void DrawBitmap(HWND hWnd, HDC hdc)
{
	HDC hMemDC;	// back Buffer
	HBITMAP hOldBitmap;
	int bx, by;

	hMemDC = CreateCompatibleDC(hdc);
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hAniImage);
	bx = bitAni.bmWidth / 16;	// 이미지 수로 나눠줌 
	by = bitAni.bmHeight / 2;	// 이미지 수로 나눠줌 

	int xStart = curFrame * bx;
	int yStart = 0;

	if (posLR < 0) posLR = 0;
	if (posUpDown < 0) posUpDown = 0;

	TransparentBlt(hdc, posLR * 10, posUpDown * 10, bx, by, hMemDC, xStart, yStart, bx, by, RGB(255, 0, 255));

	SelectObject(hMemDC, hOldBitmap);
	DeleteDC(hMemDC);
}

void DeleteBitmap()
{
	DeleteObject(hAniImage);
}

void UpdateFrame(HWND hWnd)
{
	curFrame++;
	if (curFrame > runFrameMax)
		curFrame = runFrameMin;
}

VOID CALLBACK AniProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{
	UpdateFrame(hWnd);

	{
		posX += 5;
		if (posX > rectView.right) posX = 0;
	}

	InvalidateRect(hWnd, NULL, FALSE);
	return;
}

VOID CALLBACK KeyStateProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{
	if (GetKeyState('A') & 0x8000)
	{
		wsprintf(sKeyState, TEXT("%s"), _T("A-Key"));
		posLR--;
	}
	else if (GetKeyState('S') & 0x8000)
	{
		wsprintf(sKeyState, TEXT("%s"), _T("S-Key"));
		posUpDown++;
	}
	else if (GetKeyState('D') & 0x8000)
	{
		wsprintf(sKeyState, TEXT("%s"), _T("D-Key"));
		posLR++;
	}
	else if (GetKeyState('W') & 0x8000)
	{
		wsprintf(sKeyState, TEXT("%s"), _T("W-Key"));
		posUpDown--;
	}
	else
	{
		wsprintf(sKeyState, TEXT(""));
	}

	InvalidateRect(hWnd, NULL, FALSE);
}

void DrawRectText(HDC hdc)
{
	TCHAR strArr[] = _T("Hello");
	TextOut(hdc, posX, 10, strArr, _tcslen(strArr));

	TextOut(hdc, 100, 200, sKeyState, _tcslen(sKeyState));
}