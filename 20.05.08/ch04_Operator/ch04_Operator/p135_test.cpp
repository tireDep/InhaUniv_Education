// Q. scanf() 이용 입력받고 출력하기
// no.1 xx \n no.2 xx \n no.3 형식(no는 증감 연산자 사용)
#include<stdio.h>

int main()
{
	int no = 0;
	int inputNum1 = 0;
	int inputNum2 = 0;
	int inputNum3 = 0;

	printf("숫자입력 : ");
	scanf_s("%d %d %d", &inputNum1, &inputNum2, &inputNum3);
	
	printf("no.%d \t %d\n", ++no, inputNum1);
	printf("no.%d \t %d\n", ++no, inputNum2);
	printf("no.%d \t %d\n", ++no, inputNum3);

	return 0;
}