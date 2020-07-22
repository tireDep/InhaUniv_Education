// ch05_Accelerator_Bitmap.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "ch05_Accelerator_Bitmap.h"

#include<commdlg.h>

#pragma comment(lib, "msimg32.lib")

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


// ------------------------------------------------ >>

HBITMAP hBackImage;
BITMAP bitBack;

HBITMAP hTransparentImage;
BITMAP bitTransparent;

HBITMAP hAniImage;
BITMAP bitAni;
const int Sprite_Size_x = 57;	// 이미지 가로 크기 / 이미지 수
const int Sprite_Size_y = 52;	// 이미지 세로 크기 / 이미지 수
int runFrameMax = 0;
int runFrameMin = 0;
int curFrame = runFrameMin;

RECT rectView;
void DrawRectText(HDC hdc);

HBITMAP hDoubleBufferImage;

void CreateBitmap();
void DrawBitmap(HWND hWnd, HDC hdc);
void DeleteBitmap();

void UpdateFrame(HWND hWnd);

VOID CALLBACK AniProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime);

void DrawBitmapDoubleBuffering(HWND hWnd, HDC hdc);

// ------------------------------------------------ <<

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
    LoadStringW(hInstance, IDC_CH05_ACCELERATOR_BITMAP, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CH05_ACCELERATOR_BITMAP));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CH05_ACCELERATOR_BITMAP));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CH05_ACCELERATOR_BITMAP);
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
    switch (message)
    {
	case WM_CREATE:
		CreateBitmap();
		// SetTimer(hWnd, 0, 50, NULL);
		SetTimer(hWnd, 0, 50, AniProc);
		GetClientRect(hWnd, &rectView);
		break;

	case WM_SIZE:
		break;

	// case WM_TIMER:
	// 	UpdateFrame(hWnd);
	// 	InvalidateRect(hWnd, NULL, FALSE);
	// 	break;

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
            
			// DrawBitmap(hWnd, hdc);
			
			DrawBitmapDoubleBuffering(hWnd, hdc);

			DrawRectText(hdc);

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:

		DeleteBitmap();
		KillTimer(hWnd, 0);
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

// ------------------------------------------------------------- >>

void CreateBitmap()
{
	{
		hBackImage = (HBITMAP)LoadImage(NULL, TEXT("../Image/Marbles.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	
		GetObject(hBackImage, sizeof(BITMAP), &bitBack);
	}
	// Bitmap Img

	{
		hTransparentImage = (HBITMAP)LoadImage(NULL, TEXT("../Image/Zero_Run.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		GetObject(hTransparentImage, sizeof(BITMAP), &bitTransparent);
	}
	// Magenta Img

	{
		hAniImage = (HBITMAP)LoadImage(NULL, TEXT("../Image/Zero_Run.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		GetObject(hAniImage, sizeof(BITMAP), &bitAni);
		
		// 달리는 애니메이션만
		runFrameMax = bitAni.bmWidth / Sprite_Size_x - 1;	// 인덱스
		runFrameMin = 2;
		curFrame = runFrameMin;
	}
	// Animation Img
}

void DrawBitmap(HWND hWnd, HDC hdc)
{
	{
		HDC hMemDC;	// back Buffer
		HBITMAP hOldBitmap;
		int bx, by;
	
		hMemDC = CreateCompatibleDC(hdc);
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hBackImage);
		bx = bitBack.bmWidth;
		by = bitBack.bmHeight;
	
		BitBlt(hdc, 0, 0, bx, by, hMemDC, 0, 0, SRCCOPY);
	
		SelectObject(hMemDC, hOldBitmap);
		DeleteDC(hMemDC);
	}
	// Bitmap Img

	{
		HDC hMemDC2;
		HBITMAP hOldBitmap2;
		int bx, by;

		hMemDC2 = CreateCompatibleDC(hdc);
		hOldBitmap2 = (HBITMAP)SelectObject(hMemDC2, hTransparentImage);
		bx = bitTransparent.bmWidth;
		by = bitTransparent.bmHeight;

		//BitBlt(hdc, 0, 0, bx, by, hMemDC2, 0, 0, SRCCOPY);

		TransparentBlt(hdc, 0, 0, bx, by, hMemDC2, 0, 0, bx, by, RGB(255, 0, 255));
		// Magenta 제거

		SelectObject(hMemDC2, hOldBitmap2);
		DeleteDC(hMemDC2);
	}
	// Magenta Img

	{
		HDC hMemDC3;
		HBITMAP hOldBitmap3;
		int bx, by;

		hMemDC3 = CreateCompatibleDC(hdc);
		hOldBitmap3 = (HBITMAP)SelectObject(hMemDC3, hAniImage);
		bx = bitAni.bmWidth	/ 16;	// 이미지 수로 나눠줌 
		by = bitAni.bmHeight / 2;	// 이미지 수로 나눠줌 

		int xStart = curFrame * bx;
		int yStart = 0;

		TransparentBlt(hdc, 0, 150, bx, by, hMemDC3, xStart, yStart, bx, by, RGB(255, 0, 255));

		SelectObject(hMemDC3, hOldBitmap3);
		DeleteDC(hMemDC3);
	}
	// Animation Img
}

void DeleteBitmap()
{
	DeleteObject(hBackImage);
	// Bitmap Img

	DeleteObject(hTransparentImage);
	// Magenta Img

	DeleteObject(hAniImage);
	// Magenta Img
}

void UpdateFrame(HWND hWnd)
{
	curFrame++;
	//curFrame %= (runFrameMax - runFrameMin);
	//curFrame += runFrameMin;
	if(curFrame > runFrameMax)
		curFrame = runFrameMin;
}

int posY = 0;

VOID CALLBACK AniProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{
	UpdateFrame(hWnd);

	{
		posY += 5;
		if (posY > rectView.bottom) posY = 0;
		// 창 이동과 상관없이 posY 증가
	}

	InvalidateRect(hWnd, NULL, FALSE);
	return;
}

void DrawRectText(HDC hdc)
{
	TCHAR strTest[] = _T("TEXT");
	TextOut(hdc, 10, posY, strTest, _tcslen(strTest));
	
}

void DrawBitmapDoubleBuffering(HWND hWnd, HDC hdc)
{
	HDC hMemDC;	// back Buffer
	HBITMAP hOldBitmap;
	int bx, by;

	HDC hMemDC2;
	HBITMAP hOldBitmap2;

	hMemDC = CreateCompatibleDC(hdc);
	if (hDoubleBufferImage == NULL)
		hDoubleBufferImage = CreateCompatibleBitmap(hdc, rectView.right, rectView.bottom);
	// hMemDc에 이미지 그림
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hDoubleBufferImage);

	{
		hMemDC2 = CreateCompatibleDC(hMemDC);
		hOldBitmap2 = (HBITMAP)SelectObject(hMemDC2, hBackImage);
		bx = bitBack.bmWidth;
		by = bitBack.bmHeight;

		BitBlt(hMemDC, 0, 0, bx, by, hMemDC2, 0, 0, SRCCOPY);

		SelectObject(hMemDC2, hOldBitmap2);
		DeleteDC(hMemDC2);
	}
	// Bitmap Img

	{
		hMemDC2 = CreateCompatibleDC(hMemDC);
		hOldBitmap2 = (HBITMAP)SelectObject(hMemDC2, hTransparentImage);
		bx = bitTransparent.bmWidth;
		by = bitTransparent.bmHeight;

		TransparentBlt(hMemDC, 0, 0, bx, by, hMemDC2, 0, 0, bx, by, RGB(255, 0, 255));
		// Magenta 제거

		SelectObject(hMemDC2, hOldBitmap2);
		DeleteDC(hMemDC2);
	}
	// Magenta Img

	{
		hMemDC2 = CreateCompatibleDC(hMemDC);
		hOldBitmap2 = (HBITMAP)SelectObject(hMemDC2, hAniImage);
		bx = bitAni.bmWidth / 16;	// 이미지 수로 나눠줌 
		by = bitAni.bmHeight / 2;	// 이미지 수로 나눠줌 

		int xStart = curFrame * bx;
		int yStart = 0;

		TransparentBlt(hMemDC, 0, 150, bx, by, hMemDC2, xStart, yStart, bx, by, RGB(255, 0, 255));

		SelectObject(hMemDC2, hOldBitmap2);
		DeleteDC(hMemDC2);
	}
	// Animation Img

	BitBlt(hdc, 0, 0, rectView.right, rectView.bottom, hMemDC, 0, 0, SRCCOPY);
	
	SelectObject(hMemDC, hOldBitmap);
	//DeleteObject(hMemDC);
	//DeleteObject(hOldBitmap);
}
// ------------------------------------------------------------- <<