#pragma once
#include "stdafx.h"
#include "GroundEatingGame.h"
#include "MapClass.h"

enum moveSpeed { emoveSpeed = 5 };

class Player
{
private:
	POINT playerPos;
	POINT centerPos;

	PlayerMap moveLine;
	//PlayerMap playerMap;

	int preTurn;
	int playerTurn;

public:
	Player();
	Player(int posx, int posy);
	~Player();

	void CheckPlayerPos(int _moveSpeed, int turnPos, HideMap hideMap);
	void MovePlayerX(int _moveSpeed);
	void MovePlayerY(int _moveSpeed);

	void DrawPlayer(HDC hdc);

	void SetPosX(int addPos);
	void SetPosY(int addPos);

	void CalcCenterPos();
	bool CheckSpotOnTheLine(HideMap hideMap);
};
