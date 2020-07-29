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

public:
	Player();
	Player(int posx, int posy);
	~Player();

	void CheckPlayerPos(int _moveSpeed, int turnPos, HideMap hideMap);
	void MovePlayerX(int _moveSpeed, HideMap hideMap);
	void MovePlayerY(int _moveSpeed, HideMap hideMap);

	void DrawPlayer(HDC hdc);

	void SetPosX(int addPos);
	void SetPosY(int addPos);

	void CalcCenterPos();
	bool CheckSpotOnTheLine(HideMap hideMap);
};
