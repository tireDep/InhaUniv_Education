#pragma once
#include <vector>

using namespace std;

struct ST_SPOT
{
	int x;
	int y;
};

class cDotGame
{
private:

public:
	cDotGame();
	~cDotGame();

	int Solution(vector<vector<int>>& board);

	int CalcPath(vector<vector<int>>& board, ST_SPOT pos, int& maxNum);
	
	bool IsCanMove(ST_SPOT spot, ST_SPOT lastSpot, vector<vector<int>>& board, int check);
	bool IsInRange(ST_SPOT spot, ST_SPOT lastSpot, int size);
	bool IsSameNumber(ST_SPOT spot, ST_SPOT lastSpot, vector<vector<int>>& board);
};