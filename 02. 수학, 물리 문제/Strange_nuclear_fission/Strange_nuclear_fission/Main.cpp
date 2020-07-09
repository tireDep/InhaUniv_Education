// Q. 1������ N������ ��ȣ�� �پ��ִ� N���� ���ð� �Ϸķ� �ְ�, ���� 1�� Ȥ�� 0���� ���� �����ִ�. 
// 1�ð��� ������ k�� ���ÿ� �ִ� ���� k��, 2k��, 3k��, 4k�� ... ���÷� �п��ȴ�.

// ���� ���, 6 ���� ���ð� �ְ� ù ���°� �Ʒ��� ������,
// 
// 1 1 1 0 1 0
// 
// 1�ð� �Ŀ��� 1, 2, 3, 5�� ������ �ٵ��� �п��Ǿ� �� ���ÿ� ���� ���� ������ �Ʒ�ó�� ��ȭ�Ѵ�.
// (1�� ���ô� 1,2,3,4,5,6�� ���÷�, 2�� ���ô� 2,4,6�� ���÷�, 3�� ���ô� 3,6�� ���÷�, 5�� ���ô� 5�� ���÷�)
// 
// 1 2 2 2 2 3
// 
// �Է����� N���� ���ÿ� ���� ���� ������ �־�����. ù ���°� �����̾������� �ּ� �� �ð��� �Է����� �־��� ���°� ������� �� ������ ����϶�.
// �ٺп��� ����� �� �� ���ٸ� -1�� ��� �ϵ��� �Ѵ�.
// 
// ex)
// 6 (���� ����)
// 1 3 3 5 3 8 (�� ���ÿ� ���� ���� ����)
// 
// ex Print)
// 2 (�� �ð����� �Է¿� �־��� ���¸� ���� �� ������)
// 1 1 1 0 1 0 (ù ���°� ��������)


#include<iostream>
#include<vector>

using namespace std;

bool CheckMinus(vector<int> vec, int &cnt);	// ���� �Ǻ�
bool CheckFission(vector<int> vec, int &cnt);	// �ٺп� ���� �Ǻ�
void ReverseFission(vector<int> &vDish, int &time);	// �� �ٺп�
void Fission(vector<int> &vDish, int time);	// �ٺп�
void PrintVec(vector<int> vDish);	// ���

int main()
{
	vector<int> vDish;
	int dishCnt, ncCnt;
	cout << "���� ���� �Է� : ";
	cin >> dishCnt;

	for (int i = 0; i < dishCnt; i++)
	{
		if (i == 0)
			vDish.push_back(0);

		cout << "���ÿ� ���� ���� ���� : ";
		cin >> ncCnt;
		vDish.push_back(ncCnt);
	}
	
	dishCnt += 1;	// �ִ� ���� +1(1���� ����)
	int progressTime = 0;
	ReverseFission(vDish, progressTime);

	cout << "\n[���]\n";
	if (progressTime == -1)
		cout << "�ٺп� �Ұ�\n���α׷� ����\n";
	else
	{
		cout << "�ҿ� �ð� : " << progressTime << endl;
		cout << "���� �� : ";
		PrintVec(vDish);

		cout << "�� �п� ��� : ";
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
		// ���� ���� ������ �� �� ������ ������ �ٺп� �Ұ�
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