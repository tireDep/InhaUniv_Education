#pragma once

typedef unsigned long Bitset;	// 집합을 나타내는 자료형

#define BitSetNull (Bitset)0	// 공집합
#define BitSetBits 32	// 유효 비트 수
#define SetOf(no) ((Bitset)1<<(no))	// 집합 no

int IsMember(Bitset s, int n);	// 집합 s에 n이 있는지 확인
void Add(Bitset *s, int n);	// 집합 s에 n을 추가
void Remove(Bitset *s, int n);	// 집합 s에서 n을 삭제
int Size(Bitset s);	// 집합 s의 원소 개수를 반환
void Print(Bitset s);	// 집합 s의 모든 원소를 출력
void PrintLn(Bitset s);	// 집합 s의 모든 원소를 출력(줄 바꿈 문자 포함)

// ---------------------------------------------------------------------
// todo
// - 대칭 차집합을 구하여 출력하는 함수 추가
// 대칭 차집합 : 두 집합의 공통부분을 뺀 나머지 원소들의 집합, 대칭차 라고도 함