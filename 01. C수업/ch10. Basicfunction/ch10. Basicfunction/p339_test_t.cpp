// Q. 사칙 연산 프로그램을 함수 호출 형태로 만들어라
// 형태
// 1. 메뉴출력
// 2. 값 입력
// 3. 연산
// 4. 결과 출력
// 각각을 함수로 만들고 호출해서 사용할 수 있도록 할 것

#include<stdio.h>

int SelectMenu();

int InputNumber(int selectNum);

int PlusFuc(int num1, int num2);
int MinusFuc(int num1, int num2);
int MultFuc(int num1, int num2);
int DivFuc(int num1, int num2);

void ResultFuc(int result);

int main()
{
	int _input;
	int result;
	
	while (1)
	{
		_input = SelectMenu();
		if (_input == 5)
		{
			return 0;
		}
		result = InputNumber(_input);
		ResultFuc(result);
	}

	return 0;
}	// main()

int SelectMenu()
{
	int input;
	printf("[원하는 연산 선택]\n1. +\t2. -\t3. x\t4. %%\t5. 종료 \n");
	printf("입력 : ");
	scanf_s("%d", &input);
	return input;
}	// int SelectMenu()

int InputNumber(int selectNum)
{
	int result = 0;
	
	int num1, num2;
	printf("숫자 입력 : ");
	scanf_s("%d %d", &num1, &num2);

	switch (selectNum)
	{
		case 1:
			result = PlusFuc(num1, num2);
			break;
		case 2:
			result = MinusFuc(num1, num2);
			break;
		case 3:
			result = MultFuc(num1, num2);
			break;
		case 4:
			result = DivFuc(num1, num2);
			break;
		default:
			puts("ERROR");
			return 0;
	}
	return result;
}	// int InputNumber(int selectNum)

int PlusFuc(int num1, int num2)
{
	puts("\n[덧셈 선택]");	
	return num1 + num2;
}	// int PlusFuc(int num1, int num2)

int MinusFuc(int num1, int num2)
{
	puts("\n[뺄셈 선택]");
	return num1 - num2;
}	// int MinusFuc(int num1, int num2)

int MultFuc(int num1, int num2)
{
	puts("\n[곱셈 선택]");
	return num1 * num2;
}	// int MultFuc(int num1, int num2)

int DivFuc(int num1, int num2)	
{
	puts("\n[나눗셈 선택]");
	return num1 / num2;
}	// int DivFuc(int num1, int num2)	

void ResultFuc(int result)
{
	printf("결과값 : %d\n\n", result);
	return;
}	// void ResultFuc(int result)