#pragma once
#include "cMtlTex.h"
#include "cObject.h"
#include "cGeoObject.h"

class cCharObjectLoader : public cObject
{
private:
	vector<cMtlTex*> m_vecMtrlTex;
	vector<string> m_vecMtrlName;

public:
	cCharObjectLoader();
	~cCharObjectLoader();

	void Load(OUT cGeoObject* &pGeoObject, IN char* szFolder, IN char* szFile);

	// void LoadMtlLib(FILE *fp, char szTemp[], char* szFolder, char* szTextFile);
	// void LoadObject(OUT cGeoObject* &pGeoObject, FILE *fp, char szTemp[], char* szFolder, char* szTextFile);

	void CalcNormalVector(vector<ST_PNT_VERTEX>& vecVertex);
};