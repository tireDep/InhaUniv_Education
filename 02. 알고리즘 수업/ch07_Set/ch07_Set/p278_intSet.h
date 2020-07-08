#pragma once

struct IntSet
{
	int max;	// ������ ũ��
	int num;	// ������ ���� ����
	int *set;	// ���� ��ü�� �迭(�� ù ��° ��ҿ� ���� ������)
};

int Initialize(IntSet *s, int max);	// ���� �ʱ�ȭ
int IsMember(const IntSet *s, int n);	// ���� s�� n�� ��� �ִ��� Ȯ��
void Add(IntSet *s, int n);	// ���� s�� n�� �߰�
void Remove(IntSet *s, int n);	// ���� s���� n�� ����
int Capacity(const IntSet *s);	// ���� s�� ���� �� �ִ� �ִ��� ���� ������ ��ȯ
int Size(const IntSet *s);	// ���� s�� ���� ����
void Assign(IntSet *s1, const IntSet *s2);	// ���� s2�� ���� s1�� ����
int Equal(const IntSet *s1, const IntSet *s2);	// ���� s1�� s2�� ������ Ȯ��

IntSet *Union(IntSet *s1, const IntSet *s2, const IntSet *s3);	// ���� s2�� s3�� �������� s1�� ����
IntSet *Intersection(IntSet *s1, const IntSet *s2, const IntSet *s3);	// ���� s2�� s3�� �������� s1�� ����
IntSet *Difference(IntSet *s1, const IntSet *s2, const IntSet *s3);	// ���� s2���� s3�� �� �������� s1�� ����

void Print(const IntSet *s);	// ���� s�� ��� ���Ҹ� ���
void PrintLn(const IntSet *s);	// ���� s�� ��� ���Ҹ� ���(�� �ٲ� ���� ����)
void Terminate(IntSet *s);	// ���� ����

// ---------------------------------------------

// todo
// int IsFull(const IntSet *s);	// ������ ���� á�ٸ� 1, �ƴ϶�� 0�� ��ȯ
// void Clear(IntSet *s);	// ������ ��� ���Ҹ� �����ϴ� �Լ�
// IntSet *SymmetricDiffenrence(IntSet *s1, const IntSet *s2, const IntSet *s3);	// ���� s2, s3�� ��Ī ���� s1�� �����ϴ� �Լ�
// IntSet *ToUnion(IntSet *s1, const IntSet *s2);	// ���� s1�� s2�� ��� ���Ҹ� �߰��ϴ� �Լ�(s1 ������ ��ȯ)
// IntSet *ToInterSection(IntSet *s1, const IntSet *s2);	// ���� s1���� s2�� ��� ���� ���� ��� ���Ҹ� �����ϴ� �Լ�(s1 ������ ��ȯ)
// IntSet *ToDifference(IntSet *s1, const IntSet *s2);	// ���� s1���� s2�� ����ִ� ��� ���Ҹ� �����ϴ� �Լ�(s1 ������ ��ȯ)