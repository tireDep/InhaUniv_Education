#pragma once
#include "stdafx.h"
#include "UiClass.h"
#include "GameManager.h"

#define ENEMYPOS 2

enum { eEnemyMove = 1, eUpLeft = -1, eDownRight = 1, eFreeze = 0 };
extern GameManager *gameManager;

class Enemy
{
private:
	POINT enemyPos[ENEMYPOS];
	POINT rotatePos[ENEMYPOS];
	POINT rocateCenterPos;

	POINT movePos;

	int nowDegree;
	int addDegree;

public:
	Enemy();
	~Enemy();

	void DrawEnemy(HDC hdc);
	void Update(Player player);

	int ChangeDirection();
	bool IsCanMove();
	void Move();

	void Rotate();
	double CalcDegree();
	void CalcRotateCenter();

	bool Collision(Player player);
	bool CollisionLine(Player player);
};

Enemy::Enemy()
{
	nowDegree = 0;
	addDegree = 15;

	movePos.x = eFreeze;
	movePos.y = eUpLeft;

	enemyPos[0] = { 150,250 };
	enemyPos[1] = { 225,250 };
	//enemyPos[2] = { 255,255 };
	//enemyPos[3] = { 150,255 };

	for (int i = 0; i < ENEMYPOS; i++)
		rotatePos[i] = enemyPos[i];

}

Enemy::~Enemy()
{

}

void Enemy::DrawEnemy(HDC hdc)
{
	Polygon(hdc, enemyPos, ENEMYPOS);
}

void Enemy::Update(Player player)
{
	// 충돌판정 필요
	srand((unsigned)time(NULL));

	if (Collision(player) || CollisionLine(player))
	{
		gameManager->SetSceneNum(eResultScene);
		return;
	}

	if (IsCanMove())
	{
		Move();
	}
	else
	{
		movePos.x = ChangeDirection();
		movePos.y = ChangeDirection();
	}

	Rotate();
}

bool Enemy::IsCanMove()
{
	int nextMoveX = eEnemyMove * movePos.x;
	int nextMoveY = eEnemyMove * movePos.y;
	// 이동방향

	for (int i = 0; i < ENEMYPOS; i++)
	{
		if (enemyPos[i].y + nextMoveY < ePosTop + 35 || enemyPos[i].y + nextMoveY > ePosBottom - 20
			|| enemyPos[i].x + nextMoveX < ePosLeft + 35 || enemyPos[i].x + nextMoveX  > ePosRight - 20)
			return false;
	}
	return true;
}

void Enemy::Move()
{
	// 진행방향
	for (int i = 0; i < ENEMYPOS; i++)
	{
		enemyPos[i].x += eEnemyMove * movePos.x;
		enemyPos[i].y += eEnemyMove * movePos.y;

		rotatePos[i].x += eEnemyMove * movePos.x;
		rotatePos[i].y += eEnemyMove * movePos.y;
	}
}

void Enemy::CalcRotateCenter()
{
	rocateCenterPos.x = (rotatePos[0].x + rotatePos[1].x) / 2;
	rocateCenterPos.y = (rotatePos[0].y + rotatePos[2].y) / 2;
}

double Enemy::CalcDegree()
{
	if (nowDegree < 360)
		nowDegree += addDegree;
	else
		nowDegree = 0;

	return nowDegree * 3.141592 / 180;
}

void Enemy::Rotate()
{
	CalcRotateCenter();

	double tempDegree = CalcDegree();

	for (int i = 0; i < ENEMYPOS; i++)
	{
		double tempX = cos(tempDegree) * (rotatePos[i].x - rocateCenterPos.x) - sin(tempDegree)*(rotatePos[i].y - rocateCenterPos.y);
		double tempY = sin(tempDegree) * (rotatePos[i].x - rocateCenterPos.x) + cos(tempDegree)*(rotatePos[i].y - rocateCenterPos.y);

		enemyPos[i].x = tempX + rocateCenterPos.x;
		enemyPos[i].y = tempY + rocateCenterPos.y;
	}
}

int Enemy::ChangeDirection()
{
	int chanMove = rand() % 3;
	switch (chanMove)
	{
	case 0:
		chanMove = eFreeze;
		break;

	case 1:
		chanMove = eUpLeft;
		break;

	case 2:
		chanMove = eDownRight;
		break;
	}

	return chanMove;
}

bool Enemy::Collision(Player player)
{
	POINT checkPos = player.GetPlayerPos();
	checkPos.x = (checkPos.x + checkPos.x + eDecimal) / 2;
	checkPos.y = (checkPos.y + checkPos.y + eDecimal) / 2;

	if (!player.GetCheckLine())
	{
		for (int i = 0; i < 2; i++)
		{
			if ((checkPos.x >= enemyPos[0].x && checkPos.x <= enemyPos[1].x || checkPos.x <= enemyPos[0].x && checkPos.x >= enemyPos[1].x)
				&& (checkPos.y >= enemyPos[0].y && checkPos.y <= enemyPos[1].y || checkPos.y <= enemyPos[0].y && checkPos.y >= enemyPos[1].y))
				return true;
		}
	}
	return false;

	// double x1, y1, x2, y2;
	// double m;	// 기울기
	// x1 = enemyPos[0].x;
	// y1 = enemyPos[0].y;
	// x2 = enemyPos[1].x;
	// y2 = enemyPos[1].y;
	// 
	// m = (y2 - y1) / (x2 - x1);
	// int b = y1 - (x1 * m); // y절편
	// 
	// double d = abs(checkPos.x * m + checkPos.y * 1 + b) / sqrt((m*m) + (b*b));
	// 
	// if (d < eDecimal / 2)
	// 	return false;
	// 
	// return false;
}

bool Enemy::CollisionLine(Player player)
{
	if (!player.GetCheckLine())
	{
		vector<POINT> checkCollision = player.GetPlayerMapPos();

		for (int i = 0; i < checkCollision.size(); i++)
		{
			if (((enemyPos[0].x >= checkCollision[i].x && enemyPos[1].x <= checkCollision[i].x) && (enemyPos[0].y >= checkCollision[i].y && enemyPos[1].y <= checkCollision[i].y))
				|| ((enemyPos[0].x <= checkCollision[i].x && enemyPos[1].x >= checkCollision[i].x) && (enemyPos[0].y <= checkCollision[i].y && enemyPos[1].y >= checkCollision[i].y)))
				return true;
		}
	}
	return false;
}
