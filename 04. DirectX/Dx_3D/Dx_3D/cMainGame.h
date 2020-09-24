#pragma once
#include "stdafx.h"

class cMainGame
{
private:
	vector<stPC_Vertex> m_vecLineVertex;
	vector<stPC_Vertex> m_verTriangleVertex;

	vector<stPC_Vertex> m_vecGridVertex;
	
	vector<stPC_Vertex> m_vecCube;

public:
	cMainGame();
	~cMainGame();

	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	void SetUp();
	void Update();

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

	void SetColor(vector<stPC_Vertex> &vec, int r, int g, int b);
};