#include "stdafx.h"
#include "MapClass.h"

HideMap::HideMap()
{

}

HideMap::~HideMap()
{

}

void HideMap::DrawPolygon(HDC hdc)
{	
	POINT *printMap = new POINT[mapPos.size()];
	
	for (int i = 0; i < mapPos.size(); i++)
	{
		printMap[i].x = mapPos[i].x;
		printMap[i].y = mapPos[i].y;
	}

	Polygon(hdc, printMap, mapPos.size());
}

void HideMap::AddSpot(POINT addSpot)
{
	mapPos.push_back(addSpot);
}

void HideMap::RemoveSpot()
{
	mapPos.pop_back();
}

vector<POINT> HideMap::GetHideMapPos()
{
	return mapPos;
}

void HideMap::AddSpot()
{
	if (mapPos.size() % 2 != 0)	// ���� �ٱ� ��(�ܰ��� �浹)
	{
		if (mapPos[mapPos.size() - 1].y == ePosTop || mapPos[mapPos.size() - 1].y == ePosBottom)
			mapPos.push_back({ mapPos[0].x, mapPos[mapPos.size() - 1].y });
		else if(mapPos[mapPos.size() - 1].x == ePosLeft || mapPos[mapPos.size() - 1].x == ePosRight)
			mapPos.push_back({ mapPos[mapPos.size() - 1].x, mapPos[0].y });
	}
}

void HideMap::RemoveAllSpot()
{
	vector<POINT>::iterator it;
	POINT *temp;
	for (it = mapPos.begin(); it<mapPos.end(); )
	{
		if (it->x > -1)	// ��ǥ���� ������ ���� �� x
		{
			it = mapPos.erase(it);
		}
		else it++;
	}

	// mapPos.clear();	// �޸𸮴� ��������
}

bool HideMap::CheckMapInside(POINT playerPos, POINT centerPos, int PlayerTurn)
{
	int x1, y1, x2, y2;
	int result;


	for (int i = 0; i < mapPos.size(); i++)
	{
		if (i == mapPos.size() - 1)
		{
			x1 = mapPos[0].x;
			y1 = mapPos[0].y;
			x2 = mapPos[i].x;
			y2 = mapPos[i].y;
		}
		else
		{
			x1 = mapPos[i].x;
			y1 = mapPos[i].y;
			x2 = mapPos[i + 1].x;
			y2 = mapPos[i + 1].y;
		}

		result = (y1 - y2) * centerPos.x + (x2 - x1) * centerPos.y + x1 * y2 - x2 * y1;
		// ���� ���� �� �����ϴ���

		if (result == 0)
		{
			if ((centerPos.x >= x1 && centerPos.x <= x2) && (centerPos.y >= y1 && centerPos.y <= y2)
				|| (centerPos.x >= x2 && centerPos.x <= x1) && (centerPos.y >= y2 && centerPos.y <= y1))
			{
				// if (mapPos[0].x == mapPos[1].x + emoveSpeed || mapPos[0].x + emoveSpeed == mapPos[1].x)
				// {
				// 	if ((playerPos.y != mapPos[0].y && playerPos.y != mapPos[2].y) && (eLeft == PlayerTurn || eRight == PlayerTurn))
				// 		return true;
				// 	else
				// 		return false;
				// }
				// else if (mapPos[0].x == mapPos[2].x + emoveSpeed || mapPos[0].x + emoveSpeed == mapPos[2].x)
				// {
				// 	if ((playerPos.y != mapPos[0].y && playerPos.y != mapPos[2].y) && (eLeft == PlayerTurn || eRight == PlayerTurn))
				// 		return true;
				// 	else
				// 		return false;
				// }
				// 
				// if (mapPos[0].y == mapPos[2].y + emoveSpeed || mapPos[0].y + emoveSpeed == mapPos[2].y)
				// {
				// 	if ((playerPos.x != mapPos[0].x && playerPos.x != mapPos[2].x) && (eUp == PlayerTurn || eDown == PlayerTurn))
				// 		return true;
				// 	else
				// 		return false;
				// }
				// else if (mapPos[0].y == mapPos[1].y + emoveSpeed || mapPos[0].y + emoveSpeed == mapPos[1].y)
				// {
				// 	if ((playerPos.x != mapPos[0].x && playerPos.x != mapPos[1].x) && (eUp == PlayerTurn || eDown == PlayerTurn))
				// 		return true;
				// 	else
				// 		return false;
				// }
				// else
					return false;	// ������ ���۰� �� ���̿� ���� �����ϴ���
			}
		}
	}


	int crosses = 0;
	for (int i = 0; i < mapPos.size(); i++) 
	{
		int j = (i + 1) % mapPos.size();	//�� B�� ���� (p[i], p[j])�� y��ǥ ���̿� ����
		if ((mapPos[i].y > playerPos.y) != (mapPos[j].y > playerPos.y)) 
		{
			//atX�� �� B�� ������ ���򼱰� ���� (p[i], p[j])�� ����
			double atX = (mapPos[j].x - mapPos[i].x)*(playerPos.y - mapPos[i].y) / (mapPos[j].y - mapPos[i].y) + mapPos[i].x;
			//atX�� ������ ���������� ������ ������ ������ ������ ������Ų��.
			if (playerPos.x < atX)
				crosses++;
		}
	}
	return crosses % 2 > 0;
}