// ch03_Control_Message.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "ch03_Control_Message.h"

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
    LoadStringW(hInstance, IDC_CH03_CONTROL_MESSAGE, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CH03_CONTROL_MESSAGE));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CH03_CONTROL_MESSAGE));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CH03_CONTROL_MESSAGE);
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

void CALLBACK TimeTest(HWND hWnd, UINT message, UINT_PTR idEvent, DWORD dwTime)	
{
	int breakPoint = 0;
}
// �� �������� ����Ǿ� �ֱ� ������ �̷��� �ۼ��ؾ� ��(���� �Ұ�)
// ���� ���̳� �Ű������� �ʿ��� ���, �������� ������ �����ؼ� �۾��ؾ���!
// Ÿ�̸� ����

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int movePos = 15;
	static POINT circleCenterPos;
	// �����̵�

	static RECT rectView;
	// �����̵�_�̵� ���� ����

	static bool isClick = FALSE;
	static int mouseX;
	static int mouseY;
	// ���콺 Ŭ�� ��ǥ ����



    switch (message)
    {
	case WM_CREATE:
		circleCenterPos.x = 100;
		circleCenterPos.y = 100;
		// �����̵�

		GetClientRect(hWnd, &rectView);	// â ũ��
		// �����̵�_�̵� ���� ����

		SetTimer(hWnd, 1, 100, NULL);	// Ÿ�̸� ����
		SetTimer(hWnd, 2, 200, TimeTest);	// Ÿ�̸� ����2
		// �Ű����� : ������ �ڵ� ��, Ÿ�̸� ���� ��(�̸�), �и���, Ÿ�̸Ӱ� ������ WM_TIMER �޽����� ���� �Լ� �̸� / NULL�̸� WndProc()�� WM_TIMER Msg ����
		// Ÿ�̸� ����

		break;

	case WM_SIZE:
		// int breakPoint = 0;
		// GetClientRect(hWnd, &rectView);	// â ũ��
		break;
	case WM_TIMER:
		// if (wParam == 1)
		// {
		// 	if (circleCenterPos.x + movePos < rectView.right)
		// 		circleCenterPos.x += movePos;
		// 	if (circleCenterPos.y + movePos < rectView.bottom)
		// 		circleCenterPos.y += movePos;
		// }
		// if (wParam == 2)
		// {
		// 	if (circleCenterPos.y - movePos > rectView.top)
		// 		circleCenterPos.y -= movePos;
		// }
		// InvalidateRect(hWnd, NULL, TRUE);
		// Ÿ�̸� ����

		if (isClick)
		{
			// �� : ��ġ���� �ʿ���
			if (circleCenterPos.y - movePos > mouseY)
				circleCenterPos.y -= movePos;
			if (circleCenterPos.y + movePos < mouseY)
				circleCenterPos.y += movePos;
			if (circleCenterPos.x - movePos > mouseX)
				circleCenterPos.x -= movePos;
			if (circleCenterPos.x + movePos < mouseX)
				circleCenterPos.x += movePos;

			InvalidateRect(hWnd, NULL, TRUE);
		}
		// ���콺 ��ǥ�� ���� �̵�
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

	case WM_LBUTTONDOWN:
		{
			mouseX = LOWORD(lParam);
			mouseY = HIWORD(lParam);
			// ���콺 ��ǥ ��
			
			SetTimer(hWnd, 3, 100, NULL);
			isClick = TRUE;
		}
		break;
	case WM_RBUTTONDOWN:
		{
			int breakPoint = 0;
		}
		break;
	case WM_LBUTTONUP:
		{
			int breakPoint = 0;
		}
		break;
	case WM_RBUTTONUP:
		{
			int breakPoint = 0;
		}
		break;
	case WM_MOUSEMOVE:
		{
			int breakPoint = 0;
		}
		break;
	// �ΰ��ӿ��� ���� ��� ���� : ��ư Ŭ���� �Ͼ����
	// �ΰ��ӿ��� ������ ������ : ��ư�� Ŭ���� ��, ���� ��ġ���� ��ư�� �������� ���� or �ٸ� ��ġ���� ��ư�� �������� ���
	// �̷������� ��Ȳ�� ���缭 ���콺 �̺�Ʈ�� �Ͼ�� ��
	// ���콺 �̺�Ʈ ����

	case WM_KEYDOWN:
		if (wParam == VK_UP)
			if (circleCenterPos.y  - movePos > rectView.top)
				circleCenterPos.y  -= movePos;
		if (wParam == VK_DOWN)
			if (circleCenterPos.y  + movePos < rectView.bottom)
				circleCenterPos.y  += movePos;
		if (wParam == VK_LEFT)
			if (circleCenterPos.x - movePos > rectView.left)
				circleCenterPos.x -= movePos;
		if (wParam == VK_RIGHT)
			if (circleCenterPos.x + movePos < rectView.right)
				circleCenterPos.x += movePos;
		InvalidateRect(hWnd, NULL, TRUE);
		break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

			Ellipse(hdc, circleCenterPos.x - movePos, circleCenterPos.y - movePos, circleCenterPos.x + movePos, circleCenterPos.y + movePos);

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
		KillTimer(hWnd, 1);	// Ÿ�̸� ����
		KillTimer(hWnd, 2);	// Ÿ�̸� ����
		KillTimer(hWnd, 3);
		// Ÿ�̸� ����
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
