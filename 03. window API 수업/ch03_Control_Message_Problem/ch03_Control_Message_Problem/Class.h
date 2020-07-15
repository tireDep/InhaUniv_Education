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
	POINT movePoint;
	int rndPos;

	int length;
	int angle;
	int speed;
	
	static int playType;

public:
	BasicFigure() : rndPos(0), length(0), angle(0), speed(0)
	{
		point.x = 0;
		point.y = 0;
		movePoint.x = 0;
		movePoint.y = 0;
	};

	~BasicFigure() { };

	void Update() { };
	void SetPos(int x, int y, RECT viewRect);
	virtual void DrawFigure() { };
	
	void MovePos(BasicFigure figure[], int cnt);

	int GetPosX();
	int GetPosY();
	int GetPosRnd();
};

class cCircle : public BasicFigure
{
public:
	cCircle() { };
	~cCircle() { };

	void DrawFigure(HDC hdc);
	// void DrawCircle(HDC hdc);
};

class cRect : public BasicFigure
{
public:
	cRect() { };
	~cRect() { };

	void DrawFigure(HDC hdc);
};

// class cStar : public BasicFigure
// {
// 
// };