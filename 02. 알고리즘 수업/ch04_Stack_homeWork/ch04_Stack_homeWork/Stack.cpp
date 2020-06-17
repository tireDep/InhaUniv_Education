#include<iostream>
#include "_stack.h"

bool Initialize(STACK_S *stack, int inputNum)
{
	stack->nextStack = 0;
	stack->value = new int[inputNum];

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