#pragma once

struct STACK_S
{
	int max;	// 스택 최댓값
	int nextStack;	// 다음 스택
	int *value;	// 스택의 값 첫 포인터
};

bool Initialize(STACK_S *stack, int inputNum);
int GetSize(STACK_S stack);
int GetCapacity(STACK_S stack);