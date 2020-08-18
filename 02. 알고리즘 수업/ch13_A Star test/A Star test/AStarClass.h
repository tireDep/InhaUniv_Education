#pragma once
#include "BasicHeader.h"

using namespace std;

enum STATUS { eFree = 0, eOpen = 1, eClose = -1,  eSelect = 9999 };
enum VALUE	{ eStraight = 10, eCross = 14, eBlock = 9999 };

class AStar
{
private:
	int gValue;
	int hValue;
	int fValue;

	bool isBlock;

	int nowStatus;

	bool isReverse;

public:
	AStar();
	~AStar();

	void DoAStar(AStar **astar, Point start, Point dest, vector<Point> &path);
	Point CalcAStar(AStar **astar, Point start, Point dest);
	int CheckDirection(int x, int y);
	int CalcHDirection(Point dest, int x, int y);

	void SetNowStatus(int status);
	void SetGValue(int value);
	void SetHValue(int value);
	void SetFValue();

	void SetIsBlock(bool block);
	void SetIsReverse(bool reverse);
	
	int GetNowStatus();
	int GetGValue();
	int GetHValue();
	int GetFValue();

	bool GetIsBlock();
	bool GetIsReverse();
};

AStar::AStar()
{
	gValue = 0;
	hValue = 0;
	fValue = 0;

	isBlock = false;
	nowStatus = eFree;

	isReverse = false;
}

AStar::~AStar()
{

}

void AStar::DoAStar(AStar ** astar, Point start, Point dest, vector<Point> &path)
{
	path.push_back(start);
	Point nextPath = CalcAStar(astar, start, dest);
	while (1)
	{
		// ���� ���� �Ǻ�

		if (nextPath.x == eBlock && nextPath.y == eBlock)
		{
			cout << "����x";
			break;
		}
		else if (astar[dest.x][dest.y].GetIsBlock() == true)
		{
			cout << "����x";
			break;
		}
		// ���� ���� �Ǻ�

		if (dest.x == nextPath.x && dest.y == nextPath.y)
		{
			path.push_back(nextPath);
			break;
		}
		else
		{
			path.push_back(nextPath);
			nextPath = CalcAStar(astar, nextPath, dest);
		}
	}
}

Point AStar::CalcAStar(AStar **astar, Point start, Point dest)
{
	// ����ġ �ΰ�
	astar[start.x][start.y].SetNowStatus(eSelect);

	for (int i = -1; i < 2; i++)
	{
		if (start.y + i < 0 || start.y + i >= defSize) continue;	// ���� �� ����

		for (int j = -1; j < 2; j++)
		{
			if (i == 0 && j == 0) continue;	// �ڱ��ڽ� ����
			else if (start.x + j < 0 || start.x + j >= defSize) continue;	// ���� �� ����
			else
			{
				// ���¹��⿡ ��ֹ��� ������ ���� or ����ġ ���� �ֱ�?
				if (astar[start.x + j][start.y + i].isBlock == true)
				{
					astar[start.x][start.y].SetNowStatus(eBlock);
					astar[start.x + j][start.y + i].SetGValue(eBlock);
					astar[start.x + j][start.y + i].SetHValue(eBlock);
					astar[start.x + j][start.y + i].SetFValue();
				}
				else if(astar[start.x + j][start.y + i].GetNowStatus() != eClose && astar[start.x + j][start.y + i].GetNowStatus() != eBlock)
				{
					// �̹� ������ ��� �� �� �ʿ�?
					astar[start.x][start.y].SetNowStatus(eOpen);
					astar[start.x + j][start.y + i].SetGValue(CheckDirection(j, i));
					astar[start.x + j][start.y + i].SetHValue(CalcHDirection(dest, start.x + j, start.y + i));
					astar[start.x + j][start.y + i].SetFValue();
				}
			}

		}	// for_j
	} // for_i
	// ����ġ �ΰ�

	// ���� �� ����
	Point nextPath = { eBlock, eBlock };

	int smallVal = 10000;
	int hVal = 10000;
	for (int i = -1; i < 2; i++)
	{
		if (start.y + i < 0 || start.y + i >= defSize) continue;	// ���� �� ����

		for (int j = -1; j < 2; j++)
		{
			if (i == 0 && j == 0) continue;	// �ڱ��ڽ� ����
			else if (start.x + j < 0 || start.x + j >= defSize) continue;	// ���� �� ����
			else
			{
				if (smallVal == astar[start.x + j][start.y + i].GetFValue() && astar[start.x + j][start.y + i].GetNowStatus() != eClose && astar[start.x + j][start.y + i].GetNowStatus() != eBlock)
				{
					if (hVal > astar[start.x + j][start.y + i].GetHValue())
					{
						hVal = astar[start.x + j][start.y + i].GetHValue();
						smallVal = astar[start.x + j][start.y + i].GetFValue();
						nextPath.x = start.x + j;
						nextPath.y = start.y + i;
					}
				}
				else if (smallVal > astar[start.x + j][start.y + i].GetFValue() && astar[start.x + j][start.y + i].GetNowStatus()!= eClose && astar[start.x + j][start.y + i].GetNowStatus() != eBlock)
				{
					hVal = astar[start.x + j][start.y + i].GetHValue();
					smallVal = astar[start.x + j][start.y + i].GetFValue();
					nextPath.x = start.x + j;
					nextPath.y = start.y + i;
				}
			}
		}
	}
	// ���� �� ����

	astar[start.x][start.y].SetNowStatus(eClose);

	// ���
	// for (int i = 0; i < 5; i++)
	// {
	// 	for (int j = 0; j < 5; j++)
	// 	{
	// 		cout << astar[i][j].GetHValue() << "\t";
	// 	}
	// 	cout << endl;
	// }
	// 
	// cout << nextPath.x << " " << nextPath.y << endl;
	// ���

	return nextPath;
}

int AStar::CheckDirection(int x, int y)
{
	if (x != 0 && y != 0)
		return eCross;	// �밢��
	else
		return eStraight;	// 4����
}

int AStar::CalcHDirection(Point dest, int x, int y)
{
	Point destDirection = { 9999,9999 };
	int tempX, tempY;
	int hValue = 0;

	if (x == dest.x && y == dest.y)
		return 0;	// �������� ���

	while (destDirection.x >= x || destDirection.y >= y)
	{
		destDirection.x = dest.x - x;
		destDirection.y = dest.y - y;

		if (destDirection.x < 0)
			tempX = -1;
		else if (destDirection.x == 0)
			tempX = 0;
		else
			tempX = 1;

		if (destDirection.y < 0)
			tempY = -1;
		else if (destDirection.y == 0)
			tempY = 0;
		else
			tempY = 1;

		hValue += CheckDirection(tempX, tempY);

		if (x == 0)
			destDirection.x--;
		if (y == 0)
			destDirection.y--;

		dest.x = destDirection.x;
		dest.y = destDirection.y;
	}
	
	 return hValue;

	//int tempX, tempY;
	//int hValue = 0;

	//if (x == dest.x && y == dest.y)
	//	return 0;	// �������� ���

	//while (x!=dest.x || y!=dest.y)
	//{
	//	if (destDirection.x < 0)
	//		tempX = -1;
	//	else if (destDirection.x == 0)
	//		tempX = 0;
	//	else
	//		tempX = 1;

	//	if (destDirection.y < 0)
	//		tempY = -1;
	//	else if (destDirection.y == 0)
	//		tempY = 0;
	//	else
	//		tempY = 1;

	//	hValue += CheckDirection(tempX, tempY);
	//}

	//return hValue;
}

void AStar::SetNowStatus(int isStatus)
{
	nowStatus = isStatus;
}

void AStar::SetGValue(int value)
{
	gValue = value;
}

void AStar::SetHValue(int value)
{
	hValue = value;
}

void AStar::SetFValue()
{
	fValue += gValue + hValue;
	//fValue = gValue + hValue;
}

void AStar::SetIsBlock(bool block)
{
	isBlock = block;
}

void AStar::SetIsReverse(bool reverse)
{
	isReverse = reverse;
}

int AStar::GetNowStatus()
{
	return nowStatus;
}

int AStar::GetGValue()
{
	return gValue;
}

int AStar::GetHValue()
{
	return hValue;
}

int AStar::GetFValue()
{
	return fValue;
}

bool AStar::GetIsBlock()
{
	return isBlock;
}

bool AStar::GetIsReverse()
{
	return isReverse;
}
