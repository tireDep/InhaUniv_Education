#include "stdafx.h"
#include "cCubeMan.h"

#include "cBody.h"
#include "cHead.h"
#include "cLeftArm.h"
#include "cRightArm.h"
#include "cLeftLeg.h"
#include "cRightLeg.h"

cCubeMan::cCubeMan() :
	m_pRoot(NULL)
{

}

cCubeMan::~cCubeMan()
{
	if (m_pRoot)
		m_pRoot->Destory();
}

void cCubeMan::SetUp()
{
	cCharacter::SetUp();

	ZeroMemory(&m_stMtl, sizeof(D3DMATERIAL9));
	m_stMtl.Ambient = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
	m_stMtl.Diffuse = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
	m_stMtl.Specular = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);

	cBody* pBody = new cBody;	// 몸통 최상위
	pBody->SetUp();
	pBody->SetParentWorldTM(&m_matWorld);
	m_pRoot = pBody;

	cHead* pHead = new cHead;
	pHead->SetUp();
	m_pRoot->AddChild(pHead);

	cLeftArm* pLArm = new cLeftArm;
	pLArm->SetUp();
	pLArm->SetRotDeltaX(0.1f); // 회전
	m_pRoot->AddChild(pLArm);

	cRightArm* pRArm = new cRightArm;
	pRArm->SetUp();
	pRArm->SetRotDeltaX(-0.1f); // 회전
	m_pRoot->AddChild(pRArm);

	cLeftLeg* pLLeg = new cLeftLeg;
	pLLeg->SetUp();
	pLLeg->SetRotDeltaX(-0.1f); // 회전
	m_pRoot->AddChild(pLLeg);

	cRightLeg* pRLeg = new cRightLeg;
	pRLeg->SetUp();
	pRLeg->SetRotDeltaX(0.1f); // 회전
	m_pRoot->AddChild(pRLeg);
}

void cCubeMan::Update()
{
	cCharacter::Update();
	if (m_pRoot)
		m_pRoot->Update();
}

void cCubeMan::Render()
{
	if (g_pD3DDevice)
	{
		g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);	// 조명
		g_pD3DDevice->SetMaterial(&m_stMtl);

		cCharacter::Render();
		D3DXMATRIXA16 matWorld;
		D3DXMatrixIdentity(&matWorld);
		g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

		if (m_pRoot)
			m_pRoot->Render();
	}
}
