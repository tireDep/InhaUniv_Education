#include<iostream>
#include"_Queue.h"

using namespace std;

int main()
{
	QUEUE_S queue;
	if (!Initalize(queue))
		return 0;
	else
		cout << "큐 생성 완료\n\n";

	int inputMenu;
	int resultVal;
	while (1)
	{
		cout << "현재 데이터 수 : " << GetCnt(queue) << " / " << GetMax(queue) << endl;
		cout << "\n1) 인큐 2) 디큐 3) 피크 \n4) 출력 5) 검색 6) 초기화 0) 종료\n\n입력 : ";
		cin >> inputMenu;

		switch (inputMenu)
		{
		case 1:
			if (Enque(queue))
				cout << "\n데이터 입력 성공\n";
			break;
		case 2:
			if (Deque(queue, resultVal))
				cout << "\n\n디큐 값 : " << resultVal << endl;
			break;
		case 3:
			if (Peek(queue, resultVal))
				cout << "\n\n피크 값 : " << resultVal << endl;
			break;
		case 4:
			if (Print(queue))
				cout << "\n출력 종료\n\n";
			break;
		case 5:
			Search(queue);
			cout << "검색 종료\n\n";
			break;
		case 6:
			Clear(queue);
			cout << "초기화 완료\n\n";
			break;
		case 0:
			cout << "프로그램 종료\n\n";
			break;
		default:
			cout << "잘못된 값 입력\n\n";
			break;
		}
	}

	Terminate(queue);

	return 0;
}