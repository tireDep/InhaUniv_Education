#pragma once
#include "stdafx.h"

class Obstacle
{
private:


public:
	Obstacle();
	~Obstacle();

	void DrawObstacle(HDC hdc);
};

Obstacle::Obstacle()
{

}

Obstacle::~Obstacle()
{

}

void Obstacle::DrawObstacle(HDC hdc)
{
	Ellipse(hdc, 100, 100, 110, 110);
}