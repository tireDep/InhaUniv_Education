#include<iostream>

using namespace std;

class AA
{
public:
	AA() {};
	virtual ~AA() {};
	virtual void Call() = 0;	// ���� ����
};

class AB : public AA
{
public:
	AB() {};
	~AB() {};
	void Call()
	{
		cout << typeid(*this).name() << endl;	// Ŭ������ �̸� ���
		// typeid : Ŭ������ ��ü�� �������� �˷���
	}
};

int main()
{
	AB at;
	at.Call();

	// at = static_cast<AA *> (&at);
	if (typeid(AB) == typeid(at))
	{
		cout << typeid(AB).name() << endl;
	}
	else
	{
		cout << "���� �ٸ� Ŭ����" << endl;
	}

	return 0;
}