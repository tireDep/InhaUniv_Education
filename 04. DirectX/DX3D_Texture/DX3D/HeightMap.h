#pragma once
class CHeightMap
{
private:
	vector<ST_PNT_VERTEX> m_vecVertex;

	LPDIRECT3DTEXTURE9 m_pTexture;
	D3DMATERIAL9 m_mtrl;

public:
	CHeightMap();
	~CHeightMap();

	void SetUp(IN int** heightArr);

	void Render();
};

