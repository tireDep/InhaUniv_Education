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
	~HideMap();

	void DrawPolygon(HDC hdc);

	void AddSpot(POINT addSpot);
	void RemoveSpot();
	vector<POINT> GetHideMapPos();
	void AddSpot();
	void RemoveAllSpot();
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
};