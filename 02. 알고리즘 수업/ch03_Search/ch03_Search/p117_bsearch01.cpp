// 117p

/*
bsearch()
[Ư¡]
- �˻� ����� �迭�� �׻� ���ĵǾ� �־����
- �˻��ϴ� ���� ���� ��Ұ� ���� �� �����ϴ� ���, �׻� ���ʿ� �ִ� ��Ҹ� ã�Ƴ����� ����

[�Ű�����]
- contst void *key : �˻��� ���� ����� ��ü�� ���� ������(Ű ��)
- const void *base : �迭�� ������
- size_t nmemb : �迭�� ��� ����
- size_t size : �迭�� ��� ũ��
- int(*compar)(const void*, const void*) : ���Լ�(�Լ� ������)

ex) p = bsearch(&ky, x, nx, sizeof(int), (int(*)(const void *, const void *)) int_cmp);

[���Լ�]
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

- ù ��° �μ��� ����Ű�� ���� �� ������ ���� ��ȯ
- ù ��° �μ��� ����Ű�� ���� �� ��° �μ��� ����Ű�� ���� ������ 0 ��ȯ
- ù ��° �μ��� ����Ű�� ���� �� ũ�� ��� ��ȯ
*/

#include <stdio.h>
#include<stdlib.h>

int int_cmp(const int *a, const int *b);

int main()
{
	int i, nx, ky;
	int *x;
	int *p;

	printf("bsearch �Լ��� ����Ͽ� �˻�\n��� ���� : ");
	scanf_s("%d", &nx);
	x = (int *) calloc(nx, sizeof(int));

	printf("\n������������ �Է��ϼ���.\n");
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

	printf("\n�˻��� : ");
	scanf_s("%d", &ky);

	p = (int *) bsearch(&ky, x, nx, sizeof(int), (int(*)(const void *, const void *))int_cmp);
	// �˻���, �迭, ��� ����, �迭 ũ��, �� �Լ�

	if (p == NULL)
		puts("\n�˻��� �����߽��ϴ�.\n");
	else
		printf("\n%d��/�� x[%d]�� �ֽ��ϴ�.\n", ky, (int)(p - x));

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