// 117p

/*
bsearch()
[특징]
- 검색 대상의 배열은 항상 정렬되어 있어야함
- 검색하는 값과 같은 요소가 여러 개 존재하는 경우, 항상 앞쪽에 있는 요소를 찾아내지는 않음

[매개변수]
- contst void *key : 검색할 값이 저장된 객체에 대한 포인터(키 값)
- const void *base : 배열의 포인터
- size_t nmemb : 배열의 요소 개수
- size_t size : 배열의 요소 크기
- int(*compar)(const void*, const void*) : 비교함수(함수 포인터)

ex) p = bsearch(&ky, x, nx, sizeof(int), (int(*)(const void *, const void *)) int_cmp);

[비교함수]
ex) 
int int_cmp(const int *a, const int *b)
{
	if(*a < *b)
		return -1;
	else if(*a > *b)
		return 1;
	else
		reuturn 0;
}

- 첫 번째 인수가 가리키는 값이 더 작으면 음수 반환
- 첫 번째 인수가 가리키는 값과 두 번째 인수가 가리키는 값이 같으면 0 반환
- 첫 번째 인수가 가리키는 값이 더 크면 양수 반환
*/

#include <stdio.h>
#include<stdlib.h>

int int_cmp(const int *a, const int *b);

int main()
{
	int i, nx, ky;
	int *x;
	int *p;

	printf("bsearch 함수를 사용하여 검색\n요소 개수 : ");
	scanf_s("%d", &nx);
	x = (int *) calloc(nx, sizeof(int));

	printf("\n오름차순으로 입력하세요.\n");
	printf("X[0] : ");
	scanf_s("%d", &x[0]);
	
	for (i = 1; i < nx; i++)
	{
		do
		{
			printf("x[%d] : ", i);
			scanf_s("%d", &x[i]);
		} while (x[i] < x[i - 1]);
	}

	printf("\n검색값 : ");
	scanf_s("%d", &ky);

	p = (int *) bsearch(&ky, x, nx, sizeof(int), (int(*)(const void *, const void *))int_cmp);
	// 검색값, 배열, 요소 개수, 배열 크기, 비교 함수

	if (p == NULL)
		puts("\n검색에 실패했습니다.\n");
	else
		printf("\n%d은/는 x[%d]에 있습니다.\n", ky, (int)(p - x));

	free(x);

	return 0;
}

int int_cmp(const int *a, const int *b)
{
	printf(">>> %d / %d\n", *a, *b);
	if (*a < *b)
		return -1;
	else if (*a > *b)
		return 1;
	else
		return 0;
}