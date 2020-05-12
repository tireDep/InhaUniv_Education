// Q. 입력받은 정수의 평균을 출력하는 프로그램을 작성
// 조건 
// 1) 몇 개의 정수를 입력할 것인지 물어보고, 그 수만큼 입력받기
// 2) 평균 값은 소수점 이하 2자리까지 출력
#include<stdio.h>

int main()
{
	int input = 0;
	float result = 0;

	printf("입력 할 개수 입력 : ");
	scanf_s("%d", &input);

	int cnt = 0;
	int addNum = 0;
	while (cnt < input)
	{
		printf("\n입력 : ");
		scanf_s("%d", &addNum);
		result += addNum;
		cnt++;
	}

	result = result / input;
	printf("\n평균 값 : %.2f\n",result);
	
	return 0;
}