#pragma once
#include "stdafx.h"
#include "cCharObj.h"
#include "cMtlTex.h"

class cCharObjGroup : public cCharObj
{
private:
	int m_firstFrame;
	int m_lastFrame;
	int m_frameSpeed;
	// scene

	int m_textureIndex;
	// texture

	string m_nodeName;
	D3DXMATRIXA16 m_matWorld;
	// node

	Synthesize_Pass_by_Ref(vector<ST_PNT_VERTEX>, m_vecVertex, Vertex);
	Synthesize_Add_Ref(cMtlTex*, m_pMtlTex, MtlTex);

public:
	cCharObjGroup();
	~cCharObjGroup();

	void Render();

	void SetNodeName(string set);
	void SetTextureIndex(int set);
	void SetWorldMatrix(vector<D3DXVECTOR3> vecTempMat);

	string GetNodeName();
	int GetTextureIndex();
};