#pragma once
#include "stdafx.h"
#define _USE_MATH_DEFINES
#include<math.h>
#include<time.h>

#include<vector>
using std::vector;

class BasicFigure
{
private:
	POINT point;
	POINT movePoint;
	POINT centerPos;
	int rndPos;
	double radius;
	int figureShape;

	int angle;

	static int playType;

public:
	BasicFigure() : rndPos(0), radius(0), angle(0), figureShape(0)
	{
		point.x = 0;
		point.y = 0;
		movePoint.x = 0;
		movePoint.y = 0;
	};

	~BasicFigure() { };

	void Update(BasicFigure figure[], RECT viewRect, int cnt);
	void SetPos(int x, int y, RECT viewRect);
	virtual void DrawFigure() { };

	void CalcRadius();
	void MovePos(BasicFigure figure[], int cnt);

	double CalcRadian(double degree);
	virtual void Rotation();

	void Collision(BasicFigure circle[], BasicFigure rectangle[]);

	void SetPosX(double pos);
	void SetPosY(double pos);

	int GetPosX();
	int GetPosY();
	int GetPosRnd();
	int GetCenterX();
	int GetCenterY();

	void SetFigureShape(int shape)
	{
		figureShape = shape;
	}
};

class cCircle : public BasicFigure
{
public:
	cCircle()
	{
		SetFigureShape(0);
	};

	~cCircle() { };

	void DrawFigure(HDC hdc);
	// void DrawCircle(HDC hdc);
};

// class cRect : public BasicFigure
// {
// public:
// 	cRect()
// 	{
// 		SetFigureShape(4);
// 	};
// 
// 	~cRect() { };
// 
// 	void DrawFigure(HDC hdc);
// 	void Rotation(double degree);
// };
// 
// class cStar : public BasicFigure
// {
// public:
// 	cStar()
// 	{
// 		SetFigureShape(5);
// 	};
// 
// 	~cStar() { };
// 
// 	void DrawFigure(HDC hdc);
// 	void AddPoint(int degree, int midX, int midY, POINT point[]);
// 	// void Rotation();
// };