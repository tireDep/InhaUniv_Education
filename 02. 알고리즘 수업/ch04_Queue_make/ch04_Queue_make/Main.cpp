#include<iostream>
#include"_Queue.h"

using namespace std;

int main()
{
	QUEUE_S queue;
	if (!Initalize(queue))
		return 0;
	else
		cout << "ť ���� �Ϸ�\n\n";

	int inputMenu;
	int resultVal;
	while (1)
	{
		cout << "���� ������ �� : " << GetCnt(queue) << " / " << GetMax(queue) << endl;
		cout << "\n1) ��ť 2) ��ť 3) ��ũ \n4) ��� 5) �˻� 6) �ʱ�ȭ 0) ����\n\n�Է� : ";
		cin >> inputMenu;

		switch (inputMenu)
		{
		case 1:
			if (Enque(queue))
				cout << "\n������ �Է� ����\n";
			break;
		case 2:
			if (Deque(queue, resultVal))
				cout << "\n\n��ť �� : " << resultVal << endl;
			break;
		case 3:
			if (Peek(queue, resultVal))
				cout << "\n\n��ũ �� : " << resultVal << endl;
			break;
		case 4:
			if (Print(queue))
				cout << "\n��� ����\n\n";
			break;
		case 5:
			Search(queue);
			cout << "�˻� ����\n\n";
			break;
		case 6:
			Clear(queue);
			cout << "�ʱ�ȭ �Ϸ�\n\n";
			break;
		case 0:
			cout << "���α׷� ����\n\n";
			break;
		default:
			cout << "�߸��� �� �Է�\n\n";
			break;
		}
	}

	Terminate(queue);

	return 0;
}