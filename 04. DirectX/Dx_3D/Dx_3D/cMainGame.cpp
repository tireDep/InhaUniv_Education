#include "stdafx.h"
#include "cMainGame.h"

cMainGame::cMainGame()
{

}

cMainGame::~cMainGame()
{

}

void cMainGame::SetUp()
{
	// >> 1. IDirect3D9 �������̽� ���
	// IDirect3D9 * _d3d9 = Direct3DCreate9(D3D_SDK_VERSION);
	m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
	
	{
		//// >> 2. �ϵ���� ���ؽ� ���μ��� Ȯ���ϱ�
		//D3DCAPS9 caps;
		//m_pD3D->GetDeviceCaps(
		//	D3DADAPTER_DEFAULT,		// �⺻ ���÷��� ����� 
		//	D3DDEVTYPE_HAL,			// �⺻ ����
		//	&caps					// D3DCPAS9 ����ü ���� 
		//);

		//int vp = 0;
		//// �ϵ���� ���ؽ� ���μ��� ����?
		//if (caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
		//{
		//	// �ϵ���� ���ؽ� ���μ��� ���� o 'vp'�� ����
		//	vp = D3DCREATE_HARDWARE_VERTEXPROCESSING;
		//}
		//else
		//{
		//	// �ϵ���� ���ؽ� ���μ��� ���� x 
		//	// -> ����Ʈ���� ���ؽ� ���μ��� �̿��ؾ����� 'vp'�� ����
		//	vp = D3DCREATE_SOFTWARE_VERTEXPROCESSING;
		//}
		// ��� ��
	}
	// >> 3. D3DPRESENT_PARAMETERS ����ü ä���
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(D3DPRESENT_PARAMETERS));

	//d3dpp.BackBufferWidth = 800;
	//d3dpp.BackBufferHeight = 600;
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;	// �ȼ� ����
	d3dpp.BackBufferCount = 1;
	//d3dpp.MultiSampleType = D3DMULTISAMPLE_NONE;
	//d3dpp.MultiSampleQuality = 0;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = g_hWnd;
	d3dpp.Windowed = true;
	d3dpp.EnableAutoDepthStencil = true;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;
	d3dpp.Flags = 0;
	//d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

	// >> 4. IDirect3DDevice9 �������̽� �����
	// IDirect3DDevice9* device = 0;
	m_pDevice = 0;
	HRESULT hr = m_pD3D->CreateDevice(
		D3DADAPTER_DEFAULT,		// �⺻ �����
		D3DDEVTYPE_HAL,			// ��ġ Ÿ��
		g_hWnd,					// ��ġ�� ����� ������
		D3DCREATE_HARDWARE_VERTEXPROCESSING,	//  ���ؽ� ���μ��� Ÿ��
		&d3dpp,					// �ÿ� ����
		&m_pDevice					// ������ ��ġ
	);

	if (FAILED(hr))
	{
		::MessageBox(0, L"CreateDevice() == FAILED", 0, 0);
		return;
	}
}

void cMainGame::Update()
{

}

void cMainGame::Render()
{
	if (m_pDevice)
	{
		m_pDevice->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0x00000000, 1.0f, 0);

		m_pDevice->Present(0, 0, 0, 0);
	}
}
