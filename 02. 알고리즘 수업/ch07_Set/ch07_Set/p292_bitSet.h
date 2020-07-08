#pragma once

typedef unsigned long Bitset;	// ������ ��Ÿ���� �ڷ���

#define BitSetNull (Bitset)0	// ������
#define BitSetBits 32	// ��ȿ ��Ʈ ��
#define SetOf(no) ((Bitset)1<<(no))	// ���� no

int IsMember(Bitset s, int n);	// ���� s�� n�� �ִ��� Ȯ��
void Add(Bitset *s, int n);	// ���� s�� n�� �߰�
void Remove(Bitset *s, int n);	// ���� s���� n�� ����
int Size(Bitset s);	// ���� s�� ���� ������ ��ȯ
void Print(Bitset s);	// ���� s�� ��� ���Ҹ� ���
void PrintLn(Bitset s);	// ���� s�� ��� ���Ҹ� ���(�� �ٲ� ���� ����)

// ---------------------------------------------------------------------
// todo
// - ��Ī �������� ���Ͽ� ����ϴ� �Լ� �߰�
// ��Ī ������ : �� ������ ����κ��� �� ������ ���ҵ��� ����, ��Ī�� ��� ��