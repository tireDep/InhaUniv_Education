#include<iostream>

using namespace std;

struct Node
{
	int data;
	Node *pNext;
};

int main()
{
	// ��ü ����
	//Node node1;
	//node1.data = 1;
	//node1.pNext = NULL;

	//Node node2;
	//node2.data = 3;
	//node2.pNext = NULL;

	//node1.pNext = &node2;

	//// �߰� �� �߰�
	//Node node3;
	//node3.data = 2;
	//node3.pNext = NULL;

	//node3.pNext = node1.pNext;
	//node1.pNext = &node3;
	//// --------------------------------------

	//// �߰� �� ����(�˻� ���)
	//Node *preNode = &node1;

	//preNode->pNext = node3.pNext;	// deleteNode.pNext;
	//node3.pNext = NULL;
	//// �޸� �Ҵ����� ��� �����ؾ���!
	//// --------------------------------------

	//Node *pHead = &node1;
	//while (pHead != NULL)
	//{
	//	cout << pHead->data << " ";
	//	pHead = pHead->pNext;
	//}
	//cout << endl;


	// ������ ����
	Node *node1 = new Node;
	node1->data = 1;
	node1->pNext = NULL;

	Node *node2 = new Node;
	node2->data = 3;
	node2->pNext = NULL;

	node1->pNext = node2;

	// �߰� �� �߰�
	Node *node3 = new Node;
	node3->data = 2;
	node3->pNext = NULL;

	node3->pNext = node1->pNext;
	node1->pNext = node3;
	// --------------------------------------

	// �߰� �� ����(�˻� ���)
	Node *preNode = node1;

	preNode->pNext = node3->pNext;	// deleteNode.pNext;
	delete node3;
	// �޸� �Ҵ����� ��� �����ؾ���!
	// --------------------------------------

	Node *pHead = node1;
	while (pHead != NULL)
	{
		cout << pHead->data << " ";
		pHead = pHead->pNext;
	}
	cout << endl;

	return 0;
}