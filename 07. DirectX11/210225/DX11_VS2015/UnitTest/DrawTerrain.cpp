#include "stdafx.h"
#include "DrawTerrain.h"
#include "Viewer\FreeCam.h"	// << : 
#include "Environment\Terrain.h"	// << : 

void DrawTerrain::Initialize()
{
	((FreeCam*)Context::Get()->GetCamera())->Speed(40, 3); 
	shader = new Shader(L"010_Terrain.fx"); 

	terrain = new Terrain(shader, L"HeightMap/HeightMapTest2.png"); 
	terrain->BaseMap(L"Terrain/Dirt.png");

	sphereShader = new Shader(L"007_Mesh.fx");
	sphere = new MeshSphere(sphereShader, 0.5f);
	sphere->Color(1, 0, 0);
	sphere->Position(0, 0, 0);
}


void DrawTerrain::Destroy()
{
	SafeDelete(shader); 
	SafeDelete(terrain); 
}

void DrawTerrain::Update()
{
	static Vector3 direction(-1, -1, 1); 
	ImGui::SliderFloat3("LightDirection", (float*)&direction, -1, 1); 
	shader->AsVector("LightDirection")->SetFloatVector(direction); 

	sphereShader->AsVector("LightDirection")->SetFloatVector(direction);
	// 키보드 이동
	// Vector3 position;
	// sphere->Position(&position);
	// if (Keyboard::Get()->Press(VK_UP))
	// 	position.z += 30.0f * Time::Delta();
	// else if (Keyboard::Get()->Press(VK_DOWN))
	// 	position.z -= 30.0f * Time::Delta();
	// 
	// if (Keyboard::Get()->Press(VK_RIGHT))
	// 	position.x += 30.0f * Time::Delta();
	// if (Keyboard::Get()->Press(VK_LEFT))
	// 	position.x -= 30.0f * Time::Delta();
	// 
	// // position.y = terrain->GetHeight(position) + 0.5f;
	// position.y = terrain->GetPickedHeight(position) + 0.5f;
	// sphere->Position(position);

	// 마우스 이동
	if (Mouse::Get()->Down(0))
	{
		Vector3 position = terrain->GetPickedPosition();
		if (position.x >= 0.0f && position.z >= 0.0f)
			sphere->Position(position);
	}

	terrain->Update(); 
}

void DrawTerrain::Render()
{
	// 0224
	{
		// Vector3 position = Mouse::Get()->GetPosition();
		Vector3 position = terrain->GetPickedPosition();
		string text = "X : " + to_string(position.x)  
					+ "Y : " + to_string(position.x)
					+ "Z : " + to_string(position.z);
		Gui::Get()->RenderText(10, 100, 1, 0, 0, text);
	}

	{
		// 2D로 표현
		// static Vector3 position(123, 10, 128);
		// 
		// if (Keyboard::Get()->Press('A'))
		// 	position.x -= 10.0f * Time::Delta();
		// if (Keyboard::Get()->Press('D'))
		// 	position.x += 10.0f * Time::Delta();

		Vector3 position;
		sphere->Position(&position);
		position.y += 2.0f;

		Vector3 project;
		Matrix world;
		D3DXMatrixIdentity(&world);

		Matrix V, P;
		V = Context::Get()->View();
		P = Context::Get()->Projection();

		Context::Get()->GetViewport()->Project(&project, position, world, V, P);

		Gui::Get()->RenderText(project.x, project.y, 0, 0, 1, "Test");
	}

	terrain->Render(); 
	sphere->Render();
}

