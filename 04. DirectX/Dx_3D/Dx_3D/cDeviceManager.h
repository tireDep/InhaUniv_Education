#pragma once
#include "stdafx.h"

#define g_pDeviceManager cDeviceManager::GetInstance()
// 장치 매니저
#define g_pD3DDevice cDeviceManager::GetInstance()->GetDevice()
// 디바이스 매니저

class cDeviceManager
{
	SingleTone(cDeviceManager);

private:
	LPDIRECT3D9 m_pD3D;
	LPDIRECT3DDEVICE9 m_pDevice;

public:
	LPDIRECT3DDEVICE9 GetDevice();
	void Destroy();

};