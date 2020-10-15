#include <iostream>
#include "cDotGame.h"

using namespace std;

int main()
{
	cDotGame dotGame;
	vector<vector<int>> board = { 
		{ 3,2,3,2 },{ 2,1,1,2 },
		{ 1,1,2,1 },{ 4,1,1,1 }, 
	};

	int answer = dotGame.Solution(board);

	cout << answer << endl;

	return 0;
}