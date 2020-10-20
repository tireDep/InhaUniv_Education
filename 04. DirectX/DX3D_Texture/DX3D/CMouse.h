#pragma once

#include "cCharacter.h"

class CSphere;

class CMouse
{
private:
	POINT m_clickPos;

	bool m_isLDown;
	bool m_isRDown;

	D3DXVECTOR3 m_vLookAt;

	D3DXVECTOR3 m_destPos;
	int m_gridIndex;

public:
	// CMouse();
	// ~CMouse();

	Singletone(CMouse);

	void SetUp();
	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	void Update(vector<CSphere *>& mesh, D3DXVECTOR3 setLookAt, vector<ST_PN_VERTEX> vecCheck);
	void CheckLBtn(CSphere* mesh);
	void CheckRBtn(CSphere* mesh, vector<ST_PN_VERTEX> vecCheck);


	static D3DXVECTOR3 CallFunc();

	static int CallFunc_GridMtrl();
};

