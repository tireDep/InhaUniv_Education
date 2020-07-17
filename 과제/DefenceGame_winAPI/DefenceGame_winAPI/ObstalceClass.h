#pragma once
#include"stdafx.h"
#include"DefenceGame_winAPI.h"

class Obstacle
{
private:

public:
	Obstacle() { }
	Obstacle(int left, int top, int right, int bottom){ }

	~Obstacle() {}

	virtual void DrawObstacle(HDC hdc) = 0;
	virtual void DownObstacle() = 0;
	virtual bool CheckDeadLine() = 0;
};

class Block : public Obstacle
{
private:
	POINT blockPos[2];
	int downSpeed;

public:
	Block() 
	{
		blockPos[0].x = 0;
		blockPos[0].y = 0;
		blockPos[1].x = 0;
		blockPos[1].y = 0;
	}

	Block(int left, int top, int right, int bottom, int _downSpeed)
	{
		blockPos[0].x = left;
		blockPos[0].y = top;
		blockPos[1].x = right;
		blockPos[1].y = bottom;

		downSpeed = _downSpeed;
	}

	~Block() 
	{

	}

	void DrawObstacle(HDC hdc)
	{
		Rectangle(hdc, blockPos[0].x, blockPos[0].y, blockPos[1].x, blockPos[1].y);
	}

	void DownObstacle()
	{
		blockPos[0].y += downSpeed;
		blockPos[1].y += downSpeed;
	}

	bool CheckDeadLine()
	{
		if (blockPos[1].y >= 655)
			return TRUE;
		else
			return FALSE;
	}
};
