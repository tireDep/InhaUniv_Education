#include "stdafx.h"
#include "FigureShape.h"

cStar::cStar()
{
	for (int i = 0; i < 10; i++)
	{
		starPos[i].x = 0;
	}

	SetFigureShape(eSTAR);
};

cStar::cStar(int posx, int posy)
{
	srand((unsigned)time(NULL));

	int rndpos = rand() % 100 + 10;
	//int rndpos = 5;

	POINT temp[5] = { 0 };
	temp[0].x = posx;
	temp[0].y = posy - rndpos;
	AddPoint(posx, posy, temp);

	// 크래머 공식
	double a, b, c, d, e, f;
	int _posX, _posY;

	a = temp[0].y - temp[2].y;
	b = -(temp[0].x - temp[2].x);
	e = a*temp[0].x + b*temp[0].y;

	c = temp[1].y - temp[4].y;
	d = -(temp[1].x - temp[4].x);
	f = c*temp[1].x + d*temp[1].y;

	double divide = (a*d) - (b*c);
	_posX = ((e*d) - (b*f)) / divide;
	_posY = ((a*f) - (e*c)) / divide;
	// 크래머 공식

	POINT temp2[5] = { 0 };
	temp2[0] = { _posX, _posY };
	AddPoint(posx, posy, temp2);

	// 좌표 저장
	int j = 0;
	for (int i = 0; i < 10; i++)
	{
		starPos[i] = temp[j];
		starPos[++i] = temp2[j++];
	}

	SetPosRnd(rndpos);
	SetRadius((double)rndpos / 2);
	SetFigureShape(eSTAR);
};

cStar::~cStar()
{

};

void cStar::AddPoint(int posx, int posy, POINT calcP[])
{
	int degree = 72;
	int addDegree = degree;
	double radian;
	int tempX, tempY;

	for (int i = 1; i < 5; i++)
	{
		radian = degree *(M_PI / 180);
		degree += addDegree;

		tempX = (calcP[0].x - posx)*cos(radian) - (calcP[0].y - posy) * sin(radian) + posx;
		tempY = (calcP[0].x - posx) * sin(radian) + (calcP[0].y - posy) * cos(radian) + posy;

		calcP[i] = { tempX, tempY };
	}
}

void cStar::DrawFigureShape(HDC hdc)
{
	Polygon(hdc, starPos, 10);
}

void cStar::MovePos()
{
	BasicFigure::MovePos();
	POINT _movePos = GetMovePos();
	for (int i = 0; i < 10; i++)
	{
		this->starPos[i].x += _movePos.x;
		this->starPos[i].y += _movePos.y;
	}
}

void cStar::Update(RECT rectView)
{
	int rndpos = GetPosRnd();
	if (starPos[0].x - rndpos <= rectView.left || starPos[2].x - rndpos <= rectView.left || starPos[4].x - rndpos <= rectView.left || starPos[6].x + rndpos + (rndpos / 2) >= rectView.right || starPos[8].x + rndpos + (rndpos / 2) >= rectView.right)
	{
		starPos[0].x -= GetMovePos().x;
		starPos[2].x -= GetMovePos().x;
		starPos[4].x -= GetMovePos().x;
		starPos[6].x -= GetMovePos().x;
		starPos[8].x -= GetMovePos().x;

		starPos[1].x -= GetMovePos().x;
		starPos[3].x -= GetMovePos().x;
		starPos[5].x -= GetMovePos().x;
		starPos[7].x -= GetMovePos().x;
		starPos[9].x -= GetMovePos().x;
		SetMovePosX(-1);
	}

	if (starPos[0].y <= rectView.top || starPos[2].y <= rectView.top || starPos[4].y <= rectView.top || starPos[6].y >= rectView.bottom || starPos[8].y >= rectView.bottom)
	{
		starPos[0].y -= GetMovePos().y;
		starPos[2].y -= GetMovePos().y;
		starPos[4].y -= GetMovePos().y;
		starPos[6].y -= GetMovePos().y;
		starPos[8].y -= GetMovePos().y;

		starPos[1].y -= GetMovePos().y;
		starPos[3].y -= GetMovePos().y;
		starPos[5].y -= GetMovePos().y;
		starPos[7].y -= GetMovePos().y;
		starPos[9].y -= GetMovePos().y;
		SetMovePosY(-1);
	}

	int degree = 72;
	int addDegree = degree;
	double radian = degree * M_PI / 180;
	int _centerX = starPos[0].x;
	int _centerY = starPos[0].y;

	int tempX, tempY;
	for (int i = 0; i < eSTAR * 2; i++)
	{
		tempX = (starPos[i].x - _centerX) * cos(radian) - (starPos[i].y - _centerY) * sin(radian) + _centerX;
		tempY = (starPos[i].x - _centerX) * sin(radian) + (starPos[i].y - _centerY) * cos(radian) + _centerY;

		starPos[i] = { tempX + _centerX, tempY +_centerY};
	}
}

void cStar::Collision(vector<BasicFigure *> figureList, int count)
{
	double r1 = GetRadius();	// 반지름
	double r2;
	double calcA;
	double calcB;
	double calcC;
	double calcD;

	double calcX;
	double calcY;
	double length;
	int checkShape;

	calcA = starPos[0].x + r1;
	calcB = starPos[0].y + r1;
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
			calcC = temp->GetLeftPosX() + r2;
			calcD = temp->GetTopPosY() + r2;
		}
		if (checkShape == eSTAR)
		{
			cStar *temp = (cStar *)figureList[i];
			calcC = temp->starPos[0].x + r2;
			calcD = temp->starPos[0].y + r2;
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