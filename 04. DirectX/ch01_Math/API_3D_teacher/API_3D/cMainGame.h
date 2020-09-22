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

public:
	cMainGame();
	~cMainGame();

	void SetUp();	// 데이터 초기화
	void Update();
	void Render(HDC hdc);
	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

};