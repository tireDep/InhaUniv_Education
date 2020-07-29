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
void AddPolygonSpot_Another(vector<POINT>preRect, vector<POINT>newRect, POINT *test);
int GetArrayCnt(POINT *test);

bool DotInFigure(int x, int y, const vector<POINT> &p);

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
		temp = { 100,100 };
		rectPos.push_back(temp);
		temp = { 200,100 };
		rectPos.push_back(temp);
		temp = { 200,200 };
		rectPos.push_back(temp);
		temp = { 100,200 };
		rectPos.push_back(temp);

		temp = { 200,150 };
		rect2.push_back(temp);
		temp = { 250,150 };
		rect2.push_back(temp);
		temp = { 250,250 };
		rect2.push_back(temp);
		temp = { 150,250 };
		rect2.push_back(temp);
		temp = { 150,200 };
		rect2.push_back(temp);

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

		// temp = { 100, 150 };
		// rect2.push_back(temp);
		// temp = { 50, 150 };
		// rect2.push_back(temp);
		// temp = { 50, 250 };
		// rect2.push_back(temp);
		// temp = { 150, 250 };
		// rect2.push_back(temp);
		// temp = { 150, 200 };
		// rect2.push_back(temp);

		// -----------------------------------------------------
		// 우측, 하단 판정 가능
		// -----------------------------------------------------

		// temp = { 200,100 };
		// rectPos.push_back(temp);
		// temp = { 100,100 };
		// rectPos.push_back(temp);
		// temp = { 100,200 };
		// rectPos.push_back(temp);
		// temp = { 200,200 };
		// rectPos.push_back(temp);

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

		// temp = { 200, 100 };
		// rect2.push_back(temp);
		// temp = { 200, 0 };
		// rect2.push_back(temp);
		// temp = { 100, 0 };
		// rect2.push_back(temp);
		// temp = { 100, 100 };
		// rect2.push_back(temp);

		// -----------------------------------------------------
		// 좌측, 상단 판정 가능
		// -----------------------------------------------------

		//temp = { 200,100 };
		//rectPos.push_back(temp);
		//temp = { 100,100 };
		//rectPos.push_back(temp);
		//temp = { 100,200 };
		//rectPos.push_back(temp);
		//temp = { 200,200 };
		//rectPos.push_back(temp);
		////temp = { 200,100 };
		////rectPos.push_back(temp);
		
		// temp = { 300, 100 };
		// rect2.push_back(temp);
		// temp = { 400, 100 };
		// rect2.push_back(temp);
		// temp = { 400, 200 };
		// rect2.push_back(temp);
		// temp = { 300, 200 };
		// rect2.push_back(temp);
		// //temp = { 300, 100 };
		// //rect2.push_back(temp);

		//temp = { 400, 400 };
		//rect2.push_back(temp);
		//temp = { 500, 400 };
		//rect2.push_back(temp);
		//temp = { 500, 500 };
		//rect2.push_back(temp);
		//temp = { 400, 500 };
		//rect2.push_back(temp);
		////temp = { 300, 100 };
		////rect2.push_back(temp);

		POINT *test = new POINT[rectPos.size() + rect2.size() + 2];
		AddPolygonSpot_RightBottom(rectPos, rect2, test);
		//if (AddPolygonSpot_RightBottom(rectPos, rect2, test))
		//	Polygon(hdc, test, rectPos.size() + rect2.size());
		//else
		//{
		//	if(AddPolygonSpot_LeftUp(rectPos, rect2, test))
		//		Polygon(hdc, test, rectPos.size() + rect2.size());
		//	else
		//	{
		//		AddPolygonSpot_Another(rectPos, rect2, test);
		//		//Polygon(hdc, test, cnt);
		//	}
		//}

		vector<POINT>::iterator it;
		for (it = rectPos.begin(); it < rectPos.end();)
		{
			if (it->x != NULL)
				it = rectPos.erase(it);
			else
				it++;
		}

		for (int i = 0; i < GetArrayCnt(test); i++)
		{
			rectPos.push_back(test[i]);
		}


		vector<POINT>::iterator it2;
		for (it2 = rect2.begin(); it2 < rect2.end();)
		{
			if (it2->x != NULL)
				it2 = rect2.erase(it2);
			else
				it2++;
		}

		temp = { 150, 250 };
		rect2.push_back(temp);
		temp = { 100,250 };
		rect2.push_back(temp);
		temp = { 100,200 };
		rect2.push_back(temp);
		
		POINT *test2 = new POINT[rectPos.size() + rect2.size() + 2];
		AddPolygonSpot_LeftUp(rectPos, rect2, test2);

		vector<POINT>::iterator it3;
		for (it3 = rectPos.begin(); it3 < rectPos.end();)
		{
			if (it3->x != NULL)
				it3 = rectPos.erase(it3);
			else
				it3++;
		}

		for (int i = 0; i < GetArrayCnt(test2); i++)
		{
			rectPos.push_back(test2[i]);
		}
		
		for (int i = 0; i < rectPos.size(); i++)
		{
			if (DotInFigure(rectPos[i].x, rectPos[i].y, rectPos))
				rectPos.erase(rectPos.begin() + i);
			else
				continue;
		}

		Polygon(hdc, &rectPos[0], rectPos.size());
		// if (AddPolygonSpot_RightBottom(rectPos, rect2, test2))
		// 	Polygon(hdc, test2, rectPos.size() + rect2.size());
		// else
		// {
		// 	if (AddPolygonSpot_LeftUp(rectPos, rect2, test2))
		// 		Polygon(hdc, test2, rectPos.size() + rect2.size());
		// 	else
		// 	{
		// 		AddPolygonSpot_Another(rectPos, rect2, test2);
		// 		Polygon(hdc, test2, GetArrayCnt(test2));
		// 	}
		// }
		delete test;

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

void AddPolygonSpot_Another(vector<POINT>preRect, vector<POINT>newRect, POINT *test)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < preRect.size(); i++)
	{
		test[i].x = preRect[i].x;
		test[i].y = preRect[i].y;
	}
	//test[i].x = preRect[0].x;
	//test[i++].y = preRect[0].y;

	for (i; i < preRect.size() + newRect.size(); i++)
	{
		test[i].x = newRect[j].x;
		test[i].y = newRect[j++].y;
	}
	//test[i].x = newRect[0].x;
	//test[i].y = newRect[0].y;
}

int GetArrayCnt(POINT *test)
{
	int cnt = 0;
	int c = 0;
	while (1)
	{
		if (test[c].x >= 0 && test[c].y >= 0)
			cnt++;
		else
			break;
		c++;
	}
	return cnt;
}

bool DotInFigure(int x, int y, const vector<POINT> &p)
{
	int crosses = 0; // (x, y)부터 오른쪽 반직선을 출발해 다각형 p와의 교점의 개수
	for (int i = 0; i < p.size(); i++)
	{
		int j = (i + 1) % p.size();
		//점 (x, y)가 선분 (p[i], p[j])의 y좌표 사이에 있음
		if ((p[i].y > y) != (p[j].y > y)) {
			//atX는 점 B를 지나는 수평선과 선분 (p[i], p[j])의 교점
			double atX = (p[j].x - p[i].x)*(y - p[i].y) / (p[j].y - p[i].y) + p[i].x;
			//atX가 오른쪽 반직선과의 교점이 맞으면 교점의 개수를 증가시킨다.
			if (x < atX)
				crosses++;
		}
	}
	return crosses % 2 > 0;
}