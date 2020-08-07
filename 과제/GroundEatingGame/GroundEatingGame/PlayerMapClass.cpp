#include "stdafx.h"
#include "MapClass.h"

PlayerMap::PlayerMap()
{

}

PlayerMap::~PlayerMap()
{

}

void PlayerMap::DrawPolygon(HDC hdc, int i)
{
	HPEN hPen, oldPen;
	hPen = CreatePen(2, 1, RGB(0, 0, 255));
	oldPen = (HPEN)SelectObject(hdc, hPen);
	
	if (mapPos.size() > 0)
	{
		for (int i = 0; i < mapPos.size() - 1; i++)
		{
			MoveToEx(hdc, mapPos[i].x, mapPos[i].y, NULL);
			LineTo(hdc, mapPos[i + 1].x, mapPos[i + 1].y);
		}
	}

	SelectObject(hdc, oldPen);
	DeleteObject(hPen);
}

void PlayerMap::AddSpot(POINT addSpot)
{
	mapPos.push_back(addSpot);
}

void PlayerMap::RemoveSpot()
{
	mapPos.pop_back();
}

void PlayerMap::RemoveAllSpot()
{
	vector<POINT>::iterator it;
	POINT *temp;
	for(it = mapPos.begin();it<mapPos.end(); )
	{
		if (it -> x > -1)	// 좌표값이 음수가 나올 수 x
		{
			it = mapPos.erase(it);
		}
		else it++;
	}

	// mapPos.clear();	// 메모리는 남아있음
}

bool PlayerMap::CheckMoveTwice(POINT playerPos)
{
	for (int i = 0; i < mapPos.size(); i++)
	{
		if (playerPos.x == mapPos[i].x && playerPos.y == mapPos[i].y)
			return true;
	}
	return false;
}