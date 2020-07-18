#include "stdafx.h"
#include "WeaponClass.h"

Bullet::Bullet()
{
	for (int i = 0; i < 2; i++)
	{
		bulletPos[i].x = 0;
		bulletPos[i].y = 0;
	}
	movePos.x = 0;
	movePos.y = 0;
}

Bullet::Bullet(POINT posLB, POINT posRB, POINT move)
{
	//posLB.x -= 1;
	//posLB.y -= 1;
	//posRB.x += 2;
	//posRB.x += 2;
	// ��¦ ū �Ѿ�

	// Ellipse(hdc, 245, 570, 255, 580);	// �� �´� �Ѿ�
	//Ellipse(hdc, 244, 569, 257, 582);	// ��¦ ū �Ѿ�

	bulletPos[0].x = posLB.x - 1;
	bulletPos[0].y = posLB.y - 10;

	bulletPos[1].x = posRB.x + 2;
	bulletPos[1].y = posRB.y + 2;
	// todo : �Ѿ�ũ�� ���� �ʿ�!

	movePos.x = move.x;
	movePos.y = move.y;
}

Bullet::~Bullet()
{

}

void Bullet::DrawWeapon(HDC hdc)
{
	Ellipse(hdc,bulletPos[0].x, bulletPos[0].y, bulletPos[1].x, bulletPos[1].y);
}