// Q. 로또 복권이 있다. 그 카드에는 임의로 선택된 수를 하나씩 표시하는 번호가 매겨진 자리들이 있다.
// 두 개의 매개변수를 사용하는 Lotto() 함수를 작성하라.
// 제 1 매개변수는 복권에 표시된 자리 수 여야 하고, 제 2 매개변수는 복권 구입지가 임의로 선택한 자리들의 수여야 한다.
// 함수는 임의로 선택한 수들이 정렬된 순서로 저장되어 있는 vector<int> 객체를 리턴해야 한다.
// 예를 들면, 다음과 같은 함수를 사용할 수 있다.
// vector<int> Winners;
// Winners = Lotto(45, 6);
// 이렇게 하면 1부터 45까지의 범위에서 임의로 선택한 6개의 수를 가지는 벡터를 Winners에 대입할 수 있다.
// 단순히 rand()만 사용하면 중복되는 값이 발생하기 때문에, 잘 되지 않는다.
// 이것을 해결하는 방법은 그 함수가, 가능한 모든 값들을 가지는 벡터를 만들고, random_suffle()을 사용하여 뒤섞은 다음,
// 뒤섞인 벡터의 시작 위치를 사용하여 6개의 값을 얻는 것이다.
// 간단한 프로그램을 작성하여 이 함수를 테스트하라.

#include<iostream>
#include<ctime>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> Lotto(int maxNum, int selectNum);

const int arrSize = 45;
const int select = 6;

int main()
{
	vector<int> arr;
	vector<int>::iterator iter;

	arr = Lotto(arrSize, select);

	cout << "선택 된 수 : ";
	for (iter=arr.begin(); iter != arr.end(); iter++)
		cout << *iter << " ";
	cout << endl;
}

vector<int> Lotto(int maxNum, int selectNum)
{
	srand((unsigned)time(NULL));
	vector<int> setNum;
	for (int i = 0; i < maxNum; i++)
		setNum.push_back(i + 1);

	random_shuffle(setNum.begin(), setNum.end());

	vector<int>::iterator it = setNum.begin();
	setNum.erase(it + selectNum, it + maxNum);
	// 6 ~ 45 인덱스값 삭제
	
	//for (it = setNum.begin(); it != setNum.end(); it++)
	//	cout << *it << endl;

	//vector<int> temp;
	//for (int i = 0; i < select; i++)
	//	temp.push_back(setNum.at(i));

	return setNum;
}