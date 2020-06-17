#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *pI = NULL;
	int *pOlD = NULL;
	pI = (int*)malloc(sizeof(int));
	pOlD = pI;

	pI = (int*)realloc(pI, sizeof(int) * 14);

	if (pI == NULL)
	{
		free(pOlD);
		exit(1);
	}
	// realloc 에러 방지용

	// -----------------------------------------------------------------

	int nData = 10;
	int *pnData = &nData;
	int **ppnData = &pnData;

	printf("%d %d %d\n", nData, *pnData, **ppnData);

}