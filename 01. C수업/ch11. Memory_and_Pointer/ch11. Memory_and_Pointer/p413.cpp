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

	printf("���尪 : %d %d %d \n", a, b, c);
	printf("���尪 : %d %d %d \n", *pa, *pb, *pc);

	printf("�ּ� : %x %x %x \n", &a, &b, &c);
	printf("�ּ� : %x %x %x \n", pa, pb, pc);
	printf("�ּ� : %x %x %x \n", &pa, &pb, &pc);
	puts("");

	// -----------------------------------------------------------------

	printf("���尪 : %d %d %d\n", a, b, c);
	printf("���尪 : %d %d %d\n", *pA[0], *pA[1], *pA[2]);
	puts("");

	// -----------------------------------------------------------------
}