// 구조체 멤버맞춤

#include<stdio.h>

#pragma pack(push,1)

struct userData_s
{
	char ch;
	int nAge;
};

struct myData
{
	char ch;
	int nAge;
	double dData;
};

#pragma pack(pop)

int main()
{
	printf("%d\n", sizeof(userData_s));
	printf("%d\n", sizeof(myData));

	return 0;
}


/*
------------------------------------------------------------------------------
#pragma pack이 없으면, 구조체 멤버 맞춤에 의해서 8바이트로 기본 설정됨

로컬에선 상관 x,
but 파일 입출력이나 외부로 전송할 경우 공간이 절약되고 쓰레기값이 방지된다!
------------------------------------------------------------------------------
*/

/*
비트필드
- 구조체 멤버가 바이트 단위가 아닌 비트 단위 데이터를 다루는 멤버로 선언되는 구조체
- 잘 사용하지 x, 알아만 둘 것

struct _dataFlag
{
	unsigned char main : 1;	// 8비트 중 오른쪽 1비트
	unsigned char left : 2;	// 오른쪽 2~3 비트
	unsigned char right : 3;	// 오른쪽 4~6 비트
	unsigned char top : 2;	// 왼쪽 2비트
};

*/