#pragma once

struct INTSTACK_S
{
	int max;	// ���� �뷮
	int ptr;	// ���� ������
	int *stk;	// ������ ù ��ҿ� ���� ������
};

int Initialize(INTSTACK_S *s, int max);	// ���� �ʱ�ȭ

int Push(INTSTACK_S *s, int x);	// ���ÿ� ������ ����

int Pop(INTSTACK_S *s, int *x);	// ���ÿ��� �����͸� ������

int Peek(const INTSTACK_S *s, int *x);	// ���ÿ��� �����͸� ��ũ(���� x)

void Clear(INTSTACK_S *s);	// ���� ����

int Capacity(const INTSTACK_S *s);	// ������ �ִ� �뷮

int Size(const INTSTACK_S *s);	// ������ ������ ����

int IsEmtpy(const INTSTACK_S *s);	// ������ ��� �ִ���

int IsFull(const INTSTACK_S *s);	// ���� ���� ���ִ���

int Search(const INTSTACK_S *s, int x);	// ���ÿ��� �˻�

void Print(const INTSTACK_S *s);	// ��� ������ ���

void Terminate(INTSTACK_S *s);	// ���� ����
