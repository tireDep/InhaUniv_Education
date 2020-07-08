#include<stdio.h>
#include"p292_bitSet.h"

enum { ADD, RMV, SCH };

int ScanData(int sw);

int main()
{
	Bitset s1 = BitSetNull;
	Bitset s2 = BitSetNull;
	while (1)
	{
		int m, x, idx;
		printf("s1 = ");
		PrintLn(s1);
		printf("s2 = ");
		PrintLn(s2);
		printf("(1) s1에 추가 (2) s1에서 삭제 (3) s1에서 검색 (4) s1 <- s2 (5) 여러 연산\n");
		printf("(6) s2에 추가 (7) s2에서 삭제 (8) s2에서 검색 (9) s2 <- s1 (0) 종료\n");

		scanf_s("%d", &m);
		if (m == 0)
			break;
		switch (m)
		{
		case 1:
			x = ScanData(ADD);
			Add(&s1, x);
			break;
		case 2:
			x = ScanData(RMV);
			Remove(&s1, x);
			break;
		case 3:
			x = ScanData(SCH);
			idx = IsMember(s1, x);
			printf("s1에 들어 있%s.\n", idx >= 0 ? "습니다" : "지 않습니다");
			break;
		case 4:
			s1 = s2;
			break;
		case 5:
			printf("s1 == s2 %s\n", s1 == s2 ? "true" : "false");
			printf("s1 & s2 = ");
			PrintLn(s1 & s2);
			printf("s1 | s2 = ");
			PrintLn(s1 | s2);
			printf("s1 - s2 = ");
			PrintLn(s1 - s2);
			break;
		case 6:
			x = ScanData(ADD);
			Add(&s2, x);
			break;
		case 7:
			x = ScanData(RMV);
			Remove(&s2, x);
			break;
		case 8:
			x = ScanData(SCH);
			idx = IsMember(s2, x);
			printf("s2에 들어 있%s.\n", idx >= 0 ? "습니다" : "지 않습니다");
			break;
		case 9:
			s2 = s1;
			break;
		default:
			break;
		}	// switch
	}
}

int ScanData(int sw)
{
	int data;
	switch (sw)
	{
	case ADD:
		printf("추가할 데이터 : ");
		break;
	case RMV:
		printf("삭제할 데이터 : ");
		break;
	case SCH:
		printf("검색할 데이터 : ");
		break;
	default:
		break;
	}
	scanf_s("%d", &data);

	return data;
}