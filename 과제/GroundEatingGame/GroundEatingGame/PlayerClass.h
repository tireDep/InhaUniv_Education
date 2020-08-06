#pragma once
#include "stdafx.h"
#include "GroundEatingGame.h"
#include "MapClass.h"


class Player
{
private:
	POINT playerPos;
	POINT centerPos;

	PlayerMap moveLine;
	HideMap playerMap;
	vector<HideMap> nowMap;

	int preTurn;
	int playerTurn;
	bool preCheckLine;

	float mapArea;

public:
	Player();
	Player(int posx, int posy);
	~Player();

	void CheckPlayerPos(int movePos, int turnPos, HideMap hideMap);
	void MovePlayerX(int movePos);
	void MovePlayerY(int movePos);

	void DrawPlayer(HDC hdc);

	void SetPosX(int addPos);
	void SetPosY(int addPos);

	void CalcCenterPos();
	void CalcCenterPos(POINT pos, POINT &cPos);
	bool CheckSpotOnTheLine(HideMap hideMap);

	bool CheckCanMoveX(POINT tempPlayerPos, POINT tempCenterPos);
	bool CheckCanMoveY(POINT tempPlayerPos, POINT tempCenterPos);

	void CalcMapArea();
	void Reset();

	int GetPlayerMapCnt();
	float GetMapArea();
};
