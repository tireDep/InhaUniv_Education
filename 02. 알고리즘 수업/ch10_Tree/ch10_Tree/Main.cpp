#include<iostream>
#include<string>
#include<Windows.h>

using namespace std;

struct Node
{
	int num;
	string name;

	Node *left;
	Node *right;

};

void ResetNode(Node *node);
void AddNode(Node **tree);
void DeleteNode(Node **tree);
Node *SearchNode(Node *deleteNode, int removeNum);
Node *SearchParentNode(Node **deleteNode, int removeNum);

void PrintNode(const Node *node);

int main()
{
	int inputNum;
	Node *tree = new Node;
	
	ResetNode(tree);
	
	while (1)
	{
		cout << "[���� �޴�]\n";
		cout << "1. ��� �߰�\n2. ��� ����\n3. ��� ���\n4. ȭ�� ����\n5. ���α׷� ����\n";
		cout << "�޴� ���� : ";
		cin >> inputNum;

		if (inputNum == 5)
		{
			cout << "\n���α׷� ����\n";
			break;
		}

		switch (inputNum)
		{
		case 1:
			cout << "\n[��� �߰�]\n";
			AddNode(&tree);
			break;
		case 2:
			cout << "\n[��� ����]\n";
			DeleteNode(&tree);
			break;
		case 3:
			cout << "\n[����Ʈ ���]\n��� ���� : ��ȣ, �̸�\n";
			PrintNode(tree);
			cout << endl;
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
	
	delete tree;
	return 0;
}

void ResetNode(Node *node)
{
	node->num = INT_MIN;
	node->name = "";
	node->left = NULL;
	node->right = NULL;
}

void AddNode(Node **tree)
{
	Node *addNode = *tree;
	Node *newNode = new Node;
	ResetNode(newNode);

	cout << "��ȣ �Է� : ";
	cin >> newNode->num;

	cout << "�̸� �Է� : ";
	cin >> newNode->name;

	if ((*tree)->name == "")	// �� Ʈ��
		(*tree) = newNode;
	else
	{
		while (1)
		{
			if (addNode->num == newNode->num)
			{
				cout << "\n[�ش� ��ȣ�� ������]\n";
				break;
			}

			if (addNode->num < newNode->num)
			{
				if (addNode->right == NULL)
				{
					addNode->right = newNode;
					break;
				}
				else
					addNode = addNode->right;
			}
			else if (addNode->num > newNode->num)
			{
				if (addNode->left == NULL)
				{
					addNode->left = newNode;
					break;
				}
				else
					addNode = addNode->left;
			}

		}
	}

	cout << endl;
	return;
}

void DeleteNode(Node **tree)
{
	int inputNum;
	Node *deleteNode = *tree;
	Node *parentNode = *tree;

	if ((*tree)->name == "")
	{
		cout << "\n[Ʈ���� �������]\n\n";
		return;
	}

	cout << "������ ��ȣ �Է� : ";
	cin >> inputNum;

	Node *removeNode = SearchNode(deleteNode, inputNum);
	if (removeNode == NULL)
	{
		cout << "\n[ã�� ���� �������� ����]\n\n";
		return;
	}
	else
	{
		deleteNode = SearchParentNode(&deleteNode, inputNum);
		// ������� ����� �θ� ���

		if (removeNode->left == NULL && removeNode->right == NULL)
		{
			if (deleteNode->left == removeNode)
			{
				delete(removeNode);
				deleteNode->left = NULL;
			}
			else if (deleteNode->right == removeNode)
			{
				delete(removeNode);
				deleteNode->right = NULL;
			}
		}	// ������� ��忡 �ڽĳ�� ���� x

		else if (removeNode->left == NULL || removeNode->right == NULL)
		{
			if (removeNode->left!=NULL)
			{
				if (deleteNode->left == removeNode)
				{
					deleteNode->left = removeNode->left;
					delete(removeNode);
					deleteNode->left->left = NULL;
				}
				else if (deleteNode->right == removeNode)
				{
					deleteNode->right = removeNode->left;
					delete(removeNode);
					deleteNode->right->left = NULL;
				}
			}	// ������� ����� ���� �ڽĳ�� ����

			else
			{
				if (deleteNode->left == removeNode)
				{
					deleteNode->left = removeNode->right;
					delete(removeNode);
					deleteNode->left->right = NULL;
				}
				else if (deleteNode->right == removeNode)
				{
					deleteNode->right = removeNode->right;
					delete(removeNode);
					deleteNode->right->right = NULL;
				}
			}	// ������� ����� ������ �ڽĳ�� ����

		}	// ������� ��忡 �ڽĳ�� �� �ʸ� ����
		
		else
		{
			Node *tempNode = removeNode;
			Node *tempPNode = deleteNode;

			while (tempNode != NULL)
			{
				// if()
			}
		}// ������� ��忡 �ڽĳ�尡 ���� ��� ����

	}	// else

	return;
}

Node *SearchNode(Node *deleteNode, int removeNum)
{
	Node *removeNode = deleteNode;

	while (removeNode!=NULL)
	{
		if (removeNode->num == removeNum) return removeNode;
		else if (removeNode->num > removeNum) removeNode = removeNode->left;
		else removeNode = removeNode->right;
	}

	return NULL;
}

Node *SearchParentNode(Node **deleteNode, int removeNum)
{
	Node *parentNode = *deleteNode;
	while ((*deleteNode) != NULL)
	{
		if ((*deleteNode)->num == removeNum || (*deleteNode)->num == removeNum) return parentNode;
		else if ((*deleteNode)->num > removeNum)
		{
			parentNode = *deleteNode;
			(*deleteNode) = (*deleteNode)->left;
		}
		else 
		{
			parentNode = *deleteNode;
			(*deleteNode) = (*deleteNode)->right;
		}
	}

	return NULL;
}

void PrintNode(const Node *node)
{
	if (node->name == "")
	{
		cout << "[Ʈ���� �������]\n\n";
		return;
	}

	if (node->left != NULL)
		PrintNode(node->left);
	cout << node->num << ", " << node->name << endl;
	if (node->right != NULL)
		PrintNode(node->right);

	return;
}