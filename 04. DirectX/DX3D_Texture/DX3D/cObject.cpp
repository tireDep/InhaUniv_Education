#include "stdafx.h"
#include "cObject.h"

#include <fstream>
#include <string>


cObject::cObject()
{

}

cObject::~cObject()
{

}

void cObject::ReadFileData()
{
	ReadObjFile();
}

void cObject::ReadObjFile()
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
	fp.open("../object/box.obj"); // , ios::in | ios::binary
	if (fp.is_open())
	{
		while (!fp.eof())
		{
			getline(fp, strRead);

			CheckMtrl(strRead);

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
		MessageBox(g_hWnd, L"Error : FileOpen", L"Error", MB_YESNO);
	}

	MessageBox(g_hWnd, L"fin", L"fin", MB_YESNO);

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

void cObject::CheckMtrl(string strRead)
{
	if (strstr(strRead.c_str(), ".mtl"))
	{
		m_strMtrl = strRead;
		strRead = "\0";
	}

	if (strstr(strRead.c_str(), "usemtl"))
	{
		m_strMtrlSet = strRead;
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
