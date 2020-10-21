#include "stdafx.h"
#include "RawLoader.h"

CRawLoader::CRawLoader()
{
}

CRawLoader::~CRawLoader()
{
	for (int i = 0; i < m_index; i++)
		delete[] m_retData[i];
	delete[] m_retData;
}

void CRawLoader::LoadHeightMap(vector<CHeightMap>& heightMap,  char * szFolderPath, char * szFile)
{
	D3DXCreateTextureFromFile(g_pD3DDevice, L"./HeightMapData/terrain.jpg", &m_pTexture);

	CHeightMap retMap;
	vector<int> vecHeight;

	// >> readFile
	FILE* fp;
	string filePath = string(szFolderPath) + string("/") + string(szFile);
	fopen_s(&fp, filePath.c_str(), "rb");

	if (fp == NULL)
	{
		MessageBox(g_hWnd, L"RAW FILE OPEN ERROR", L"ERROR", MB_OK);
		exit(1);
	}
	
	int readCh;
	while (true)
	{
		if (feof(fp))
			break;

		readCh = fgetc(fp);
		vecHeight.push_back(readCh);
	}

	fclose(fp);

	m_retData = new int*[pow(vecHeight.size(), 2)];
	
	int index = pow(vecHeight.size(), 0.5);
	m_index = index;

	for (int i = 0; i < index; i++)
	{
		m_retData[i] = new int[index];

		for (int j = 0; j < index; j++)
			m_retData[i][j] = vecHeight[j + (i*index)];	// ÁÂÇ¥ ÁÖÀÇ!
	}
	// << readFile

	vector<D3DXVECTOR3> vV;
	vector<D3DXVECTOR3> vT;
	vector<D3DXVECTOR3> vN;

	for (int j = 0; j < index - 1; j++)
	{
		for (int i = 0; i < index - 1; i++)
		{
			ST_PNT_VERTEX v;
			v.p = D3DXVECTOR3(j + 1, m_retData[j + 1][i] / 5.0f, i);
			v.t = D3DXVECTOR2((j + 1) / (index - 1.0f), (i) / (index - 1.0f));
			v.n = D3DXVECTOR3(0, 1, 0);
			vecVertex.push_back(v);

			v.p = D3DXVECTOR3(j, m_retData[j][i] / 5.0f, i);
			v.t = D3DXVECTOR2((j) / (index - 1.0f), (i) / (index - 1.0f));
			v.n = D3DXVECTOR3(0, 1, 0);
			vecVertex.push_back(v);

			v.p = D3DXVECTOR3(j, m_retData[j][i + 1] / 5.0f, i + 1);
			v.t = D3DXVECTOR2((j) / (index - 1.0f), (i + 1) / (index - 1.0f));
			v.n = D3DXVECTOR3(0, 1, 0);
			vecVertex.push_back(v);

			v.p = D3DXVECTOR3(j + 1, m_retData[j + 1][i] / 5.0f, i);
			v.t = D3DXVECTOR2((j + 1) / (index - 1.0f), (i) / (index - 1.0f));
			v.n = D3DXVECTOR3(0, 1, 0);
			vecVertex.push_back(v);

			v.p = D3DXVECTOR3(j, m_retData[j][i + 1] / 5.0f, i + 1);
			v.t = D3DXVECTOR2((j) / (index - 1.0f), (i + 1) / (index - 1.0f));
			v.n = D3DXVECTOR3(0, 1, 0);
			vecVertex.push_back(v);

			v.p = D3DXVECTOR3(j + 1, m_retData[j + 1][i + 1] / 5.0f, i + 1);
			v.t = D3DXVECTOR2((j + 1) / (index - 1.0f), (i + 1) / (index - 1.0f));
			v.n = D3DXVECTOR3(0, 1, 0);
			vecVertex.push_back(v);
		}
	}
}

void CRawLoader::Render()
{
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);

	// g_pD3DDevice->SetMaterial(&m_mtrl);
	g_pD3DDevice->SetTexture(0, m_pTexture);

	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);

	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetFVF(ST_PNT_VERTEX::FVF);

	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, vecVertex.size() / 3, &vecVertex[0], sizeof(ST_PNT_VERTEX));

	g_pD3DDevice->SetTexture(0, NULL);
}
