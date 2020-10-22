#include "stdafx.h"
#include "XfileObj.h"


CXfileObj::CXfileObj() :
	m_pXBuffer(NULL),
	m_pMtlXBuffer(NULL),
	m_pMesh(NULL),
	m_nMtlNum(0),
	m_adjBuffer(NULL),
	m_mtrlBuffer(NULL)
{
}


CXfileObj::~CXfileObj()
{
	SafeRelease(m_pXBuffer);
	SafeRelease(m_pMtlXBuffer);
	SafeRelease(m_pMesh);

	SafeRelease(m_adjBuffer);
	SafeRelease(m_mtrlBuffer);
}

void CXfileObj::LoadXFile(char * szFolder, char * szFile)
{
	// D3DXLoadMeshFromXA(szFile,
	// 	D3DXMESH_MANAGED | D3DXMESH_32BIT | D3DXMESH_WRITEONLY | D3DXMESH_DYNAMIC,
	// 	// �޽��� ���� �޸� Ǯ ���� ���� | 32 ��Ʈ �ε��� ��� | ���⸸ ��� | ���� ����
	// 	g_pD3DDevice,
	// 	&m_pXBuffer,
	// 	&m_pMtlXBuffer,
	// 	0,
	// 	&m_nMtlNum,
	// 	&m_pMesh);

	string filePath = string(szFolder) + "/" + string(szFile);
	// >> ���� ����
	HRESULT hr = 0;
	D3DXLoadMeshFromXA(filePath.c_str(),
		D3DXMESH_MANAGED,
		g_pD3DDevice,
		&m_adjBuffer,
		&m_mtrlBuffer,
		0,
		&m_nMtlNum,
		&m_pMesh);

	if (FAILED(hr))
	{
		MessageBox(g_hWnd, L"XFile Open Error", L"ERROR", MB_OK);
		return;
	}
	// << ���� ����

	// >> ���� ����, �ؽ��� �ε�
	if (m_mtrlBuffer != 0 && m_nMtlNum != 0)
	{
		D3DXMATERIAL* mtrls = (D3DXMATERIAL*)m_mtrlBuffer->GetBufferPointer();

		for (int i = 0; i < m_nMtlNum; i++)
		{
			mtrls[i].MatD3D.Ambient = mtrls[i].MatD3D.Diffuse;
			// MatD3D �Ӽ��� �ε�� �� ambient ���� ������ �����Ƿ� ���� �̸� ����
			
			m_vecMtl.push_back(mtrls[i].MatD3D);
			// i��° ���� ����

			// i��° ������ ����� �ؽ��İ� �ִ����� Ȯ��
			if (mtrls[i].pTextureFilename != 0)
			{
				IDirect3DTexture9* tex = 0;
				string txtFilePath = string(szFolder) + ("/") + string(mtrls[i].pTextureFilename);
				D3DXCreateTextureFromFileA(g_pD3DDevice, txtFilePath.c_str(), &tex);
				// ���� �׷��ٸ� i��° ������� ���� �ؽ�ó �ε�

				m_vecTxt.push_back(tex);
				// �о���� �ؽ�ó ����
			}
			else
			{
				// i��° ����¿� �ؽ��İ� ����
				m_vecTxt.push_back(0);
			}
		}

		SafeRelease(m_mtrlBuffer);	// �۾� �Ϸ�
	}
	// << ���� ����, �ؽ��� �ε�
}

void CXfileObj::Render()
{
	if (g_pD3DDevice)
	{
		D3DXMATRIXA16 matWorld;
		// D3DXMatrixIdentity(&matWorld);
		D3DXMatrixScaling(&matWorld, 5.0f, 5.0f, 5.0f);
		// D3DXMatrixTranslation(&matWorld, 0.0f, 10.0f, 0.0f);

		g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

		for (int i = 0; i < m_vecMtl.size(); i++)
		{
			g_pD3DDevice->SetMaterial(&m_vecMtl[i]);
			g_pD3DDevice->SetTexture(0, m_vecTxt[i]);
			m_pMesh->DrawSubset(i);
		}
	}
}
