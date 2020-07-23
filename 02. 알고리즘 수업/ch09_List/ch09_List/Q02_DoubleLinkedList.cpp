#include<iostream>
#include<string>
#include<Windows.h>

using namespace std;

struct ClassMate
{
	int num;
	string name;

	ClassMate *pPrev;
	ClassMate *pNext;
};

void ResetNode(ClassMate *node);
void AddNode(ClassMate **pHead);
void DeleteNode(ClassMate **pHead);
void PrintNode(ClassMate *pHead);
void FreeNode(ClassMate *pHead);

int main()
{
	int inputMenu;
	ClassMate *pHead = new ClassMate;
	ResetNode(pHead);

	while (1)
	{
		cout << "[메인메뉴]\n";
		cout << "1. 노드 추가\n2. 노드 삭제\n3. 노드 출력\n4. 화면 삭제\n5. 프로그램 종료\n";
		cout << "메뉴 선택 : ";
		cin >> inputMenu;

		if (inputMenu == 5)
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
			cout << "\n[리스트 출력]\n출력 내역 : 번호, 이름\n";
			PrintNode(pHead);
			break;
		case 4:
			cout << "\n[화면 삭제]\n";
			Sleep(200);
			system("cls");
			break;
		default:
			cout << "\n[잘못된 메뉴 입력. 재입력 필요]\n";
			break;
		}
	}

	FreeNode(pHead);
	return 0;
}

void ResetNode(ClassMate *node)
{
	node->num = INT_MIN;
	node->name = "";
	node->pNext = NULL;
	node->pPrev = NULL;
}

void FreeNode(ClassMate *pHead)
{
	ClassMate *temp = pHead->pNext;
	while (1)
	{
		delete pHead;
		pHead = temp;

		if (temp != NULL)
			temp = temp->pNext;
		else
			break;
	}

	if (pHead != NULL)
		delete pHead;
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

	if ((*pHead) == NULL || (*pHead)->num == INT_MIN)	// 리스트가 비어있을 경우, 맨 앞 삽입
	{
		(*pHead) = newNode;
		(*pHead)->pPrev = newNode;
		(*pHead)->pNext = newNode;
	}
	else if ((*pHead)->num > newNode->num)
	{
		//(*pHead)->pNext = newNode ->pNext;
		newNode->pNext = (*pHead)->pNext;
		(*pHead) = newNode;
		newNode->pPrev = (*pHead);
	}
	else
	{
		while (1)
		{
			if (addNode->num == newNode->num)
			{
				cout << "\n[해당 번호가 존재함]\n";
				break;
			}
			
			if (addNode->pNext == (*pHead))
			{
				addNode->pNext = newNode;
				addNode->pNext->pPrev = newNode;
				
				newNode->pPrev = addNode;				
				newNode->pNext = (*pHead);
				break;
			}
			if (addNode->pNext->num > newNode->num)
			{
				addNode->pNext->pPrev = newNode;
				addNode->pNext = newNode;

				newNode->pPrev = addNode;
				newNode->pNext = addNode->pNext;
				break;
			}
			addNode = addNode->pNext;
		}
	}

	cout << endl;
}

void DeleteNode(ClassMate **pHead)
{
	ClassMate *deleteNode = *pHead;
	ClassMate *removeNode = NULL;

	if ((*pHead) == NULL || (*pHead)->num == INT_MIN)
	{
		cout << "\n[리스트가 비어 있음]\n\n";
		return;
	}

	int deleteNum = 0;
	cout << "삭제하려는 번호 입력 : ";
	cin >> deleteNum;

	if ((*pHead)->num == deleteNum)
	{
		if ((*pHead)->pNext == (*pHead))
		{
			removeNode = (*pHead);
			(*pHead) = NULL;
			(*pHead)->pPrev = (*pHead)->pNext;
			deleteNum = -1;
		}
		else
		{
			removeNode = (*pHead);
			(*pHead) = (*pHead)->pNext;
			(*pHead)->pNext = removeNode->pNext;
			(*pHead)->pPrev = removeNode->pPrev;
			deleteNum = -1;
		}
	}
	else
	{
		while (1)
		{
			if (deleteNode->pNext == (*pHead))
				break;

			if (deleteNode->pNext->num == deleteNum)
			{
				removeNode = deleteNode->pNext;
				deleteNode->pNext = removeNode->pNext;

				if (deleteNode->pNext != (*pHead))
				{
					deleteNum = -1;
					removeNode->pNext->pPrev = deleteNode;
				}
				else
				{
					deleteNum = -1;
					// tail
				}
					break;
			}
			deleteNode = deleteNode->pNext;
		}
	}

	if (deleteNum != -1)
		cout << "\n[해당 값이 리스트에 존재하지 않음]\n";
	else
	{
		cout << "\n[삭제된 데이터]\n출력내역 : 번호, 이름\n" << removeNode->num << ", " << removeNode->name << endl;
		delete removeNode;
	}

	cout << endl;
}

void PrintNode(ClassMate *pHead)
{
	if (pHead == NULL || pHead->num == INT_MIN)
	{
		cout << "\n[리스트가 비어 있음]\n\n";
		return;
	}

	ClassMate *tempPrint = pHead;
	do
	{
		cout << tempPrint->num << ", " << tempPrint->name << endl;
		tempPrint = tempPrint->pNext;
	} while (tempPrint ->num != pHead -> num);

	cout << endl << endl;
}