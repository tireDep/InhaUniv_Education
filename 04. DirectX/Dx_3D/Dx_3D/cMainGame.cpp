#include "stdafx.h"
#include "cMainGame.h"
#include <time.h>

cMainGame::cMainGame() :
	movePos(0, 0, 0),
	cubeDirect(0, 0, 1),
	fRotY(0.0f),
	fCamDistance(5.0f),
	camPos(0, 0, 5),
	camAngle(0,0,0),
	fScale(0.5f)
{
	srand((unsigned)time(NULL));

	startPos = { 0,0 };
	D3DXMatrixIdentity(&matWorld);	// 항등 행렬
	D3DXMatrixIdentity(&matRot);
}

cMainGame::~cMainGame()
{

}

void cMainGame::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_LBUTTONDOWN:
		startPos.x = LOWORD(lParam);
		startPos.y = HIWORD(lParam);

		isLBtnDown = true;
		break;

	case WM_LBUTTONUP:
		isLBtnDown = false;
		break;

	case WM_MOUSEMOVE:
		if (isLBtnDown)
		{
			POINT ptCurMouse;
			ptCurMouse.x = LOWORD(lParam);
			ptCurMouse.y = HIWORD(lParam);
		
			float fDelatX = (float)ptCurMouse.x - startPos.x;
			float fDelatY = (float)ptCurMouse.y - startPos.y;

			camAngle.y = camAngle.y + fDelatX / 100.0f;
			camAngle.x = camAngle.x + fDelatY / 100.0f;

			if (camAngle.x < -D3DX_PI / 2.0f + 0.0001f)
				camAngle.x = -D3DX_PI / 2.0f + 0.0001f;

			if (camAngle.x > D3DX_PI / 2.0f - 0.0001f)
				camAngle.x = D3DX_PI / 2.0f - 0.0001f;

			startPos = ptCurMouse;
		}
		break;

	case WM_MOUSEWHEEL:
		fCamDistance -= (GET_WHEEL_DELTA_WPARAM(wParam) / 30.0f);
		
		if (fCamDistance < 0.0001f)
			fCamDistance = 0.0001f;
		break;

	default:
		break;
	}
}

void cMainGame::SetUp()
{
	// SetUp_Line();
	// SetUp_Triangle();
	SetUp_Grid();
	SetUp_Cube();
	SetUp_Gizmo();

	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
	// >> 조명 Off
}

void cMainGame::Update()
{
	Update_Scale();
	Update_Rotaion();
	Update_Move();

	cubeDirect = { 0, 0, 1 };
	D3DXVec3TransformNormal(&cubeDirect, &cubeDirect, &matRot);

	D3DXMatrixIdentity(&matRot);
	D3DXMatrixRotationY(&matRot, fRotY);
}

void cMainGame::Update_Scale()
{
	if (GetKeyState('1') & 0x8000)
		fScale = (fScale + 0.1f) > 10.0f ? fScale : fScale + 0.1f;
	if (GetKeyState('2') & 0x8000)
		fScale = (fScale - 0.1f - 0.0001f) < 0.5f ? 0.5f : fScale - 0.1f;
}

void cMainGame::Update_Rotaion()
{
	if (GetKeyState('A') & 0x8000)
		fRotY -= 0.1f;
	if (GetKeyState('D') & 0x8000)
		fRotY += 0.1f;
}

void cMainGame::Update_Move()
{
	if (GetAsyncKeyState(0x57) & 0x8000)
		movePos = movePos + (cubeDirect * 0.1f);
	if (GetAsyncKeyState(0x53) & 0x8000)
		movePos = movePos - (cubeDirect * 0.1f);
}

void cMainGame::Render()
{
	RECT rc;
	GetClientRect(g_hWnd, &rc);

	D3DXMATRIXA16 matRx;
	D3DXMatrixRotationX(&matRx, camAngle.x);

	D3DXMATRIXA16 matRy;
	D3DXMatrixIdentity(&matRy);
	D3DXMatrixRotationY(&matRy, camAngle.y);

	D3DXVECTOR3 vEye = D3DXVECTOR3(0.0f, fCamDistance, -fCamDistance);
	D3DXVec3TransformCoord(&vEye, &vEye, &(matRx * matRy));

	// D3DXVECTOR3 vLookAt = D3DXVECTOR3(0,0,0);
	D3DXVECTOR3 vLookAt = movePos;
	vEye = vEye + movePos;

	D3DXVECTOR3 vUp = D3DXVECTOR3(0, 1, 0);

	D3DXMATRIXA16 matView;
	D3DXMatrixLookAtLH(&matView, &vEye, &vLookAt, &vUp);
	g_pD3DDevice->SetTransform(D3DTS_VIEW, &matView);

	D3DXMATRIXA16 matProj;
	D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI / 4.0f, rc.right / (float)rc.bottom, 1.0f, 1000.0f);
	g_pD3DDevice->SetTransform(D3DTS_PROJECTION, &matProj);

	g_pD3DDevice->Clear(NULL, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(150, 150, 150), 1.0f, 0);
	// 화면 삭제 및 그리기

	g_pD3DDevice->BeginScene();
	
	// Draw_Line();
	// Draw_Triangle();
	Draw_Grid();
	Draw_Cube();
	Draw_Gizmo();

	g_pD3DDevice->EndScene();

	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}

void cMainGame::SetUp_Line()
{
	stPC_Vertex v;
	v.c = D3DCOLOR_XRGB(255,0,0);
	v.p = D3DXVECTOR3(0, 2, 0);
	m_vecLineVertex.push_back(v);

	v.p = D3DXVECTOR3(0, -2, 0);
	m_vecLineVertex.push_back(v);

}

void cMainGame::Draw_Line()
{
	D3DXMatrixIdentity(&matWorld);	// 항등 행렬

	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetFVF(stPC_Vertex::eFVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_LINELIST, m_vecLineVertex.size() / 2, &m_vecLineVertex[0], sizeof(stPC_Vertex));
	// m_vecLineVertex.size() / 2 : 점 2개니까 선 하나 그림
	// !! 찾아보기 !!
}

void cMainGame::SetUp_Triangle()
{
	stPC_Vertex v;
	// v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);
	v.c = D3DCOLOR_XRGB(255, 255, 255);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, 0.0f);
	m_verTriangleVertex.push_back(v);

	v.p = D3DXVECTOR3(-1.0f, 1.0f, 0.0f);
	m_verTriangleVertex.push_back(v);

	v.p = D3DXVECTOR3(1.0f, 1.0f, 0.0f);
	m_verTriangleVertex.push_back(v);
}

void cMainGame::Draw_Triangle()
{
	D3DXMatrixIdentity(&matWorld);	// 항등 행렬

	D3DXVECTOR3 vPosition = D3DXVECTOR3(0, 0, 5);
	D3DXMatrixTranslation(&matWorld, vPosition.x, vPosition.y, vPosition.z);
	// 삼각형 월드 좌표 이동

	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetFVF(stPC_Vertex::eFVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, m_verTriangleVertex.size() / 3, &m_verTriangleVertex[0], sizeof(stPC_Vertex));
}

void cMainGame::SetUp_Grid()
{
	stPC_Vertex v;

	int cnt = 0;
	float nMaxNum = 7.5;
	float interval = 1.0f;
	for (float i = -nMaxNum; i  <= nMaxNum; i += 0.5)
	{
		if (cnt == 0)
		{
			v.c = D3DCOLOR_XRGB(255, 255, 255);
			cnt = 4;
		}
		else
		{
			v.c = D3DCOLOR_XRGB(200, 200, 200);
			cnt--;
		}

		v.p = D3DXVECTOR3(-nMaxNum * interval, 0, i * interval);
		m_vecGridVertex.push_back(v);
		v.p = D3DXVECTOR3(nMaxNum * interval, 0, i * interval);
		m_vecGridVertex.push_back(v);
		// 가로선

		v.p = D3DXVECTOR3(-nMaxNum * interval, 0, -i * interval);
		m_vecGridVertex.push_back(v);
		v.p = D3DXVECTOR3(nMaxNum * interval, 0, -i * interval);
		m_vecGridVertex.push_back(v);
		// 세로선

		v.p = D3DXVECTOR3(-i * interval, 0, -nMaxNum * interval);
		m_vecGridVertex.push_back(v);
		v.p = D3DXVECTOR3(-i * interval, 0, nMaxNum * interval);
		m_vecGridVertex.push_back(v);
		// 세로선
	}

	v.c = D3DCOLOR_XRGB(0, 255, 0);
	v.p = D3DXVECTOR3(0, nMaxNum, 0);
	m_vecGridVertex.push_back(v);
	v.p = D3DXVECTOR3(0, -nMaxNum, 0);
	m_vecGridVertex.push_back(v);
	// z축

	v.c = D3DCOLOR_XRGB(255, 0, 0);
	v.p = D3DXVECTOR3(nMaxNum, 0, 0);
	m_vecGridVertex.push_back(v);
	v.p = D3DXVECTOR3(-nMaxNum, 0, 0);
	m_vecGridVertex.push_back(v);
	// x축

	v.c = D3DCOLOR_XRGB(0, 0, 255);
	v.p = D3DXVECTOR3(0, 0, nMaxNum);
	m_vecGridVertex.push_back(v);
	v.p = D3DXVECTOR3(0, 0, -nMaxNum);
	m_vecGridVertex.push_back(v);
	// y축
}

void cMainGame::Draw_Grid()
{
	D3DXMatrixIdentity(&matWorld);	// 항등 행렬

	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetFVF(stPC_Vertex::eFVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_LINELIST, m_vecGridVertex.size() / 2, &m_vecGridVertex[0], sizeof(stPC_Vertex));
}

void cMainGame::SetUp_Cube()
{
	stPC_Vertex v;
	vector<stPC_Vertex> index;
	v.p = D3DXVECTOR3(-0.5f, -0.5f, -0.5f);
	index.push_back(v);

	v.p = D3DXVECTOR3(-0.5f, 0.5f, -0.5f);
	index.push_back(v);

	v.p = D3DXVECTOR3(0.5f, 0.5f, -0.5f);
	index.push_back(v);

	v.p = D3DXVECTOR3(0.5f, -0.5f, -0.5f);
	index.push_back(v);

	v.p = D3DXVECTOR3(-0.5f, -0.5f, 0.5f);
	index.push_back(v);

	v.p = D3DXVECTOR3(-0.5f, 0.5f, 0.5f);
	index.push_back(v);

	v.p = D3DXVECTOR3(0.5f, 0.5f, 0.5f);
	index.push_back(v);

	v.p = D3DXVECTOR3(0.5f, -0.5f, 0.5f);
	index.push_back(v);


	// front
	SetColor(index, rand() % 256, rand() % 256, rand() % 256);
	m_vecCube.push_back(index[0]);
	m_vecCube.push_back(index[1]);
	m_vecCube.push_back(index[2]);

	m_vecCube.push_back(index[0]);
	m_vecCube.push_back(index[2]);
	m_vecCube.push_back(index[3]);

	// back
	SetColor(index, rand() % 256, rand() % 256, rand() % 256);
	m_vecCube.push_back(index[4]);
	m_vecCube.push_back(index[6]);
	m_vecCube.push_back(index[5]);

	m_vecCube.push_back(index[4]);
	m_vecCube.push_back(index[7]);
	m_vecCube.push_back(index[6]);

	// left
	SetColor(index, rand() % 256, rand() % 256, rand() % 256);
	m_vecCube.push_back(index[4]);
	m_vecCube.push_back(index[5]);
	m_vecCube.push_back(index[1]);

	m_vecCube.push_back(index[4]);
	m_vecCube.push_back(index[1]);
	m_vecCube.push_back(index[0]);

	// right
	SetColor(index, rand() % 256, rand() % 256, rand() % 256);
	m_vecCube.push_back(index[3]);
	m_vecCube.push_back(index[2]);
	m_vecCube.push_back(index[6]);

	m_vecCube.push_back(index[3]);
	m_vecCube.push_back(index[6]);
	m_vecCube.push_back(index[7]);

	// up
	SetColor(index, rand() % 256, rand() % 256, rand() % 256);
	m_vecCube.push_back(index[1]);
	m_vecCube.push_back(index[5]);
	m_vecCube.push_back(index[6]);

	m_vecCube.push_back(index[1]);
	m_vecCube.push_back(index[6]);
	m_vecCube.push_back(index[2]);

	// down
	SetColor(index, rand() % 256, rand() % 256, rand() % 256);
	m_vecCube.push_back(index[4]);
	m_vecCube.push_back(index[0]);
	m_vecCube.push_back(index[3]);

	m_vecCube.push_back(index[4]);
	m_vecCube.push_back(index[3]);
	m_vecCube.push_back(index[7]);
}

void cMainGame::Draw_Cube()
{	
	D3DXMATRIXA16 tempScale;
	D3DXMatrixIdentity(&tempScale);
	D3DXMatrixScaling(&tempScale, fScale, fScale, fScale);

	D3DXMATRIXA16 tempMove;
	D3DXMatrixIdentity(&tempMove);
	D3DXMatrixTranslation(&tempMove, movePos.x, movePos.y, movePos.z);

	matWorld = tempScale * matRot * tempMove;

	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetFVF(stPC_Vertex::eFVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, m_vecCube.size() / 3, &m_vecCube[0], sizeof(stPC_Vertex));
}

void cMainGame::SetUp_Gizmo()
{
	stPC_Vertex v;
	vector<stPC_Vertex> index;

	{
		// rec1
		v.c = D3DCOLOR_XRGB(255, 0, 0);
		v.p = D3DXVECTOR3(1.0f, 0.1f, -0.1f);
		index.push_back(v);

		v.p = D3DXVECTOR3(1.0f, 0.1f, 0.1f);
		index.push_back(v);

		v.p = D3DXVECTOR3(1.0f, -0.1f, 0.1f);
		index.push_back(v);
		// rec1

		// rec2
		v.p = D3DXVECTOR3(1.0f, -0.1f, -0.1f);
		index.push_back(v);

		v.p = D3DXVECTOR3(1.0f, 0.1f, -0.1f);
		index.push_back(v);

		v.p = D3DXVECTOR3(1.0f, -0.1f, 0.1f);
		index.push_back(v);
		// rec2

		// 1
		v.p = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		index.push_back(v);

		v.p = D3DXVECTOR3(1.0f, 0.1f, -0.1f);
		index.push_back(v);

		v.p = D3DXVECTOR3(1.0f, 0.1f, 0.1f);
		index.push_back(v);
		// 1

		// 2
		v.p = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		index.push_back(v);

		v.p = D3DXVECTOR3(1.0f, -0.1f, -0.1f);
		index.push_back(v);

		v.p = D3DXVECTOR3(1.0f, -0.1f, 0.1f);
		index.push_back(v);
		// 2

		// 3
		v.p = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		index.push_back(v);

		v.p = D3DXVECTOR3(1.0f, 0.1f, -0.1f);
		index.push_back(v);

		v.p = D3DXVECTOR3(1.0f, -0.1f, -0.1f);
		index.push_back(v);
		// 3

		// 4
		v.p = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		index.push_back(v);

		v.p = D3DXVECTOR3(1.0f, 0.1f, 0.1f);
		index.push_back(v);

		v.p = D3DXVECTOR3(1.0f, -0.1f, 0.1f);
		index.push_back(v);
		// 4
	}
	/*
	{
		// rec1
		v.c = D3DCOLOR_XRGB(0, 255, 0);
		v.p = D3DXVECTOR3(1.0f, 0.1f, -0.1f);
		index.push_back(v);

		v.p = D3DXVECTOR3(1.0f, 0.1f, 0.1f);
		index.push_back(v);

		v.p = D3DXVECTOR3(1.0f, -0.1f, 0.1f);
		index.push_back(v);
		// rec1

		// rec2
		v.p = D3DXVECTOR3(1.0f, -0.1f, -0.1f);
		index.push_back(v);

		v.p = D3DXVECTOR3(1.0f, 0.1f, -0.1f);
		index.push_back(v);

		v.p = D3DXVECTOR3(1.0f, -0.1f, 0.1f);
		index.push_back(v);
		// rec2

		// 1
		v.p = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		index.push_back(v);

		v.p = D3DXVECTOR3(1.0f, 0.1f, -0.1f);
		index.push_back(v);

		v.p = D3DXVECTOR3(1.0f, 0.1f, 0.1f);
		index.push_back(v);
		// 1

		// 2
		v.p = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		index.push_back(v);

		v.p = D3DXVECTOR3(1.0f, -0.1f, -0.1f);
		index.push_back(v);

		v.p = D3DXVECTOR3(1.0f, -0.1f, 0.1f);
		index.push_back(v);
		// 2

		// 3
		v.p = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		index.push_back(v);

		v.p = D3DXVECTOR3(1.0f, 0.1f, -0.1f);
		index.push_back(v);

		v.p = D3DXVECTOR3(1.0f, -0.1f, -0.1f);
		index.push_back(v);
		// 3

		// 4
		v.p = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		index.push_back(v);

		v.p = D3DXVECTOR3(1.0f, 0.1f, 0.1f);
		index.push_back(v);

		v.p = D3DXVECTOR3(1.0f, -0.1f, 0.1f);
		index.push_back(v);
		// 4
	}
	*/
	for (int i = 0; i < index.size(); i++)
	{
		m_vecZGizmo.push_back(index[i]);
	}
}

void cMainGame::Draw_Gizmo()
{
	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);	// 항등 행렬

	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetFVF(stPC_Vertex::eFVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, m_vecZGizmo.size() / 3, &m_vecZGizmo[0], sizeof(stPC_Vertex));
}

void cMainGame::SetColor(vector<stPC_Vertex>& vec, int r, int g, int b)
{
	for (int i = 0; i<vec.size(); i++)
		vec[i].c = D3DCOLOR_XRGB(r, g, b);
}
