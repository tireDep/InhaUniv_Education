// Q. ����ڷκ��� ����ؼ� ���� �Է� �ް� ����, 
// 0�� �Է��� �� ���� �����ϸ� 0�� �Էµ� ��� ������ �� ��� �� ����
#include<stdio.h>

int main()
{
	int input = 1;
	int result = 0;

	while (input != 0)
	{
		printf("�� �Է�(0�Է� �� ����) : ");
		scanf_s("%d", &input);

		result += input;
	}

	printf("\n��� : %d\n", result);
	return 0;

}