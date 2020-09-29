#pragma once
#include "stdafx.h"

class cCubePC;
class cCamera;
class cGrid;

class cCubeMan;
// >> 어딘가에 선언되어 있음

class cMainGame
{
private:
	vector<stPC_Vertex> m_vecLineVertex;
	vector<stPC_Vertex> m_verTriangleVertex;

	// >>
	cCubePC* m_pCubePc;
	cCamera* m_pCamera;
	cGrid* m_pGrid;
	//<<

	cCubeMan* m_pCubeMan;

public:
	cMainGame();
	~cMainGame();

	void SetUp();
	void Update();
	void Render();

	void SetUp_Line();
	void Draw_Line();

	void SetUp_Triangle();
	void Draw_Triangle();

	// >>
	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	// <<

	void Set_Light();
};