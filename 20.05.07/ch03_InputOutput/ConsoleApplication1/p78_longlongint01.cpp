// 78p

#include<stdio.h>

int main()
{
	long long int lldData = 4294967295LL;
	// ��ȣ�� �ִ� 64bit ������ ���� ���� �� ����

	printf("%d\n", lldData);
	printf("%u\n", lldData);
	// 64bit ���� 32bit ���� ���ڷ� ���

	printf("%u\n", lldData + 1);
	printf("%u\n", lldData + 2);
	printf("%u\n", lldData + 3);
	// 32bit�� ��� => ����� �� ��� x

	printf("%lld\n", lldData + 1);
	printf("%lld\n", lldData + 2);
	printf("%lld\n", lldData + 3);
	// 64bit�� ��� => ����� �� ��� o

	return 0;
}