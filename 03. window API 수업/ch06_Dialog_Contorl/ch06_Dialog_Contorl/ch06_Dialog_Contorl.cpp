// ch06_Dialog_Contorl.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "ch06_Dialog_Contorl.h"

#define MAX_LOADSTRING 100

// >>
BOOL CALLBACK Dlg6_1Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);

// HINSTANCE g_hInst;
// <<

// >> : 윈도우 분할
int pushBtn;
#define IDC_CHILD_BTN 999

#define IDC_CIRCLE_BTN 50
#define IDC_RECTANGLE_BTN 70
#define IDC_STAR_BTN 90

#define _USE_MATH_DEFINES    // use M_PI
#include<math.h>

HWND childeHwnd[3];
LRESULT CALLBACK ChildWndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK ChildWndProc2(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK ChildWndProc3(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

void DrawStar(HDC hdc, int midX, int midY, int distance);
void AddPoint(int degree, int midX, int midY, POINT point[]);
// <<

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
	LoadStringW(hInstance, IDC_CH06_DIALOG_CONTORL, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CH06_DIALOG_CONTORL));

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

	return (int)msg.wParam;
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

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CH06_DIALOG_CONTORL));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_CH06_DIALOG_CONTORL);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
	RegisterClassExW(&wcex);

	wcex.lpfnWndProc = ChildWndProc;
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = _T("Child1");
	RegisterClassExW(&wcex);

	wcex.lpfnWndProc = ChildWndProc2;
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = _T("Child2");
	RegisterClassExW(&wcex);

	wcex.lpfnWndProc = ChildWndProc3;
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = _T("Child3");
	RegisterClassExW(&wcex);

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
RECT rectView;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
		GetWindowRect(hWnd, &rectView);

		// >> :
		childeHwnd[0] = CreateWindowEx(WS_EX_CLIENTEDGE, _T("Child1"), NULL, WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN, 0, 0, rectView.right / 2 - 1, rectView.bottom / 2 + 1, hWnd, NULL, hInst, NULL);
		childeHwnd[1] = CreateWindowEx(WS_EX_CLIENTEDGE, _T("Child2"), NULL, WS_CHILD | WS_VISIBLE | WS_EX_APPWINDOW, 0, rectView.bottom / 2 + 1, rectView.right, rectView.bottom / 2 - 1, hWnd, NULL, hInst, NULL);
		childeHwnd[2] = CreateWindowEx(WS_EX_CLIENTEDGE, _T("Child3"), NULL, WS_CHILD | WS_VISIBLE, rectView.right / 2 + 1, 0, rectView.right, rectView.bottom, hWnd, NULL, hInst, NULL);
		// << 
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

	case WM_SIZE:
		GetWindowRect(hWnd, &rectView);
		break;

	case WM_RBUTTONDOWN:
		DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, Dlg6_1Proc);
		break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

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
	{
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
			EndDialog(hDlg, LOWORD(wParam));
		return (INT_PTR)TRUE;
	}
	break;
	}
	return (INT_PTR)FALSE;
}

BOOL CALLBACK Dlg6_1Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	RECT dlgRect;
	GetWindowRect(hDlg, &dlgRect);

	HDC hdc;
	TCHAR tStr[256];

	// >>

	static int check[3], radio;
	TCHAR hobby[][30] = { _T("독서"), _T("음악감상"), _T("게임") };
	TCHAR sex[][30] = { _T("여자"),_T("남자") };
	TCHAR output[200];

	// <<

	// >>
	static HWND hCombo;
	static int selection;
	TCHAR name[30];
	// <<

	int width = (dlgRect.right - dlgRect.left);
	int height = (dlgRect.bottom - dlgRect.top);
	switch (iMsg)
	{
	case WM_INITDIALOG:
	{
		//HWND hButton;
		//hButton = GetDlgItem(hDlg, IDC_BTN_PRINT);
		//EnableWindow(hButton, FALSE);
		//SetWindowPos(hDlg, NULL, (rect.right + rect.left) * 0.5 - width * 0.5, (rect.bottom + rect.top) * 0.5 - height * 0.5, 0, 0, SWP_NOSIZE);

		// >>
		CheckRadioButton(hDlg, IDC_RADIO_WOMAN, IDC_RADIO_MAN, IDC_RADIO_MAN);    // 라디오 버튼은 미리 하나 체크되어있어야 함
																				  // <<

																				  // >>
		hCombo = GetDlgItem(hDlg, IDC_COMBO_LIST);
		// <<
	}
	return (INT_PTR)TRUE;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_BUTTON_COPY:
			GetDlgItemText(hDlg, IDC_EDIT_INPUT, tStr, 256);
			SetDlgItemText(hDlg, IDC_EDIT_OUTPUT, tStr);
			break;

		case IDC_BUTTON_DELETE:
			SetDlgItemText(hDlg, IDC_EDIT_INPUT, _T(""));
			SetDlgItemText(hDlg, IDC_EDIT_OUTPUT, _T(""));
			break;

		case IDC_BTN_PRINT:
			hdc = GetDC(hDlg);
			SetBkMode(hdc, TRANSPARENT);    // 배경 투명
			TextOut(hdc, 10, 10, _T("Hello Dialog"), 12);
			ReleaseDC(hDlg, hdc);
			break;

		case IDC_BTN_EXIT:
			EndDialog(hDlg, 0);
			break;

		case IDCANCEL:
			EndDialog(hDlg, 0);
			break;

			// >>

		case IDC_CHECK_READING:
			check[0] = 1 - check[0];    // 0, 1
			break;

		case IDC_CHECK_MUSIC:
			check[1] = 1 - check[1];    // 0, 1
			break;

		case IDC_CHECK_GAME:
			check[2] = 1 - check[2];    // 0, 1
			break;

		case IDC_RADIO_WOMAN:
			radio = 0;
			break;

		case IDC_RADIO_MAN:
			radio = 1;
			break;

		case IDC_BUTTON_PRINT:
			_stprintf_s(output, _T("선택한 취미는 %s %s %s 입니다.\r\n선택한 성별은 %s 입니다."),
				check[0] ? hobby[0] : _T(""),
				check[1] ? hobby[1] : _T(""),
				check[2] ? hobby[2] : _T(""),
				sex[radio]);
			SetDlgItemText(hDlg, IDC_EDIT_SAMPLE, output);
			break;
			// <<

			// >>
		case IDC_BUTTON_INSERT:
			GetDlgItemText(hDlg, IDC_EDIT_NAME, name, 20);
			if (_tcscmp(name, _T("")))
			{
				SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)name);    // 콤보 박스에 추가
				return 0;
			}
			break;

		case IDC_BUTTON_REMOVE:
			SendMessage(hCombo, CB_DELETESTRING, selection, 0);    // 콤보박스에서 현재 선택된 것 삭제
			break;

		case IDC_COMBO_LIST:
			if (HIWORD(wParam) == CBN_SELCHANGE)
				selection = SendMessage(hCombo, CB_GETCURSEL, 0, 0);
			break;
			// <<

		default:
			break;
		}
		break;
	}

	return FALSE;
}

LRESULT CALLBACK ChildWndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	int posy = 0, posx = 0;
	switch (iMsg)
	{
	case WM_CREATE:
		break;

	case WM_TIMER:
		break;

	case WM_LBUTTONDOWN:
	{
		posx = LOWORD(lParam);
		posy = HIWORD(lParam);
		HDC hdc = GetDC(hWnd);

		switch (pushBtn)
		{
		case IDC_CIRCLE_BTN:
			Ellipse(hdc, posx, posy, posx + 50, posy + 50);
			break;
		case IDC_RECTANGLE_BTN:
			Rectangle(hdc, posx, posy, posx + 50, posy + 50);
			break;
		case IDC_STAR_BTN:
			DrawStar(hdc, posx, posy, 50);
			break;
		}
		ReleaseDC(hWnd, hdc);
		InvalidateRect(hWnd, NULL, false);
	}
	break;

	case WM_PAINT:
		break;

	case WM_DESTROY:
		break;

	default:
		break;
	}

	return DefWindowProc(hWnd, iMsg, wParam, lParam);
}

LRESULT CALLBACK ChildWndProc2(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_CREATE:
		SetTimer(hWnd, 0, 100, NULL);
		break;

	case WM_TIMER:
		InvalidateRect(hWnd, NULL, false);
		break;

	case WM_PAINT:
	{
		switch (pushBtn)
		{
		case IDC_CIRCLE_BTN:
		{
			HDC hdc = GetDC(hWnd);
			Ellipse(hdc, 50, 50, 150, 150);
			ReleaseDC(hWnd, hdc);
			return 0;
		}
		break;

		case IDC_RECTANGLE_BTN:
		{
			HDC hdc = GetDC(hWnd);
			Rectangle(hdc, 200, 50, 300, 150);
			ReleaseDC(hWnd, hdc);
			return 0;
		}
		break;

		case IDC_STAR_BTN:
		{
			HDC hdc = GetDC(hWnd);
			DrawStar(hdc, 400, 100, 75);
			ReleaseDC(hWnd, hdc);
			return 0;
		}
		break;
		}
	}
	break;


	case WM_DESTROY:
		KillTimer(hWnd, 0);
		break;

	default:
		break;
	}

	return DefWindowProc(hWnd, iMsg, wParam, lParam);
}

LRESULT CALLBACK ChildWndProc3(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HWND hButton;
	HWND cButton, rButton, sButton;

	switch (iMsg)
	{
	case WM_CREATE:
		cButton = CreateWindow(_T("Button"), _T("원"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 0, 0, 100, 25, hWnd, (HMENU)IDC_CIRCLE_BTN, hInst, NULL);
		rButton = CreateWindow(_T("Button"), _T("사각형"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 100, 0, 100, 25, hWnd, (HMENU)IDC_RECTANGLE_BTN, hInst, NULL);
		sButton = CreateWindow(_T("Button"), _T("별"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 200, 0, 100, 25, hWnd, (HMENU)IDC_STAR_BTN, hInst, NULL);
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_CIRCLE_BTN:
			pushBtn = IDC_CIRCLE_BTN;
			break;

		case IDC_RECTANGLE_BTN:
			pushBtn = IDC_RECTANGLE_BTN;
			break;

		case IDC_STAR_BTN:
			pushBtn = IDC_STAR_BTN;
			break;

		default:
			break;
		}
		break;

	case WM_DESTROY:
		break;

	default:
		break;
	}

	return DefWindowProc(hWnd, iMsg, wParam, lParam);
}

void DrawStar(HDC hdc, int midX, int midY, int distance)
{
	int _x = midX;
	int _y = midY;
	int _rnd = distance;

	POINT point1[5] = { 0 };
	point1[0] = { _x, _y - _rnd };

	int degree = 72;
	AddPoint(degree, _x, _y, point1);

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
	AddPoint(degree, _x, _y, point2);

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
