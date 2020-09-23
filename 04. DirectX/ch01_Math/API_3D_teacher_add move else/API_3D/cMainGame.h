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

	// >> 
	vector<cVector3> vecLineVertex;	// �� ���� ���� ���� ����
	cVector3 vecPos;	// �ڽ� ��ġ
	POINT ptPreveMouse;	// ���콺 ��ġ ����
	bool isLButtonDown;	// ���콺 ���� Ȯ��
	
	float fCameraDistance;	// ī�޶� ��ġ
	cVector3 vecCamRotAngle;	// ī�޶� ȸ����
	
	cVector3 vecAxisXTextPos;	// X�� ��ġ
	cVector3 vecAxisZTextPos;	// Z�� ��ġ

	float fBoxRotY;	// y�� ȸ��(�ڽ� ȸ��)

	cVector3 vecBoxDirect;	// �ڽ� �������

	float fScale;
	// <<

public:
	cMainGame();
	~cMainGame();

	void SetUp();	// ������ �ʱ�ȭ
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