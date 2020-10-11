#pragma once
#include "stdafx.h"

class cPath
{
private:
	
protected:
	vector<ST_PC_VERTEX> m_vecVertex;

public:
	cPath();
	~cPath();

	void SetUp(int spot);
	void Render();

	float ShapeDegreeToRadian(int spot);
	vector<ST_PC_VERTEX> GetVertex();
};