#include "stdafx.h"
#include "ObstalceClass.h"
#include "Function.h"

enum { eBulletDecimal = 13 };

Block::Block()
{
	for (int i = 0; i < 4; i++)
	{
		blockPos[i].x = 0;
		blockPos[i].y = 0;
	}
}

Block::Block(int left, int top, int right, int bottom, int _downSpeed)
{
	blockPos[0].x = left;
	blockPos[0].y = top;

	blockPos[1].x = right;
	blockPos[1].y = top;

	blockPos[2].x = right;
	blockPos[2].y = bottom;

	blockPos[3].x = left;
	blockPos[3].y = bottom;

	hitCheckPos.left = left - eBulletDecimal / 2;
	hitCheckPos.top = top - eBulletDecimal / 2;
	hitCheckPos.right = right + eBulletDecimal / 2;
	hitCheckPos.bottom = bottom + eBulletDecimal / 2;

	downSpeed = _downSpeed;

	radius = (right - left) / 2;

	isHit = FALSE;
}

Block::~Block()
{

}

void Block::Update(vector<vector<Obstacle *>> &obstacle, vector<Obstacle *> &deleteEffect, int &_loseHpPoint)
{
	int hitCnt = 0;
	for (int i = 0; i < obstacle.size(); i++)
	{
		CheckHitDeadLine(obstacle, hitCnt, i);
		CheckLoseHp(obstacle, deleteEffect, hitCnt, _loseHpPoint, i);
	}
}

void Block::CheckHitDeadLine(vector<vector<Obstacle *>> &obstacle, int &hitCnt, int linePos)
{
	for (int j = 0; j < obstacle[linePos].size(); j++)
	{
		obstacle[linePos][j]->DownObstacle();
		if (obstacle[linePos][j]->CheckDeadLine() && !isHit)
			hitCnt++;
	}
}

void Block::CheckLoseHp(vector<vector<Obstacle *>> &obstacle, vector<Obstacle *> &deleteEffect, int &hitCnt, int &_loseHpPoint, int linePos)
{
	if (hitCnt != 0)
	{
		Obstacle *temp;
		for (int i = 0; i < obstacle[linePos].size(); i++)
		{
			temp = obstacle[linePos].at(i);
			deleteEffect.push_back(temp);
		}

		obstacle.erase(obstacle.begin() + linePos);
		_loseHpPoint += 25 * hitCnt;
		hitCnt = 0;
	}
}

void Block::DrawObstacle(HDC hdc)
{
	HPEN hPen, oldPen;
	HBRUSH hBrush, oldBrush;

	SetColor(hdc, hPen, oldPen, 255, 255, 255);
	SetColor(hdc, hBrush, oldBrush, 45, 45, 45);

	Polygon(hdc, blockPos, 4);

	DeleteColor(hdc, hPen, oldPen);
	DeleteColor(hdc, hBrush, oldBrush);
}

void Block::DownObstacle()
{
	for(int i = 0; i < 4; i++)
		blockPos[i].y += downSpeed;

	hitCheckPos.top += downSpeed;
	hitCheckPos.bottom += downSpeed;
	
	centerPos.x += downSpeed;
	centerPos.y += downSpeed;
}

bool Block::CheckDeadLine()
{
	if (blockPos[2].y >= 660)
		return TRUE;
	else
		return FALSE;
}

double Block::GetCenterPosX()
{
	return (blockPos[0].x + blockPos[1].x) / 2;
}

double Block::GetCenterPosY()
{
	return (blockPos[1].y + blockPos[2].y) / 2;
}

int Block::GetRadius()
{
	return radius;
}
