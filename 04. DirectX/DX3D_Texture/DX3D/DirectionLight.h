#pragma once
#include "stdafx.h"
#include "cLight.h"

class DirectionLight : public cLight
{
private:
	D3DLIGHT9 m_DirLight;

public:
	DirectionLight();
	~DirectionLight();
	
	void SetUp();
	void Update();
	void Render();
};