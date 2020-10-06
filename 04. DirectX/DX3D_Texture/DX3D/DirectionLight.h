#pragma once
#include "stdafx.h"

class DirectionLight
{
private:
	D3DLIGHT9 m_DirLight;

	float radian;

public:
	DirectionLight();
	~DirectionLight();
	
	void SetUp();
	void Update();
};