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

#include "Ray.h"

#include "HeigthMap.h"

#include "SkinnedMesh.h"

#include "Frustum.h"

#include "Zealot.h"
#include "OBB.h"

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
	, m_pSkinnedMesh(NULL)
	, m_pFrustum(NULL)
	, m_pHoldZealot(NULL)
	, m_pMoveZealot(NULL)
	, m_pFont(NULL)
	, m_p3DText(NULL)
	, m_pSprite(NULL)
	, m_pTextureUI(NULL)
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

	SafeDelete(m_pFrustum);

	SafeDelete(m_pSkinnedMesh);

	// >> OBB
	SafeDelete(m_pHoldZealot);
	SafeDelete(m_pMoveZealot);
	// << OBB

	//>> font
	SafeRelease(m_pFont);
	SafeRelease(m_p3DText);

	g_pFontManager->Destroy();
	//>> font

	// >> UI
	SafeRelease(m_pSprite);
	SafeRelease(m_pTextureUI);
	// << UI

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

	// SetUp_MeshObj();
	// 
	// SetUp_PickingObj();
	// 
	// SetUp_HeightMap();

	m_pSkinnedMesh = new CSkinnedMesh;
	m_pSkinnedMesh->SetUp("xFile/Zealot", "zealot.x");

	SetUp_Frustum();

	// >> OBB
	SetUp_OBB();
	// << OBB

	Create_Font();

	SetUp_UI();
}

void cMainGame::Update()
{
	//if (m_pCubePC)
	//	m_pCubePC->Update(); 

	// if (m_pCubeMan)
	// 	m_pCubeMan->Update(m_pMap); 
	
	if (m_pFrustum)
		m_pFrustum->Update();

	if (m_pCamera)
		m_pCamera->Update(); 

	//for (int i = 0; i < m_vecLight.size(); i++)
	//	m_vecLight[i]->Update();

	if (m_pRootFrame)
		m_pRootFrame->Update(m_pRootFrame->GetKeyFrame(), NULL);

	// if (GetKeyState('5') & 0x8000)
	// 	m_pSkinnedMesh->SetAnimationIndexBlend(3);
	// 
	// g_pTimeManager->Update();
	// if (m_pSkinnedMesh)
	// 	m_pSkinnedMesh->Update();

	// >> OBB
	g_pTimeManager->Update();
	if (m_pHoldZealot)
		m_pHoldZealot->Update(m_pMap);

	if (m_pMoveZealot)
		m_pMoveZealot->Update(m_pMap);
	// << OBB
}

void cMainGame::Render()
{
	g_pD3DDevice->Clear(NULL, NULL,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_XRGB(47, 121, 112) , 
		1.0F, 0);

	g_pD3DDevice->BeginScene();

	Render_Txt();
	// PickingObj_Render();

	if (m_pGrid)
		m_pGrid->Render(); 

	Render_OBB();

	// Render_Frustum();

	// if (m_pCubePC)
	//	m_pCubePC->Render(); 

	// if (m_pMap)
	// 	m_pMap->Render();

	// if (m_pCubeMan)
	// 	m_pCubeMan->Render(); 

	// Render_SkinnedMesh();

	// for (int i = 0; i < m_vecLight.size(); i++)
	// 	m_vecLight[i]->Render();

	// Render_Obj();

	// Draw_Texture(); 

	// if (m_pRootFrame)
	// 	m_pRootFrame->Render();

	// Render_MeshObj();

	Render_UI();
	// 맨 마지막에 그릴 것

	g_pD3DDevice->EndScene();
	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}

void cMainGame::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (m_pCamera)
		m_pCamera->WndProc(hWnd, message, wParam, lParam); 

	switch (message)
	{
	case WM_LBUTTONDOWN:
		{
			CRay r = CRay::RayAtWorldSpace(LOWORD(lParam), HIWORD(lParam));
			for (int i = 0; i < m_vecSphere.size(); i++)
			{
				m_vecSphere[i].isPicked = r.IsPicked(&m_vecSphere[i]);
				// 라인이 있는 모든것이 선택되는 단점이 있음
			}
		}
		break;

	case WM_RBUTTONDOWN:
		{
			// >> frustum
			for each(ST_SPHERE* sphere in m_vecCullingSphere)
			{
				if (m_pFrustum->IsIn(sphere))
					sphere->isPicked = true;
				else
					sphere->isPicked = false;
			}
			// << frustum

			// << 애니메이션
			//static int n = 0;
			// m_pSkinnedMesh->SetAnimationIndex(++n);
			//m_pSkinnedMesh->SetAnimationIndexBlend(++n);
			// >> 애니메이션

			// CRay r = CRay::RayAtWorldSpace(LOWORD(lParam), HIWORD(lParam));
			// 
			// for (int i = 0; i < m_vecPlanVertex.size(); i+=3)
			// {
			// 	D3DXVECTOR3 v(0, 0, 0);
			// 	if (r.IntersectTri(m_vecPlanVertex[i + 0].p, m_vecPlanVertex[i + 1].p, m_vecPlanVertex[i + 2].p, v))
			// 	{
			// 		m_vPickedPosition = v;
			// 	}
			// }
		}
		break;

	default:
		break;
	}
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
		m_pMeshTeaPot->DrawSubset(0);	// attribute 1개
	}

	{
		D3DXMatrixIdentity(&matS);
		D3DXMatrixIdentity(&matR);
		matWorld = matS * matR;
		D3DXMatrixTranslation(&matWorld, 1, 1, 0);
		g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

		g_pD3DDevice->SetMaterial(&m_stMtlSphere);
		m_pMeshSphere->DrawSubset(0);	// attribute 1개
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

void cMainGame::SetUp_PickingObj()
{
	for (int i = 0; i <= 10; i++)
	{
		ST_SPHERE s;
		s.fRadius = 0.5f;
		s.vCenter = D3DXVECTOR3(0, 0, -10 + 2 * i);
		m_vecSphere.push_back(s);
	}

	ZeroMemory(&m_stMtlNone, sizeof(D3DMATERIAL9));
	m_stMtlNone.Ambient =  D3DXCOLOR(0.7f, 0.7f, 0.0f, 1.0f);
	m_stMtlNone.Diffuse =  D3DXCOLOR(0.7f, 0.7f, 0.0f, 1.0f);
	m_stMtlNone.Specular = D3DXCOLOR(0.7f, 0.7f, 0.0f, 1.0f);

	ZeroMemory(&m_stMtlPicked, sizeof(D3DMATERIAL9));
	m_stMtlPicked.Ambient =  D3DXCOLOR(0.0f, 0.0f, 0.7f, 1.0f);
	m_stMtlPicked.Diffuse =  D3DXCOLOR(0.0f, 0.0f, 0.7f, 1.0f);
	m_stMtlPicked.Specular = D3DXCOLOR(0.0f, 0.0f, 0.7f, 1.0f);

	ZeroMemory(&m_stMtlPlane, sizeof(D3DMATERIAL9));
	m_stMtlPlane.Ambient =  D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
	m_stMtlPlane.Diffuse =  D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
	m_stMtlPlane.Specular = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
	
	ST_PN_VERTEX v;
	v.n = D3DXVECTOR3(0, 1, 0);	
	v.p = D3DXVECTOR3(-10,  0, -10);	m_vecPlanVertex.push_back(v);
	v.p = D3DXVECTOR3(-10,  0,  10);	m_vecPlanVertex.push_back(v);
	v.p = D3DXVECTOR3( 10,  0,  10);	m_vecPlanVertex.push_back(v);

	v.p = D3DXVECTOR3(-10, 0, -10);	m_vecPlanVertex.push_back(v);
	v.p = D3DXVECTOR3( 10, 0,  10);	m_vecPlanVertex.push_back(v);
	v.p = D3DXVECTOR3( 10, 0, -10);	m_vecPlanVertex.push_back(v);
}

void cMainGame::PickingObj_Render()
{
	g_pD3DDevice->LightEnable(1, false);
	g_pD3DDevice->LightEnable(2, false);

	// >> plane
	g_pD3DDevice->SetFVF(ST_PN_VERTEX::FVF);
	g_pD3DDevice->SetMaterial(&m_stMtlPlane);
	
	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);

	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetTexture(0, 0);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 2, &m_vecPlanVertex[0], sizeof(ST_PN_VERTEX));
	// << plane

	// >> Sphere
	for (int i = 0; i < m_vecSphere.size(); i++)
	{
		D3DXMatrixIdentity(&matWorld);
		matWorld._41 = m_vecSphere[i].vCenter.x;
		matWorld._42 = m_vecSphere[i].vCenter.y;
		matWorld._43 = m_vecSphere[i].vCenter.z;

		g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
		g_pD3DDevice->SetMaterial(m_vecSphere[i].isPicked ? &m_stMtlPicked : &m_stMtlNone);

		m_pMeshSphere->DrawSubset(0);
	}
	// << Sphere

	// >> 선택된 위치 표시용
	g_pD3DDevice->SetMaterial(&m_stMtlPicked);	
	D3DXMatrixTranslation(&matWorld, m_vPickedPosition.x, m_vPickedPosition.y, m_vPickedPosition.z);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

	m_pMeshSphere->DrawSubset(0);
	// << 선택된 위치 표시용
}

void cMainGame::SetUp_HeightMap()
{
	CHeigthMap* pMap = new CHeigthMap;
	pMap->SetUp("HeightMapData/", "HeightMap.raw", "terrain.jpg");
	m_pMap = pMap;
}

void cMainGame::Render_SkinnedMesh()
{
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);

	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);

	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	if (m_pSkinnedMesh)
		m_pSkinnedMesh->Render(NULL);
}

void cMainGame::SetUp_Frustum()
{
	D3DXCreateSphere(g_pD3DDevice, 0.5f, 10, 10, &m_pSphere, NULL);

	for (int i = -20; i <= 20; i++)
	{
		for (int j = -20; j <= 20; j++)
		{
			for (int k = -20; k <= 20; k++)
			{
				ST_SPHERE* s = new ST_SPHERE;
				s->fRadius = 0.5f;
				s->vCenter = D3DXVECTOR3((float)i, (float)j, (float)k);
				s->isPicked = true;

				m_vecCullingSphere.push_back(s);
			} // : for_k

		} // : for_j

	} // : for_i

	ZeroMemory(&m_stCullingMtl, sizeof(D3DMATERIAL9));
	m_stCullingMtl.Ambient = D3DXCOLOR(0.7f, 0.7f, 0.7f, 0.7f);
	m_stCullingMtl.Diffuse = D3DXCOLOR(0.7f, 0.7f, 0.7f, 0.7f);
	m_stCullingMtl.Specular = D3DXCOLOR(0.7f, 0.7f, 0.7f, 0.7f);

	m_pFrustum = new CFrustum;
	m_pFrustum->SetUp();
}

void cMainGame::Render_Frustum()
{
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);

	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);

	for each(ST_SPHERE* sphere in m_vecCullingSphere)
	{
		if (sphere->isPicked)
		{
			D3DXMatrixIdentity(&matWorld);
			matWorld._41 = sphere->vCenter.x;
			matWorld._42 = sphere->vCenter.y;
			matWorld._43 = sphere->vCenter.z;

			g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
			g_pD3DDevice->SetMaterial(&m_stCullingMtl);
			m_pSphere->DrawSubset(0);
		}
	}
}

void cMainGame::SetUp_OBB()
{
	m_pHoldZealot = new CZealot;
	m_pHoldZealot->SetUp();

	m_pMoveZealot = new CZealot;
	m_pMoveZealot->SetUp();

	cCharacter* pCharacter = new cCharacter;
	m_pMoveZealot->SetCharacterController(pCharacter);	// 캐릭터 이동
	SafeRelease(pCharacter);
}

void cMainGame::Render_OBB()
{
	D3DCOLOR c = COBB::IsCollision(m_pHoldZealot->GetOBB(), m_pMoveZealot->GetOBB())
		? D3DCOLOR_XRGB(255,0,0) : D3DCOLOR_XRGB(255, 255, 255); // 충돌시 색상 변경

	if (m_pHoldZealot)
		m_pHoldZealot->Render(c);

	if (m_pMoveZealot)
		m_pMoveZealot->Render(c);
}

void cMainGame::Create_Font()
{
	D3DXFONT_DESC fd;
	ZeroMemory(&fd, sizeof(D3DXFONT_DESC));
	fd.Height = 50;
	fd.Width = 25;
	fd.Weight = FW_MEDIUM;
	fd.Italic = false;
	fd.CharSet = DEFAULT_CHARSET;
	fd.OutputPrecision = OUT_DEFAULT_PRECIS;	// 외곽선 관련인듯?
	fd.PitchAndFamily = FF_DONTCARE;

	// wcscpy_s(fd.FaceName, L"굴림체");
	// 시스템 폰트 사용

	// AddFontResource(L"font/umberto.ttf");
	AddFontResourceA("font/umberto.ttf");
	wcscpy_s(fd.FaceName, L"umberto");
	// 텍스트가 깨질 경우 이미지 출력하는 방법으로(글자와 이미지 대치)
	// 외부 폰트 사용

	// >> 3dFont
	HDC hdc = CreateCompatibleDC(0);
	LOGFONT lf;
	ZeroMemory(&lf, sizeof(LOGFONT));
	lf.lfHeight = 25;
	lf.lfWidth = 12;
	lf.lfWidth = 500;
	lf.lfItalic = false;
	lf.lfUnderline = false;
	lf.lfStrikeOut = false;
	lf.lfCharSet = DEFAULT_CHARSET;

	wcscpy_s(lf.lfFaceName, L"umberto");

	HFONT hFont;
	HFONT hFontOld;
	hFont = CreateFontIndirect(&lf);
	hFontOld = (HFONT)SelectObject(hdc, hFont);
	D3DXCreateTextA(g_pD3DDevice, hdc, "Direct3D", 0.001f, 0.01f, &m_p3DText, 0, 0);

	SelectObject(hdc, hFontOld);
	DeleteObject(hFont);
	DeleteDC(hdc);
	// << 3dFont
	// 무거워서 UI는 사용 안하는 것이 좋음(단, 캐릭터 위 아이디 등..? => 부하 생길 수 있음)
	// 오브젝트 처럼 사용 할 수 있음

	D3DXCreateFontIndirect(g_pD3DDevice, &fd, &m_pFont);
}

void cMainGame::Render_Txt()
{
	string sText("ABC 123 !@# 가나다");

	RECT rc;
	SetRect(&rc, 100, 100, 300, 300);

	LPD3DXFONT pFont = g_pFontManager->GetFont(CFontManager::E_DEFAULT);

	// m_pFont->DrawTextA(NULL, sText.c_str(), sText.length(), 
	// 	&rc, DT_LEFT | DT_TOP | DT_NOCLIP, D3DCOLOR_XRGB(255, 255, 0));
	// >> 문자 출력

	m_pFont = pFont;
	m_pFont->DrawTextA(NULL, sText.c_str(), sText.length(),
		&rc, DT_LEFT | DT_TOP | DT_NOCLIP, D3DCOLOR_XRGB(255, 255, 0));


	// >> 3dFont
	D3DXMATRIXA16 matWorld, matS, matR, matT;
	D3DXMatrixIdentity(&matS);
	D3DXMatrixIdentity(&matR);
	D3DXMatrixIdentity(&matT);
	
	D3DXMatrixScaling(&matS, 1.0f, 1.0f, 1.0f);
	D3DXMatrixRotationX(&matR, -D3DX_PI / 4.0f);
	D3DXMatrixTranslation(&matT, -2.0f, 1.0f, 0.0f);

	matWorld = matS * matR * matT;
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

	m_p3DText->DrawSubset(0);
	// << 3dFont
}

void cMainGame::SetUp_UI()
{
	D3DXCreateSprite(g_pD3DDevice, &m_pSprite);

	// m_pTextureUI = g_pTextureManager->GetTexture("UI/test2.png");
	// UI는 이런식 로드 X

	D3DXCreateTextureFromFileExA(
		g_pD3DDevice,
		"UI/test2.png",
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_FILTER_NONE,
		D3DX_DEFAULT,
		0,
		&m_stImgInfo,
		NULL,
		&m_pTextureUI
	);
}

void cMainGame::Render_UI()
{
	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);

	RECT rc;
	SetRect(&rc, 0, 0, m_stImgInfo.Width, m_stImgInfo.Height);

	D3DXMATRIXA16 matS, matR, matT, matWorld;
	D3DXMatrixTranslation(&matT, 5, 5, 0);

	static float fAngle = 0.0f;
	fAngle += 0.01f;
	D3DXMatrixRotationZ(&matR, fAngle);

	matWorld = matR * matT;
	m_pSprite->SetTransform(&matWorld);

	m_pSprite->Draw(m_pTextureUI, &rc, &D3DXVECTOR3(0, 0, 0),
		&D3DXVECTOR3(0, 0, 0), D3DCOLOR_ARGB(150, 255, 255, 255));

	m_pSprite->End();
}
