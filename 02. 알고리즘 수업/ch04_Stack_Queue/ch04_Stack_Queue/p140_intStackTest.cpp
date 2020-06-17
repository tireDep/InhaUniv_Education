// 140p

#include<stdio.h>
#include"p132_intStack.h"

int main()
{
	INTSTACK_S s;
	if (Initialize(&s, 64) == -1)
	{
		puts("���� ������ �����Ͽ����ϴ�.\n");
		return 1;
	}

	int menu, x;
	while (1)
	{
		printf("���� ������ �� : %d / %d\n", Size(&s), Capacity(&s));
		printf("(1) Ǫ�� (2) �� (3) ��ũ (4) ��� (0) ���� \n\n�Է� : ");
		scanf_s("%d", &menu);

		if (menu == 0) break;
		
		switch (menu)
		{
		case 1:
			printf("������ : ");
			scanf_s("%d", &x);
			if (Push(&s, x) == -1) puts("���� : Ǫ�ÿ� �����Ͽ����ϴ�n\n");
			break;
		case 2:
			if (Pop(&s, &x) == -1) puts("���� : �˿� �����Ͽ����ϴ�.\n");
			else
				printf("�� �����ʹ� %d �Դϴ�.\n", x);
			break;
		case 3:
			if(Peek(&s,&x)==-1) puts("���� : ��ũ�� �����Ͽ����ϴ�.\n");
			else
				printf("��ũ �����ʹ� %d �Դϴ�.\n", x);
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