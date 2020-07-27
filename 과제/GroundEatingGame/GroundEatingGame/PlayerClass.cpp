#include "stdafx.h"
#include "PlayerClass.h"

Player::Player()
{
	playerPos.x = 0;
	playerPos.y = 0;
	preTurn = eStart;
	playerTurn = eStart;
}

Player::Player(int posx, int posy)
{
	playerPos.x = posx;
	playerPos.y = posy;
	preTurn = eStart;
	playerTurn = eStart;
	preCheckLine = true;
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
		if (i == hideMapPos.size() - 1)
		{

			x1 = hideMapPos[0].x;
			y1 = hideMapPos[0].y;
			x2 = hideMapPos[i].x;
			y2 = hideMapPos[i].y;
		}
		else
		{
			x1 = hideMapPos[i].x;
			y1 = hideMapPos[i].y;
			x2 = hideMapPos[i + 1].x;
			y2 = hideMapPos[i + 1].y;
		}
		
		result = (y1 - y2) * centerPos.x + (x2 - x1) * centerPos.y + x1 * y2 - x2 * y1;
		// 직선 위에 점 존재하는지

		if (result == 0)
		{
			if ((centerPos.x >= x1 && centerPos.x <= x2) && (centerPos.y >= y1 && centerPos.y <= y2)
				|| (centerPos.x >= x2 && centerPos.x <= x1) && (centerPos.y >= y2 && centerPos.y <= y1))
				return true;	// 직선의 시작과 끝 사이에 점이 존재하는지
		}
			
	}
	return false;
}

void Player::CheckPlayerPos(int _moveSpeed, int turnPos, HideMap hideMap)
{
	CalcCenterPos();
	bool checkLine = CheckSpotOnTheLine(hideMap);
	if (!checkLine)
	{
		if (preCheckLine != checkLine)	// 시작점 저장
		{
			POINT temp = centerPos;
			if (centerPos.x == 95)	temp.x = 90;
			if (centerPos.y == 95)	temp.y = 90;
			// 라인에 딱 맞게 보정
			playerMap.AddSpot(temp);
		}
		moveLine.AddSpot(centerPos);
	}
	else
	{
		if (preCheckLine != checkLine)	// 끝점 저장
		{
			playerMap.AddSpot(centerPos);
			playerMap.AddSpot();
		}
		moveLine.RemoveAllSpot();
	}
	preTurn = playerTurn;	// 기존 방향 저장
	preCheckLine = checkLine;	// 라인 체크 저장

	switch (turnPos)
	{
	case eLeft:
		playerTurn = eLeft;
		MovePlayerX(_moveSpeed, hideMap);
		break;

	case eUp:
		playerTurn = eUp;
		MovePlayerY(_moveSpeed, hideMap);
		break;

	case eRight:
		playerTurn = eRight;
		MovePlayerX(_moveSpeed, hideMap);
		break;

	case eDown:
		playerTurn = eDown;
		MovePlayerY(_moveSpeed, hideMap);
		break;

	default:
		break;
	}

	if (preTurn != playerTurn && !checkLine)	// 외부 존재, 방향 전환
		playerMap.AddSpot(centerPos);
}

void Player::DrawPlayer(HDC hdc)
{
	moveLine.DrawPolygon(hdc);
	// todo : 수정해야함
	HBRUSH hBrush, oldBrush;
	hBrush = CreateSolidBrush(RGB(100, 100, 100));
	oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
	
	if(preCheckLine==true)
	 	playerMap.DrawPolygon(hdc);

	SelectObject(hdc, oldBrush);
	DeleteObject(hBrush);
	// todo : 수정해야함
	Ellipse(hdc, playerPos.x, playerPos.y, playerPos.x + eNum15, playerPos.y + eNum15);
}

void Player::MovePlayerX(int _moveSpeed, HideMap hideMap)
{
	if (playerPos.x >= eStartposX && playerPos.x <= ePosRight)// && CheckSpotOnTheLine(hideMap))
	{
		if (playerPos.x == eStartposX && _moveSpeed < 0)
			playerPos.x = playerPos.x;
		else if (playerPos.x == ePosRight - eSpotNum && _moveSpeed > 0)
			playerPos.x = playerPos.x;
		else
			SetPosX(_moveSpeed);
	}
}

void Player::MovePlayerY(int _moveSpeed, HideMap hideMap)
{
	if (playerPos.y >= eStartPosY && playerPos.y <= ePosBottom)// && CheckSpotOnTheLine(hideMap))
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
