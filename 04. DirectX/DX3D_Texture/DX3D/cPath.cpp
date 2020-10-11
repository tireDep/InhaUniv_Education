#include "stdafx.h"
#include "cPath.h"

cPath::cPath()
{
}

cPath::~cPath()
{
}

void cPath::SetUp(int spot)
{
	float radian = ShapeDegreeToRadian(spot);

	ST_PC_VERTEX addSpot;
	addSpot.c = D3DXCOLOR(0.0f, 255.0f, 0.0f, 1.0f);
	addSpot.p = D3DXVECTOR3(0.0f, 1.0f, 5.0f);
	m_vecVertex.push_back(addSpot);

	for (int i = 0; i < spot; i++)
	{
		D3DXMATRIXA16 matR;
		D3DXMatrixRotationY(&matR, radian);
		D3DXVec3TransformCoord(&addSpot.p, &addSpot.p, &matR);

		m_vecVertex.push_back(addSpot);
	}
}

void cPath::Render()
{
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);

	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);

	g_pD3DDevice->DrawPrimitiveUP(D3DPT_LINESTRIP, m_vecVertex.size() - 1, &m_vecVertex[0], sizeof(ST_PC_VERTEX));
}

float cPath::ShapeDegreeToRadian(int spot)
{
	float degree = 180 - (180 * (spot - 2) / spot);
	// ※ : 정n각형의 내각 공식 => 180 * (spot - 2) / spot
	return degree * D3DX_PI / 180;
}

vector<ST_PC_VERTEX> cPath::GetVertex()
{
	return m_vecVertex;
}
