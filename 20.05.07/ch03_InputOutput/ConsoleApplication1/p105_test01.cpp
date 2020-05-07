// 105p
// Q : getchar() 함수를 호출하여 사용자로부터 영문 네 글자 이상을 입력받고, 그중에서 두 번째 글자만 화면에 출력
#include<stdio.h>

int main()
{	
	printf("입력 : ");
	getchar();
	// rewind(stdin);
	printf("출력 : %c\n", getchar()); // 버퍼에 남아있는 문자를 입력받아옴
	return 0;
}