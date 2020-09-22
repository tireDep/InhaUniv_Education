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

	{vecVertex.push_back(cVector3(-1.0f, -1.0f, -1.0f));
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
	}
	matWorld = cMatrix::Identity(dMatSize);
	matView = cMatrix::Identity(dMatSize);
	matProj = cMatrix::Identity(dMatSize);
	matViewPort = cMatrix::Identity(dMatSize);

	matScale = cMatrix::Identity(dMatSize);
	matTrans = cMatrix::Identity(dMatSize);

	matRotate = cMatrix::Identity(dMatSize);
	matRotateX = cMatrix::Identity(dMatSize);
	matRotateY = cMatrix::Identity(dMatSize);
	matRotateZ = cMatrix::Identity(dMatSize);

	moveX = 0;
	moveY = 0;
	moveZ = 0;

	moveDirection = cVector3(0, 0, 1);
	tempDirection = cVector3(0, 0, 1);

	rotateX = 0;
	rotateY = 0;
	rotateZ = 0;

	cameraVal = 5.0;

	startPos = { -1, -1 };
	endPos = { -1, -1 };

	camX = 0;
	camY = 0;
	camZ = 0;
}

void cMainGame::Update()
{
	RECT rc;
	GetClientRect(g_hWnd, &rc);

	vecLookAt = cVector3(0.0f, 0.0f, 0.0f);
	vecEye = cVector3(camX, camY, camZ);

	matRotate = matRotateX * matRotateY * matRotateZ;

	cVector3 movePos(2, 2, 2);
	tempDirection = cVector3::TransformCoord(moveDirection, matRotate);
	movePos.SetVectorX(movePos.GetVectorX() * tempDirection.GetVectorX());// + moveX);
	movePos.SetVectorY(movePos.GetVectorY() * tempDirection.GetVectorY());// + moveY);
	movePos.SetVectorZ(movePos.GetVectorZ() * tempDirection.GetVectorZ());// + moveZ);

	movePos.PrintValue();

	matTrans = cMatrix::Translation(movePos);

	matView = cMatrix::View(vecEye, vecLookAt, vecUp);
	matProj = cMatrix::Projection(M_PI_4, rc.right / (float)rc.bottom, 1.0f, 1000.0f);
	matViewPort = cMatrix::ViewPort(0, 0, rc.right, rc.bottom, 0, 1);
}

void cMainGame::Render(HDC hdc)
{
	RECT rc;
	GetClientRect(g_hWnd, &rc);

	PatBlt(memDc, rc.left, rc.top, rc.right, rc.bottom, WHITENESS);

	matWorld = cMatrix::Identity(dMatSize);
	cMatrix matWVP = matWorld * matView * matProj;

	// >> grid!
	// >>
	vector<cVector3> GridColumn;
	vector<cVector3> GridRow;
	vector<cVector3> polygon;
	vector<cVector3> coord;

	for (cVector3 poly : polygon)
	{
		MoveToEx(memDc, coord[poly.GetVectorX()].GetVectorX(), coord[poly.GetVectorX()].GetVectorY(), NULL);
		LineTo(memDc, coord[poly.GetVectorY()].GetVectorX(), coord[poly.GetVectorY()].GetVectorY());
		LineTo(memDc, coord[poly.GetVectorZ()].GetVectorX(), coord[poly.GetVectorZ()].GetVectorY());
		LineTo(memDc, coord[poly.GetVectorX()].GetVectorX(), coord[poly.GetVectorX()].GetVectorY());
	}

	for (int i = -9; i < 10; i += 2)
	{
		GridColumn.emplace_back(i, 0, 9);
		GridColumn.emplace_back(i, 0, -9);
	}

	for (int i = -9; i < 10; i += 2)
	{
		GridRow.emplace_back(9, 0, i);
		GridRow.emplace_back(-9, 0, i);
	}

	for (int i = 0; i < GridColumn.size(); i++)
	{
		GridColumn[i] = cVector3::TransformCoord(GridColumn[i], matWVP);
		GridColumn[i] = cVector3::TransformCoord(GridColumn[i], matViewPort);
	}

	for (int i = 0; i < GridRow.size(); i++)
	{
		GridRow[i] = cVector3::TransformCoord(GridRow[i], matWVP);
		GridRow[i] = cVector3::TransformCoord(GridRow[i], matViewPort);
	}

	for (int i = 0; i < 20; i += 2)
	{
		MoveToEx(memDc, GridColumn[i].GetVectorX(), GridColumn[i].GetVectorY(), NULL);
		LineTo(memDc, GridColumn[i + 1].GetVectorX(), GridColumn[i + 1].GetVectorY());
	}
	for (int i = 0; i < 20; i += 2)
	{
		MoveToEx(memDc, GridRow[i].GetVectorX(), GridRow[i].GetVectorY(), NULL);
		LineTo(memDc, GridRow[i + 1].GetVectorX(), GridRow[i + 1].GetVectorY());
	}
	// <<
	// << grid!

	matWorld = matScale * matRotate * matTrans;
	matWVP = matWorld * matView * matProj;

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
		startPos.x = LOWORD(lParam);
		startPos.y = HIWORD(lParam);
		break;

	case WM_LBUTTONUP:
		startPos.x = -1;
		startPos.y = -1;

		endPos.x = -1;
		endPos.y = -1;
		break;

	case WM_MOUSEMOVE:
		if (startPos.x != -1 && startPos.y != -1)
		{
			endPos.x = LOWORD(lParam);
			endPos.y = HIWORD(lParam);

			if (startPos.x - endPos.x < 0)
				camX -= 0.1f;// camX = abs(camX - 0.1f) < 0.0001f ? 0 : camX - 0.1f; // camX -= 0.1f;// 
			else if (startPos.x - endPos.x > 0)
				camX += 0.1f;// camX = camX + 1 > 360 ? 0 : camX + 1;

			if (startPos.y - endPos.y < 0)
				camY += 0.1f; // camY = camY + 2 > 360 ? 0 : camY + 2;
			else if (startPos.y - endPos.y > 0)
				camY -= 0.1f;// camY = abs(camY - 0.1f) < 0.00001f < 0 ? 0 : camY - 0.1f;

			if (startPos.x - endPos.x < 0 && startPos.y - endPos.y < 0)
				camZ -= 0.1f;
			else if (startPos.x - endPos.x < 0 && startPos.y - endPos.y < 0)
				camZ += 0.1f;

			// startPos = endPos;
		}

		break;

	case WM_MOUSEWHEEL:
		// 화면 +-
		if (GET_WHEEL_DELTA_WPARAM(wParam) > 0)
			camY += 5;
		else
			camY = camY - 5 < 0 ? 0 : camY - 5;
		break;

	default:
		break;
	}
}

void cMainGame::SetMoveX(float move)
{
	moveX += move;
}

void cMainGame::SetMoveY(float move)
{
	moveY += move;
}

void cMainGame::SetMoveZ(float move)
{
	moveZ += move;
}

void cMainGame::SetRotateXDegree(float degree)
{
	rotateX = degree * (M_PI / 180);
	matRotateX = cMatrix::RotationX(rotateX);
}

void cMainGame::SetRotateYDegree(float degree)
{
	rotateY = degree * (M_PI / 180);
	matRotateY = cMatrix::RotationY(rotateY);
}

void cMainGame::SetRotateZDegree(float degree)
{
	rotateZ = degree * (M_PI / 180);
	matRotateZ = cMatrix::RotationZ(rotateZ);
}
