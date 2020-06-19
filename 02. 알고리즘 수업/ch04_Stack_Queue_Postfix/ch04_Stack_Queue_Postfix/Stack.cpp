#include<iostream>
#include "_stack.h"

using namespace std;

bool Initialize(STACK_S *stack, int inputNum)
{
	stack->nextStack = 0;
	stack->value = new int[inputNum];

	if (stack->value == NULL)	// ���� ����
	{
		stack->max = 0;
		return false;
	}
	else
	{
		stack->max = inputNum;
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

bool Push(STACK_S *stack, int pushData)
{
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
		cout << "\n���ÿ� �����Ͱ� �������� ����" << endl;
	else
	{
		for (int i = 0; i < stack.nextStack; i++)
		{
			cout << stack.value[i] << " ";
		}
		cout << "\n��� ����" << endl;
	}
}

bool Search(STACK_S stack, int searchData, int *index)
{
	for (int i = 0; i < stack.nextStack; i++)
	{
		if (searchData == stack.value[i])
		{
			*index = i;
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