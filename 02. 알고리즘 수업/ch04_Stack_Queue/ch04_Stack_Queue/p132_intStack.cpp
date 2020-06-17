// 134p ~ 139p

#include<stdio.h>
#include<stdlib.h>
#include"p132_intStack.h"

int Initialize(INTSTACK_S *s, int max)
{
	s->ptr = 0;
	if ((s->stk = (int *) calloc(max, sizeof(int))) == NULL)
	{
		s->max = 0;
		return -1;
	}
	s->max = max;
	return 0;
}

int Push(INTSTACK_S *s, int x)
{
	if (s->ptr >= s->max)
		return -1;	// 스택이 가득 참
	s->stk[s->ptr++] = x;
	
	return 0;
}

int Pop(INTSTACK_S *s, int *x)
{
	if (s->ptr <= 0)
		return -1;	// 스택이 비어있음
	*x = s->stk[s->ptr - 1];
	s->ptr--;

	return 0;
}

int Peek(const INTSTACK_S *s, int *x)
{
	if (s->ptr <= 0)
		return -1;	// 스택이 비어있음

	*x = s->stk[s->ptr - 1];

	return 0;
}

void Clear(INTSTACK_S *s)
{
	s->ptr = 0;
}

int Capacity(const INTSTACK_S *s)
{
	return s->max;
}

int Size(const INTSTACK_S *s)
{
	return s->ptr;
}

int IsEmtpy(const INTSTACK_S *s)
{
	return s->ptr <= 0;
}

int IsFull(const INTSTACK_S *s)
{
	return s->ptr >= s->max;
}

int Search(const INTSTACK_S *s, int x)
{
	for (int i = s->ptr - 1; i >= 0; i--)
	{
		if (s->stk[i] == x)
			return i;
	}
	return -1;
}

void Print(const INTSTACK_S *s)
{
	for (int i = 0; i < s->ptr; i++)
	{
		printf("%d", s->stk[i]);
	}
	putchar('\n');
}

void Terminate(INTSTACK_S *s)
{
	if (s->stk != NULL)
		free(s->stk);
	s->max = s->ptr = 0;
}
