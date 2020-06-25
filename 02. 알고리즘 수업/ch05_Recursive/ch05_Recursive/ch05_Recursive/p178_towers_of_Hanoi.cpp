#include<iostream>
#include<string>

void Hanoi(int roundCnt, int start, int temp, int goal);

using namespace std;

int main()
{
	int inputGoal;
	int inputRoundCnt;
	
	cout << "���� ���� : ";
	cin >> inputRoundCnt;
	
	while (1)
	{
		cout << "�ϳ���ž ���� ������(2,3) : ";
		cin >> inputGoal;

		if (inputGoal == 2)
		{
			Hanoi(inputRoundCnt, 1, 3, inputGoal);
			break;
		}
		else if (inputGoal == 3)
		{
			Hanoi(inputRoundCnt, 1, 2, inputGoal);
			break;
		}
		else
			cout << "\nERROR : ����\n";
	}

	return 0;
}

void Hanoi(int roundCnt, int start, int temp, int goal)	// ����, ������, ������
{
	if (roundCnt == 1)
		cout << "1 : " << start << " -> " << goal << endl;
	else
	{
		Hanoi(roundCnt - 1, start, goal, temp);
		cout << roundCnt << " : " << start << " -> " << goal << endl;
		Hanoi(roundCnt - 1, temp, start, goal);
	}
}
