// Q. 다음 식을 만족하는 모든 A와 Z를 수하는 프로그램 작성
// AZ + ZA = 99
#include<stdio.h>

int main()
{
	/*
	99가 되는 수
	0,9 / 1,8 / 2,7 / 3,6 / 4,5  * 2
	*/

	int result = 0;

	// 더해서 99가 되는 수
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

	// 더해서 입력한 수가 되는 수
	puts("\n[AZ + ZA = InputNum]\n");
	int input;
	int check = 0;

	do
	{
		if (check == 1)
		{
			check = 0;
			puts("십의자리 숫자와 일의 자리 숫자가 같아야 함\n");
		}

		printf("숫자 입력 : ");
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
다른 방법
- A 0부터 1씩 증가, Z 최대값 부터 1씩 감소
- A가 최대값에 증가할 경우 FIN
--------------------------------------------------
*/