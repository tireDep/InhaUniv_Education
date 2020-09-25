#include "stdafx.h"
#include "cGrid.h"
#include "cGizmo.h"

cGrid::cGrid()
{

}

cGrid::~cGrid()
{
	for each(auto p in m_vecGizmo)
	{
		SafeDelete(p);
	}

	m_vecGizmo.clear();
}

void cGrid::SetUp(int nNumHalfTile, float fInterval)
{
	float fMax = nNumHalfTile * fInterval;
	float fMin = -fMax;

	stPC_Vertex v;
	for (int i = 1; i <= nNumHalfTile; i++)
	{
		if (i % 5 == 0)
			v.c = D3DCOLOR_XRGB(255, 255, 255);
		else
			v.c = D3DCOLOR_XRGB(128, 128, 128);

		v.p = D3DXVECTOR3(fMin, 0, i*fInterval);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(fMax, 0, i*fInterval);
		m_vecVertex.push_back(v);

		v.p = D3DXVECTOR3(fMin, 0, -i*fInterval);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(fMax, 0, -i*fInterval);
		m_vecVertex.push_back(v);

		v.p = D3DXVECTOR3(i*fInterval, 0, fMin);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(i*fInterval, 0, fMax);
		m_vecVertex.push_back(v);

		v.p = D3DXVECTOR3(-i*fInterval, 0, fMin);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(-i*fInterval, 0, fMax);
		m_vecVertex.push_back(v);
	}

	// >> 축
	v.c = D3DCOLOR_XRGB(255, 0, 0);
	v.p = D3DXVECTOR3(fMin, 0, 0); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(fMax, 0, 0); m_vecVertex.push_back(v);

	v.c = D3DCOLOR_XRGB(0, 255, 0);
	v.p = D3DXVECTOR3(0, fMin, 0); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0, fMax, 0); m_vecVertex.push_back(v);

	v.c = D3DCOLOR_XRGB(0, 0, 255);
	v.p = D3DXVECTOR3(0, 0, fMin); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0, 0, fMax); m_vecVertex.push_back(v);
	// << 축

	// >> gizmo
	cGizmo* pGizmo = NULL;
	D3DXMATRIXA16 matR;

	// x
	pGizmo = new cGizmo;
	D3DXMatrixRotationZ(&matR, D3DX_PI / 2.0f);
	pGizmo->SetUp(D3DCOLOR_XRGB(255, 0, 0), matR);
	m_vecGizmo.push_back(pGizmo);

	// y
	pGizmo = new cGizmo;
	D3DXMatrixRotationZ(&matR, D3DX_PI);
	pGizmo->SetUp(D3DCOLOR_XRGB(0, 255, 0), matR);
	m_vecGizmo.push_back(pGizmo);
	// >> 180도 회전

	// z
	pGizmo = new cGizmo;
	D3DXMatrixRotationX(&matR, -D3DX_PI / 2.0f);
	pGizmo->SetUp(D3DCOLOR_XRGB(0, 0,255), matR);
	m_vecGizmo.push_back(pGizmo);
	// << gizmo
}

void cGrid::Render()
{
	D3DXMATRIXA16 matI;
	D3DXMatrixIdentity(&matI);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matI);
	g_pD3DDevice->SetFVF(stPC_Vertex::eFVF);

	g_pD3DDevice->DrawPrimitiveUP(D3DPT_LINELIST, m_vecVertex.size() / 2, &m_vecVertex[0], sizeof(stPC_Vertex));

	for each(auto p in m_vecGizmo)
		p->Render();
}


