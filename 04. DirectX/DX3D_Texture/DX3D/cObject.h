#pragma once
#include "stdafx.h"

class cObject
{
private:
	vector<vector<ST_PNT_VERTEX>> m_vecVertex;

	string m_strMtrl;
	string m_strMtrlSet;

public:
	cObject();
	~cObject();

	void ReadFileData();

	void ReadObjFile();
	void CheckMtrl(string strRead);
	void ParseData(string & strRead, D3DXVECTOR3 & vSet, vector<D3DXVECTOR3> & vecAdd);
	void ParseData(string & strRead, D3DXVECTOR2 & vSet, vector<D3DXVECTOR2> & vecAdd);
	void ParseIndexData(string & strRead, vector<D3DXVECTOR3> & vecP, vector<D3DXVECTOR3> & vecN, vector<D3DXVECTOR2> & vecT, vector<ST_PNT_VERTEX> & vecAdd);
	void Reset(vector<D3DXVECTOR3> &vecP, vector<D3DXVECTOR3> &vecN, vector<D3DXVECTOR2> &vecT, vector<ST_PNT_VERTEX> &vecAdd);

};
