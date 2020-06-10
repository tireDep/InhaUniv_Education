// 402p

#include<stdio.h>
#include<string.h>

int main()
{
	char szBuffer[32] = { "I am a boy." };

	printf("%p\n", szBuffer);	// 배열 주소 출력

	printf("%p\n", strstr(szBuffer, "am"));
	printf("%p\n", strstr(szBuffer, "boy"));
	// 대상 문자열에서 문자열을 검색하고 찾은 위치(주소) 출력

	printf("Index : %d\n", strstr(szBuffer, "am") - szBuffer);
	printf("Index : %d\n", strstr(szBuffer, "boy") - szBuffer);
	// 문자열이 검색된 위치에서 기준이 되는 주소를 빼면 인덱스 계산 가능

	/*
	----------------------------------
	추가 문제
	I'm a boy -> I'm a cat
	----------------------------------
	*/

	char *index = strstr(szBuffer, "boy");	// 주소값 반환
	if (index != NULL)
	{
		memcpy(index, "Cat", sizeof(char) * 3);	// 해당하는 주소값에 문자열 복사
	}
	
	/*
	----------------------------------
	조건 쓰는 것을 습관화 해야함!
	없을 경우를 대비한 코드 만들어야 함
	----------------------------------
	*/
	puts(szBuffer);

	return 0;
}