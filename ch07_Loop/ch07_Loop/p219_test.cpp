// Q. ���� �ڵ带 �ۼ��ϰ� ����ڰ� 15�� �Է��ߴٸ� � ����� ��µǴ��� ������.
#include<stdio.h>

int main()
{
	int nInput = 0;
	scanf_s("%d", &nInput);

	if (nInput > 10)
	{
		int nInput = 20;
		printf("%d\n", nInput);

		if (nInput < 20)
		{
			int nInput = 30;
			printf("%d\n", nInput);
		}
	}
	printf("%d\n", nInput);
	return 0;
}
// ��°�� : 15, 20, 15