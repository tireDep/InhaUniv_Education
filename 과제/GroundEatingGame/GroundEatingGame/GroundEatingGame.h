#pragma once

#include "resource.h"
#include <vector>

using std::vector;

// enum BaisPolygonSize { ePosLeft = 90, ePosTop = 90, ePosRight = 900, ePosBottom = 900 }; // basic size
enum WindowSize { eWinPosX = 50, eWinPosY = 0, eWinWidth = 1010, eWinHeight = 1000 };	// test size

enum BaisPolygonSize { ePosLeft = 90, ePosTop = 90, ePosRight = 500, ePosBottom = 500 };

enum AddNum { eSpotNum = 7, eNum15 = 15 };
enum PlayerSet { eStartposX = ePosLeft - eSpotNum, eStartPosY = ePosTop - eSpotNum };

enum { eLeft = 0, eUp= 1, eRight = 2, eDown = 3 };

VOID CALLBACK KeyStateProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime);