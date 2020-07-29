// test.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "test.h"

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
    LoadStringW(hInstance, IDC_TEST, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TEST));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TEST));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_TEST);
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
#include<vector>
using std::vector;
using std::pair;
using std::iterator;

bool AddPolygonSpot_RightBottom(vector<POINT>preRect, vector<POINT>newRect, POINT *test);
bool AddPolygonSpot_LeftUp(vector<POINT>preRect, vector<POINT>newRect, POINT *test);

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		vector<POINT> rectPos;
		vector<POINT> rect2;

		POINT temp;
		// temp = { 100,100 };
		// rectPos.push_back(temp);
		// temp = { 200,100 };
		// rectPos.push_back(temp);
		// temp = { 200,200 };
		// rectPos.push_back(temp);
		// temp = { 100,200 };
		// rectPos.push_back(temp);

		//temp = { 200,150 };
		//rect2.push_back(temp);
		//temp = { 250,150 };
		//rect2.push_back(temp);
		//temp = { 250,250 };
		//rect2.push_back(temp);
		//temp = { 150,250 };
		//rect2.push_back(temp);
		//temp = { 150,200 };
		//rect2.push_back(temp);

		//temp = { 200, 200 };
		//rect2.push_back(temp);
		//temp = { 200,250 };
		//rect2.push_back(temp);
		//temp = { 100,250 };
		//rect2.push_back(temp);

		//temp = { 200, 100 };
		//rect2.push_back(temp);
		//temp = { 300, 100 };
		//rect2.push_back(temp);
		//temp = { 300, 200 };
		//rect2.push_back(temp);

		// temp = { 200, 120 };
		// rect2.push_back(temp);
		// temp = { 300, 120 };
		// rect2.push_back(temp);
		// temp = { 300, 150 };
		// rect2.push_back(temp);
		// temp = { 200, 150 };
		// rect2.push_back(temp);

		// 우측, 하단 판정 가능

		temp = { 200,100 };
		rectPos.push_back(temp);
		temp = { 100,100 };
		rectPos.push_back(temp);
		temp = { 100,200 };
		rectPos.push_back(temp);
		temp = { 200,200 };
		rectPos.push_back(temp);


		// temp = { 150, 100 };
		// rect2.push_back(temp);
		// temp = { 150, 0 };
		// rect2.push_back(temp);
		// temp = { 0, 0 };
		// rect2.push_back(temp);
		// temp = { 0, 150 };
		// rect2.push_back(temp);
		// temp = { 100, 150 };
		// rect2.push_back(temp);

		// temp = { 100, 100 };
		// rect2.push_back(temp);
		// temp = { 0, 100 };
		// rect2.push_back(temp);
		// temp = { 0, 200 };
		// rect2.push_back(temp);
		// temp = { 100, 200 };
		// rect2.push_back(temp);

		temp = { 200, 100 };
		rect2.push_back(temp);
		temp = { 200, 0 };
		rect2.push_back(temp);
		temp = { 100, 0 };
		rect2.push_back(temp);
		temp = { 100, 100 };
		rect2.push_back(temp);

		POINT *test = new POINT[rectPos.size() + rect2.size()];
		if (AddPolygonSpot_RightBottom(rectPos, rect2, test))
			Polygon(hdc, test, rectPos.size() + rect2.size());
		else
		{
			if(AddPolygonSpot_LeftUp(rectPos, rect2, test))
				Polygon(hdc, test, rectPos.size() + rect2.size());
			else
				Ellipse(hdc, 100, 100, 200, 200);
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

bool AddPolygonSpot_RightBottom(vector<POINT>preRect, vector<POINT>newRect, POINT *test)
{
	int k = 0;
	int i = 0;
	int j = 0;
	int check = 0;
	while (1)
	{
		if (j != 0)
		{
			while (newRect.size() > j)
			{
				test[i++] = newRect[j++];
			}
			while (k < preRect.size() && j == newRect.size())
			{
				if (check == 0)
				{
					if (preRect[k].x == newRect[j - 1].x && preRect[k].y >= newRect[j - 1].y)
					{
						test[i++] = preRect[k++];
						check++;
						continue;
					}
					else if (preRect[k].x <= newRect[j - 1].x || preRect[k].x >= newRect[j - 1].x && preRect[k].y <= newRect[j - 1].y)
						k++;
				}
				test[i++] = preRect[k++];
				check++;
			}
		}
		if (k == preRect.size() && j == newRect.size())
		{
			test[i] = test[0];
			return true;
		}
		else if (k + 1 == preRect.size() && j != newRect.size())
			return false;


		if (preRect[k].x <= newRect[j].x && preRect[k + 1].x >= newRect[j].x && preRect[k].y <= newRect[j].y && preRect[k + 1].y >= newRect[j].y)
		{
			test[i] = preRect[k++];
			test[++i] = newRect[j++];
			i++;
		}
		else
		{
			test[i] = preRect[k];
			test[++i] = preRect[++k];
		}
	}
}

bool AddPolygonSpot_LeftUp(vector<POINT>preRect, vector<POINT>newRect, POINT *test)
{
	int k = 0;
	int i = 0;
	int j = 0;
	int check = 0;
	while (1)
	{
		if (j != 0)
		{
			while (newRect.size() > j)
			{
				test[i++] = newRect[j++];
			}
			while (k < preRect.size() && j == newRect.size())
			{
				if (check == 0)
				{
					if (preRect[k].x == newRect[j - 1].x && preRect[k].y >= newRect[j - 1].y)
					{
						test[i++] = preRect[k++];
						check++;
						continue;
					}
					else if (preRect[k].x <= newRect[j - 1].x || preRect[k].x >= newRect[j - 1].x && preRect[k].y <= newRect[j - 1].y)
						k++;
				}
				test[i++] = preRect[k++];
				check++;
			}
		}
		if (k == preRect.size() && j == newRect.size())
		{
			test[i] = test[0];
			return true;
		}
		else if (k + 1 == preRect.size() && j != newRect.size())
			return false;


		if (preRect[k].x >= newRect[j].x && preRect[k + 1].x <= newRect[j].x && preRect[k].y <= newRect[j].y && preRect[k + 1].y >= newRect[j].y)
		{
			test[i] = preRect[k++];
			test[++i] = newRect[j++];
			i++;
		}
		else
		{
			test[i] = preRect[k];
			test[++i] = preRect[++k];
		}
	}
}