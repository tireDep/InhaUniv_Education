// ch09_WindowSocektPrograming_WinServer.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "ch09_WindowSocektPrograming_WinServer.h"

// >>
#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")

#include <stdio.h>
#define WM_ASYNC WM_USER+2
// <<

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

// >> 
int WinServer();
// <<
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
    LoadStringW(hInstance, IDC_CH09_WINDOWSOCEKTPROGRAMING_WINSERVER, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CH09_WINDOWSOCEKTPROGRAMING_WINSERVER));

	// return WinServer();
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CH09_WINDOWSOCEKTPROGRAMING_WINSERVER));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CH09_WINDOWSOCEKTPROGRAMING_WINSERVER);
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

#include <vector>
using std::vector;
using std::iterator;

#define MAX_CLIENT 100

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static WSADATA wsaData;
	static SOCKET s, cs;
	static TCHAR msg[200];
	static SOCKADDR_IN addr = { 0 }, c_addr;
	int size, msgLen;
	char buffer[100];

	static TCHAR str[100];
	static int count;

	static vector<TCHAR *> SaveMsg;

	static SOCKET clientArray[MAX_CLIENT];
	static int iClientCnt = 0;

    switch (message)
    {
	case WM_CREATE:
		WSAStartup(MAKEWORD(2, 2), &wsaData);
		s = socket(AF_INET, SOCK_STREAM, 0);
		if (s == INVALID_SOCKET)
		{
			MessageBox(NULL, _T("Socket Fail"), _T("Error"), MB_OK);
			return 0;
		}
		else
			MessageBox(NULL, _T("Socket Success"), _T("Success"), MB_OK);
		addr.sin_family = AF_INET;
		addr.sin_port = 20;
		addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");


		if (bind(s, (LPSOCKADDR)&addr, sizeof(addr)))
		{
			MessageBox(NULL, _T("Binding Fail"), _T("Error"), MB_OK);
			return 0;
		}
		else
			MessageBox(NULL, _T("Binding Success"), _T("Success"), MB_OK);

		WSAAsyncSelect(s, hWnd, WM_ASYNC, FD_ACCEPT);

		if (listen(s, 5) == -1)
		{
			MessageBox(NULL, _T("Binding Fail"), _T("Error"), MB_OK);
			return 0;
		}
		else
			MessageBox(NULL, _T("Binding Success"), _T("Success"), MB_OK);
		break;
	
	case WM_ASYNC:
		switch (lParam)
		{
		case FD_ACCEPT:
			size = sizeof(c_addr);
			cs = accept(s, (LPSOCKADDR)&c_addr, &size);
			if (iClientCnt < MAX_CLIENT)
			{
				WSAAsyncSelect(cs, hWnd, WM_ASYNC, FD_READ);
				clientArray[iClientCnt++] = cs;
			}
			else
				closesocket(cs);
			break;

		case FD_READ:
		{
			int csTemp;
			for (int i = 0; i < iClientCnt; i++)
			{
				msgLen = recv(clientArray[i], buffer, 99, 0);
				if (msgLen != -1)
				{
					csTemp = clientArray[i];
					buffer[msgLen + 1] = NULL;
					break;
				}
			}
#ifdef _UNICODE
			msgLen = MultiByteToWideChar(CP_ACP, 0, buffer, strlen(buffer), NULL, NULL);
			MultiByteToWideChar(CP_ACP, 0, buffer, strlen(buffer), msg, msgLen);
			msg[msgLen] = NULL;
#else
			strcpy_s(msg, buffer);
#endif
			char clientTemp[100];
			char changeNum[100];
			sprintf(changeNum, "%d", csTemp);

			strcpy(clientTemp, "Client ");
			strcat(clientTemp, changeNum);
			strcat(clientTemp, " : ");
			strcat(clientTemp, buffer);

			for (int i = 0; i < iClientCnt; i++)
				send(clientArray[i], (LPSTR)clientTemp, strlen(clientTemp) + 1, 0);

			TCHAR *temp = new TCHAR[200];
			msgLen = MultiByteToWideChar(CP_ACP, 0, clientTemp, strlen(clientTemp), NULL, NULL);
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, clientTemp, strlen(clientTemp), temp, msgLen);
			temp[msgLen] = NULL;

			SaveMsg.push_back(temp);

			if (SaveMsg.size() > 30)
				SaveMsg.erase(SaveMsg.begin());

			InvalidateRgn(hWnd, NULL, true);
		}
			break;
		default:
			break;
		}
		break;

	case WM_CHAR:
	{
		if (wParam == VK_RETURN)
		{
			if (cs == INVALID_SOCKET)
				return 0;
			else
			{
#ifdef  _UNICODE
				msgLen = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);
				WideCharToMultiByte(CP_ACP, 0, str, -1, buffer, msgLen, NULL, NULL);
#else
				strcpy_s(buffer, str);

#endif //  _UNICODE
				char serverTemp[100] = "Server : ";
				strcat(serverTemp, buffer);

				for(int i=0; i < iClientCnt; i++)
					send(clientArray[i], (LPSTR)serverTemp, strlen(serverTemp) + 1, 0);

				TCHAR *temp = new TCHAR[200];
				_tcscpy(temp, _T("Server : "));
				_tcscat(temp, str);
				SaveMsg.push_back(temp);

				if (SaveMsg.size() > 30)
					SaveMsg.erase(SaveMsg.begin());

				count = 0;
				str[count] = NULL;
				InvalidateRgn(hWnd, NULL, true);
				return 0;
			}
		}
		str[count++] = wParam;
		str[count] = NULL;
	}
	InvalidateRgn(hWnd, NULL, true);
	break;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
			for (int i = 0; i < SaveMsg.size(); i++)
			{
				TextOut(hdc, 0, (i + 1) * 30, SaveMsg[i], (int)_tcslen(SaveMsg[i]));
			}

			TextOut(hdc, 0, 0, str, (int)_tcslen(str));

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
	{
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


// >>
int WinServer()
{
	WSADATA wsaData;
	SOCKET s;
	SOCKADDR_IN addr = { 0 };
	TCHAR message[256];

	WSAStartup(MAKEWORD(2, 2), &wsaData);
	s = socket(AF_INET, SOCK_STREAM, 0);
	if (s == INVALID_SOCKET)
	{
		MessageBox(NULL, _T("Socket Fail"), _T("Error"), MB_OK);
		return 0;
	}
	else
	{
		MessageBox(NULL, _T("Socket Success"), _T("Success"), MB_OK);
	}
	addr.sin_family = AF_INET;
	addr.sin_port = 20;
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");


	 if (bind(s, (LPSOCKADDR)&addr, sizeof(addr)))
	 {
	 	MessageBox(NULL, _T("Binding Fail"), _T("Error"), MB_OK);
	 	return 0;
	 }
	 else
	 {
	 	MessageBox(NULL, _T("Binding Success"), _T("Success"), MB_OK);
	 }
	 
	 if (listen(s, 5) == -1)
	 {
	 	MessageBox(NULL, _T("Binding Fail"), _T("Error"), MB_OK);
	 	return 0;
	 }
	 else
	 {
	 	MessageBox(NULL, _T("Binding Success"), _T("Success"), MB_OK);
	 }

 	do
 	{
 		SOCKADDR_IN c_addr;
 		char buffer[100];
 
 #ifdef _UNICODE
 		TCHAR wBuffer[100];
 #endif // _UNICODE
 		int msgLen;
 		int size = sizeof(c_addr);
 		SOCKET cs = accept(s, (LPSOCKADDR)&c_addr, &size);
 		// if
 		msgLen = recv(cs, buffer, 99, 0);
 		buffer[msgLen] = NULL;
 
 #ifdef _UNICODE
 		msgLen = MultiByteToWideChar(CP_ACP, 0, buffer, strlen(buffer), NULL, NULL);
 		MultiByteToWideChar(CP_ACP, 0, buffer, strlen(buffer), wBuffer, msgLen);
 		wBuffer[msgLen] = NULL;
 		_stprintf_s(message, _T("클라이언트 메시지 : %s, 서버를 종료하시겠습니까?"), wBuffer);
 #else
 		_stprintf_s(message, _T("클라이언트 메시지 : %s, 서버를 종료하시겠습니까?"), wBuffer);
 #endif
 
 	} while (MessageBox(NULL, message, _T("Server msg"), MB_YESNO) == IDNO);

	closesocket(s);
	WSACleanup();
	return 1;
}
// <<