// Q. ���� ���� �����ϴ� ��� A�� Z�� ���ϴ� ���α׷� �ۼ�
// AZ + ZA = 99
#include<stdio.h>

int main()
{
	/*
	99�� �Ǵ� ��
	0,9 / 1,8 / 2,7 / 3,6 / 4,5  * 2
	*/

	int result = 0;

	// ���ؼ� 99�� �Ǵ� ��
	puts("[AZ + ZA = 99]");
	for (int numA = 0; numA < 10; numA++)
	{
		for (int numZ = 0; numZ < 10; numZ++)
		{
			result = (numA * 10 + numZ) + (numZ * 10 + numA);

			if (result == 99)
			{
				printf("%d%d + %d%d = %d\n", numA, numZ, numZ, numA, result);
			}
		}
	}

	// ���ؼ� �Է��� ���� �Ǵ� ��
	puts("\n[AZ + ZA = InputNum]\n");
	int input;
	int check = 0;

	do
	{
		if (check == 1)
		{
			check = 0;
			puts("�����ڸ� ���ڿ� ���� �ڸ� ���ڰ� ���ƾ� ��\n");
		}

		printf("���� �Է� : ");
		scanf_s("%d", &input);
		check = 1;

	} while (input % 10 != input / 10);

	for (int numA = 0; numA < 10; numA++)
	{
		for (int numZ = 0; numZ < 10; numZ++)
		{
			result = (numA * 10 + numZ) + (numZ * 10 + numA);

			if (result == input)
			{
				printf("\n%d%d + %d%d = %d", numA, numZ, numZ, numA, result);
			}
		}
	}
	puts("");

	return 0;

}

/*
--------------------------------------------------
�ٸ� ���
- A 0���� 1�� ����, Z �ִ밪 ���� 1�� ����
- A�� �ִ밪�� ������ ��� FIN
--------------------------------------------------
*/