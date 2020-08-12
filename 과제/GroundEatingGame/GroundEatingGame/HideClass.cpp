#include "stdafx.h"
#include "MapClass.h"

int HideMap::test = 0;

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
		oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
		//ExtFloodFill(hdc, mapPos[0].x + 5, mapPos[0].y + 5, 0x00ffffff, FLOODFILLSURFACE);
		//ExtFloodFill(hdc, 95, 95, 0x00ffffff, FLOODFILLSURFACE);
	}
	else
	{
		hBrush = CreateSolidBrush(RGB(10, 100, 0));
		oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
		//ExtFloodFill(hdc, mapPos[0].x + 5, mapPos[0].y + 5, 0x00ffffff, FLOODFILLSURFACE);
	}
	
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

//void HideMap::AddSpot()
//{
//	POINT temp;
//	if (mapPos.size() != 2 && mapPos.size()%2 != 0)
//	{
//		// 1ĭ �̵��� ���� ����!!
//		 if (mapPos[0].x < mapPos[1].x && mapPos[0].y == mapPos[1].y && mapPos[1].y > mapPos[mapPos.size() - 1].y)
//		 {
//		 	temp.x = mapPos[0].x;
//		 	temp.y = mapPos[mapPos.size() - 1].y;
//		 }	// �¿��
//		 else if (mapPos[0].y < mapPos[1].y && mapPos[0].x == mapPos[1].x && mapPos[1].x > mapPos[mapPos.size() - 1].x)
//		 {
//		 	temp.x = mapPos[mapPos.size() - 1].x;
//		 	temp.y = mapPos[0].y;
//		 }	// �Ͽ���
//		 // �޻��
//		else if (mapPos[0].x > mapPos[1].x && mapPos[0].y == mapPos[1].y && mapPos[1].y > mapPos[mapPos.size() - 1].y)
//		{
//			temp.x = mapPos[0].x;
//			temp.y = mapPos[mapPos.size() - 1].y;
//		}	// ���»� == �¿��
//		else if (mapPos[0].y < mapPos[1].y && mapPos[0].x == mapPos[1].x && mapPos[1].x < mapPos[mapPos.size() - 1].x)
//		{
//			temp.x = mapPos[mapPos.size() - 1].x;
//			temp.y = mapPos[0].y;
//		}	// ���¿� == �Ͽ���
//		////����
//		else if (mapPos[0].x < mapPos[1].x && mapPos[0].y == mapPos[1].y && mapPos[1].y < mapPos[mapPos.size() - 1].y)
//		{
//			temp.x = mapPos[0].x;
//			temp.y = mapPos[mapPos.size() - 1].y;
//		}	// �¿���
//		else if (mapPos[0].y > mapPos[1].y && mapPos[0].x == mapPos[1].x && mapPos[1].x > mapPos[mapPos.size() - 1].x)
//		{
//			temp.x = mapPos[mapPos.size() - 1].x;
//			temp.y = mapPos[0].y;
//		}	// �����
//		// ���ϴ�
//		else if (mapPos[0].y > mapPos[1].y && mapPos[0].x == mapPos[1].x && mapPos[1].x < mapPos[mapPos.size() - 1].x)
//		{
//			temp.x = mapPos[mapPos.size() - 1].x;
//			temp.y = mapPos[0].y;
//		}	// ���¿�
//		else if (mapPos[0].x > mapPos[1].x && mapPos[0].y == mapPos[1].y && mapPos[1].y < mapPos[mapPos.size() - 1].y)
//		{
//			temp.x = mapPos[0].x;
//			temp.y = mapPos[mapPos.size() - 1].y;
//		}	// ������
//		// ���ϴ�
//		else
//		{
//			temp.x = mapPos[mapPos.size()-1].x;
//			temp.y = mapPos[0].y;
//		}
//
//		mapPos.push_back(temp);
//	}
//	else if (mapPos.size() == 2)
//	{
//		if (mapPos[0].y == mapPos[mapPos.size() - 1].y)	// �¿� ����
//		{
//			temp.x = mapPos[1].x;
//			if (mapPos[1].y <= (eStartPosY + ePosBottom) / 2)
//				temp.y = eStartPosY + eDecimal / 2;
//			else
//				temp.y = ePosBottom;
//			
//			//temp.y = eStartPosY + eDecimal / 2;
//
//			mapPos.push_back(temp);
//			temp.x = mapPos[0].x;
//			mapPos.push_back(temp);
//		}
//		else if (mapPos[0].x == mapPos[1].x)	// ���� ����
//		{
//			temp.y = mapPos[1].y;
//			if (mapPos[1].x <= (eStartposX + ePosRight) / 2)
//				temp.x = eStartposX + eDecimal / 2;
//			else
//				temp.x = ePosBottom;
//
//			//temp.x = eStartposX + eDecimal / 2;
//
//			mapPos.push_back(temp);
//			temp.y = mapPos[0].y;
//			mapPos.push_back(temp);
//		}
//	}
//	else if(mapPos.size() % 2 == 0) //else if (mapPos.size() == 4)
//	{
//		if (mapPos[0].x == mapPos[1].x)
//		{
//			temp.x = mapPos[mapPos.size() - 1].x;
//			if (mapPos[0].y < mapPos[mapPos.size() - 1].y)
//				temp.y = mapPos[0].y;
//			else
//				temp.y = mapPos[mapPos.size() - 1].y;
//		}
//		else if (mapPos[0].y == mapPos[1].y)
//		{
//			temp.x = mapPos[0].x;
//			if(mapPos[0].y < mapPos[mapPos.size() - 1].y)
//				temp.y = mapPos[0].y;
//			else
//				temp.y = mapPos[mapPos.size() - 1].y;
//		}
//
//		mapPos.push_back(temp);
//	}
//}

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
