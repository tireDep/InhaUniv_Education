#include "stdafx.h"
#include "PlayerClass.h"

Player::Player()
{
	playerPos.x = 0;
	playerPos.y = 0;
}

Player::Player(int posx, int posy)
{
	playerPos.x = posx;
	playerPos.y = posy;
}

Player::~Player()
{

}

void Player::CheckPlayerPos(int _moveSpeed, bool isLeft)
{
	if (isLeft && playerPos.x >= eStartposX && playerPos.x <= ePosRight - eSpotNum)
	{
		if (playerPos.x == eStartposX && _moveSpeed < 0)
			playerPos.x = playerPos.x;
		else if(playerPos.x == ePosRight - eSpotNum && _moveSpeed > 0)
			playerPos.x = playerPos.x;
		else
			SetPosX(_moveSpeed);
	}
		

	if (!isLeft && playerPos.y >= eStartPosY && playerPos.y <= ePosBottom - eSpotNum)
	{
		if (playerPos.y == eStartPosY && _moveSpeed < 0)
			playerPos.y = playerPos.y;
		else if (playerPos.y == ePosRight - eSpotNum && _moveSpeed > 0)
			playerPos.y = playerPos.y;
		else
			SetPosY(_moveSpeed);
	}	
}

void Player::SetPosX(int addPos)
{
	playerPos.x += addPos;
}

void Player::SetPosY(int addPos)
{
	playerPos.y += addPos;
}

POINT Player::GetPosPoint()
{
	return playerPos;
}
