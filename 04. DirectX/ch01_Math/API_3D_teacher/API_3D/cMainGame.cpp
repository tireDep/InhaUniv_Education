#include "stdafx.h"
#include "cMainGame.h"
#include "cVector.h"
#include "cMatrix.h"

#define dMatSize 4

cMainGame::cMainGame() 
	: hBitmap(NULL)
	, vecEye(0,0,-5)
	, vecLookAt(0,0,0)
	, vecUp(0,1,0)
{

}

cMainGame::~cMainGame()
{
	SelectObject(memDc, hOldBitmap);
	DeleteObject(hBitmap);
	DeleteDC(memDc);
}

void cMainGame::SetUp()
{
	HDC hdc = GetDC(g_hWnd);
	memDc = CreateCompatibleDC(hdc);

	RECT rc;
	GetClientRect(g_hWnd, &rc);

	hBitmap = CreateCompatibleBitmap(hdc, rc.right, rc.bottom);
	hOldBitmap = (HBITMAP)SelectObject(memDc, hBitmap);
	ReleaseDC(g_hWnd, hdc);

	vecVertex.push_back(cVector3(-1.0f, -1.0f, -1.0f));
	vecVertex.push_back(cVector3(-1.0f, 1.0f, -1.0f));
	vecVertex.push_back(cVector3(1.0f, 1.0f, -1.0f));
	vecVertex.push_back(cVector3(1.0f, -1.0f, -1.0f));

	vecVertex.push_back(cVector3(-1.0f, -1.0f, 1.0f));
	vecVertex.push_back(cVector3(-1.0f, 1.0f, 1.0f));
	vecVertex.push_back(cVector3(1.0f, 1.0f, 1.0f));
	vecVertex.push_back(cVector3(1.0f, -1.0f, 1.0f));

	// ---------------------------------------------------

	// 바깥 면 바라보는 방향으로 시계방향 진행
	// front
	vecIndex.push_back(0);
	vecIndex.push_back(1);
	vecIndex.push_back(2);

	vecIndex.push_back(0);
	vecIndex.push_back(2);
	vecIndex.push_back(3);

	// back
	vecIndex.push_back(4);
	vecIndex.push_back(6);
	vecIndex.push_back(5);

	vecIndex.push_back(4);
	vecIndex.push_back(7);
	vecIndex.push_back(6);

	// left
	vecIndex.push_back(4);
	vecIndex.push_back(5);
	vecIndex.push_back(1);

	vecIndex.push_back(4);
	vecIndex.push_back(1);
	vecIndex.push_back(0);

	// right
	vecIndex.push_back(3);
	vecIndex.push_back(2);
	vecIndex.push_back(6);

	vecIndex.push_back(3);
	vecIndex.push_back(6);
	vecIndex.push_back(7);

	// up
	vecIndex.push_back(1);
	vecIndex.push_back(5);
	vecIndex.push_back(6);

	vecIndex.push_back(1);
	vecIndex.push_back(6);
	vecIndex.push_back(2);

	// down
	vecIndex.push_back(4);
	vecIndex.push_back(0);
	vecIndex.push_back(3);

	vecIndex.push_back(4);
	vecIndex.push_back(3);
	vecIndex.push_back(7);

	// ---------------------------------------------------

	matWorld = cMatrix::Identity(dMatSize);
	matView = cMatrix::Identity(dMatSize);
	matProj = cMatrix::Identity(dMatSize);
	matViewPort = cMatrix::Identity(dMatSize);
}

void cMainGame::Update()
{
	RECT rc;
	GetClientRect(g_hWnd, &rc);

	vecLookAt = cVector3(0.0f, 0.0f, 0.0f);
	vecEye = cVector3(0.0f, 5.0f, -5.0f);

	matView = cMatrix::View(vecEye, vecLookAt, vecUp);
	matProj = cMatrix::Projection(M_PI / 4.0f, rc.right / (float)rc.bottom, 1.0f, 1000.f);
	matViewPort = cMatrix::ViewPort(0, 0, rc.right, rc.bottom, 0, 1);
}

void cMainGame::Render(HDC hdc)
{
	RECT rc;
	GetClientRect(g_hWnd, &rc);

	PatBlt(memDc, rc.left, rc.top, rc.right, rc.bottom, WHITENESS);

	cMatrix matWVP = matWorld * matView * matProj;

	for (size_t i = 0; i < vecIndex.size(); i += 3)
	{
		cVector3 v1 = vecVertex[vecIndex[i + 0]];
		cVector3 v2 = vecVertex[vecIndex[i + 1]];
		cVector3 v3 = vecVertex[vecIndex[i + 2]];

		v1 = cVector3::TransformCoord(v1, matWVP);
		v2 = cVector3::TransformCoord(v2, matWVP);
		v3 = cVector3::TransformCoord(v3, matWVP);

		v1 = cVector3::TransformCoord(v1, matViewPort);
		v2 = cVector3::TransformCoord(v2, matViewPort);
		v3 = cVector3::TransformCoord(v3, matViewPort);

		MoveToEx(memDc, v1.GetVectorX(), v1.GetVectorY(), NULL);
		LineTo(memDc, v2.GetVectorX(), v2.GetVectorY());
		LineTo(memDc, v3.GetVectorX(), v3.GetVectorY());
		LineTo(memDc, v1.GetVectorX(), v1.GetVectorY());
	}

	BitBlt(hdc, 0, 0, rc.right, rc.bottom, memDc, 0, 0, SRCCOPY);
}

void cMainGame::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_LBUTTONDOWN:
		break;

	case WM_LBUTTONUP:
		break;

	case WM_MOUSEMOVE:
		break;

	case WM_MOUSEWHEEL:
		break;

	default:
		break;
	}
}
