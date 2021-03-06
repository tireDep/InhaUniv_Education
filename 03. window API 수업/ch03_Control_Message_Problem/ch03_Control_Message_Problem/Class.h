#pragma once
// Q. 게임 제작
// [기본 상태]
// - 클릭한 위치에 임의도형 생성, 임의의 방향으로 이동
// - 밖으로 벗어나지 x, 끝에 도달하면 반대 방향으로 튕겨나감
// - 충돌 발생
// - 회전 발생
// 
//	+) 위 아래 부딪힘 : y * -1 / 왼 오 부딪힘 : x * -1 
//	+) 할 수 있으면 질량도 계산..
// 
// [합쳐짐]
// - 부딪힐 경우 하나는 없어지고 하나는 커짐
// - 상성 : 별 > 원 > 네모 > 별
// - 같은 도형끼리는 반응 x
// 
// [나눠짐]
// - 다른 도형을 만나면 쪼개짐
// - 상성 : 별 > 원 > 네모 > 별
// - 같은 도형끼리는 반응 x

#include "stdafx.h"

#include<time.h>

#define _USE_MATH_DEFINES
#include<math.h>

class BasicFigure
{
	/*
	[기본클래스_예시]

	<필요 변수>
	필요 정보
	좌표
	크기
	type
	회전(각도)
	이동 스피드
	이동 방향값 x = 1, y = 2	(or 벡터 값)

	<필요 함수>
	Update(); 현재 상태 갱신
	Collision(); 충돌 함수
	Show(HDC hdc);	그려주는 함수

	PlayType();	// 플레이 상태
	*/

private:
	POINT point;
	POINT movePoint;
	POINT centerPos;
	int rndPos;
	double radius;
	int figureShape;

	int angle;

	static int playType;

public:
	BasicFigure() : rndPos(0), radius(0), angle(0), figureShape(0)
	{
		point.x = 0;
		point.y = 0;
		movePoint.x = 0;
		movePoint.y = 0;
	};

	~BasicFigure() { };

	void Update(BasicFigure figure[], RECT viewRect, int cnt);
	void SetPos(int x, int y, RECT viewRect);
	virtual void DrawFigure() { };
	
	void CalcRadius();
	void MovePos(BasicFigure figure[], int cnt);

	double CalcRadian(double degree);
	virtual void Rotation();

	void Collision(BasicFigure circle[], BasicFigure rectangle[], int circleCnt);

	void SetPosX(double pos);
	void SetPosY(double pos);

	int GetPosX();
	int GetPosY();
	int GetPosRnd();
	int GetCenterX();
	int GetCenterY();

	void SetFigureShape(int shape)
	{
		figureShape = shape;
	}
};

class cCircle : public BasicFigure
{
public:
	cCircle() 
	{
		SetFigureShape(0);
	};

	~cCircle() { };

	void DrawFigure(HDC hdc);
	// void DrawCircle(HDC hdc);
};

class cRect : public BasicFigure
{
public:
	cRect() 
	{
		SetFigureShape(4);
	};

	~cRect() { };

	void DrawFigure(HDC hdc);
	void Rotation(double degree);
};

class cStar : public BasicFigure
{
public:
	cStar() 
	{
		SetFigureShape(5);
	};

	~cStar() { };

	void DrawFigure(HDC hdc);
	void AddPoint(int degree, int midX, int midY, POINT point[]);
	// void Rotation();
};