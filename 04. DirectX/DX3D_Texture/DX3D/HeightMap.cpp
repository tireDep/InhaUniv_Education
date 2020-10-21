#include "stdafx.h"
#include "HeightMap.h"


CHeightMap::CHeightMap() : 
	m_pTexture(NULL)
{
}


CHeightMap::~CHeightMap()
{
	SafeRelease(m_pTexture);
}

void CHeightMap::SetUp(IN int ** heightArr)
{
	m_mtrl.Ambient = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
}

void CHeightMap::Render()
{
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);

	g_pD3DDevice->SetMaterial(&m_mtrl);
	g_pD3DDevice->SetTexture(0, m_pTexture);

	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);

	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetFVF(ST_PNT_VERTEX::FVF);

	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, m_vecVertex.size() / 3, &m_vecVertex[0], sizeof(ST_PNT_VERTEX));

	g_pD3DDevice->SetTexture(0, NULL);
}
