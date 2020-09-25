#pragma once
#include "stdafx.h"

class cCubePC
{
private:
	vector<stPC_Vertex> m_VecVertex;
	float				m_fRotY;
	D3DXVECTOR3			m_vDirection;
	D3DXVECTOR3			m_vPosition;
	D3DXMATRIXA16		m_matWorld;

public:
	cCubePC();
	~cCubePC();

	void SetUp();
	void Update();
	void Render();

	D3DXVECTOR3& GetPosition();
};