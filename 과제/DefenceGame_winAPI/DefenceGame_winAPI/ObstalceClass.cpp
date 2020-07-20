#include "stdafx.h"
#include "ObstalceClass.h"
#include "Function.h"

enum { eBulletDecimal = 13 };

Block::Block()
{
	blockPos.left = 0;
	blockPos.top = 0;
	blockPos.right = 0;
	blockPos.bottom = 0;
}

Block::Block(int left, int top, int right, int bottom, int _downSpeed)
{
	blockPos.left = left;
	blockPos.top = top;
	blockPos.right = right;
	blockPos.bottom = bottom;

	hitCheckPos.left = left - eBulletDecimal / 2;
	hitCheckPos.top = top - eBulletDecimal / 2;
	hitCheckPos.right = right + eBulletDecimal / 2;
	hitCheckPos.bottom = bottom + eBulletDecimal / 2;

	downSpeed = _downSpeed;

	radius = (right - left) / 2;
}

Block::~Block()
{

}

void Block::Update(vector<vector<Obstacle *>> &obstacle, int &_loseHpPoint)
{
	int hitCnt = 0;
	for (int i = 0; i < obstacle.size(); i++)
	{
		CheckHitDeadLine(obstacle, hitCnt, i);
		CheckLoseHp(obstacle, hitCnt, _loseHpPoint, i);
	}
}

void Block::CheckHitDeadLine(vector<vector<Obstacle *>> &obstacle, int &hitCnt, int linePos)
{
	for (int j = 0; j < obstacle[linePos].size(); j++)
	{
		obstacle[linePos][j]->DownObstacle();
		if (obstacle[linePos][j]->CheckDeadLine())
			hitCnt++;
	}
}

void Block::CheckLoseHp(vector<vector<Obstacle *>> &obstacle, int &hitCnt, int &_loseHpPoint, int linePos)
{
	if (hitCnt != 0)
	{
		obstacle.erase(obstacle.begin() + linePos);
		_loseHpPoint += 10 * hitCnt;
		hitCnt = 0;
	}
}

void Block::DrawObstacle(HDC hdc)
{
	HPEN hPen, oldPen;
	HBRUSH hBrush, oldBrush;

	SetColor(hdc, hPen, oldPen, 255, 255, 255);
	SetColor(hdc, hBrush, oldBrush, 45, 45, 45);

	Rectangle(hdc, blockPos.left, blockPos.top, blockPos.right, blockPos.bottom);
	//Ellipse(hdc, blockPos.left, blockPos.top, blockPos.right, blockPos.bottom);

	DeleteColor(hdc, hPen, oldPen);
	DeleteColor(hdc, hBrush, oldBrush);
}

void Block::DownObstacle()
{
	blockPos.top += downSpeed;
	blockPos.bottom += downSpeed;

	hitCheckPos.top += downSpeed;
	hitCheckPos.bottom += downSpeed;
	
	centerPos.x += downSpeed;
	centerPos.y += downSpeed;
}

bool Block::CheckDeadLine()
{
	if (blockPos.bottom >= 660)
		return TRUE;
	else
		return FALSE;
}

double Block::GetCenterPosX()
{
	return (blockPos.left + blockPos.right) / 2;
}

double Block::GetCenterPosY()
{
	return (blockPos.bottom + blockPos.top) / 2;
}

int Block::GetRadius()
{
	return radius;
}
