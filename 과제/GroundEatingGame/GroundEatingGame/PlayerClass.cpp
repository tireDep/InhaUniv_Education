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
		// ���� ���� �� �����ϴ���

		if (result == 0)
		{
			if ((centerPos.x >= x1 && centerPos.x <= x2) && (centerPos.y >= y1 && centerPos.y <= y2)
				|| (centerPos.x >= x2 && centerPos.x <= x1) && (centerPos.y >= y2 && centerPos.y <= y1))
				return true;	// ������ ���۰� �� ���̿� ���� �����ϴ���
		}
			
	}
	return false;
}

void Player::CheckPlayerPos(int _moveSpeed, int turnPos, HideMap hideMap)
{
	CalcCenterPos();
	//bool a = false;
	//if(nowMap.size()!=0)
	//	a = CheckSpotOnTheLine(nowMap[0]);
	//// �׸� �� ���� �� �ö󰡴��� �Ǻ� �׽�Ʈ
	bool checkLine = CheckSpotOnTheLine(hideMap);
	if (!checkLine)
	{
		POINT temp = centerPos;
		if (preCheckLine != checkLine)	// ������ ����
		{
			if (centerPos.x == ePosTop + emoveSpeed )	temp.x = ePosTop;
			else if (centerPos.x == ePosBottom - emoveSpeed)	temp.x = ePosBottom;

			if (centerPos.y == ePosLeft + emoveSpeed)	temp.y = ePosLeft;
			else if (centerPos.y == ePosRight - emoveSpeed)	temp.y = ePosRight;
			// ���ο� �� �°� ����
			playerMap.AddSpot(temp);
		}
		moveLine.AddSpot(temp);
	}
	else
	{
		if (preCheckLine != checkLine)	// ���� ����
		{
			playerMap.AddSpot(centerPos);
			playerMap.AddSpot();
			nowMap.push_back(playerMap);
		}
		moveLine.RemoveAllSpot();
		playerMap.RemoveAllSpot();
	}
	preTurn = playerTurn;	// ���� ���� ����
	preCheckLine = checkLine;	// ���� üũ ����

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

	if (preTurn != playerTurn && !checkLine)	// �ܺ� ����, ���� ��ȯ
		playerMap.AddSpot(centerPos);
}

void Player::DrawPlayer(HDC hdc)
{
	moveLine.DrawPolygon(hdc);
	// todo : �����ؾ���
	HBRUSH hBrush, oldBrush;
	hBrush = CreateSolidBrush(RGB(100, 100, 100));
	oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
	
	for (int i = 0; i < nowMap.size(); i++)
		nowMap[i].DrawPolygon(hdc);
	 	
	SelectObject(hdc, oldBrush);
	DeleteObject(hBrush);
	// todo : �����ؾ���
	Ellipse(hdc, playerPos.x, playerPos.y, playerPos.x + eNum15, playerPos.y + eNum15);
}

void Player::MovePlayerX(int _moveSpeed, HideMap hideMap)
{
	// ���� �ܺ����� �Ǻ� �ʿ�
	bool checkInside = false;
	for (int i = 0; i < nowMap.size(); i++)
	{
		checkInside = nowMap[i].CheckMapInside(playerPos, centerPos);

		if (checkInside == true)
			break;
		else
			continue;
	}
	if (!checkInside)
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
}

void Player::MovePlayerY(int _moveSpeed, HideMap hideMap)
{
	bool checkInside = false;
	for (int i = 0; i < nowMap.size(); i++)
	{
		checkInside = nowMap[i].CheckMapInside(playerPos, centerPos);
	
		if (checkInside == true)
			break;
		else
			continue;
	}
	if (!checkInside)
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
