// 374p
// 포인터 변수의 선언 및 정의
#include<stdio.h>

int main()
{
	char c = 'A';
	char *cp = NULL;

	cp = &c;

	printf("c주소 : %x\nc저장 내용 : %c\nc주소의 값 : %c\n\n", &c, c, *&c);
	printf("cp주소 : %x\ncp저장 내용 : %x\ncp주소의 값 : %x\n", &cp, cp, *&cp);
	printf("\ncp가 가리키는 값 : %c\n", *cp);
	puts("");

	// ---------------------------------------------------------------------------------

	int a = 0, b = 0, cc = 0;
	int *ip = NULL;
	ip = &a;

	*ip = 10;

	printf("ip = a\n%d\t%d\t%d\t%d\t\n", a, b, cc, *ip);

	ip = &b;
	*ip = 20;
	printf("\nip = b\n%d\t%d\t%d\t%d\t\n", a, b, cc, *ip);

	ip = &cc;
	*ip = 30;
	printf("\nip = cc\n%d\t%d\t%d\t%d\t\n", a, b, cc, *ip);
	puts("");

	// ---------------------------------------------------------------------------------

	int num = 10;
	int *ip2 = &num;

	printf("%x %x %x %x %d\n", &num, &ip2, &*&ip2, *&ip2, **&ip2);
	// num 주소
	// ip2 주소
	// ip2 주소의 내용의 주소 == ip2주소	=> 2개 상쇄되서 최종적으로 &ip2
	// ip2 주소의 내용 == num 주소		=> 2개 상쇄되서 최종적으로 ip2
	// ip2 주소의 내용의 내용 == num값	=> 2개 상쇄되서 최종적으로 *ip2

	printf("%d %x %x %d\n", num, &ip2, ip2, *ip2);
	puts("");

	// ---------------------------------------------------------------------------------

	int num2 = 0;
	num2 = *ip2 + num;
	printf("*ip2 + num : %d\n", num2);

	*ip2 = 10000;
	printf("%d \n",*ip2);

	return 0;

}