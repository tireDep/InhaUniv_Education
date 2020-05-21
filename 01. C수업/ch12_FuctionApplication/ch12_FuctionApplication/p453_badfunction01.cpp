// 453p
// 잘못된 코드의 예시

#include<stdio.h>

int *TestFunc(void);

int main()
{
	int *pnResult = NULL;

	pnResult = TestFunc();

	printf("%d\n", *pnResult);	
	// 포인터가 가리키는 대상 메모리는 유효하지 않은 메모리
	// but, 돌아가기는 하기 때문에 주의해야 함!

	return 0;

}

int *TestFunc(void)
{
	int nData = 10;

	return &nData;
}