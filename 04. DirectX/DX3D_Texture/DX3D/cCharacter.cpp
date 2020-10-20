#include "stdafx.h"
#include "cCharacter.h"


cCharacter::cCharacter()
	: m_fRotY(0.0f)
	, m_vDirection(0,0,1)
	, m_vPosition(0,0,0)
{
	D3DXMatrixIdentity(&m_matWorld); 
}


cCharacter::~cCharacter()
{
}

void cCharacter::Setup()
{
}

void cCharacter::Update(iMap *pMap)
{
	m_pMap = pMap;

	if (GetKeyState('A') & 0X8000)
	{
		m_fRotY -= 0.1f;
	}
	if (GetKeyState('D') & 0X8000)
	{
		m_fRotY += 0.1f;
	}

	D3DXVECTOR3 vPosition = m_vPosition;

	if (GetKeyState('W') & 0X8000)
	{
		// m_vPosition += (m_vDirection*0.1f);
		vPosition = m_vPosition + (m_vDirection*0.1f);
	}
	if (GetKeyState('S') & 0X8000)
	{
		// m_vPosition -= (m_vDirection*0.1f);
		vPosition = m_vPosition - (m_vDirection*0.1f);
	}

	D3DXMATRIXA16 matR, matT;
	D3DXMatrixRotationY(&matR, m_fRotY);

	// if (pMap)
	// {
	// 	if (pMap->GetHeight(vPosition.x, vPosition.y, vPosition.z))
	// 	{
	// 		if(vPosition.y -  m_vPosition.y < 2.0f)
	// 			m_vPosition = vPosition;
	// 	}
	// }
	// >> �ٴ� üũ

	m_vPosition = vPosition;

	m_vDirection = D3DXVECTOR3(0, 0, 1);
	D3DXVec3TransformNormal(&m_vDirection, &m_vDirection, &matR);
	D3DXMatrixTranslation(&matT, m_vPosition.x, m_vPosition.y + 1.0f, m_vPosition.z);

	m_matWorld = matR * matT;
}

void cCharacter::Render()
{
}

D3DXVECTOR3 & cCharacter::GetPosition()
{
	return m_vPosition; 
}
