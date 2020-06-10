// Q. �� ���� 10���� ���� �� �ִ� �κ��丮�� �ִ�.
// �����۸��� �߿䵵�� �ְ� ���԰� �ٸ���.
// �߿䵵�� ���� ���� ������ ���⸦ ���� �� �ֵ��� ���α׷��� �ۼ��϶�
/*
�̸�		�߿䵵	����
kar98k	7		4
�Ķ�����	10		2
������	7		4
�ҹ��	6		6
������	2		10
����		3		5

�߿䵵 ������ ����� �� �ֵ��� �� ��

�߿䵵 1���� : 24
kar98k	7		4
�Ķ�����	10		2
������	7		4
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXITEM 6
#define MAXWEIGHT 10

struct Items_s
{
	char name[8];
	int important;
	int weight;

	int checkInput = 0;
};

/*
�߿䵵 ���� ���� �� ã��, ���濡 ���
*/

void CheckMem(Items_s *mem);
void CheckFree(Items_s *mem);

void InputItem(Items_s *inventory);
void ImportantInput(Items_s *inventory, Items_s *yourItem, int *yourImportant, int *yourWeight);
void PrintYourItem(Items_s *yourItem, int yourImportant, int yourWeight);

void LightWeightInput(Items_s *inventory, Items_s *yourItem, int *yourImportant, int *yourWeight);

int main()
{
	Items_s *inventory = NULL;
	inventory = (Items_s *)malloc(sizeof(Items_s) * MAXITEM);
	CheckMem(inventory);

	Items_s *yourItem = NULL;
	yourItem = (Items_s *)malloc(sizeof(Items_s) * MAXITEM);
	CheckMem(yourItem);

	InputItem(inventory);

	int yourWeight = 0;
	int yourImportant = 0;
	ImportantInput(inventory, yourItem, &yourImportant, &yourWeight);
	PrintYourItem(yourItem, yourImportant, yourWeight);

	puts("");

	yourWeight = 0;
	yourImportant = 0;
	for (int i = 0; i < MAXITEM; i++)
	{
		inventory[i].checkInput = 0;
	}
	LightWeightInput(inventory, yourItem, &yourImportant, &yourWeight);
	PrintYourItem(yourItem, yourImportant, yourWeight);

	CheckFree(inventory);
	CheckFree(yourItem);

	return 0;
}

void CheckMem(Items_s *mem)
{
	if (mem == NULL)
	{
		puts("Error!");
		exit(0);
	}
	else
		memset(mem, 0, sizeof(Items_s)*MAXITEM);
}

void CheckFree(Items_s *mem)
{
	if (mem != NULL)
		free(mem);
}

void InputItem(Items_s *inventory)
{
	char nameArr[MAXITEM][8] = { "kar98r", "pan", "scope", "pot", "raffle", "map" };
	char numArr[MAXITEM][2] = { { 7,4 },{ 10,2 },{ 7,4 },{ 6,6 },{ 2,10 },{ 3,5 } };

	for (int i = 0; i < MAXITEM; i++)
	{
		memcpy(inventory[i].name, nameArr[i], sizeof(inventory[i].name));
		inventory[i].important = numArr[i][0];
		inventory[i].weight = numArr[i][1];
	}
}

void ImportantInput(Items_s *inventory, Items_s *yourItem, int *yourImportant, int *yourWeight)
{
	int index;
	for (int i = 0; i < MAXITEM - 1; i++)
	{
		for (int j = i; j < MAXITEM; j++)
		{
			if (inventory[j].checkInput != 1)	// �������� �ʾ��� ���
			{
				index = inventory[i].important < inventory[j].important ? j : i;
				// �߿䵵�� ���Ͽ� �� ���� �߿䵵�� �ε��� ����
			}
		}

		if (*yourWeight + inventory[i].weight <= MAXWEIGHT)
		{
			// ���� ���� + ������ ���� ����ġ���� ���� ��쿡�� ���� ����
			yourItem[i] = inventory[index];
			*yourWeight += inventory[index].weight;
			*yourImportant += inventory[index].important;
			inventory[index].checkInput = 1;
		}
		else
			continue;
	}
	
	/*
	------------------------------------------------------------
	�ٸ����
	- �߿䵵�� ���� ������� ���� �� ���Ը� ����ؼ� ����ϴ� ���
	-------------------------------------------------------------
	*/
}

void LightWeightInput(Items_s *inventory, Items_s *yourItem, int *yourImportant, int *yourWeight)
{
	int index;
	for (int i = 0; i < MAXITEM - 1; i++)
	{
		index = i;
		for (int j = i; j < MAXITEM; j++)
		{
			if (inventory[j].checkInput != 1)
			{
				if (inventory[index].weight > inventory[j].weight)
					index = j;
			}
		}

		yourItem[i] = inventory[index];
		*yourWeight += inventory[index].weight;
		*yourImportant += inventory[index].important;
		inventory[index].checkInput = 1;

		if (*yourWeight >= 10)
			break;
	}
}

void PrintYourItem(Items_s *yourItem, int yourImportant, int yourWeight)
{
	printf("�߿䵵 1���� �� : %d\n", yourImportant);
	printf("���� �� : %d\n", yourWeight);
	printf("\n�̸�\t�߿䵵\t����\n");
	for (int i = 0; i < MAXITEM; i++)
	{
		if (yourItem[i].important != 0)
		{
			printf("%s\t%2d\t%2d\n", yourItem[i].name, yourItem[i].important, yourItem[i].weight);
		}
	}
}