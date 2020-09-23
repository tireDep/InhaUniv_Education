#pragma once
#include "stdafx.h"

class cMainGame
{
private:
	HDC memDc;
	HBITMAP hBitmap, hOldBitmap;

	vector<cVector3> vecVertex; // 각각의 정점 저장 벡터
	vector<DWORD> vecIndex;	// 각 벡터의 인덱스 번호

	cMatrix matWorld;

	cMatrix matView;
	cMatrix matProj;
	cMatrix matViewPort;

	cVector3 vecEye;
	cVector3 vecLookAt;
	cVector3 vecUp;

	// >> 
	vector<cVector3> vecLineVertex;	// 각 선에 대한 정점 정보
	cVector3 vecPos;	// 박스 위치
	POINT ptPreveMouse;	// 마우스 위치 변수
	bool isLButtonDown;	// 마우스 눌림 확인
	
	float fCameraDistance;	// 카메라 위치
	cVector3 vecCamRotAngle;	// 카메라 회전량
	
	cVector3 vecAxisXTextPos;	// X축 위치
	cVector3 vecAxisZTextPos;	// Z축 위치

	float fBoxRotY;	// y축 회전(박스 회전)

	cVector3 vecBoxDirect;	// 박스 전방방향

	float fScale;
	// <<

public:
	cMainGame();
	~cMainGame();

	void SetUp();	// 데이터 초기화
	void Update();
	void Render(HDC hdc);
	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	// >>
	void SetGrid();
	void DrawGrid();

	void Update_Scale();
	void Update_Move();
	void Update_Rotation();

	bool IsBackFace(cVector3 & v1, cVector3 & v2, cVector3 & v3);
	// <<
};