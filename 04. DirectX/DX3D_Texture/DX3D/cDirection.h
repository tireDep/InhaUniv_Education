#pragma once
#include "stdafx.h"

class cDirection
{
private:
	vector<ST_PC_VERTEX> m_vecVertex;

public:
	cDirection();
	~cDirection();

	void SetUp(cDirection set);
	void SetUpHexa();
	void Render();
};