#pragma once

#include "resource.h"

#define _USE_MATH_DEFINES
#include<math.h>

void AddPoint(int posx, int posy, POINT calcP[]);
void DrawStar(HDC hdc, int posx, int posy, int distance);

#include <stdio.h>	// fclose
void OutFromFile(TCHAR filename[], HWND hWnd);