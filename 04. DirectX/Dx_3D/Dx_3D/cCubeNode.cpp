#include "stdafx.h"
#include "cCubeNode.h"

cCubeNode::cCubeNode() :
	m_fRotDeleaX(0.0f),
	m_pParentWorldTM(NULL),
	m_vLocalPos(0,0,0),
	m_fRotX(0.0f)
{
	D3DXMatrixIdentity(&m_matLocalTM);
	D3DXMatrixIdentity(&m_matWorldTM);
}

cCubeNode::~cCubeNode()
{

}

void cCubeNode::AddChild(cCubeNode * pChild)
{
	// 몸통 기준
	pChild->m_pParentWorldTM = &m_matWorldTM;
	m_vecChild.push_back(pChild);
}

void cCubeNode::Destory()
{
	for each(auto p in m_vecChild)
	{
		p->Destory();
	}
	delete this;
}

void cCubeNode::SetUp()
{
	cCubePNT::SetUp();
}

void cCubeNode::Update()
{
	cCubePNT::Update();

	// >> 회전
	m_fRotX += m_fRotDeleaX;
	if (m_fRotX > D3DX_PI / 6.0f)
	{
		m_fRotX = D3DX_PI / 6.0f;
		m_fRotDeleaX *= -1;
	}
	if (m_fRotX < -D3DX_PI / 6.0f)
	{
		m_fRotX = - D3DX_PI / 6.0f;
		m_fRotDeleaX *= -1;
	}
	// << 회전

	D3DXMATRIXA16 matR, matT;
	D3DXMatrixIdentity(&matR);
	D3DXMatrixIdentity(&matT);

	// >> 회전
	D3DXMatrixRotationX(&matR, m_fRotX);
	// << 회전

	D3DXMatrixTranslation(&matT, m_vLocalPos.x, m_vLocalPos.y, m_vLocalPos.z);
	m_matLocalTM = matR * matT;

	m_matWorldTM = m_matLocalTM;
	if (m_pParentWorldTM)
	{
		// 몸통이 아닌 다른 부위일 때
		m_matWorldTM *= *m_pParentWorldTM;
	}

	for each(auto p in m_vecChild)
	{
		// 몸통일 때
		p->Update();
	}
}

void cCubeNode::Render()
{
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorldTM);	// 월드 세팅
	cCubePNT::Render();
	// 몸통 그려짐

	for each(auto p in m_vecChild)
	{
		// child가 있는 경우가 몸통임
		p->Render();
	}
}
