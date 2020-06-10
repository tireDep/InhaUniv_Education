// Q3. 현재 경로에서 'TestFile.txt' 파일을 연 후, 원본 파일에서 행 단위로 문자열을 읽어들여 대상 파일에 복사하는 프로그램 작성
// 단, 대상 파일도 현재 경로에 생성하며, 파일명은 'DstFile.txt'

// Q4. main() 함수의 인자로 두 바이너리 파일의 경로를 입력받아 바이너리 모드로 열고, 
// 원본 파일의 내용을 읽어들여 대상 파일로 복사하는 프로그램 작성
// 단, 복사의 진행 과정을 백분율로 화면에 출력하고, 한번에 4KB 단위로 복사함, 
// 그리고 대상 파일이 존재 유무에 상관없이 무조건 생성하며, 파일의 크기가 최대 100mb 이상인 경우는 고려하지 x

// 조건
// - png 등 이미지 파일로 진행할 것 

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

	printf("원본 파일 이름 입력(확장자 포함) : ");
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

	printf("복사할 파일 이름 입력(확장자 포함) : ");
	scanf_s("%s", dstName, sizeof(dstName));

	fopen_s(&dstFp, dstName, "wb");
	
	/*
	fseek(scrFp, 0, SEEK_END);
	int size = ftell(scrFp);
	printf("%d %d\n", size, size);
	// 파일의 크기 구하기
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
			fwrite(tempArr, sizeof(tempArr), cnt, dstFp);	// cnt로 해야지 4kb 미만도 받아올 수 있음
			memset(tempArr, 0, sizeof(tempArr));
			isSize = ftell(dstFp);
		}
		else
		{
			cnt = fread(tempArr, size-isSize, 1, scrFp);
			fwrite(tempArr, size - isSize, cnt, dstFp);	// cnt로 해야지 4kb 미만도 받아올 수 있음
			memset(tempArr, 0, sizeof(tempArr));
			isSize += (size - isSize);
		}
		// 4kb가 안되는 값을 받기 위한 else 문
		
		if (isSize >= size / 10 * percent)
		{
			Sleep(250);
			system("cls");
			printf("진행률 : %d\n", 10*percent++);
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