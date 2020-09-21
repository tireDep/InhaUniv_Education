#pragma once
#include "stdafx.h"
#include "cVector.h"
#include "cMatrix.h"

class PipeLine
{
private:
	cMatrix worldMatrix;
	cMatrix viewMatrix;
	cMatrix projectMatrix;
	cMatrix viewPortMatrix;

	PipeLine();

public:
	~PipeLine();
	static PipeLine* GetInstance();

	void CalcWorld();
	void CalcVeiw(cVector3 eye, cVector3 lookAt, cVector3 up);
	void CalcProjection(float fFovY, float fAspect, float fNearZ, float fFalZ);
	void CalcViewPort(float x, float y, float w, float h, float minZ, float maxZ);

	cMatrix GetResultMatrix();

	void Rendering(HDC hdc, vector<cVector3> vecSpot);
};