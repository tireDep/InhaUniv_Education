#pragma once
#include "Meshs\Mesh.h"

class MeshGrid : public Mesh
{
public:
	MeshGrid(Shader* shader);
	~MeshGrid();

private:
	void Create() override;
};

