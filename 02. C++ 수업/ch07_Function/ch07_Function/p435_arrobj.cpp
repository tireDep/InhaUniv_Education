// 435p

#include<iostream>
#include<array>
#include<string>

using namespace std;

const int Seasons = 4;
const array<string, Seasons>Sname = { "Spring", "Summer", "Fall", "Winter" };

void Fill(array<double, Seasons> *pa);
void Show(array<double, Seasons> da);

int main()
{
	array<double, Seasons> expenses;
	Fill(&expenses);
	Show(expenses);

	return 0;
}

void Fill(array<double, Seasons> *pa)
{
	for (int i = 0; i < Seasons; i++)
	{
		cout << Sname[i] << "에 소요되는 비용 : ";
		cin >> (*pa)[i];
	}
}

void Show(array<double, Seasons> da)
{
	double total = 0;
	cout << "\n계절별 비용\n";
	for (int i = 0; i < Seasons; i++)
	{
		cout << Sname[i] << " : $" << da[i] << endl;
		total += da[i];
	}

	cout << "총 비용 : $" << total << endl;
}
