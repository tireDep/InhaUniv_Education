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
	, vecPos(0,0,0)
	, fCameraDistance(5.0f)
	, isLButtonDown(false)
	, vecCamRotAngle(0,0,0)
	, fBoxRotY(0.0f)
	, vecBoxDirect(0,0,1)
{
	ptPreveMouse = { 0,0 };
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

	// >> 
	SetGrid();
	// <<
}

void cMainGame::Update()
{
	// Update_Scale();
	Update_Rotation();	// R
	Update_Move();	// T

	RECT rc;
	GetClientRect(g_hWnd, &rc);

	cMatrix matRX = cMatrix::RotationX(vecCamRotAngle.GetVectorX());
	cMatrix matRY = cMatrix::RotationY(vecCamRotAngle.GetVectorY());
	cMatrix matR = matRX * matRY;
	// >> x, y 마우스 컨트롤

	vecEye = cVector3(0.0f, fCameraDistance, -fCameraDistance);
	// vecEye = cVector3(0.0f, 5.0f, -fCameraDistance);	// 곡선으로 빠짐
	vecEye = cVector3::TransformCoord(vecEye, matR);
	// >> 기본위치 회전
	
	vecLookAt = vecPos;
	vecEye = vecEye + vecPos;
	// >> 따라가게 만듦

	matR = cMatrix::RotationY(fBoxRotY);
	vecBoxDirect = cVector3(0, 0, 1);
	vecBoxDirect = cVector3::TransformNormal(vecBoxDirect,matR);
	// >> 회전 수치

	matWorld = matR * cMatrix::Translation(vecPos); // 회전 * 이동

	matView = cMatrix::View(vecEye, vecLookAt, vecUp);
	matProj = cMatrix::Projection(M_PI_4, rc.right / (float)rc.bottom, 1.0f, 1000.0f);
	matViewPort = cMatrix::ViewPort(0, 0, rc.right, rc.bottom, 0, 1);
}

void cMainGame::Render(HDC hdc)
{
	RECT rc;
	GetClientRect(g_hWnd, &rc);

	PatBlt(memDc, rc.left, rc.top, rc.right, rc.bottom, WHITENESS);

	cMatrix matWVP = matWorld * matView * matProj;

	{
		//// >> grid!
	//// >>
	//vector<cVector3> GridColumn;
	//vector<cVector3> GridRow;
	//vector<cVector3> polygon;
	//vector<cVector3> coord;

	//for (cVector3 poly : polygon)
	//{
	//	MoveToEx(memDc, coord[poly.GetVectorX()].GetVectorX(), coord[poly.GetVectorX()].GetVectorY(), NULL);
	//	LineTo(memDc, coord[poly.GetVectorY()].GetVectorX(), coord[poly.GetVectorY()].GetVectorY());
	//	LineTo(memDc, coord[poly.GetVectorZ()].GetVectorX(), coord[poly.GetVectorZ()].GetVectorY());
	//	LineTo(memDc, coord[poly.GetVectorX()].GetVectorX(), coord[poly.GetVectorX()].GetVectorY());
	//}

	//for (int i = -9; i < 10; i += 2)
	//{
	//	GridColumn.emplace_back(i, 0, 9);
	//	GridColumn.emplace_back(i, 0, -9);
	//}

	//for (int i = -9; i < 10; i += 2)
	//{
	//	GridRow.emplace_back(9, 0, i);
	//	GridRow.emplace_back(-9, 0, i);
	//}

	//for (int i = 0; i < GridColumn.size(); i++)
	//{
	//	GridColumn[i] = cVector3::TransformCoord(GridColumn[i], matWVP);
	//	GridColumn[i] = cVector3::TransformCoord(GridColumn[i], matViewPort);
	//}

	//for (int i = 0; i < GridRow.size(); i++)
	//{
	//	GridRow[i] = cVector3::TransformCoord(GridRow[i], matWVP);
	//	GridRow[i] = cVector3::TransformCoord(GridRow[i], matViewPort);
	//}

	//for (int i = 0; i < 20; i += 2)
	//{
	//	MoveToEx(memDc, GridColumn[i].GetVectorX(), GridColumn[i].GetVectorY(), NULL);
	//	LineTo(memDc, GridColumn[i + 1].GetVectorX(), GridColumn[i + 1].GetVectorY());
	//}
	//for (int i = 0; i < 20; i += 2)
	//{
	//	MoveToEx(memDc, GridRow[i].GetVectorX(), GridRow[i].GetVectorY(), NULL);
	//	LineTo(memDc, GridRow[i + 1].GetVectorX(), GridRow[i + 1].GetVectorY());
	//}
	//// <<
	//// << grid!
	}

	DrawGrid();

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

		// >> backFaceCulling
		cVector3 minusVec1 = v2 - v1;
		cVector3 minusVec2 = v3 - v1;

		cVector3 backFaceCulling = cVector3::Cross(minusVec1, minusVec2);

		vecEye.PrintValue();
		if ((cVector3::GetDegree(vecEye, backFaceCulling) < 90 && vecEye.GetVectorZ() <= 0.0001f)	// z축_음수
			|| (cVector3::GetDegree(vecEye, backFaceCulling) >= 90 && vecEye.GetVectorZ() >= 0.0001f))	// z축_양수
			// >> 1안

			// (backFaceCulling.GetVectorZ() < 0) // 깊이
			// >> 2안
		{
			MoveToEx(memDc, v1.GetVectorX(), v1.GetVectorY(), NULL);
			LineTo(memDc, v2.GetVectorX(), v2.GetVectorY());
			LineTo(memDc, v3.GetVectorX(), v3.GetVectorY());
			LineTo(memDc, v1.GetVectorX(), v1.GetVectorY());
		}
		// << backFaceCulling
	}

	// >> 위치 표시
	cVector3 v = vecVertex[0];
	v = cVector3::TransformCoord(v, matWVP * matViewPort);
	TextOut(memDc, v.GetVectorX(), v.GetVectorY(), (LPCWSTR)"B", 1);

	v = vecVertex[3];
	v = cVector3::TransformCoord(v, matWVP * matViewPort);
	TextOut(memDc, v.GetVectorX(), v.GetVectorY(), (LPCWSTR)"B", 1);

	v = vecVertex[5];
	v = cVector3::TransformCoord(v, matWVP * matViewPort);
	TextOut(memDc, v.GetVectorX(), v.GetVectorY(), (LPCWSTR)"F", 1);

	v = vecVertex[6];
	v = cVector3::TransformCoord(v, matWVP * matViewPort);
	TextOut(memDc, v.GetVectorX(), v.GetVectorY(), (LPCWSTR)"F", 1);
	// << 위치 표시

	BitBlt(hdc, 0, 0, rc.right, rc.bottom, memDc, 0, 0, SRCCOPY);
}

void cMainGame::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_LBUTTONDOWN:
		ptPreveMouse.x = LOWORD(lParam);
		ptPreveMouse.y = HIWORD(lParam);
		
		isLButtonDown = true;
		break;

	case WM_LBUTTONUP:
		isLButtonDown = false;
		break;

	case WM_MOUSEMOVE:
		if (isLButtonDown)
		{
			POINT ptCurMouse;
			ptCurMouse.x = LOWORD(lParam);
			ptCurMouse.y = HIWORD(lParam);

			float fDelatX = (float)ptCurMouse.x - ptPreveMouse.x;
			float fDelatY = (float)ptCurMouse.y - ptPreveMouse.y;

			vecCamRotAngle.SetVectorY(vecCamRotAngle.GetVectorY() + fDelatX / 100.0f);	// 마우스는 x 기준, 축은 y
			vecCamRotAngle.SetVectorX(vecCamRotAngle.GetVectorX() + fDelatY / 100.0f);	// 마우스는 y 기준, 축은 x

			if (vecCamRotAngle.GetVectorX() < -M_PI / 2.0f + 0.0001f)
				vecCamRotAngle.SetVectorX(-M_PI / 2.0f + 0.0001f);

			if (vecCamRotAngle.GetVectorX() > M_PI / 2.0f - 0.0001f)
				vecCamRotAngle.SetVectorX(M_PI / 2.0f - 0.0001f);

			ptPreveMouse = ptCurMouse;

		}
		break;

	case WM_MOUSEWHEEL:
		fCameraDistance -= (GET_WHEEL_DELTA_WPARAM(wParam) / 30.0f);

		if (fCameraDistance < 0.0001f)
			fCameraDistance = 0.0001f;
		break;

	default:
		break;
	}
}

void cMainGame::SetGrid()
{
	int nNumHalfTile = 5;
	float fInterval = 1.0f;
	float fMax = nNumHalfTile * fInterval;
	float fMin = -nNumHalfTile * fInterval;

	for (int i = 1; i <= nNumHalfTile; i++)
	{
		vecLineVertex.push_back(cVector3(fMin, 0, i*fInterval));
		vecLineVertex.push_back(cVector3(fMax, 0, i*fInterval));
		// 가로선

		vecLineVertex.push_back(cVector3(fMin, 0, -i*fInterval));
		vecLineVertex.push_back(cVector3(fMax, 0, -i*fInterval));
		// 세로선

		vecLineVertex.push_back(cVector3(i*fInterval, 0, fMin));
		vecLineVertex.push_back(cVector3(i*fInterval, 0, fMax));
		// z축

		vecLineVertex.push_back(cVector3(-i*fInterval, 0, fMin));
		vecLineVertex.push_back(cVector3(-i*fInterval, 0, fMax));
	}

	vecLineVertex.push_back(cVector3(0, 0, fMin));
	vecLineVertex.push_back(cVector3(0, 0, fMax));

	vecLineVertex.push_back(cVector3(fMin, 0, 0));
	vecLineVertex.push_back(cVector3(fMax, 0, 0));
	// 가운데 선

	vecAxisXTextPos = cVector3(fMax, 0, 0);
	vecAxisZTextPos = cVector3(0, 0, fMax);

}

void cMainGame::DrawGrid()
{
	cMatrix mat = matView * matProj * matViewPort;

	for (size_t i = 0; i < vecLineVertex.size(); i += 2)
	{
		cVector3 v1 = vecLineVertex[i + 0];
		cVector3 v2 = vecLineVertex[i + 1];

		v1 = cVector3::TransformCoord(v1, mat);
		v2 = cVector3::TransformCoord(v2, mat);

		MoveToEx(memDc, v1.GetVectorX(), v1.GetVectorY(), NULL);
		LineTo(memDc, v2.GetVectorX(), v2.GetVectorY());
	}

	cVector3 v = vecAxisXTextPos;
	v = cVector3::TransformCoord(v, mat);
	TextOut(memDc, v.GetVectorX(), v.GetVectorY(), (LPCWSTR)"X", 1);

	v = vecAxisZTextPos;
	v = cVector3::TransformCoord(v, mat);
	TextOut(memDc, v.GetVectorX(), v.GetVectorY(), (LPCWSTR)"Z", 1);
}

void cMainGame::Update_Move()
{
	if (GetAsyncKeyState(0x57) & 0x8000)
		vecPos = vecPos + (vecBoxDirect * 0.1f);
	if (GetAsyncKeyState(0x53) & 0x8000)
		vecPos = vecPos + (vecBoxDirect * -0.1f); // vecPos = vecPos - (vecBoxDirect * 0.1f);	// 같은 건데 이건 안됨..?
}

void cMainGame::Update_Rotation()
{
	if (GetKeyState('A') & 0x8000)// if (GetAsyncKeyState(0x41) & 0x8000)
		fBoxRotY -= 0.1f;
	if (GetKeyState('D') & 0x8000) // if (GetAsyncKeyState(0x44) & 0x8000)
		fBoxRotY += 0.1f;
}
