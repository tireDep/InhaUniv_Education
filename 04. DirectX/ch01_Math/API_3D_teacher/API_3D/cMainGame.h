#pragma once
#include "stdafx.h"

class cMainGame
{
private:
	HDC memDc;
	HBITMAP hBitmap, hOldBitmap;

	vector<cVector3> vecVertex; // ������ ���� ���� ����
	vector<DWORD> vecIndex;	// �� ������ �ε��� ��ȣ

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

	void SetUp();	// ������ �ʱ�ȭ
	void Update();
	void Render(HDC hdc);
	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

};