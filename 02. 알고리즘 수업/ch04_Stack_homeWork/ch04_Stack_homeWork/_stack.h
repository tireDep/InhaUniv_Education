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