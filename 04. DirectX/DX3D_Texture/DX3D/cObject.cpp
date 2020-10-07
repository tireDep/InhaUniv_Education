#include "stdafx.h"
#include "cObject.h"

#include <fstream>
#include <string>

#define dFilePath "../object/"

cObject::cObject()
{

}

cObject::~cObject()
{

}

cObject::cObject(string fName)
{
	ReadObjFile(fName);
	ReadMtlFile();

	// << Scale
	D3DXMATRIXA16 matS;
	D3DXMatrixScaling(&matS, 0.5f, 0.5f, 0.5f);
	for (int i = 0; i < m_vecVertex.size(); i++)
	{
		for (int j = 0; j < m_vecVertex[i].size(); j++)
			D3DXVec3TransformCoord(&m_vecVertex[i][j].p, &m_vecVertex[i][j].p, &matS);
	}
	// >> Scale

	// >> Normal
	D3DXVECTOR3 u, v, n;
	for (int i = 0; i < m_vecVertex.size(); i++)
	{
		for (int j = 0; j < m_vecVertex[i].size(); j += 3)
		{
			u = m_vecVertex[i][j + 1].p - m_vecVertex[i][j].p;
			v = m_vecVertex[i][j + 2].p - m_vecVertex[i][j].p;

			D3DXVec3Cross(&n, &u, &v);
			D3DXVec3Normalize(&n, &n);

			m_vecVertex[i][j + 0].n = n;
			m_vecVertex[i][j + 1].n = n;
			m_vecVertex[i][j + 2].n = n;
		}
	}
	// << Normal

	// >> Texture
	for (int i = 0; i < m_vecVertex.size(); i++)
	{
		int len;
		int sLength = m_vecTextureFilePath[i].length() + 1;
		len = MultiByteToWideChar(CP_ACP, 0, m_vecTextureFilePath[i].c_str(), sLength, 0, 0);

		wchar_t* buffer = new wchar_t[len];
		MultiByteToWideChar(CP_ACP, 0, m_vecTextureFilePath[i].c_str(), sLength, buffer, len);

		wstring result(buffer);
		delete[] buffer;

		LPCWSTR lFileName = result.c_str();
		// <<

		D3DXCreateTextureFromFile(g_pD3DDevice, lFileName, &texture);
		m_vecTexture.push_back(texture);
	}
	// << Texture

}


void cObject::ReadObjFile(string fName)
{
	D3DXVECTOR3	readP;
	vector<D3DXVECTOR3> vecReadP;

	D3DXVECTOR3	readN;
	vector<D3DXVECTOR3> vecReadN;

	D3DXVECTOR2	readT;
	vector<D3DXVECTOR2> vecReadT;

	vector<ST_PNT_VERTEX> vecAddPNT;

	bool isCheck = false;
	ifstream fp;
	string strRead;

	string fileName = fName;
	SetFilePath(fileName);

	fp.open(fileName); // , ios::in | ios::binary
	if (fp.is_open())
	{
		while (!fp.eof())
		{
			getline(fp, strRead);

			CheckMtl(strRead);

			if (strstr(strRead.c_str(), "v "))
				ParseData(strRead, readP, vecReadP);

			if (strstr(strRead.c_str(), "vt "))
				ParseData(strRead, readT, vecReadT);

			if (strstr(strRead.c_str(), "vn "))
				ParseData(strRead, readN, vecReadN);

			if (strstr(strRead.c_str(), "g "))
			{
				// >> index & groudFin
				while (!strstr(strRead.c_str(), "g") || strstr(strRead.c_str(), "g "))
				{
					getline(fp, strRead);
					CheckMtl(strRead);

					if (strstr(strRead.c_str(), "f "))
						ParseIndexData(strRead, vecReadP, vecReadN, vecReadT, vecAddPNT);
				}

				m_vecVertex.push_back(vecAddPNT);
				Reset(vecReadP, vecReadN, vecReadT, vecAddPNT);
				// << index & groudFin
			} // if strRead == "g "

		}	// while

	}	// if is_Open()
	else
	{
		MessageBox(g_hWnd, L"Error : ObjFileOpen", L"Error", MB_YESNO);
	}

	if (&fp != NULL)
		fp.close();
}

void cObject::ParseData(string & strRead, D3DXVECTOR3 & vSet, vector<D3DXVECTOR3> & vecAdd)
{
	string token;
	int pos = 0;
	string delimeter = " ";

	pos = strRead.find(delimeter);
	token = strRead.substr(0, pos);
	strRead.erase(0, pos + 2);

	pos = strRead.find(delimeter);
	token = strRead.substr(0, pos);
	vSet.x = stof(token);
	strRead.erase(0, pos + delimeter.length());

	pos = strRead.find(delimeter);
	token = strRead.substr(0, pos);
	vSet.y = stof(token);
	strRead.erase(0, pos + delimeter.length());

	pos = strRead.find(delimeter);
	token = strRead.substr(0, pos);
	vSet.z = stof(token);
	strRead.erase(0, pos + delimeter.length());

	vecAdd.push_back(vSet);
	
	strRead = "\0";
}

void cObject::ParseData(string & strRead, D3DXVECTOR2 & vSet, vector<D3DXVECTOR2> & vecAdd)
{
	string token;
	int pos = 0;
	string delimeter = " ";

	pos = strRead.find(delimeter);
	token = strRead.substr(0, pos);
	strRead.erase(0, pos + 2);

	pos = strRead.find(delimeter);
	token = strRead.substr(0, pos);
	vSet.x = stof(token);
	strRead.erase(0, pos + delimeter.length());

	pos = strRead.find(delimeter);
	token = strRead.substr(0, pos);
	vSet.y = stof(token);
	strRead.erase(0, pos + delimeter.length());

	vecAdd.push_back(vSet);
}

void cObject::ParseIndexData(string & strRead, vector<D3DXVECTOR3> & vecP, vector<D3DXVECTOR3>& vecN, vector<D3DXVECTOR2> & vecT, vector<ST_PNT_VERTEX> & vecAdd)
{
	string token;
	int pos = 0;
	string delimeter = " ";
	int x, y, z;

	while (1)
	{
		pos = strRead.find(delimeter);
		token = strRead.substr(0, pos);
		strRead.erase(0, pos + delimeter.length());
		if (0 == pos + 1)
		{
			strRead = "\0";
			break;
		}

		pos = strRead.find("/");
		token = strRead.substr(0, pos);
		x = stof(token);
		strRead.erase(0, pos + delimeter.length());

		pos = strRead.find("/");
		token = strRead.substr(0, pos);
		y = stof(token);
		strRead.erase(0, pos + delimeter.length());

		pos = strRead.find("/");
		token = strRead.substr(0, pos);
		z = stof(token);

		ST_PNT_VERTEX temp;
		temp.p = vecP[x - 1];
		temp.t = vecT[y - 1];
		temp.n = vecN[z - 1];

		vecAdd.push_back(temp);
	}
	// << readVn
}

void cObject::CheckMtl(string strRead)
{
	if (strstr(strRead.c_str(), ".mtl"))
	{
		int pos = strRead.find("/");
		m_strMtlFileName = strRead.substr(pos + 1, strRead.length()-1);

		strRead = "\0";
	}

	if (strstr(strRead.c_str(), "usemtl"))
	{
		int pos = strRead.find(" ");
		m_vecReadMtlUse.push_back(strRead.substr(pos + 1, strRead.length() - 1));

		if (m_vecReadMtlUse.size() == 1)
			m_vecMtlUseIndex.push_back(0);
		else
		{
			bool isIn = false;
			for (int i = 0; i < m_vecReadMtlUse.size(); i++)
			{
				if (m_vecReadMtlUse[i] == m_vecReadMtlUse[m_vecReadMtlUse.size() - 1])
				{
					m_vecMtlUseIndex.push_back(i);
					isIn = true;
					break;
				}
			}

			if (!isIn)
				m_vecMtlUseIndex.push_back(m_vecMtlUseIndex.size());
		}


		
		strRead = "\0";
	}

}

void cObject::Reset(vector<D3DXVECTOR3> &vecP, vector<D3DXVECTOR3> &vecN, vector<D3DXVECTOR2> &vecT, vector<ST_PNT_VERTEX> &vecAdd)
{
	vecP.clear();
	vecN.clear();
	vecT.clear();
	vecAdd.clear();
}

void cObject::ReadMtlFile()
{
	ifstream fp;
	string strRead;
	
	SetFilePath(m_strMtlFileName);
	fp.open(m_strMtlFileName); // , ios::in | ios::binary
	if (fp.is_open())
	{
		while (!fp.eof())
		{
			getline(fp, strRead);

			for (int i = 0; i < m_vecReadMtlUse.size(); i++)
			{
				if (strstr(strRead.c_str(), m_vecReadMtlUse[i].c_str()))
				{
					string temp;
					D3DMATERIAL9 tempMtrl;

					ZeroMemory(&tempMtrl, sizeof(D3DMATERIAL9));
					fp >> temp >> tempMtrl.Ambient.r >> tempMtrl.Ambient.g >> tempMtrl.Ambient.b;
					tempMtrl.Ambient.a = 1.0f;

					fp >> temp >> tempMtrl.Diffuse.r >> tempMtrl.Diffuse.g >> tempMtrl.Diffuse.b;
					tempMtrl.Diffuse.a = 1.0f;

					fp >> temp >> tempMtrl.Specular.r >> tempMtrl.Specular.g >> tempMtrl.Specular.b;
					tempMtrl.Specular.a = 1.0f;

					// ※ : d, Ns, illum은 읽어오지 않음

					while (1)
					{
						string temp;
						fp >> temp;
						if (temp == "map_Kd")
						{
							string str; //  = strRead.substr(pos + 1, strRead.length() - 1);
							fp >> str;
							SetFilePath(str);
							m_vecReadTexture.push_back(str);
							break;
						}
					}

					m_vecReadMtrl.push_back(tempMtrl);
					strRead = "\0";
				}
			}	// for
		}

		for (int i = 0; i < m_vecMtlUseIndex.size(); i++)
		{
			for (int j = 0; j < m_vecReadMtrl.size(); j++)
			{
				if (m_vecMtlUseIndex[i] == j)
				{
					m_vecMtrl.push_back(m_vecReadMtrl[j]);
					m_vecTextureFilePath.push_back(m_vecReadTexture[j]);
				}
			}
		}
	}
	else
	{
		MessageBox(g_hWnd, L"Error : MtlFileOpen", L"Error", MB_YESNO);
	}

	if (&fp != NULL)
		fp.close();
}

void cObject::SetFilePath(string & str)
{
	str = dFilePath + str;
}

void cObject::Render()
{
	if (g_pD3DDevice)
	{
		for (int i = 0; i < m_vecVertex.size(); i++)
		{
			g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
			g_pD3DDevice->SetMaterial(&m_vecMtrl[i]);

			D3DXMATRIXA16 matWorld;
			D3DXMatrixIdentity(&matWorld);
			g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

			g_pD3DDevice->SetFVF(ST_PNT_VERTEX::FVF);

			g_pD3DDevice->SetTexture(0, m_vecTexture[i]);
			// ?? : 0 -> i or 1로 하면 텍스쳐가 출력되지 않음

			g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 
										  m_vecVertex[i].size() / 3, 
										  &m_vecVertex[i][0], 
										  sizeof(ST_PNT_VERTEX));

			g_pD3DDevice->SetTexture(0, NULL);
		}
	}
}
