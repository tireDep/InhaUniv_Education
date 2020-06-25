#include<iostream>
#include<string>
#include "_Queue.h"

using namespace std;

bool Initialize(QUEUE_S &queue, int dataSize)
{
	queue.value = new string[dataSize];
	if (queue.value == NULL)
	{
		cout << "error : 데이터 할당 에러\n\n";
		return false;
	}
	queue.front = 0;
	queue.rear = 0;
	queue.cnt = 0;
	queue.max = dataSize;

	return true;
}

int GetMax(const QUEUE_S &queue)
{
	return queue.max;
}

int GetCnt(const QUEUE_S &queue)
{
	return queue.cnt;
}

bool IsFull(const QUEUE_S &queue)
{
	if (queue.front == queue.rear && queue.cnt == queue.max)
		return false;
	else
		return true;
}

bool IsEmpty(const QUEUE_S &queue)
{
	if (queue.front == queue.rear && queue.cnt == 0)
		return false;
	else
		return true;
}

bool Enque(QUEUE_S &queue, string inputData)
{
	if (!IsFull(queue))
	{
		cout << "Error : 인큐\n\n";
		return false;
	}

	queue.value[queue.rear] = inputData;
	queue.cnt++;
	queue.rear = ++queue.rear % queue.max;
	// 최댓값을 넘어가지 않음!
	// ex)
	// max = 8, rear가 가질 수 있는 값은 0 ~ 7

	return true;
}

bool Deque(QUEUE_S &queue, string &resultVal)
{
	if (!IsEmpty(queue))
	{
		cout << "Error : 디큐\n\n";
		return false;
	}

	resultVal = queue.value[queue.front];
	queue.cnt--;
	queue.front = ++queue.front % queue.max;
	// 최댓값을 넘어가지 않음!
	// ex)
	// max = 8, rear가 가질 수 있는 값은 0 ~ 7
	
	return true;
}

bool Print(const QUEUE_S &queue)
{
	if (!IsEmpty(queue))
	{
		cout << "Error : 출력\n\n";
		return false;
	}

	//char printChar;
	for (int i = 0; i < queue.cnt; i++)
	{
		//printChar = queue.value[i];
		cout << queue.value[i] << " ";
	}
	return true;
}

void Terminate(QUEUE_S &queue)
{
	delete[] queue.value;
}