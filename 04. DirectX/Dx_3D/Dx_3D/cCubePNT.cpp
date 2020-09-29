#include "stdafx.h"
#include "cCubePNT.h"

cCubePNT::cCubePNT()
{

}

cCubePNT::~cCubePNT()
{

}

void cCubePNT::SetUp()
{
	std::vector<stPNT_Vertext> verVertex;
	verVertex.resize(8);
	
	verVertex[0].p.x = -0.5f; verVertex[0].p.y = -0.5f; verVertex[0].p.z = -0.5f;
	verVertex[1].p.x = -0.5f; verVertex[1].p.y = 0.5f; verVertex[1].p.z = -0.5f;
	verVertex[2].p.x = 0.5f; verVertex[2].p.y = 0.5f; verVertex[2].p.z = -0.5f;
	verVertex[3].p.x = 0.5f; verVertex[3].p.y = -0.5f; verVertex[3].p.z = -0.5f;

	verVertex[4].p.x = -0.5f; verVertex[4].p.y = -0.5f; verVertex[4].p.z = 0.5f;
	verVertex[5].p.x = -0.5f; verVertex[5].p.y =  0.5f; verVertex[5].p.z = 0.5f;
	verVertex[6].p.x =  0.5f; verVertex[6].p.y =  0.5f; verVertex[6].p.z = 0.5f;
	verVertex[7].p.x =  0.5f; verVertex[7].p.y = -0.5f; verVertex[7].p.z = 0.5f;
	// >> 크기가 1인 상자

	std::vector<DWORD> vecIndex;
	// front
	vecIndex.push_back(0);
	vecIndex.push_back(1);
	vecIndex.push_back(2);

	vecIndex.push_back(0);
	vecIndex.push_back(2);
	vecIndex.push_back(3);

	// back
	vecIndex.push_back(4);
	vecIndex.push_back(6);
	vecIndex.push_back(5);

	vecIndex.push_back(4);
	vecIndex.push_back(7);
	vecIndex.push_back(6);

	// left
	vecIndex.push_back(4);
	vecIndex.push_back(5);
	vecIndex.push_back(1);

	vecIndex.push_back(4);
	vecIndex.push_back(1);
	vecIndex.push_back(0);

	// right
	vecIndex.push_back(3);
	vecIndex.push_back(2);
	vecIndex.push_back(6);

	vecIndex.push_back(3);
	vecIndex.push_back(6);
	vecIndex.push_back(7);

	// up
	vecIndex.push_back(1);
	vecIndex.push_back(5);
	vecIndex.push_back(6);

	vecIndex.push_back(1);
	vecIndex.push_back(6);
	vecIndex.push_back(2);

	// down
	vecIndex.push_back(4);
	vecIndex.push_back(0);
	vecIndex.push_back(3);

	vecIndex.push_back(4);
	vecIndex.push_back(3);
	vecIndex.push_back(7);

	m_vecVertex.resize(36);
	for (size_t i = 0; i < vecIndex.size(); i += 3)
	{
		m_vecVertex[i + 0] = verVertex[vecIndex[i + 0]];
		m_vecVertex[i + 1] = verVertex[vecIndex[i + 1]];
		m_vecVertex[i + 2] = verVertex[vecIndex[i + 2]];
	}

	D3DXVECTOR3 u, v, n;
	for (int i = 0; i < 36; i += 3)
	{
		u = m_vecVertex[i + 1].p - m_vecVertex[i].p;
		n = m_vecVertex[i + 2].p - m_vecVertex[i].p;	// normal vector

		D3DXVec3Cross(&n, &u, &v);
		D3DXVec3Normalize(&n, &n);

		m_vecVertex[i + 0].n = n;
		m_vecVertex[i + 1].n = n;
		m_vecVertex[i + 2].n = n;
	}
	// >> normal vector 생성 관련
}

void cCubePNT::Update()
{

}

void cCubePNT::Render()
{
	g_pD3DDevice->SetFVF(stPNT_Vertext::eFVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, m_vecVertex.size() / 3, &m_vecVertex[0], sizeof(stPNT_Vertext));
}
