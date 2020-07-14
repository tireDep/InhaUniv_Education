// Q. �Է� ������ ������� ��ȣ ������� ���ĵ� ����Ʈ�� �����ϰ��� �ϴ� ���α׷� �ۼ�

// [��ũ�� ����Ʈ ���]
// 1) ����Ʈ �ʱ�ȭ
// 2) ��� �߰�
//		-> 1. ���� �տ� �߰�
//		-> 2. �� �ڿ� �߰�
//		-> 3. ���̿� �߰�
// 3) ��� ����
//		-> 1. ���� �� ��� ����
//		-> 2. �� �� ��� ����
//		-> 3. ���� ��� ����
// 4) �˻�
//		-> ��ȣ�� �Է¹޾Ƽ� �ش� ��ȣ�� �̸� ���
// 5) ���
//		-> ����Ʈ ��ü ������ ���

#include<iostream>
#include<string>
#include<Windows.h>

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

	if(pHead != NULL)
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
	}
	else // ����Ʈ�� ������� ���� ���
	{
		while (addNode)
		{
			if (addNode->num == newNode->num)
			{
				cout << "\n[�ش� ��ȣ�� ������]\n";
				break;
			}

			if (addNode->num < newNode->num)	// �Է��� ���� ���� �� ���� Ŭ ���
			{
				if (addNode->pNext == NULL)	// ����Ʈ�� ���� ����
				{
					newNode->pNext = addNode->pNext;
					addNode->pNext = newNode;
					break;
				}
				else if (addNode->pNext != NULL)	// ����Ʈ �߰��� ����
				{
					if (addNode->pNext->num > newNode->num)	// ���� ����� ���� �����Ϸ��� ������ ū ���
					{
						newNode->pNext = addNode->pNext;
						addNode->pNext = newNode;
						break;
					}
				}	// else if
			}	// if
			else // �Է��� ���� ���� ���� ���, ����Ʈ �� �� ����
			{
				newNode->pNext = addNode;
				(*pHead) = newNode;
				break;
			}
			addNode = addNode->pNext;	// ���� ��� ����
		}	// while
	}	// else_list is not Empty

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

	while (deleteNode)
	{
		if (deleteNode->num == deleteNum)	// ������ ���� �� ���� ���
		{
			removeNode = deleteNode;
			(*pHead) = removeNode->pNext;
			deleteNum = -1;
			break;
		}
		else if (deleteNode->pNext != NULL && deleteNode -> pNext -> num == deleteNum)	// ������ ���� �� ���� �ƴ� ���
		{
			removeNode = deleteNode->pNext;
			deleteNode->pNext = removeNode->pNext;
			deleteNum = -1;
			break;
		}
		deleteNode = deleteNode->pNext;
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
	if (pHead == NULL || pHead -> num == INT_MIN)
	{
		cout << "\n[����Ʈ�� ��� ����]\n\n";
		return;
	}

	ClassMate *tempPrint = pHead;
	while (tempPrint != NULL)
	{
		cout << tempPrint->num <<", "<< tempPrint->name << endl;
		tempPrint = tempPrint->pNext;
	}
	cout << endl << endl;
}