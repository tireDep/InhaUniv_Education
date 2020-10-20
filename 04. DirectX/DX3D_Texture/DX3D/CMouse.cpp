#include "stdafx.h"
#include "CMouse.h"
#include "CSphere.h"

CMouse::CMouse() :
	m_isLDown(false),
	m_isRDown(false),
	m_destPos(9999, 9999, 9999)
{
	m_clickPos.x = -1;
	m_clickPos.y = -1;
}

CMouse::~CMouse()
{
}

void CMouse::SetUp()
{

}

void CMouse::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_LBUTTONDOWN:
			if (GetKeyState(VK_CONTROL) & 0x8000)
			{
				m_clickPos.x = LOWORD(lParam);
				m_clickPos.y = HIWORD(lParam);
				m_isLDown = true;
			}
			break;

		case WM_RBUTTONDOWN:
			if (GetKeyState(VK_CONTROL) & 0x8000)
			{
				m_clickPos.x = LOWORD(lParam);
				m_clickPos.y = HIWORD(lParam);
				m_isRDown = true;
			}
			break;
	}
}

void CMouse::Update(vector<CSphere *>& mesh, D3DXVECTOR3 setLookAt)
{
	POINT pos;
	for(int i=0;i<mesh.size();i++)
		CheckClicked(mesh[i], pos);

	m_vLookAt = setLookAt;
}

void CMouse::CheckClicked(CSphere* mesh, POINT& pos)
{
	if (m_isLDown)
		CheckLBtn(mesh, pos);

	if (m_isRDown)
		CheckRBtn(mesh, pos);
}

void CMouse::CheckLBtn(CSphere * mesh, POINT & pos)
{
	// >> ��ŷ ������ ���
	D3DXVECTOR3 mousePos;

	D3DVIEWPORT9 viewPortMat;
	g_pD3DDevice->GetViewport(&viewPortMat);

	D3DXMATRIX projMat;
	g_pD3DDevice->GetTransform(D3DTS_PROJECTION, &projMat);

	mousePos.x = ((2.0f * m_clickPos.x) / viewPortMat.Width - 1.0f) / projMat._11;
	mousePos.y = ((-2.0f * m_clickPos.y) / viewPortMat.Height + 1.0f) / projMat._22;
	mousePos.z = 1.0f;
	// << ��ŷ ������ ���

	// >> ������ȯ
	D3DXVECTOR3 origin(0, 0, 0);
	// D3DXVECTOR3 origin = m_vLookAt;
	D3DXVECTOR3 direction(mousePos.x, mousePos.y, mousePos.z);

	D3DXMATRIXA16 view;
	g_pD3DDevice->GetTransform(D3DTS_VIEW, &view);
	D3DXMatrixInverse(&view, 0, &view);


	D3DXVec3TransformCoord(&origin, &origin, &view);
	D3DXVec3TransformNormal(&direction, &direction, &view);
	D3DXVec3Normalize(&direction, &direction);
	// << ������ȯ

	// ���� ��ü ����_MESH���� VERTEX & FACE �̾Ƽ� ��� => ���� �ʿ� (���͸� �����)
	/*
	// >>>>>>>>>>>>>>>>>>>>>>
	{
	LPDIRECT3DVERTEXBUFFER9 vB;
	LPDIRECT3DINDEXBUFFER9 iB;

	LPD3DXMESH tempMesh = mesh->GetMesh();
	tempMesh->GetVertexBuffer(&vB);
	tempMesh->GetIndexBuffer(&iB);

	WORD* pIndex;
	ST_PN_VERTEX * pVer;
	vB->Lock(0, 0, (LPVOID*)&pVer, 0);
	iB->Lock(0, 0, (LPVOID*)&pIndex, 0);

	for (int i = 0; i < tempMesh->GetNumFaces(); i++)
	{
	D3DXVECTOR3 v0 = pVer[pIndex[i * 3 + 0]].p;
	D3DXVECTOR3 v1 = pVer[pIndex[i * 3 + 1]].p;
	D3DXVECTOR3 v2 = pVer[pIndex[i * 3 + 2]].p;

	D3DXMATRIXA16 matWorld; // = mesh->GetMatWorld();

	// D3DXVECTOR3 center = mesh->GetCenter();
	// D3DXMatrixTranslation(&matWorld, center.x, center.y, center.z);

	g_pD3DDevice->GetTransform(D3DTS_WORLD, &matWorld);

	D3DXVec3TransformCoord(&v0, &v0, &mesh->GetMatWorld());
	D3DXVec3TransformCoord(&v1, &v1, &mesh->GetMatWorld());
	D3DXVec3TransformCoord(&v2, &v2, &mesh->GetMatWorld());

	float u = 0, v = 0, fDist = 0;
	if (D3DXIntersectTri(&v0, &v1, &v2, &origin, &direction, &u, &v, &fDist))
	{
	vB->Unlock();
	iB->Unlock();

	SafeRelease(vB);
	SafeRelease(iB);

	mesh->SetIsClicked(!mesh->GetIsClicked());
	return;
	}

	}

	vB->Unlock();
	iB->Unlock();

	SafeRelease(vB);
	SafeRelease(iB);
	}

	// <<<<<<<<<<<<<<<<<<<<<<<
	*/


	// >> ���� ��ü ����
	{
		D3DXVECTOR3 v = origin - mesh->GetCenter();

		float b = 2.0f * D3DXVec3Dot(&direction, &v);
		float c = D3DXVec3Dot(&v, &v) - (0.5f * 0.5f); // radius - radius

		float discriminant = (b * b) - (4.0f*c);	// �Ǻ���

		if (discriminant < 0.0f)
			return;

		discriminant = sqrtf(discriminant);

		float s0 = (-b + discriminant) / 2.0f;
		float s1 = (-b - discriminant) / 2.0f;

		if (s0 > 0.0f || s1 >= 0.0f)
			mesh->SetIsClicked(!mesh->GetIsClicked());
	}
	// << ���� ��ü ����

	m_isLDown = false;
}

void CMouse::CheckRBtn(CSphere * mesh, POINT & pos)
{
	D3DXVECTOR3 mousePos;

	D3DVIEWPORT9 viewPortMat;
	g_pD3DDevice->GetViewport(&viewPortMat);

	D3DXMATRIX projMat;
	g_pD3DDevice->GetTransform(D3DTS_PROJECTION, &projMat);

	mousePos.x = ((2.0f * m_clickPos.x) / viewPortMat.Width - 1.0f) / projMat._11;
	mousePos.y = ((-2.0f * m_clickPos.y) / viewPortMat.Height + 1.0f) / projMat._22;
	mousePos.z = 1.0f;
	// ��ŷ ������ ���

	// >> ������ȯ
	D3DXVECTOR3 origin(0, 0, 0);
	D3DXVECTOR3 direction(mousePos.x, mousePos.y, mousePos.z);

	D3DXMATRIXA16 view;
	g_pD3DDevice->GetTransform(D3DTS_VIEW, &view);
	D3DXMatrixInverse(&view, 0, &view);


	D3DXVec3TransformCoord(&origin, &origin, &view);
	D3DXVec3TransformNormal(&direction, &direction, &view);
	D3DXVec3Normalize(&direction, &direction);
	// << ������ȯ

	m_destPos = D3DXVECTOR3(5,0,5);
	// m_destPos.y = 0.0f;

	m_isRDown = false;
}

D3DXVECTOR3 CMouse::CallFunc(D3DXVECTOR3 a)
{
	return  CMouse::GetInstance()->m_destPos;
}
