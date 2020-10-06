#pragma once
#include "stdafx.h"

class SpotLight
{
private:
	D3DLIGHT9 m_SpotLight;

	vector<ST_PC_VERTEX>	m_vecVertex;

	D3DXVECTOR3 m_vRotation;

public:
	SpotLight();
	~SpotLight();

	void SetUp();
	void Update();
	void Render();
};
