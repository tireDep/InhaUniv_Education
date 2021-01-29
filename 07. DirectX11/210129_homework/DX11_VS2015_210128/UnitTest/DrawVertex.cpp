#include "stdafx.h"
#include "DrawVertex.h"

void DrawVertex::Initialize()
{
	shader = new Shader(L"003_World.fx");

	vertices[0].Position = Vector3(0.0f, 0.0f, 0.0f);
	vertices[1].Position = Vector3(0.0f, 0.5f, 0.0f);
	vertices[2].Position = Vector3(0.5f, 0.0f, 0.0f);
	
	vertices[3].Position = Vector3(0.5f, 0.0f, 0.0f);
	vertices[4].Position = Vector3(0.0f, 0.5f, 0.0f);
	vertices[5].Position = Vector3(0.5f, 0.5f, 0.0f);

	D3D11_BUFFER_DESC desc;
	ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));
	desc.Usage = D3D11_USAGE_DEFAULT;
	desc.ByteWidth = sizeof(Vertex) * 6;
	desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	
	D3D11_SUBRESOURCE_DATA subResource = { 0 };
	subResource.pSysMem = vertices;
	
	Check(D3D::GetDevice()->CreateBuffer(&desc,
										&subResource,
										&vertexBuffer));

	color = Color(0, 0.5, 0.5, 1);

	srand(time(0));
}

void DrawVertex::Destroy()
{
	SafeDelete(shader);
	SafeRelease(vertexBuffer);
}

void DrawVertex::Update()
{
	/// Rect Coior, Move
	//ImGui::ColorEdit3("Color", (float*)&color);
	//shader->AsVector("Color")->SetFloatVector(color);
	//// << 색상 변경
	//
	//// >> 한 정점 이동
	//ImGui::InputInt("Number", (int*)&number);
	//number %= 6;
	//
	//// >> 키 값 인식
	//if (Keyboard::Get()->Press(VK_LEFT))
	//	vertices[number].Position.x -= 2.0f * Time::Delta();
	//else if (Keyboard::Get()->Press(VK_RIGHT))
	//	vertices[number].Position.x += 2.0f * Time::Delta();
	//
	//if (Keyboard::Get()->Press(VK_DOWN))
	//	vertices[number].Position.y -= 2.0f * Time::Delta();
	//else if (Keyboard::Get()->Press(VK_UP))
	//	vertices[number].Position.y += 2.0f * Time::Delta();
	//// << 키 값 인식
	//
	//D3D::GetDC()->UpdateSubresource(
	//	vertexBuffer, 0, NULL, vertices, sizeof(Vertex) * 6, 0);
	//// >> 상당히 느린 방식
	//
	//// << 한 정점 이동
	//
	// 
	//4x4 행렬
	//	a000
	//	0a00
	//	00a0
	//	xyzw
	//
	//	a : 크기 값
	//	x,y,z : 이동 값
	//
	//// w : 점(0), 선(1)

	/// World Set WVP, Move, Color
	//ImGui::ColorEdit3("Color", (float*)&color);
	//shader->AsVector("Color")->SetFloatVector(color);
	//
	//Matrix world; 
	//D3DXMatrixIdentity(&world);
	//{
	//	static Vector3 position(0, 0, 0);
	//	if (Keyboard::Get()->Press(VK_LEFT))
	//		position.x -= 1.0f * Time::Delta();
	//	else if (Keyboard::Get()->Press(VK_RIGHT))
	//		position.x += 1.0f * Time::Delta();
	//	
	//	if (Keyboard::Get()->Press(VK_DOWN))
	//		position.y -= 1.0f * Time::Delta();
	//	else if (Keyboard::Get()->Press(VK_UP))
	//		position.y += 1.0f * Time::Delta();
	//	D3DXMatrixTranslation(&world, position.x, position.y, position.z);
	//}
	//shader->AsMatrix("World")->SetMatrix(world);
	//
	//Matrix view = Context::Get()->View();
	//shader->AsMatrix("View")->SetMatrix(view);
	//
	//Matrix projection = Context::Get()->Projection();
	//shader->AsMatrix("Projection")->SetMatrix(projection);
}

void DrawVertex::Render()
{
	UINT stride = sizeof(Vertex);
	UINT offset = 0;

	D3D::GetDC()->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);

	// >> drawRect
	// Rect 1

	Matrix view = Context::Get()->View();
	shader->AsMatrix("View")->SetMatrix(view);

	Matrix projection = Context::Get()->Projection();
	shader->AsMatrix("Projection")->SetMatrix(projection);

	int random = Math::Random(-2, 1);
	int randomY = Math::Random(-1, 0);

	Vector3 moveRectCenter;
	{
		static Vector3 position(random, randomY, 0);
		moveRectCenter = position;
		Matrix world;

		if (Keyboard::Get()->Press(VK_LEFT) || Keyboard::Get()->Press('A'))
			position.x -= 1.0f * Time::Delta();
		else if (Keyboard::Get()->Press(VK_RIGHT) || Keyboard::Get()->Press('D'))
			position.x += 1.0f * Time::Delta();

		if (Keyboard::Get()->Press(VK_DOWN) || Keyboard::Get()->Press('S'))
			position.y -= 1.0f * Time::Delta();
		else if (Keyboard::Get()->Press(VK_UP) || Keyboard::Get()->Press('W'))
			position.y += 1.0f * Time::Delta();

		D3DXMatrixTranslation(&world, position.x, position.y, position.z);
		Color color(0.5f, 0, 0, 1); 

		shader->AsVector("Color")->SetFloatVector(color);
		shader->AsMatrix("World")->SetMatrix(world);
		shader->Draw(0, 0, 6);
	}

	// Rect 2
	{
		random = Math::Random(-3, 1);
		randomY = Math::Random(-1, 0);

		static Vector3 position(random, randomY, 0);

		float fLength = sqrt(
			(pow(moveRectCenter.x - position.x, 2) + pow(moveRectCenter.y - position.y, 2) + pow(moveRectCenter.z - position.z, 2))
		);

		if (fLength >= 0.5f)
			shader->AsVector("Color")->SetFloatVector(Color(1, 1, 1, 1));
		else
			shader->AsVector("Color")->SetFloatVector(Color(1, 0, 0, 1));

		Matrix world;
		D3DXMatrixTranslation(&world, position.x, position.y, position.z);
		Color color(1, 1, 1, 1);

		shader->AsMatrix("World")->SetMatrix(world);
		shader->Draw(0, 0, 6);
	}
	// << drawRect

	// shader->Draw(0, 0, 6);
}
