// Q. ��Ģ ���� ���α׷��� �Լ� ȣ�� ���·� ������
// ����
// 1. �޴����
// 2. �� �Է�
// 3. ����
// 4. ��� ���
// ������ �Լ��� ����� ȣ���ؼ� ����� �� �ֵ��� �� ��

#include<stdio.h>

int SelectMenu();

int InputNumber(int selectNum);

int PlusFuc(int num1, int num2);
int MinusFuc(int num1, int num2);
int MultFuc(int num1, int num2);
int DivFuc(int num1, int num2);

void ResultFuc(int result);

int main()
{
	int _input;
	int result;
	
	while (1)
	{
		_input = SelectMenu();
		if (_input == 5)
		{
			return 0;
		}
		result = InputNumber(_input);
		ResultFuc(result);
	}

	return 0;
}	// main()

int SelectMenu()
{
	int input;
	printf("[���ϴ� ���� ����]\n1. +\t2. -\t3. x\t4. %%\t5. ���� \n");
	printf("�Է� : ");
	scanf_s("%d", &input);
	return input;
}	// int SelectMenu()

int InputNumber(int selectNum)
{
	int result = 0;
	
	int num1, num2;
	printf("���� �Է� : ");
	scanf_s("%d %d", &num1, &num2);

	switch (selectNum)
	{
		case 1:
			result = PlusFuc(num1, num2);
			break;
		case 2:
			result = MinusFuc(num1, num2);
			break;
		case 3:
			result = MultFuc(num1, num2);
			break;
		case 4:
			result = DivFuc(num1, num2);
			break;
		default:
			puts("ERROR");
			return 0;
	}
	return result;
}	// int InputNumber(int selectNum)

int PlusFuc(int num1, int num2)
{
	puts("\n[���� ����]");	
	return num1 + num2;
}	// int PlusFuc(int num1, int num2)

int MinusFuc(int num1, int num2)
{
	puts("\n[���� ����]");
	return num1 - num2;
}	// int MinusFuc(int num1, int num2)

int MultFuc(int num1, int num2)
{
	puts("\n[���� ����]");
	return num1 * num2;
}	// int MultFuc(int num1, int num2)

int DivFuc(int num1, int num2)	
{
	puts("\n[������ ����]");
	return num1 / num2;
}	// int DivFuc(int num1, int num2)	

void ResultFuc(int result)
{
	printf("����� : %d\n\n", result);
	return;
}	// void ResultFuc(int result)