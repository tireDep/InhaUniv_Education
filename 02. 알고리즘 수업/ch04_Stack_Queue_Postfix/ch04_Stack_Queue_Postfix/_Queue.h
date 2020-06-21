#pragma once
// Ring Buffer == Cicular Queue

using namespace std;

struct QUEUE_S
{
	int max;	// 최대값
	int cnt;	// 현재 개수
	int front;	// 맨 앞
	int rear;	// 맨 뒤
	string *value;	// 큐의 값
};

bool Initialize(QUEUE_S &queue, int dataSize);
int GetMax(const QUEUE_S &queue);
int GetCnt(const QUEUE_S &queue);
bool IsFull(const QUEUE_S &queue);
bool Enque(QUEUE_S &queue, string inputData);
bool IsEmpty(const QUEUE_S &queue);
bool Deque(QUEUE_S &queue, string &resultVal);
bool Peek(const QUEUE_S &queue, string &resultVal);
bool Print(const QUEUE_S &queue);
void Search(const QUEUE_S &queue);
void Clear(QUEUE_S &queue);
void Terminate(QUEUE_S &queue);