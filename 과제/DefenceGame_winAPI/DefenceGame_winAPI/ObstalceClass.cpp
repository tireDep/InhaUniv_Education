#include "stdafx.h"
#include "ObstalceClass.h"

Block::Block()
{
	blockPos[0].x = 0;
	blockPos[0].y = 0;
	blockPos[1].x = 0;
	blockPos[1].y = 0;
}

Block::Block(int left, int top, int right, int bottom, int _downSpeed)
{
	blockPos[0].x = left;
	blockPos[0].y = top;
	blockPos[1].x = right;
	blockPos[1].y = bottom;

	downSpeed = _downSpeed;
}

Block::~Block()
{

}

void Block::DrawObstacle(HDC hdc)
{
	Rectangle(hdc, blockPos[0].x, blockPos[0].y, blockPos[1].x, blockPos[1].y);
}

void Block::DownObstacle()
{
	blockPos[0].y += 10;
	blockPos[1].y += 10;
}

bool Block::CheckDeadLine()
{
	if (blockPos[1].y >= 670)
		return TRUE;
	else
		return FALSE;
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
