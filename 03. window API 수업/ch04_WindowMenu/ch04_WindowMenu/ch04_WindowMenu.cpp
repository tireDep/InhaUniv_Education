// ch04_WindowMenu.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "ch04_WindowMenu.h"

#include<commdlg.h>	// 파일

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
    LoadStringW(hInstance, IDC_CH04_WINDOWMENU, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CH04_WINDOWMENU));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CH04_WINDOWMENU));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CH04_WINDOWMENU);
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

#include <stdio.h>	// fclose

void OutFromFile(TCHAR filename[], HWND hWnd)
{
	FILE *fPtr;
	HDC hdc;
	int line;
	TCHAR buffer[500];
	line = 0;
	hdc = GetDC(hWnd);

#ifdef _UNICODE
	_tfopen_s(&fPtr, filename, _T("r, ccs = UNICODE"));
#else
	_tfopen_s(&fPtr, filename, _T("r"));
#endif // _UNICODE
	while (_fgetts(buffer, 100, fPtr) != NULL)
	{
		if (buffer[_tcslen(buffer) - 1] == _T('\n'))
			buffer[_tcslen(buffer) - 1] = NULL;
		TextOut(hdc, 0, line * 20, buffer, _tcslen(buffer));
		line++;
	}
	fclose(fPtr);
	ReleaseDC(hWnd, hdc);

}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static int setFigure = -1;
	static POINT mousePos;
    
	OPENFILENAME ofn;
	TCHAR str[100], lpstrFile[100] = _T("");
	TCHAR filter[] = _T("Every File(*.*) \0*.*\0TextFile\0*.txt;*.doc\0");

	OPENFILENAME sfn;

	CHOOSECOLOR cColor;
	static COLORREF temp[16], color;
	HBRUSH hBrush, oldBrush;
	int i;

	static HMENU hMenu, hSubMenu;

	switch (message)
    {
	case WM_CREATE:
		hMenu = GetMenu(hWnd);
		hSubMenu = GetSubMenu(hMenu, 2);
		EnableMenuItem(hSubMenu, ID_DRAW_CIRCLE, MF_GRAYED);
		EnableMenuItem(hSubMenu, ID_DRAW_RECTANGLE, MF_GRAYED);
		EnableMenuItem(hSubMenu, ID_DRAW_STAR, MF_GRAYED);
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

			case ID_DRAW_CIRCLE:
				setFigure = 0;
				MessageBox(NULL, L"Draw", L"Circle", MB_OK);
				break;

			case ID_DRAW_RECTANGLE:
				setFigure = 1;
				MessageBox(NULL, L"Draw", L"Rectangle", MB_OK);
				break;

			case ID_DRAW_STAR:
				setFigure = 2;
				MessageBox(NULL, L"Draw", L"Star", MB_OK);
				break;

			case ID_FILE_FILEOPEN:	// 145p 파일 열기
				memset(&ofn, 0, sizeof(OPENFILENAME));
				ofn.lStructSize = sizeof(OPENFILENAME);
				ofn.hwndOwner = hWnd;	// 창의 부모가 누구인지
				ofn.lpstrFilter = filter;
				ofn.lpstrFile = lpstrFile;
				ofn.nMaxFile = 100;
				ofn.lpstrInitialDir = _T(".");

				if (GetOpenFileName(&ofn) != 0)
				{
					_stprintf_s(str, _T("%s 파일을 열겠습니까?"), ofn.lpstrFile);
					MessageBox(hWnd, str, _T("열기 선택"), MB_OK);

					OutFromFile(ofn.lpstrFile, hWnd);
				}
				break;

			case ID_FILE_FILESAVE:
				memset(&sfn, 0, sizeof(OPENFILENAME));
				sfn.lStructSize = sizeof(OPENFILENAME);
				sfn.hwndOwner = hWnd;
				sfn.lpstrFilter = filter;
				sfn.lpstrFile = lpstrFile;
				sfn.nMaxFile = 256;
				sfn.lpstrInitialDir = _T(".");

				if (GetSaveFileName(&sfn) != 0)
				{
					_stprintf_s(str, _T("%s 파일로 저장하시겠습니까?"), sfn.lpstrFile);
					MessageBox(hWnd, str, _T("저장하기 선택"), MB_OK);
				}
				break;

			case ID_COLORDLG:
				for (i = 0; i < 16; i++)
					temp[i] = RGB(rand() % 256, rand() % 256, rand() % 256);
				memset(&cColor, 0, sizeof(CHOOSECOLOR));
				cColor.lStructSize = sizeof(CHOOSECOLOR);
				cColor.hwndOwner = hWnd;
				cColor.lpCustColors = temp;
				cColor.Flags = CC_FULLOPEN;
				if (ChooseColor(&cColor) != 0)
				{
					color = cColor.rgbResult;
					InvalidateRgn(hWnd, NULL, TRUE);
				}
				break;

            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;

	case WM_LBUTTONDOWN:
		mousePos.x = LOWORD(lParam);
		mousePos.y = HIWORD(lParam);
		InvalidateRect(hWnd, NULL, TRUE);
		break;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);

			hBrush = CreateSolidBrush(color);
			oldBrush = (HBRUSH)SelectObject(hdc, hBrush);

			if(setFigure==0)
				Ellipse(hdc, mousePos.x, mousePos.y, mousePos.x + 100, mousePos.y + 100);
			else if(setFigure==1)
				Rectangle(hdc, mousePos.x, mousePos.y, mousePos.x + 100, mousePos.y + 100);
			else if (setFigure == 2)
			{
				int distance = 50;
				int midX = mousePos.x;
				int midY = mousePos.y;
				DrawStar(hdc, midX, midY, distance);
			}

			SelectObject(hdc, oldBrush);
			DeleteObject(hBrush);
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

void DrawStar(HDC hdc, int posx, int posy, int distance)
{
	POINT starPos[10];
	POINT temp[5] = { 0 };
	temp[0].x = posx;
	temp[0].y = posy - distance;
	AddPoint(posx, posy, temp);

	// 크래머 공식
	double a, b, c, d, e, f;
	int _posX, _posY;

	a = temp[0].y - temp[2].y;
	b = -(temp[0].x - temp[2].x);
	e = a*temp[0].x + b*temp[0].y;

	c = temp[1].y - temp[4].y;
	d = -(temp[1].x - temp[4].x);
	f = c*temp[1].x + d*temp[1].y;

	double divide = (a*d) - (b*c);
	_posX = ((e*d) - (b*f)) / divide;
	_posY = ((a*f) - (e*c)) / divide;
	// 크래머 공식

	POINT temp2[5] = { 0 };
	temp2[0] = { _posX, _posY };
	AddPoint(posx, posy, temp2);

	// 좌표 저장
	int j = 0;
	for (int i = 0; i < 10; i++)
	{
		starPos[i] = temp[j];
		starPos[++i] = temp2[j++];
	}

	Polygon(hdc, starPos, 10);
}

void AddPoint(int posx, int posy, POINT calcP[])
{
	int degree = 72;
	int addDegree = degree;
	double radian;
	int tempX, tempY;

	for (int i = 1; i < 5; i++)
	{
		radian = degree *(M_PI / 180);
		degree += addDegree;

		tempX = (calcP[0].x - posx)*cos(radian) - (calcP[0].y - posy) * sin(radian) + posx;
		tempY = (calcP[0].x - posx) * sin(radian) + (calcP[0].y - posy) * cos(radian) + posy;

		calcP[i] = { tempX, tempY };
	}
}