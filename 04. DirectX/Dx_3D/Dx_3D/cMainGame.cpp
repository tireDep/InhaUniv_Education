#include "stdafx.h"
#include "cMainGame.h"

#include "cCubePC.h"
#include "cCamera.h"
#include "cGrid.h"

cMainGame::cMainGame() :
	m_pCubePc(NULL),
	m_pCamera(NULL),
	m_pGrid(NULL)
{

}

cMainGame::~cMainGame()
{
	SafeDelete(m_pCubePc);
	SafeDelete(m_pCamera);
	SafeDelete(m_pGrid);

	g_pDeviceManager->Destroy();
}

void cMainGame::SetUp()
{
	m_pCubePc = new cCubePC;
	m_pCubePc->SetUp();

	m_pCamera = new cCamera;
	m_pCamera->SetUp(&m_pCubePc->GetPosition());

	m_pGrid = new cGrid;
	m_pGrid->SetUp();

	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
	// >> 조명 Off
}

void cMainGame::Update()
{
	if (m_pCubePc)
		m_pCubePc->Update();

	if (m_pCamera)
		m_pCamera->Update();
}

void cMainGame::Render()
{
	RECT rc;
	GetClientRect(g_hWnd, &rc);
	
	g_pD3DDevice->Clear(NULL, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(150, 150, 150), 1.0f, 0);
	// 화면 삭제 및 그리기
	
	g_pD3DDevice->BeginScene(); 

	if (m_pGrid)
		m_pGrid->Render();

	if (m_pCubePc)
		m_pCubePc->Render();
	
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

void cMainGame::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (m_pCamera)
		m_pCamera->WndProc(hWnd, message, wParam, lParam);
}
