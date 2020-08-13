// Omok.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Omok_Client.h"

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
    LoadStringW(hInstance, IDC_OMOK, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_OMOK));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_OMOK));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_OMOK);
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
      CW_USEDEFAULT, 0, 1100, 800, nullptr, nullptr, hInstance, nullptr);

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
#include <stdio.h>
#include <vector>

#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")

#define WM_ASYNC WM_USER+2
#define defMaxChat 22

using std::vector;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static int map[defArrSize][defArrSize];

	static vector<POINT> playerMark;
	static vector<bool> playerColor;

	static WSADATA wsaData;
	static SOCKET s;
	static SOCKADDR_IN addr = { 0 };

	static TCHAR msg[200];
	int msgLen;
	char buffer[100];

	static TCHAR str[100];
	static int count;

	static vector<TCHAR *> SaveMsg;

    switch (message)
    {
	case WM_CREATE:
		//AllocConsole();
		//freopen("CONOUT$", "wt", stdout);

		WSAStartup(MAKEWORD(2, 2), &wsaData);
		s = socket(AF_INET, SOCK_STREAM, 0);
		if (s == INVALID_SOCKET)
		{
			//MessageBox(NULL, _T("Socket Fail"), _T("Error"), MB_OK);
			return 0;
		}
		//else
		//	MessageBox(NULL, _T("Socket Success"), _T("Success"), MB_OK);

		addr.sin_family = AF_INET;
		addr.sin_port = 20;
		addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");


		if (connect(s, (LPSOCKADDR)&addr, sizeof(addr)) == SOCKET_ERROR)
		{
		//	MessageBox(NULL, _T("Connect Fail"), _T("Error"), MB_OK);
			return 0;
		}
		//else
		//	MessageBox(NULL, _T("Connect Success"), _T("Success"), MB_OK);

		WSAAsyncSelect(s, hWnd, WM_ASYNC, FD_READ);
		break;

	case WM_ASYNC:
		switch (lParam)
		{
		case FD_READ:
		{
			msgLen = recv(s, buffer, 99, 0);
			buffer[msgLen] = NULL;
#ifdef _UNICODE
			msgLen = MultiByteToWideChar(CP_ACP, 0, buffer, strlen(buffer), NULL, NULL);
			MultiByteToWideChar(CP_ACP, 0, buffer, strlen(buffer), msg, msgLen);
			msg[msgLen] = NULL;
#else
			strcpy_s(msg, buffer);
#endif
			// 파싱
			char tempBuffer[100];
			char *checkPakit;
			int tempSaveVal[5];
			int i = 0;
			bool isPassing = false;
			strcpy(tempBuffer, buffer);
			checkPakit = strtok(tempBuffer, "!");

			if (atoi(buffer) == -1)
			{
				isPassing = true;
				while (1)
				{
					checkPakit = strtok(NULL, "!");

					if (checkPakit == NULL)
						break;
					else
						tempSaveVal[i++] = atoi(checkPakit);
				}

				if (tempSaveVal[4] == 0)
				{
					map[tempSaveVal[0]][tempSaveVal[1]] = 1;
					playerColor.push_back(false);
					strcat(buffer, "0");	// false
				}
				else
				{
					map[tempSaveVal[0]][tempSaveVal[1]] = -1;
					playerColor.push_back(true);
					strcat(buffer, "1");	// true
				}
				playerMark.push_back({ tempSaveVal[2],tempSaveVal[3] });
			}
			// 파싱
			else
			{
				TCHAR *temp = new TCHAR[200];
				_tcscpy(temp, msg);
				SaveMsg.push_back(temp);

				if (SaveMsg.size() > defMaxChat)
					SaveMsg.erase(SaveMsg.begin());
			}
			break;
		}
		default:
			break;
		}
		InvalidateRgn(hWnd, NULL, false);
		break;

	case WM_CHAR:
	{
		if (wParam == VK_RETURN)
		{
			if (s == INVALID_SOCKET)
				return 0;
			else
			{
#ifdef  _UNICODE
				msgLen = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);
				WideCharToMultiByte(CP_ACP, 0, str, -1, buffer, msgLen, NULL, NULL);
#else
				strcpy_s(buffer, str);
				msgLen = strlen(buffer);
#endif //  _UNICODE
				send(s, (LPSTR)buffer, strlen(buffer) + 1, 0);
				count = 0;
				str[count] = NULL;
				InvalidateRgn(hWnd, NULL, false);
				return 0;
			}
		}

		if (wParam == VK_BACK && count > 0)
			count--;
		else
			str[count++] = wParam;
		str[count] = NULL;
	}
	InvalidateRgn(hWnd, NULL, false);
	break;

	case WM_LBUTTONDOWN:
		{
			int posX = LOWORD(lParam);
			int posY = HIWORD(lParam);
			int tempX, tempY;
			int rangeDistance = eMarkDiameter / 2;

			if ((posX >= eMapLeft - rangeDistance && posX <= eMapRight + rangeDistance)
				&& (posY >= eMapTop - rangeDistance && posY <= eMapBottom + rangeDistance))
			{
				tempX = posX / eMarkDistance - 1;
				tempY = posY / 19 / 2;

				int saveX = tempX * eMarkDistance + eMarkLeft + eMarkDiameter;
				int saveY = tempY * eMarkDistance + eMarkTop + eMarkDiameter;

				// 클릭이벤트
				int pakitCnt = 0;
				char temp[10] = { 0 };

				strcpy(buffer, "-1!!");	
				_itoa(tempX, temp, 10);
				strcat(buffer, temp);
				strcat(buffer, "!!");

				_itoa(tempY, temp, 10);
				strcat(buffer, temp);
				strcat(buffer, "!!");

				_itoa(saveX, temp, 10);
				strcat(buffer, temp);
				strcat(buffer, "!!");

				_itoa(saveY, temp, 10);
				strcat(buffer, temp);
				strcat(buffer, "!!");
				// 클릭이벤트

				send(s, (LPSTR)buffer, strlen(buffer) + 1, 0);
			}
			InvalidateRgn(hWnd, NULL, false);
		}
 		break;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            
			// 더블버퍼링
			RECT rectView;
			HDC memDc;
			HBITMAP hBit, oldBit;

			GetClientRect(hWnd, &rectView);
			memDc = CreateCompatibleDC(hdc);
			hBit = CreateCompatibleBitmap(hdc, rectView.right, rectView.bottom);
			oldBit = (HBITMAP)SelectObject(memDc, hBit);
			PatBlt(memDc, rectView.left, rectView.top, rectView.right, rectView.bottom, WHITENESS);
			// 더블버퍼링

			// 바둑판

			int j = 0;
			HBRUSH hBrush, oldBrush;
			hBrush = CreateSolidBrush(RGB(230, 186, 148));
			oldBrush = (HBRUSH)SelectObject(memDc, hBrush);
			Rectangle(memDc, 0, 0, 765, 741);
			Rectangle(memDc, 47, 35, 714, 705);

			for (int i = 2; i < 19; i++)
			{
				MoveToEx(memDc, 47, 37 * i, NULL);
				LineTo(memDc, 714, 37 * i);
				// 가로줄
			
				MoveToEx(memDc, (42 * i) - (5 * j), 36, NULL);
				LineTo(memDc, (42 * i) - (5 * j), 705);
				j++;
				// 세로줄
			}

			SelectObject(memDc, oldBrush);
			DeleteObject(hBrush);

			// 바둑판

			// 바둑판 점

			hBrush = CreateSolidBrush(RGB(0, 0, 0));
			oldBrush = (HBRUSH)SelectObject(memDc, hBrush);

			Ellipse(memDc, 42 + 37 * 3, 32 + 37 * 3, 52 + 37 * 3, 42 + 37 * 3);
			Ellipse(memDc, 42 + 37 * 9, 32 + 37 * 3, 52 + 37 * 9, 42 + 37 * 3);
			Ellipse(memDc, 42 + 37 * 15, 32 + 37 * 3, 52 + 37 * 15, 42 + 37 * 3);

			Ellipse(memDc, 42 + 37 * 3, 32 + 37 * 9, 52 + 37 * 3, 42 + 37 * 9);
			Ellipse(memDc, 42 + 37 * 9, 32 + 37 * 9, 52 + 37 * 9, 42 + 37 * 9);
			Ellipse(memDc, 42 + 37 * 15, 32 + 37 * 9, 52 + 37 * 15, 42 + 37 * 9);

			Ellipse(memDc, 42 + 37 * 3, 32 + 37 * 15, 52 + 37 * 3, 42 + 37 * 15);
			Ellipse(memDc, 42 + 37 * 9, 32 + 37 * 15, 52 + 37 * 9, 42 + 37 * 15);
			Ellipse(memDc, 42 + 37 * 15, 32 + 37 * 15, 52 + 37 * 15, 42 + 37 * 15);

			SelectObject(memDc, oldBrush);
			DeleteObject(hBrush);

			// 바둑판 점

			// playerDraw
			HBRUSH blackBrush, oldBrush1;
			HBRUSH whiteBrush, oldBrush2;

			for (int i = 0; i < playerMark.size(); i++)
			{
				if (playerColor[i] == false)
				{
					blackBrush = CreateSolidBrush(RGB(0, 0, 0));
					oldBrush1 = (HBRUSH)SelectObject(memDc, blackBrush);

					Ellipse(memDc, playerMark[i].x - eMarkDiameter, playerMark[i].y - eMarkDiameter, playerMark[i].x + eMarkDiameter, playerMark[i].y + eMarkDiameter);

					SelectObject(memDc, oldBrush1);
					DeleteObject(blackBrush);
				}
				else
				{
					whiteBrush = CreateSolidBrush(RGB(255, 255, 255));
					oldBrush2 = (HBRUSH)SelectObject(memDc, whiteBrush);

					Ellipse(memDc, playerMark[i].x - eMarkDiameter, playerMark[i].y - eMarkDiameter, playerMark[i].x + eMarkDiameter, playerMark[i].y + eMarkDiameter);

					SelectObject(memDc, oldBrush2);
					DeleteObject(whiteBrush);
				}
			}

			// playerDraw

			for (int i = 0; i < SaveMsg.size(); i++)
			{
				TextOut(memDc, 790, (i + 1) * 30, SaveMsg[i], (int)_tcslen(SaveMsg[i]));
			}

			if (_tcslen(str) != 0)
				TextOut(memDc, 790, 710, str, _tcslen(str));

			// 더블버퍼링
			BitBlt(hdc, 0, 0, rectView.right, rectView.bottom, memDc, 0, 0, SRCCOPY);

			SelectObject(memDc, oldBit);
			DeleteObject(hBit);
			DeleteDC(memDc);
			// 더블버퍼링

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
	{
		send(s, "quit!", strlen("quit!") + 1, 0);
		closesocket(s);
		WSACleanup();

		vector<TCHAR *>::iterator it;
		for (it = SaveMsg.begin(); it != SaveMsg.end();)
		{
			TCHAR *temp = *it;
			if (temp != NULL)
			{
				it = SaveMsg.erase(it);
				delete temp;
			}
			else
				it++;
		}
		//FreeConsole();
		PostQuitMessage(0);
	}
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
