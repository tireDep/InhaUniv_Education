// 129p
// Q : �� ������ ���� �� ���
// �� ������ �Է¹޾� ���� ���, ��, ���� �߰� x
#include<stdio.h>

int main()
{
	int nInput, nTotal;
	
	// ------- �ڵ� �ۼ� ���� -------
	nInput = nTotal = 0;
	printf("Input Three Tumber\n");

	scanf_s("%d", &nInput);
	nTotal += nInput;

	scanf_s("%d", &nInput);
	nTotal += nInput;

	scanf_s("%d", &nInput);
	nTotal += nInput;
	puts("");

	// ------- �ڵ� �ۼ� ���� -------

	printf("Total : %d\n", nTotal);
	
	return 0;
}