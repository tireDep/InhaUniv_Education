#include <iostream>
#include <string>
#include "Dijkstra.h"

using namespace std;

void InputData(int &node, string text);

int main()
{
	cDijkstra *dijkstra = cDijkstra::GetInstance();

	int startNode, endNode;
	InputData(startNode, "시작할 노드 입력");
	InputData(endNode, "\n목적지 노드 입력 ");

	dijkstra->SetGoalNode(startNode, endNode);
	dijkstra->DoDijkstra();

	return 0;
}

void InputData(int &node, string text)
{
	while (1)
	{
		cout << text <<"(1 ~ " << defNodeCnt << ") : ";
		cin >> node;

		if (node > defNodeCnt || node <= 0)
		{
			cout << "[ 입력 에러. 재입력 필요 ]\n\n";
			while ((node = getchar()) != EOF && node != '\n') {};
			// todo : 문자 입력시 에러 마무리
		}
		else
			break;
	}
}