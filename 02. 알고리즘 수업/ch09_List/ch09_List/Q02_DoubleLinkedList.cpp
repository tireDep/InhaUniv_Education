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
		cout << "[���θ޴�]\n";
		cout << "1. ��� �߰�\n2. ��� ����\n3. ��� ���\n4. ȭ�� ����\n5. ���α׷� ����\n";
		cout << "�޴� ���� : ";
		cin >> inputMenu;

		if (inputMenu == 5)
		{
			cout << "\n���α׷� ����\n";
			break;
		}

		switch (inputMenu)
		{
		case 1:
			cout << "\n[��� �߰�]\n";
			AddNode(&pHead);
			break;
		case 2:
			cout << "\n[��� ����]\n";
			DeleteNode(&pHead);
			break;
		case 3:
			cout << "\n[����Ʈ ���]\n��� ���� : ��ȣ, �̸�\n";
			PrintNode(pHead);
			break;
		case 4:
			cout << "\n[ȭ�� ����]\n";
			Sleep(200);
			system("cls");
			break;
		default:
			cout << "\n[�߸��� �޴� �Է�. ���Է� �ʿ�]\n";
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
	ClassMate *deleteCnt = pHead;

	int delCnt = 0;
	while (deleteCnt->pNext != pHead)
	{
		delCnt;
		deleteCnt = deleteCnt->pNext;
	}

	while (delCnt > 0)
	{
		delCnt--;
		delete pHead;
		pHead = temp;

		if (temp->name != "")
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

	cout << "�߰��� ��ȣ �Է� : ";
	cin >> newNode->num;

	cout << "�߰��� �̸� �Է� : ";
	cin >> newNode->name;

	if ((*pHead) == NULL || (*pHead)->num == INT_MIN)	// ����Ʈ�� ������� ���, �� �� ����
	{
		(*pHead) = newNode;
		(*pHead)->pPrev = newNode;
		(*pHead)->pNext = newNode;
	}
	else if ((*pHead)->num > newNode->num)
	{
		newNode->pNext = (*pHead);
		(*pHead)->pPrev = newNode;
		
		while ((*pHead)->pNext != newNode->pNext)
			(*pHead) = (*pHead)->pNext;

		newNode->pPrev = (*pHead);
		(*pHead)->pNext = newNode;
		(*pHead) = newNode;
	}
	else
	{
		while (1)
		{
			if (addNode->num == newNode->num)
			{
				cout << "\n[�ش� ��ȣ�� ������]\n";
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
				newNode->pPrev = addNode;
				newNode->pNext = addNode->pNext;

				addNode->pNext = newNode;
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
		cout << "\n[����Ʈ�� ��� ����]\n\n";
		return;
	}

	int deleteNum = 0;
	cout << "�����Ϸ��� ��ȣ �Է� : ";
	cin >> deleteNum;

	if ((*pHead)->num == deleteNum)
	{
		if ((*pHead)->pNext == (*pHead))
		{
			removeNode = (*pHead);
			(*pHead)->pNext = NULL;
			(*pHead)->pPrev = NULL;
			(*pHead) = NULL;
			deleteNum = -1;
		}
		else
		{
			removeNode = (*pHead);
			(*pHead) = removeNode->pNext;

			while (deleteNode->pNext != removeNode)
				deleteNode = deleteNode->pNext;

			(*pHead)->pNext = removeNode->pNext->pNext;
			removeNode->pPrev->pPrev = (*pHead);

			(*pHead)->pPrev = deleteNode;
			deleteNode->pNext = (*pHead);
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
				// else
				// {
				// 	deleteNum = -1;
				// 	// tail
				// }
					break;
			}
			deleteNode = deleteNode->pNext;
		}
	}

	if (deleteNum != -1)
		cout << "\n[�ش� ���� ����Ʈ�� �������� ����]\n";
	else
	{
		cout << "\n[������ ������]\n��³��� : ��ȣ, �̸�\n" << removeNode->num << ", " << removeNode->name << endl;
		delete removeNode;
	}

	cout << endl;
}

void PrintNode(ClassMate *pHead)
{
	if (pHead == NULL || pHead->num == INT_MIN)
	{
		cout << "\n[����Ʈ�� ��� ����]\n\n";
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