#include "stdafx.h"
#include "cCharacter.h"

#define dSpeed 5.0f

cCharacter::cCharacter()
	: m_fRotY(0.0f)
	, m_vDirection(0,0,1)
	, m_vPosition(0,1,0)
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
		m_fRotY -= dSpeed * dTimer->DeltaTime();
	}
	if (GetKeyState('D') & 0X8000)
	{
		m_fRotY += dSpeed * dTimer->DeltaTime();
	}

	// D3DXVECTOR3 pos = m_vPosition;
	if (GetKeyState('W') & 0X8000)
	{
		m_vPosition += (m_vDirection * dSpeed) * dTimer->DeltaTime();
		// pos = m_vPosition + (m_vDirection * dSpeed) * dTimer->DeltaTime();
	}
	if (GetKeyState('S') & 0X8000)
	{
		m_vPosition -= (m_vDirection * dSpeed) * dTimer->DeltaTime();
		// pos = m_vPosition - (m_vDirection * dSpeed) * dTimer->DeltaTime();
	}

	D3DXMATRIXA16 matR, matT;
	D3DXMatrixRotationY(&matR, m_fRotY);

	// // >> 시선 예제 코드
	// D3DXMATRIXA16 matR, matT;
	// 
	// D3DXVECTOR3 vUp(0, 1, 0);
	// D3DXVECTOR3 vAt(1, 0, 1);
	// 
	// D3DXMatrixIdentity(&matR);
	// D3DXMatrixLookAtLH(&matR, &m_vPosition, &vAt, &vUp);
	// D3DXMatrixTranspose(&matR, &matR);
	// // << 시선 예제 코드

	// if (pMap)
	// {
	// 	if (pMap->GetHeight(pos.x, pos.y, pos.z))
	// 	{
	// 		m_vPosition = pos;
	// 	}
	// }

	m_vDirection = D3DXVECTOR3(0, 0, 1);
	D3DXVec3TransformNormal(&m_vDirection, &m_vDirection, &matR);
	D3DXMatrixTranslation(&matT, m_vPosition.x, m_vPosition.y + 1.0f, m_vPosition.z);

	m_matWorld = matR * matT;
}

void cCharacter::Update(iMap *pMap)
{
	if (GetKeyState('A') & 0X8000)
	{
		m_fRotY -= dSpeed * dTimer->DeltaTime();
	}
	if (GetKeyState('D') & 0X8000)
	{
		m_fRotY += dSpeed * dTimer->DeltaTime();
	}

	D3DXVECTOR3 pos = m_vPosition;
	if (GetKeyState('W') & 0X8000)
	{
		pos = m_vPosition + (m_vDirection * dSpeed) * dTimer->DeltaTime();
	}
	if (GetKeyState('S') & 0X8000)
	{
		pos = m_vPosition - (m_vDirection * dSpeed) * dTimer->DeltaTime();
	}

	D3DXMATRIXA16 matR, matT;
	D3DXMatrixRotationY(&matR, m_fRotY);

	if (pMap)
	{
		if (pMap->GetHeight(pos.x, pos.y, pos.z))
		{
			if(pos.y - m_vPosition.y < 3)
				m_vPosition = pos;	// 계단 판정
		}
	}

	m_vDirection = D3DXVECTOR3(0, 0, 1);
	D3DXVec3TransformNormal(&m_vDirection, &m_vDirection, &matR);
	D3DXMatrixTranslation(&matT, m_vPosition.x, m_vPosition.y + 1.0f, m_vPosition.z);

	m_matWorld = matR * matT;
}

void cCharacter::Update_Sub(vector<ST_PC_VERTEX> path, int &destNum)
{
	D3DXMATRIXA16 matR, matT;
	D3DXMatrixIdentity(&matR);

	if (sqrt(pow(path[destNum].p.x - m_vPosition.x, 2) + pow(path[destNum].p.z - m_vPosition.z, 2)) < 0.1f)
	{
		destNum = destNum + 1 < path.size() ? destNum+=1 : 0;

		D3DXVECTOR3 vUp(0, 1, 0);
		D3DXMatrixLookAtLH(&matR, &m_vPosition, &path[destNum].p, &vUp);
		D3DXMatrixTranspose(&matR, &matR);

		D3DXVECTOR3 direction = D3DXVECTOR3(0, 0, 1);
		D3DXVec3TransformNormal(&direction, &direction, &matR);
		D3DXVec3Normalize(&direction, &direction);

		m_fRotY += abs(acosf(D3DXVec3Dot(&direction, &m_vDirection)));

		m_vDirection = direction;
	}
	else
	{
		m_vPosition += m_vDirection * dSpeed * 0.5f * dTimer->DeltaTime();
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

void cCharacter::SetMap(vector<ST_PNT_VERTEX> set)
{
	m_vecMap = set;
}

bool cCharacter::Collision_Btm(D3DXVECTOR3 center)
{
	D3DXVECTOR3 rayPos(center.x, center.y + 1.0f, center.z);
	D3DXVECTOR3 rayDir(0, -1, 0);
	float vU = 0, vV = 0, fDist = 0;

	for (int i = 0; i < m_vecMap.size(); i += 3)
	{
		if (D3DXIntersectTri(&m_vecMap[i + 0].p, &m_vecMap[i + 1].p, &m_vecMap[i + 2].p,
			&rayPos, &rayDir, &vU, &vV, &fDist))
		{
			// D3DXMATRIXA16 matWorld, matR;
			// D3DXMatrixRotationX(&matR, -D3DX_PI / 2.0f);
			// D3DXVec3TransformNormal(&m_vPosition, &m_vPosition, &matR);

			m_vPosition = rayPos + (fDist * rayDir);
			// m_vPosition.y += 1.0f - fDist;
			
			return true;
		}
	}
	return false;
}
