// 264p
#include<stdio.h>

int main()
{
	int aList[5] = { 0 };
	int i = 0;
	// int k = 5;
	// int aList[k] = { 0 };
	// 이런 형태는 불가능!

	for (i = 0; i < 5; i++)
	{
		scanf_s("%d", &aList[i]);
	}

	aList[0] = 100;
	aList[3] = 200;


	puts("");
	for (i = 0; i < 5; i++)
	{
		printf("%d\t %d\n", aList[i], &aList[i]);
	}

	printf("\n%d\t %d\n", aList[0], aList);
	return 0;

}
/*
----------------------------------
배열변수는 첫 번째 요소의 주소임
----------------------------------
*/