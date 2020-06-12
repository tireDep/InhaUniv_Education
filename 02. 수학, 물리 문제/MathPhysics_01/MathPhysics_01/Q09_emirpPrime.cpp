// Q. 역회문 소수(Emirp prime) : 소수를 뒤집어도 소수가 되는 소수를 찾아 출력
// 2 ~ 1000
// ex) 13, 17, ...31, 71

#include<iostream>
#include<string>
#include<cmath>

void CheckDivide(int maxNum, int *check);

using namespace std;

int main()
{
	int check = 0;
	int tmp = 0;
	int reverse[3] = { 0 };
	int reversernum = 0;
	for (int i = 2; i <= 1000; i++)
	{
		check = 0;
		CheckDivide(i, &check);

		if (check == 2)
		{
			tmp = i;
			for (int k = 0; k<sizeof(reverse) / sizeof(int); k++)
			{
				reverse[k] = (tmp % 10);
				tmp = tmp / 10;
			}

			reversernum = 0;
			for (int y = sizeof(reverse) / sizeof(int) - 1; y >= 0; y--)
			{
				if (reverse[sizeof(reverse) / sizeof(int) - 1] != 0)
				{
					if (y == sizeof(reverse) / sizeof(int) - 1) reversernum += reverse[y];
					else if (y == sizeof(reverse) / sizeof(int) - 2) reversernum += reverse[y] * 10;
					else reversernum += reverse[y] * 100;
				}
				else
				{
					if (y == sizeof(reverse) / sizeof(int) - 2) reversernum += reverse[y];
					else reversernum += reverse[y] * 10;
				}
			}

			check = 0;
			CheckDivide(reversernum, &check);
			if (check == 2)
				cout << i << " ";
		}

	}

	return 0;
}

void CheckDivide(int maxNum, int *check)
{
	for (int j = 1; j <= maxNum; j++)
	{
		if (maxNum % j == 0)
			(*check)++;
	}
}