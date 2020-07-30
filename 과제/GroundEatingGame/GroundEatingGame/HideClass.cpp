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
	if (mapPos.size() % 2 != 0)	// 가장 바깥 선(외곽선 충돌)
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
		if (it->x > -1)	// 좌표값이 음수가 나올 수 x
		{
			it = mapPos.erase(it);
		}
		else it++;
	}

	// mapPos.clear();	// 메모리는 남아있음
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
		// 직선 위에 점 존재하는지

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
					return false;	// 직선의 시작과 끝 사이에 점이 존재하는지
			}
		}
	}


	int crosses = 0;
	for (int i = 0; i < mapPos.size(); i++) 
	{
		int j = (i + 1) % mapPos.size();	//점 B가 선분 (p[i], p[j])의 y좌표 사이에 있음
		if ((mapPos[i].y > playerPos.y) != (mapPos[j].y > playerPos.y)) 
		{
			//atX는 점 B를 지나는 수평선과 선분 (p[i], p[j])의 교점
			double atX = (mapPos[j].x - mapPos[i].x)*(playerPos.y - mapPos[i].y) / (mapPos[j].y - mapPos[i].y) + mapPos[i].x;
			//atX가 오른쪽 반직선과의 교점이 맞으면 교점의 개수를 증가시킨다.
			if (playerPos.x < atX)
				crosses++;
		}
	}
	return crosses % 2 > 0;
}