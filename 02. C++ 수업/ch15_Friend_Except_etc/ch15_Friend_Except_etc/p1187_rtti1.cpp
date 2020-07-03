#include<iostream>
#include<cstdlib>
#include<ctime>

using std::cout;

class Grand
{
private:
	int hold;

public:
	Grand(int h = 0) : hold(h) { }
	virtual void Speak() const { cout << "나는 Grand 클래스이다!\n"; }
	virtual int Value() const { return hold; }
};

class Superb : public Grand
{
public:
	Superb(int h = 0) : Grand(h) { }
	void Speak() const { cout << "나는 Superb 클래스이다!!\n"; }
	virtual void Say() const { cout<< "내가 가지고 있는 Superb값은 " << Value() << "이다.\n"; }
};

class Magnificent : public Superb
{
private:
	char ch;
	
public:
	Magnificent(int h = 0, char c = 'A') : Superb(h), ch(c) { }
	void Speak()const { cout << "나는 Magnificent 클래스이다!!\n"; }
	void Say() const { cout << "내가 가지고 있는 문자는 " << ch << "이고, 정수는 " << Value() << "이다.\n"; }

};

class Test
{
private:
	int temp;

public:
	Test() { }
	void TestPrint() const { cout << "test 클래스" << std::endl; }
};

class Test2 : public Test
{
public:
	void TestPrint2() const { cout << "test2 클래스" << std::endl; }
};

Grand * GetOne();

int main()
{
	std::srand(std::time(0));
	Grand *pg;
	Superb *ps;

	for (int i = 0; i < 5; i++)
	{
		pg = GetOne();
		pg->Speak();
		if (ps = dynamic_cast<Superb *>(pg))
			ps->Say();
	}

	// Test *tt;
	// Test2 *tt2;
	// for (int i = 0; i < 5; i++)
	// {
	// 	if (tt2 = dynamic_cast<Test2 *>(tt))
	// 		cout << "isOk\n";
	// }
	return 0;
}

Grand * GetOne()
{
	Grand *p = NULL;

	switch (std::rand()%3)
	{
	case 0:
		p = new Grand(std::rand() % 100);
		break;
	case 1:
		p = new Superb(std::rand() % 100);
		break;
	case 2:
		p = new Magnificent(std::rand() % 100, 'A' + std::rand() % 26);
		break;
	default:
		break;
	}

	return p;
}