#include <iostream>
#include <Windows.h>

enum { eMapSize = 10 };

void CheckOmok(int map[][eMapSize], bool playerColor[][eMapSize]);	// 오목 판정

bool CheckDirection(int map[][eMapSize], bool playerColor[][eMapSize], int i, int j, int &direction, bool isPlayerColor);	// 방향 판정
void SetDirection(int &setDirection, int direction);	// 방향 설정
bool CheckSpot(int map[][eMapSize], bool playerColor[][eMapSize], int i, int j, int direction, int &cnt, bool isPlayerColor);	// 5개인지 확인

int main()
{
	int map[eMapSize][eMapSize] = { 0 };
	bool playerColor[eMapSize][eMapSize] = { false };
	
	// 임시 맵
	for (int i = eMapSize / 2; i < eMapSize; i++)
	{
		playerColor[i][i] = false;
		map[i][i] = 1;
	}
	
	//playerColor[eMapSize - 1][eMapSize - 1] = true;
	//map[0][1] = 1;

	//for (int i = 0; i < eMapSize/2; i++)
	//	map[eMapSize/2][i] = 1;

	map[4][0] = 1;
	map[3][1] = 1;
	map[2][2] = 1;
	map[1][3] = 1;
	map[0][4] = 1;
	
	playerColor[4][0] = false;
	playerColor[3][1] = false;
	playerColor[2][2] = false;
	playerColor[1][3] = false;
	playerColor[0][4] = true;
	// 임시 맵

	// 출력
	for (int i = 0; i < eMapSize; i++)
	{
		for (int j = 0; j < eMapSize; j++)
		{
			printf("%d ", map[i][j]);
		}
		puts("");
	}
	// 출력

	CheckOmok(map, playerColor);
}

void CheckOmok(int map[][eMapSize], bool playerColor[][eMapSize])
{
	int cnt = 0;
	int direction = 0;

	for (int i = 0; i < eMapSize; i++)
	{
		for (int j = 0; j < eMapSize; j++)
		{
			if (map[i][j] == 1)
			{
				cnt = 0;
				if (CheckDirection(map, playerColor, i, j, direction, playerColor[i][j]))	// 실제 판정시 색상도 필요함
				{
					cnt++;
					if (CheckSpot(map, playerColor, i, j, direction, cnt, playerColor[i][j]))
					{
						printf("오목완성 %d %d\n", j, i);	// x, y 반대
						return;
					}
				}

			}	// if

		}	// for_j
	}	// for_i
}

bool CheckDirection(int map[][eMapSize], bool playerColor[][eMapSize], int i, int j, int &direction, bool isPlayerColor)
{
	direction = 0;
	for (int x = -1; x < 2; x++)
	{
		if (i + x < 0 || i + x >= eMapSize)
			continue;

		for (int y = -1; y < 2; y++)
		{
			direction++;
			if (x == 0 && y == 0)
				continue;

			if (j + y < 0 || j + y >= eMapSize)
				continue;
			// 자기자신 제외, 범위 밖 제외

			if (map[i + x][j + y] == 1 && isPlayerColor == playerColor[i+x][j+y])
				return true;
				//printf("%d %d || %d %d\n", x, y, i, j);
		}
	}
	return false;
}

bool CheckSpot(int map[][eMapSize], bool playerColor[][eMapSize], int i, int j, int direction, int &cnt, bool isPlayerColor)
{
	// 방향 체크
	int checkY;
	int checkX;
	// SetDirection(checkX, direction);
	// SetDirection(checkY, direction);
	if (direction >= 1 && direction <= 3)
		checkY = -1;
	else if (direction >= 4 && direction <= 6)
		checkY = 0;
	else if (direction >= 7 && direction <= 9)
		checkY = 1;

	if (direction == 1 || direction == 4 || direction == 7)
		checkX = -1;
	else if (direction == 2 || direction == 5 || direction == 8)
		checkX = 0;
	else if (direction == 3 || direction == 6 || direction == 9)
		checkX = 1;
	// 방향 체크

	for (int k = 1; k < 5; k++)
	{
		if (map[i + checkY*k][j + checkX*k] && (isPlayerColor == playerColor[i + checkY*k][j + checkX*k]))
			cnt++;
	}

	if (cnt == 5)
		return true;
	else
		return false;
}

void SetDirection(int &setDirection, int direction)
{
	if (direction >= 1 && direction <= 3)
		setDirection = -1;
	else if (direction >= 4 && direction <= 6)
		setDirection = 0;
	else if (direction >= 7 && direction <= 9)
		setDirection = 1;
}
