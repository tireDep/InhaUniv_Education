#pragma once
#include "stdafx.h"
#include "GroundEatingGame.h"

enum moveSpeed { emoveSpeed = 5 };

class Player
{
private:
	POINT playerPos;

public:
	Player();
	Player(int posx, int posy);
	~Player();

	void CheckPlayerPos(int _moveSpeed, bool isLeft);

	void SetPosX(int addPos);
	void SetPosY(int addPos);

	POINT GetPosPoint();
};
