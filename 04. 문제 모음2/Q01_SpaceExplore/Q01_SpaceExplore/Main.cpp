#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Point
{
	int x;
	int y;
};

int main()
{
	/*
	  char map[7][8] =
      {
         {'0','0','0','0','0','0','0','0'},
         {'0','X','X','X','0','X','X','0'},
         {'0','0','0','0','0','X','X','0'},
         {'0','S','0','X','0','X','X','F'},
         {'0','0','0','X','0','0','0','0'},
         {'0','0','0','X','0','0','0','0'},
         {'0','0','0','0','0','0','0','0'},
      };
	*/

	int mapX, mapY;
	cin >> mapX >> mapY;

	string **map;
	map = new string *[mapY];
	for (int i = 0; i < mapX; i++)
		map[i] = new string [mapX];

	// >> 맵 입력
	string input;
	for (int i = 0; i < mapY; i++)
	{
		input = "\0";
		cout << i + 1 << "map : ";
		cin >> input;
		for (int j = 0; j < mapX; j++)
		{
			map[i][j] = input[j];
		}
	}
	// << 맵 입력

	Point start, finish, nowSpot;
	vector<Point> cantSpot;

	// >> 좌표 설정
	for (int i = 0; i < mapY; i++)
	{
		for (int j = 0; j < mapX; j++)
		{
			if (map[i][j] == "S" || map[i][j] == "s")
			{
				start = { j,i };
				nowSpot = { j,i };
			}
			else if (map[i][j] == "F" || map[i][j] == "f")
				finish = { j,i };
		}
	}
	// << 좌표 설정

	Point temp;
	for (int i = -1; i < 1; i++)
	{
		for (int j = -1; j < 1; j++)
		{
			if (i == 0 && j == 0)
				continue;

			if (nowSpot.x + j < mapX && nowSpot.y + i < mapY)
			{

			}

		}
	}


	// << 맵 출력
	for (int i = 0; i < mapY; i++)
	{
		for (int j = 0; j < mapX; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	// >> 맵 출력

	// >> 동적할당 해제
	for (int i = 0; i < mapY; i++)
		delete[] map[i];
	delete[] map;
	// << 동적할당 해제

	return 0;
}