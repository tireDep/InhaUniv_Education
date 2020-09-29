#pragma once
#include "stdafx.h"
#include "cCubeNode.h"
#include "cCharacter.h"

class cCubeMan : public cCharacter
{
private:

protected:
	cCubeNode* m_pRoot;
	D3DMATERIAL9 m_stMtl;

public:
	cCubeMan();
	virtual ~cCubeMan();

	virtual void SetUp() override;
	virtual void Update() override;
	virtual void Render() override;
};
