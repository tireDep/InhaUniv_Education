#pragma once
#include "stdafx.h"
#include "Omok_Server.h"
#include <vector>

using std::vector;

class Omok
{
private:
	int map[defArrSize][defArrSize];
	int colorMap[defArrSize][defArrSize];

	vector<POINT> playerMark;
	vector<int> playerColor;

	Omok();
	~Omok();

public:
	static Omok *GetInstance();
	bool CheckOmok_class();

	void SetPlayerOmok(int saveVal[], int saveNum);
	void ErasePlayerOmok(int saveVal[]);

	vector<POINT> GetPlayerMark();
	vector<int> GetPlayerColor();
	void AddPlayerMark(int saveVal[]);

	void DrawOmok(HDC hdc);
	void DrawMap(HDC hdc);
	void DrawPlayer(HDC hdc);
};
