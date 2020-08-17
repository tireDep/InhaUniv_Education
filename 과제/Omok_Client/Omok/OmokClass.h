#pragma once
#include "stdafx.h"
#include "Omok_Client.h"
#include <vector>

using std::vector;


class Omok
{
private:
	int map[defArrSize][defArrSize];

	vector<POINT> playerMark;
	vector<int> playerColor;

	Omok();
	~Omok();

public:
	static Omok* GetInstance();

	void SetPlayerOmok(int saveVal[], int saveNum);
	void AddPlayerMark(int saveVal[]);

	vector<POINT> GetPlayerMark();
	vector<int> GetPlayerColor();

	void DrawOmok(HDC hdc);
	void DrawMap(HDC hdc);
	void DrawPlayer(HDC hdc);
};

Omok::Omok()
{

}

Omok::~Omok()
{

}

Omok* Omok::GetInstance()
{
	static Omok omok;
	return &omok;
}

void Omok::SetPlayerOmok(int saveVal[], int saveNum)
{
	map[saveVal[0]][saveVal[1]] = saveNum;
	playerColor.push_back(saveNum);
}

void Omok::AddPlayerMark(int saveVal[])
{
	playerMark.push_back({ saveVal[2],saveVal[3] });
}

vector<POINT> Omok::GetPlayerMark()
{
	return playerMark;
}

vector<int> Omok::GetPlayerColor()
{
	return playerColor;
}

void Omok::DrawOmok(HDC hdc)
{
	DrawMap(hdc);
	DrawPlayer(hdc);
}

void Omok::DrawMap(HDC hdc)
{
	// ¹ÙµÏÆÇ
	int j = 0;
	HBRUSH hBrush, oldBrush;
	hBrush = CreateSolidBrush(RGB(230, 186, 148));
	oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
	Rectangle(hdc, 0, 0, 765, 741);
	Rectangle(hdc, 47, 35, 714, 705);

	for (int i = 2; i < 19; i++)
	{
		MoveToEx(hdc, 47, 37 * i, NULL);
		LineTo(hdc, 714, 37 * i);
		// °¡·ÎÁÙ

		MoveToEx(hdc, (42 * i) - (5 * j), 36, NULL);
		LineTo(hdc, (42 * i) - (5 * j), 705);
		j++;
		// ¼¼·ÎÁÙ
	}

	SelectObject(hdc, oldBrush);
	DeleteObject(hBrush);

	// ¹ÙµÏÆÇ

	// ¹ÙµÏÆÇ Á¡

	hBrush = CreateSolidBrush(RGB(0, 0, 0));
	oldBrush = (HBRUSH)SelectObject(hdc, hBrush);

	Ellipse(hdc, 42 + 37 * 3, 32 + 37 * 3, 52 + 37 * 3, 42 + 37 * 3);
	Ellipse(hdc, 42 + 37 * 9, 32 + 37 * 3, 52 + 37 * 9, 42 + 37 * 3);
	Ellipse(hdc, 42 + 37 * 15, 32 + 37 * 3, 52 + 37 * 15, 42 + 37 * 3);

	Ellipse(hdc, 42 + 37 * 3, 32 + 37 * 9, 52 + 37 * 3, 42 + 37 * 9);
	Ellipse(hdc, 42 + 37 * 9, 32 + 37 * 9, 52 + 37 * 9, 42 + 37 * 9);
	Ellipse(hdc, 42 + 37 * 15, 32 + 37 * 9, 52 + 37 * 15, 42 + 37 * 9);

	Ellipse(hdc, 42 + 37 * 3, 32 + 37 * 15, 52 + 37 * 3, 42 + 37 * 15);
	Ellipse(hdc, 42 + 37 * 9, 32 + 37 * 15, 52 + 37 * 9, 42 + 37 * 15);
	Ellipse(hdc, 42 + 37 * 15, 32 + 37 * 15, 52 + 37 * 15, 42 + 37 * 15);

	SelectObject(hdc, oldBrush);
	DeleteObject(hBrush);

	// ¹ÙµÏÆÇ Á¡
}

void Omok::DrawPlayer(HDC hdc)
{
	HBRUSH blackBrush, oldBrush1;
	HBRUSH whiteBrush, oldBrush2;

	for (int i = 0; i < playerMark.size(); i++)
	{
		if (playerColor[i] == 1)
		{
			blackBrush = CreateSolidBrush(RGB(0, 0, 0));
			oldBrush1 = (HBRUSH)SelectObject(hdc, blackBrush);

			Ellipse(hdc, playerMark[i].x - eMarkDiameter, playerMark[i].y - eMarkDiameter, playerMark[i].x + eMarkDiameter, playerMark[i].y + eMarkDiameter);

			SelectObject(hdc, oldBrush1);
			DeleteObject(blackBrush);
		}
		else
		{
			whiteBrush = CreateSolidBrush(RGB(255, 255, 255));
			oldBrush2 = (HBRUSH)SelectObject(hdc, whiteBrush);

			Ellipse(hdc, playerMark[i].x - eMarkDiameter, playerMark[i].y - eMarkDiameter, playerMark[i].x + eMarkDiameter, playerMark[i].y + eMarkDiameter);

			SelectObject(hdc, oldBrush2);
			DeleteObject(whiteBrush);
		}
	}
}
