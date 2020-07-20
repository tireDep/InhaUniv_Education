#include "stdafx.h"
#include "ObstalceClass.h"

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
	// Rectangle(hdc, blockPos.left, blockPos.top, blockPos.right, blockPos.bottom);
	Ellipse(hdc, blockPos.left, blockPos.top, blockPos.right, blockPos.bottom);
	wchar_t temp[32];
	_itot_s(centerPos.x, temp, 10);
	TextOut(hdc, blockPos.left, blockPos.top, temp, _tcslen(temp));

	_itot_s(centerPos.y, temp, 10);
	TextOut(hdc, blockPos.right, blockPos.bottom, temp, _tcslen(temp));
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
	if (blockPos.bottom >= 670)
		return TRUE;
	else
		return FALSE;
}

RECT Block::GetHitPos()
{
	return hitCheckPos;
}

RECT Block::GetRectPos()
{
	return blockPos;
}
