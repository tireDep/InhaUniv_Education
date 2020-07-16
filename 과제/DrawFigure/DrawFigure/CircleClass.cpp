#include "stdafx.h"
#include "FigureShape.h"

cCircle::cCircle()
{
	for (int i = 0; i < 2; i++)
	{
		circlePos[i].x = 0;
		circlePos[i].y = 0;
	}
	SetFigureShape(eCIR);
};

cCircle::cCircle(int posx, int posy)
{
	srand((unsigned)time(NULL));
	int rndpos = rand() % 100 + 10;

	for (int i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			circlePos[i].x = posx;
			circlePos[i].y = posy;
		}
		else
		{
			circlePos[i].x = posx + rndpos;
			circlePos[i].y = posy + rndpos;
		}
	}

	SetPosRnd(rndpos);
	SetRadius((double) rndpos / 2);
	SetFigureShape(eCIR);
};

cCircle::~cCircle() 
{

};

void cCircle::DrawFigureShape(HDC hdc)
{
	Ellipse(hdc, circlePos[0].x, circlePos[0].y, circlePos[1].x, circlePos[1].y);
}

void cCircle::MovePos()
{
	BasicFigure::MovePos();
	POINT _movePos = GetMovePos();
	for (int i = 0; i < 2; i++)
	{
		this->circlePos[i].x += _movePos.x;
		this->circlePos[i].y += _movePos.y;
	}
}

void cCircle::Update(RECT rectView)
{
	if (circlePos[0].x <= rectView.left || circlePos[1].x >= rectView.right)
		SetMovePosX(-1);
	if (circlePos[0].y <= rectView.top || circlePos[1].y >= rectView.bottom)
		SetMovePosY(-1);
}

void cCircle::Collision(vector<BasicFigure *> figureList, int count)
{
	double r1 = GetRadius();	// ¹ÝÁö¸§
	double r2;
	double calcA;
	double calcB;
	double calcC;
	double calcD;

	double calcX;
	double calcY;
	double length;
	int checkShape;

	calcA = circlePos[0].x + r1;
	calcB = circlePos[0].y + r1;
	for (int i = 0; i < figureList.size(); i++)
	{
		if (count == i)
			continue;

		r2 = figureList[i]->GetRadius();
		checkShape = figureList[i]->GetFigureShape();

		if (checkShape == eCIR)
		{
			cCircle *temp = (cCircle *)figureList[i];
			calcC = temp->circlePos[0].x + r2;
			calcD = temp->circlePos[0].y + r2;
		}
		if (checkShape == eRECT)
		{
			cRect *temp = (cRect *)figureList[i];
			calcC = temp->GetLeftPosX() + r2;
			calcD = temp->GetTopPosY() + r2;
		}
		if (checkShape == eSTAR)
		{
			cStar *temp = (cStar *)figureList[i];
			calcC = temp->GetLeftPosX() + r2;
			calcD = temp->GetTopPosY() + r2;
		}

		calcX = calcA - calcC;
		calcY = calcB - calcD;
		length = sqrt(calcX * calcX + calcY * calcY);

		if (length < (r1 + r2))
		{
			this->SetMovePosX(-1);
			figureList[i]->SetMovePosY(-1);
		}
	}
}