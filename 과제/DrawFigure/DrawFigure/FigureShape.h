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
	POINT movePos;
	POINT centerPos;
	int rndPos;
	double radius;
	int figureShape;

	int angle;

	static int playType;

public:
	BasicFigure() : rndPos(0), radius(0), angle(0), figureShape(0)
	{
		movePos.x = 0;
		movePos.y = 0;
	};

	~BasicFigure() { };

	void SetFigureShape(int shape) { figureShape = shape; }
	virtual void DrawFigure(HDC hdc) = 0;

	virtual void MovePos();

	void SetPosRnd(int rndpos) { rndPos = rndpos; }
	int GetPosRnd() { return rndPos; }
	POINT GetMovePos() { return movePos;  }

	//void Update(BasicFigure figure[], RECT viewRect, int cnt);
	//void SetPos(int x, int y, RECT viewRect);

	//void CalcRadius();
	//void MovePos(BasicFigure figure[], int cnt);

	//double CalcRadian(double degree);
	//virtual void Rotation();

	//void Collision(BasicFigure circle[], BasicFigure rectangle[]);

	//void SetPosX(double pos);
	//void SetPosY(double pos);

	//int GetPosX();
	//int GetPosY();
	//int GetPosRnd();
	//int GetCenterX();
	//int GetCenterY();
	//
};

class cCircle : public BasicFigure
{
private:
	POINT circlePos;

public:
	cCircle();
	cCircle(int posx, int posy);
	~cCircle();

	void DrawFigure(HDC hdc);
	void MovePos();
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