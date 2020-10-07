#include "stdafx.h"
#include "cDirection.h"

#define dMaxT 1.0f
#define dAddT 0.5f
// 값이 클 수록 급격하게 꺾임

cDirection::cDirection()
{
}

cDirection::~cDirection()
{
}

void cDirection::SetUp(cDirection set)
{
	ST_PC_VERTEX addVertex;
	D3DXVECTOR3 fSpot, sSpot;

	addVertex.c = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);

	float tNum = 0.0f;
	// 1차 베지에 곡선 : 두 점 사이의 직선
	/*
	for (int i = 0; i < set.m_vecVertex.size() - 1; i += 1)
	{
		while (tNum < dMaxT)
		{
			addVertex.p = (1 - tNum) * set.m_vecVertex[i + 0].p
						+ tNum * set.m_vecVertex[i + 1].p;

			m_vecVertex.push_back(addVertex);
			tNum += dAddT;
		}
		tNum = 0.0f;
	}
	*/
	
	// 2차 베지에 곡선
	for (int i = 0; i < set.m_vecVertex.size() - 1; i += 2)
	{
		while (tNum < dMaxT)
		{
			addVertex.p = pow(1 - tNum, 2) * set.m_vecVertex[i + 0].p
						+ 2 * (1 - tNum) * tNum * set.m_vecVertex[i + 1].p
						+ pow(tNum, 2) * set.m_vecVertex[i + 2].p;
	
			m_vecVertex.push_back(addVertex);
			tNum += dAddT;
		}
		 tNum = 0.0f;
	}

	// 3차 베지에 곡선
	/*
	for (int i = 0; i < set.m_vecVertex.size() - 1; i += 3)
	{
		while (tNum < dMaxT)
		{
			addVertex.p = pow(1 - tNum, 3) * set.m_vecVertex[i + 0].p
						+ 3 * pow(1 - tNum, 2) * tNum * set.m_vecVertex[i + 1].p
						+ 3 * (1 - tNum) * pow(tNum, 2)  * set.m_vecVertex[i + 2].p;
						+ pow(tNum, 3) * set.m_vecVertex[i + 3].p;

			m_vecVertex.push_back(addVertex);
			tNum += dAddT;
		}
		tNum = 0.0f;
	}
	*/

	m_vecVertex.push_back(m_vecVertex[0]);
}

void cDirection::SetUpHexa()
{
	ST_PC_VERTEX addVertex;

	addVertex.c = D3DXCOLOR(0.0f, 1.0f, 0.0f, 1.0f);

	addVertex.p = D3DXVECTOR3(5.0f, 0.5f, 5.0f);
	m_vecVertex.push_back(addVertex);

	D3DXMATRIXA16 matR;

	D3DXMatrixRotationY(&matR, 60 * D3DX_PI / 180);
	for (int i = 0; i < 6; i++)
	{
		D3DXVec3TransformCoord(&addVertex.p, &addVertex.p, &matR);
		m_vecVertex.push_back(addVertex);
	}
}

void cDirection::Render()
{
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);

	D3DXMATRIXA16 matI;
	D3DXMatrixIdentity(&matI);

	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matI);
	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);

	g_pD3DDevice->DrawPrimitiveUP(D3DPT_LINESTRIP, m_vecVertex.size() - 1, &m_vecVertex[0], sizeof(ST_PC_VERTEX));
}
