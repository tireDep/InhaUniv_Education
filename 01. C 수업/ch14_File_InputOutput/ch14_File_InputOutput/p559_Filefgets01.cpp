// 559p
#include<stdio.h>
#include<string.h>

void main()
{
	FILE *fp = NULL;
	char szBuffer[512] = { 0 };

	// 파일을 생성해 여러 행의 문자열을 쓴 후 닫음
	fopen_s(&fp, "Text.txt", "w");
	fputs("Test\n", fp);
	fputs("String\n", fp);
	fputs("Data\n", fp);
	fclose(fp);

	// 앞서 생성한 파일을 다시 개방함
	fopen_s(&fp, "Text.txt", "r");
	if (fp == NULL)
		return;

	// 파일에서 한 행 씩 끊어내서 읽어옴
	while (fgets(szBuffer, sizeof(szBuffer), fp))
	{
		/*
		-----------------------------------------------------------------
		fgets()는 개행까지 읽어옴
		fgets()는 함수가 문자열을 읽는데 성공하면 NULL이 아닌 값을 반환함
		-----------------------------------------------------------------
		*/

		printf("%s", szBuffer);
		memset(szBuffer, 0, sizeof(szBuffer));
	}

	fclose(fp);

	return;
}

/*
--------------------------------------------------------
게임 등 프로그램을 만들고 배포할 때,
데이터 텍스트로 이루어져 있으면 쉽게 수정 가능함

최소한 바이너리화 or 암호화를 적용하여 데이터를 보호해야함
--------------------------------------------------------
*/