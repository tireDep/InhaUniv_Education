#include "stdafx.h"
#include "cCharObjLoader.h"

cCharObjLoader::cCharObjLoader()
{
}

cCharObjLoader::~cCharObjLoader()
{
}

void cCharObjLoader::Load(OUT vector<cCharObjGroup*>& vecGroup, IN char * szFolder, IN char * szFile)
{
	int firstFrame;
	int lastFrame;
	int ticksPerFrame;

	string sFullPath(szFolder);
	sFullPath += (string("/") + string(szFile));

	FILE *fp;
	fopen_s(&fp, sFullPath.c_str(), "r");

	while (1)
	{
		if (feof(fp))
			break;

		char szTemp[1024];
		fgets(szTemp, 1024, fp);

		// >> Scene
		if (strstr(szTemp, "*SCENE_FIRSTFRAME"))
			sscanf_s(szTemp, "%*s %d", &firstFrame);
		if (strstr(szTemp, "*SCENE_LASTFRAME"))
			sscanf_s(szTemp, "%*s %d", &lastFrame);
		if (strstr(szTemp, "*SCENE_TICKSPERFRAME"))
			sscanf_s(szTemp, "%*s %d", &ticksPerFrame);
		// << Scene

		// << Mtrl
		if (strstr(szTemp, "*MATERIAL_LIST"))
			LoadMtlLib(fp, szTemp, szFolder, szFile);
		// >> Mtrl

		// >> GEOMOBJECT
		if (strstr(szTemp, "*GEOMOBJECT"))
		{
			LoadObject(vecGroup, fp, szTemp, szFolder, szFile);
		}
		// << GEOMOBJECT
	}

	fclose(fp);
}

void cCharObjLoader::LoadMtlLib(FILE *fp, char szTemp[], char* szFolder, char* szTextFile)
{
	int arrSize;
	fgets(szTemp, 1024, fp);
	if (strstr(szTemp, "*MATERIAL_COUNT"))
		sscanf_s(szTemp, "%*s %d", &arrSize);

	float r, g, b;
	float alpha = 1.0f;

	cMtlTex temp;
	while(1)
	{
		fgets(szTemp, 1024, fp);

		if (m_vecMtlTex.size() >= arrSize)
			break;

		if (strstr(szTemp, "*MATERIAL_AMBIENT"))
		{
			sscanf_s(szTemp, "%*s %f %f %f", &r, &g, &b);

			temp.GetMaterial().Ambient.r = r;
			temp.GetMaterial().Ambient.g = g;
			temp.GetMaterial().Ambient.b = b;
			temp.GetMaterial().Ambient.a = alpha;
		}
		else if (strstr(szTemp, "*MATERIAL_DIFFUSE"))
		{
			sscanf_s(szTemp, "%*s %f %f %f", &r, &g, &b);

			temp.GetMaterial().Diffuse.r = r;
			temp.GetMaterial().Diffuse.g = g;
			temp.GetMaterial().Diffuse.b = b;
			temp.GetMaterial().Diffuse.a = alpha;
		}
		else if (strstr(szTemp, "*MATERIAL_SPECULAR"))
		{
			sscanf_s(szTemp, "%*s %f %f %f", &r, &g, &b);

			temp.GetMaterial().Specular.r = r;
			temp.GetMaterial().Specular.g = g;
			temp.GetMaterial().Specular.b = b;
			temp.GetMaterial().Specular.a = alpha;

			m_vecMtlTex.push_back(&temp);
		}

		if (strstr(szTemp, "*MAP_DIFFUSE"))
		{
			while (1)
			{
				fgets(szTemp, 1024, fp);
				if (strstr(szTemp, "*BITMAP") && !strstr(szTemp, "*BITMAP_"))
				{
					char bitFile[1024];
					sscanf_s(szTemp, "%*s %s", bitFile, 1024);
					
					string path = (string(bitFile));
					path = path.assign(path.begin() + 1, path.end() - 1);
					path[path.length()] = 0;

					LPDIRECT3DTEXTURE9 texture = g_pTextureManager->GetTexture(path);
					m_vecMtlTex[m_vecMtlTex.size() - 1]->SetTexture(texture);
					break;
				}
			}
		} // : if_ReadTexture

	}	// : while
}

void cCharObjLoader::LoadObject(OUT vector<cCharObjGroup*>& vecGroup, FILE * fp, char szTemp[], char * szFolder, char * szTextFile)
{
	int cnt = 0;
	if (strstr(szTemp, "{"))
		cnt++;

	cCharObjGroup* charObj = new cCharObjGroup;
	vector<D3DXVECTOR3> vecTempMat;
	
	vector<D3DXVECTOR3> vVertex;
	vector<D3DXVECTOR3> vFace;
	vector<D3DXVECTOR3> vNormal;

	vector<D3DXVECTOR2> vTVertexList;
	vector<D3DXVECTOR3> vTFaceList;

	vector<ST_PNT_VERTEX> vecPNTVertex;
	vector<ST_PN_VERTEX> vecPNVertex;

	int tempIndex = 0;

	while (1)
	{
		fgets(szTemp, 1024, fp);

		// >> 종료 조건
		if (strstr(szTemp, "{"))
			cnt++;
		else if (strstr(szTemp, "}"))
			cnt--;

		if (cnt == 0)
			break;
		// << 종료 조건

		// >> NodeName
		if (strstr(szTemp, "*NODE_NAME"))
		{
			char name[1024];
			sscanf_s(szTemp, "%*s %s", &name, 1024);
			string sName = name;
			sName = sName.assign(sName.begin() + 1, sName.end() - 1);

			charObj->SetNodeName(sName);
		}
		// << NodeName

		// >> worldMat
		if (strstr(szTemp, "*TM_ROW"))
		{
			float x, y, z;
			sscanf_s(szTemp, "%*s %f %f %f", &x, &z, &y);

			vecTempMat.push_back(D3DXVECTOR3(x, y, z));
			if (vecTempMat.size() >= 4)
				charObj->SetWorldMatrix(vecTempMat);
		}
		// << worldMat

		// >> vertexList
		if (strstr(szTemp, "*MESH_VERTEX") && !strstr(szTemp, "*MESH_VERTEX_LIST"))
		{
			float x, y, z;
			sscanf_s(szTemp, "%*s %*d %f %f %f", &x, &z, &y);

			vVertex.push_back(D3DXVECTOR3(x, y, z));
		}
		// << vertexList

		// >> TVerList == uv
		if (strstr(szTemp, "*MESH_TVERT") && !strstr(szTemp, "*MESH_TVERTLIST"))
		{
			float x, y;
			sscanf_s(szTemp, "%*s %*d %f", &x, &y);

			vTVertexList.push_back(D3DXVECTOR2(x, 1.0f - y));
		}
		// << TVerList == uv

		// >> faceList
		if (strstr(szTemp, "*MESH_FACE") && !strstr(szTemp, "*MESH_FACE_LIST"))
		{
			float x, y, z;
			sscanf_s(szTemp, "%*s %*s %*s %f %*s %f %*s %f", &x, &z, &y);

			vFace.push_back(D3DXVECTOR3(x, y, z));
		}
		// << faceList

		// >> TFaceList
		if (strstr(szTemp, "*MESH_TFACE") && !strstr(szTemp, "*MESH_TFACELIST"))
		{
			int x, y, z;
			sscanf_s(szTemp, "%*s %*d %f %f %f", &x, &z, &y);

			vTFaceList.push_back(D3DXVECTOR3(x, y, z));
		}
		// << TFaceList

		// >> normal
		if (strstr(szTemp, "*MESH_VERTEXNORMAL"))
		{
			float x, y, z;
			sscanf_s(szTemp, "%*s %*d %f %f %f", &x, &z, &y);

			vNormal.push_back(D3DXVECTOR3(x, y, z));
		}
		// << normal

		// >> Material_Ref
		if (strstr(szTemp, "*MATERIAL_REF"))
		{
			int num;
			sscanf_s(szTemp, "%*s %d", &num);
			charObj->SetTextureIndex(num);
		}
		// << Material_Ref


	}	// : while

	for (int i = 0; i < 3; i+=3)
	{
	// 	if (vFace.size() != 0 && vTFaceList.size() == 0)
	// 	{
	// 		ST_PN_VERTEX v;
	// 
	// 		v.p = vVertex[vFace[i][0]];
	// 		v.n = vNormal[vFace[i][0]];
	// 
	// 		vecPNVertex.push_back(v);
	// 	}

		if (vTFaceList.size() != 0)
		{
			ST_PNT_VERTEX v;

			v.p = vVertex[vTFaceList[i][0]];
			v.t = vTVertexList[vTFaceList[i][0]];
			v.n = vNormal[vTFaceList[i][0]];

			vecPNTVertex.push_back(v);
		}
	}

	if (!vecPNTVertex.empty())
	{
		charObj->SetVertex(vecPNTVertex);
		charObj->SetMtlTex(m_vecMtlTex[charObj->GetTextureIndex()]);

		vecGroup.push_back(charObj);

		vecPNTVertex.clear();
	}

	// if (!vecPNVertex.empty())
	// {
	// 	charObj->SetVertex(vecPNVertex);
	// 	charObj->SetMtlTex(m_vecMtlTex[charObj->GetTextureIndex()]);
	// 
	// 	vecGroup.push_back(charObj);
	// 
	// 	vecPNTVertex.clear();
	// }
}
