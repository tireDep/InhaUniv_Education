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
// 이 형식으로 저장되어 있기 때문에 이렇게 작성해야 함(변경 불가)
// 리턴 값이나 매개변수가 필요할 경우, 전역변수 등으로 설정해서 작업해야함!
// 타이머 관련

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int movePos = 15;
	static POINT circleCenterPos;
	// 도형이동

	static RECT rectView;
	// 도형이동_이동 제한 관련

	static bool isClick = FALSE;
	static int mouseX;
	static int mouseY;
	// 마우스 클릭 좌표 관련



    switch (message)
    {
	case WM_CREATE:
		circleCenterPos.x = 100;
		circleCenterPos.y = 100;
		// 도형이동

		GetClientRect(hWnd, &rectView);	// 창 크기
		// 도형이동_이동 제한 관련

		SetTimer(hWnd, 1, 100, NULL);	// 타이머 생성
		SetTimer(hWnd, 2, 200, TimeTest);	// 타이머 생성2
		// 매개변수 : 윈도우 핸들 값, 타이머 구분 값(이름), 밀리초, 타이머가 보내는 WM_TIMER 메시지를 받을 함수 이름 / NULL이면 WndProc()가 WM_TIMER Msg 받음
		// 타이머 관련

		break;

	case WM_SIZE:
		// int breakPoint = 0;
		// GetClientRect(hWnd, &rectView);	// 창 크기
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
		// 타이머 관련

		if (isClick)
		{
			// ※ : 위치보정 필요함
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
		// 마우스 좌표로 도형 이동
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
			// 마우스 좌표 값
			
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
	// 인게임에서 총을 쏘고 있음 : 버튼 클릭시 일어나야함
	// 인게임에서 아이템 구매함 : 버튼을 클릭한 후, 같은 위치에서 버튼이 떼어지면 선택 or 다른 위치에서 버튼이 떼어지면 취소
	// 이런식으로 상황에 맞춰서 마우스 이벤트가 일어나야 함
	// 마우스 이벤트 관련

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
		KillTimer(hWnd, 1);	// 타이머 삭제
		KillTimer(hWnd, 2);	// 타이머 삭제
		KillTimer(hWnd, 3);
		// 타이머 관련
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
