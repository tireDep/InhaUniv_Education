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

	// >> �� �Է�
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
	// << �� �Է�

	Point start, finish, nowSpot;
	vector<Point> cantSpot;

	// >> ��ǥ ����
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
	// << ��ǥ ����

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


	// << �� ���
	for (int i = 0; i < mapY; i++)
	{
		for (int j = 0; j < mapX; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	// >> �� ���

	// >> �����Ҵ� ����
	for (int i = 0; i < mapY; i++)
		delete[] map[i];
	delete[] map;
	// << �����Ҵ� ����

	return 0;
}