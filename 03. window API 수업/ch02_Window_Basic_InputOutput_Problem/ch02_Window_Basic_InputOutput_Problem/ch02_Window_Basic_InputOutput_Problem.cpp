// ch02_Window_Basic_InputOutput_Problem.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "ch02_Window_Basic_InputOutput_Problem.h"

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
    LoadStringW(hInstance, IDC_CH02_WINDOW_BASIC_INPUTOUTPUT_PROBLEM, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CH02_WINDOW_BASIC_INPUTOUTPUT_PROBLEM));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CH02_WINDOW_BASIC_INPUTOUTPUT_PROBLEM));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CH02_WINDOW_BASIC_INPUTOUTPUT_PROBLEM);
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
	static int isPush[4] = { 0 };
    switch (message)
    {
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

	case WM_KEYDOWN:
		if (wParam == VK_UP)
			isPush[0] = 1;
		else if (wParam == VK_DOWN)
			isPush[1] = 1;
		else if (wParam == VK_LEFT)
			isPush[2] = 1;
		else if (wParam == VK_RIGHT)
			isPush[3] = 1;
		
		InvalidateRgn(hWnd, NULL, true);
		break;

	case WM_KEYUP:
		if (wParam == VK_UP)
			isPush[0] = 0;
		else if (wParam == VK_DOWN)
			isPush[1] = 0;
		else if (wParam == VK_LEFT)
			isPush[2] = 0;
		else if (wParam == VK_RIGHT)
			isPush[3] = 0;
		InvalidateRgn(hWnd, NULL, true);
		break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
			
			HBRUSH hBrush, oldBrush;
			hBrush = CreateSolidBrush(RGB(255, 0, 0));
			oldBrush = (HBRUSH)SelectObject(hdc, hBrush);

			RECT bottomRect;
			bottomRect.top = 300;
			bottomRect.left = 300;
			bottomRect.bottom = 400;
			bottomRect.right = 400;

			RECT leftRect;
			leftRect.top = 200;
			leftRect.left = 200;
			leftRect.bottom = 300;
			leftRect.right = 300;

			RECT topRect;
			topRect.top = 100;
			topRect.left = 300;
			topRect.bottom = 200;
			topRect.right = 400;

			RECT rightRect;
			rightRect.top = 200;
			rightRect.left = 400;
			rightRect.bottom = 300;
			rightRect.right = 500;
			
			for (int i = 0; i < 4; i++)
			{
				if (isPush[i] == 1)	// 색상 O
				{
					hBrush = CreateSolidBrush(RGB(255, 0, 0));
					oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
				}
				else if (isPush[i] == 0)	// 색상 X
				{
					hBrush = CreateSolidBrush(RGB(0, 0, 0));
					oldBrush = (HBRUSH)SelectObject(hdc, GetStockObject(NULL_BRUSH));	// 투명
				}

				switch (i)
				{
				case 0:
					Rectangle(hdc, topRect.left, topRect.top, topRect.right, topRect.bottom);
					SetBkMode(hdc, TRANSPARENT);	// 글자배경 투명
					DrawText(hdc, _T("Top"), _tcslen(_T("Top")), &topRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					break;
				case 1:
					Rectangle(hdc, bottomRect.left, bottomRect.top, bottomRect.right, bottomRect.bottom);
					SetBkMode(hdc, TRANSPARENT);	// 글자배경 투명
					DrawText(hdc, _T("Bottom"), _tcslen(_T("Bottom")), &bottomRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					break;
				case 2:
					Rectangle(hdc, leftRect.left, leftRect.top, leftRect.right, leftRect.bottom);
					SetBkMode(hdc, TRANSPARENT);		// 글자배경 투명
					DrawText(hdc, _T("Left"), _tcslen(_T("Left")), &leftRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					break;
				case 3:
					Rectangle(hdc, rightRect.left, rightRect.top, rightRect.right, rightRect.bottom);
					SetBkMode(hdc, TRANSPARENT);		// 글자배경 투명
					DrawText(hdc, _T("Right"), _tcslen(_T("Right")), &rightRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					break;

				default:
					break;
				}

			}
			SelectObject(hdc, oldBrush);	// 기존 세팅 돌려줌
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
