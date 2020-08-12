#include "stdafx.h"
#include "GroundEatingGame.h"
#include "PlayerClass.h"
#include "UiClass.h"

#define COUNTDOWNSEC 5000

UI* UI::GetInstance()
{
	static UI playerUI; // 상속을 받았을 경우 접근할 수 있기 때문에 지역변수로 선언
	return &playerUI;
}

UI::UI()
{
	playerScreen = eStartScreen;

	time(&nowTime);
	tmTime = localtime(&nowTime);

	lastSec = tmTime->tm_sec;
	countDownSec = COUNTDOWNSEC;

	for (int i = 0; i < 256; i++)
	{
		wCountDown[i] = NULL;
		wPlayerName[i] = NULL;
		wPlayerCnt[i] = NULL;
		wMapArea[i] = NULL;
	}
	for (int i = 0; i < 516; i++)
		wName[i] = NULL;

	restartBtnRect = { 0,0,0,0 };
	exitBtnRect = { 0,0,0,0 };
}

UI::~UI()
{
	
}

void UI::Update()
{
	CountDown();

	if (countDownSec == -1)
		playerScreen = eResultScreen;
}

void UI::CountDown()
{
	time(&nowTime);
	tmTime = localtime(&nowTime);
	if (lastSec != tmTime->tm_sec)
	{
		lastSec = tmTime->tm_sec;
		countDownSec--;
	}

	swprintf(wCountDown, _TEXT("%s %d"), _T("LastSec : "), countDownSec);
}

void UI::DrawStartUI(HDC hdc)
{
	RECT rectView = { 0,75,460,450 };
	DrawText(hdc, _T("GroundEating Game"), _tcslen(_T("GroundEating Game")), &rectView, DT_CENTER | DT_VCENTER);

	rectView.top += 150;
	DrawText(hdc, _T("Input Name"), _tcslen(_T("Input Name")), &rectView, DT_CENTER | DT_VCENTER);

	rectView.top += 25;
	DrawText(hdc, wPlayerName, _tcslen(wPlayerName), &rectView, DT_CENTER | DT_VCENTER);
}

void UI::DrawGameUI(HDC hdc, int playerMapCnt, float mapArea)
{
	RECT uiRect = { 20,0,430,35 };

	DrawText(hdc, wName, _tcslen(wName) - 1, &uiRect, DT_BOTTOM | DT_LEFT | DT_SINGLELINE);

	swprintf(wPlayerCnt, _TEXT("%s %d"), _T("DrawCount : "), playerMapCnt);
	DrawText(hdc, wPlayerCnt, _tcslen(wPlayerCnt), &uiRect, DT_BOTTOM | DT_RIGHT | DT_SINGLELINE);

	uiRect.bottom += 30;
	DrawText(hdc, wCountDown, _tcslen(wCountDown), &uiRect, DT_BOTTOM | DT_LEFT | DT_SINGLELINE);

	swprintf(wMapArea, _TEXT("%s %.1lf%s"), _T("Area : "), mapArea, _T("%"));
	DrawText(hdc, wMapArea, _tcslen(wMapArea), &uiRect, DT_BOTTOM | DT_RIGHT | DT_SINGLELINE);
	// ※ : 넓이 중복있어서 일단 보류
}

void UI::DrawResultUI(HDC hdc)
{
	RECT uiRect = { 0,50,430,450 };

	// DrawText(hdc, _T("Result"), _tcslen(_T("Result")), &uiRect, DT_CENTER | DT_VCENTER);
	// 
	// uiRect.top += 50;
	// DrawText(hdc, _T("YourScore"), _tcslen(_T("YourScore")), &uiRect, DT_CENTER | DT_VCENTER);
	// ※ : 수정 예정

	uiRect.top += 50;
	DrawText(hdc, _T("GameOver"), _tcslen(_T("GameOver")), &uiRect, DT_CENTER | DT_VCENTER);

	RECT _btnRect = { uiRect.left + 50, uiRect.top + 175, 175, uiRect.top + 225 };
	Rectangle(hdc, _btnRect.left, _btnRect.top, _btnRect.right, _btnRect.bottom);
	DrawText(hdc, _T("MAIN"), _tcslen(_T("MAIN")), &_btnRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	restartBtnRect = _btnRect;

	_btnRect = { _btnRect.left + 210, _btnRect.top, 390, _btnRect.bottom };
	Rectangle(hdc, _btnRect.left, _btnRect.top, _btnRect.right, _btnRect.bottom);
	DrawText(hdc, _T("EXIT"), _tcslen(_T("EXIT")), &_btnRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	exitBtnRect = _btnRect;
}

bool UI::PushBtn(LPARAM lParam, Player *player)
{
	int xPos = LOWORD(lParam);
	int yPos = HIWORD(lParam);

	if (yPos >= restartBtnRect.top && yPos <= restartBtnRect.bottom && xPos >= restartBtnRect.left&&xPos <= restartBtnRect.right)
	{
		Reset();	// resetUI
		player->Reset();	// resetPlayer
	}
	if (yPos >= exitBtnRect.top && yPos <= exitBtnRect.bottom && xPos >= exitBtnRect.left&&xPos <= exitBtnRect.right)
		return false;

	return true;
}

void UI::SetPlayerName(WPARAM wParam)
{
	int nameCnt = 0;
	for (int i = 0; i < 256; i++)
	{
		if (wPlayerName[i] != NULL)
			nameCnt++;
		else
			break;
	}

	if (wParam == VK_RETURN)
		playerScreen = eGameScreen;

	if (wParam == VK_BACK && nameCnt > 0)
		nameCnt--;
	else
		wPlayerName[nameCnt++] = wParam;

	wPlayerName[nameCnt] = NULL;

	wcscpy(wName, _T("PlayerName : "));
	wcscat(wName, wPlayerName);
}

int UI::GetScreenNum()
{
	return playerScreen;
}

void UI::Reset()
{
	playerScreen = eStartScreen;
	lastSec = 0;
	countDownSec = COUNTDOWNSEC;

	for (int i = 0; i < 256; i++)
	{
		wCountDown[i] = NULL;
		wPlayerName[i] = NULL;
		wPlayerCnt[i] = NULL;
		wMapArea[i] = NULL;
	}

	for (int i = 0; i < 516; i++)
		wName[i] = NULL;
}
