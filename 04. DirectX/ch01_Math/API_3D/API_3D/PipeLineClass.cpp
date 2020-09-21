#include "stdafx.h"
#include "PipeLineClass.h"

#define dMatSize 4 

PipeLine::PipeLine()
{
	worldMatrix = cMatrix::Identity(dMatSize);
	viewMatrix = cMatrix::Identity(dMatSize);
	projectMatrix = cMatrix::Identity(dMatSize);
	viewPortMatrix = cMatrix::Identity(dMatSize);
	// >> 단위 행렬 초기화
}

PipeLine::~PipeLine()
{

}

PipeLine * PipeLine::GetInstance()
{
	static PipeLine pipeLine;
	return &pipeLine;
}

void PipeLine::CalcWorld()
{
	worldMatrix = cMatrix::Identity(dMatSize);
	// todo : 작업 추가
	// s * r * t
}

void PipeLine::CalcVeiw(cVector3 eye, cVector3 lookAt, cVector3 up)
{
	viewMatrix = cMatrix::View(eye, lookAt, up);
}

void PipeLine::CalcProjection(float fFovY, float fAspect, float fNearZ, float fFalZ)
{
	projectMatrix = cMatrix::Projection(90 * (3.14 / 180), fAspect, 1, 1000);
}

void PipeLine::CalcViewPort(float x, float y, float w, float h, float minZ, float maxZ)
{
	viewPortMatrix = cMatrix::ViewPort(0, 0, w, h, 0, 1);
}

cMatrix PipeLine::GetResultMatrix()
{
	return worldMatrix * viewMatrix * projectMatrix * viewPortMatrix;
	// >> 순서가 변경되면 x
}

void PipeLine::Rendering(HDC hdc, vector<cVector3> vecSpot)
{
	// for (int i = 0; i < vecSpot.size(); i+=4)
	// {
	// 	MoveToEx(hdc, vecSpot[i].GetVectorX(), vecSpot[i].GetVectorY(), NULL);
	// 	LineTo(hdc, vecSpot[i + 1].GetVectorX(), vecSpot[i + 1].GetVectorY());
	// 	LineTo(hdc, vecSpot[i + 2].GetVectorX(), vecSpot[i + 2].GetVectorY());
	// 	LineTo(hdc, vecSpot[i].GetVectorX(), vecSpot[i].GetVectorY());
	// 
	// 	LineTo(hdc, vecSpot[i + 3].GetVectorX(), vecSpot[i + 3].GetVectorY());
	// 	LineTo(hdc, vecSpot[i + 2].GetVectorX(), vecSpot[i + 2].GetVectorY());
	// 	LineTo(hdc, vecSpot[i].GetVectorX(), vecSpot[i].GetVectorY());
	// }

	// int addNum = 0;
	// for (int i = 0; i < 4; i++)
	// {
	// 	MoveToEx(hdc, vecSpot[i].GetVectorX(), vecSpot[i].GetVectorY(), NULL);
	// 	addNum = i + 3 < vecSpot.size() ? i + 3 : i + 3 - vecSpot.size();
	// 	LineTo(hdc, vecSpot[addNum].GetVectorX(), vecSpot[addNum].GetVectorY());
	// 	LineTo(hdc, vecSpot[addNum - 1].GetVectorX(), vecSpot[addNum - 1].GetVectorY());
	// 	LineTo(hdc, vecSpot[i].GetVectorX(), vecSpot[i].GetVectorY());
	// 
	// 	addNum = i + 1 < vecSpot.size() ? i + 1 : i + 1 - vecSpot.size();
	// 	LineTo(hdc, vecSpot[addNum].GetVectorX(), vecSpot[addNum].GetVectorY());
	// 	LineTo(hdc, vecSpot[addNum + 1].GetVectorX(), vecSpot[addNum + 1].GetVectorY());
	// 	LineTo(hdc, vecSpot[i].GetVectorX(), vecSpot[i].GetVectorY());
	// }

	MoveToEx(hdc, vecSpot[0].GetVectorX(), vecSpot[0].GetVectorY(), NULL);
	LineTo(hdc, vecSpot[1].GetVectorX(), vecSpot[1].GetVectorY());
	LineTo(hdc, vecSpot[2].GetVectorX(), vecSpot[2].GetVectorY());
	LineTo(hdc, vecSpot[0].GetVectorX(), vecSpot[0].GetVectorY());

	LineTo(hdc, vecSpot[3].GetVectorX(), vecSpot[3].GetVectorY());
	LineTo(hdc, vecSpot[2].GetVectorX(), vecSpot[2].GetVectorY());
	LineTo(hdc, vecSpot[0].GetVectorX(), vecSpot[0].GetVectorY());

	// -------------------------------------------------------------------------

	MoveToEx(hdc, vecSpot[4].GetVectorX(), vecSpot[4].GetVectorY(), NULL);
	LineTo(hdc, vecSpot[5].GetVectorX(), vecSpot[5].GetVectorY());
	LineTo(hdc, vecSpot[6].GetVectorX(), vecSpot[6].GetVectorY());
	LineTo(hdc, vecSpot[4].GetVectorX(), vecSpot[4].GetVectorY());

	LineTo(hdc, vecSpot[7].GetVectorX(), vecSpot[7].GetVectorY());
	LineTo(hdc, vecSpot[6].GetVectorX(), vecSpot[6].GetVectorY());
	LineTo(hdc, vecSpot[4].GetVectorX(), vecSpot[4].GetVectorY());

	// -------------------------------------------------------------------------

	MoveToEx(hdc, vecSpot[5].GetVectorX(), vecSpot[5].GetVectorY(), NULL);
	LineTo(hdc, vecSpot[6].GetVectorX(), vecSpot[6].GetVectorY());
	LineTo(hdc, vecSpot[2].GetVectorX(), vecSpot[2].GetVectorY());
	LineTo(hdc, vecSpot[5].GetVectorX(), vecSpot[5].GetVectorY());

	LineTo(hdc, vecSpot[1].GetVectorX(), vecSpot[1].GetVectorY());
	LineTo(hdc, vecSpot[2].GetVectorX(), vecSpot[2].GetVectorY());
	LineTo(hdc, vecSpot[5].GetVectorX(), vecSpot[5].GetVectorY());

	// -------------------------------------------------------------------------

	MoveToEx(hdc, vecSpot[4].GetVectorX(), vecSpot[4].GetVectorY(), NULL);
	LineTo(hdc, vecSpot[7].GetVectorX(), vecSpot[7].GetVectorY());
	LineTo(hdc, vecSpot[3].GetVectorX(), vecSpot[3].GetVectorY());
	LineTo(hdc, vecSpot[4].GetVectorX(), vecSpot[4].GetVectorY());

	LineTo(hdc, vecSpot[0].GetVectorX(), vecSpot[0].GetVectorY());
	LineTo(hdc, vecSpot[3].GetVectorX(), vecSpot[3].GetVectorY());
	LineTo(hdc, vecSpot[4].GetVectorX(), vecSpot[4].GetVectorY());

	// -------------------------------------------------------------------------

	MoveToEx(hdc, vecSpot[6].GetVectorX(), vecSpot[6].GetVectorY(), NULL);
	LineTo(hdc, vecSpot[7].GetVectorX(), vecSpot[7].GetVectorY());
	LineTo(hdc, vecSpot[3].GetVectorX(), vecSpot[3].GetVectorY());
	LineTo(hdc, vecSpot[6].GetVectorX(), vecSpot[6].GetVectorY());

	LineTo(hdc, vecSpot[2].GetVectorX(), vecSpot[2].GetVectorY());
	LineTo(hdc, vecSpot[3].GetVectorX(), vecSpot[3].GetVectorY());
	LineTo(hdc, vecSpot[6].GetVectorX(), vecSpot[6].GetVectorY());

	// -------------------------------------------------------------------------

	MoveToEx(hdc, vecSpot[4].GetVectorX(), vecSpot[4].GetVectorY(), NULL);
	LineTo(hdc, vecSpot[5].GetVectorX(), vecSpot[5].GetVectorY());
	LineTo(hdc, vecSpot[1].GetVectorX(), vecSpot[1].GetVectorY());
	LineTo(hdc, vecSpot[4].GetVectorX(), vecSpot[4].GetVectorY());

	LineTo(hdc, vecSpot[0].GetVectorX(), vecSpot[0].GetVectorY());
	LineTo(hdc, vecSpot[1].GetVectorX(), vecSpot[1].GetVectorY());
	LineTo(hdc, vecSpot[4].GetVectorX(), vecSpot[4].GetVectorY());



}
