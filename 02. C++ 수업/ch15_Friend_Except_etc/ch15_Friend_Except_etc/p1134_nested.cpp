#include<iostream>
#include<string>
#include"p1131_queuetp.h"

int main()
{
	using std::string;
	using std::cin;
	using std::cout;

	QueueTP<string> cs(5);
	string temp;

	while (!cs.IsFull())
	{
		cout << "�̸��� �Է��Ͻʽÿ�. �����Ͻ� ������� ����ǰ�� �帳�ϴ�.\n";
		getline(cin, temp);
		cs.Enqueue(temp);
	}

	cout << "ť�� ���� á���Ƿ�, ���ݺ��� ����ǰ�� ������ �帮�ڽ��ϴ�.\n";
	while (!cs.IsEmpty())
	{
		cs.Dequeue(temp);
		cout << temp << " ��! �����մϴ�. �ȳ��� ���ʽÿ�.\n";
	}

	return 0;
}