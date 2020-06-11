// 232p 5 + 6 + 9
// Q5. candybar 구조체는 세 개의 멤버를 가지고 있다.
// 첫 번째 멤버는 캔디바의 상표명 저장, 두 번째 멤버는 캔디바의 중량(소수부 가질 수 있음), 세 번째 멤버는 캔디바의 칼로리 저장
// 구조체를 선언하고, snack이라는 캔디바형 구조체 변수를 만든다음 특정 값으로 초기화하라(Moch Munchm, 2.3, 350)
// 초기화는 스낵을 선언할 때 함께 하고, 스낵 변수의 내용을 출력

// Q6. 세 개의 캔디바 구조체를 원소로 가지는 배열을 만들고, 그 배열의 구조체 원소들을 원하는 값으로 초기화 한 후
// 구조체의 내용을 출력하는 프로그램 작성

// Q9. 세 개의 캔디바 구조체 변수를 선언하는 대신에 new를 사용하여 그 배열을 동적으로 대입

#include<iostream>
#include<string>

using namespace std;

struct CandyBar_S
{
	string candyName;
	double candyWeight;
	int candyCal;
};

int main()
{
	CandyBar_S snack = { "Mocha Munch", 2.3,350 };
	cout << "Q5.\n";
	cout << "[출력]\n상표명 : " << snack.candyName 
		<< "\n중량 : " << snack.candyWeight 
		<< "\n칼로리 : " << snack.candyCal;

	
	CandyBar_S candyArr[3];
	CandyBar_S snack_1 = { "Mocha Munch", 2.3,350 };
	CandyBar_S snack_2 = { "Banna Chips", 5.7,700 };
	CandyBar_S snack_3 = { "Strawberry Chips", 4.5 ,500 };
	candyArr[0] = snack_1;
	candyArr[1] = snack_2;
	candyArr[2] = snack_3;
	cout << "\n\nQ6.\n";
	for (int i = 0; i < 3; i++)
	{
		cout << "[출력]\n상표명 : " << candyArr[i].candyName 
			<< "\n중량 : " << candyArr[i].candyWeight 
			<< "\n칼로리 : " << candyArr[i].candyCal << endl;
	}

	CandyBar_S *snackNew = new CandyBar_S[3];
	snackNew[0] = snack_1;
	snackNew[1] = snack_2;
	snackNew[2] = snack_3;

	cout << "\n\nQ9.\n";
	for (int i = 0; i < 3; i++)
	{
		cout << "[출력]\n상표명 : " << candyArr[i].candyName 
			<< "\n중량 : " << candyArr[i].candyWeight 
			<< "\n칼로리 : " << candyArr[i].candyCal << endl;
	}
	delete[] snackNew;

	return 0;
}