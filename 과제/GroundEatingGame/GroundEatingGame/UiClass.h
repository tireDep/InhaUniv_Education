#pragma once
#include "stdafx.h"

class UI
{
private:
	int playerScreen;

	WCHAR wPlayerName[256];
	WCHAR wName[516];

	time_t nowTime;
	struct tm *tmTime;
	int lastSec;
	int countDownSec;
	WCHAR wCountDown[256];
	WCHAR wPlayerCnt[256];
	WCHAR wMapArea[256];

	RECT restartBtnRect;
	RECT exitBtnRect;

public:
	UI();
	~UI();
	void Update();
	void CountDown();
	void DrawStartUI(HDC hdc);
	void DrawGameUI(HDC hdc, int playerMapCnt, float mapArea);
	void DrawResultUI(HDC hdc);

	void SetPlayerName(WPARAM wParam);
	
	int GetScreenNum();
	bool PushBtn(LPARAM lParam, Player *player);
};
