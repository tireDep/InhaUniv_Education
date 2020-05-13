// Q. 배열에서 최댓값 구하기
// 조건 : 새로운 변수 선언 x, 출력결과가 다음과 같아야 함
// 출력 값 : 50 40 10 50 20 \n MAX : 50 
#include<stdio.h>

int main()
{
	int aList[5] = { 30,40,10,50,20 };
	int i = 0;

	// -------- 코드 작성 부분 ---------
	for (i = 0; i < 4; i++)
	{
		if (aList[0] < aList[i + 1])
		{
			aList[0] = aList[i + 1];
		}
	}
	// ------- 코드 수정 X 부분 --------

	for (i = 0; i < 5; i++)
	{
		printf("%d\t", aList[i]);
	}
	putchar('\n');

	printf("MAX : %d\n", aList[0]);
	return 0;

}