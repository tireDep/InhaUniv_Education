// 171p
// Q : �����̹� ������� ���� ū �� ���ϱ� - ��������
// �Է¹����� -100 ~ 100 ���̷� �Է�, 5���ุ ����(���� ������)
#include<stdio.h>

int main()
{
	int nMax = -9999, nInput = 0;
	// int nMax, nInput = 0; ������
	
	scanf_s("%d", &nInput);
	nMax = nInput > nMax ? nInput : nMax;

	scanf_s("%d", &nInput);
	nMax = nInput > nMax ? nInput : nMax;

	scanf_s("%d", &nInput);
	nMax = nInput > nMax ? nInput : nMax;

	printf("Max : %d\n", nMax);
	
	return 0;
}