#include "stdafx.h"
#include "cMainGame.h"
#include <time.h>

cMainGame::cMainGame()
{
	srand((unsigned)time(NULL));
}

cMainGame::~cMainGame()
{

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

void cMainGame::SetUp()
{
	// SetUp_Line();
	// SetUp_Triangle();
	SetUp_Grid();
	SetUp_Cube();

	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
	// >> 조명 Off
}

void cMainGame::Update()
{
	Update_Move();
}

void cMainGame::Update_Move()
{
	// if (GetAsyncKeyState(0x57) & 0x8000)
	// 	vecPos = vecPos + (vecBoxDirect * 0.1f);
	//if (GetAsyncKeyState(0x53) & 0x8000)
	//	vecPos = vecPos + (vecBoxDirect * -0.1f);
}

void cMainGame::Render()
{
	RECT rc;
	GetClientRect(g_hWnd, &rc);

	D3DXVECTOR3 vEye = D3DXVECTOR3(5.0f, -5.0f, -5.0f);
	D3DXVECTOR3 vLookAt = D3DXVECTOR3(0, 0, 0);
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
	D3DXMATRIXA16 matWorld;
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
	D3DXMATRIXA16 matWorld;
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
	int nMaxNum = 5;
	for (float i = -nMaxNum; i <= nMaxNum; i += 0.5)
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

		v.p = D3DXVECTOR3(nMaxNum, i, 0);
		m_vecGridVertex.push_back(v);
		v.p = D3DXVECTOR3(-nMaxNum, i, 0);
		m_vecGridVertex.push_back(v);
		// 가로선

		v.p = D3DXVECTOR3(i, nMaxNum, 0);
		m_vecGridVertex.push_back(v);
		v.p = D3DXVECTOR3(i, -nMaxNum, 0);
		m_vecGridVertex.push_back(v);
		// 세로선
	}

	v.c = D3DCOLOR_XRGB(0, 0, 255);
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

	v.c = D3DCOLOR_XRGB(0, 255, 0);
	v.p = D3DXVECTOR3(0, 0, nMaxNum);
	m_vecGridVertex.push_back(v);
	v.p = D3DXVECTOR3(0, 0, -nMaxNum);
	m_vecGridVertex.push_back(v);
	// y축
}

void cMainGame::Draw_Grid()
{
	D3DXMATRIXA16 matWorld;
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
	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);	// 항등 행렬

	g_pD3DDevice->SetFVF(stPC_Vertex::eFVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, m_vecCube.size() / 3, &m_vecCube[0], sizeof(stPC_Vertex));
}

void cMainGame::SetColor(vector<stPC_Vertex>& vec, int r, int g, int b)
{
	for (int i = 0; i<vec.size(); i++)
		vec[i].c = D3DCOLOR_XRGB(r, g, b);
}
