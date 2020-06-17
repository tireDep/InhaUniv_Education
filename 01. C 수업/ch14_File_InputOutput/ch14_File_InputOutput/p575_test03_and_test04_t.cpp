// Q3. ���� ��ο��� 'TestFile.txt' ������ �� ��, ���� ���Ͽ��� �� ������ ���ڿ��� �о�鿩 ��� ���Ͽ� �����ϴ� ���α׷� �ۼ�
// ��, ��� ���ϵ� ���� ��ο� �����ϸ�, ���ϸ��� 'DstFile.txt'

// Q4. main() �Լ��� ���ڷ� �� ���̳ʸ� ������ ��θ� �Է¹޾� ���̳ʸ� ���� ����, 
// ���� ������ ������ �о�鿩 ��� ���Ϸ� �����ϴ� ���α׷� �ۼ�
// ��, ������ ���� ������ ������� ȭ�鿡 ����ϰ�, �ѹ��� 4KB ������ ������, 
// �׸��� ��� ������ ���� ������ ������� ������ �����ϸ�, ������ ũ�Ⱑ �ִ� 100mb �̻��� ���� ������� x

// ����
// - png �� �̹��� ���Ϸ� ������ �� 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>

int main()
{
	FILE *scrFp = NULL;
	FILE *dstFp = NULL;
	char scrName[128];
	char dstName[128];

	printf("���� ���� �̸� �Է�(Ȯ���� ����) : ");
	scanf_s("%s", scrName, sizeof(scrName));

	fopen_s(&scrFp, scrName, "rb");
	if (scrFp == NULL)
	{
		puts("Error!");
		return 0;
	}

	fseek(scrFp, 0, SEEK_END);
	int size = ftell(scrFp);
	rewind(scrFp);

	printf("������ ���� �̸� �Է�(Ȯ���� ����) : ");
	scanf_s("%s", dstName, sizeof(dstName));

	fopen_s(&dstFp, dstName, "wb");
	
	/*
	fseek(scrFp, 0, SEEK_END);
	int size = ftell(scrFp);
	printf("%d %d\n", size, size);
	// ������ ũ�� ���ϱ�
	*/

	char tempArr[4096] = { 0 };	// 4kb + null(1byte)
	int cnt = 0;
	int percent = 1;
	int isSize = 4096;
	while (1)
	{
		if (size - isSize != size % 4096)
		{
			cnt = fread(tempArr, sizeof(tempArr), 1, scrFp);
			fwrite(tempArr, sizeof(tempArr), cnt, dstFp);	// cnt�� �ؾ��� 4kb �̸��� �޾ƿ� �� ����
			memset(tempArr, 0, sizeof(tempArr));
			isSize = ftell(dstFp);
		}
		else
		{
			cnt = fread(tempArr, size-isSize, 1, scrFp);
			fwrite(tempArr, size - isSize, cnt, dstFp);	// cnt�� �ؾ��� 4kb �̸��� �޾ƿ� �� ����
			memset(tempArr, 0, sizeof(tempArr));
			isSize += (size - isSize);
		}
		// 4kb�� �ȵǴ� ���� �ޱ� ���� else ��
		
		if (isSize >= size / 10 * percent)
		{
			Sleep(250);
			system("cls");
			printf("����� : %d\n", 10*percent++);
		}

		if(isSize>=size) break;
	}

	fclose(scrFp);
	fclose(dstFp);

	return 0;
}

/*
https://dojang.io/mod/page/view.php?id=623
*/