#include "stdafx.h"
#include "DirectionLight.h"

DirectionLight::DirectionLight() : 
	lightNum(0.0f),
	isTurn(false)
{
}

DirectionLight::~DirectionLight()
{

}

void DirectionLight::SetUp()
{
	ZeroMemory(&m_DirLight, sizeof(D3DLIGHT9));

	m_DirLight.Type = D3DLIGHT_DIRECTIONAL;
	m_DirLight.Diffuse = D3DXCOLOR(1.0f, 0, 0, 1.0f);
	// m_DirLight.Specular = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f) * 0.3f;
	// 과하게 반짝여서 제외
	m_DirLight.Ambient = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f) * 0.6f;
	m_DirLight.Direction = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
}

void DirectionLight::Update()
{
	float zDirc = 5.0f;
	
	if (!isTurn)
	{
		lightNum += 1.0f;

		if (lightNum > 90)
			isTurn = true;
	}
	else
	{
		lightNum -= 1.0f;
		zDirc = -5.0f;

		if (lightNum <= -90)
			isTurn = false;
	}


	m_DirLight.Direction = D3DXVECTOR3(0.0f, lightNum, zDirc);

	g_pD3DDevice->SetLight(0, &m_DirLight);
	g_pD3DDevice->LightEnable(0, true);

	g_pD3DDevice->SetRenderState(D3DRS_NORMALIZENORMALS, true);
	g_pD3DDevice->SetRenderState(D3DRS_SPECULARENABLE, true);
}
