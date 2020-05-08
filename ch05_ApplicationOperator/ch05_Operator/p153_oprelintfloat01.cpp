// 153p
#include<stdio.h>

int main()
{
	printf("%d\n", 300 == 299.99999f);
	printf("%d\n", 300 == 299.99999);

	printf("%d\n", 300 == 299.9999f);
	printf("%d\n", 300 == 300.00001f);

	return 0;
}