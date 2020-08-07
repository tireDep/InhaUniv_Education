#include "stdafx.h"
#include "MapClass.h"

HideMap::HideMap()
{

}

HideMap::HideMap(int x1, int y1, int x2, int y2)
{
	this->AddSpot({ x1, y1 });
	this->AddSpot({ x2, y1 });
	this->AddSpot({ x2, y2 });
	this->AddSpot({ x1, y2 });
}

HideMap::~HideMap()
{

}

void HideMap::DrawPolygon(HDC hdc, int i)
{
	printf("HideMap : %f\n", CalcMapArea());

	POINT *printMap = new POINT[mapPos.size()];

	// for (int i = 0; i < mapPos.size(); i++)
	// {
	// 	printMap[i].x = mapPos[i].x;
	// 	printMap[i].y = mapPos[i].y;
	// }
	// 
	// // Polygon(hdc, printMap, mapPos.size());
	// MoveToEx(hdc, printMap[0].x, printMap[0].y, NULL);
	// for (int i = 0; i < mapPos.size(); i++)
	// {
	// 	LineTo(hdc, printMap[i + 1].x, printMap[i + 1].y);
	// }

	for (int i = 0; i < mapPos.size() - 1; i++)
	{
		MoveToEx(hdc, mapPos[i].x, mapPos[i].y, NULL);
		LineTo(hdc, mapPos[i+1].x, mapPos[i+1].y);
	}
	if (i == 1)
	{
		MoveToEx(hdc, mapPos[mapPos.size() - 1].x, mapPos[mapPos.size() - 1].y, NULL);
		LineTo(hdc, mapPos[0].x, mapPos[0].y);
	}

	HBRUSH hBrush, oldBrush;
	if (i == 0)
	{
		hBrush = CreateSolidBrush(RGB(100, 150, 255));
		
	}
	else
	{
		hBrush = CreateSolidBrush(RGB(10, 100, 0));

	}
	
	ExtFloodFill(hdc, 83, 83, 0x00ffffff, FLOODFILLSURFACE);

	oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
	SelectObject(hdc, oldBrush);
	DeleteObject(hBrush);
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
	POINT temp;
	if (mapPos.size() != 2 && mapPos.size()%2 != 0)
	{
		// 1칸 이동시 버그 있음!!
		 if (mapPos[0].x < mapPos[1].x && mapPos[0].y == mapPos[1].y && mapPos[1].y > mapPos[mapPos.size() - 1].y)
		 {
		 	temp.x = mapPos[0].x;
		 	temp.y = mapPos[mapPos.size() - 1].y;
		 }	// 좌우상
		 else if (mapPos[0].y < mapPos[1].y && mapPos[0].x == mapPos[1].x && mapPos[1].x > mapPos[mapPos.size() - 1].x)
		 {
		 	temp.x = mapPos[mapPos.size() - 1].x;
		 	temp.y = mapPos[0].y;
		 }	// 하우좌
		 // 왼상단
		else if (mapPos[0].x > mapPos[1].x && mapPos[0].y == mapPos[1].y && mapPos[1].y > mapPos[mapPos.size() - 1].y)
		{
			temp.x = mapPos[0].x;
			temp.y = mapPos[mapPos.size() - 1].y;
		}	// 우좌상 == 좌우상
		else if (mapPos[0].y < mapPos[1].y && mapPos[0].x == mapPos[1].x && mapPos[1].x < mapPos[mapPos.size() - 1].x)
		{
			temp.x = mapPos[mapPos.size() - 1].x;
			temp.y = mapPos[0].y;
		}	// 하좌우 == 하우좌
		////우상단
		else if (mapPos[0].x < mapPos[1].x && mapPos[0].y == mapPos[1].y && mapPos[1].y < mapPos[mapPos.size() - 1].y)
		{
			temp.x = mapPos[0].x;
			temp.y = mapPos[mapPos.size() - 1].y;
		}	// 좌우하
		else if (mapPos[0].y > mapPos[1].y && mapPos[0].x == mapPos[1].x && mapPos[1].x > mapPos[mapPos.size() - 1].x)
		{
			temp.x = mapPos[mapPos.size() - 1].x;
			temp.y = mapPos[0].y;
		}	// 상우좌
		// 좌하단
		else if (mapPos[0].y > mapPos[1].y && mapPos[0].x == mapPos[1].x && mapPos[1].x < mapPos[mapPos.size() - 1].x)
		{
			temp.x = mapPos[mapPos.size() - 1].x;
			temp.y = mapPos[0].y;
		}	// 상좌우
		else if (mapPos[0].x > mapPos[1].x && mapPos[0].y == mapPos[1].y && mapPos[1].y < mapPos[mapPos.size() - 1].y)
		{
			temp.x = mapPos[0].x;
			temp.y = mapPos[mapPos.size() - 1].y;
		}	// 우좌하
		// 우하단
		else
		{
			temp.x = mapPos[mapPos.size()-1].x;
			temp.y = mapPos[0].y;
		}

		mapPos.push_back(temp);
	}
	else if (mapPos.size() == 2)
	{
		if (mapPos[0].y == mapPos[mapPos.size() - 1].y)	// 좌우 직선
		{
			temp.x = mapPos[1].x;
			if (mapPos[1].y <= (eStartPosY + ePosBottom) / 2)
				temp.y = eStartPosY + eDecimal / 2;
			else
				temp.y = ePosBottom;
			
			//temp.y = eStartPosY + eDecimal / 2;

			mapPos.push_back(temp);
			temp.x = mapPos[0].x;
			mapPos.push_back(temp);
		}
		else if (mapPos[0].x == mapPos[1].x)	// 상하 직선
		{
			temp.y = mapPos[1].y;
			if (mapPos[1].x <= (eStartposX + ePosRight) / 2)
				temp.x = eStartposX + eDecimal / 2;
			else
				temp.x = ePosBottom;

			//temp.x = eStartposX + eDecimal / 2;

			mapPos.push_back(temp);
			temp.y = mapPos[0].y;
			mapPos.push_back(temp);
		}
	}
	else if(mapPos.size() % 2 == 0) //else if (mapPos.size() == 4)
	{
		if (mapPos[0].x == mapPos[1].x)
		{
			temp.x = mapPos[mapPos.size() - 1].x;
			if (mapPos[0].y < mapPos[mapPos.size() - 1].y)
				temp.y = mapPos[0].y;
			else
				temp.y = mapPos[mapPos.size() - 1].y;
		}
		else if (mapPos[0].y == mapPos[1].y)
		{
			temp.x = mapPos[0].x;
			if(mapPos[0].y < mapPos[mapPos.size() - 1].y)
				temp.y = mapPos[0].y;
			else
				temp.y = mapPos[mapPos.size() - 1].y;
		}

		mapPos.push_back(temp);
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
					return false;	// 직선의 시작과 끝 사이에 점이 존재하는지
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

float HideMap::CalcMapArea()
{
	float calcX = 0;
	float calcY = 0;
	float result = 0;

	for (int i = 0; i < mapPos.size(); i++)
	{
		if (i == mapPos.size() - 1)
		{
			calcX += mapPos[mapPos.size() - 1].x * mapPos[0].y;
		}
		else
		{
			calcX += mapPos[i].x * mapPos[i + 1].y;
		}
	}

	for (int i = 0; i < mapPos.size(); i++)
	{
		if (i == mapPos.size() - 1)
		{
			calcY += mapPos[mapPos.size() - 1].y * mapPos[0].x;
		}
		else
		{
			calcY += mapPos[i].y * mapPos[i + 1].x;
		}
	}

	result = (calcX - calcY) / 2;
	if (result < 0) result *= -1;

	return result;
}