// Q. 요소의 값을 교환하는 방식으로 배열에서 최소값 구하기
#include<stdio.h>

int main()
{
	int aList[5] = { 30,40,10,50,20 };
	int i = 0, nTemp = 0;

	// -------- 코드 작성 부분 ---------
	for (i = 0; i < 4; i++)
	{
		if (aList[i+1] < aList[0])
		{
			nTemp = aList[0];
			aList[0] = aList[i+1];
			aList[i+1] = nTemp;
		}
	}
	// ------- 코드 수정 X 부분 --------

	for (i = 0; i < 5; i++)
	{
		printf("%d\t", aList[i]);
	}
	putchar('\n');

	printf("MIN : %d\n", aList[0]);
	return 0;
}