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
	D3DXVECTOR3	readP;
	vector<D3DXVECTOR3> vecReadP;

	D3DXVECTOR3	readN;
	vector<D3DXVECTOR3> vecReadN;

	D3DXVECTOR2	readT;
	vector<D3DXVECTOR2> vecReadT;

	vector<ST_PNT_VERTEX> vecAddPNT;

	// >> obj
	bool isCheck = false;
	ifstream fp;
	string strRead;
	fp.open("../object/box.obj"); // , ios::in | ios::binary
	if (fp.is_open())
	{
		while (!fp.eof())
		{
			getline(fp, strRead);

			// <<
			if (strstr(strRead.c_str(), ".mtl"))
			{
				m_strMtrl = strRead;
				continue;
			}
			// >> mtrl 정보

			if (strstr(strRead.c_str(), "v "))
			{
				string token;
				int pos = 0;
				string delimeter = " ";
				
				// >> readV
				{
					pos = strRead.find(delimeter);
					token = strRead.substr(0, pos);
					strRead.erase(0, pos + 2);

					pos = strRead.find(delimeter);
					token = strRead.substr(0, pos);
					readP.x = stof(token);
					strRead.erase(0, pos + delimeter.length());

					pos = strRead.find(delimeter);
					token = strRead.substr(0, pos);
					readP.y = stof(token);
					strRead.erase(0, pos + delimeter.length());

					pos = strRead.find(delimeter);
					token = strRead.substr(0, pos);
					readP.z = stof(token);
					strRead.erase(0, pos + delimeter.length());

					vecReadP.push_back(readP);
				}
				// << readV
			}

			if (strstr(strRead.c_str(), "vt "))
			{
				string token;
				int pos = 0;
				string delimeter = " ";

				// >> readVt
				{
					pos = strRead.find(delimeter);
					token = strRead.substr(0, pos);
					strRead.erase(0, pos + 2);

					pos = strRead.find(delimeter);
					token = strRead.substr(0, pos);
					readT.x = stof(token);
					strRead.erase(0, pos + delimeter.length());

					pos = strRead.find(delimeter);
					token = strRead.substr(0, pos);
					readT.y = stof(token);
					strRead.erase(0, pos + delimeter.length());

					vecReadT.push_back(readT);
				}
				// << readVt
			}

			if (strstr(strRead.c_str(), "vn "))
			{
				string token;
				int pos = 0;
				string delimeter = " ";

				// >> readVn
				{
					pos = strRead.find(delimeter);
					token = strRead.substr(0, pos);
					strRead.erase(0, pos + 2);

					pos = strRead.find(delimeter);
					token = strRead.substr(0, pos);
					readN.x = stof(token);
					strRead.erase(0, pos + delimeter.length());

					pos = strRead.find(delimeter);
					token = strRead.substr(0, pos);
					readN.y = stof(token);
					strRead.erase(0, pos + delimeter.length());

					pos = strRead.find(delimeter);
					token = strRead.substr(0, pos);
					readN.z = stof(token);
					strRead.erase(0, pos + delimeter.length());

					vecReadN.push_back(readN);
				}
				// << readVn
			}

			if (strstr(strRead.c_str(), "g "))
			{
				// >> setIndex_fx
				while (!strstr(strRead.c_str(),"g") || strstr(strRead.c_str(), "g "))
				{
					getline(fp, strRead);

					if (strstr(strRead.c_str(), "usemtl"))
					{
						m_strMtrlSet = strRead;
						continue;
					}
					// >> mtrl 정보

					if (strstr(strRead.c_str(), "f "))
					{
						// parse & save
						string token;
						int pos = 0;
						string delimeter = " ";
						int x, y, z;

						while(1)
						{
							pos = strRead.find(delimeter);
							token = strRead.substr(0, pos);
							strRead.erase(0, pos + delimeter.length());
							if (0 == pos + 1)
								break;

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
							temp.p = vecReadP[x - 1];
							temp.t = vecReadT[y - 1];
							temp.n = vecReadN[z - 1];

							vecAddPNT.push_back(temp);
						}
						// << readVn
					}
				}
				// << setIndex

				// >> add & reset
				m_vecVertex.push_back(vecAddPNT);
				vecReadP.clear();
				vecReadT.clear();
				vecReadN.clear();
				vecAddPNT.clear();
				// << add & reset
			} // if_g objName

		}	// while
	}	// if is_Open()
	else
	{
		MessageBox(g_hWnd, L"Error", L"Error", MB_YESNO);
	}
	// << obj

	MessageBox(g_hWnd, L"fin", L"fin", MB_YESNO);

	fp.close();

}
