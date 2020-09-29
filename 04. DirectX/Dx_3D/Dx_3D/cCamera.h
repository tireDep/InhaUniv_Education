#pragma once
#include "stdafx.h"

class cCamera
{
private:
	D3DXVECTOR3 m_vEye;
	D3DXVECTOR3	m_vLookAt;
	D3DXVECTOR3 m_vUp;
	D3DXVECTOR3* m_pvTarget;

	POINT m_ptPrevMouse;
	bool m_isLBtnDown;
	float m_fCameraDistance;
	D3DXVECTOR3 m_vCamRotAngle;

public:
	cCamera();
	~cCamera();

	void SetUp(D3DXVECTOR3* pvTarget);
	void Update();

	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	// 마우스 처리

	// 카메라라 랜더 필요 x
};
