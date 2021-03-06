// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#define _USE_MATH_DEFINES	// use M_PI
#include<math.h>


void DrawGrid(HDC hdc, int posX1, int posY1, int posX2, int posY2, int tab);
// void DrawCircle(HDC hdc, int centerX, int centerY, int radius);

void DrawCircle(HDC hdc, int centerX, int centerY, int radius);
double DegreeToRadian(int arcDegree);
void DrawSunflower(HDC hdc, int centerX, int centerY, int centerR, int num);

void DrawRectangle(HDC hdc, int left, int top, int right, int bottom);

void DrawStar(HDC hdc, int midX, int midY, int distance);
void AddPoint(int degree, int midX, int midY, POINT point[]);

// TODO: reference additional headers your program requires here
