// 119p
// Q : �ʸ� '��:��:��'�� ��ȯ�ϴ� ���α׷�
// �����Է�, ���ڸ� ������ ǥ��(���ڸ��� 0x)
#include<stdio.h>

int main()
{
	int inputSec = 0;
	printf("�ʸ� �Է��ϼ��� : ");
	scanf_s("%d", &inputSec);

	int hour = inputSec / 3600;
	int min = inputSec % 3600 / 60; // hour ������ ��
	int sec = inputSec % 3600 % 60; // min ������ ��

	printf("%d�ʴ� %02d�ð� %02d�� %02d�� �Դϴ�.\n", inputSec, hour, min, sec);
	
	return 0;
}
// ���!!!!!

// ---------- ���� ----------
// int n = 0, m = 50, k = 10;
// printf("%d %d %d", n = 10, m = n / k, k = 10 / n);
//
// �̷��ĵ� ������ �ѵ� ���� ��� ���ؾ���!
// �� �ڵ��� ��� 10/0�� ���� ���۵Ǿ �����߻�
// --------------------------