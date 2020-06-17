// Q. 
// - 프로그램 상에서 파일 99.txt를 만들어서 이 파일에 구구단을 저장하는 프로그램 작성, fprintf() 이용
// - fseek() 함수를 이용해서 원하는 단의 내용만 찾아서 출력하는 프로그램 작성

#include<stdio.h>

int main()
{
	FILE *fp = NULL;
	fopen_s(&fp, "99.txt", "w");

	for (int i = 0; i <= 9; i++)
	{
		if (i <= 1) continue;
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0) continue;
			fprintf(fp, "%2d x %2d = %2d\n", i, j, i*j);
		}
		fprintf(fp,"            \n"); // 공백12 + \n + eof = 14	
		/*
		-------------------------------
		[주의]
		- 형식이 같지 않으면 에러남!
		-------------------------------
		*/
	}
	fclose(fp);

	fopen_s(&fp, "99.txt", "r");
	char printArr[128] = { 0 };
	int inputNum;
	printf("원하는 단 입력 : ");
	scanf_s("%d", &inputNum);

	if (inputNum <= 1)
		inputNum = 2;
	else if (inputNum >= 10)
		inputNum = 9;
	// 간단한 보정

	fseek(fp, 14 * 10 * (inputNum - 2), SEEK_SET);	
	/*
	-------------------------------------------------------------
	[주의]
	- 14 : NULL값 까지 포함한 값(12 + \n + eof)
	- 10 : 해당 단의 갯수(1~9 + \n)
	- -2 : 단이 0이 위치부터 2단이 시작되기 때문에, -2를 해줘야 함
	-------------------------------------------------------------
	*/
	for (int i = 0; i < 9; i++)
	{
		fprintf(stdout, "%s", fgets(printArr, sizeof(printArr), fp));
	}

	fclose(fp);

	return 0;
}