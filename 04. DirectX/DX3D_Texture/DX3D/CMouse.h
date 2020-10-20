#pragma once

#include "cCharacter.h"

struct ST_RAY
{
	D3DXVECTOR3 vRayOrigin;
	D3DXVECTOR3 vRayDir;
};

class CSphere;

class CMouse
{
private:
	POINT m_clickPos;
	ST_RAY m_ray;

	bool m_isLDown;
	bool m_isRDown;

	D3DXVECTOR3 m_vLookAt;
	D3DXVECTOR3 m_destPos;

public:
	// CMouse();
	// ~CMouse();

	Singletone(CMouse);

	void SetUp();
	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	void Update(vector<CSphere *>& mesh, D3DXVECTOR3 setLookAt);
	void CheckClicked(CSphere* mesh, POINT& pos);
	void CheckLBtn(CSphere* mesh, POINT& pos);
	void CheckRBtn(CSphere* mesh, POINT& pos);

	// D3DXVECTOR3 CheckRClicked(D3DXVECTOR3 vPos);
	// typedef void*(funcType)(CMouse mouse);
	// void CheckRClicked(D3DXVECTOR3 pos);
	static D3DXVECTOR3 CallFunc(D3DXVECTOR3 a);
};

