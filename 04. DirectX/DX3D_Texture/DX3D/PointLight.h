#pragma once
#include "stdafx.h"

class PointLight
{
private:
	D3DLIGHT9 m_PointLight;

	vector<ST_PC_VERTEX>	m_vecVertex;

public:
	PointLight();
	~PointLight();

	void SetUp();

	void Render();
};