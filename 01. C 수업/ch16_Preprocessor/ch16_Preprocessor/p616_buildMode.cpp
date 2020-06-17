#include<stdio.h>

#ifdef _DEBUG
	#define MODEMESSAGE "Debug mode"
#else
	#define MODEMESSAGE "Release mode"
#endif // _DEBUG

int main()
{
	puts(MODEMESSAGE);
	return 0;
}

/*
-----------------------------------------------------------------------------
배포할 경우, Release Mode로 빌드하는 것이 좋음
- Debug Mode의 경우, 해커들이 접근하기 쉬움

Debug Mode에서 실행되는 것이 Release Mode에서 실행되지 않을 수 있음

실제 개발 후 배포할 때
유닛단위 or 하루단위로 개발한 후 Debug Mode 테스트 -> Release Mode 테스트
-----------------------------------------------------------------------------
*/