#pragma once

#include "../stdafx.h"

struct AsMaterial
{
	string Name;
	Color Ambient;
	Color Diffuse;
	Color Specular;

	string DiffuseFile;
	string SpecularFile;
	string NormalFile;
};