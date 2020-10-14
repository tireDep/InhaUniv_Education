#include "stdafx.h"
#include "cCharObjectLoader.h"

cCharObjectLoader::cCharObjectLoader()
{
}

cCharObjectLoader::~cCharObjectLoader()
{
}

void cCharObjectLoader::Load(OUT cGeoObject* &pGeoObject, IN char * szFolder, IN char * szFile)
{
	vector<D3DXVECTOR3> vecV;
	vector<D3DXVECTOR2> vecVT;
	vector<D3DXVECTOR3> vecVN;
	vector<ST_PNT_VERTEX> vecVertex;

	int nIndex;

	int fFrame;
	int lFrame;
	int tickFrame;
	cGeoObject* newGeoObject = NULL;

	FILE *fp;
	string sFullPath(szFolder);
	sFullPath += (string("/") + string(szFile));
	fopen_s(&fp, sFullPath.c_str(), "r");

	while (1)
	{
		if (feof(fp))
			break;

		char szTemp[1024];
		fgets(szTemp, 1024, fp);

		char szBuffer[1024];
		sscanf(szTemp, "%s", szBuffer);

		// >> SetScene
		if (!strcmp(szBuffer, "*SCENE_FIRSTFRAME"))
		{
			sscanf_s(szTemp, "%*s %d", &fFrame);
		}
		else if (!strcmp(szBuffer, "*SCENE_LASTFRAME"))
		{
			sscanf_s(szTemp, "%*s %d", &lFrame);
		}
		else if (!strcmp(szBuffer, "*SCENE_TICKSPERFRAME"))
		{
			sscanf_s(szTemp, "%*s %d", &tickFrame);
		}
		// << SetScene

		// >> SetMtrl
		if (!strcmp(szBuffer, "*MATERIAL_COUNT"))
		{
			int nSize;
			sscanf_s(szTemp, "%*s %d", &nSize);
			
			m_vecMtrlTex.resize(nSize);
			m_vecMtrlName.resize(nSize);
		}
		else if (!strcmp(szBuffer, "*MATERIAL"))
		{
			sscanf_s(szTemp, "%*s %d", &nIndex);

			SafeRelease(m_vecMtrlTex[nIndex]);
			m_vecMtrlTex[nIndex] = new cMtlTex;
		}
		else if (!strcmp(szBuffer, "*MATERIAL_NAME"))
		{
			char name[1024];
			sscanf_s(szTemp, "%*s %[^/]%[/]%*[^/]%s", name, 1024);

			string sName = name;
			sName = sName.assign(sName.begin() + 1, sName.end() - 2);

			m_vecMtrlName[nIndex] = sName;
		}
		else if (!strcmp(szBuffer, "*MATERIAL_AMBIENT"))
		{
			D3DMATERIAL9& mtrl = m_vecMtrlTex[nIndex]->GetMaterial();
			float r, g, b;
			sscanf_s(szTemp, "%*s %f %f %f", &r, &g, &b);

			mtrl.Ambient.r = r;
			mtrl.Ambient.g = g;
			mtrl.Ambient.b = b;
			mtrl.Ambient.a = 1.0f;
		}
		else if (!strcmp(szBuffer, "*MATERIAL_AMBIENT"))
		{
			D3DMATERIAL9& mtrl = m_vecMtrlTex[nIndex]->GetMaterial();
			float r, g, b;
			sscanf_s(szTemp, "%*s %f %f %f", &r, &g, &b);

			mtrl.Diffuse.r = r;
			mtrl.Diffuse.g = g;
			mtrl.Diffuse.b = b;
			mtrl.Diffuse.a = 1.0f;
		}
		else if (!strcmp(szBuffer, "*MATERIAL_AMBIENT"))
		{
			D3DMATERIAL9& mtrl = m_vecMtrlTex[nIndex]->GetMaterial();
			float r, g, b;
			sscanf_s(szTemp, "%*s %f %f %f", &r, &g, &b);

			mtrl.Specular.r = r;
			mtrl.Specular.g = g;
			mtrl.Specular.b = b;
			mtrl.Specular.a = 1.0f;
		}
		if (!strcmp(szBuffer, "*MAP_DIFFUSE"))
		{
			while (1)
			{
				fgets(szTemp, 1024, fp);
				sscanf(szTemp, "%s", szBuffer);
				if (!strcmp(szBuffer, "*BITMAP"))
				{
					char bitFile[1024];
					sscanf_s(szTemp, "%*s %s", bitFile, 1024);

					string path = (string(bitFile));
					path = path.assign(path.begin() + 1, path.end() - 1);
					path[path.length()] = 0;

					g_pTextureManager->AddTexture(path, path);
					m_vecMtrlTex[nIndex]->SetTexture(g_pTextureManager->GetTexture(path));
					break;
				}
			}
		} // : if_ReadTexture
		// << SetMtrl

		// >> SetGeo
		else if (!strcmp(szBuffer, "*GEOMOBJECT"))
		{
			if (newGeoObject == NULL)
			{
				newGeoObject = new cGeoObject;
				pGeoObject = newGeoObject;
			}
			else
			{
				if (!vecVertex.empty())
				{
					D3DXMATRIXA16 matInverse; 
					matInverse = newGeoObject->GetMatWorld();
					D3DXMatrixInverse(&matInverse, 0, &matInverse);

					CalcNormalVector(vecVertex);
					for (int i = 0; i < vecVertex.size(); i++)
					{
						D3DXVec3TransformCoord(&vecVertex[i].p, &vecVertex[i].p, &matInverse);
						D3DXVec3TransformNormal(&vecVertex[i].n, &vecVertex[i].n, &matInverse);
					}
					newGeoObject->SetVertex(vecVertex);
					// newGeoObject->SetMatLocal(matInverse);
					newGeoObject->SetMatLocal(newGeoObject->GetMatWorld());
					vecVertex.clear();
				}
				newGeoObject = new cGeoObject;
			}
		} // : if_GEOMOBJECT

		else if (!strcmp(szBuffer, "*NODE_NAME"))
		{
			char name[1024];
			sscanf_s(szTemp, "%*s %s", &name, 1024);
			string sName = name;
			sName = sName.assign(sName.begin() + 1, sName.end() - 1);

			newGeoObject->SetName(sName);
		}
		else if (!strcmp(szBuffer, "*NODE_PARENT"))
		{
			char name[1024];
			sscanf_s(szTemp, "%*s %s", &name, 1024);
			string sName = name;
			sName = sName.assign(sName.begin() + 1, sName.end() - 1);

			cGeoObject* parent = NULL;
			parent = pGeoObject->GetMyParents(sName);

			if (parent)
				parent->AddChild(newGeoObject);
		}
		else if (!strcmp(szBuffer, "*TM_ROW0"))
		{
			float x, y, z;
			sscanf_s(szTemp, "%*s %f %f %f", &x, &z, &y);

			D3DXMATRIXA16 mat = newGeoObject->GetMatWorld();
			mat._11 = x;
			mat._12 = y;
			mat._13 = z;
			mat._14 = 0.0f;

			newGeoObject->SetMatWorld(mat);
		}
		else if (!strcmp(szBuffer, "*TM_ROW1"))
		{
			float x, y, z;
			sscanf_s(szTemp, "%*s %f %f %f", &x, &z, &y);

			D3DXMATRIXA16 mat = newGeoObject->GetMatWorld();
			mat._31 = x;
			mat._32 = y;
			mat._33 = z;
			mat._34 = 0.0f;

			newGeoObject->SetMatWorld(mat);
		}
		else if (!strcmp(szBuffer, "*TM_ROW2"))
		{
			float x, y, z;
			sscanf_s(szTemp, "%*s %f %f %f", &x, &z, &y);

			D3DXMATRIXA16 mat = newGeoObject->GetMatWorld();
			mat._21 = x;
			mat._22 = y;
			mat._23 = z;
			mat._24 = 0.0f;

			newGeoObject->SetMatWorld(mat);
		}
		else if (!strcmp(szBuffer, "*TM_ROW3"))
		{
			float x, y, z;
			sscanf_s(szTemp, "%*s %f %f %f", &x, &z, &y);

			D3DXMATRIXA16 mat = newGeoObject->GetMatWorld();
			mat._41 = x;
			mat._42 = y;
			mat._43 = z;
			mat._44 = 1.0f;

			newGeoObject->SetMatWorld(mat);
		}
		else if (!strcmp(szBuffer, "*MESH_NUMVERTEX"))
		{
			int nSize;
			sscanf_s(szTemp, "%*s %d", &nSize);

			vecV.clear();
			vecV.resize(nSize);
		}
		// >> Mesh
		else if(!strcmp(szBuffer, "*MESH_VERTEX"))
		{
			int nIndex;
			float x, y, z;
			sscanf_s(szTemp, "%*s %d %f %f %f", &nIndex, &x, &z, &y);

			vecV[nIndex] = D3DXVECTOR3(x, y, z);
		}
		else if (!strcmp(szBuffer, "*MESH_NUMFACES"))
		{
			int nSize;
			sscanf_s(szTemp, "%*s %d", &nSize);

			vecVertex.clear();
			vecVertex.resize(nSize * 3);
		}
		else if (!strcmp(szBuffer, "*MESH_FACE"))
		{
			int nIndex;
			int x, y, z;
			sscanf_s(szTemp, "%*s %d: A: %d B: %d C: %d", &nIndex, &x, &z, &y);

			vecVertex[nIndex * 3 + 0].p = vecV[x];
			vecVertex[nIndex * 3 + 1].p = vecV[y];
			vecVertex[nIndex * 3 + 2].p = vecV[z];
		}
		else if (!strcmp(szBuffer, "*MESH_NUMTVERTEX"))
		{
			int nSize;
			sscanf_s(szTemp, "%*s %d", &nSize);

			vecVT.clear();
			vecVT.resize(nSize);
		}
		else if (!strcmp(szBuffer, "*MESH_TVERT"))
		{
			int nIndex;
			float x, y;
			sscanf_s(szTemp, "%*s %d %f %f",&nIndex, &x, &y);

			vecVT[nIndex] = D3DXVECTOR2(x, 1.0f - y);
		}
		else if (!strcmp(szBuffer, "*MESH_TFACE"))
		{
			int nIndex;
			int x, y, z;
			sscanf_s(szTemp, "%*s %d %d %d %d", &nIndex, &x, &z, &y);

			vecVertex[nIndex * 3 + 0].t = vecVT[x];
			vecVertex[nIndex * 3 + 1].t = vecVT[y];
			vecVertex[nIndex * 3 + 2].t = vecVT[z];
		}
		else if (!strcmp(szBuffer, "*MESH_FACENORMAL"))
		{
			int nIndex;
			D3DXVECTOR3 a, b, c;
			sscanf_s(szTemp, "%*s %d", &nIndex);

			fgets(szTemp, 1024, fp);
			sscanf_s(szTemp, "%*s %*d %f %f %f", &a.x, &a.z, &a.y);
			fgets(szTemp, 1024, fp);
			sscanf_s(szTemp, "%*s %*d %f %f %f", &c.x, &c.z, &c.y);
			fgets(szTemp, 1024, fp);
			sscanf_s(szTemp, "%*s %*d %f %f %f", &b.x, &b.z, &b.y);

			vecVertex[nIndex * 3 + 0].n = a;
			vecVertex[nIndex * 3 + 1].n = b;
			vecVertex[nIndex * 3 + 2].n = c;
		}
		else if (!strcmp(szBuffer, "*MATERIAL_REF"))
		{
			int nIndex;
			sscanf_s(szTemp, "%*s %d", &nIndex);
			newGeoObject->SetMtrlTex((m_vecMtrlTex[nIndex]));
		}
		// << Mesh
		// << SetGeo

	}	// : while

	if (!vecVertex.empty())
	{
		D3DXMATRIXA16 matInverse;
		matInverse = newGeoObject->GetMatWorld();
		D3DXMatrixInverse(&matInverse, 0, &matInverse);

		CalcNormalVector(vecVertex);
		for (int i = 0; i < vecVertex.size(); i++)
		{
			D3DXVec3TransformCoord(&vecVertex[i].p, &vecVertex[i].p, &matInverse);
			D3DXVec3TransformNormal(&vecVertex[i].n, &vecVertex[i].n, &matInverse);
		}

		newGeoObject->SetVertex(vecVertex);
		newGeoObject->SetMatLocal(newGeoObject->GetMatWorld());
		// newGeoObject->SetMatLocal(matInverse);
	}

	for (int i = 0; i < m_vecMtrlTex.size(); i++)
	{
		SafeRelease(m_vecMtrlTex[i]);
	}
	m_vecMtrlTex.clear();

	fclose(fp);

	pGeoObject->CalcLocalMat(NULL);
}

void cCharObjectLoader::CalcNormalVector(vector<ST_PNT_VERTEX>& vecVertex)
{
	D3DXVECTOR3 u, v, n;
	for (int i = 0; i < vecVertex.size(); i += 3)
	{
		u = vecVertex[i + 1].p - vecVertex[i].p;
		v = vecVertex[i + 2].p - vecVertex[i].p;

		D3DXVec3Cross(&n, &u, &v);
		D3DXVec3Normalize(&n, &n);

		vecVertex[i + 0].n = n;
		vecVertex[i + 1].n = n;
		vecVertex[i + 2].n = n;
	}

}