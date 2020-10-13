#pragma once
#include "stdafx.h"
#include "cMtlTex.h"
#include "cObject.h"

class cGeoObject : public cObject
{
	Synthesize_Pass_by_Ref(D3DXMATRIXA16, m_matWorld, MatWorld);
	Synthesize_Pass_by_Ref(D3DXMATRIXA16, m_matLocal, MatLocal);
	Synthesize_Pass_by_Ref(vector<ST_PNT_VERTEX>, m_vecVertex, Vertex);
	Synthesize_Add_Ref(cMtlTex*, m_pMtrlTex, MtrlTex);

private:
	vector<cGeoObject*> m_vecChild;
	string m_sName;

public:
	cGeoObject();
	~cGeoObject();

	void Render();

	cGeoObject* GetMyParents(string sParentName);
	bool AddChild(cGeoObject* pChild);
	void SetName(string name);

	void CalcLocalMat(cGeoObject* pParent);
};
