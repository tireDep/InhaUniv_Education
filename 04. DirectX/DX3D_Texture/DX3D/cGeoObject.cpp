#include "stdafx.h"
#include "cGeoObject.h"

cGeoObject::cGeoObject() :
	m_pMtrlTex(NULL)
{
	D3DXMatrixIdentity(&m_matWorld);
	D3DXMatrixIdentity(&m_matLocal);
}

cGeoObject::~cGeoObject()
{
}

void cGeoObject::Render()
{
	for (int i = 0; i < m_vecChild.size(); i++)
	{
		m_vecChild[i]->Render();
	}

	if (m_pMtrlTex == NULL)
		return;
	else
	{
		g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);

		g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matLocal);
		g_pD3DDevice->SetTexture(0, m_pMtrlTex->GetTexture());
		g_pD3DDevice->SetMaterial(&m_pMtrlTex->GetMaterial());
		g_pD3DDevice->SetFVF(ST_PNT_VERTEX::FVF);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, m_vecVertex.size() / 3,
			&m_vecVertex[0], sizeof(ST_PNT_VERTEX));
	}
}

cGeoObject * cGeoObject::GetMyParents(string sParentName)
{
	if (!strcmp(m_sName.c_str(), sParentName.c_str()))
		return this;

	cGeoObject * pParenet = NULL;
	for (int i = 0; i < m_vecChild.size(); i++)
	{
		pParenet = m_vecChild[i]->GetMyParents(sParentName);
		if (pParenet != NULL)
			return pParenet;
	}

	return NULL;
}

bool cGeoObject::AddChild(cGeoObject * pChild)
{
	if (pChild == NULL)
		return false;

	m_vecChild.push_back(pChild);
	return true;
}

void cGeoObject::SetName(string name)
{
	m_sName = name;
}

void cGeoObject::CalcLocalMat(cGeoObject * pParent)
{
	m_matLocal = m_matWorld;

	if (pParent)
	{
		D3DXMATRIXA16 matInverse;
		D3DXMatrixInverse(&matInverse, 0, &pParent->m_matWorld);
		m_matLocal *= matInverse;
	}

	for (int i = 0; i < m_vecChild.size(); i++)
	{
		m_vecChild[i]->CalcLocalMat(this);
	}
}
