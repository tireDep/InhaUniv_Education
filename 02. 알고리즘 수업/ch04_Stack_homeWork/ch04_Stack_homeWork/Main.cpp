/*

Q. å�� ���� ��� Stack ���� �Լ����� �� �� �ִ� ���α׷��� ������ ��Ÿ�Ϸ� �ٽ� ����ÿ�.

Initialize.		���� �ʱ�ȭ.
Push.			���� Ǫ��.
Pop.			���� ��.
Peek.			���� ��ũ.
Clear.			���� ����.
Capacity.		������ �ִ� �뷮.
Size.			������ ������ ����.
IsEmpty.		������ ����ִ��� Ȯ��.
IsFull.			������ ���� �� �ִ��� Ȯ��.
Search.			���� �˻�.
Print.			���� �� ��� ������ ���.
Terminate.		���� ����.

*/

#include<iostream>
#include"_stack.h"

using namespace std;

int main()
{
	STACK_S stack;

	int inputNum = 0;
	cout << "������ ���� �Է� : ";
	cin >> inputNum;

	if (Initialize(&stack, inputNum) == false)
	{
		cout << "\n���� : ���� ���� ����\n\n";
		return 0;
	}

	int inputMenu, inputValue;
	while (1)
	{
		cout << "\n���� ������ �� : " << GetSize(stack) << " / " << GetCapacity(stack) << endl;
		cout << "\n1) Push 2) Pop 3) Peek \n4) Print 5) Search 6) Clear 0) Exit\n\n�Է� : ";
		cin >> inputMenu;

		if (inputMenu == 0)
			break;
		
		switch (inputMenu)
		{
		case 1:
			if (!Push(&stack))
				cout << "\n������ �Է� ����" << endl;
			else
				cout << "\n������ �Է� ����" << endl;
			break;
		case 2:
			int popData;
			if (!Pop(&stack, &popData))
				cout << "\n���ÿ� �����Ͱ� �������� ����" << endl;
			else
				cout << "Pop ��� : " << popData << endl;
			break;
		case 3:
			int peekData;
			if (!Peek(&stack, &peekData))
				cout << "\n���ÿ� �����Ͱ� �������� ����" << endl;
			else
				cout << "Peek ��� : " << peekData << endl;
			break;
		case 4:
			Print(stack);
			break;
		case 5:
			if(!Search(stack))
				cout << "\n�˻� ��� : �ش� �����Ͱ� �������� ����" << endl;
			break;
		case 6:
			Clear(&stack);
			cout << "\n���� �ʱ�ȭ �Ϸ�" << endl;
			break;

		default:
			cout << "\n�߸��� �� �Է�" << endl;
			break;
		}
	}

	cout << "���α׷� ����" << endl;
	Terminate(&stack);

	return 0;
}