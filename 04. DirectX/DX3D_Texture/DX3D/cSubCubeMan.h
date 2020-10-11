#pragma once
#include "stdafx.h"
#include "cCharacter.h"

class cCubeNode;

class cSubCubeMan : public cCharacter
{
public:
	int idestIndex;

	cSubCubeMan();

protected:
	cCubeNode*			m_pRoot;
	D3DMATERIAL9		m_stMtl;

	LPDIRECT3DTEXTURE9		m_pTexture;

public:
	virtual ~cSubCubeMan();

	virtual void Setup() override;
	virtual void Update() override;
	void Update_Path(vector<ST_PC_VERTEX> path);
	virtual void Render() override;
};

