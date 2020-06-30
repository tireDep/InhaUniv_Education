#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cnt = 0;
int arr[8][8] = { 0, };

void ShowTable() 
{
	for (int i = 0; i<8; i++) 
	{
		for (int j = 0; j<8; j++) 
		{
			if (arr[i][j] == 1) 
				printf("��");
			else 
				printf("��");
		}
		printf("\n");
	}
}	// ShowTable()

//Ư�� ��ǥ�� ���� ������ ���, ���� ���� �� ���� ��ġ�� ǥ���ϴ� �Լ�
void IsAble(int x, int y) 
{
	int data_arr[8][8] = { 0, };

	for (int i = 0; i<8; i++) 
		data_arr[i][y] = 1;

	for (int j = 0; j<8; j++) 
		data_arr[x][j] = 1;

	if (x >= y) 
	{
		for (int i = 0; i<8; i++) 
		{
			for (int j = 0; j<8; j++) 
			{
				if (i - j == x - y)
					data_arr[i][j] = 1;
			}	// for_j
		}	// for_i
	}	// if
	else 
	{
		for (int i = 0; i<8; i++) 
		{
			for (int j = 0; j<8; j++) 
			{
				if (j - i == y - x)
					data_arr[i][j] = 1;
			}	// for_j
		}	// for_i
	}	// if

	for (int i = 0; i<8; i++) 
	{
		for (int j = 0; j<8; j++) 
		{
			if (i + j == x + y)
				data_arr[i][j] = 1;
		}
	}

	printf("\n");

	for (int i = 0; i<8; i++) 
	{
		printf("  ");
		for (int j = 0; j<8; j++) 
		{
			/*
			printf("%d ", data_arr[i][j]);
			*/

			if (data_arr[i][j] == 1) 
			{
				if (i == x && j == y)
					printf("��");
				else
					printf("��");
			}	// if
			else
				printf("��");
		}	// for_j
		printf("\n");
	}	// for_i
}	// IsAble()

int Able(int x, int y) 
{
	//printf("\n\nȣ��:able(%d, %d) \n", x, y);
	//arr[n][depth] = 1;

	int i, j;
	int ret_num = 1;

	// ��üũ (��� ��üũ�� �ʿ䵵 ���� ������ ��� �ϳ�������« �㳪 �������� ���ؼ�)
	for (i = 0; i<8; i++) 
	{
		if (arr[i][y] == 1) 
		{
			//����� ���⼭ return 0; �ع����� �������� ������� ���ؼ�
			//printf("�� üũ���� ����");
			ret_num = 0;
		}
	}

	// ��üũ
	for (j = 0; j<8; j++) 
	{
		if (arr[x][j] == 1) 
		{
			//����� ���⼭ return 0; �ع����� �������� ������� ���ؼ�
			//printf("�� üũ���� ����");
			ret_num = 0;
		}
	}


	// �밢�� üũ(1)
	if (x >= y) 
	{
		for (int i = 0; i<8; i++) 
		{
			for (int j = 0; j<8; j++) 
			{
				if (i - j == x - y) 
				{
					if (arr[i][j] == 1) 
						//����� ���⼭ return 0; �ع����� �������� ������� ���ؼ�
						//printf("�밢�� üũ���� ����");
						ret_num = 0;
				}
			}
		}

	}
	else 
	{
		for (int i = 0; i<8; i++) 
		{
			for (int j = 0; j<8; j++) 
			{
				if (j - i == y - x) 
				{
					if (arr[i][j] == 1)
						//����� ���⼭ return 0; �ع����� �������� ������� ���ؼ�
						//printf("�밢�� üũ���� ����");
						ret_num = 0;
				}
			}
		}
	}

	// �밢�� üũ(2) 
	for (int i = 0; i<8; i++) 
	{
		for (int j = 0; j<8; j++) 
		{
			if (i + j == x + y) 
			{
				if (arr[i][j] == 1)
					//����� ���⼭ return 0; �ع����� �������� ������� ���ؼ�
					//printf("�� �밢�� üũ���� ����");
					ret_num = 0;
			}
		}
	}

	//getchar();

	if (ret_num == 0) 
	{
		//printf("[%d,%d]���� ���� ���� �� �����ϴ�.\n\n", x, y);
		//showtable();
	}
	else 
	{
		//arr[x][y] = 1;
		//printf("[%d,%d]���� ���� ���� �� �ֽ��ϴ�.\n\n", x, y);
		//showtable();
	}
	//arr[x][y] = 0;

	return ret_num;
}

int Check(int depth) 
{
	if (depth == 8) 
	{
		cnt++; //������ ���� ���� �Ѱ� �߰�

		printf("\n----����(%02d)----\n", cnt);
		ShowTable();
		printf("\n");

		getchar(); //�Է� ���

		return 1;
	}


	for (int i = 0; i<8; i++) 
	{
		if (Able(i, depth) == 1)
		{
			arr[i][depth] = 1;
			Check(depth + 1); //����� ȣ��
		}
		arr[i][depth] = 0;
	}

	return 0;
}
int main(void) {
	srand((unsigned int)time(NULL));

	/*
	while(1) {
	IsAble(rand()%8,rand()%8);
	getchar();
	}
	*/

	Check(0);

	printf("������ �迭�� ���� : %d��\n", cnt);

	return 0;
}

