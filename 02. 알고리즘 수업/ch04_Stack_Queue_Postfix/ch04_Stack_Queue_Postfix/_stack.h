#pragma once

struct STACK_S
{
	int max;	// ���� �ִ�
	int nextStack;	// ���� ����
	int *value;	// ������ �� ù ������
};

bool Initialize(STACK_S *stack, int inputNum);
int GetSize(STACK_S stack);
int GetCapacity(STACK_S stack);
bool IsFull(STACK_S stack);
bool IsEmpty(STACK_S stack);

bool Push(STACK_S *stack, int pushData);
bool Pop(STACK_S *stack, int *popData);
bool Peek(STACK_S *stack, int *peekData);
void Print(STACK_S stack);
bool Search(STACK_S stack, int searchData, int *index);
void Clear(STACK_S *stack);
void Terminate(STACK_S *stack);