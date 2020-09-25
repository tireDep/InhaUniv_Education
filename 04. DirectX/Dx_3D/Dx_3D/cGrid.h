#pragma once
#include "stdafx.h"

class cGizmo;

class cGrid
{
private:
	vector<stPC_Vertex> m_vecVertex;
	vector<cGizmo *> m_vecGizmo;

public:
	cGrid();
	~cGrid();

	void SetUp(int nNumHalfTile = 15, float fInterval = 1.0f);
	void Render();
};