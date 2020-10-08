#pragma once
#include "stdafx.h"

class cObject
{
private:
	vector<vector<ST_PNT_VERTEX>> m_vecVertex;

	string m_strMtlFileName;

	vector<string> m_vecReadMtlUse;
	vector<int> m_vecMtlUseIndex;

	vector<D3DMATERIAL9> m_vecReadMtrl;
	vector<D3DMATERIAL9> m_vecMtrl;

	vector<string> m_vecReadTexture;
	vector<string> m_vecTextureFilePath;

	LPDIRECT3DTEXTURE9 texture;
	vector<LPDIRECT3DTEXTURE9> m_vecTexture;

public:
	cObject();
	~cObject();

	cObject(string fileName);

	void ReadObjFile(string fName);
	void CheckMtl(string strRead);
	void ParseData(string & strRead, D3DXVECTOR3 & vSet, vector<D3DXVECTOR3> & vecAdd);
	void ParseData(string & strRead, D3DXVECTOR2 & vSet, vector<D3DXVECTOR2> & vecAdd);
	void ParseIndexData(string & strRead, vector<D3DXVECTOR3> & vecP, vector<D3DXVECTOR3> & vecN, vector<D3DXVECTOR2> & vecT, vector<ST_PNT_VERTEX> & vecAdd);
	void Reset(vector<D3DXVECTOR3> &vecP, vector<D3DXVECTOR3> &vecN, vector<D3DXVECTOR2> &vecT, vector<ST_PNT_VERTEX> &vecAdd);

	void ReadMtlFile();

	void SetFilePath(string & str);

	void Render();
};
