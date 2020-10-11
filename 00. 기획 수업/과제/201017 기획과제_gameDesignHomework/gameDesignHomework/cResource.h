#pragma once
#include "BasicHeader.h"

class cResource
{
private:
	int gold;
	int sheep;
	int wood;
	int brick;
	int flour;

	map<string, int> preTrade;
	
	cResource();

public:
	static cResource* GetInstance();
	~cResource();

	void SetUp();
	void Update();

	void AddResource(string name, int value);
	void MinusResource(string name, int value);

	bool CheckResourceZero(string name);
	bool CheckCanTrade(string name, int price);
};