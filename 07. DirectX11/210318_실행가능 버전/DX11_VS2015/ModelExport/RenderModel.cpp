#include "stdafx.h"
#include "RenderModel.h"
#include "Viewer\FreeCam.h"	// << : 
#include "Environment\Terrain.h"	// << : 

void RenderModel::Initialize()
{
	Context::Get()->GetCamera()->RotationDegree(0, 0, 0); 
	Context::Get()->GetCamera()->Position(0, 60, -50); 
	((FreeCam*)Context::Get()->GetCamera())->Speed(40, 2); 

	tankRenderer = NULL;
	shader = new Shader(L"014_Model.fx");

	ReadTank(); 
}


void RenderModel::Destroy()
{

}

void RenderModel::Update()
{
	if (tankRenderer != NULL)
	{
		static bool bWire = false;
		ImGui::Checkbox("WireFrame", &bWire);
		tankRenderer->Pass(bWire ? 1 : 0);
		tankRenderer->Update();

		ModelBone* bone = tankRenderer->GetModel()->BoneByIndex(10);	// 이름으로 해도 됨
		Matrix matrix;
		D3DXMatrixRotationY(&matrix, Math::ToRadian(5) * 0.01f);
		tankRenderer->UpdateTransform(bone, matrix);
	}
}

void RenderModel::Render()
{
	if (tankRenderer != NULL)
	{
		tankRenderer->Render();
	}
}

void RenderModel::ReadTank()
{
	tank = new Model(); 
	tank->ReadMaterial(L"Tank/Tank"); 
	tank->ReadMesh(L"Tank/Tank");
	int breakpoint = 999; 

	tankRenderer = new ModelRenderer(shader, tank);
	tankRenderer->GetTransform()->Scale(10, 10, 10);
}

