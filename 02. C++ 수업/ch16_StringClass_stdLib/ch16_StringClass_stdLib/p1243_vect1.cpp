#include<iostream>
#include<string>
#include<vector>

const int NUM = 5;

int main()
{
	using std::vector;
	using std::string;
	using std::cin;
	using std::cout;
	using std::endl;
	
	vector<int>ratings(NUM);
	vector<string>titles(NUM);

	cout << NUM << "���� å ����� å ���(0-10)�� �Է��Ͻʽÿ�.\n";
	
	for (int i = 0; i < NUM; i++)
	{
		cout << i + 1 << "�� å�� ������ �Է��Ͻʽÿ�.\n";
		getline(cin, titles[i]);
		cout << i + 1 << "�� å�� ���(0-10)�� �Է��Ͻʽÿ�.\n";
		cin >> ratings[i];
		cin.get();
	}

	cout << "�����մϴ�. ����� ������ ���� �Է��ϼ̽��ϴ�.\n���\t����\n";
	for (int i = 0; i < NUM; i++)
		cout << ratings[i] << "\t" << titles[i] << endl;

	return 0;
}