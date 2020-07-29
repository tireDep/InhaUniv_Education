#pragma once

#include "resource.h"
#include <vector>

using std::vector;

enum WindowSize { eWinPosX = 50, eWinPosY = 0, eWinWidth = 460, eWinHeight = 500 };
enum BaisPolygonSize { ePosLeft = 90, ePosTop = 90, ePosRight = 350, ePosBottom = 350 };		// test size

enum AddNum { eSpotNum = 7, eNum5 = 5, eNum15 = 15 };
enum PlayerSet { eStartposX = ePosLeft - eSpotNum, eStartPosY = ePosTop - eSpotNum };

enum moveSpeed { emoveSpeed = 10 };

enum { eLeft = 0, eUp= 1, eRight = 2, eDown = 3, eStart = -1 };

VOID CALLBACK KeyStateProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime);