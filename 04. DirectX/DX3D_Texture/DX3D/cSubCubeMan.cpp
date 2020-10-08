#include "stdafx.h"

#include "cBody.h"
#include "cLeftArm.h"
#include "cRightArm.h"
#include "cLeftLeg.h"
#include "cRightLeg.h"
#include "cHead.h"

#include "cSubCubeMan.h"

cSubCubeMan::cSubCubeMan() : m_pRoot(NULL)
{

}

cSubCubeMan::~cSubCubeMan()
{
	if (m_pRoot)
		m_pRoot->Destroy();

	SafeRelease(m_pTexture);
}

void cSubCubeMan::Setup()
{
	cCharacter::Setup();

	ZeroMemory(&m_stMtl, sizeof(D3DMATERIAL9));
	m_stMtl.Ambient = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
	m_stMtl.Diffuse = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
	m_stMtl.Specular = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);

	cBody*	pBody = new cBody;
	pBody->Setup();
	pBody->SetParentWorldTM(&m_matWorld);
	m_pRoot = pBody;

	cHead* pHead = new cHead;
	pHead->Setup();

	m_pRoot->AddChild(pHead);

	cLeftArm* pLArm = new cLeftArm;
	pLArm->Setup();
	pLArm->SetRotDeltaX(0.1f);
	m_pRoot->AddChild(pLArm);

	cRightArm* pRArm = new cRightArm;
	pRArm->Setup();
	pRArm->SetRotDeltaX(-0.1f);
	m_pRoot->AddChild(pRArm);

	cLeftLeg* pLLeg = new cLeftLeg;
	pLLeg->Setup();
	pLLeg->SetRotDeltaX(-0.1f);
	m_pRoot->AddChild(pLLeg);

	cRightLeg* pRLeg = new cRightLeg;
	pRLeg->Setup();
	pRLeg->SetRotDeltaX(0.1f);
	m_pRoot->AddChild(pRLeg);

	D3DXCreateTextureFromFile(g_pD3DDevice, L"../image/mkLink.png", &m_pTexture);
}

void cSubCubeMan::Update()
{
	// cCharacter::Update();

	// if (GetKeyState('A') & 0X8000)
	// {
	// 	m_fRotY -= 0.1f;
	// }
	// if (GetKeyState('D') & 0X8000)
	// {
	// 	m_fRotY += 0.1f;
	// }

	// if (GetKeyState('W') & 0X8000)
	// {
	// 	 m_vPosition += (m_vDirection*0.05f);
	// }
	// if (GetKeyState('S') & 0X8000)
	// {
	// 	m_vPosition -= (m_vDirection*0.1f);
	// }

	// if(m_vPosition <= test)
	// 	m_vPosition += (m_vDirection * 0.01f);
	// else
	// 	iDestSpot = iDestSpot + 1 >= m_vecPath.size() ? 0 : iDestSpot++;

	RECT rc;
	GetClientRect(g_hWnd, &rc);

	D3DXMATRIXA16 matR, matT;
	// D3DXMatrixRotationY(&matR, m_fRotY);	
	D3DXMatrixIdentity(&matR);
	// D3DXMatrixIdentity(&matT);


	 //// >> 시선 예제 코드
	 //D3DXMATRIXA16 matR, matT;
	 //D3DXMatrixIdentity(&matR);
	 //D3DXMatrixIdentity(&matT);
	 //
	 //D3DXVECTOR3 vUp(0, 1, 0);
	 //D3DXVECTOR3 vAt(5, 0, 0);
	 //
	 //D3DXMatrixIdentity(&matR);
	 //D3DXMatrixLookAtLH(&matR, &m_vPosition, &vAt, &vUp);

	 //D3DXMatrixTranspose(&matR, &matR);
	 //// << 시선 예제 코드

	if(m_vPosition.x < 2.0f)
		m_vPosition += (m_vDirection * 0.1f);
		
	m_vDirection = D3DXVECTOR3(1, 0, 0);
	D3DXVec3TransformNormal(&m_vDirection, &m_vDirection, &matR);
	D3DXMatrixTranslation(&matT, m_vPosition.x, m_vPosition.y, m_vPosition.z);

	m_matWorld = matR * matT;

	if (m_pRoot)
		m_pRoot->SubUpdate(); 
}

void cSubCubeMan::Render()
{
	if (g_pD3DDevice)
	{
		g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
		// g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);

		g_pD3DDevice->SetMaterial(&m_stMtl);

		cCharacter::Render();

		D3DXMATRIXA16 matWorld;
		D3DXMatrixIdentity(&matWorld);
		g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

		g_pD3DDevice->SetTexture(0, m_pTexture);

		if (m_pRoot)
			m_pRoot->Render();	// cCubeNode -> Render()

		g_pD3DDevice->SetTexture(0, NULL);
	}
}

void cSubCubeMan::SetUp(vector<ST_PC_VERTEX> path)
{
	Setup();

	m_vecPath = path;
	
	m_vPosition = D3DXVECTOR3(0,0,0);
	iDestSpot = 1;
}
