// 377p
// 포인터와 배열
#include<stdio.h>

int main()
{
	puts("[배열을 이용한 방식]");
	
	int numArr[3] = { 10,20,30 };

	printf("%x %x %x\n", numArr, numArr + 0, &numArr[0]);	// numArr의 첫번째 주소 표현 방법, 3개 모두 numArr[0]의 주소를 가리킴
	printf("%x %x\n", numArr + 1, &numArr[1]);	// numArr[1]의 주소
	printf("%x %x\n", numArr + 2, &numArr[2]);	// numArr[2]의 주소
	puts("");

	printf("%d %d %d\n", *numArr, *(numArr + 0), *&(numArr[0]));
	printf("%d %d\n", *(numArr + 1), *&(numArr[1]));
	printf("%d %d\n", *(numArr + 2), *&(numArr[2]));
	puts("");

	for (int i = 0; i < 3; i++)
	{
		printf("%d %d %d\n", *(numArr + i), *&numArr[i], numArr[i]);
	}
	puts("");

	printf("주소의 크기 : %d %d %d\n", sizeof(numArr), sizeof(numArr + 0), sizeof(&numArr[0]));
	// 첫번째 요소 : 전체의 크기
	// 두번째 & 세번째 요소 : 첫번째 요소의 크기

	printf("배열의 개수 : %d\n", sizeof(numArr) / sizeof(int));
	puts("");

	// ------------------------------------------------------------------------------
	
	puts("[포인터를 이용한 방식]");

	int *p = NULL;
	p = numArr;

	printf("%x %x %x\n", p, p + 0, &p[0]);
	printf("%x %x\n", p + 1, &p[1]);
	printf("%x %x\n", p + 2, &p[2]);
	puts("");

	printf("%d %d %d\n", *p, *(p + 0), *&p[0]);
	printf("%d %d\n", *(p + 1), *&p[1]);
	printf("%d %d\n", *(p + 2), *&p[2]);
	puts("");

	for (int i = 0; i < 3; i++)
	{
		printf("%d %d %d\n", *(p + i), *&p[i], p[i]);
	}
	puts("");

	/*
	---------------------------------------------------
	*&가 연달아 있을 경우, 상쇄되는 것에 주의!
	---------------------------------------------------
	*/

	printf("배열의 크기 : %d\n포인터의 크기 : %d\n", sizeof(numArr), sizeof(p));
	puts("");

	// ------------------------------------------------------------------------------

	*p = 40;
	p = numArr + 1; // == &numArr[1];
	*p = 50;
	printf("%d %d %d\n", *p, *(p + 1), *(p + 2));
	puts("");

	p = numArr + 2; // == &numArr[2];
	*p = 60;
	printf("%d %d %d\n", *(p - 2), *(p - 1), *p);
	puts("");

	return 0;

}