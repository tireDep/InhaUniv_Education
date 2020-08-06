#pragma once
#include"GroundEatingGame.h"
#include "MapClass.h"

class Map
{
private:

public:
	Map();
	virtual ~Map() = 0;
	// 상속이 존재할 경우, 가상으로 선언해야함

	virtual void DrawPolygon(HDC hdc) = 0;
	virtual void AddSpot(POINT addSpot) = 0;
	virtual void RemoveSpot() = 0;
	virtual void RemoveAllSpot() = 0;
};

class HideMap : public Map
{
private:
	vector<POINT> mapPos;

public:
	HideMap();
	HideMap(int x1, int y1, int x2, int y2);
	~HideMap();

	void DrawPolygon(HDC hdc);

	void AddSpot(POINT addSpot);
	void AddSpot();
	void RemoveSpot();
	void RemoveAllSpot();

	vector<POINT> GetHideMapPos();

	bool CheckMapInside(POINT playerPos, POINT centerPos, int PlayerTurn);

	float CalcMapArea()
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
};

class PlayerMap : public Map
{
private:
	vector<POINT> mapPos;

public:
	PlayerMap();
	~PlayerMap();

	void DrawPolygon(HDC hdc);

	void AddSpot(POINT addSpot);
	void RemoveSpot();
	void RemoveAllSpot();


	bool CheckMoveTwice(POINT playerPos)
	{
		for (int i = 0; i < mapPos.size(); i++)
		{
			if (playerPos.x == mapPos[i].x && playerPos.y == mapPos[i].y)
				return true;
		}
		return false;
	}
};