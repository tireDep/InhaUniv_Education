// p606_매크로

#include<stdio.h>

#define ADD(a,b) (a+b)
// 괄호가 중요함(범위)

void Macro();

// ----------------------

// p610_매크로 특수화 연산자

#define STRING(a) #a	
#define PASTER(a,b) a##b	
/*
# : 인수가 무엇이든 모두 문자열로 바꾸어주는 연산자
## : 두 매개변수를 한 덩어리로 묶어 코드를 만들어 주는 연산자
내용을 변환해 주는것은 x, 출력형태만 만들어주는 것
*/

void SpecialMacro();

// ----------------------

// p612_조건부 컴파일

#define _MSGTEST_

#ifdef _MSGTEST_
	#define MYMESSAGE "I am a boy."	// define 되어 있으면 사용
#else
	#define MYMESSAGE "You are a girl"	// define 되어 있지않으면 사용
#endif // _MSGTEST_
/*
------------------------------------------------------
사용예시
- 혼자 작업할 경우 #define xxx 1 선언
- 작업할 공간에 #ifdef xxx 선언
- 다른 사람들 사용할 공간에 #else 선언해줌
- 안전한 코드만 있을 경우 define 삭제하고 커밋
------------------------------------------------------
*/


void main()
{
	Macro();
	// ----------------------
	SpecialMacro();
}

void Macro()
{
	int a = 10, b = 20;
	double c = 30.0, d = 40.0;

	printf("%d %lf\n", ADD(a, b) * 3, ADD(c, d));

	/*
	-----------------------------------------------------------
	매크로 ≠ 함수
	매크로에 도달하면 define된 연산으로 대치됨
	사용하는 이유 -> 속도가 빠름
	간단한 연산은 훨씬 이득
	but, 많아지면 실행파일 크기가 커짐

	같은 형태 여러번 쓰이면 사용하는 것도 좋은 방법
	ex)
	#define ERROR_MSG(msg) printf("Error : %s\n", msg);
	...
	ERROR_MSG("Failed to open file!");
	-----------------------------------------------------------
	*/
}

// ------------------------------------------------------------------------------

void SpecialMacro()
{
	int nData = 10;
	printf("%s = %d\n", STRING(n10string), nData);
	// 출력값 : n10String = 10

	printf("%d \n", PASTER(nD, ata));
	// PASTER에 nData가 넘어가서 출력값은 10
	
}