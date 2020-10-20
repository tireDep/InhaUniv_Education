#include "stdafx.h"
#include "cCharacter.h"

#include "CMouse.h"

cCharacter::cCharacter()
	: m_fRotY(0.0f)
	, m_vDirection(0,0,1)
	, m_vPosition(0,0,0)
	, m_destPos(0, 0, 0)
	, m_isMoving(false)
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

	funcPtr = CMouse::CallFunc;
	m_destPos = funcPtr(D3DXVECTOR3(1, 1, 1));

	if (!m_isMoving && m_destPos.x < 9999 && m_destPos.y < 9999 && m_destPos.z < 9999)
	{
		// m_isMoving = true;
		// m_vDirection = m_destPos;
		m_vPosition = m_destPos;
		m_destPos = D3DXVECTOR3(9999, 9999, 9999);
	}
	// else if(m_destPos.x == m_vDirection.x && m_destPos.z == m_vDirection.z)
	// {
	// 	m_isMoving = false;
	// 	m_vDirection = D3DXVECTOR3(0, 0, 0);
	// }

	// if (GetKeyState('A') & 0X8000)
	// {
	// 	m_fRotY -= 0.1f;
	// }
	// if (GetKeyState('D') & 0X8000)
	// {
	// 	m_fRotY += 0.1f;
	// }
	// 
	// D3DXVECTOR3 vPosition = m_vPosition;
	// 
	// if (GetKeyState('W') & 0X8000)
	// {
	// 	// m_vPosition += (m_vDirection*0.1f);
	// 	vPosition = m_vPosition + (m_vDirection*0.1f);
	// }
	// if (GetKeyState('S') & 0X8000)
	// {
	// 	// m_vPosition -= (m_vDirection*0.1f);
	// 	vPosition = m_vPosition - (m_vDirection*0.1f);
	// }

	// m_vPosition = m_vDirection;

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
	// >> ¹Ù´Ú Ã¼Å©

	// m_vPosition = vPosition;

	m_vDirection = D3DXVECTOR3(0, 0, 1);
	D3DXVec3TransformNormal(&m_vDirection, &m_vDirection, &matR);
	D3DXMatrixTranslation(&matT, m_vPosition.x, m_vPosition.y + 1.0f, m_vPosition.z);
	// D3DXMatrixTranslation(&matT, m_destPos.x, m_destPos.y + 1.0f, m_destPos.z);

	m_matWorld = matR * matT;
}

void cCharacter::Render()
{
}

D3DXVECTOR3 & cCharacter::GetPosition()
{
	return m_vPosition; 
}

// void cCharacter::SetDestPos(cCharacter& character)
// {
// 	
// }

// void cCharacter::CallFunc(m_pFunc func)
// {
// 	pFunc = func;
// 
// 	pFunc();
// }
