#pragma once
#include "cMtlTex.h"
#include "cObject.h"

// * : ���¸� ����, �������� �ε�� �δ����� �����
class cFrame : public cObject
{
private:
	Synthesize_Pass_by_Ref(vector<ST_PNT_VERTEX>, m_vecVertex, Vertex);
	Synthesize_Pass_by_Ref(D3DXMATRIXA16, m_matWorldTM, WorldTM);
	Synthesize_Pass_by_Ref(D3DXMATRIXA16,m_matLocalTM, LocalTM);

	Synthesize_Add_Ref(cMtlTex *, m_pMtlTex, MtlTex);

	vector<cFrame*> m_vecChild;

public:
	cFrame();
	~cFrame();

	void Update(int nKeyFrame, D3DXMATRIXA16* pMatParent);
	void Render();
	void AddChild(cFrame* pChild);
	void Destroy();
	void CalcOriginalLocalTM(D3DXMATRIXA16* pMatParent);

};
