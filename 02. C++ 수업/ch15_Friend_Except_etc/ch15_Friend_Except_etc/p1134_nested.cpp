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
		cout << "이름을 입력하십시오. 도착하신 순서대로 사은품을 드립니다.\n";
		getline(cin, temp);
		cs.Enqueue(temp);
	}

	cout << "큐가 가득 찼으므로, 지금부터 사은품을 나누어 드리겠습니다.\n";
	while (!cs.IsEmpty())
	{
		cs.Dequeue(temp);
		cout << temp << " 님! 감사합니다. 안녕히 가십시오.\n";
	}

	return 0;
}