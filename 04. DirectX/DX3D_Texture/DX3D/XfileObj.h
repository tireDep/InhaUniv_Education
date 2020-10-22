#pragma once
class CXfileObj
{
private:
	ID3DXBuffer* m_pXBuffer;
	ID3DXBuffer* m_pMtlXBuffer;
	DWORD m_nMtlNum;
	ID3DXMesh* m_pMesh;

	// ---------------------
	ID3DXBuffer* m_adjBuffer;
	ID3DXBuffer* m_mtrlBuffer;
	// ID3DXMesh* m_pMesh;
	vector<D3DMATERIAL9> m_vecMtl;
	vector<IDirect3DTexture9*> m_vecTxt;

public:
	CXfileObj();
	~CXfileObj();

	void LoadXFile(char* szFolder, char* szFile);

	void Render();
};

