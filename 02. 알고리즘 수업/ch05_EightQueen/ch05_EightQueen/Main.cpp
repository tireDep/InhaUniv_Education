// 183p
// Q. 8퀸 문제
// - 재귀를 사용해서 풀 수 있음
// - 경우의 수 : 92가지 =

#include<iostream>
#include<cstdlib>
#include<ctime>

const int arrSize = 8;

void PrintMap(int map[][arrSize]);
void CollocatQueen(int map[][arrSize], int x, int y, int &maxQueen);

using namespace std;

int main()
{
	srand((unsigned)time(NULL));

	int x = -1;
	int y = 0;
	int maxQueen = 8;
	int map[arrSize][arrSize] = { 0 };	// 비어있는 체스판

	CollocatQueen(map, x, y, maxQueen);

	PrintMap(map);

	return 0;
}

void CollocatQueen(int map[][arrSize], int x, int y, int &maxQueen)
{
	x++;
	y = rand() % 8;

	//for(int i=0)

	if (map[x][y] == 0 && x < arrSize && y < arrSize)
	{
		maxQueen--;
		map[x][y] = 1;

		int tempX = x;
		int tempY = y;
		int tempCrossX = x;
		int tempCrossY = y;
		
		while (1)
		{
			if (tempX == 0 || tempY == 0)
				break;

			tempX--;
			tempY--;
		}

		while (1)
		{
			if (tempCrossX == 0 || tempCrossY + 1 == arrSize)
				break;

			tempCrossX--;
			tempCrossY++;
		}

		for (int i = 0; i < 8; i++)
		{
			if (map[x][i] == 0)
				map[x][i] = -1;	// 가로
			if (map[i][y] == 0)
				map[i][y] = -1;	// 세로
			
			if (map[tempX][tempY] == 0)
			{
				if (tempX < arrSize && tempY < arrSize)
				{
					if(tempX>=0 && tempY>=0)
						map[tempX][tempY] = -1;
				}
			}

			 if (map[tempCrossX][tempCrossY] == 0)
			 {
			 	if (tempCrossX < arrSize && tempCrossY < arrSize)
			 	{
			 		if (tempCrossX >= 0 && tempCrossY >= 0)
			 			map[tempCrossX][tempCrossY] = -1;
			 	}
			 }

			tempX++;
			tempY++;
			tempCrossX++;
			tempCrossY--;// cross
		}
		 PrintMap(map);
		 cout << endl;

		CollocatQueen(map, x, y, maxQueen);
	}
	else
		CollocatQueen(map, x, y, maxQueen);
}

void PrintMap(int map[][arrSize])
{
	for (int i = 0; i < arrSize; i++)
	{
		for (int j = 0; j < arrSize; j++)
		{
			if (map[i][j] == 1)
				cout << "◆" << " ";
			else if (map[i][j] == -1)
				cout << "■" << " ";
			else
				cout << "□" << " ";
		}
		cout << endl;
	}
}