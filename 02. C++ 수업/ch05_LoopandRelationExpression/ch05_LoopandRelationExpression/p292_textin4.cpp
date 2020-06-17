#include<iostream>

using namespace std;

int main()
{
	int ch = 0;
	int count = 0;

	while ((ch = cin.get()) != EOF)
	{
		cout.put(char(ch));
		++count;
	}
	// ctrl+z, Enter
	cout << count << "문자를 읽었습니다.\n";

	return 0;
}