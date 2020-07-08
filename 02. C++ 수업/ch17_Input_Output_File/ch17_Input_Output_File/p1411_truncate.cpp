// 입력 행이 길 때 get()을 사용하여 자른다
#include<iostream>

const int SLEN = 10;
inline void eatLine() { while (std::cin.get() != '\n') continue; }

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;

	char name[SLEN];
	char title[SLEN];

	cout << "이름을 입력하십시오.\n";
	cin.get(name, SLEN);

	if (cin.peek() != '\n')
		cout << "죄송합니다. 이름란이 좁아서 " << name << "만 적어넣었습니다.\n";
	eatLine();

	cout << name << "씨! 직위를 입력하십시오.\n";
	cin.get(title, SLEN);
	if (cin.peek() != '\n')
		cout << "직위도 뒷 부분을 잘랐습니다.\n";
	eatLine();
	cout << "이름 : " << name << "\n직위 : " << title << endl;

	return 0;
}