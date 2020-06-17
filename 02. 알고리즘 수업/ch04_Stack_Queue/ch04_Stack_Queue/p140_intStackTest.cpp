// 140p

#include<stdio.h>
#include"p132_intStack.h"

int main()
{
	INTSTACK_S s;
	if (Initialize(&s, 64) == -1)
	{
		puts("스택 생성에 실패하였습니다.\n");
		return 1;
	}

	int menu, x;
	while (1)
	{
		printf("현재 데이터 수 : %d / %d\n", Size(&s), Capacity(&s));
		printf("(1) 푸시 (2) 팝 (3) 피크 (4) 출력 (0) 종료 \n\n입력 : ");
		scanf_s("%d", &menu);

		if (menu == 0) break;
		
		switch (menu)
		{
		case 1:
			printf("데이터 : ");
			scanf_s("%d", &x);
			if (Push(&s, x) == -1) puts("오류 : 푸시에 실패하였습니다n\n");
			break;
		case 2:
			if (Pop(&s, &x) == -1) puts("오류 : 팝에 실패하였습니다.\n");
			else
				printf("팝 데이터는 %d 입니다.\n", x);
			break;
		case 3:
			if(Peek(&s,&x)==-1) puts("오류 : 피크에 실패하였습니다.\n");
			else
				printf("피크 데이터는 %d 입니다.\n", x);
			break;
		case 4:
			Print(&s);
			break;
		default:
			break;
		}
	}

	Terminate(&s);

	return 0;
}