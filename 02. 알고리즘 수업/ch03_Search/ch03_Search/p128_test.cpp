// 128p
// Q9. bsearch �Լ��� ���� �������� ȣ���� �� �ִ� ���� �Լ��� �ۼ��ϼ���.
// �̶� Q5(115��)ó�� ���� �˻� �˰����� ����Ͽ� ��ġ�ϴ� ����� �˻��� �����ϸ� �� ��ġ���� ��������
// ���� �˻��� �����Ͽ� ���� ������ ��ҿ� ���� �����͸� ��ȯ�ϼ���.
// void *bsearch(const void *key, const void *base, size_t nmemb, size_t size, int(*compar)(const void *, const void *));


// 115p
// Q5. �츮�� ���캻 ���� �˻� �˰��� ���α׷��� �˻��� ���� ���� ���� ���� ��Ұ� �ϳ� �̻��� ���
// �� ��� �߿��� �� ���� ��Ҹ� ã�� ���մϴ�.
// ���� ���, �Ʒ� �׸��� �迭���� 7�� �˻��ϸ� �߾ӿ� ��ġ�ϴ� a[5]�� �˻��մϴ�.
// �� ���� ��Ҹ� ã�� bin_search2 �Լ��� �ۼ��� ������
// int bin_serach2(const int a[], int n, int key);

// ex) 
// a = 1/0 3/1 5/2 7/3 7/4 7/5�� 7/6 8/7 9/9 9/10
// b = 1/0 3/1 5/2 7/3�� 7/4 7/5 7/6 8/7 9/9 9/10
// �迭�� �� ���� ���� �ʴ� �������� ���� ���� ��Ұ� ��ӵǴ� �� �������� ��ĵ�մϴ�.

#include<stdio.h>
#include<stdlib.h>

void *bsearch(const void *key, const void *base, size_t nmemb, size_t size, int(*compar)(const void *, const void *));
int compareNum(const int *x, const int *y);
void *SearchFront(int resultNum, int *numArr);

int main()
{
	int *numArr;
	int sizeArr;
	printf("�迭 ũ�� �Է� : ");
	scanf_s("%d", &sizeArr);
	numArr = (int *)calloc(sizeArr, sizeof(int));

	int maxArrSize = _msize(numArr)/sizeof(int);
	for (int i = 0; i < maxArrSize; i++)
	{
		printf("���� �Է�(%d ����) : ", maxArrSize - i);
		scanf_s("%d", &numArr[i]);
	}

	int searchNum = 0;
	printf("�˻��� �� �Է� : ");
	scanf_s("%d", &searchNum);

	int *resultNum = 0;
	resultNum = (int *)bsearch(&searchNum, numArr, maxArrSize, sizeof(int), (int(*)(const void *, const void *))compareNum);
	// �˻���, �迭, ��� ����, �迭 ũ��, �� �Լ�
	
	if (resultNum == NULL)
		puts("\n�˻��� �����߽��ϴ�.\n");
	else
	{
		resultNum = (int *) SearchFront(*resultNum, numArr);
		printf("\n%d��/�� x[%d]�� �ֽ��ϴ�.\n", searchNum, (int)*resultNum);
	}

	free(numArr);

	return 0;
}

void *bsearch(const void *key, const void *base, size_t nmemb, size_t size, int(*compar)(const void *, const void *))
{
	// �˻���, �迭, ��� ����, �迭 ũ��, �� �Լ�
	int startIndex = 0;
	int endIndex = size;
	int midIndex;	// �߾Ӱ�
	int rangeNum = 0;

	int *check = (int *)base;
	int *_key = (int *)key;
	bool isCheck = true;
	while (1)
	{
		midIndex = (startIndex + endIndex) / 2;

		if (abs(midIndex - endIndex) == 1 || abs(midIndex - endIndex) == 1)
		{
			if (check[midIndex] == *_key)
			{
				isCheck = false;
				return (int *)&midIndex;
			}
			if (check[midIndex - 1] == *_key)
			{
				isCheck = false;
				midIndex--;
				return (int *)&midIndex;
			}
			if (check[midIndex + 1] == *_key)
			{
				isCheck = false;
				midIndex++;
				return (int *)&midIndex;
			}

			if (isCheck)
				printf("\n\nã�°��� �������� ����\n");
			break;
		}

		rangeNum = (*compar)((int *)&check[midIndex], _key);
		if (rangeNum  == 1)
		{
			endIndex = midIndex;
		}
		else if(rangeNum == -1)
		{
			startIndex = midIndex;
		}
		else
		{
			printf("%d\n", *_key);	// ���� ���
			return (int *) &midIndex;
		}
	}
	return 0;
}

int compareNum(const int *x, const int *y)
{
	if (*x < *y)
		return -1;
	else if (*x > *y)
		return 1;
	else
		return 0;
}

void *SearchFront(int resultNum, int *numArr)
{
	int temp = resultNum;
	for (int i = temp; i >= 0; i--)
	{
		if (numArr[temp] == numArr[i])
			resultNum = i;
	}

	return (int *) &resultNum;
}