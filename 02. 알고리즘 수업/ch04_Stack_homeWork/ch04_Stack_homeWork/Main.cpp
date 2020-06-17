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
		cout << "1) Push 2) Pop 3) Peek 4) Print 5) Search 6) Clear 0) Exit\n\n�Է� : ";
		cin >> inputMenu;

		if (inputMenu == 0)
			break;
		
		switch (inputMenu)
		{
		case 1:
			Push();
			break;
		case 2:
			Pop();
			break;
		case 3:
			Peek();
			break;
		case 4:
			Print();
			break;
		case 5:
			Search();
			break;
		case 6:
			Clear();
			break;

		default:
			cout << "\n�߸��� �� �Է�" << endl;
			break;
		}

	}

	cout << "���α׷� ����" << endl;

	return 0;
}