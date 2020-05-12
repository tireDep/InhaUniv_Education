// Q. 다음 코드를 작성하고 사용자가 15를 입력했다면 어떤 결과가 출력되는지 쓰세요.
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
// 출력결과 : 15, 20, 15