#pragma once
#include "stdafx.h"

class cMainGame
{
private:
	HDC memDc;
	HBITMAP hBitmap, hOldBitmap;

	vector<cVector3> vecVertex; // ������ ���� ���� ����
	vector<DWORD> vecIndex;	// �� ������ �ε��� ��ȣ

	cVector3 tempDirection;
	cVector3 moveDirection;

	cMatrix matScale;

	float moveX, moveY, moveZ;
	cMatrix matTrans;

	float rotateX, rotateY, rotateZ;
	cMatrix matRotate;

	cMatrix matRotateX;
	cMatrix matRotateY;
	cMatrix matRotateZ;

	cMatrix matWorld;

	cMatrix matView;
	cMatrix matProj;
	cMatrix matViewPort;

	cVector3 vecEye;
	cVector3 vecLookAt;
	cVector3 vecUp;

	float cameraVal;
	// >> ���콺 ��

	POINT startPos;
	POINT endPos;

	float camX, camY, camZ;
	// >> ���콺 �巡��

public:
	cMainGame();
	~cMainGame();

	void SetUp();	// ������ �ʱ�ȭ
	void Update();
	void Render(HDC hdc);
	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	void SetMoveX(float move);
	void SetMoveY(float move);
	void SetMoveZ(float move);

	void SetRotateXDegree(float degree);
	void SetRotateYDegree(float degree);
	void SetRotateZDegree(float degree);
};