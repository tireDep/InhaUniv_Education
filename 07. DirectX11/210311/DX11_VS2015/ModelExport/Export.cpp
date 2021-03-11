#include "stdafx.h"
#include "Export.h"
#include "Assimp/Loader.h"

void Export::Initialize()
{
	// Tank();
	Tower();
	// Kachujin();
}

void Export::Tank()
{
	Loader* loader = new Loader();
	loader->ReadFile(L"Tank/tank.fbx");
	loader->ExportMaterial(L"Tank/Tank");

	int breakPoint = 999;
	SafeDelete(loader);
}

void Export::Tower()
{
	Loader* loader = new Loader();
	loader->ReadFile(L"Tower/Tower.fbx");
	loader->ExportMaterial(L"Tower/Tower");

	int breakPoint = 999;
	SafeDelete(loader);
}

void Export::Kachujin()
{
	Loader* loader = new Loader();
	loader->ReadFile(L"Kachujin/Mesh.fbx");
	loader->ExportMaterial(L"Kachujin/Mesh");

	int breakPoint = 999;
	SafeDelete(loader);
}
