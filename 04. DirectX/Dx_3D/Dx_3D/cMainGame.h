#pragma once
#include "stdafx.h"

class cMainGame
{
private:
	vector<stPC_Vertex> m_vecLineVertex;
	vector<stPC_Vertex> m_verTriangleVertex;

	vector<stPC_Vertex> m_vecGridVertex;
	
	vector<stPC_Vertex> m_vecCube;

	vector<stPC_Vertex> m_vecZGizmo;

	D3DXVECTOR3 movePos;
	D3DXVECTOR3 cubeDirect;

	float fRotY;

	D3DXMATRIXA16 matWorld;
	D3DXMATRIXA16 matRot;

	float fCamDistance;

	D3DXVECTOR3 camPos;
	POINT startPos;
	bool isLBtnDown;

	D3DXVECTOR3 camAngle;

public:
	cMainGame();
	~cMainGame();

	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	void SetUp();
	void Update();

	void Update_Rotaion();
	void Update_Move();

	void Render();

	void SetUp_Line();
	void Draw_Line();

	void SetUp_Triangle();
	void Draw_Triangle();

	void SetUp_Grid();
	void Draw_Grid();

	void SetUp_Cube();
	void Draw_Cube();

	void SetUp_Gizmo();
	void Draw_Gizmo();

	void SetColor(vector<stPC_Vertex> &vec, int r, int g, int b);
};