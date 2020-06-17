// 552p
#include<stdio.h>

void main()
{
	FILE *fp = NULL;
	int nClose = 0;

	fopen_s(&fp, "temp01", "w");
	fopen_s(&fp, "temp02", "w");
	fopen_s(&fp, "temp03", "w");

	nClose = _fcloseall();
	printf("%d\n", nClose);

	return;
}