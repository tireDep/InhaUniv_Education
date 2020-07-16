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

	virtual void DrawFigureShape(HDC hdc) = 0;

	virtual void MovePos();

	void SetFigureShape(int shape) { figureShape = shape; }
	void SetPosRnd(int rndpos) { rndPos = rndpos; }
	void SetRadius(double radi) { radius = radi; }

	int GetPosRnd() { return rndPos; }
	POINT GetMovePos() { return movePos; }

	//void Update(BasicFigure figure[], RECT viewRect, int cnt);
	//void SetPos(int x, int y, RECT viewRect);

	//void MovePos(BasicFigure figure[], int cnt);

	//double CalcRadian(double degree);
	//virtual void Rotation();

	//void Collision(BasicFigure circle[], BasicFigure rectangle[]);

	//void SetPosX(double pos);
	//void SetPosY(double pos);

	//int GetCenterX();
	//int GetCenterY();
};

class cCircle : public BasicFigure
{
private:
	POINT circlePos[2];

public:
	cCircle();
	cCircle(int posx, int posy);
	~cCircle();

	void DrawFigureShape(HDC hdc);
	void MovePos();
};

class cRect : public BasicFigure
{
private:
	POINT rectPos[2];

public:
	cRect();
	cRect(int posx, int posy);
	~cRect();

	void DrawFigureShape(HDC hdc);
	void MovePos();
};

class cStar : public BasicFigure
{
private:
	POINT starPos[10];

public:
	cStar();
	cStar(int posx, int posy);
	~cStar();

	void AddPoint(int posx, int posy, POINT calcP[]);
	void DrawFigureShape(HDC hdc);
	void MovePos();
	// void Rotation();
};