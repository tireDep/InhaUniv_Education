/*

Q. 책에 나온 모든 Stack 관련 함수들을 쓸 수 있는 프로그램을 본인의 스타일로 다시 만드시오.

Initialize.		스택 초기화.
Push.			스택 푸시.
Pop.			스택 팝.
Peek.			스택 피크.
Clear.			스택 비우기.
Capacity.		스택의 최대 용량.
Size.			스택의 데이터 개수.
IsEmpty.		스택이 비어있는지 확인.
IsFull.			스택이 가득 차 있는지 확인.
Search.			스택 검색.
Print.			스택 내 모든 데이터 출력.
Terminate.		스택 종료.

*/

#include<iostream>
#include"_stack.h"

using namespace std;

int main()
{
	STACK_S stack;

	int inputNum = 0;
	cout << "스택의 개수 입력 : ";
	cin >> inputNum;

	if (Initialize(&stack, inputNum) == false)
	{
		cout << "\n에러 : 스택 생성 실패\n\n";
		return 0;
	}

	int inputMenu, inputValue;
	while (1)
	{
		cout << "\n현재 데이터 수 : " << GetSize(stack) << " / " << GetCapacity(stack) << endl;
		cout << "\n1) Push 2) Pop 3) Peek \n4) Print 5) Search 6) Clear 0) Exit\n\n입력 : ";
		cin >> inputMenu;

		if (inputMenu == 0)
			break;
		
		switch (inputMenu)
		{
		case 1:
			if (!Push(&stack))
				cout << "\n데이터 입력 실패" << endl;
			else
				cout << "\n데이터 입력 성공" << endl;
			break;
		case 2:
			int popData;
			if (!Pop(&stack, &popData))
				cout << "\n스택에 데이터가 존재하지 않음" << endl;
			else
				cout << "Pop 결과 : " << popData << endl;
			break;
		case 3:
			int peekData;
			if (!Peek(&stack, &peekData))
				cout << "\n스택에 데이터가 존재하지 않음" << endl;
			else
				cout << "Peek 결과 : " << peekData << endl;
			break;
		case 4:
			Print(stack);
			break;
		case 5:
			if(!Search(stack))
				cout << "\n검색 결과 : 해당 데이터가 존재하지 않음" << endl;
			break;
		case 6:
			Clear(&stack);
			cout << "\n스택 초기화 완료" << endl;
			break;

		default:
			cout << "\n잘못된 수 입력" << endl;
			break;
		}
	}

	cout << "프로그램 종료" << endl;
	Terminate(&stack);

	return 0;
}