#pragma once

#include <vector>
#include <map>

using namespace std;

#define defNodeCnt 8
#define defInfNum 9999

class cDijkstra
{
private:
	int nodeArr[defNodeCnt][defNodeCnt];
	vector<pair<int, int>> nodeList;
	vector<int> closeNodeList;

	int startNode;
	int endNode;

	int addedNum;

	cDijkstra();
	~cDijkstra();

public:
	static cDijkstra* GetInstance();

	void DoDijkstra();
	bool CalcNode(int nodeArr[][defNodeCnt], int openNode, int nodeCnt);
	void SetGoalNode(int sNode, int eNode);
};

cDijkstra::cDijkstra()
{
	int tempArr[defNodeCnt][defNodeCnt] = {
		{ 0, 2, defInfNum, defInfNum, defInfNum, 3, defInfNum, defInfNum },
		{ 2, 0, 4, 1, defInfNum, defInfNum, defInfNum, defInfNum },
		{ defInfNum, 4, 0, defInfNum, 3, defInfNum, defInfNum, defInfNum },
		{ defInfNum, 1, defInfNum, 0, 3, defInfNum, 2, defInfNum },
		{ defInfNum, defInfNum, 3, 3, 0, defInfNum, defInfNum, 4},
		{ 3, defInfNum, defInfNum, defInfNum, defInfNum, 0, 6, defInfNum },
		{ defInfNum, defInfNum, defInfNum, 2, defInfNum, 6, 0, 4 },
		{ defInfNum, defInfNum, defInfNum, defInfNum, 4, defInfNum, 4, 0 }
	};

	for (int i = 0; i < defNodeCnt; i++)
	{
		for (int j = 0; j < defNodeCnt; j++)
			nodeArr[i][j] = tempArr[i][j];
	}

	startNode = 0;
	endNode = 0;
	addedNum = 0;
}

cDijkstra::~cDijkstra()
{

}

cDijkstra* cDijkstra::GetInstance()
{
	static cDijkstra dijkstra;
	return &dijkstra;
}

void cDijkstra::SetGoalNode(int sNode, int eNode)
{
	startNode = sNode - 1;
	endNode = eNode - 1;

	//addedNum = startNode;
}

void cDijkstra::DoDijkstra()
{
	int tempNodeArr[defNodeCnt][defNodeCnt];

	for (int i = 0; i < defNodeCnt; i++)
	{
		for (int j = 0; j < defNodeCnt; j++)
			tempNodeArr[i][j] = nodeArr[i][j];
	}

	CalcNode(tempNodeArr, startNode,nodeList.size());

	for (int i = 0; i < closeNodeList.size(); i++)
		cout << closeNodeList[i] + 1 << "\n";
}

bool cDijkstra::CalcNode(int nodeArr[][defNodeCnt], int openNode, int nodeCnt)
{
	if (openNode == endNode)
	{
		closeNodeList.push_back(openNode);
		return true;
	}
	else if (closeNodeList.size() != 0)
	{
		if (closeNodeList.back() == endNode)
			return true;
	}

	int calcNodeCnt = nodeCnt;

	// reset
	int saveAddedNum = addedNum;
	int saveOpenNode = openNode;
	int saveNodeCnt = nodeCnt;
	vector<pair<int, int>> saveNodeList = nodeList;
	int saveNodeArr[defNodeCnt][defNodeCnt] = { 0 };
	for (int i = 0; i < defNodeCnt; i++)
	{
		for (int j = 0; j < defNodeCnt; j++)
		{
			saveNodeArr[i][j] = nodeArr[i][j];
		}
	}
	// reset

	for (int i = 0; i < defNodeCnt; i++)
	{
		if (nodeArr[openNode][i] == 0 || nodeArr[openNode][i] != defInfNum)
			nodeList.push_back({ i, nodeArr[openNode][i] + addedNum });
	}

	for (int i = 0; i < nodeCnt; i++)
	{
		nodeList[i].second += addedNum;
	}

	int minIndex = 0;	// 변경?
	int minVal = 10000;
	//int smallVal = nodeList[calcNodeCnt].second; // ? 
	//bool isSmall = false;
	for (int i = 0; i < nodeList.size(); i++)
	{
		if (minVal > nodeList[i].second && i > nodeCnt)
		{
			if (nodeList[i].first != openNode)
			{
				minVal = nodeList[i].second;
				minIndex = i;	// 오픈 노드 제외
			}
		}

		// if (smallVal <= nodeList[i].second && nodeList[i].first != openNode && calcNodeCnt > i)
		// 	isSmall = true;// smallVal = nodeList[i].first;	// ?

		//if (i == 0)
		//	continue;
		//else if (smallVal <= nodeList[i].second && nodeList[i].first != openNode && calcNodeCnt > i)
		//{
		//	for (int j = nodeList.size(); j > calcNodeCnt; j--)
		//		nodeList.pop_back();
		//}
	}

	for (int i = 0; i < nodeCnt; i++)
	{
		if (nodeList[minIndex].second > nodeList[i].second)
		{
			puts("anotherWay");
			return false;
		}
	}

	// Infi Node

	closeNodeList.push_back(openNode);
	addedNum = nodeList[minIndex].first;

	for (int i = 0; i < defNodeCnt; i++)
	{
		nodeArr[openNode][i] = defInfNum;
		nodeArr[i][openNode] = defInfNum;
	}

	vector<pair<int, int>>::iterator it;
	for (it = nodeList.begin(); it != nodeList.end(); )
	{
		if (it->first == openNode || it->first == minIndex)
			it = nodeList.erase(it);
		else
			it++;
	}
	// close Node

	// openNode = minIndex;
	openNode = addedNum;

	if (!CalcNode(nodeArr, openNode, nodeList.size()))
	{
		openNode = saveOpenNode;
		nodeList = saveNodeList;
		nodeCnt = saveNodeCnt - 1;

		for (int i = 0; i < defNodeCnt; i++)
		{
			for (int j = 0; j < defNodeCnt; j++)
				nodeArr[i][j] = saveNodeArr[i][j];
		}

		closeNodeList.pop_back();
		// reset

		for (int i = 0; i < nodeList.size(); i++)
		{
			if (nodeList[i].first == saveOpenNode)
			{
				nodeList.erase(nodeList.begin() + i);
				break;
			}
		}

		if (nodeList.size() == 1)
			return false;
		else
		{
			int minIndex = 0;
			int minVal = 10000;
			for (int i = 0; i < nodeList.size(); i++)
			{
				if (minVal > nodeList[i].second)
				{
					if (nodeList[i].first != openNode)
					{
						minVal = nodeList[i].second;
						minIndex = i;	// 오픈 노드 제외
					}
				}
			}
			
			openNode = nodeList[minIndex].first;
			CalcNode(nodeArr, openNode, nodeList.size());
		}
		// 자기 자신 제외, 가장 작은 값에 대해서 재귀
		// 자기 자신만 남았을 경우 false 반환
	}
}