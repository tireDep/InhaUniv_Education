#pragma once
// Q. ���� ����
// [�⺻ ����]
// - Ŭ���� ��ġ�� ���ǵ��� ����, ������ �������� �̵�
// - ������ ����� x, ���� �����ϸ� �ݴ� �������� ƨ�ܳ���
// - �浹 �߻�
// - ȸ�� �߻�
// 
//	+) �� �Ʒ� �ε��� : y * -1 / �� �� �ε��� : x * -1 
//	+) �� �� ������ ������ ���..
// 
// [������]
// - �ε��� ��� �ϳ��� �������� �ϳ��� Ŀ��
// - �� : �� > �� > �׸� > ��
// - ���� ���������� ���� x
// 
// [������]
// - �ٸ� ������ ������ �ɰ���
// - �� : �� > �� > �׸� > ��
// - ���� ���������� ���� x

#include "stdafx.h"

#include<time.h>

class BasicFigure
{
	/*
	[�⺻Ŭ����_����]

	<�ʿ� ����>
	�ʿ� ����
	��ǥ
	ũ��
	type
	ȸ��(����)
	�̵� ���ǵ�
	�̵� ���Ⱚ x = 1, y = 2	(or ���� ��)

	<�ʿ� �Լ�>
	Update(); ���� ���� ����
	Collision(); �浹 �Լ�
	Show(HDC hdc);	�׷��ִ� �Լ�

	PlayType();	// �÷��� ����
	*/

private:
	POINT point;
	int rndPos;

	int size;
	int angle;
	int speed;
	int moveX;
	int moveY;
	int playType;

public:
	BasicFigure() : rndPos(0), size(0), angle(0), speed(0), moveX(0), moveY(0), playType(0) 
	{
		point.x = 0;
		point.y = 0;
	};

	~BasicFigure() { };

	void Update() { };
	void SetPos(int x, int y, RECT viewRect);
	
	int GetPosX();
	int GetPosY();
	int GetPosRnd();
};

class cCircle : public BasicFigure
{
private:


public:
	cCircle() { };
	~cCircle() { };

	// void SetPos(int x, int y, RECT viewRect);
	void DrawCircle(HDC hdc);
};

// class cRect : public BasicFigure
// {
// 
// };
// 
// class cStar : public BasicFigure
// {
// 
// };