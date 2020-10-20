#include "stdafx.h"
#include "CSphere.h"


CSphere::CSphere() :
	m_isClicked(false),
	m_center(0, 0, 0)
{
}


CSphere::~CSphere()
{
}

void CSphere::SetUp(float radius, UINT slice, UINT stack, D3DXVECTOR3 center)
{
	D3DXCreateSphere(g_pD3DDevice, radius, slice, stack, &m_pMeshSphere, NULL);

	ZeroMemory(&m_stMtlSphere, sizeof(D3DMATERIAL9));
	m_stMtlSphere.Ambient = D3DXCOLOR(0.7f, 0.7f, 0.0f, 1.0f);
	m_stMtlSphere.Diffuse = D3DXCOLOR(0.7f, 0.7f, 0.0f, 1.0f);
	m_stMtlSphere.Specular = D3DXCOLOR(0.7f, 0.7f, 0.0f, 1.0f);

	m_center = center;
}

void CSphere::Render()
{
	D3DXMATRIXA16 matWorld, matS, matR;
	
	D3DXMatrixIdentity(&matS);
	D3DXMatrixIdentity(&matR);
	matWorld = matS * matR;
	
	D3DXMatrixTranslation(&matWorld, m_center.x, m_center.y, m_center.z);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetMaterial(&m_stMtlSphere);

	if(m_isClicked)
	{
		m_stMtlSphere.Ambient = D3DXCOLOR(0.7f, 0.0f, 0.0f, 1.0f);
		m_stMtlSphere.Diffuse = D3DXCOLOR(0.7f, 0.0f, 0.0f, 1.0f);
		m_stMtlSphere.Specular = D3DXCOLOR(0.7f, 0.0f, 0.0f, 1.0f);

		// D3DXMatrixTranslation(&matWorld, 0, 0, 0);
		// g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	}
	else
	{
		m_stMtlSphere.Ambient = D3DXCOLOR(0.7f, 0.0f, 7.0f, 1.0f);
		m_stMtlSphere.Diffuse = D3DXCOLOR(0.7f, 0.0f, 7.0f, 1.0f);
		m_stMtlSphere.Specular = D3DXCOLOR(0.7f, 0.0f, 7.0f, 1.0f);
	}
	m_pMeshSphere->DrawSubset(0);
}

void CSphere::SetIsClicked(bool set)
{
	m_isClicked = set;
}

void CSphere::SetMatWorldPos(D3DXVECTOR3 set)
{
	m_center = set;
}

bool CSphere::GetIsClicked()
{
	return m_isClicked;
}

D3DXVECTOR3 CSphere::GetCenter()
{
	return m_center;
}

D3DXMATRIXA16 CSphere::GetMatWorld()
{
	D3DXMATRIXA16 ret;
	D3DXMatrixTranslation(&ret, m_center.x, m_center.y, m_center.z);
	return ret;
}

LPD3DXMESH CSphere::GetMesh()
{
	return m_pMeshSphere;
}
