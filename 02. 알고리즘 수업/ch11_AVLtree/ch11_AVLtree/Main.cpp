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
		cout << "[메인 메뉴]\n";
		cout << "1. 노드 추가\n2. 노드 삭제\n3. 노드 출력\n4. 검색\n5. 화면 삭제\n6. 트리 출력\n7. 프로그램 종료\n";
		cout << "\n메뉴 선택 : ";
		cin >> inputNum;

		if (inputNum == 7)
		{
			cout << "\n프로그램 종료\n";
			break;
		}

		switch (inputNum)
		{
		case 1:
			cout << "\n[노드 추가]\n";
			AddNode(&tree);
			CheckBalance(&tree, *tree);
			break;
		case 2:
			cout << "\n[노드 삭제]\n";
			if (DeleteNode(&tree))
				CheckBalance(&tree, *tree);
			break;
		case 3:
			cout << "\n[트리 출력]\n출력 내역 : 번호, 이름\n";
			PrintNode(tree);
			cout << endl;
			break;
		case 4:
			cout << "\n[검색]\n";
			Search(tree);
			break;
		case 5:
			cout << "\n[화면 삭제]\n";
			Sleep(200);
			system("cls");
			break;
		case 6:
		{
			cout << "\n[트리 출력]\n출력 내역 : 번호, 이름\n";
			LevelInorder(*tree);
			break;
		}
		default:
			cout << "\n[잘못된 메뉴 입력. 재입력 필요]\n";
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

	cout << "번호 입력 : ";
	cin >> newNode->num;

	cout << "이름 입력 : ";
	cin >> newNode->name;

	if ((*tree)->name == "")	// 빈 트리
		(*tree) = newNode;
	else
	{
		while (1)
		{
			if (addNode->num == newNode->num)
			{
				cout << "\n[해당 번호가 존재함]\n";
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
		cout << "\n[트리가 비어있음]\n\n";
		return false;
	}

	cout << "삭제할 번호 입력 : ";
	cin >> inputNum;

	bool isRemove = false;
	Node *removeNode = SearchNode(deleteNode, inputNum);
	if (removeNode == NULL || removeNode->num < 0)
	{
		cout << "\n[찾는 값이 존재하지 않음]\n\n";
		return false;
	}
	else
	{
		deleteNode = SearchParentNode(&deleteNode, inputNum);
		// 지우려는 노드의 부모 노드

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
				cout << "\n[삭제 완료]\n";
				cout << "삭제한 값 : " << removeNode->num << ", " << removeNode->name << endl << endl;
				ResetNode(deleteNode);	// 루트노드
				return true;
			}
		}	// 지우려는 노드에 자식노드 존재 x

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
			}	// 지우려는 노드의 왼쪽 자식노드 존재

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
			}	// 지우려는 노드의 오른쪽 자식노드 존재

		}	// 지우려는 노드에 자식노드 한 쪽만 존재

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

		}// 지우려는 노드에 자식노드가 양쪽 모두 존재

	}	// else

	if (isRemove)
	{
		cout << "\n[삭제 완료]\n";
		cout << "삭제한 값 : " << removeNode->num << ", " << removeNode->name << endl << endl;
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
	cout << "검색할 번호 입력 : ";
	cin >> inputNum;

	Node *searchNode = SearchNode(tree, inputNum);
	if (searchNode != NULL)
	{
		cout << "\n[검색결과]\n";
		cout << searchNode->num << ", " << searchNode->name << endl << endl;
	}
	else
		cout << "\n[해당 값이 존재하지 않음]\n\n";
}

void PrintNode(const Node *node)
{
	if (node->name == "")
	{
		cout << "\n[트리가 비어있음]\n\n";
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
		cout << "\n[트리가 비어있음]\n\n";
		return;
	}

	if (balanceNode->left != NULL)
		CheckBalance(&balanceNode->left, *balanceNode);

	int left = CheckLeftNode(balanceNode, *balanceNode);
	int right = CheckRightNode(balanceNode, *balanceNode);

	// 노드의 차가 2이상이면 변경필요
	if (left - right >= 2)
	{
		cout << "왼쪽 밸런스 조정 필요" << endl;

		Node *tempNode = new Node;
		if (balanceNode->left->right != NULL) tempNode = balanceNode->left->right;
		balanceNode->left->right = balanceNode;

		if (balanceNode == &goalNode)	// 루트노드
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
		cout << "오른쪽 밸런스 조정 필요" << endl;
		
		Node *tempNode = new Node;
		if(balanceNode->right->left!=NULL) tempNode = balanceNode->right->left;
		balanceNode->right->left = balanceNode;

		if (balanceNode == &goalNode)	// 루트노드
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
		return result;	// 시작노드 만날 경우
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
		return result;	// 시작노드 만날 경우
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
		cout << "\n[트리가 비어있음]\n\n";
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