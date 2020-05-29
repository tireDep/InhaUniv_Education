// 612p
#include<stdio.h>

#ifdef _MYGTEST_
	#define MYMESSAGE "I am a boy."
#else
	#define MYMESSAGE "I am a girl."
#endif // _MYGTEST_

int main()
{
	puts(MYMESSAGE);
	return 0;
}