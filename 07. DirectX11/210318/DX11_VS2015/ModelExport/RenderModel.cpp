#include "stdafx.h"
#include "RenderModel.h"
#include "Viewer\FreeCam.h"	// << : 
#include "Environment\Terrain.h"	// << : 

void RenderModel::Initialize()
{
	Context::Get()->GetCamera()->RotationDegree(0, 0, 0);
	Context::Get()->GetCamera()->Position(0, 60, -50);
	((FreeCam*)Context::Get()->GetCamera())->Speed(40, 2);

	ReadTank();
}


void RenderModel::Destroy()
{

}

void RenderModel::Update()
{

}

void RenderModel::Render()
{

}

void RenderModel::ReadTank()
{
	tank = new Model();
	tank->ReadMaterial(L"Tank/Tank");
	int breakpoint = 999;
}

