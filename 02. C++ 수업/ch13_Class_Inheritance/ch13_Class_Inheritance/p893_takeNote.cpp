#include<iostream>
#include<list>

using namespace std;

class Fruit
{
public :
	Fruit();
	virtual ~Fruit();	// 상속을 할 예정이면 가상으로 만드는 것이 좋음
	virtual void Name()	// 각각 객체의 고유한 값을 사용하기 위해서는 virtual 작성해야 함
	{
		cout << "Fruit" << endl;
	}
};

Fruit::Fruit()
{
	cout << "Fruit()" << endl;
}

Fruit::~Fruit()
{
	cout << "~Fruit()" << endl;
}

class Apple : public Fruit // 상속
{
public:
	Apple(){ cout << "Apple()" << endl; }
	~Apple(){ cout << "~Apple()" << endl; }

	virtual void Name()
	{
		cout << "Apple" << endl;
	}

	void Test()
	{
		cout << "Apple - Test()" << endl;
	}
};

class Banana :public Fruit	// 상속
{
public:
	Banana() { cout << "Banana()" << endl; }
	~Banana() { cout << "~Banana()" << endl; }

	virtual void Name()
	{
		cout << "Banana" << endl;
	}
};

int main()
{
	list<class Fruit*> cl;
	// Apple* apple = new Apple;
	// Banana* banana = new Banana;
	
	Fruit* apple = new Apple;	// is a 관계
	Fruit* banana = new Banana;	// is a 관계

	cl.push_back((Fruit*)apple);	// 업캐스팅
	cl.push_back((Fruit*)banana);	// 업캐스팅
	apple->Name();
	banana->Name();

	// apple->Test(); // 없는 기능 확장한 거라 사용 x
	((Apple *)apple)->Test();	// 사용시 이런식으로 사용함

	for (list<class Fruit*>::iterator it = cl.begin(); it != cl.end();)
	{
		Fruit* a = (*it);
		delete a;
		it = cl.erase(it);
	}

	return 0;
}