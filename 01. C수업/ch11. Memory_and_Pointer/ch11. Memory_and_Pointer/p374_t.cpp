// 374p
// ������ ������ ���� �� ����
#include<stdio.h>

int main()
{
	char c = 'A';
	char *cp = NULL;

	cp = &c;

	printf("c�ּ� : %x\nc���� ���� : %c\nc�ּ��� �� : %c\n\n", &c, c, *&c);
	printf("cp�ּ� : %x\ncp���� ���� : %x\ncp�ּ��� �� : %x\n", &cp, cp, *&cp);
	printf("\ncp�� ����Ű�� �� : %c\n", *cp);
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
	// num �ּ�
	// ip2 �ּ�
	// ip2 �ּ��� ������ �ּ� == ip2�ּ�	=> 2�� ���Ǽ� ���������� &ip2
	// ip2 �ּ��� ���� == num �ּ�		=> 2�� ���Ǽ� ���������� ip2
	// ip2 �ּ��� ������ ���� == num��	=> 2�� ���Ǽ� ���������� *ip2

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