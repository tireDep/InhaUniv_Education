#include "stdafx.h"
#include "FigureShape.h"

cRect::cRect()
{
	for (int i = 0; i < 2; i++)
	{
		rectPos[i].x = 0;
		rectPos[i].y = 0;
	}
	SetFigureShape(eRECT);
};

cRect::cRect(int posx, int posy)
{
	srand((unsigned)time(NULL));
	int rndpos = rand() % 100 + 10;

	for (int i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			rectPos[i].x = posx;
			rectPos[i].y = posy;
		}
		else
		{
			rectPos[i].x = posx + rndpos;
			rectPos[i].y = posy + rndpos;
		}
	}

	SetPosRnd(rndpos);
	SetRadius((double)rndpos / 2);
	SetFigureShape(eRECT);
};

cRect::~cRect() 
{ 

};

void cRect::DrawFigureShape(HDC hdc)
{
	Rectangle(hdc, rectPos[0].x, rectPos[0].y, rectPos[1].x, rectPos[1].y);
}

void cRect::MovePos()
{
	BasicFigure::MovePos();
	POINT _movePos = GetMovePos();
	for (int i = 0; i < 2; i++)
	{
		this->rectPos[i].x += _movePos.x;
		this->rectPos[i].y += _movePos.y;
	}
}

void cRect::Update(RECT rectView)
{
	if (rectPos[0].x <= rectView.left || rectPos[1].x >= rectView.right)
	{
		rectPos[0].x = rectView.top;
		SetMovePosX(-1);
	}
	if (rectPos[0].y <= rectView.top || rectPos[1].y >= rectView.bottom)
	{
		rectPos[0].y = rectView.left;
		SetMovePosY(-1);
	}
}

void cRect::Collision(vector<BasicFigure *> figureList, int count)
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

	calcA = rectPos[0].x + r1;
	calcB = rectPos[0].y + r1;
	for (int i = 0; i < figureList.size(); i++)
	{
		if (count == i)
			continue;

		r2 = figureList[i]->GetRadius();
		checkShape = figureList[i]->GetFigureShape();

		if (checkShape == eCIR)
		{
			cCircle *temp = (cCircle *)figureList[i];
			calcC = temp->GetLeftPosX() + r2;
			calcD = temp->GetTopPosY() + r2;
		}
		if (checkShape == eRECT)
		{
			cRect *temp = (cRect *)figureList[i];
			calcC = temp->rectPos[0].x + r2;
			calcD = temp->rectPos[0].y + r2;
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