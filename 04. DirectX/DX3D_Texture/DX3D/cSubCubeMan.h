#pragma once
#include "stdafx.h"
#include "cCharacter.h"
class cCubeNode;

class cSubCubeMan : public cCharacter
{
protected:
	cCubeNode*			m_pRoot;
	D3DMATERIAL9		m_stMtl;

	LPDIRECT3DTEXTURE9		m_pTexture;

	// >> 경로 설정
	vector<ST_PC_VERTEX> m_vecPath;
	int iDestSpot;
	// << 경로 설정

public:
	cSubCubeMan();

	virtual ~cSubCubeMan();

	virtual void Setup() override;
	virtual void Update() override;
	virtual void Render() override;

	void SetUp(vector<ST_PC_VERTEX> path);
};