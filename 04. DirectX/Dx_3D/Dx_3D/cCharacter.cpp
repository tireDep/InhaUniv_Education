#include "stdafx.h"
#include "cCharacter.h"

cCharacter::cCharacter() :
	m_fRotY(0.0f),
	m_vDirection(0,0,1),
	m_vPosition(0,0,0)
{
	D3DXMatrixIdentity(&m_matWorld);
}

cCharacter::~cCharacter()
{

}

void cCharacter::SetUp()
{

}

void cCharacter::Update()
{
	if (GetKeyState('A') & 0x8000)
		m_fRotY -= 0.1f;
	if (GetKeyState('D') & 0x8000)
		m_fRotY += 0.1f;

	if (GetKeyState('W') & 0x8000)
		m_vPosition += (m_vDirection * 0.1f);
	if (GetKeyState('S') & 0x8000)
		m_vPosition -= (m_vDirection * 0.1f);
	// 이동

	RECT rc;	// 화면 사이즈 변경 x 라면 미리 구해놔도 상관 x
	GetClientRect(g_hWnd, &rc);

	D3DXMATRIXA16 matR, matT;
	D3DXMatrixRotationY(&matR, m_fRotY);

	m_vDirection = D3DXVECTOR3(0, 0, 1);
	D3DXVec3TransformNormal(&m_vDirection, &m_vDirection, &matR);
	D3DXMatrixTranslation(&matT, m_vPosition.x, m_vPosition.y, m_vPosition.z);

	m_matWorld = matR * matT;
	// >> cube Update에서 가져옴
}

void cCharacter::Render()
{

}

D3DXVECTOR3 & cCharacter::GetPosition()
{
	return m_vPosition;
}
