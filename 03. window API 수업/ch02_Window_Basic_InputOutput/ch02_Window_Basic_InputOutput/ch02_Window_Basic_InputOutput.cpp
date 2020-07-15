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
	static TCHAR str[100];
	static int count;
	static int yPos;
	static RECT rt = { 0,0,1000,1000 };
	// 문자열

	// static SIZE size;	// 캐럿
    switch (message)
    {
	case WM_CREATE:
		count = 0;
		yPos = 0;
		// 문자열
		
		// CreateCaret(hWnd, NULL, 7, 16);
		// ShowCaret(hWnd);
		// 캐럿
		break;

	case WM_CHAR:	// 문자열
		{
			if (wParam == VK_BACK && count > 0)
				count--;
			else if (VK_RETURN == wParam)
			{
				count = 0;
				yPos += 20;
				rt = { 0, 0 + yPos, 1000, 1000 + yPos };
			}
			else
				str[count++] = wParam;
			str[count] = NULL;
			
			InvalidateRgn(hWnd, NULL, true);	// window 핸들링에 대해 다시 그리기
			// WM_PAINT 호출(함수 자체가 다시 실행됨) 
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

			// DrawCircle(hdc, 300, 300, 100);	
			// 원 생성 함수

			//DrawSunflower(hdc, 100, 100, 50, 5);
			// 해바라기 함수

			// RECT drawRect = { 100,100,300,300 };
			// DrawRectangle(hdc, drawRect.left, drawRect.top, drawRect.right, drawRect.bottom);
			// 사각형 생성 함수

			// RECT rect;
			// rect.left = 101;
			// rect.top = 101;
			// rect.right = 299;
			// rect.bottom = 299;	// 사각형 내부에 들어가기 위한 영역설정
			// DrawText(hdc, _T("Hello"), _tcsclen(_T("Hello")), &rect, DT_LEFT | DT_TOP | DT_SINGLELINE);
			// DrawText(hdc, _T("Hello"), _tcsclen(_T("Hello")), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			// DrawText(hdc, _T("Hello"), _tcsclen(_T("Hello")), &rect, DT_RIGHT | DT_BOTTOM | DT_SINGLELINE);

			// DrawText(hdc, str, _tcslen(str), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			// 사각형 내부에 문자 찍기

			// POINT point[5] = { { 10,150 }, { 250,30 }, { 500,150 }, { 350,300 }, { 150,300 } };	// 각각 좌표
			// Polygon(hdc, point, 5);
			// 폴리곤 생성

			// ---------------------------------------------------------
			// 별 찍기
			// [개념]
			// - 두 점 사이 직선 구하기
			// - 직선의 교차점 구하기
			// - 구한 교차점 point 리스트(Array)에 추가하기

			// 제공되는 것 : 거리, 원점
			int distance = 50;
			int midX = 50;
			int midY = 50;
			DrawStar(hdc, midX, midY, distance);
			// 별 찍기
			// ---------------------------------------------------------

			// ---------------------------------------------------------
			// 펜 변경 관련
			//HPEN hPen, hPen2, oldPen;
			//hPen = CreatePen(PS_DOT, 1, RGB(255, 0, 0));
			//hPen2 = CreatePen(PS_DASH, 1, RGB(0, 0, 255)); 
			//oldPen = (HPEN)SelectObject(hdc, hPen);
			//// hPen을 설정하고, 기존 정보를 oldPen에 저장함 
			//// oldPen = CreatePen(PS_SOLID, 1, RGE(0, 0, 0));
			//// 펜 생성 및 설정
			//
			//int distance = 100;
			//int midX = 100;
			//int midY = 100;
			//DrawStar(hdc, midX, midY, distance);
			//
			//SelectObject(hdc, hPen2);
			//// 펜 변경
			//
			//DrawCircle(hdc, 300, 300, 100);
			//
			//SelectObject(hdc, oldPen);	// 기존 세팅 돌려줌
			//DeleteObject(hPen);	// 펜 삭제
			//DeleteObject(hPen2);	// 펜 삭제
			//// 펜 변경 관련
			//// ---------------------------------------------------------
			//
			//// ---------------------------------------------------------
			//// 면 변경 관련
			//HBRUSH hBrush, oldBrush;
			//hBrush = CreateSolidBrush(RGB(250, 250, 0));
			////oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
			//
			//// DrawCircle(hdc, 300, 300, 100);
			//// 
			//// SelectObject(hdc, oldBrush);
			//// DeleteObject(hBrush);
			//
			//// hBrush = CreateSolidBrush(RGB(250, 250, 0));
			//oldBrush = (HBRUSH)SelectObject(hdc, GetStockObject(NULL_BRUSH));
			//
			//DrawCircle(hdc, 300, 300, 100);
			//
			//SelectObject(hdc, oldBrush);
			////DeleteObject(hBrush);
			//
			//// 면 변경 관련
			// ---------------------------------------------------------

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

void DrawStar(HDC hdc, int midX, int midY, int distance)
{
	POINT point1[5] = { 0 };
	point1[0] = { midX, midY};

	int degree = 72;
	AddPoint(degree, midX, midY, point1);

	// 크래머
	double a, b, c, d, e, f;
	int posX, posY;

	a = point1[0].y - point1[2].y;
	b = -(point1[0].x - point1[2].x);
	e = a*point1[0].x + b*point1[0].y;

	c = point1[1].y - point1[4].y;
	d = -(point1[1].x - point1[4].x);
	f = c*point1[1].x + d*point1[1].y;

	double divide = (a*d) - (b*c);
	posX = ((e*d) - (b*f)) / divide;
	posY = ((a*f) - (e*c)) / divide;

	POINT point2[5] = { 0 };
	point2[0] = { posX, posY };
	AddPoint(degree, midX, midY, point2);

	POINT result[10] = { point1[0], point2[0],point1[1],point2[1],point1[2],point2[2],point1[3],point2[3],point1[4],point2[4] };
	Polygon(hdc, result, 10);
}

void AddPoint(int degree, int midX, int midY, POINT point[])
{
	int addDeg = degree;
	double radian;
	int spotX;
	int spotY;
	for (int i = 1; i < 5; i++)
	{
		radian = degree * (M_PI / 180);
		degree += addDeg;

		spotX = (point[0].x - midX) * cos(radian) - (point[0].y - midY) * sin(radian) + midX;
		spotY = (point[0].x - midX) * sin(radian) + (point[0].y - midY) * cos(radian) + midY;

		point[i] = { spotX, spotY };
	}
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

/*
void DrawCircle(HDC hdc, int centerX, int centerY, int radius)
{
	// int yr = radius / 2;
	int posX1 = centerX - radius;
	int posY1 = centerY - radius;
	int posX2 = centerX + radius;
	int posY2 = centerY + radius;

	Ellipse(hdc, posX1, posY1, posX2, posY2);
}
*/

void DrawCircle(HDC hdc, int centerX, int centerY, int radius)
{
	Ellipse(hdc, centerX - radius, centerY - radius, centerX + radius, centerY + radius);
}

double DegreeToRadian(int arcDegree)
{
	return arcDegree * M_PI / 180;
}

void DrawSunflower(HDC hdc, int centerX, int centerY, int centerR, int num)
{
	DrawCircle(hdc, centerX, centerY, centerR);

	int arcDegree = 360 / num;
	double rad = DegreeToRadian(arcDegree);
	int arc2 = arcDegree / 2;
	double rad2 = DegreeToRadian(arc2);
	int sonR = centerR * sin(rad2) / (1 - sin(rad2));

	double sonX = centerX;
	double sonY = centerY + centerR + sonR;
	for (int i = 0; i < num; i++)
	{
		DrawCircle(hdc, sonX, sonY, sonR);
		double tempX = cos(rad) * (sonX - centerX) - sin(rad) * (sonY - centerY);
		double tempY = sin(rad) * (sonX - centerX) + cos(rad) * (sonY - centerY);
		// 삼각함수 회전변환
		sonX = tempX + centerX;
		sonY = tempY + centerY;
	}
}

void DrawRectangle(HDC hdc, int left, int top, int right, int bottom)
{
	Rectangle(hdc, left, top, right, bottom);;
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
