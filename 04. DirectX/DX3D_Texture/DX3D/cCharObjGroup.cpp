#include "stdafx.h"
#include "cCharObjGroup.h"

cCharObjGroup::cCharObjGroup() :
	m_pMtlTex(NULL)
{
}

cCharObjGroup::~cCharObjGroup()
{
	SafeRelease(m_pMtlTex);
}

void cCharObjGroup::Render()
{
	if (m_pMtlTex)
	{
		g_pD3DDevice->SetTexture(0, m_pMtlTex->GetTexture());
		g_pD3DDevice->SetMaterial(&m_pMtlTex->GetMaterial());
	}

	g_pD3DDevice->SetFVF(ST_PNT_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, m_vecVertex.size() / 3, &m_vecVertex[0], sizeof(ST_PNT_VERTEX));

	g_pD3DDevice->SetTexture(0, NULL);
}

void cCharObjGroup::SetNodeName(string set)
{
	m_nodeName = set;
}

void cCharObjGroup::SetTextureIndex(int set)
{
	m_textureIndex = set;
}

void cCharObjGroup::SetWorldMatrix(vector<D3DXVECTOR3> vecTempMat)
{
	D3DXMatrixIdentity(&m_matWorld);
	for (int i = 0; i < 16; i++)
	{
		if (i == 0 || i == 3)
		{
			m_matWorld[i + 0] = vecTempMat[i].x;
			m_matWorld[i + 1] = vecTempMat[i].y;
			m_matWorld[i + 2] = vecTempMat[i].z;
		}
		else if (i == 1)
		{
			m_matWorld[i + 0 + 1] = vecTempMat[i + 1].x;
			m_matWorld[i + 1 + 1] = vecTempMat[i + 1].y;
			m_matWorld[i + 2 + 1] = vecTempMat[i + 1].z;
		}
		else if (i == 2)
		{
			m_matWorld[i + 0 - 1] = vecTempMat[i - 1].x;
			m_matWorld[i + 1 - 1] = vecTempMat[i - 1].y;
			m_matWorld[i + 2 - 1] = vecTempMat[i - 1].z;
		}
	}
}

string cCharObjGroup::GetNodeName()
{
	return m_nodeName;
}

int cCharObjGroup::GetTextureIndex()
{
	return m_textureIndex;
}
