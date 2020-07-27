#include "stdafx.h"
#include "PlayerClass.h"

Player::Player()
{
	playerPos.x = 0;
	playerPos.y = 0;
	preTurn = 0;
	playerTurn = 0;
}

Player::Player(int posx, int posy)
{
	playerPos.x = posx;
	playerPos.y = posy;
	preTurn = 0;
	playerTurn = 0;
}

Player::~Player()
{

}

bool Player::CheckSpotOnTheLine(HideMap hideMap)
{
	vector<POINT>hideMapPos = hideMap.GetHideMapPos();
	int x1, y1, x2, y2;
	int result;
	for (int i = 0; i < hideMapPos.size(); i++)
	{
		x1 = hideMapPos[i].x;
		y1 = hideMapPos[i].y;
		if (i == hideMapPos.size() - 1)
		{
			x2 = hideMapPos[0].x;
			y2 = hideMapPos[0].y;
		}
		else
		{
			x2 = hideMapPos[i + 1].x;
			y2 = hideMapPos[i + 1].y;
		}
		
		result = (y1 - y2) * centerPos.x + (x2 - x1) * centerPos.y + x1 * y2 - x2 * y1;
		// 직선 위에 점 존재하는지

		if (result == 0)
			return true;
	}
	return false;
}

void Player::CheckPlayerPos(int _moveSpeed, int turnPos, HideMap hideMap)
{
	CalcCenterPos();
	if (!CheckSpotOnTheLine(hideMap))
		moveLine.AddSpot(centerPos);
	else
		moveLine.RemoveAllSpot();

	preTurn = playerTurn;	// 기존 방향 저장

	switch (turnPos)
	{
	case eLeft:
		playerTurn = eLeft;
		MovePlayerX(_moveSpeed);
		// if (preTurn != playerTurn)
		// 	playerMap.AddSpot(centerPos);
		// else
		// { }
		break;

	case eUp:
		playerTurn = eUp;
		MovePlayerY(_moveSpeed);
		break;

	case eRight:
		playerTurn = eRight;
		MovePlayerX(_moveSpeed);
		break;

	case eDown:
		playerTurn = eDown;
		MovePlayerY(_moveSpeed);
		break;

	default:
		break;
	}	
}

void Player::DrawPlayer(HDC hdc)
{
	moveLine.DrawPolygon(hdc);
	Ellipse(hdc, playerPos.x, playerPos.y, playerPos.x + eNum15, playerPos.y + eNum15);
}

void Player::MovePlayerX(int _moveSpeed)
{
	if (playerPos.x >= eStartposX && playerPos.x <= ePosRight - eSpotNum)
	{
		if (playerPos.x == eStartposX && _moveSpeed < 0)
			playerPos.x = playerPos.x;
		else if (playerPos.x == ePosRight - eSpotNum && _moveSpeed > 0)
			playerPos.x = playerPos.x;
		else
			SetPosX(_moveSpeed);
	}
}

void Player::MovePlayerY(int _moveSpeed)
{
	if (playerPos.y >= eStartPosY && playerPos.y <= ePosBottom - eSpotNum)
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

void Player::CalcCenterPos()
{
	centerPos.x = (playerPos.x + playerPos.x + eNum15) / 2;
	centerPos.y = (playerPos.y + playerPos.y + eNum15) / 2;
}
