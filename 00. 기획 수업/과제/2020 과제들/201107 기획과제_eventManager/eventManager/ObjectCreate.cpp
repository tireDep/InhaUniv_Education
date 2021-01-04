#include "ObjectCreate.h"

CObjectCreate::CObjectCreate()
{
	m_strName = "object";
}

CObjectCreate::~CObjectCreate()
{
}

void CObjectCreate::ReceiveMsg(string msg)
{
	if (msg == "1")
		cout << "Object : 1 Create" << endl;
	else if (msg == "2")
		cout << "Object : 2 Create" << endl;
	else if (msg == "3")
		cout << "Object : 3 Create" << endl;
}

string CObjectCreate::GetName()
{
	return m_strName;
}
