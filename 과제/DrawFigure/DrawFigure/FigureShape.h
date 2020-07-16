#pragma once
#include "stdafx.h"
#define _USE_MATH_DEFINES
#include<math.h>
#include<time.h>

#include<vector>
using std::vector;

enum FigureNum { eCIR = 0, eRECT = 4, eSTAR = 5, eBASIC = 0 };

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
	BasicFigure() : rndPos(0), radius(0), angle(0), figureShape(eBASIC)
	{
		movePos.x = 0;
		movePos.y = 0;
	};
	~BasicFigure() { };

	virtual void DrawFigureShape(HDC hdc) = 0;

	virtual void MovePos();

	virtual void Update(RECT rectView) = 0;

	virtual void Collision(vector<BasicFigure *> figureList, int count) = 0;

	void SetFigureShape(int shape) { figureShape = shape; }
	void SetPosRnd(int rndpos) { rndPos = rndpos; }
	void SetRadius(double radi) { radius = radi; }
	void SetMovePosX(int posx) { movePos.x *= posx; }
	void SetMovePosY(int posy) { movePos.y *= posy; }

	int GetPosRnd() { return rndPos; }
	double GetRadius() { return radius; }
	int GetFigureShape() { return figureShape; }
	POINT GetMovePos() { return movePos; }

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
	
	void Update(RECT rectView);

	void Collision(vector<BasicFigure *> figureList, int count);

	double GetLeftPosX() { return circlePos[0].x; }
	double GetTopPosY() { return circlePos[0].y; }

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

	void Update(RECT rectView);

	void Collision(vector<BasicFigure *> figureList, int count);

	double GetLeftPosX() { return rectPos[0].x; }
	double GetTopPosY() { return rectPos[0].y; }
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

	void Update(RECT rectView);

	void Collision(vector<BasicFigure *> figureList, int count);

	double GetLeftPosX() { return starPos[0].x; }
	double GetTopPosY() { return starPos[0].y; }
};