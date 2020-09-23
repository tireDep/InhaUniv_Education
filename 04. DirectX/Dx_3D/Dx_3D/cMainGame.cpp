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
	// >> 1. IDirect3D9 인터페이스 얻기
	// IDirect3D9 * _d3d9 = Direct3DCreate9(D3D_SDK_VERSION);
	m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
	
	{
		//// >> 2. 하드웨어 버텍스 프로세싱 확인하기
		//D3DCAPS9 caps;
		//m_pD3D->GetDeviceCaps(
		//	D3DADAPTER_DEFAULT,		// 기본 디스플레이 어댑터 
		//	D3DDEVTYPE_HAL,			// 기본 설정
		//	&caps					// D3DCPAS9 구조체 리턴 
		//);

		//int vp = 0;
		//// 하드웨어 버텍스 프로세싱 지원?
		//if (caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
		//{
		//	// 하드웨어 버텍스 프로세싱 지원 o 'vp'에 저장
		//	vp = D3DCREATE_HARDWARE_VERTEXPROCESSING;
		//}
		//else
		//{
		//	// 하드웨어 버텍스 프로세싱 지원 x 
		//	// -> 소프트웨어 버텍스 프로세싱 이용해야함을 'vp'에 저장
		//	vp = D3DCREATE_SOFTWARE_VERTEXPROCESSING;
		//}
		// 없어도 됨
	}
	// >> 3. D3DPRESENT_PARAMETERS 구조체 채우기
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(D3DPRESENT_PARAMETERS));

	//d3dpp.BackBufferWidth = 800;
	//d3dpp.BackBufferHeight = 600;
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;	// 픽셀 포멧
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

	// >> 4. IDirect3DDevice9 인터페이스 만들기
	// IDirect3DDevice9* device = 0;
	m_pDevice = 0;
	HRESULT hr = m_pD3D->CreateDevice(
		D3DADAPTER_DEFAULT,		// 기본 어댑터
		D3DDEVTYPE_HAL,			// 장치 타입
		g_hWnd,					// 장치와 연결된 윈도우
		D3DCREATE_HARDWARE_VERTEXPROCESSING,	//  버텍스 프로세싱 타입
		&d3dpp,					// 시연 인자
		&m_pDevice					// 생성된 장치
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
