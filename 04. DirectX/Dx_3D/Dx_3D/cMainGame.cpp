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
	
}

void cMainGame::Update()
{
	// g_pDeviceManager->Destroy();
}

void cMainGame::Render()
{
	g_pD3DDevice->Clear(NULL, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(150, 150, 150), 1.0f, 0);
	// 화면 삭제 및 그리기

	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}
