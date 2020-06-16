// Q7. 외따로 떨어진 q가 입력될 때까지 한 번에 한 단어씩 입력을 읽는 프로그램을 작성하라.
// 프로그램은 모음으로 시작하는 단어 수, 자음으로 시작하는 단어 수, 두 범주의 어디에도 속하지 않는 것들의 수를 보고해야 한다.
// 한 가지 방법은, 글자들로 시작하는 단어와 그렇지 않은 것들을 구별하기 위해 isalpha()를 사용하고나서,
// if 또는 switch 구문을 사용하여 isalpha() 검사에 전달된 것 들 중에서 모음으로 시작하는 단어를 다시 식별하는 것이다.
// 프로그램의 실행 예는 다음과 같이 될 것 이다.

// ex)
// 단어들을 입력하시오(끝내려면 q) : 
// The 12 awesome oxen ambled
// quietly across 15 meters of lawn. q
// 모음으로 시작하는 단어 수 : 5
// 자음으로 시작하는 단어 수 : 4
// 기타 : 2

#include<iostream>
#include<cctype>

using namespace std;

int main()
{
	char inputCh[50] = { 0 };
	int elseCh = 0;
	int consonant = 0;	// 자음
	int vowel = 0; // 모음
	cout << "단어들을 입력하시오(끝내려면 q) : ";
	cin >> inputCh;

	while (strcmp(inputCh, "q"))	// strcmp : 1(앞에가 큼), -1(뒤에가 큼), 0(같음)
	{
		if (!isalpha(inputCh[0]))
			elseCh++;
		else
		{		
			for (int i = 0; i < strlen(inputCh); i++)
			{
				inputCh[i] = tolower(inputCh[i]);
			}

			switch (inputCh[0])
			{
			case 'w': case 'e': case 'y':
			case 'u': case 'i': case 'o': case 'a':
				vowel++;
				break;

			default:
				consonant++;
				break;
			}
		}
		cin >> inputCh;

	}
	cout << endl << "모음으로 시작하는 단어 수 : " << vowel
		<< endl << "자음으로 시작하는 단어 수 : " << consonant 
		<< endl << "기타 : " << elseCh << endl;

	return 0;
}