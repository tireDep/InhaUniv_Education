#pragma once

using namespace std;

struct STACK_S
{
	int max;	// ���� �ִ�
	int nextStack;	// ���� ����
	string *value;	// ������ �� ù ������
};

bool Initialize(STACK_S *stack, int inputNum);
int GetSize(STACK_S stack);
int GetCapacity(STACK_S stack);
bool IsFull(STACK_S stack);
bool IsEmpty(STACK_S stack);

bool Push(STACK_S *stack, int pushData);
bool Pop(STACK_S *stack, string *popData);
bool Peek(STACK_S *stack, string *peekData);
void Print(STACK_S stack);
bool Search(STACK_S stack, string searchData, int *index);
void Clear(STACK_S *stack);
void Terminate(STACK_S *stack);