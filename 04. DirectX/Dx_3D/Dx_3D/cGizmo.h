#pragma once
#include "stdafx.h"

class cGizmo
{
private:
	vector<stPC_Vertex> m_vecVertex;
	D3DXMATRIXA16 m_matR;

public:
	cGizmo();
	~cGizmo();

	void SetUp(D3DCOLOR c, D3DXMATRIXA16& mat);
	void Render();
};