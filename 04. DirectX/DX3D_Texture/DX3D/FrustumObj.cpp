#include "stdafx.h"
#include "FrustumObj.h"

CFrustumObj::CFrustumObj()
{
}

CFrustumObj::~CFrustumObj()
{
}

void CFrustumObj::SetUp()
{
	D3DXMATRIXA16 matProj;
	g_pD3DDevice->GetTransform(D3DTS_PROJECTION, &matProj);
	// D3DXMatrixInverse(&matProj, 0, &matProj);

	D3DXMATRIXA16 matView;
	g_pD3DDevice->GetTransform(D3DTS_VIEW, &matView);
	// D3DXMatrixInverse(&matView, 0, &matView);
	
	D3DVIEWPORT9 viewPort;
	g_pD3DDevice->GetViewport(&viewPort);

	float zMinNum = -matProj._43 / matProj._33;
	float r = 1000 / (1000 - zMinNum);
	matProj._33 = r;
	matProj._43 = -r*zMinNum;

	D3DXMATRIXA16 matViewProj = matView * matProj;
	
	D3DXPLANE plane;
	plane.a = matViewProj._14 + matViewProj._13;
	plane.b = matViewProj._24 + matViewProj._23;
	plane.c = matViewProj._34 + matViewProj._33;
	plane.d = matViewProj._44 + matViewProj._43;
	D3DXPlaneNormalize(&plane, &plane);
	m_vecPlane.push_back(plane);
	// near
	
	plane.a = matViewProj._14 - matViewProj._13;
	plane.b = matViewProj._24 - matViewProj._23;
	plane.c = matViewProj._34 - matViewProj._33;
	plane.d = matViewProj._44 - matViewProj._43;
	D3DXPlaneNormalize(&plane, &plane);
	m_vecPlane.push_back(plane);
	// far
	
	plane.a = matViewProj._14 + matViewProj._11;
	plane.b = matViewProj._24 + matViewProj._21;
	plane.c = matViewProj._34 + matViewProj._31;
	plane.d = matViewProj._44 + matViewProj._41;
	D3DXPlaneNormalize(&plane, &plane);
	m_vecPlane.push_back(plane);
	// left
	
	plane.a = matViewProj._14 - matViewProj._11;
	plane.b = matViewProj._24 - matViewProj._21;
	plane.c = matViewProj._34 - matViewProj._31;
	plane.d = matViewProj._44 - matViewProj._41;
	D3DXPlaneNormalize(&plane, &plane);
	m_vecPlane.push_back(plane);
	// right
	
	plane.a = matViewProj._14 - matViewProj._12;
	plane.b = matViewProj._24 - matViewProj._22;
	plane.c = matViewProj._34 - matViewProj._32;
	plane.d = matViewProj._44 - matViewProj._42;
	D3DXPlaneNormalize(&plane, &plane);
	m_vecPlane.push_back(plane);
	// top
	
	plane.a = matViewProj._14 + matViewProj._12;
	plane.b = matViewProj._24 + matViewProj._22;
	plane.c = matViewProj._34 + matViewProj._32;
	plane.d = matViewProj._44 + matViewProj._42;
	D3DXPlaneNormalize(&plane, &plane);
	m_vecPlane.push_back(plane);
	// bottom
}

void CFrustumObj::Update()
{
	m_vecPlane.clear();
	SetUp();
}

bool CFrustumObj::IsInFrustum(D3DXVECTOR3 vPoint, float & fRadius, bool isClicked)
{
	float fRet;
	if (isClicked)
	{
		// isClicked = false;

		for (int i = 0; i < m_vecPlane.size(); i++)
		{
			fRet = D3DXPlaneDotCoord(&m_vecPlane[i], &vPoint);

			if (fRet < fRadius * 0.5)
				return false;
		}
	}

	return true;
}

void CFrustumObj::Render()
{
	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);

	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

	g_pD3DDevice->DrawPrimitiveUP(D3DPT_LINESTRIP, m_vecPlane.size()-1, &m_vecPlane[0], sizeof(D3DXPLANE));
}
