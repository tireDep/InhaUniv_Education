// Q. 소수 => 약수로 1과 자기 자신만을 가지는 수
// 약수 => 어떤 수를 나누었을 때 나누어 떨어지게 하는 자연수
// 2와 1000 사이에 존재하는 모든 소수를 출력하는 프로그램 작성

#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int check = 0;
	int tmp = 1;
	cout << "소수 출력" << endl;
	cout << 2 << " ";
	for (int i = 3; i <= 1000; i+=2)
	{
		check = 0;

		for (int j = 3; j <= sqrt(i); j++) // or j <= i/2
		{
			if (i % j == 0)
				check++;
		}
		if (check == 0)
		{
			tmp++;
			cout << i << " ";
		}
	}
	cout << "갯수 : " << tmp << endl;
}

/*
int check = 0;
cout << "소수 출력" << endl;
for (int i = 2; i <= 1000; i++)
{
	if (i % 100 == 0)
		cout << endl;
	
	for (int j = 1; j <= i; j++)
	{
		if (i % j == 0)
		check++;
	}
	if (check == 2)
		cout << i << " ";
	check = 0;
}

*/