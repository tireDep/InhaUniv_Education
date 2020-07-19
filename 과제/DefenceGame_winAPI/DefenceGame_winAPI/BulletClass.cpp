#include "stdafx.h"
#include "DefenceGame_winAPI.h"
#include "WeaponClass.h"
#include "Function.h"

enum { eStartBulletSpped = 25 };

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

Bullet::Bullet(POINT posLB, POINT posRB, POINT move, POINT _centerPos, int _nowDegree)
{
	bulletPos[0] = { 244,569 };
	bulletPos[1] = { 257,569 };
	bulletPos[2] = { 257,582 };
	bulletPos[3] = { 244,582 };
	// circle Bullet

	// bulletPos[0] = { 248,560 };
	// bulletPos[1] = { 253,560 };
	// bulletPos[2] = { 253,582 };
	// bulletPos[3] = { 248,582 };
	// rectangle Bullet

	for (int i = 0; i < 4; i++)
		tempBulletPos[i] = bulletPos[i];
	
	nowDegree = _nowDegree;

	if (nowDegree != 0)
	{
		for (int i = 0; i < 4; i++)
			bulletPos[i] = PointRotate(_centerPos.x, _centerPos.y, _nowDegree, &tempBulletPos[i]);
	}

	centerPos.x = (bulletPos[0].x + bulletPos[2].x) / 2;
	centerPos.y = (bulletPos[0].y + bulletPos[2].y) / 2;
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
}

Bullet::~Bullet()
{

}

void Bullet::DrawWeapon(HDC hdc)
{
	if (nowDegree == 0)
		Ellipse(hdc, bulletPos[0].x, bulletPos[0].y, bulletPos[0].x + 13, bulletPos[0].y + 12);
	else if (nowDegree > 0)
		Ellipse(hdc, bulletPos[0].x, bulletPos[0].y, bulletPos[0].x - 13, bulletPos[0].y + 12);
	else 
		Ellipse(hdc, bulletPos[0].x, bulletPos[0].y, bulletPos[0].x + 13, bulletPos[0].y - 12);

	//Polygon(hdc, bulletPos, 4);	// 일단 네모..
}

void Bullet::Update(vector<Bullet *> &bullet, RECT viewRect)
{
	MoveBullet(bullet);
	CheckBulletOutScreen(bullet, viewRect);
	// CheckHitObstacle();
}

void Bullet::MoveBullet(vector<Bullet *> &bullet)
{
	for (int i = 0; i < bullet.size(); i++)
	{
		for (int j = 0; j < 4; j++)
		{
			bullet[i]->bulletPos[j].x += bullet[i]->movePos.x * bulletSpped;
			bullet[i]->bulletPos[j].y += bullet[i]->movePos.y * bulletSpped;
		}
	}
}

void Bullet::CheckBulletOutScreen(vector<Bullet *> &bullet, RECT viewRect)
{
	for (int i = 0; i < bullet.size(); i++)
	{
		if (viewRect.right <= bulletPos[1].x || viewRect.left >= bulletPos[0].x)
			bullet.erase(bullet.begin() + i);
		if (viewRect.top >= bulletPos[0].y)
			bullet.erase(bullet.begin() + i);
	}
}

