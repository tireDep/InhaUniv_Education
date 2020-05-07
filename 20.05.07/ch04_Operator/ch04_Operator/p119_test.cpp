// 119p
// Q : 초를 '시:분:초'로 변환하는 프로그램
// 정수입력, 두자리 정수로 표시(한자리면 0x)
#include<stdio.h>

int main()
{
	int inputSec = 0;
	printf("초를 입력하세요 : ");
	scanf_s("%d", &inputSec);

	int hour = inputSec / 3600;
	int min = inputSec % 3600 / 60; // hour 제외한 값
	int sec = inputSec % 3600 % 60; // min 제외한 값

	printf("%d초는 %02d시간 %02d분 %02d초 입니다.\n", inputSec, hour, min, sec);
	
	return 0;
}
// 산수!!!!!

// ---------- 주의 ----------
// int n = 0, m = 50, k = 10;
// printf("%d %d %d", n = 10, m = n / k, k = 10 / n);
//
// 이런식도 가능은 한데 순서 고려 잘해야함!
// 이 코드의 경우 10/0이 먼저 시작되어서 에러발생
// --------------------------