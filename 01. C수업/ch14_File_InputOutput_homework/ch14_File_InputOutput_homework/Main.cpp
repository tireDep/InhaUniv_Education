#include "BasicHeader.h"
#include "FuncHeader.h"

int main()
{
	Student_s *headStu = NULL;
	Student_s *tailStu = headStu;
	int inputNum;
	int nodeCnt = 0;

	while (1)
	{
		rewind(stdin);
		printf("[메인화면]\n");
		printf("1. 데이터 추가  2. 검색&출력  3. 변경  4. 복구  5. 종료\n입력 : ");
		scanf_s("%d", &inputNum);

		CheckFile(&headStu, &tailStu, &nodeCnt);
		switch (inputNum)
		{
		case 1:
			AddStudent(&headStu, &tailStu, nodeCnt);
			break;
		case 2:
			SearchAndPrint(&headStu);
			break;
		case 3:
			ChangeData(&headStu, &tailStu, nodeCnt);
			break;
		case 4:
			CopyFile("nowFile.dat", "lastFile.dat");
			printf("파일 복구\n");
			break;
		case 5:
			puts("프로그램 종료");
			return 0;
			break;

		default:
			printf("보기에 없는 숫자, 재입력 필요\n");
			break;
		}
		puts("");
	}

	CheckFree(headStu);
	CheckFree(tailStu);

	return 0;
}
