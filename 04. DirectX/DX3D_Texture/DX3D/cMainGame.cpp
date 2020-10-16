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

#include "cObjMap.h"

#include "cFrame.h"
#include "cAseLoader.h"

cMainGame::cMainGame()
	: m_pCubePC(NULL)
	, m_pCamera(NULL)
	, m_pGrid(NULL)
	, m_pCubeMan(NULL) 
	, m_pTexture(NULL)
	, m_directLight(NULL)
	, m_SpotLight(NULL)
	, m_PointLight(NULL)
	, m_pMap(NULL)
	, m_pRootFrame(NULL)
	, m_pMeshTeaPot(NULL)
	, m_pMeshSphere(NULL)
	, m_pObjMesh(NULL)
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

	SafeDelete(m_pMap);

	for each(auto p in m_vecGroup)
	{
		SafeRelease(p);
	}
	m_vecGroup.clear();

	m_pRootFrame->Destroy();

	// >> mesh
	SafeRelease(m_pMeshTeaPot);
	SafeRelease(m_pMeshSphere);
	SafeRelease(m_pObjMesh);
	for each(auto p in m_vecObjMtlTex)
	{
		SafeRelease(p);
	}
	m_vecObjMtlTex.clear();
	// << mesh

	g_pObjectManger->Destroy();

	g_pDeviceManager->Destroy();
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

	cAseLoader aseLoder;
	m_pRootFrame = aseLoder.Load("woman/woman_01_all.ASE");

	SetUp_MeshObj();
}

void cMainGame::Update()
{
	//if (m_pCubePC)
	//	m_pCubePC->Update(); 

	if (m_pCubeMan)
		m_pCubeMan->Update(m_pMap); 

	if (m_pCamera)
		m_pCamera->Update(); 

	//for (int i = 0; i < m_vecLight.size(); i++)
	//	m_vecLight[i]->Update();

	if (m_pRootFrame)
		m_pRootFrame->Update(m_pRootFrame->GetKeyFrame(), NULL);
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
	//	m_pCubePC->Render(); 

	// if (m_pCubeMan)
	// 	m_pCubeMan->Render(); 

	// for (int i = 0; i < m_vecLight.size(); i++)
	// 	m_vecLight[i]->Render();

	// Render_Obj();

	// Draw_Texture(); 

	if (m_pRootFrame)
		m_pRootFrame->Render();

	Render_MeshObj();

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

	Load_Surface();
}

void cMainGame::Render_Obj()
{
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
	g_pD3DDevice->LightEnable(1, false);
	g_pD3DDevice->LightEnable(2, false);

	D3DXMATRIXA16 matWorld, matS, matR;
	D3DXMatrixScaling(&matS, 0.01f, 0.01f, 0.01f);
	D3DXMatrixRotationX(&matR, -D3DX_PI / 2.0f);

	matWorld = matS * matR;

	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	
	// m_vecGroup[0]->Render();
	for each(auto p in m_vecGroup)
	{
		p->Render();
	}

	// todo : ����!
	//		  �� �ε� & ĳ���� �ٴ� üũ
	// D3DXIntersectTri()
	/*
	D3DXIntersectTri(v1, v2, v3, rayPos, rayDir, u, v, f);
	// v1, v2, v3 : ������ ����(�ٴ� surface)
	// rayPos : ���� ������
	// rayDir : ���� ���� ����
	// (ĳ���� ��ġ, �ǹ� ���� ��, ĳ���� ��ġ)
	// u, v ���� ���� �ʿ� x
	// f : �浹�� ���� �� ��
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

void cMainGame::SetUp_MeshObj()
{
	D3DXCreateTeapot(g_pD3DDevice, &m_pMeshTeaPot, NULL);
	D3DXCreateSphere(g_pD3DDevice, 0.5f, 10, 10, &m_pMeshSphere, NULL);

	ZeroMemory(&m_stMtlTeaPot,sizeof(D3DMATERIAL9));
	m_stMtlTeaPot.Ambient = D3DXCOLOR(0.0f, 0.7f, 0.7f, 1.0f);
	m_stMtlTeaPot.Diffuse = D3DXCOLOR(0.0f, 0.7f, 0.7f, 1.0f);
	m_stMtlTeaPot.Specular = D3DXCOLOR(0.0f, 0.7f, 0.7f, 1.0f);

	ZeroMemory(&m_stMtlSphere, sizeof(D3DMATERIAL9));
	m_stMtlSphere.Ambient = D3DXCOLOR(0.7f, 0.7f, 0.0f, 1.0f);
	m_stMtlSphere.Diffuse = D3DXCOLOR(0.7f, 0.7f, 0.0f, 1.0f);
	m_stMtlSphere.Specular = D3DXCOLOR(0.7f, 0.7f, 0.0f, 1.0f);

	// ================================================================

	cObjLoader loader;
	m_pObjMesh = loader.LoadMesh(m_vecObjMtlTex, "obj", "map.obj");

}

void cMainGame::Render_MeshObj()
{
	D3DXMATRIXA16 matWorld, matS, matR;
	{
		D3DXMatrixIdentity(&matS);
		D3DXMatrixIdentity(&matR); 
		matWorld = matS * matR;
		D3DXMatrixTranslation(&matWorld, 0, 1, 10);

		g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

		g_pD3DDevice->SetMaterial(&m_stMtlTeaPot);
		m_pMeshTeaPot->DrawSubset(0);	// attribute 1��
	}

	{
		D3DXMatrixIdentity(&matS);
		D3DXMatrixIdentity(&matR);
		matWorld = matS * matR;
		D3DXMatrixTranslation(&matWorld, 1, 1, 0);
		g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

		g_pD3DDevice->SetMaterial(&m_stMtlSphere);
		m_pMeshSphere->DrawSubset(0);	// attribute 1��
	}
	// ================================================================
	{
		D3DXMatrixIdentity(&matWorld);
		D3DXMatrixScaling(&matS, 0.01f, 0.01f, 0.01f);
		D3DXMatrixRotationX(&matR, -D3DX_PI / 2.0f);

		matWorld = matS * matR;

		g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

		for (size_t i = 0; i < m_vecObjMtlTex.size(); i++)
		{
			g_pD3DDevice->SetMaterial(&m_vecObjMtlTex[i]->GetMaterial());
			g_pD3DDevice->SetTexture(0, m_vecObjMtlTex[i]->GetTexture());

			m_pObjMesh->DrawSubset(i);
		}
	}
}