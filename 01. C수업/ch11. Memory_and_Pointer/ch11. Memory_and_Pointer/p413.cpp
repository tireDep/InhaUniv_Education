#include<stdio.h>

int main()
{
	int *pA[3] = { NULL,NULL ,NULL };

	int a = 1, b = 2, c = 3;
	int *pa = NULL;
	int *pb = NULL;
	int *pc = NULL;

	pA[0] = &a;
	pA[1] = &b;
	pA[2] = &c;

	pa = &a;
	pb = &b;
	pc = &c;

	printf("历厘蔼 : %d %d %d \n", a, b, c);
	printf("历厘蔼 : %d %d %d \n", *pa, *pb, *pc);

	printf("林家 : %x %x %x \n", &a, &b, &c);
	printf("林家 : %x %x %x \n", pa, pb, pc);
	printf("林家 : %x %x %x \n", &pa, &pb, &pc);
	puts("");

	// -----------------------------------------------------------------

	printf("历厘蔼 : %d %d %d\n", a, b, c);
	printf("历厘蔼 : %d %d %d\n", *pA[0], *pA[1], *pA[2]);
	puts("");

	// -----------------------------------------------------------------
}