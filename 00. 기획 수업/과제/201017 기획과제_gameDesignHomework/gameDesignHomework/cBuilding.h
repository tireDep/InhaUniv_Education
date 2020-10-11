#pragma once
#include "BasicHeader.h"

class cBuilding
{
private:
	string typeName;
	Position pos;
	int gainDate;
	int status;

public:
	cBuilding();
	~cBuilding();

	void Update();
	void Render();

	bool CheckGainResource();

};
