#pragma once
#include "stdafx.h"
#include "cCubePNT.h"

class cCubeNode : public cCubePNT
{
private:


protected:
	D3DXVECTOR3 m_vLocalPos;	// 부모 위치에서 난 어디 있느지
	D3DXMATRIXA16 m_matLocalTM;
	D3DXMATRIXA16 m_matWorldTM;
	std::vector<cCubeNode *> m_vecChild;

	Synthesize(D3DXMATRIXA16*, m_pParentWorldTM, ParentWorldTM);

	float m_fRotX;	// 회전
	Synthesize(float, m_fRotDeleaX, RotDeltaX);

public:
	cCubeNode();
	virtual ~cCubeNode(void);

	virtual void AddChild(cCubeNode* pChild);
	virtual void Destory();

	virtual void SetUp() override;
	virtual void Update() override;
	virtual void Render() override;
};