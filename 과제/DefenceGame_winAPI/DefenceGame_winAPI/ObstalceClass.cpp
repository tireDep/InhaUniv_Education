#include "stdafx.h"
#include "ObstalceClass.h"

void Obstacle::Update(vector<vector<Obstacle *>> &obstacle, int &_loseHpPoint)
{
	int hitCnt = 0;
	for (int i = 0; i < obstacle.size(); i++)
	{
		CheckHit(obstacle, hitCnt, i);
		CheckLoseHp(obstacle, hitCnt, _loseHpPoint, i);
	}
}

void Obstacle::CheckHit(vector<vector<Obstacle *>> &obstacle, int &hitCnt, int linePos)
{
	for (int j = 0; j < obstacle[linePos].size(); j++)
	{
		obstacle[linePos][j]->DownObstacle();
		if (obstacle[linePos][j]->CheckDeadLine())
			hitCnt++;
	}
}

void Obstacle::CheckLoseHp(vector<vector<Obstacle *>> &obstacle, int &hitCnt, int &_loseHpPoint, int linePos)
{
	if (hitCnt != 0)
	{
		obstacle.erase(obstacle.begin() + linePos);
		_loseHpPoint += 10 * hitCnt;
		hitCnt = 0;
	}
}
