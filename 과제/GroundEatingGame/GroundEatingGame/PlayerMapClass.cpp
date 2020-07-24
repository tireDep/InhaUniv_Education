#include "stdafx.h"
#include "MapClass.h"

PlayerMap::PlayerMap()
{

}

PlayerMap::~PlayerMap()
{

}

void PlayerMap::DrawPolygon(HDC hdc)
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