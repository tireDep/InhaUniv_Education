#include "stdafx.h"
#include "DefenceGame_winAPI.h"
#include "ObstalceClass.h"
#include "WeaponClass.h"
#include "Function.h"

enum { eStartBulletSpped = 25, eBulletDecimal = 13 };

Bullet::Bullet()
{
	for (int i = 0; i < 4; i++)
	{
		tempBulletPos[i] = { 0,0 };
		bulletPos[i] = { 0,0 };
	}

	centerPos.x = 0;
	centerPos.y = 0;
	nowDegree = 0;
}

Bullet::Bullet(POINT _centerPos, int _nowDegree)
{
	bulletPos[0] = { 244,569 };
	bulletPos[1] = { 257,569 };
	bulletPos[2] = { 257,582 };
	bulletPos[3] = { 244,582 };

	for (int i = 0; i < 4; i++)
		tempBulletPos[i] = bulletPos[i];

	nowDegree = _nowDegree;

	if (nowDegree != 0)
	{
		for (int i = 0; i < 4; i++)
			bulletPos[i] = PointRotate(_centerPos.x, _centerPos.y, _nowDegree, &tempBulletPos[i]);
	}

	centerPos.x = (bulletPos[0].x + bulletPos[1].x) / 2;
	centerPos.y = (bulletPos[0].y + bulletPos[1].y) / 2;
	// 총알 중점

	if (nowDegree == 90 || nowDegree == -90)
		movePos.y = 0;
	else
		movePos.y = -1;

	if (nowDegree == 0)
		movePos.x = 0;
	else if (nowDegree > 0)
		movePos.x = 1;
	else
		movePos.x = -1;
	// 방향

	bulletSpped = eStartBulletSpped;
	// 속도

	radius = (bulletPos[1].x - bulletPos[0].x) / 2;
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

	if (nowDegree == 0)
		Ellipse(hdc, bulletPos[0].x, bulletPos[0].y, bulletPos[0].x + eBulletDecimal, bulletPos[0].y + eBulletDecimal - 1);
	else if (nowDegree > 0)
		Ellipse(hdc, bulletPos[0].x, bulletPos[0].y, bulletPos[0].x - eBulletDecimal, bulletPos[0].y + eBulletDecimal - 1);
	else
		Ellipse(hdc, bulletPos[0].x, bulletPos[0].y, bulletPos[0].x + eBulletDecimal, bulletPos[0].y - eBulletDecimal - 1);

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
		for (int j = 0; j < 4; j++)
		{
			bullet[i]->bulletPos[j].x += bullet[i]->movePos.x * bulletSpped;
			bullet[i]->bulletPos[j].y += bullet[i]->movePos.y * bulletSpped;

			bullet[i]->centerPos.x += bullet[i]->movePos.x * bulletSpped;
			bullet[i]->centerPos.y += bullet[i]->movePos.y * bulletSpped;
		}
	}
}

void Bullet::CheckBulletOutScreen(vector<Bullet *> &bullet, RECT viewRect)
{
	for (int i = 0; i < bullet.size(); i++)
	{
		if (viewRect.right <= bullet[i]->bulletPos[1].x || viewRect.left >= bullet[i]->bulletPos[0].x)
			bullet.erase(bullet.begin() + i);
		else if (viewRect.top >= bullet[i]->bulletPos[3].y)
			bullet.erase(bullet.begin() + i);
	}
}


double Bullet::GetCenterPosX()
{
	return (bulletPos[0].x + bulletPos[1].x) / 2;
}

double Bullet::GetCenterPosY()
{
	return (bulletPos[1].y + bulletPos[2].y) / 2;
}

int Bullet::GetRadius()
{
	return radius;
}