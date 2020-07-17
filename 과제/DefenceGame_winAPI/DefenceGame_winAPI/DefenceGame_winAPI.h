#pragma once

#include "resource.h"

#include<time.h>
#include<vector>
using std::vector;
using std::iterator;

enum ViewSize { eViewX = 350, eViewY = 200, eViewW = 516, eViewH = 750 };
enum GameScreen { eStart = 0, eGame = 50, eResult = 100, eExit = 9999 };

/*
static hp;
healthBar
-  0, 650, 500 - hp, 700	// 하단
-  0, 0, 500 - hp, 30	// 상단

static downSpeed;
for : i += 50
obstacle
-  i, 0 + downSpeed, 50 + i, 30 + downSpeed

*/