#pragma once
#include "stdafx.h"

// ĳ���� ����
// ĳ���� ȸ����, ��ġ, ���� ��Ʈ���� ��
class cCharacter
{
private:


protected:
	float m_fRotY;
	D3DXVECTOR3 m_vDirection;
	D3DXVECTOR3 m_vPosition;

	D3DXMATRIXA16 m_matWorld;

public:
	cCharacter();
	virtual ~cCharacter();

	virtual void SetUp();
	virtual void Update();
	virtual void Render();

	virtual D3DXVECTOR3& GetPosition();

};