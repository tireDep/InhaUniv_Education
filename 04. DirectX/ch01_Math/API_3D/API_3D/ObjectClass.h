#pragma once
#include "stdafx.h"
#include "cVector.h"

class Object
{
private:
	vector<cVector3> vecSpot;
	vector<cVector3> renderSpot;

	Object();

public:
	~Object();

	static Object* GetInstance();

	void ObjTransFromCoord(cMatrix matrix);

	vector<cVector3> GetRenderSpot();
};