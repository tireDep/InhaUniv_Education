#include "stdafx.h"
#include "cMainGame.h"
#include "cDeviceManager.h"
#include "cCamera.h"
#include "cCubePC.h"
#include "cGrid.h"
#include "cCubeMan.h"
#include "DirectionLight.h"
#include "SpotLight.h"
#include "PointLight.h"

#include "cObjLoader.h"
#include "cGroup.h"

#include "cPath.h"
#include "cBezierPath.h"

#include "cSubCubeMan.h"

#include "cTimer.h"

#include "cGeoObject.h"
#include "cCharObjectLoader.h"

#include "cObjMap.h"

cMainGame::cMainGame()
	: m_pCubePC(NULL)
	, m_pCamera(NULL)
	, m_pGrid(NULL)
	, m_pCubeMan(NULL) 
	, m_pTexture(NULL)
	, m_directLight(NULL)
	, m_SpotLight(NULL)
	, m_PointLight(NULL)
	, m_pSubCubeMan(NULL)
	, m_pGeoObject(NULL)
	, m_pMap(NULL)
{

}


cMainGame::~cMainGame()
{
	SafeDelete(m_pCubePC); 
	SafeDelete(m_pCamera); 
	SafeDelete(m_pGrid); 
	SafeDelete(m_pCubeMan); 
	SafeRelease(m_pTexture); 

	SafeDelete(m_directLight);
	SafeDelete(m_SpotLight);
	SafeDelete(m_PointLight);

	for each(auto p in m_vecGroup)
	{
		SafeRelease(p);
	}
	m_vecGroup.clear();
	g_pObjectManger->Destroy();

	g_pDeviceManager->Destroy();

	for each(auto p in m_vecPath)
	{
		SafeDelete(p);
	}
	m_vecPath.clear();

	SafeDelete(m_pSubCubeMan);

	SafeDelete(m_pGeoObject);

	SafeDelete(m_pMap);
}

void cMainGame::Setup()
{
	m_pCubePC = new cCubePC; 
	m_pCubePC->Setup(); 

	m_pCubeMan = new cCubeMan; 
	m_pCubeMan->Setup(); 

	m_pCamera = new cCamera; 
	m_pCamera->Setup(&m_pCubeMan->GetPosition()); 
	// &m_pCubePC->GetPosition());

	m_pGrid = new cGrid; 
	m_pGrid->Setup(); 

	// >> : for texture  
	{
		D3DXCreateTextureFromFile(g_pD3DDevice, L"../image/mkLink.png", &m_pTexture); 
		ST_PT_VERTEX v; 
		v.p = D3DXVECTOR3(0, 0, 0); 
		v.t = D3DXVECTOR2(0, 0.5); 
		m_vecVertex.push_back(v); 

		v.p = D3DXVECTOR3(0, 2, 0);
		v.t = D3DXVECTOR2(0, 0.25);
		m_vecVertex.push_back(v);

		v.p = D3DXVECTOR3(2, 2, 0);
		v.t = D3DXVECTOR2(0.25, 0.25);
		m_vecVertex.push_back(v);
	}

	Set_Light();

	SetUp_Obj();

	cPath *hexaPath = new cPath;
	hexaPath->SetUp(6);
	m_vecPath.push_back(hexaPath);

	cBezierPath *bezierPath = new cBezierPath;
	bezierPath->SetUp(m_vecPath[0]->GetVertex(), 0.5);
	m_vecPath.push_back(bezierPath);

	m_pSubCubeMan = new cSubCubeMan;
	m_pSubCubeMan->Setup();

	dTimer->SetUp();

	cCharObjectLoader loader;
	loader.Load(m_pGeoObject, "woman", "woman_01_all.ASE");
}

void cMainGame::Update()
{
	//if (m_pCubePC)
	//	m_pCubePC->Update(); 

	dTimer->Update();

	if (m_pCubeMan)
		m_pCubeMan->Update(m_pMap); 

	if (m_pCamera)
		m_pCamera->Update(); 

	for (int i = 0; i < m_vecLight.size(); i++)
		m_vecLight[i]->Update();

	if (m_pSubCubeMan)
		m_pSubCubeMan->Update_Path(m_vecPath[1]->GetVertex());
}

void cMainGame::Render()
{
	g_pD3DDevice->Clear(NULL, NULL,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_XRGB(47, 121, 112) , 
		1.0F, 0);

	g_pD3DDevice->BeginScene();

	if (m_pGrid)
		m_pGrid->Render(); 

	// if (m_pCubePC)
	// 	m_pCubePC->Render(); 

	// if (m_pCubeMan)
	//  	m_pCubeMan->Render(); 
	 
	// for (int i = 0; i < m_vecLight.size(); i++)
	// 	m_vecLight[i]->Render();
	 
	// Render_Obj();
	 
	// for (int i = 0; i < m_vecPath.size(); i++)
	// 	m_vecPath[i]->Render();
	 
	// if (m_pSubCubeMan)
	// 	m_pSubCubeMan->Render();
	 
	// Draw_Texture(); 

	m_pGeoObject->Render();

	g_pD3DDevice->EndScene();
	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}

void cMainGame::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (m_pCamera)
		m_pCamera->WndProc(hWnd, message, wParam, lParam); 
}

void cMainGame::Set_Light()
{
	m_directLight = new DirectionLight;
	m_vecLight.push_back(m_directLight);

	m_SpotLight = new SpotLight;
	m_vecLight.push_back(m_SpotLight);

	m_PointLight = new PointLight;
	m_vecLight.push_back(m_PointLight);
}

void cMainGame::Draw_Texture()
{
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false); 

	D3DXMATRIXA16 matWorld; 
	D3DXMatrixIdentity(&matWorld); 
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld); 
	g_pD3DDevice->SetTexture(0, m_pTexture); 
	g_pD3DDevice->SetFVF(ST_PT_VERTEX::FVF); 
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, m_vecVertex.size() / 3, &m_vecVertex[0], sizeof(ST_PT_VERTEX)); 
	g_pD3DDevice->SetTexture(0, NULL); 
}

void cMainGame::SetUp_Obj()
{
	cObjLoader l;
	l.Load(m_vecGroup, "obj", "map.obj");

	m_pCubeMan->SetMap(m_vecGroup[0]->GetVertex());

	Load_Surface();
}

void cMainGame::Render_Obj()
{
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);

	D3DXMATRIXA16 matWorld, matS, matR;
	D3DXMatrixScaling(&matS, 0.01f, 0.01f, 0.01f);
	D3DXMatrixRotationX(&matR, -D3DX_PI / 2.0f);

	matWorld = matS * matR;

	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	
	for each(auto p in m_vecGroup)
	{
		p->Render();
	}

	// todo : 과제!
	//		  맵 로드 & 캐릭터 바닥 체크
	// D3DXIntersectTri()
	/*
	D3DXIntersectTri(v1, v2, v3, rayPos, rayDir, u, v, f);
	// v1, v2, v3 : 폴리곤 정점(바닥 surface)
	// rayPos : 광선 시작점
	// rayDir : 광선 진행 방향
	// (캐릭터 위치, 건물 높이 등, 캐릭터 위치)
	// u, v 지금 당장 필요 x
	// f : 충돌이 있을 때 값
	*/
}

void cMainGame::Load_Surface()
{
	D3DXMATRIXA16 matWorld, matS, matR;
	D3DXMatrixScaling(&matS, 0.01f, 0.01f, 0.01f);
	D3DXMatrixRotationX(&matR, -D3DX_PI / 2.0f);

	matWorld = matS * matR;

	m_pMap = new cObjMap("obj", "map_surface.obj", &matWorld);
}


