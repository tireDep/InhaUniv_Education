#pragma once
#include "cResource.h"
#include "cBuilding.h"
#include "cCharacter.h"

class cPlayer : public cCharacter
{
private:
	cResource *m_resource = cResource::GetInstance();
	vector<cBuilding> m_vecBuilding;

	cPlayer();

public:
	~cPlayer();

	static cPlayer* GetInstance();

	void SetUp();
	void Update();
	void Render();

	bool Explor(Position position);
	bool Build(Position position, string type);
};
