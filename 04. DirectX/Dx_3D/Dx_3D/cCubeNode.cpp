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
	// ���� ����
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

	// >> ȸ��
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
	// << ȸ��

	D3DXMATRIXA16 matR, matT;
	D3DXMatrixIdentity(&matR);
	D3DXMatrixIdentity(&matT);

	// >> ȸ��
	D3DXMatrixRotationX(&matR, m_fRotX);
	// << ȸ��

	D3DXMatrixTranslation(&matT, m_vLocalPos.x, m_vLocalPos.y, m_vLocalPos.z);
	m_matLocalTM = matR * matT;

	m_matWorldTM = m_matLocalTM;
	if (m_pParentWorldTM)
	{
		// ������ �ƴ� �ٸ� ������ ��
		m_matWorldTM *= *m_pParentWorldTM;
	}

	for each(auto p in m_vecChild)
	{
		// ������ ��
		p->Update();
	}
}

void cCubeNode::Render()
{
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorldTM);	// ���� ����
	cCubePNT::Render();
	// ���� �׷���

	for each(auto p in m_vecChild)
	{
		// child�� �ִ� ��찡 ������
		p->Render();
	}
}
