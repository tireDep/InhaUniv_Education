#include "Player.h"

CPlayer::CPlayer()
{
	m_strName = "Player";
}

CPlayer::~CPlayer()
{
}

void CPlayer::ReceiveMsg(string msg)
{
	if (msg == "w")
		cout << "Player input : W" << endl;
	else if (msg == "s")
		cout << "Player input : S" << endl;
	else if (msg == "a")
		cout << "Player input : A" << endl;
	else if (msg == "d")
		cout << "Player input : D" << endl;
}

string CPlayer::GetName()
{
	return m_strName;
}
