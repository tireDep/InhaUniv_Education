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
};
