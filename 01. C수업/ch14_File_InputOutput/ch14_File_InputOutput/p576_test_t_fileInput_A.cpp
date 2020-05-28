#include<stdio.h>

int main()
{
	FILE *nowFp = NULL;
	FILE *lastFp = NULL;
	
	fopen_s(&nowFp, "nowFile.txt", "ab");

	int inputNum;
	char inputName[32] = { 0 };
	printf("학생의 번호 입력 : ");
	scanf_s("%d", &inputNum);
	printf("학생의 이름 입력 : ");
	scanf_s("%s", inputName, sizeof(inputName));

	fprintf(nowFp, "%d %s\n", inputNum, inputName);
	fclose(nowFp);

	/* 
	todo 
	*/

	// 파일 복사 부분
	fopen_s(&nowFp, "nowFile.txt", "rb");
	fopen_s(&lastFp, "lastFile.txt", "wb");
	if (nowFp == NULL) return 0;

	char temp[128] = { 0 };
	int cnt = 0;
	fseek(nowFp, 0, SEEK_SET);
	while (!feof(nowFp))
	{
		//cnt = fread(temp, sizeof(temp), 1, nowFp);
		//fwrite(temp, sizeof(temp), cnt, lastFp);
		fscanf_s(nowFp, "%s", temp, sizeof(temp));
		if (!feof(nowFp))fprintf(lastFp, "%s\n", temp);
	}

	_fcloseall();
	return 0;
}