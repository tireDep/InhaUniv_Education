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
	cout << count << "���ڸ� �о����ϴ�.\n";

	return 0;
}