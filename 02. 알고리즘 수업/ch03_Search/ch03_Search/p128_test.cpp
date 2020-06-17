// 128p
// Q9. bsearch 함수와 같은 형식으로 호출할 수 있는 다음 함수를 작성하세요.
// 이때 Q5(115쪽)처럼 이진 검색 알고리즘을 사용하여 일치하는 요소의 검색에 성공하면 그 위치에서 앞쪽으로
// 선형 검색을 수행하여 가장 앞쪽의 요소에 대한 포인터를 반환하세요.
// void *bsearch(const void *key, const void *base, size_t nmemb, size_t size, int(*compar)(const void *, const void *));


// 115p
// Q5. 우리가 살펴본 이진 검색 알고리즘 프로그램은 검색할 값과 같은 값을 갖는 요소가 하나 이상일 경우
// 그 요소 중에서 맨 앞의 요소를 찾지 못합니다.
// 예를 들어, 아래 그림의 배열에서 7을 검색하면 중앙에 위치하는 a[5]를 검색합니다.
// 맨 앞의 요소를 찾는 bin_search2 함수를 작성해 보세요
// int bin_serach2(const int a[], int n, int key);

// ex) 
// a = 1/0 3/1 5/2 7/3 7/4 7/5∨ 7/6 8/7 9/9 9/10
// b = 1/0 3/1 5/2 7/3∨ 7/4 7/5 7/6 8/7 9/9 9/10
// 배열의 맨 앞을 넘지 않는 범위에서 같은 값의 요소가 계속되는 한 앞쪽으로 스캔합니다.

#include<stdio.h>
#include<stdlib.h>

void *bsearch(const void *key, const void *base, size_t nmemb, size_t size, int(*compar)(const void *, const void *));
int compareNum(const int *x, const int *y);
void *SearchFront(int resultNum, int *numArr);

int main()
{
	int *numArr;
	int sizeArr;
	printf("배열 크기 입력 : ");
	scanf_s("%d", &sizeArr);
	numArr = (int *)calloc(sizeArr, sizeof(int));

	int maxArrSize = _msize(numArr)/sizeof(int);
	for (int i = 0; i < maxArrSize; i++)
	{
		printf("숫자 입력(%d 남음) : ", maxArrSize - i);
		scanf_s("%d", &numArr[i]);
	}

	int searchNum = 0;
	printf("검색할 값 입력 : ");
	scanf_s("%d", &searchNum);

	int *resultNum = 0;
	resultNum = (int *)bsearch(&searchNum, numArr, maxArrSize, sizeof(int), (int(*)(const void *, const void *))compareNum);
	// 검색값, 배열, 요소 개수, 배열 크기, 비교 함수
	
	if (resultNum == NULL)
		puts("\n검색에 실패했습니다.\n");
	else
	{
		resultNum = (int *) SearchFront(*resultNum, numArr);
		printf("\n%d은/는 x[%d]에 있습니다.\n", searchNum, (int)*resultNum);
	}

	free(numArr);

	return 0;
}

void *bsearch(const void *key, const void *base, size_t nmemb, size_t size, int(*compar)(const void *, const void *))
{
	// 검색값, 배열, 요소 개수, 배열 크기, 비교 함수
	int startIndex = 0;
	int endIndex = size;
	int midIndex;	// 중앙값
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
				printf("\n\n찾는값이 존재하지 않음\n");
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
			printf("%d\n", *_key);	// 같을 경우
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