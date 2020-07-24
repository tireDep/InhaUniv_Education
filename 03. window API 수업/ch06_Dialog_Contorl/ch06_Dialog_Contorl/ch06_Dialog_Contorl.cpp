// ch06_Dialog_Contorl.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "ch06_Dialog_Contorl.h"

#define MAX_LOADSTRING 100

// >>
BOOL CALLBACK Dlg6_1Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);

// HINSTANCE g_hInst;
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
    if (!InitInstance (hInstance, nCmdShow))
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CH06_DIALOG_CONTORL));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CH06_DIALOG_CONTORL);
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

RECT rect;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
    {
	case WM_CREATE:
		GetWindowRect(hWnd, &rect);

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
		GetWindowRect(hWnd, &rect);
		break;

	case WM_RBUTTONDOWN:
		DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, Dlg6_1Proc);
		break;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
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
			// CheckRadioButton(hDlg, IDC_RADIO_WOMAN, IDC_RADIO_MAN, IDC_RADIO_MAN);	// 라디오 버튼은 미리 하나 체크되어있어야 함
		CheckRadioButton(hDlg, IDC_RADIO_WOMAN, IDC_RADIO_MAN, IDC_RADIO_WOMAN);
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
			SetBkMode(hdc, TRANSPARENT);	// 배경 투명
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
			check[0] = 1 - check[0];	// 0, 1
			break;

		case IDC_CHECK_MUSIC:
			check[1] = 1 - check[1];	// 0, 1
			break;

		case IDC_CHECK_GAME:
			check[2] = 1 - check[2];	// 0, 1
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

		default:
			break;
		}
		break;
	}

	return FALSE;
}
