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

	virtual void DrawPolygon(HDC hdc, int i) = 0;
	virtual void AddSpot(POINT addSpot) = 0;
	virtual void RemoveSpot() = 0;
	virtual void RemoveAllSpot() = 0;
};

class HideMap : public Map
{
private:
	static int test;
	vector<POINT> mapPos;

public:
	HideMap();
	HideMap(int x1, int y1, int x2, int y2);
	~HideMap();

	void DrawPolygon(HDC hdc, int i);

	void AddSpot(POINT addSpot);
	//void AddSpot();
	void RemoveSpot();
	void RemoveAllSpot();

	vector<POINT> GetHideMapPos();

	void SetMap(vector<POINT> getMap)
	{
		mapPos = getMap;

		//if (test == 0)
		//{
		//	mapPos.push_back({ ePosLeft, ePosTop });
		//	mapPos.push_back({ ePosRight, ePosTop });
		//	mapPos.push_back({ ePosRight, ePosBottom });
		//	mapPos.push_back({ ePosLeft, ePosBottom });
		//	mapPos.push_back({ ePosLeft, ePosTop });
		//	test++;
		//}

	}
};

class PlayerMap : public Map
{
private:
	vector<POINT> mapPos;

public:
	PlayerMap();
	~PlayerMap();

	void DrawPolygon(HDC hdc, int i);

	void AddSpot(POINT addSpot);
	void RemoveSpot();
	void RemoveAllSpot();

	bool CheckMoveTwice(POINT playerPos);

	vector<POINT> GetMap()
	{
		return mapPos;
	}

	vector<POINT> GetPlayerMapPos()
	{
		return mapPos;
	}
};