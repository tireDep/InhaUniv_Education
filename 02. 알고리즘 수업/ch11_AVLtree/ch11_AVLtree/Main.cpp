#include<iostream>
#include<string>
#include<Windows.h>

#include<queue>

using namespace std;

using std::queue;

struct Node
{
	int num;
	string name;

	Node *left;
	Node *right;

};

void ResetNode(Node *node);
void AddNode(Node **tree);
bool DeleteNode(Node **tree);
void Search(Node *tree);
Node *SearchNode(Node *deleteNode, int removeNum);
Node *SearchParentNode(Node **deleteNode, int removeNum);

void PrintNode(const Node *node);

void CheckBalance(Node **tree, Node goalNode);
int CheckLeftNode(const Node *node, const Node goalNode);
int CheckRightNode(const Node *node, const Node goalNode);

void LevelInorder(Node tree);

int main()
{
	int inputNum;
	Node *tree = new Node;

	ResetNode(tree);

	while (1)
	{
		cout << "[���� �޴�]\n";
		cout << "1. ��� �߰�\n2. ��� ����\n3. ��� ���\n4. �˻�\n5. ȭ�� ����\n6. Ʈ�� ���\n7. ���α׷� ����\n";
		cout << "\n�޴� ���� : ";
		cin >> inputNum;

		if (inputNum == 7)
		{
			cout << "\n���α׷� ����\n";
			break;
		}

		switch (inputNum)
		{
		case 1:
			cout << "\n[��� �߰�]\n";
			AddNode(&tree);
			CheckBalance(&tree, *tree);
			break;
		case 2:
			cout << "\n[��� ����]\n";
			if (DeleteNode(&tree))
				CheckBalance(&tree, *tree);
			break;
		case 3:
			cout << "\n[Ʈ�� ���]\n��� ���� : ��ȣ, �̸�\n";
			PrintNode(tree);
			cout << endl;
			break;
		case 4:
			cout << "\n[�˻�]\n";
			Search(tree);
			break;
		case 5:
			cout << "\n[ȭ�� ����]\n";
			Sleep(200);
			system("cls");
			break;
		case 6:
		{
			cout << "\n[Ʈ�� ���]\n��� ���� : ��ȣ, �̸�\n";
			LevelInorder(*tree);
			break;
		}
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

bool DeleteNode(Node **tree)
{
	int inputNum;
	Node *deleteNode = *tree;
	Node *parentNode = *tree;

	if ((*tree)->name == "")
	{
		cout << "\n[Ʈ���� �������]\n\n";
		return false;
	}

	cout << "������ ��ȣ �Է� : ";
	cin >> inputNum;

	bool isRemove = false;
	Node *removeNode = SearchNode(deleteNode, inputNum);
	if (removeNode == NULL || removeNode->num < 0)
	{
		cout << "\n[ã�� ���� �������� ����]\n\n";
		return false;
	}
	else
	{
		deleteNode = SearchParentNode(&deleteNode, inputNum);
		// ������� ����� �θ� ���

		if (removeNode->left == NULL && removeNode->right == NULL)
		{
			if (deleteNode->left == removeNode)
			{
				deleteNode->left = NULL;
				isRemove = true;
			}
			else if (deleteNode->right == removeNode)
			{
				deleteNode->right = NULL;
				isRemove = true;
			}
			else
			{
				cout << "\n[���� �Ϸ�]\n";
				cout << "������ �� : " << removeNode->num << ", " << removeNode->name << endl << endl;
				ResetNode(deleteNode);	// ��Ʈ���
				return true;
			}
		}	// ������� ��忡 �ڽĳ�� ���� x

		else if (removeNode->left == NULL || removeNode->right == NULL)
		{
			if (removeNode->left != NULL)
			{
				if (removeNode == deleteNode)
				{
					(*tree) = removeNode->left;
					isRemove = true;
				}
				else if (deleteNode->left == removeNode)
				{
					deleteNode->left = removeNode->left;
					deleteNode->left->left = NULL;
					isRemove = true;
				}
				else if (deleteNode->right == removeNode)
				{
					deleteNode->right = removeNode->left;
					deleteNode->right->left = NULL;
					isRemove = true;
				}
			}	// ������� ����� ���� �ڽĳ�� ����

			else
			{
				if (removeNode == deleteNode)
				{
					(*tree) = removeNode->right;
					isRemove = true;
				}
				else if (deleteNode->left == removeNode)
				{
					deleteNode->left = removeNode->right;
					deleteNode->left->right = NULL;
					isRemove = true;
				}
				else if (deleteNode->right == removeNode)
				{
					deleteNode->right = removeNode->right;
					deleteNode->right->right = NULL;
					isRemove = true;
				}
			}	// ������� ����� ������ �ڽĳ�� ����

		}	// ������� ��忡 �ڽĳ�� �� �ʸ� ����

		else
		{
			Node *tempNode = removeNode->left;

			while (tempNode->right != NULL)
				tempNode = tempNode->right;

			Node *pNode = *tree;
			pNode = SearchParentNode(&pNode, tempNode->num);

			if (pNode == *tree)
			{
				tempNode->right = (*tree)->right;
				(*tree) = tempNode;
				isRemove = true;
			}
			else if (pNode == removeNode)
			{
				pNode = removeNode->left;
				pNode->left = NULL;
				pNode->right = removeNode->right;
				isRemove = true;
			}
			else
			{
				pNode->right = tempNode->left;
				tempNode->left = NULL;

				if (pNode != NULL)
				{
					if (pNode->left == removeNode)
						pNode->left = tempNode;
					else
						pNode->right = tempNode;
				}
				else
					(*tree) = tempNode;

				tempNode->left = removeNode->left;
				tempNode->right = removeNode->right;
				isRemove = true;
			}

		}// ������� ��忡 �ڽĳ�尡 ���� ��� ����

	}	// else

	if (isRemove)
	{
		cout << "\n[���� �Ϸ�]\n";
		cout << "������ �� : " << removeNode->num << ", " << removeNode->name << endl << endl;
		delete removeNode;
	}

	return true;
}

Node *SearchNode(Node *deleteNode, int removeNum)
{
	Node *removeNode = deleteNode;

	while (removeNode != NULL)
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

void Search(Node *tree)
{
	int inputNum;
	cout << "�˻��� ��ȣ �Է� : ";
	cin >> inputNum;

	Node *searchNode = SearchNode(tree, inputNum);
	if (searchNode != NULL)
	{
		cout << "\n[�˻����]\n";
		cout << searchNode->num << ", " << searchNode->name << endl << endl;
	}
	else
		cout << "\n[�ش� ���� �������� ����]\n\n";
}

void PrintNode(const Node *node)
{
	if (node->name == "")
	{
		cout << "\n[Ʈ���� �������]\n\n";
		return;
	}

	if (node->left != NULL)
		PrintNode(node->left);
	cout << node->num << ", " << node->name << endl;
	if (node->right != NULL)
		PrintNode(node->right);

	return;
}

void CheckBalance(Node **tree, Node goalNode)
{
	Node *balanceNode = *tree;
	if (balanceNode->name == "")
	{
		cout << "\n[Ʈ���� �������]\n\n";
		return;
	}

	if (balanceNode->left != NULL)
		CheckBalance(&balanceNode->left, *balanceNode);

	int left = CheckLeftNode(balanceNode, *balanceNode);
	int right = CheckRightNode(balanceNode, *balanceNode);

	// ����� ���� 2�̻��̸� �����ʿ�
	if (left - right >= 2)
	{
		cout << "���� �뷱�� ���� �ʿ�" << endl;

		Node *tempNode = new Node;
		if (balanceNode->left->right != NULL) tempNode = balanceNode->left->right;
		balanceNode->left->right = balanceNode;

		if (balanceNode == &goalNode)	// ��Ʈ���
		{
			(*tree) = balanceNode->left;
			(*tree)->right->right = balanceNode->right;
		}
		else
		{
			(*tree) = balanceNode->left;

			if((*tree)->right==NULL)
				(*tree)->right = balanceNode;
			else
				(*tree)->right->left = tempNode;
		}
		//balanceNode->left = NULL;
	}
	else if (left - right <= -2)
	{
		cout << "������ �뷱�� ���� �ʿ�" << endl;
		
		Node *tempNode = new Node;
		if(balanceNode->right->left!=NULL) tempNode = balanceNode->right->left;
		balanceNode->right->left = balanceNode;

		if (balanceNode == &goalNode)	// ��Ʈ���
		{
			(*tree) = balanceNode->right;
			(*tree)->left->left = balanceNode->left;
		}
		else
		{
			(*tree) = balanceNode->right;
			if ((*tree)->left == NULL)
				(*tree)->left = balanceNode;
			else
				(*tree)->left->right = tempNode;
		}
		// balanceNode->right = NULL;
	}

	if (balanceNode->right != NULL)
		CheckBalance(&balanceNode->right, *balanceNode);

	return;
}

int CheckLeftNode(const Node *node, const Node goalNode)
{
	static int checkNum;

	if (node->left != NULL)
	{
		checkNum++;
		CheckLeftNode(node->left, goalNode);
	}

	if (node->num == goalNode.num)
	{
		int result = checkNum;
		checkNum = 0;
		return result;	// ���۳�� ���� ���
	}

	if (node->right != NULL)
	{
		checkNum++;
		CheckLeftNode(node->right, goalNode);
	}
}

int CheckRightNode(const Node *node, const Node goalNode)
{
	static int checkNum;

	if (node->right != NULL)
	{
		checkNum++;
		CheckRightNode(node->right, goalNode);
	}

	if (node->num == goalNode.num)
	{
		int result = checkNum;
		checkNum = 0;
		return result;	// ���۳�� ���� ���
	}

	if (node->left != NULL)
	{
		checkNum++;
		CheckRightNode(node->left, goalNode);
	}
}

void LevelInorder(Node tree)
{
	if (tree.name == "")
	{
		cout << "\n[Ʈ���� �������]\n\n";
		return;
	}

	queue<Node *> printQueue;
	Node *tempData;

	printQueue.push(&tree);

	while (printQueue.size() != 0)
	{
		tempData = printQueue.front();
		printQueue.pop();

		cout << tempData->num << " | " << tempData->name << ", ";

		if (tempData->left)
			printQueue.push(tempData->left);

		if (tempData->right)
			printQueue.push(tempData->right);
	}
	cout << endl << endl;
}