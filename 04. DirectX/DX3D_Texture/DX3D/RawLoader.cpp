#include "stdafx.h"
#include "RawLoader.h"

CRawLoader::CRawLoader() : 
	m_vB(NULL),
	m_iB(NULL),
	m_mtrl(NULL)
	
{
}

CRawLoader::~CRawLoader()
{
	for (int i = 0; i < m_index; i++)
		delete[] m_retData[i];
	delete[] m_retData;

	SafeRelease(m_vB);
	SafeRelease(m_iB);

	SafeDelete(m_mtrl);
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
			m_retData[i][j] = vecHeight[j + (i*index)];	// 좌표 주의!
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

	//// >> vertexBuffer 
	//m_numTri = vecVertex.size() / 3;
	//g_pD3DDevice->CreateVertexBuffer(vecVertex.size() * sizeof(ST_PNT_VERTEX),
	//							   	0,
	//							   	ST_PNT_VERTEX::FVF,
	//							   	D3DPOOL_MANAGED,
	//							   	&m_vB,
	//							   	NULL);

	//ST_PNT_VERTEX* pV = NULL;
	//m_vB->Lock(0, 0, (LPVOID*)&pV, 0);
	//memcpy(pV, &vecVertex[0], vecVertex.size() * sizeof(ST_PNT_VERTEX));
	//m_vB->Unlock();
	//// << vertexBuffer

	//// >> indexBuffer
	//g_pD3DDevice->CreateIndexBuffer(vecVertex.size() * sizeof(WORD),
	//	D3DUSAGE_WRITEONLY,
	//	D3DFMT_INDEX16,
	//	D3DPOOL_MANAGED,
	//	&m_iB,
	//	NULL);

	//vector<WORD> vIndex;
	//for (int i = 0; i < vecVertex.size(); i++)
	//	vIndex.push_back(i);


	//WORD* pW = NULL;
	//m_iB->Lock(0, 0, (void**)&pW, 0);
	//memcpy(pW, &vIndex[0], vecVertex.size() * sizeof(WORD));
	//m_iB->Unlock();
	//// << indexBuffer

	vector<DWORD> vecAttrBuf;
	for (int i = 0; i < vecVertex.size(); i++)
		vecAttrBuf.push_back(0);
	// 임시 Mtrl
	
	int divideNum = 9;	// size가 너무 커서 메쉬 생성되지 x
	D3DXCreateMeshFVF(vecAttrBuf.size() / divideNum,
		vecVertex.size() / divideNum,
		D3DXMESH_MANAGED,
		ST_PNT_VERTEX::FVF,
		g_pD3DDevice, &m_mesh);

	ST_PNT_VERTEX* pV = NULL;
	m_mesh->LockVertexBuffer(0, (LPVOID*)&pV);
	memcpy(pV, &vecVertex[0], vecVertex.size() / divideNum * sizeof(ST_PNT_VERTEX));
	// memcpy(pV, &vecVertex[vecVertex.size() / divideNum - 1], vecVertex.size() / divideNum * sizeof(ST_PNT_VERTEX));
	// 다음 구역
	m_mesh->UnlockVertexBuffer();

	WORD* pI = NULL;
	m_mesh->LockIndexBuffer(0, (LPVOID*)&pI);
	for (int i = 0; i < vecVertex.size() / divideNum; i++)
		pI[i] = i;
	// int j = 0;
	// for (int i = vecVertex.size() / divideNum; i < vecVertex.size() / divideNum * 3 ; i++)
	// 	pI[j++] = i;
	// 다음 구역
	m_mesh->UnlockIndexBuffer();

	DWORD* pA = NULL;
	m_mesh->LockAttributeBuffer(0, &pA);
	memcpy(pA, &vecAttrBuf[0], vecAttrBuf.size() / divideNum * sizeof(DWORD));
	// memcpy(pA, &vecAttrBuf[vecVertex.size() / divideNum - 1], vecAttrBuf.size() / divideNum * sizeof(DWORD));
	// 다음 구역
	m_mesh->UnlockAttributeBuffer();

	// 최적화
	vector<DWORD> vecAdj(vecVertex.size());
	m_mesh->GenerateAdjacency(0.0f, &vecAdj[0]);
	m_mesh->OptimizeInplace(D3DXMESHOPT_ATTRSORT |
							D3DXMESHOPT_COMPACT |
							D3DXMESHOPT_VERTEXCACHE,
							&vecAdj[0],0,0,0);
}

void CRawLoader::Render()
{
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);

	// g_pD3DDevice->SetMaterial(m_mtrl);
	g_pD3DDevice->SetTexture(0, m_pTexture);

	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);
	//D3DXMatrixScaling(&matWorld, 0.1f, 0.1f, 0.1f);
	D3DXMatrixTranslation(&matWorld, -5.0f, 0.0f, 0.0f);

	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetFVF(ST_PNT_VERTEX::FVF);

	// g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, vecVertex.size() / 3, &vecVertex[0], sizeof(ST_PNT_VERTEX));
	//
	// g_pD3DDevice->SetStreamSource(0, m_vB, 0, sizeof(ST_PNT_VERTEX));
	// g_pD3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, m_numTri);
	//
	// g_pD3DDevice->SetStreamSource(0, m_vB, 0, sizeof(ST_PNT_VERTEX));
	// g_pD3DDevice->SetIndices(m_iB);
	// g_pD3DDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, vecVertex.size(), 0, vecVertex.size()/3);

	m_mesh->DrawSubset(0);

	g_pD3DDevice->SetTexture(0, NULL);

	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
}

vector<D3DXVECTOR3> CRawLoader::GetVecHeight()
{
	vector<D3DXVECTOR3> retVec;
	for (int i = 0; i < vecVertex.size(); i++)
	{
		retVec.push_back(vecVertex[i].p);
	}
	return retVec;
}
