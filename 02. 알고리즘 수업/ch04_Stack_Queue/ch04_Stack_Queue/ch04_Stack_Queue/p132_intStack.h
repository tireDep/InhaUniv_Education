#pragma once

struct INTSTACK_S
{
	int max;	// 스택 용량
	int ptr;	// 스택 포인터
	int *stk;	// 스택의 첫 요소에 대한 포인터
};

int Initialize(INTSTACK_S *s, int max);	// 스택 초기화

int Push(INTSTACK_S *s, int x);	// 스택에 데이터 저장

int Pop(INTSTACK_S *s, int *x);	// 스택에서 데이터를 가져옴

int Peek(const INTSTACK_S *s, int *x);	// 스택에서 데이터를 피크(삭제 x)

void Clear(INTSTACK_S *s);	// 스택 비우기

int Capacity(const INTSTACK_S *s);	// 스택의 최대 용량

int Size(const INTSTACK_S *s);	// 스택의 데이터 개수

int IsEmtpy(const INTSTACK_S *s);	// 스택이 비어 있는지

int IsFull(const INTSTACK_S *s);	// 스택 가득 차있는지

int Search(const INTSTACK_S *s, int x);	// 스택에서 검색

void Print(const INTSTACK_S *s);	// 모든 데이터 출력

void Terminate(INTSTACK_S *s);	// 스택 종료
