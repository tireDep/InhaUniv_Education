// Q. ���̰� 7�� int�� �迭�� �����ϰ�, ����ڷκ��� �� 7���� ������ �Է¹޾�
// �Էµ� ���� �� �ִ�&�ּڰ�, ������ �� ���� ����ϴ� ���α׷� �ۼ�
#include<stdio.h>

int main()
{
	int nArray[7] = { 0 };
	int input;

	for (int i = 0; i < 7; i++)
	{
		scanf_s("%d", &input);
		nArray[i] = input;
	}

	int min = nArray[0];
	int max = nArray[0];
	int sum = 0;
	for (int i = 0; i < sizeof(nArray) / sizeof(int); i++)
	{

		/*
		if (max < nArray[i])
		{
		max = nArray[i];
		}

		if (min > nArray[i])
		{
		min = nArray[i];
		}
		*/

		max = max < nArray[i] ? nArray[i] : max;
		min = min > nArray[i] ? nArray[i] : min;
		// ���� ������ -> ? �� : ����

		sum += nArray[i];
	}

	printf("\nMax : %d\n", max);
	printf("Min : %d\n", min);
	printf("Sum : %d\n", sum);

	return 0;
}