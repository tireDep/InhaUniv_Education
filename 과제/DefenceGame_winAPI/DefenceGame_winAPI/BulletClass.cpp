#include "stdafx.h"
#include "DefenceGame_winAPI.h"
#include "ObstalceClass.h"
#include "WeaponClass.h"
#include "Function.h"

enum { eStartBulletSpped = 25, eBulletDecimal = 7 };

Bullet::Bullet()
{

}

Bullet::Bullet(POINT _BarrelPos0, POINT _BarrelPos1, int degree)
{
	nowDegree = degree + 90;

	int tempX = _BarrelPos0.x - _BarrelPos1.x;
	int tempY = _BarrelPos0.y - _BarrelPos1.y;

	if (tempX == 0)
	{
		if (degree == 90 || degree == -90)
			movePos.y = 0;
		else
			movePos.y = -1;

		if (degree == 0)
			movePos.x = 0;
		else
			movePos.x = -1;

		bulletPos.x = _BarrelPos0.x;
		bulletPos.y = _BarrelPos0.y;
	}
	else if(tempY == -1)
	{
		if (tempX < 0)
			movePos.x = -1;
		else
			movePos.x = 1;
		movePos.y = 0;

		bulletPos.x = _BarrelPos0.x;
		bulletPos.y = _BarrelPos0.y;
	}
	else
	{
		movePos.x = tempX / abs(tempX);
		movePos.y = -1;
		bulletPos.x = _BarrelPos0.x;
		bulletPos.y = _BarrelPos0.y;
	}

	bulletSpped = eStartBulletSpped;
	// 속도

	radius = eBulletDecimal;
	// 반지름
}

Bullet::~Bullet()
{

}


void Bullet::DrawWeapon(HDC hdc)
{
	HPEN hPen, oldPen;
	HBRUSH hBrush, oldBrush;

	SetColor(hdc, hPen, oldPen, 200, 200, 200);
	SetColor(hdc, hBrush, oldBrush, 200, 200, 200);

	Ellipse(hdc, bulletPos.x - eBulletDecimal, bulletPos.y - eBulletDecimal, bulletPos.x + eBulletDecimal, bulletPos.y + eBulletDecimal);

	DeleteColor(hdc, hPen, oldPen);
	DeleteColor(hdc, hBrush, oldBrush);
}

bool CheckPointInCircle(int cx, int cy, int cr, int px, int py)
{
	int deltaX = cx - px;
	int deltaY = cy - py;

	float length = sqrt(deltaX*deltaX + deltaY *deltaY);

	if (length > cr)
		return FALSE;

	return TRUE;
}

void Bullet::Update(vector<Bullet *> &bullet, RECT viewRect)
{
	MoveBullet(bullet);
	CheckBulletOutScreen(bullet, viewRect);
}

void Bullet::MoveBullet(vector<Bullet *> &bullet)
{
	for (int i = 0; i < bullet.size(); i++)
	{
		bullet[i]->bulletPos.x += bullet[i]->movePos.x * bulletSpped * cos(bullet[i]->nowDegree*M_PI / 180);
		bullet[i]->bulletPos.y -= bullet[i]->movePos.y * bulletSpped * -sin(bullet[i]->nowDegree*M_PI / 180);
	}	
}

void Bullet::CheckBulletOutScreen(vector<Bullet *> &bullet, RECT viewRect)
{
	for (int i = 0; i < bullet.size(); i++)
	{
		if (viewRect.right <= bullet[i]->bulletPos.x || viewRect.left >= bullet[i]->bulletPos.x)
			bullet.erase(bullet.begin() + i);
		else if (viewRect.top >= bullet[i]->bulletPos.y)
			bullet.erase(bullet.begin() + i);
	}
}

double Bullet::GetCenterPosX()
{
	return (bulletPos.x - eBulletDecimal + bulletPos.x + eBulletDecimal) / 2;
}

double Bullet::GetCenterPosY()
{
	return (bulletPos.y - eBulletDecimal + bulletPos.y + eBulletDecimal) / 2;
}

int Bullet::GetRadius()
{
	return radius;
}