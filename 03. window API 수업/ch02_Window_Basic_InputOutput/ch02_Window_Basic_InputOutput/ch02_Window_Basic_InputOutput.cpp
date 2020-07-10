// ch02_Window_Basic_InputOutput.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "ch02_Window_Basic_InputOutput.h"

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
    LoadStringW(hInstance, IDC_CH02_WINDOW_BASIC_INPUTOUTPUT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CH02_WINDOW_BASIC_INPUTOUTPUT));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CH02_WINDOW_BASIC_INPUTOUTPUT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_IBEAM);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW + 2);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CH02_WINDOW_BASIC_INPUTOUTPUT);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(NULL, MAKEINTRESOURCE(IDI_QUESTION));

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

   wcscpy(szTitle, _T("Frist Window"));	// define 추가
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
     200, 300, 1000, 700, nullptr, nullptr, hInstance, nullptr);

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
	//static TCHAR str[100];
	//static int count;
	//static int yPos;
	//static RECT rt = { 0,0,1000,1000 };
	// 문자열

	// static SIZE size;	// 캐럿
    switch (message)
    {
	case WM_CREATE:
		// count = 0;
		// yPos = 0;
		// 문자열
		
		// CreateCaret(hWnd, NULL, 7, 16);
		// ShowCaret(hWnd);
		// 캐럿
		break;

	case WM_CHAR:	// 문자열
		// {
		// 	if (wParam == VK_BACK && count > 0)
		// 		count--;
		// 	else if (VK_RETURN == wParam)
		// 	{
		// 		count = 0;
		// 		yPos += 20;
		// 		rt = { 0, 0 + yPos, 1000, 1000 + yPos };
		// 	}
		// 	else
		// 		str[count++] = wParam;
		// 	str[count] = NULL;
		// 	
		// 	InvalidateRgn(hWnd, NULL, true);	// window 핸들링에 대해 다시 그리기
		// 	// WM_PAINT 호출(함수 자체가 다시 실행됨) 
		// }
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

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
			// TextOut(hdc, 100, 100, _T("hello"), _tcslen(_T("hello")));
			// 
			// RECT rect;
			// rect.left = 300;
			// rect.top = 30;
			// rect.right = 350;
			// rect.bottom = 350;
			// TCHAR tText[] = _T("bello");
			// DrawText(hdc, tText, _tcslen(tText), &rect, DT_SINGLELINE | DT_RIGHT | DT_VCENTER);

			// TextOut(hdc, 0, yPos, str, _tcslen(str));
			// DrawText(hdc, str, _tcslen(str), &rt, DT_CENTER|DT_VCENTER);
			// 글자 출력

			// GetTextExtentPoint(hdc, str, _tcslen(str), &size);
			// DrawText(hdc, str, _tcslen(str), &rt, DT_LEFT | DT_TOP);
			// SetCaretPos(size.cx, yPos);
			// 캐럿 생성

			// MoveToEx(hdc, 100, 100, NULL);
			// LineTo(hdc, 200, 230);
			// 직선 그리기
			
			// DrawGrid(hdc, 100, 100, 500, 500, 50);
			// 격자 생성 함수

			DrawCircle(hdc, 300, 300, 100);	
			// 원 생성 함수


            EndPaint(hWnd, &ps);
        }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);

		// HideCaret(hWnd);
		// DestroyCaret();
		// 캐럿
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

void DrawGrid(HDC hdc, int posX1, int posY1, int posX2, int posY2, int tab)
{
	int temp = posX1;
	int temp2 = posY1;
	while (temp <= posX2)
	{
		MoveToEx(hdc, temp, posY1, NULL);
		LineTo(hdc, temp, posY2);

		MoveToEx(hdc, posX1, temp2, NULL);
		LineTo(hdc, posX2, temp2);

		temp += tab;
		temp2 += tab;
	}

}

void DrawCircle(HDC hdc, int centerX, int centerY, int radius)
{
	// int yr = radius / 2;
	int posX1 = centerX - radius;
	int posY1 = centerY - radius;
	int posX2 = centerX + radius;
	int posY2 = centerY + radius;

	Ellipse(hdc, posX1, posY1, posX2, posY2);
	
	int srdi = 0;
	int calc = pow(radius + srdi, 2);
	int calc2 = calc + calc - 2 * calc * sqrt(3) / 2;
	int calc3 = sqrt(calc2) / 2;	// small radius

	int x1 = centerX - calc3;
	int y1 = centerY + radius + calc3 - calc3;
	int x2 = centerX + calc3;
	int y2 = centerY + radius + calc3 + calc3;

	Ellipse(hdc, x1, y1, x2, y2);
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
