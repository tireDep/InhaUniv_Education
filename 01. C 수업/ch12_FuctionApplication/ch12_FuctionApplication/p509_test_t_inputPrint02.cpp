// // Q. 사용자로부터 단어 하나를 입력받은 뒤, 그 문자열 내에 A부터 Z까지 알파벳이 각각 몇 개씩 등장하는지 세어 출력
// 대소문자는 같이 처리, 등장하지 않는 알파벳을 출력하지 않음, 알파벳 이외의 문자는 무시

// [다른 방법 풀이]

#include<stdio.h>
#include<string.h>

void Method_ASCII();
void Method_Token();

int main()
{
	Method_ASCII();	// 아스키 코드 이용
	puts("----------------------------------------------------");

	Method_Token();	// 토큰 사용
	puts("----------------------------------------------------");

	return 0;
}

void Method_ASCII()
{
	char *alpha = "abcdefghijklmnopqrstuvwxyz";
	char inputStr[128] = { 0 };

	printf("입력 : ");
	gets_s(inputStr, sizeof(inputStr));
	// 문자열 입력

	int count[26] = { 0 };
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < strlen(inputStr); j++)
		{
			if (inputStr[j] == alpha[i] || inputStr[j] == alpha[i] - 32)
			{
				count[i]++;
			}
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (count[i] != 0)
		{
			printf("%c : %d\n", alpha[i], count[i]);
		}
	}
}

void Method_Token()
{
	char inputStr[128] = { 0 };
	char enG[27] = { 0 };

	for (int i = 0; i < 26; i++)
	{
		enG[i] = i + 97;
	}

	printf("입력 : ");
	gets_s(inputStr, sizeof(inputStr));
	
	char *pszNewStart = inputStr;
	pszNewStart = strpbrk(pszNewStart, enG);

	int count[26] = { 0 };
	int i = 0;
	while (pszNewStart != NULL)	// 찾지 못할 경우 NULL 반환
	{
		count[*pszNewStart - 97]++;
		pszNewStart = strpbrk(pszNewStart + 1, enG);
	}

	for (int i = 0; i < 26; i++)
	{
		if (count[i] != 0)
		{
			printf("%c : %d\n", enG[i], count[i]);
		}
	}
}