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
		printf("[����ȭ��]\n");
		printf("1. ������ �߰�  2. �˻�&���  3. ����  4. ����  5. ����\n�Է� : ");
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
			printf("���� ����\n");
			break;
		case 5:
			puts("���α׷� ����");
			return 0;
			break;

		default:
			printf("���⿡ ���� ����, ���Է� �ʿ�\n");
			break;
		}
		puts("");
	}

	CheckFree(headStu);
	CheckFree(tailStu);

	return 0;
}
