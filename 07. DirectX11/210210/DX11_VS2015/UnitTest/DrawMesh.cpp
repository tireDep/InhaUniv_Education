#include "stdafx.h"
#include "DrawMesh.h"
#include "Viewer\FreeCam.h"	// << : 
#include "Environment\Terrain.h"	// << : 

void DrawMesh::Initialize()
{
	Context::Get()->GetCamera()->RotationDegree(25, 0, 0);
	Context::Get()->GetCamera()->Position(0, 60, -150);
	((FreeCam*)Context::Get()->GetCamera())->Speed(40, 2); 

	shader = new Shader(L"007_Mesh.fx"); 
	
	quad = new MeshQuad(shader);

	grid = new MeshGrid(shader);
	grid->Position(0, 0, 0);
	grid->Scale(20, 1, 20);
	grid->Color(0, 1, 1);

	// 
	cube = new MeshCube(shader);
	cube->Position(0, 5, 0);
	cube->Scale(20, 10, 20);
	cube->Color(1, 0, 0);

	for (UINT i = 0; i < 5; i++)
	{
		cylinder[i] = new MeshCylinder(shader, 0.5f, 3.0f, 20, 20);
		cylinder[i]->Position(-20 - (float)i * 10.0f, 6, -15.0f);
		cylinder[i]->Scale(5, 5, 5);
		cylinder[i]->Color(0, 1, 0);

		sphere[i] = new MeshSphere(shader, 0.5f, 20, 20);
		sphere[i]->Position(20 + (float)i * 10.0f, 3, -15.0f);
		sphere[i]->Scale(5, 5, 5);
		sphere[i]->Color(0, 0, 1);
	}
}


void DrawMesh::Destroy()
{
}

void DrawMesh::Update()
{
	((FreeCam*)Context::Get()->GetCamera())->Update();
}

void DrawMesh::Render()
{
	Vector3& direction = Context::Get()->LightDirection();
	ImGui::SliderFloat3("Light Direction", (float*)&direction, -1, 1);
	shader->AsVector("LightDirection")->SetFloatVector(direction);

	// quad->Render();
	grid->Render();

	cube->Render();
	for (UINT i = 0; i < 5; i++)
	{
		sphere[i]->Render();
		cylinder[i]->Render();
	}
}

