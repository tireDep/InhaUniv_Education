// 334p

#include<iostream>

using namespace std;

void ShowMenu();
void Report();
void Comfort();

int main()
{
	ShowMenu();
	int choice;
	cin >> choice;
	while (choice != 5)
	{
		switch (choice)
		{
		case 1: 
			cout << "\a\n";
			break;
		case 2: 
			Report();
			break;
		case 3:
			cout << "사장님은 오늘 회사에 계셨습니다.\n";
			break;
		case 4:
			Comfort();
			break;
		default:
			cout << "그것은 선택할 수 없습니다.\n";
			break;
		}
		ShowMenu();
		cin >> choice;
	}
	cout << "프로그램을 종료합니다!\n";
	
	return 0;
}

void ShowMenu()
{
	cout << "1, 2, 3, 4, 5번 중에서 하나를 선택하십시오\n";
	cout << "1) 경고음 2) 보고서 3) 알리바이 4) 격려사 5) 종료\n";
}

void Report()
{
	cout << "이번 분기는 경영 실력이 아주 좋습니다\n판매량은 120% 늘어났고, 비용은 35% 줄었습니다.\n";
}

void Comfort()
{
	cout << "사원들은 당신을 업계 최고의 CEO라고 생각하고 있습니다.\n이사회도 당신을 업계 최고의 CEO라고 생각하고 있습니다.\n";
}
