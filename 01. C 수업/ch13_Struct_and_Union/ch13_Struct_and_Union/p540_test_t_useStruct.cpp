// Q. 총 무게 10까지 담을 수 있는 인벤토리가 있다.
// 아이템마다 중요도가 있고 무게가 다르다.
// 중요도가 제일 높게 다음의 무기를 담을 수 있도록 프로그램을 작성하라
/*
이름		중요도	무게
kar98k	7		4
후라이팬	10		2
스코프	7		4
뚝배기	6		6
라이플	2		10
지도		3		5

중요도 순으로 출력할 수 있도록 할 것

중요도 1순위 : 24
kar98k	7		4
후라이팬	10		2
스코프	7		4
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
중요도 가장 높은 것 찾고, 가방에 담기
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
			if (inventory[j].checkInput != 1)	// 소지하지 않았을 경우
			{
				index = inventory[i].important < inventory[j].important ? j : i;
				// 중요도를 비교하여 더 높은 중요도의 인덱스 저장
			}
		}

		if (*yourWeight + inventory[i].weight <= MAXWEIGHT)
		{
			// 가방 무게 + 아이템 무게 기준치보다 낮을 경우에만 적재 가능
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
	다른방법
	- 중요도가 높은 순서대로 정렬 후 무게를 계산해서 출력하는 방법
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
	printf("중요도 1순위 합 : %d\n", yourImportant);
	printf("무게 합 : %d\n", yourWeight);
	printf("\n이름\t중요도\t무게\n");
	for (int i = 0; i < MAXITEM; i++)
	{
		if (yourItem[i].important != 0)
		{
			printf("%s\t%2d\t%2d\n", yourItem[i].name, yourItem[i].important, yourItem[i].weight);
		}
	}
}