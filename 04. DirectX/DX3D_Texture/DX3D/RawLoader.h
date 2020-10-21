#pragma once
#include "HeightMap.h"

class CRawLoader
{
private:
	int **m_retData;
	int m_index;

	LPDIRECT3DTEXTURE9 m_pTexture;
	vector<ST_PNT_VERTEX> vecVertex;

	IDirect3DVertexBuffer9* m_vB;
	IDirect3DIndexBuffer9* m_iB;
	LPD3DXMESH m_mesh;
	D3DMATERIAL9* m_mtrl;
	int m_numTri;

	Synthesize(int, m_nAttrID, AttrID);

public:
	CRawLoader();
	~CRawLoader();

	// vector<int> LoadHeightMap(char* szFolderPath, char* szFile);
	// int** LoadHeightMap(char* szFolderPath, char* szFile);

	void LoadHeightMap(vector<CHeightMap>& heightMap, char* szFolderPath, char* szFile);

	void Render();

	vector<D3DXVECTOR3> GetVecHeight();
};

