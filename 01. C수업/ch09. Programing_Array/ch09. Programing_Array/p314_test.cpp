// 314p
// Q. ������ �迭 ä���
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
		// ���� �̵�
		for (int pos = 0; pos < maxSize; pos++)
		{
			j = j + checkPos;
			nArray[i][j] = num++;
		}

		// �ִ� �̵� ����
		maxSize--;
		if (maxSize < 0)
		{
			break;
		}

		// ���� �̵�
		for (int pos = 0; pos < maxSize; pos++)
		{
			i = i + checkPos;
			nArray[i][j] = num++;
		}

		// �̵����� ����
		checkPos = -checkPos;
	}

	// 2���� �迭 ���
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
// true : �Ʒ� �밢��
// false : �� �밢��
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