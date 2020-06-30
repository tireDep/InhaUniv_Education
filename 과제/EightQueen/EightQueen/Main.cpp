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
				printf("▩");
			else 
				printf("□");
		}
		printf("\n");
	}
}	// ShowTable()

//특정 좌표에 퀸이 놓였을 경우, 퀸을 놓을 수 없는 위치를 표시하는 함수
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
					printf("▣");
				else
					printf("▩");
			}	// if
			else
				printf("□");
		}	// for_j
		printf("\n");
	}	// for_i
}	// IsAble()

int Able(int x, int y) 
{
	//printf("\n\n호출:able(%d, %d) \n", x, y);
	//arr[n][depth] = 1;

	int i, j;
	int ret_num = 1;

	// 행체크 (사실 행체크는 필요도 없음 로직이 행당 하나씩들어가게짬 허나 직관성을 위해서)
	for (i = 0; i<8; i++) 
	{
		if (arr[i][y] == 1) 
		{
			//사실은 여기서 return 0; 해버리면 더빠르나 디버깅을 위해서
			//printf("행 체크에서 문제");
			ret_num = 0;
		}
	}

	// 열체크
	for (j = 0; j<8; j++) 
	{
		if (arr[x][j] == 1) 
		{
			//사실은 여기서 return 0; 해버리면 더빠르나 디버깅을 위해서
			//printf("열 체크에서 문제");
			ret_num = 0;
		}
	}


	// 대각선 체크(1)
	if (x >= y) 
	{
		for (int i = 0; i<8; i++) 
		{
			for (int j = 0; j<8; j++) 
			{
				if (i - j == x - y) 
				{
					if (arr[i][j] == 1) 
						//사실은 여기서 return 0; 해버리면 더빠르나 디버깅을 위해서
						//printf("대각선 체크에서 문제");
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
						//사실은 여기서 return 0; 해버리면 더빠르나 디버깅을 위해서
						//printf("대각선 체크에서 문제");
						ret_num = 0;
				}
			}
		}
	}

	// 대각선 체크(2) 
	for (int i = 0; i<8; i++) 
	{
		for (int j = 0; j<8; j++) 
		{
			if (i + j == x + y) 
			{
				if (arr[i][j] == 1)
					//사실은 여기서 return 0; 해버리면 더빠르나 디버깅을 위해서
					//printf("역 대각선 체크에서 문제");
					ret_num = 0;
			}
		}
	}

	//getchar();

	if (ret_num == 0) 
	{
		//printf("[%d,%d]에는 돌을 놓을 수 없습니다.\n\n", x, y);
		//showtable();
	}
	else 
	{
		//arr[x][y] = 1;
		//printf("[%d,%d]에는 돌을 놓을 수 있습니다.\n\n", x, y);
		//showtable();
	}
	//arr[x][y] = 0;

	return ret_num;
}

int Check(int depth) 
{
	if (depth == 8) 
	{
		cnt++; //가능한 판의 개수 한개 추가

		printf("\n----성립(%02d)----\n", cnt);
		ShowTable();
		printf("\n");

		getchar(); //입력 대기

		return 1;
	}


	for (int i = 0; i<8; i++) 
	{
		if (Able(i, depth) == 1)
		{
			arr[i][depth] = 1;
			Check(depth + 1); //재귀적 호출
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

	printf("가능한 배열의 개수 : %d개\n", cnt);

	return 0;
}

