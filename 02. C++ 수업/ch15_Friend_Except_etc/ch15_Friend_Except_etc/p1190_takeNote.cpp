#include<iostream>

using namespace std;

class AA
{
public:
	AA() {};
	virtual ~AA() {};
	virtual void Call() = 0;	// 순수 가상
};

class AB : public AA
{
public:
	AB() {};
	~AB() {};
	void Call()
	{
		cout << typeid(*this).name() << endl;	// 클래스의 이름 출력
		// typeid : 클래스의 정체가 무엇인지 알려줌
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
		cout << "서로 다른 클래스" << endl;
	}

	return 0;
}