#include "stdafx.h"
#include "Export.h"
#include "Assimp/Loader.h"	// << :

void Export::Initialize()
{
	// Tank() ;
	// Tower(); 
	// Kachujin(); 

}

void Export::Tank()
{
	Loader* loader = new Loader();
	loader->ReadFile(L"Tank/tank.fbx");
	loader->ExportMaterial(L"Tank/Tank"); 
	loader->ExportMesh(L"Tank/Tank"); 
	SafeDelete(loader);
}

void Export::Tower()
{
	Loader* loader = new Loader();
	loader->ReadFile(L"Tower/Tower.fbx");
	loader->ExportMaterial(L"Tower/Tower");
	loader->ExportMesh(L"Tower/Tower"); 

	SafeDelete(loader);
}

void Export::Kachujin()
{
	Loader* loader = new Loader();
	loader->ReadFile(L"Kachujin/Mesh.fbx");
	loader->ExportMaterial(L"Kachujin/Mesh");
	loader->ExportMesh(L"Kachujiin/Mesh"); 
	SafeDelete(loader);
}
