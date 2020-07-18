#include"stdafx.h"
#include"DefenceGame_winAPI.h"
#include"WeaponClass.h"
#include"Function.h"

Gun::Gun()
{
	// barrelPos[4] = { { 245,580 },{ 255,580 },{ 255,650 },{ 245,650 } };

	barrelPos[0].x = 245;
	barrelPos[0].y = 580;

	barrelPos[1].x = 255;
	barrelPos[1].y = 580;

	barrelPos[2].x = 255;
	barrelPos[2].y = 650;

	barrelPos[3].x = 245;
	barrelPos[3].y = 650;

	for (int i = 0; i < 4; i++)
	{
		tempbarrelPos[i].x = barrelPos[i].x;
		tempbarrelPos[i].y = barrelPos[i].y;
	}

	nowDegree = 0;
	addDegree = 15;
}

Gun::~Gun()
{

}

void Gun::CheckBarrelPos(int inputKey)
{
	if(inputKey == 0 && nowDegree > -90)
		nowDegree -= addDegree;
	else if(inputKey == 1 && nowDegree < 90)
		nowDegree += addDegree;
}

void Gun::MoveBarrel(int inputKey)
{
	CheckBarrelPos(inputKey);

	for (int i = 0; i < 4; i++)
	{
		barrelPos[i] = PointRotate(barrelCenter.x, barrelCenter.y, nowDegree, &tempbarrelPos[i]);
	}
}

void Gun::DrawWeapon(HDC hdc)
{
	HPEN hPen, oldPen;
	HBRUSH hBrush, oldBrush;

	SetColor(hdc, hPen, oldPen, 100, 100, 100);
	SetColor(hdc, hBrush, oldBrush, 100, 100, 100);

	Rectangle(hdc, 205, 655, 295, 750);	// 채색용 사각형
	Ellipse(hdc, 205, 615, 295, 690);	// 채색용 원
	Arc(hdc, 205, 615, 295, 690, 360, 660, 180, 660);	// 원호
	
	DeleteColor(hdc, hPen, oldPen);
	DeleteColor(hdc, hBrush, oldBrush);

	SetColor(hdc, hPen, oldPen, 150, 150, 150);
	SetColor(hdc, hBrush, oldBrush, 150, 150, 150);

	Polygon(hdc, barrelPos, 4);	// barrel

	DeleteColor(hdc, hPen, oldPen);
	DeleteColor(hdc, hBrush, oldBrush);
}

POINT Gun::GetBarrelPosLB()
{
	return barrelPos[0];
}

POINT Gun::GetBarrelPosRB()
{
	return barrelPos[1];
}

