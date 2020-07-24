#pragma once
#include"GroundEatingGame.h"
#include "MapClass.h"

class Map
{
private:

public:
	Map();
	~Map();

	virtual void DrawPolygon(HDC hdc) = 0;
	virtual void AddSpot(POINT addSpot) = 0;
	virtual void RemoveSpot() = 0;
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
};