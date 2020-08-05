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

bool Player::CheckCanMoveX(POINT tempPlayerPos, POINT tempCenterPos)
{
	bool checkInside = false;
	for (int i = 0; i < nowMap.size(); i++)
	{
		checkInside = nowMap[i].CheckMapInside(tempCenterPos, tempCenterPos, playerTurn);

		if (checkInside == true)
			break;
		else
			continue;
	}
	if (!checkInside)
	{
		if ((tempCenterPos.x <= eStartposX - eDecimal / 2 && playerTurn == eLeft)
			|| (tempCenterPos.x >= ePosRight + eDecimal / 2 && playerTurn == eRight))
			return false;

		else if ((tempCenterPos.x <= ePosRight - eDecimal / 2 && playerTurn == eLeft)
			|| (tempCenterPos.x >= eStartposX + eDecimal / 2 && playerTurn == eRight))
			return true;
	}
	return false;
}

bool Player::CheckCanMoveY(POINT tempPlayerPos, POINT tempCenterPos)
{
	bool checkInside = false;
	for (int i = 0; i < nowMap.size(); i++)
	{
		checkInside = nowMap[i].CheckMapInside(tempCenterPos, tempCenterPos, playerTurn);

		if (checkInside == true)
			break;
		else
			continue;
	}
	if (!checkInside)
	{
		if ((tempCenterPos.y <= eStartPosY - eDecimal / 2 && playerTurn == eUp)
			|| (tempCenterPos.y >= ePosBottom + eDecimal / 2 && playerTurn == eDown))
			return false;

		else if ((tempCenterPos.y <= ePosBottom - eDecimal / 2 && playerTurn == eUp)
			|| (tempCenterPos.y >= eStartPosY + eDecimal / 2 && playerTurn == eDown))
			return true;	
	}
	return false;
}

void Player::CheckPlayerPos(int movePos, int turnPos, HideMap hideMap)
{
	bool isCanMove;
	POINT tempPlayerPos;
	POINT tempCenterPos;
	tempPlayerPos = playerPos;
	preTurn = playerTurn;	// ���� ���� ����

	// �̵� �������� �Ǻ�
	switch (turnPos)
	{
	case eLeft:
	case eRight:
		playerTurn = turnPos;
		tempPlayerPos.x += movePos;
		CalcCenterPos(tempPlayerPos, tempCenterPos);
		isCanMove = CheckCanMoveX(tempPlayerPos, tempCenterPos);
		break;

	case eUp:
	case eDown:
		playerTurn = turnPos;
		tempPlayerPos.y += movePos;
		CalcCenterPos(tempPlayerPos, tempCenterPos);
		isCanMove = CheckCanMoveY(tempPlayerPos, tempCenterPos);
		break;

	default:
		break;
	}

	// �̵� ������ ��
	if (isCanMove)
	{
		POINT trueCenter;	// ������ǥ
		CalcCenterPos(playerPos, trueCenter);
		centerPos = tempCenterPos;	// �̵���ǥ
		//CalcCenterPos();

		bool checkLine = CheckSpotOnTheLine(hideMap);

		if (!checkLine)	// �����ڸ� ���� �ƴ� ���
		{
			for (int i = 0; i < nowMap.size(); i++)
			{
				checkLine = CheckSpotOnTheLine(nowMap[i]);

				if (checkLine == true)
				//if (checkLine == true && preCheckLine != checkLine)
					break;
			}
		}

		if (!checkLine)// || !CheckSpotOnTheLine(hideMap))
		{
			POINT temp = trueCenter;	// �������� ������ǥ ����
			if (preCheckLine != checkLine)	// ������ ����
			{
				if (trueCenter.x == ePosTop + emoveSpeed)	temp.x = ePosTop;
				else if (trueCenter.x == ePosBottom - emoveSpeed)	temp.x = ePosBottom;

				if (trueCenter.y == ePosLeft + emoveSpeed)	temp.y = ePosLeft;
				else if (trueCenter.y == ePosRight - emoveSpeed)	temp.y = ePosRight;
				// ���ο� �� �°� ����
				playerMap.AddSpot(temp);
			}
			
			if (moveLine.CheckMoveTwice(tempCenterPos))	// ������ �� �Ǻ�
			{
				playerPos = playerMap.GetHideMapPos()[0];
				playerPos.x -= eSpotNum;
				playerPos.y -= eSpotNum;

				preCheckLine != preCheckLine;
				moveLine.RemoveAllSpot();
				playerMap.RemoveAllSpot();
				return;
			}
			else
				moveLine.AddSpot(temp);
		}
		else
		{
			if (preCheckLine != checkLine)// || !CheckSpotOnTheLine(hideMap))	// ���� ����
			{
				playerMap.AddSpot(centerPos);	// ������ �̵���ǥ ����
				playerMap.AddSpot();
				nowMap.push_back(playerMap);
			}
			moveLine.RemoveAllSpot();
			playerMap.RemoveAllSpot();
		}

		if (preTurn != playerTurn && !preCheckLine)	// �ܺ� ����, ���� ��ȯ
		{
			moveLine.AddSpot(centerPos);	// ���̴� �κ� ����
			playerMap.AddSpot(trueCenter);
		}

		preCheckLine = checkLine;	// ���� üũ ����	
		playerPos = tempPlayerPos;
		if (turnPos == eLeft || turnPos == eRight)
			MovePlayerX(movePos);
		if (turnPos == eUp || turnPos == eDown)
			MovePlayerY(movePos);
		// �̵� ��ġ ����
	}
}

void Player::DrawPlayer(HDC hdc)
{
	moveLine.DrawPolygon(hdc);
	// todo : �����ؾ���
	HBRUSH hBrush, oldBrush;
	hBrush = CreateSolidBrush(RGB(255, 65, 255));
	oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
	
	vector<HideMap>::reverse_iterator it;
	for (it = nowMap.rbegin(); it < nowMap.rend(); it++)
		it->DrawPolygon(hdc);
	 	
	SelectObject(hdc, oldBrush);
	DeleteObject(hBrush);
	// todo : �����ؾ���
	Ellipse(hdc, playerPos.x, playerPos.y, playerPos.x + eDecimal, playerPos.y + eDecimal);
}

void Player::MovePlayerX(int movePos)
{
	if (playerPos.x < eStartposX && movePos < 0)
		playerPos.x = playerPos.x + (movePos * -1);
	else if (playerPos.x > ePosRight - eSpotNum && movePos > 0)
		playerPos.x = playerPos.x + (movePos * -1);
}

void Player::MovePlayerY(int movePos)
{
	if (playerPos.y < eStartPosY && movePos < 0)
		playerPos.y = playerPos.y + (movePos * -1);
	else if (playerPos.y > ePosBottom - eSpotNum && movePos > 0)
		playerPos.y = playerPos.y + (movePos * -1);

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
	centerPos.x = (playerPos.x + playerPos.x + eDecimal) / 2;
	centerPos.y = (playerPos.y + playerPos.y + eDecimal) / 2;
}

void Player::CalcCenterPos(POINT pos, POINT &cPos)
{
	cPos.x = (pos.x + pos.x + +eDecimal) / 2;
	cPos.y = (pos.y + pos.y + +eDecimal) / 2;
}