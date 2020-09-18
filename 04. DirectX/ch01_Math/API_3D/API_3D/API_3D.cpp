// API_3D.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "API_3D.h"

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
    LoadStringW(hInstance, IDC_API_3D, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_API_3D));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_API_3D));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_API_3D);
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
	static RECT rectView;
    switch (message)
    {
	case WM_CREATE:
		AllocConsole();
		freopen("CONIN$", "rb", stdin);
		freopen("CONOUT$", "wb", stdout);
		freopen("CONOUT$", "wb", stderr);

		GetClientRect(hWnd, &rectView);
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

			cVector3 eye(0.0f,5.0f,10.0f);
			cVector3 lookAt(0.0f, 0.0f, 0.0f);
			cVector3 up(0, 1, 0); 

			// // >> world
			// cMatrix scaleMat(4);
			// scaleMat = cMatrix::Identity(4);
			// scaleMat = scaleMat * 2;
			// 
			// scaleMat.Print();
			// 
			// cVector3 rotateVec(45 * (3.14 / 180), 45 * (3.14 / 180), 45 * (3.14 / 180));
			// cMatrix rotateMat(4);
			// rotateMat = cMatrix::Identity(4);
			// rotateMat = cMatrix::RotationX(rotateVec);
			// 
			// rotateMat.Print();
			// 
			// cVector3 transVec(1, 1, 1);
			// cMatrix transMat(4);
			// transMat = cMatrix::Identity(4);
			// transMat = transMat.Translation(transVec);
			// 
			// transMat.Print();
			// 
			// cMatrix worldMat(4);
			// worldMat.SetZero();
			// worldMat.Print();
			// worldMat = scaleMat * rotateMat * transMat;
			// worldMat.Print();
			// // << world

			cMatrix worldMat(4);
			worldMat = worldMat.Identity(4);

			cMatrix viewMat = cMatrix::View(eye, lookAt, up);
			cMatrix projecMat = cMatrix::Projection(3.14 * 0.5f, rectView.right / rectView.bottom, 1, 1000);
			cMatrix viewPortMat = cMatrix::ViewPort(0, 0, 640, 480, 0, 1);

			cVector3 v1(1, 1, 1);
			cVector3 v2(1, 1, -1);
			cVector3 v3(-1, 1, -1);
			cVector3 v4(-1, 1, 1);

			cVector3 v5(1, -1, 1);
			cVector3 v6(1, -1, -1);
			cVector3 v7(-1, -1, -1);
			cVector3 v8(-1, -1, 1);

			// cVector3 v5(2, -2, 2);
			// cVector3 v6(2, -2, -2);
			// cVector3 v7(-2, -2, -2);
			// cVector3 v8(-2, -2, 2);

			cMatrix resultMat = (worldMat * viewMat) * (projecMat * viewPortMat);	// s * r * t
			resultMat.Print();

			v1 = cVector3::TransformCoord(v1, resultMat);
			//v1 = cVector3::TransformCoord(v1, viewPortMat);

			v2 = cVector3::TransformCoord(v2, resultMat);
			//v2 = cVector3::TransformCoord(v2, viewPortMat);

			v3 = cVector3::TransformCoord(v3, resultMat);
			//v3 = cVector3::TransformCoord(v3, viewPortMat);

			v4 = cVector3::TransformCoord(v4, resultMat);
			//v4 = cVector3::TransformCoord(v4, viewPortMat);

			v5 = cVector3::TransformCoord(v5, resultMat);
			//v5 = cVector3::TransformCoord(v5, viewPortMat);

			v6 = cVector3::TransformCoord(v6, resultMat);
			//v6 = cVector3::TransformCoord(v6, viewPortMat);

			MoveToEx(hdc, v1.GetVectorX(), v1.GetVectorY(), NULL);
			LineTo(hdc, v2.GetVectorX(), v2.GetVectorY());

			MoveToEx(hdc, v2.GetVectorX(), v2.GetVectorY(), NULL);
			LineTo(hdc, v3.GetVectorX(), v3.GetVectorY());

			MoveToEx(hdc, v3.GetVectorX(), v3.GetVectorY(), NULL);
			LineTo(hdc, v4.GetVectorX(), v4.GetVectorY());

			MoveToEx(hdc, v4.GetVectorX(), v4.GetVectorY(), NULL);
			LineTo(hdc, v1.GetVectorX(), v1.GetVectorY());

			MoveToEx(hdc, v5.GetVectorX(), v5.GetVectorY(), NULL);
			LineTo(hdc, v6.GetVectorX(), v6.GetVectorY());


			// Rectangle(hdc, 100, 100, 250, 250);

            EndPaint(hWnd, &ps);
        }
        break;

    case WM_DESTROY:
		FreeConsole();

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
