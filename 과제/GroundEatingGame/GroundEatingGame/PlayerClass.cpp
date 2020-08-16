#include "stdafx.h"
#include "PlayerClass.h"

Player::Player()
{
	playerPos.x = 0;
	playerPos.y = 0;
	preTurn = eStart;
	playerTurn = eStart;
	mapArea = 0;
}

Player::Player(int posx, int posy)
{
	playerPos.x = posx;
	playerPos.y = posy;
	preTurn = eStart;
	playerTurn = eStart;
	preCheckLine = true;
	mapArea = 0;
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
		
		if (isColoredArray[tempCenterPos.x][tempCenterPos.y])
			isCanMove = false;
		else
		{
			if (tempCenterPos.x < ePosLeft || tempCenterPos.x > ePosRight)
				isCanMove = false;
			else
				isCanMove = true;
		}

		break;

	case eUp:
	case eDown:
		playerTurn = turnPos;
		tempPlayerPos.y += movePos;
		CalcCenterPos(tempPlayerPos, tempCenterPos);
		if (isColoredArray[tempCenterPos.x][tempCenterPos.y])
			isCanMove = false;
		else
		{
			if (tempCenterPos.y < ePosTop || tempCenterPos.y > ePosBottom)
				isCanMove = false;
			else
				isCanMove = true;
		}

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

		bool checkLine = CheckSpotOnTheLine(hideMap);

		if (!checkLine)	// �����ڸ� ���� �ƴ� ���
		{
			for (int i = 0; i < nowMap.size(); i++)
			{
				checkLine = CheckSpotOnTheLine(nowMap[i]);

				if (checkLine == true)
					break;
			}
		}

		if (!checkLine)
		{
			POINT temp = trueCenter;	// �������� ������ǥ ����
			if (preCheckLine != checkLine)	// ������ ����
				preMapSize = nowMap.size();
			
			if (moveLine.CheckMoveTwice(tempCenterPos))	// ������ �� �Ǻ�
			{
				playerPos = moveLine.GetPlayerMapPos()[0];
				playerPos.x -= eSpotNum;
				playerPos.y -= eSpotNum;

				preCheckLine = true;
				moveLine.RemoveAllSpot();
				playerMap.RemoveAllSpot();
				return;
			}
			else
				moveLine.AddSpot(temp);
		}
		else
		{
			if (preTurn != playerTurn && !preCheckLine)	// �ܺ� ����, ���� ��ȯ
			{
				// moveLine.AddSpot(centerPos);	// ���̴� �κ� ����
				moveLine.AddSpot(trueCenter);
			}

			if (preCheckLine != checkLine)
			{
				moveLine.AddSpot(centerPos);	// ���̴� �κ� ����
				playerMap.RemoveAllSpot();

				vector<POINT> check = moveLine.GetPlayerMapPos();
				if (check[0].x == check[check.size() - 1].x && check[0].y == check[check.size() - 1].y)
				{

				}
				else
				{
					playerMap.SetMap(moveLine.GetMap());
					nowMap.push_back(playerMap);
				}
			}
			playerMap.RemoveAllSpot();
			moveLine.RemoveAllSpot();
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
	CalcMapArea();
	printf("%f\n", mapArea);

	moveLine.DrawPolygon(hdc,0);
	
	HPEN hPen, oldPen;
	hPen = CreatePen(BS_SOLID, 1, RGB(100, 100, 100));
	oldPen = (HPEN)SelectObject(hdc, hPen);

	HBRUSH hBrush, oldBrush;
	hBrush = CreateSolidBrush(RGB(255, 65, 255));
	oldBrush = (HBRUSH)SelectObject(hdc, hBrush);

	vector<HideMap>::reverse_iterator it;
	for (it = nowMap.rbegin(); it < nowMap.rend(); it++)
	{
		it->DrawPolygon(hdc, 0);
	}
	for (int i = 0; i < nowMap.size(); i++)
	{
		vector<POINT> temp = nowMap[i].GetHideMapPos();
		int x, y;
		int straightX = 0;
		int straightY = 0;

		for (int i = 0; i < temp.size() - 1; i++)
		{
			if (temp[i].x == temp[i + 1].x) straightX++;
			if (temp[i].y == temp[i + 1].y) straightY++;
		}

		if (temp.size() - 1 == straightX)
		{
			x = temp[0].x  < 260 ? -1 : 1;
			if (temp[0].y > temp[1].y)
				y = -1;
			else
				y = 1;
		}	// ���� �Ǻ�
		else if (temp.size() - 1 == straightY)
		{
			y = temp[0].y  < 260 ? -1 : 1;
			if (temp[0].x > temp[1].x)
				x = -1;
			else
				x = 1;
		}	// ���� �Ǻ�
		else
		{
			if (temp[0].x < temp[1].x && temp[0].y == temp[1].y && temp[1].y>temp[temp.size() - 1].y)
			{
				x = 1;
				y = -1;
			} // �¿��
			else if (temp[0].y < temp[1].y && temp[0].x == temp[1].x && temp[1].x > temp[temp.size() - 1].x)
			{
				x = -1;
				y = 1;
			} // �Ͽ���
			  // �޻��

			else if (temp[0].x > temp[1].x && temp[0].y == temp[1].y && temp[1].y > temp[temp.size() - 1].y)
			{
				x = -1;
				y = -1;
			}	// ���»�
			else if (temp[0].y < temp[1].y && temp[0].x == temp[1].x && temp[1].x < temp[temp.size() - 1].x)
			{
				x = 1;
				y = 1;
			}	// ���¿�
				// ����

			else if (temp[0].x < temp[1].x && temp[0].y == temp[1].y && temp[1].y < temp[temp.size() - 1].y)
			{
				x = 1;
				y = 1;
			}	// �¿���
			else if (temp[0].y > temp[1].y && temp[0].x == temp[1].x && temp[1].x > temp[temp.size() - 1].x)
			{
				x = -1;
				y = -1;
			}	// �����
				// ���ϴ�

			else if (temp[0].y > temp[1].y && temp[0].x == temp[1].x && temp[1].x < temp[temp.size() - 1].x)
			{
				x = 1;
				y = -1;
			}	// ���¿�
			else if (temp[0].x > temp[1].x && temp[0].y == temp[1].y && temp[1].y < temp[temp.size() - 1].y)
			{
				x = -1;
				y = 1;
			}	// ������
				// ���ϴ�
			else
			{
				x = temp[0].x < 260 ? 1 : -1;
				y = temp[0].y < 260 ? -1 : 1;
			}
		}

		ExtFloodFill(hdc, temp[0].x + x, temp[0].y + y, 0x00ffffff, FLOODFILLSURFACE);
	}

	SelectObject(hdc, oldPen);
	DeleteObject(hPen);

	SelectObject(hdc, oldBrush);
	DeleteObject(hBrush);

	if (preMapSize != nowMap.size())
	{
		preMapSize = nowMap.size();
		for (int i = 0; i < 351; i++)
		{
			for (int j = 0; j < 351; j++)
			{
				if (isColoredArray[i][j] == true)
					continue;

				COLORREF color = GetPixel(hdc, i, j);
				int a = GetRValue(color);
				int b = GetGValue(color);
				int c = GetBValue(color);

				if (RGB(a, b, c) != RGB(255, 65, 255))
					isColoredArray[i][j] = false;
				else
					isColoredArray[i][j] = true;
			}
		}
	}

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

void Player::CalcMapArea()
{
	mapArea = 0;
	float divide = 1;
	for (int i = 0; i < defColorSize; i++)
	{
		if (i < 90)
			continue;

		for (int j = 0; j < defColorSize; j++)
		{
			if (j < 90)
				continue; 

			divide++;
			if(isColoredArray[i][j])
				mapArea++;
		}
	}
	mapArea = (mapArea / divide) * 100;
}

void Player::Reset()
{
	playerPos.x = eStartposX;
	playerPos.y = eStartPosY;
	preTurn = eStart;
	playerTurn = eStart;
	preCheckLine = true;
	mapArea = 0;

	moveLine.RemoveAllSpot();

	vector<HideMap>::iterator it;
	for (int i = 0; i < nowMap.size(); i++)
	{
		nowMap[i].RemoveAllSpot();

		for (it = nowMap.begin(); it<nowMap.end(); )
		{
			if ((&it))
				it = nowMap.erase(it);
			else it++;
		}
	}

	for (int i = 0; i < defColorSize + 2; i++)
	{
		for (int j = 0; j < defColorSize + 2; j++)
			isColoredArray[i][j] = false;
	}

}

int Player::GetPlayerMapCnt()
{
	return nowMap.size();
}

float Player::GetMapArea()
{
	return mapArea;
}

POINT Player::GetPlayerPos()
{
	return playerPos;
}

bool Player::GetCheckLine()
{
	return preCheckLine;
}

vector<POINT> Player::GetPlayerMapPos()
{
	return moveLine.GetPlayerMapPos();
}