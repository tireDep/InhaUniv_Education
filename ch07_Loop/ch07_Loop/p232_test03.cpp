// Q. �Է¹��� ������ ����� ����ϴ� ���α׷��� �ۼ�
// ���� 
// 1) �� ���� ������ �Է��� ������ �����, �� ����ŭ �Է¹ޱ�
// 2) ��� ���� �Ҽ��� ���� 2�ڸ����� ���
#include<stdio.h>

int main()
{
	int input = 0;
	float result = 0;

	printf("�Է� �� ���� �Է� : ");
	scanf_s("%d", &input);

	int cnt = 0;
	int addNum = 0;
	while (cnt < input)
	{
		printf("\n�Է� : ");
		scanf_s("%d", &addNum);
		result += addNum;
		cnt++;
	}

	result = result / input;
	printf("\n��� �� : %.2f\n",result);
	
	return 0;
}