// Q. ���밪�� ���ϴ� �Լ� Abs() ���� 
// -> Ű���带 ���� �Է� �޴� ���밪�� ���ϴ� ���α׷�
// ex) ������ �Է��Ͻÿ� : -34
//	   ���밪�� 34 �Դϴ�.

#include<stdio.h>

void Abs(int num);
void Result(int result);

int main()
{
	int inputNum;
	printf("������ �Է� �Ͻÿ� : ");
	scanf_s("%d", &inputNum);

	Abs(inputNum);

	return 0;
}

void Abs(int num)
{
	if (0 > num)
	{
		return Result(num*-1);
	}
	else
	{
		return Result(num);
	}
}

void Result(int result)
{
	printf("���밪�� %d �Դϴ�\n", result);
}