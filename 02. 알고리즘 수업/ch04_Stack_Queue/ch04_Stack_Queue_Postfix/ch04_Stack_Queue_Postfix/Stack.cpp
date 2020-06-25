#include<iostream>
#include<string>
#include "_stack.h"

using namespace std;

bool Initialize(STACK_S *stack, int inputNum)
{
	stack->nextStack = 0;
	stack->value = new string[inputNum];

	if (stack->value == NULL)	// 생성 실패
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

bool Push(STACK_S *stack, string pushData)
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

bool Pop(STACK_S *stack, string *popData)
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

void Terminate(STACK_S *stack)
{
	delete[] stack->value;
}