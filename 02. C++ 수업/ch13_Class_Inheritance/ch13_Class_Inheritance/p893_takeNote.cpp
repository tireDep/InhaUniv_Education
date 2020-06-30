#include<iostream>
#include<list>

using namespace std;

class Fruit
{
public :
	Fruit();
	virtual ~Fruit();	// ����� �� �����̸� �������� ����� ���� ����
	virtual void Name()	// ���� ��ü�� ������ ���� ����ϱ� ���ؼ��� virtual �ۼ��ؾ� ��
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

class Apple : public Fruit // ���
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

class Banana :public Fruit	// ���
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
	
	Fruit* apple = new Apple;	// is a ����
	Fruit* banana = new Banana;	// is a ����

	cl.push_back((Fruit*)apple);	// ��ĳ����
	cl.push_back((Fruit*)banana);	// ��ĳ����
	apple->Name();
	banana->Name();

	// apple->Test(); // ���� ��� Ȯ���� �Ŷ� ��� x
	((Apple *)apple)->Test();	// ���� �̷������� �����

	for (list<class Fruit*>::iterator it = cl.begin(); it != cl.end();)
	{
		Fruit* a = (*it);
		delete a;
		it = cl.erase(it);
	}

	return 0;
}