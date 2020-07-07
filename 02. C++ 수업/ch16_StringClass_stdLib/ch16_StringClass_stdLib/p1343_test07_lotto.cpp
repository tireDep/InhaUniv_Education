// Q. �ζ� ������ �ִ�. �� ī�忡�� ���Ƿ� ���õ� ���� �ϳ��� ǥ���ϴ� ��ȣ�� �Ű��� �ڸ����� �ִ�.
// �� ���� �Ű������� ����ϴ� Lotto() �Լ��� �ۼ��϶�.
// �� 1 �Ű������� ���ǿ� ǥ�õ� �ڸ� �� ���� �ϰ�, �� 2 �Ű������� ���� �������� ���Ƿ� ������ �ڸ����� ������ �Ѵ�.
// �Լ��� ���Ƿ� ������ ������ ���ĵ� ������ ����Ǿ� �ִ� vector<int> ��ü�� �����ؾ� �Ѵ�.
// ���� ���, ������ ���� �Լ��� ����� �� �ִ�.
// vector<int> Winners;
// Winners = Lotto(45, 6);
// �̷��� �ϸ� 1���� 45������ �������� ���Ƿ� ������ 6���� ���� ������ ���͸� Winners�� ������ �� �ִ�.
// �ܼ��� rand()�� ����ϸ� �ߺ��Ǵ� ���� �߻��ϱ� ������, �� ���� �ʴ´�.
// �̰��� �ذ��ϴ� ����� �� �Լ���, ������ ��� ������ ������ ���͸� �����, random_suffle()�� ����Ͽ� �ڼ��� ����,
// �ڼ��� ������ ���� ��ġ�� ����Ͽ� 6���� ���� ��� ���̴�.
// ������ ���α׷��� �ۼ��Ͽ� �� �Լ��� �׽�Ʈ�϶�.

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

	cout << "���� �� �� : ";
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
	// 6 ~ 45 �ε����� ����
	
	//for (it = setNum.begin(); it != setNum.end(); it++)
	//	cout << *it << endl;

	//vector<int> temp;
	//for (int i = 0; i < select; i++)
	//	temp.push_back(setNum.at(i));

	return setNum;
}