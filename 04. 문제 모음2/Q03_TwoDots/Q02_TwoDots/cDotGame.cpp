#include "cDotGame.h"

cDotGame::cDotGame()
{
}

cDotGame::~cDotGame()
{
}

int cDotGame::Solution(vector<vector<int>>& board)
{
	int answer = 0;
	ST_SPOT spot;
	spot.x = 0;
	spot.y = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			CalcPath(board, spot, answer);
		}
	}

	return answer;
}

int cDotGame::CalcPath(vector<vector<int>>& board, ST_SPOT pos, int& maxNum)
{
	int tNum = 0;
	int arrX[4] = { 0,1,0,-1 };
	int arrY[4] = { -1,0,1,0 };

	ST_SPOT moveSpot;
	for (int i = 0; i < 4; i++)
	{
		moveSpot.x = pos.x + arrX[i];
		moveSpot.y = pos.y + arrY[i];

		if (IsCanMove(moveSpot, pos, board, i) 
			&& IsInRange(moveSpot, pos,board.size()) 
			&& IsSameNumber(pos,moveSpot,board))
		{
			// all true
			tNum = 10;
			// tNum = CalcPath(board, pos, tNum);
			if (tNum > maxNum)
				maxNum = tNum;
		}
		else
			continue;
	}

	return maxNum;
}

bool cDotGame::IsCanMove(ST_SPOT spot, ST_SPOT lastSpot, vector<vector<int>>& board, int check)
{
	if (spot.x == lastSpot.x && spot.y == lastSpot.y)
		return false;
	// 직전 위치랑 같은지

	if (check == 4)
		return false;

	return true;
}

bool cDotGame::IsInRange(ST_SPOT spot, ST_SPOT lastSpot, int size)
{
	if (spot.x >= size || spot.y >= size)
		return false;

	if (spot.x < 0 || spot.y < 0)
		return false;

	return true;
}

bool cDotGame::IsSameNumber(ST_SPOT spot, ST_SPOT lastSpot, vector<vector<int>>& board)
{
	if (board[spot.x][spot.y] != board[lastSpot.x][lastSpot.y])
		return false;
	
	return true;
}
