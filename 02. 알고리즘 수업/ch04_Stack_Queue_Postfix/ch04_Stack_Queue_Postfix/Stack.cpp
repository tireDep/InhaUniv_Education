#include<iostream>
#include "_stack.h"

using namespace std;

bool Initialize(STACK_S *stack, int dataSize)
{
	stack->nextStack = 0;
	stack->value = new int[dataSize];

	if (stack->value == NULL)	// 생성 실패
	{
		stack->max = 0;
		return false;
	}
	else
	{
		stack->max = dataSize;
		return true;
	}
}

int GetSize(STACK_S stack)
{
	return stack.nextStack;
}

int GetCapacity(STACK_S stack)
{
	return stack.max;
}

bool IsFull(STACK_S stack)
{
	if (stack.max <= stack.nextStack)
		return false;
	else
		return true;
}

bool IsEmpty(STACK_S stack)
{
	if (0 >= stack.nextStack)
		return false;
	else
		return true;
}

bool Push(STACK_S *stack)
{
	int pushData;
	cout << "데이터 입력 : ";
	cin >> pushData;
	if (!IsFull(*stack))
		return false;
	else
	{
		stack->value[stack->nextStack] = pushData;
		stack->nextStack++;
	}
	return true;
}

bool Pop(STACK_S *stack, int *popData)
{
	if (!IsEmpty(*stack))
		return false;
	else
	{
		*popData = stack->value[stack->nextStack - 1];
		stack->nextStack--;
	}
	return true;
}

bool Peek(STACK_S *stack, int *peekData)
{
	if (!IsEmpty(*stack))
		return false;
	else
		*peekData = stack->value[stack->nextStack - 1];
	return true;
}

void Print(STACK_S stack)
{
	cout << endl;
	if (!IsEmpty(stack))
		cout << "\n스택에 데이터가 존재하지 않음" << endl;
	else
	{
		for (int i = 0; i < stack.nextStack; i++)
		{
			cout << stack.value[i] << " ";
		}
		cout << "\n출력 종료" << endl;
	}
}

bool Search(STACK_S stack)
{
	int searchData;
	cout << "검색할 값 입력 : ";
	cin >> searchData;

	for (int i = 0; i < stack.nextStack; i++)
	{
		if (searchData == stack.value[i])
		{
			cout << "\n검색 결과 : " << searchData;
			cout << "\n해당 값은 인덱스 번호 [" << i << "] 에 존재" << endl;
			return true;
		}
	}

	return false;
}

void Clear(STACK_S *stack)
{
	stack->nextStack = 0;
	for (int i = 0; i < stack->max; i++)
	{
		stack->value[i] = 0;
	}
}

void Terminate(STACK_S *stack)
{
	delete[] stack->value;
}