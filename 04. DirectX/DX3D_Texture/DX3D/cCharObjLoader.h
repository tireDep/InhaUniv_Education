#pragma once
#include "cCharObjGroup.h"
#include "cMtlTex.h"

class cCharObjLoader
{
private:
	vector<cMtlTex *> m_vecMtlTex;

public:
	cCharObjLoader();
	~cCharObjLoader();

	void Load(OUT vector<cCharObjGroup*>&vecGroup, IN char* szFolder, IN char* szFile);
	void LoadMtlLib(FILE *fp, char szTemp[], char* szFolder, char* szTextFile);

	void LoadObject(OUT vector<cCharObjGroup*>& vecGroup, FILE *fp, char szTemp[], char* szFolder, char* szTextFile);
};