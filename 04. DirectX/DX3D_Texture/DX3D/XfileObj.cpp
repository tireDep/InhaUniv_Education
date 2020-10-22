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
	// 	// 메쉬가 관리 메모리 풀 내에 보관 | 32 비트 인덱스 사용 | 쓰기만 허용 | 동적 생성
	// 	g_pD3DDevice,
	// 	&m_pXBuffer,
	// 	&m_pMtlXBuffer,
	// 	0,
	// 	&m_nMtlNum,
	// 	&m_pMesh);

	string filePath = string(szFolder) + "/" + string(szFile);
	// >> 파일 열기
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
	// << 파일 열기

	// >> 재질 추출, 텍스쳐 로드
	if (m_mtrlBuffer != 0 && m_nMtlNum != 0)
	{
		D3DXMATERIAL* mtrls = (D3DXMATERIAL*)m_mtrlBuffer->GetBufferPointer();

		for (int i = 0; i < m_nMtlNum; i++)
		{
			mtrls[i].MatD3D.Ambient = mtrls[i].MatD3D.Diffuse;
			// MatD3D 속성은 로드될 때 ambient 값을 가지지 않으므로 지금 이를 지정
			
			m_vecMtl.push_back(mtrls[i].MatD3D);
			// i번째 재질 저장

			// i번째 재질에 연결된 텍스쳐가 있는지를 확인
			if (mtrls[i].pTextureFilename != 0)
			{
				IDirect3DTexture9* tex = 0;
				string txtFilePath = string(szFolder) + ("/") + string(mtrls[i].pTextureFilename);
				D3DXCreateTextureFromFileA(g_pD3DDevice, txtFilePath.c_str(), &tex);
				// 만약 그렇다면 i번째 서브셋을 위한 텍스처 로드

				m_vecTxt.push_back(tex);
				// 읽어들인 텍스처 저장
			}
			else
			{
				// i번째 서브셋에 텍스쳐가 없음
				m_vecTxt.push_back(0);
			}
		}

		SafeRelease(m_mtrlBuffer);	// 작업 완료
	}
	// << 재질 추출, 텍스쳐 로드
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
