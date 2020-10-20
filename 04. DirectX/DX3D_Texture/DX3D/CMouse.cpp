#include "stdafx.h"
#include "CMouse.h"
#include "CSphere.h"

CMouse::CMouse() :
	m_isLDown(false),
	m_isRDown(false),
	m_destPos(0, 0, 0),
	m_gridIndex(-1)
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

void CMouse::Update(vector<CSphere *>& mesh, D3DXVECTOR3 setLookAt, vector<ST_PN_VERTEX> vecCheck)
{
	for (int i = 0; i < mesh.size(); i++)
	{
		if (m_isLDown)
		CheckLBtn(mesh[i]);

		if (m_isRDown)
		CheckRBtn(mesh[i], vecCheck);
	}

	m_vLookAt = setLookAt;
}


void CMouse::CheckLBtn(CSphere * mesh)
{
	// >> 픽킹 광선의 계산
	D3DXVECTOR3 mousePos;

	D3DVIEWPORT9 viewPortMat;
	g_pD3DDevice->GetViewport(&viewPortMat);

	D3DXMATRIX projMat;
	g_pD3DDevice->GetTransform(D3DTS_PROJECTION, &projMat);

	mousePos.x = ((2.0f * m_clickPos.x) / viewPortMat.Width - 1.0f) / projMat._11;
	mousePos.y = ((-2.0f * m_clickPos.y) / viewPortMat.Height + 1.0f) / projMat._22;
	mousePos.z = 1.0f;
	// << 픽킹 광선의 계산

	// >> 광선변환
	D3DXVECTOR3 origin(0, 0, 0);
	// D3DXVECTOR3 origin = m_vLookAt;
	D3DXVECTOR3 direction(mousePos.x, mousePos.y, mousePos.z);

	D3DXMATRIXA16 view;
	g_pD3DDevice->GetTransform(D3DTS_VIEW, &view);
	D3DXMatrixInverse(&view, 0, &view);


	D3DXVec3TransformCoord(&origin, &origin, &view);
	D3DXVec3TransformNormal(&direction, &direction, &view);
	D3DXVec3Normalize(&direction, &direction);
	// << 광선변환

	// 광선 물체 교차_MESH에서 VERTEX & FACE 뽑아서 계산 => 수정 필요 (센터만 적용됨)
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


	// >> 광선 물체 교차
	{
		D3DXVECTOR3 v = origin - mesh->GetCenter();

		float b = 2.0f * D3DXVec3Dot(&direction, &v);
		float c = D3DXVec3Dot(&v, &v) - (0.5f * 0.5f); // radius - radius

		float discriminant = (b * b) - (4.0f*c);	// 판별식

		if (discriminant < 0.0f)
			return;

		discriminant = sqrtf(discriminant);

		float s0 = (-b + discriminant) / 2.0f;
		float s1 = (-b - discriminant) / 2.0f;

		if (s0 > 0.0f || s1 >= 0.0f)
			mesh->SetIsClicked(!mesh->GetIsClicked());
	}
	// << 광선 물체 교차

	m_isLDown = false;
}

void CMouse::CheckRBtn(CSphere * mesh, vector<ST_PN_VERTEX> vecCheck)
{
	// >> 언프로젝션
	D3DVIEWPORT9 viewPort;
	g_pD3DDevice->GetViewport(&viewPort);

	D3DXMATRIXA16 matProj;
	g_pD3DDevice->GetTransform(D3DTS_PROJECTION, &matProj);

	D3DXVECTOR3 finV;
	finV.x = ((  (((m_clickPos.x - viewPort.X) * 2.0 / viewPort.Width - 1.0f) )) - matProj._31 ) / matProj._11;
	finV.y = (( -(((m_clickPos.y - viewPort.Y) * 2.0 / viewPort.Height - 1.0f) )) - matProj._32) / matProj._22;
	finV.z = 1.0f;
	// << 언프로젝션

	// >> 카메라 좌표와 구해진 점을 있는 반직선 구함
	D3DXMATRIXA16 matView, matInverseView;
	g_pD3DDevice->GetTransform(D3DTS_VIEW, &matView);

	D3DXMatrixInverse(&matInverseView, NULL, &matView);
	
	D3DXVECTOR3 rayOrigin;
	D3DXVECTOR3	rayDir;

	rayDir.x = finV.x*matInverseView._11 + finV.y*matInverseView._21 + finV.z*matInverseView._31;
	rayDir.y = finV.x*matInverseView._12 + finV.y*matInverseView._22 + finV.z*matInverseView._32;
	rayDir.z = finV.x*matInverseView._13 + finV.y*matInverseView._23 + finV.z*matInverseView._33;
	
	rayOrigin.x = matInverseView._41;
	rayOrigin.y = matInverseView._42;
	rayOrigin.z = matInverseView._43;
	// << 카메라 좌표와 구해진 점을 있는 반직선 구함

	// >> piking
	float u = 0, v = 0, dist = 0;
	for (int i = 0; i < vecCheck.size(); i += 3)
	{
		if (D3DXIntersectTri(
			&vecCheck[i + 0].p,
			&vecCheck[i + 1].p,
			&vecCheck[i + 2].p,
			&rayOrigin,
			&rayDir,
			&u,
			&v,
			&dist))
		{
			// 3d 마우스 좌표 계산
			m_destPos = rayOrigin + rayDir * dist;
			m_gridIndex = i; // Callback return Value
			return;
		}
		// else
		// {
		// 	dist = 5.0f / D3DXVec3Length(&vPickRayDir);
		// 	m_destPos = vPickRayOrig + vPickRayDir * dist;
		//	// 아무것도 눌리지 않았을 경우의 처리도 필요함
		// }

	} // : for
	// << piking

	m_isRDown = false;
}

D3DXVECTOR3 CMouse::CallFunc()
{
	return CMouse::GetInstance()->m_destPos;
}

int CMouse::CallFunc_GridMtrl()
{
	return CMouse::GetInstance()->m_gridIndex;
}
