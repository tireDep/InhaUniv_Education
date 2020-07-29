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