// Q. 1번부터 N번까지 번호가 붙어있는 N개의 접시가 일렬로 있고, 각각 1개 혹은 0개의 핵이 놓여있다. 
// 1시간이 지나면 k번 접시에 있는 핵은 k번, 2k번, 3k번, 4k번 ... 접시로 분열된다.

// 예를 들어, 6 개의 접시가 있고 첫 상태가 아래와 같으면,
// 
// 1 1 1 0 1 0
// 
// 1시간 후에는 1, 2, 3, 5번 접시의 핵들이 분열되어 각 접시에 놓인 핵의 개수는 아래처럼 변화한다.
// (1번 접시는 1,2,3,4,5,6번 접시로, 2번 접시는 2,4,6번 접시로, 3번 접시는 3,6번 접시로, 5번 접시는 5번 접시로)
// 
// 1 2 2 2 2 3
// 
// 입력으로 N개의 접시에 놓인 핵의 개수가 주어진다. 첫 상태가 무엇이었을지와 최소 몇 시간만 입력으로 주어진 상태가 만들어질 수 있을지 출력하라.
// 핵분열의 결과가 될 수 없다면 -1을 출력 하도록 한다.
// 
// ex)
// 6 (접시 개수)
// 1 3 3 5 3 8 (각 접시에 놓인 핵의 개수)
// 
// ex Print)
// 2 (몇 시간만에 입력에 주어진 상태를 만들 수 있을지)
// 1 1 1 0 1 0 (첫 상태가 무엇인지)


#include<iostream>
#include<vector>

using namespace std;

bool CheckMinus(vector<int> vec, int &cnt);	// 음수 판별
bool CheckFission(vector<int> vec, int &cnt);	// 핵분열 가능 판별
void ReverseFission(vector<int> &vDish, int &time);	// 역 핵분열
void Fission(vector<int> &vDish, int time);	// 핵분열
void PrintVec(vector<int> vDish);	// 출력

int main()
{
	vector<int> vDish;
	int dishCnt, ncCnt;
	cout << "접시 개수 입력 : ";
	cin >> dishCnt;

	for (int i = 0; i < dishCnt; i++)
	{
		if (i == 0)
			vDish.push_back(0);

		cout << "접시에 놓인 핵의 개수 : ";
		cin >> ncCnt;
		vDish.push_back(ncCnt);
	}
	
	dishCnt += 1;	// 최대 개수 +1(1부터 시작)
	int progressTime = 0;
	ReverseFission(vDish, progressTime);

	cout << "\n[결과]\n";
	if (progressTime == -1)
		cout << "핵분열 불가\n프로그램 종료\n";
	else
	{
		cout << "소요 시간 : " << progressTime << endl;
		cout << "최초 핵 : ";
		PrintVec(vDish);

		cout << "핵 분열 결과 : ";
		Fission(vDish, progressTime);
		PrintVec(vDish);
	}
	return 0;
}

bool CheckMinus(vector<int> vec, int &cnt)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] < 0)
		{
			cnt = -1;
			return false;
		}
	}
	return true;
}

bool CheckFission(vector<int> vec, int &cnt)
{
	if (!CheckMinus(vec, cnt))
		return false;

	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] > 1)
			return true;
	}
	return false;
}

void ReverseFission(vector<int> &vDish, int &time)
{
	int check = 0;
	int cnt = 0;
	vector<int> temp;
	while (CheckFission(vDish, cnt))
	{
		temp = vDish;
		for (int i = 0; i <= ceil(sqrt(vDish.size() - 1)); i++)
		{
			if (i == 0)
				continue;

			for (int j = i + i; j < vDish.size(); j += i)
			{
				vDish[j] -= vDish[i];
			}
		}	// for_i
		cnt++;
		// 기존 값과 비교했을 때 값 변동이 없으면 핵분열 불가
		if (vDish == temp)
		{
			time = -1;
			return;
		}	// if
	}	// while

	time = cnt;
	return;
}

void Fission(vector<int> &vDish, int time)
{
	vector<int> temp = vDish;
	while (time > 0)
	{
		time--;
		for (int i = 0; i <vDish.size(); i++)
		{
			if (i == 0)
				continue;

			for (int j = i + i; j < vDish.size(); j += i)
			{
				temp[j] += vDish[i];
			}	// for_j
		}	// for_i
		vDish = temp;
	}	// while
}

void PrintVec(vector<int> vDish)
{
	for (int i = 0; i < vDish.size(); i++)
	{
		if (i == 0)
			continue;
		cout << vDish[i] << " ";
	}
	cout << endl;
}