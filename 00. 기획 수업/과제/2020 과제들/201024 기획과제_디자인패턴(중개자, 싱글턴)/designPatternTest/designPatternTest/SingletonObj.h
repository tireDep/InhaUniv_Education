#pragma once
#include <iostream>
#include "Singleton.h"

using namespace std;

class CSingletonObj : public CSingleton<CSingletonObj>
{
private:
	int m_iNum;

public:
	void PrintSuccess();

	void SetNumber(int set);
	void PrintNumber();
};
