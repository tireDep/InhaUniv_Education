// Q. 동전을 백만 번 던지는 것을 시뮬레이션 하고
// 앞면과 뒷면의 수를 출력하는 프로그램을 작성하라.
// 100 / 1,000 / 10,000 / 100,000 / 1,000,000
// 각각 앞 뒤가 몇 %씩 나오는지 계산해 출력하라

// 전제조건 : 앞, 뒤의 무게는 똑같다

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
	srand((unsigned)time(NULL));

	int side;
	int printVal = 100;
	double frontSide = 0;
	double backSide = 0;

	int i;
	cout << "[앞면 / 뒷면 확률]";
	for (i = 0; i < 1000000; i++)
	{
		side = rand() % 2;
		if (side == 0)
			backSide++;
		else
			frontSide++;

		if (i == printVal) // if (i == 100 || i == 1000 || i == 10000 || i == 100000 || i == 1000000)
		{
			printVal *= 10;
			cout << endl << i << "번 던졌을 경우\n";
			cout << "앞면 : " << frontSide / i * 100 << "%, 뒷면 : " << backSide / i * 100 <<"%\n";
		}
	}

	cout << endl << i << "번 던졌을 경우\n";
	cout << "앞면 : " << frontSide / i * 100 << "%, 뒷면 : " << backSide / i * 100 << "%\n";

	return 0;
}
