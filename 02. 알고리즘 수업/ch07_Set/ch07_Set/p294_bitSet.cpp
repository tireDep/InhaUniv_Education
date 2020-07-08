#include<stdio.h>
#include"p292_bitSet.h"

int IsMember(Bitset s, int n)
{
	return s & SetOf(n);
}

void Add(Bitset *s, int n)
{
	*s |= SetOf(n);
}

void Remove(Bitset *s, int n)
{
	*s &= ~SetOf(n);
}

int Size(Bitset s)
{
	int n = 0;
	for (; s != BitSetNull; n++)
		s &= s - 1;

	return n;
}

void Print(Bitset s)
{
	printf("{");
	for (int i = 0; i < BitSetBits; i++)
	{
		if (IsMember(s, i))
			printf("%d ", i);
	}
	printf("}");
}

void PrintLn(Bitset s)
{
	Print(s);
	putchar('\n');
}