#pragma once
#include "stdafx.h"
#include <iostream>

enum { eMapSize = 19 };

bool CheckOmok(int map[][eMapSize], int playerColor[][eMapSize]);	// ���� ����

bool CheckDirection(int map[][eMapSize], int playerColor[][eMapSize], int i, int j, int &direction, int isPlayerColor);	// ���� ����
void SetDirection(int &setDirection, int direction);	// ���� ����
bool CheckSpot(int map[][eMapSize], int playerColor[][eMapSize], int i, int j, int direction, int &cnt, int isPlayerColor);	// 5������ Ȯ��

bool CheckOmok(int map[][eMapSize], int playerColor[][eMapSize])
{
	int cnt = 0;
	int direction = 0;

	for (int i = 0; i < eMapSize; i++)
	{
		for (int j = 0; j < eMapSize; j++)
		{
			if (map[i][j] == 1 || map[i][j] == -1)
			{
				cnt = 0;
				if (CheckDirection(map, playerColor, i, j, direction, playerColor[i][j]))	// ���� ������ ���� �ʿ���
				{
					if (CheckSpot(map, playerColor, i, j, direction, cnt, playerColor[i][j]))
						return true;
				}

			}	// if

		}	// for_j
	}	// for_i

	return false;
}

bool CheckDirection(int map[][eMapSize], int playerColor[][eMapSize], int i, int j, int &direction, int isPlayerColor)
{
	for (int x = -1; x < 2; x++)
	{
		if (i + x < 0 || i + x >= eMapSize)
			continue;

		for (int y = -1; y < 2; y++)
		{
			if (x == 0 && y == 0)
				continue;

			if (j + y < 0 || j + y >= eMapSize)
				continue;
			// �ڱ��ڽ� ����, ���� �� ����

			if ((map[i + x][j + y] == 1 || map[i + x][j + y] == -1) && isPlayerColor == playerColor[i + x][j + y])
			{
				if (x == -1 && y == 1) direction = 1;
				if (x == -1 && y == 0) direction = 2;
				if (x == -1 && y == 1) direction = 3;

				if (x == 0 && y == -1) direction = 4;
				if (x == 0 && y == 1) direction = 6;

				if (x == 1 && y == -1) direction = 7;
				if (x == 1 && y == 0) direction = 8;
				if (x == 1 && y == 1) direction = 9;

				return true;
			}
		}
	}
	return false;
}

bool CheckSpot(int map[][eMapSize], int playerColor[][eMapSize], int i, int j, int direction, int &cnt, int isPlayerColor)
{
	// ���� üũ
	int checkY;
	int checkX;

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
	// ���� üũ

	 for (int k = 0; k < 5; k++)
	 {
	 	if (map[i + checkY*k][j + checkX*k] && (isPlayerColor == playerColor[i + checkY*k][j + checkX*k]))
	 		cnt++;
		// ���� �����ϰ� ���� ���� ��� ���� ����
	 }
	 // todo : 6�� �̻��� ��� �Ǻ�x

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
