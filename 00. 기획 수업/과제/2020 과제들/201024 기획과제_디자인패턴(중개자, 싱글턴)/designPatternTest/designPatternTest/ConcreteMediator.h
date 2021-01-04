#pragma once
#include <vector>
#include <string>
#include "IMediator.h"
#include "ICollegue.h"

using std::vector;
using std::iterator;
using std::string;

class CConcreteMediator : public IMediator
{
private:
	vector<ICollegue*> m_vecCollegue;

public:
	CConcreteMediator();
	~CConcreteMediator();

	void SetUp();
	void Notify(ICollegue* sender, string strMsg) const;

	void AddCollegue(ICollegue *addColl);
	void RemoveCollegue(ICollegue *removeColl);
};
