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
		m_vecStrMtlSet.push_back(strRead.substr(pos + 1, strRead.length() - 1));
		// m_vecStrMtlSet = (strRead.substr(pos + 1, strRead.length() - 1));

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
	bool isTextureAdd = false;
	
	SetFilePath(m_strMtlFileName);
	fp.open(m_strMtlFileName); // , ios::in | ios::binary
	if (fp.is_open())
	{
		while (!fp.eof())
		{
			getline(fp, strRead);

			for (int i = 0; i < m_vecStrMtlSet.size(); i++)
			{
				if (strstr(strRead.c_str(), m_vecStrMtlSet[i].c_str()))
				{
					isTextureAdd = true;
					string temp;
					D3DMATERIAL9 tempMtrl;
					fp >> temp >> tempMtrl.Ambient.r >> tempMtrl.Ambient.g >> tempMtrl.Ambient.b;
					tempMtrl.Ambient.a = 1.0f;

					fp >> temp >> tempMtrl.Diffuse.r >> tempMtrl.Diffuse.g >> tempMtrl.Diffuse.b;
					tempMtrl.Diffuse.a = 1.0f;

					fp >> temp >> tempMtrl.Specular.r >> tempMtrl.Specular.g >> tempMtrl.Specular.b;
					tempMtrl.Specular.a = 1.0f;

					// ※ : d, Ns, illum은 읽어오지 않음

					m_vecMtrl.push_back(tempMtrl);
					strRead = "\0";
				}

				if (strstr(strRead.c_str(), "map_Kd"))
				{
					int pos = strRead.find(" ");
					string str = strRead.substr(pos + 1, strRead.length() - 1);
					SetFilePath(str);
					m_vecTextureFilePath.push_back(str);

					strRead = "\0";
				}
			}	// for

			if (!isTextureAdd)
			{

			}

		}
	}
	else
	{
		MessageBox(g_hWnd, L"Error : MtlFileOpen", L"Error", MB_YESNO);
	}

	MessageBox(g_hWnd, L"fin", L"fin", MB_YESNO);

	if (&fp != NULL)
		fp.close();
}

void cObject::SetFilePath(string & str)
{
	str = dFilePath + str;
}

void cObject::Render()
{
	for (int i = 0; i < m_vecVertex.size(); i++)
	{
		if (g_pD3DDevice)
		{
			g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
			g_pD3DDevice->SetMaterial(&m_vecMtrl[i]);

			D3DXMATRIXA16 matWorld;
			D3DXMatrixIdentity(&matWorld);
			g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

			g_pD3DDevice->SetFVF(ST_PNT_VERTEX::FVF);
			
			// >>
			int len;
			int sLength = m_vecTextureFilePath[i].length() + 1;
			len = MultiByteToWideChar(CP_ACP, 0, m_vecTextureFilePath[i].c_str(), sLength, 0, 0);

			wchar_t* buffer = new wchar_t[len];
			MultiByteToWideChar(CP_ACP, 0, m_vecTextureFilePath[i].c_str(), sLength, buffer, len);

			wstring result(buffer);
			delete[] buffer;

			LPCWSTR lFileName = result.c_str();
			// <<

			LPDIRECT3DTEXTURE9 texture;
			D3DXCreateTextureFromFile(g_pD3DDevice, lFileName, &texture);
			g_pD3DDevice->SetTexture(i, texture);

			g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 
										  m_vecVertex[i].size() / 3, 
										  &m_vecVertex[i][0], 
										  sizeof(ST_PNT_VERTEX));

			g_pD3DDevice->SetTexture(0, NULL);
		}
	}
}
