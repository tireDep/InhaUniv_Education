#include <iostream>
#include <vector>

using namespace std;

struct Point
{
	int x;
	int y;
};

static const int mapX = 7;
static const int mapY = 8;
int main()
{
	char map[7][8] = 
	{
		{ '0','0','0','0','0','0','0','0' },
		{ '0','X','X','X','0','X','X','0' },
		{ '0','0','0','0','0','X','X','0' },
		{ '0','S','0','X','0','X','X','F' },
		{ '0','0','0','X','0','0','0','0' },
		{ '0','0','0','X','0','0','0','0' },
		{ '0','0','0','0','0','0','0','0' },
	};

	Point start, finish, nowSpot;
	vector<Point> calcSpot;
	vector<Point> cantSpot;
	
	for (int i = 0; i < mapY; i++)
	{
		for (int j = 0; j < mapX; j++)
		{
			if (map[j][i] == 'S')
			{
				start = { i,j };
				nowSpot = { i,j };
			}
			else if (map[j][i] == 'F')
				finish = { i,j };
		}
	}
	// >> 좌표 세팅

	int valArr[7][8] = { 0 };
	Point temp = start;
	bool isWall = false;
	while (1)
	{
		temp.x--;
		if (map[temp.y][temp.x] == 'X')
		{
			isWall = true;
			valArr[temp.y][temp.x] = 9999;
			continue;
		}
		
		if (!isWall && temp.x >= 0 && temp.x != finish.x && temp.x != start.x)
			valArr[temp.y][temp.x] += 1;
		else if (temp.x < 0)
			break;
	}
	temp = start;
	isWall = false;
	while (1)
	{
		temp.x++;
		if (map[temp.y][temp.x] == 'X')
		{
			isWall = true;
			valArr[temp.y][temp.x] = 9999;
			continue;
		}
		if (!isWall && temp.x < mapY && temp.x != finish.x && temp.x != start.x)
			valArr[temp.y][temp.x] += 1;
		else if(temp.x >= mapY)
			break;
	}
	temp = start;
	isWall = false;
	while (1)
	{
		temp.y--;
		if (map[temp.y][temp.x] == 'X')
		{
			isWall = true;
			valArr[temp.y][temp.x] = 9999;
			continue;
		}
		if (!isWall && temp.y >= 0 && temp.y != finish.y && temp.y != start.y)
			valArr[temp.y][temp.x] += 1;
		else if (temp.y < 0)
			break;
	}
	temp = start;
	isWall = false;
	while (1)
	{
		temp.y++;
		if (map[temp.y][temp.x] == 'X')
		{
			isWall = true;
			valArr[temp.y][temp.x] = 9999;
			continue;
		}
		if (!isWall && temp.y < mapX && temp.y != finish.y && temp.y != start.y)
			valArr[temp.y][temp.x] += 1;
		else if (temp.y >= mapX)
			break;
	}

	//int a, b, c, d;
	//for (int i = 0; i < mapX; i++)
	//{
	//	for (int j = 0; j < mapY; j++)
	//	{
	//		if (valArr[i][j] == 9999 || map[i][j]=='S' || map[i][j]=='F')
	//			continue;
	//
	//		a = b = c = d = 0;
	//
	//		if (i - 1 >= 0)
	//			a = valArr[i - 1][j] < 9999 ? valArr[i - 1][j] : 1;
	//
	//		if (i + 1 < mapX)
	//			b = valArr[i + 1][j] < 9999 ? valArr[i + 1][j] : 1;
	//
	//		if (j - 1 >= 0)
	//			c = valArr[i][j - 1] < 9999 ? valArr[i][j - 1] : 1;
	//
	//		if (j + 1 < mapX)
	//			d = valArr[i][j + 1] < 9999 ? valArr[i][j + 1] : 1;
	//
	//		valArr[i][j] += a + b + c + d;
	//	}
	//}


	// >> 출력
	for (int i = 0; i < mapX; i++)
	{
		for (int j = 0; j < mapY; j++)
		{
			cout << valArr[i][j] << "\t";
		}
		cout << endl;
	}
	// << 출력


	return 0;
}