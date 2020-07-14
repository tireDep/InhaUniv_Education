// Q. 입력 순서와 상관없이 번호 순서대로 정렬된 리스트를 구현하고자 하는 프로그램 작성

// [링크드 리스트 기능]
// 1) 리스트 초기화
// 2) 노드 추가
//		-> 1. 제일 앞에 추가
//		-> 2. 맨 뒤에 추가
//		-> 3. 사이에 추가
// 3) 노드 삭제
//		-> 1. 제일 앞 노드 삭제
//		-> 2. 맨 뒤 노드 삭제
//		-> 3. 사이 노드 삭제
// 4) 검색
//		-> 번호를 입력받아서 해당 번호의 이름 출력
// 5) 출력
//		-> 리스트 전체 데이터 출력

#include<iostream>
#include<string>

using namespace std;

struct ClassMate
{
	int num;
	string name;
	ClassMate *pNext;
};

void ResetNode(ClassMate *node);
void AddNode(ClassMate **pHead);
void DeleteNode(ClassMate **pHead);
void PrintNode(ClassMate *pHead);

int main()
{
	int inputMenu;
	ClassMate *pHead = new ClassMate;
	ResetNode(pHead);

	while (1)
	{
		cout << "[메인메뉴]\n";
		cout << "1. 노드 추가\n2. 노드 삭제\n3. 노드 출력\n4. 프로그램 종료\n";
		cout << "메뉴 선택 : ";
		cin >> inputMenu;

		if (inputMenu == 4)
		{
			cout << "\n프로그램 종료\n";
			break;
		}

		switch (inputMenu)
		{
		case 1:
			cout << "\n[노드 추가]\n";
			AddNode(&pHead);
			break;
		case 2:
			cout << "\n[노드 삭제]\n";
			DeleteNode(&pHead);
			break;
		case 3:
			cout << "\n[리스트 출력]\n";
			PrintNode(pHead);
			break;
		default:
			cout << "\n[잘못된 메뉴 입력. 재입력 필요]\n";
			break;
		}
	}
	
	// TODO
	ClassMate *temp = pHead ->pNext;
	do
	{
		ClassMate *free = temp->pNext;
		delete free;
	} while (free != NULL);

	delete pHead;
	// delete pHead;

	return 0;
}

void ResetNode(ClassMate *node)
{
	node->num = -1;
	node->name = "";
	node->pNext = NULL;
}

void AddNode(ClassMate **pHead)
{
	ClassMate *addNode = *pHead;
	ClassMate *newNode = new ClassMate;
	ResetNode(newNode);
	
	cout << "추가할 번호 입력 : ";
	cin >> newNode->num;
	
	cout << "추가할 이름 입력 : ";
	cin >> newNode->name;

	if ((*pHead) == NULL || (*pHead)->name == "")	// 리스트가 비어있을 경우, 맨 앞 삽입
	{
		(*pHead) = newNode;
	}
	else // 리스트가 비어있지 않을 경우
	{
		while (addNode)
		{
			if (addNode->num == newNode->num)
			{
				cout << "같은 번호는 저장할 수 없습니다.\n";
				break;
			}

			if (addNode->num < newNode->num)	// 입력한 값이 기존 값 보다 클 경우
			{
				if (addNode->pNext == NULL)	// 리스트의 끝에 삽입
				{
					newNode->pNext = addNode->pNext;
					addNode->pNext = newNode;
					break;
				}
				else if (addNode->pNext != NULL)	// 리스트 중간에 삽입
				{
					if (addNode->pNext->num > newNode->num)	// 다음 노드의 값이 삽입하려는 값보다 큰 경우
					{
						newNode->pNext = addNode->pNext;
						addNode->pNext = newNode;
						break;
					}
				}	// else if
			}	// if
			else // 입력한 값이 가장 작은 경우, 리스트 맨 앞 삽입
			{
				newNode->pNext = addNode;
				(*pHead) = newNode;
				break;
			}
			addNode = addNode->pNext;	// 다음 노드 진행
		}	// while
	}	// else_list is not Empty

	cout << endl;
}

void DeleteNode(ClassMate **pHead)
{
	ClassMate *deleteNode = *pHead;
	ClassMate *removeNode = NULL;

	int deleteNum = 0;
	cout << "삭제하려는 번호 입력 : ";
	cin >> deleteNum;

	if (pHead == NULL || (*pHead)->num == -1)
	{
		cout << "리스트가 비어 있음\n\n";
		return;
	}

	while (deleteNode)
	{
		if (deleteNode->num == deleteNum)	// 삭제할 값이 맨 앞인 경우
		{
			removeNode = deleteNode;
			(*pHead) = removeNode->pNext;
			deleteNum = -1;
			break;
		}
		else if (deleteNode->pNext != NULL && deleteNode -> pNext -> num == deleteNum)	// 삭제할 값이 맨 앞이 아닐 경우
		{
			removeNode = deleteNode->pNext;
			deleteNode->pNext = removeNode->pNext;
			deleteNum = -1;
			break;
		}
		deleteNode = deleteNode->pNext;
	}
	
	if (deleteNum != -1)
		cout << "해당 값이 리스트에 존재하지 않음\n";
	else
	{
		cout << "삭제된 데이터 : " << removeNode->num << ", " << removeNode->name << endl;
		delete removeNode;
	}

	cout << endl;
}

void PrintNode(ClassMate *pHead)
{
	ClassMate *tempPrint = pHead;

	if (pHead == NULL || pHead->num == -1)
	{
		cout << "리스트가 비어 있음\n\n";
		return;
	}

	while (tempPrint != NULL)
	{
		cout << tempPrint->num << ", " << tempPrint->name << endl;
		tempPrint = tempPrint->pNext;
	}
	cout << endl << endl;
}