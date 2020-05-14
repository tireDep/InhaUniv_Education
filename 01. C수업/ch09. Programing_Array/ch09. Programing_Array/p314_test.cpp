// 314p
// Q. 달팽이 배열 채우기
#include<stdio.h>

int main()
{
	int nArray[5][5] = { 0 };
	int num = 1;

	int maxSize = sizeof(nArray) / sizeof(nArray[0]);
	
	int i=0, j=-1;
	int checkPos = 1;

	while (1)
	{
		// 가로 이동
		for (int pos = 0; pos < maxSize; pos++)
		{
			j = j + checkPos;
			nArray[i][j] = num++;
		}

		// 최대 이동 감소
		maxSize--;
		if (maxSize < 0)
		{
			break;
		}

		// 세로 이동
		for (int pos = 0; pos < maxSize; pos++)
		{
			i = i + checkPos;
			nArray[i][j] = num++;
		}

		// 이동방향 변경
		checkPos = -checkPos;
	}

	// 2차원 배열 출력
	for (int p = 0; p < 5; p++) {
		for (int q = 0; q < 5; q++) {
			printf("%d\t", nArray[p][q]);
		}
		printf("\n");
	}
}

/*
int tempIndex;
bool check = true;
// true : 아래 대각선
// false : 위 대각선
for (int i = 0; i < maxRow; i++)
{
tempIndex = i;
if (check)
{
for (int j = 0; j <= i; j++)
{
nArray[tempIndex--][j] = cnt++;
}
check = false;
}
else
{
for (int j = i; j >= 0; j--)
{
nArray[tempIndex++][j] = cnt++;
}
check = true;
}
}


*/