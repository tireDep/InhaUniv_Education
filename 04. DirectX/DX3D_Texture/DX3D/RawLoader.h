#pragma once
#include "HeightMap.h"

class CRawLoader
{
private:
	int **m_retData;
	int m_index;

	LPDIRECT3DTEXTURE9 m_pTexture;
	vector<ST_PNT_VERTEX> vecVertex;

public:
	CRawLoader();
	~CRawLoader();

	// vector<int> LoadHeightMap(char* szFolderPath, char* szFile);
	// int** LoadHeightMap(char* szFolderPath, char* szFile);

	void LoadHeightMap(vector<CHeightMap>& heightMap, char* szFolderPath, char* szFile);

	void Render();
};

