/*
-------------------------------------------------------------------
�Լ� ��ü
- �Լ�ó�� �����ϴ� ��ü
- �Լ�ó�� �����Ϸ��� ��ü�� operator()�� �����ؾ� ��

- �Լ� ��ü�� �Լ�ó�� �����ϴ� ��ü�̹Ƿ� �ٸ� ��� ������ ��� �Լ��� ���� �� �ְ�,
�Ϲ� �Լ����� ���� ���ϴ� ������ ���� �� ����
- �Լ� ��ü�� ������ ������ ��ü Ÿ���� �ٸ��� ���� ���� �ٸ� Ÿ������ �ν�
- �ӵ��� �Ϲ� �Լ����� ������(�ζ��� ����, �����Ϸ��� ���� ����ȭ)
- Ư�� ��Ȳ���� �Լ� ��ü�� �Լ����� ����
-> ���� �Լ��� �ٸ� �Լ��� ���ڷ� ������ �� ����� ��, �Ϲ��Լ��� �ζ���ȭ �� �� ������, ��ü�� �ζ���ȭ �� �� �ִ�

��ũ��(Fuctor)
- ���ʷ�����(generator)�� �Ű����� ���� ȣ���ϴ� �Լ�
- ���� �Լ�(unary function)�� �ϳ��� �Ű������� ȣ���ϴ� �Լ�
- ���� �Լ�(binary fuction)�� �� ���� �Ű������� ȣ���ϴ� �Լ�

- bool ���� �����ϴ� ���� �Լ��� ����(predicate)�̴�
- bool ���� �����ϴ� ���� �Լ��� ���� ����(binary predicate)�̴�

- ����
1) �Լ� ��ü�� ���� ������ ���� �� ����, ����ڰ� �Լ� ��ü�� ����ϸ鼭 �ٸ� ���¸� ���� �� ����
2) �Լ� ��ü�� �ڽŸ��� Ÿ���� ���� �� ����, �̸� �̿��� ���� �ٸ� �Լ�-��ü�� ���� �����̳ʸ� ���� �� ����
3) �ӵ��� ����, �Լ��� inline���� ����� �� ���� ���� �Լ� ��ü�� inline���� ����� �� ����
-------------------------------------------------------------------
*/

#include<iostream>
#include<list>
#include<iterator>
#include<algorithm>

template<class T>	// ��ũ�� Ŭ������ operator() ()�� �����Ѵ�
class TooBig
{
private:
	T cutoff;
public:
	TooBig(const T &t) :cutoff(t) { }
	bool operator() (const T &v) { return v > cutoff; }
};

void OutInt(int n) { std::cout << n << " "; }

int main()
{
	using std::list;
	using std::cout;
	using std::endl;

	TooBig<int> f100(100);
	int vals[10] = { 50,100,90,180,60,210,415,88,188,201 };
	list<int>yadayada(vals, vals + 10);	// range ������
	list<int>etcetera(vals, vals + 10);

	cout << "������ ����Ʈ\n";
	for_each(yadayada.begin(), yadayada.end(), OutInt);
	cout << endl;
	yadayada.remove_if(f100);	// �̸��� �ִ� �Լ� ��ü ���	// functor
	etcetera.remove_if(TooBig<int>(200));	// �Լ� ��ü�� ����
	cout << "����� ����Ʈ\n";
	for_each(yadayada.begin(), yadayada.end(), OutInt);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), OutInt);
	cout << endl;

	return 0;

}
