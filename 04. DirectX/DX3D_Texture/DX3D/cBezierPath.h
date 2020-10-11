#pragma once
#include "cPath.h"

class cBezierPath : public cPath
{
public:
	cBezierPath();
	~cBezierPath();

	void SetUp(vector<ST_PC_VERTEX>, float maxT);
	void Render();
};