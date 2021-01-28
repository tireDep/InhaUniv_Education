#pragma once

#include "Systems\IExecute.h"

class DrawVertex : public IExecute
{
public:
	// Inherited via IExecute
	virtual void Initialize() override;
	virtual void Ready() override { };
	virtual void Destroy() override;
	virtual void Update() override;
	virtual void PreRender() override { };
	virtual void Render() override;
	virtual void PostRender() override { };
	virtual void ResizeScreen() override { };

private:
	//Shader* shader;
	//Vertex vertices[6];
	//ID3D11Buffer* vertexBuffer;

	// Homework
	Shader* shader;
	Vertex vertices[10];
	ID3D11Buffer* vertexBuffer;
};
