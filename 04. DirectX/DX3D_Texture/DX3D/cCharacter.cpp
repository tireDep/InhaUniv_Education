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

void cCharacter::Update()
{
	if (GetKeyState('A') & 0X8000)
	{
		m_fRotY -= 0.1f;
	}
	if (GetKeyState('D') & 0X8000)
	{
		m_fRotY += 0.1f;
	}

	if (GetKeyState('W') & 0X8000)
	{
		m_vPosition += (m_vDirection*0.1f);
	}
	if (GetKeyState('S') & 0X8000)
	{
		m_vPosition -= (m_vDirection*0.1f);
	}

	RECT rc;
	GetClientRect(g_hWnd, &rc);

	D3DXMATRIXA16 matR, matT;
	D3DXMatrixRotationY(&matR, m_fRotY);

	m_vDirection = D3DXVECTOR3(0, 0, 1);
	D3DXVec3TransformNormal(&m_vDirection, &m_vDirection, &matR);
	D3DXMatrixTranslation(&matT, m_vPosition.x, m_vPosition.y, m_vPosition.z);

	m_matWorld = matR * matT;
}

void cCharacter::Update_Sub(vector<ST_PC_VERTEX> path, int &destNum)
{
	// D3DXMATRIXA16 matR, matT;
	// D3DXMatrixRotationY(&matR, m_fRotY);
	// 
	// m_vDirection = D3DXVECTOR3(0, 0, 1);
	// D3DXVec3TransformNormal(&m_vDirection, &m_vDirection, &matR);
	// D3DXMatrixTranslation(&matT, m_vPosition.x, m_vPosition.y, m_vPosition.z);
	// 
	// m_matWorld = matR * matT;

	D3DXMATRIXA16 matR, matT;

	if (sqrt(pow(path[destNum].p.x - m_vPosition.x, 2) + pow(path[destNum].p.z - m_vPosition.z, 2)) < 0.1f)
	{
		destNum = destNum + 1 < path.size() ? destNum += 1 : 0;

		D3DXVECTOR3 vUp(0, 1, 0);
		D3DXMatrixLookAtLH(&matR, &m_vPosition, &path[destNum].p, &vUp);
		D3DXMatrixTranspose(&matR, &matR);

		D3DXVECTOR3 direction = D3DXVECTOR3(0, 0, 1);
		D3DXVec3TransformNormal(&direction, &direction, &matR);
		D3DXVec3Normalize(&direction, &direction);

		m_fRotY += abs(acosf(D3DXVec3Dot(&m_vDirection, &direction)));

		m_vDirection = direction;
	}
	else
	{
		m_vPosition += m_vDirection * 0.1f;
	}

	D3DXMatrixTranslation(&matT, m_vPosition.x, m_vPosition.y, m_vPosition.z);
	D3DXMatrixRotationY(&matR, m_fRotY);

	m_matWorld = matR * matT;
}

void cCharacter::Render()
{
}

D3DXVECTOR3 & cCharacter::GetPosition()
{
	return m_vPosition; 
}
